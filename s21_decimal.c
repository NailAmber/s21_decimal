#include "s21_decimal.h"

#include <stdio.h>

int getoverflow(work_decimal *dec) {
  int overflow = 0;
  for (int i = 0; i < 7; i++) {
    dec->bits[i] += overflow;
    overflow = dec->bits[i] >> 32;
    // printf("overflow = %x\n", overflow);
    // printf("dec.bits[%d] = %lx\n", i,dec->bits[i]);
    dec->bits[i] &= MAX4BITE;
    // printf("dec.bits[%d] = %lx\n", i,dec->bits[i]);
  }
  int result = 0;
  if (overflow) {
    result = 1;
  }
  return result;
}

int pointleft(work_decimal *dec) {
  work_decimal temp_dec = *dec;
  for (int i = 0; i < 7; i++) {
    temp_dec.bits[i] *= 10;
  }
  temp_dec.scale++;
  int overflowed = 0;
  if (getoverflow(&temp_dec)) {
    overflowed = 1;
  } else {
    *dec = temp_dec;
  }
  return overflowed;
}
int pointright(work_decimal *dec) {
  long int remainder = 0;
  for (int i = 6; i >= 0; i--) {
    dec->bits[i] += remainder << 32;
    remainder = dec->bits[i] % 10;
    dec->bits[i] /= 10;
  }
  dec->scale--;
  return remainder;
}

int bankround(double x) {
  double under = x - (int)x;
  int result = 0;
  if (under > 0.5) {
    result = (int)x + 1;

  } else if (under < 0.5) {
    result = (int)x;
  } else if (under == 0.5 && (int)x % 2 == 0) {
    result = (int)x;
  } else {
    result = (int)x + 1;
  }
  return result;
}

int normalize(work_decimal *dec) {
  int trash = 0;
  int error = 0;
  int last = 0;
  work_decimal temp_dec = *dec;
  for (int i = 6; i > 2; i--) {
    while (temp_dec.bits[i] != 0 && temp_dec.scale > 0) {
      last = pointright(&temp_dec);
      trash += last;
    }
    if (((last > 5 || last == 5) && trash > 5) ||
        (last == 5 && trash == 5 && temp_dec.bits[0] % 10 == 1)) {
      temp_dec
          .bits[0]++;  // ТУТ НУЖНО ОКРУГЛИТЬ, ТО ЕСТЬ ДОБАВИТЬ ЕДИНИЧКУ
                       // КУДА-ТО, ПОКА НЕ ИЗВЕСТНО КУДА. ВОЗМОЖНО ЦИКЛ ДОЛЖЕН
                       // ИДТИ В ОБРАТНУЮ СТОРОНУ,, хотя возможно это безразницы
    }
  }
  for (int i = 3; i < 7; i++) {
    if (temp_dec.bits[i] != 0 && temp_dec.scale == 0) {
      error = 1;
      i = 7;
    }
  }

  if (!error) {
    *dec = temp_dec;
  }

  return error;
}

int s21_is_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;
  if ((dec1.bits[3] & MINUS) != (dec2.bits[3] & MINUS)) {
    res = 0;
  } else {
    work_decimal dec1_work, dec2_work;
    dec1_work.bits[0] = dec1.bits[0] & MAX4BITE;
    dec1_work.bits[1] = dec1.bits[1] & MAX4BITE;
    dec1_work.bits[2] = dec1.bits[2] & MAX4BITE;
    dec1_work.scale = (dec1.bits[3] & SC) >> 16;
    printf("dec1_work.scale = %d\n", dec1_work.scale);

    dec2_work.bits[0] = dec2.bits[0] & MAX4BITE;
    dec2_work.bits[1] = dec2.bits[1] & MAX4BITE;
    dec2_work.bits[2] = dec2.bits[2] & MAX4BITE;
    dec2_work.scale = (dec2.bits[3] & SC) >> 16;
    printf("dec2_work.scale = %d\n", dec2_work.scale);

    if (dec1_work.scale < dec2_work.scale) {
      while (dec1_work.scale != dec2_work.scale && !pointleft(&dec1_work));
    } else if (dec2_work.scale < dec1_work.scale) {
      while (dec1_work.scale != dec2_work.scale && !pointleft(&dec2_work));
    }
    for (int i = 2; i >= 0; i--) {
      if (dec1_work.bits[i] != dec2_work.bits[i]) {
        res = 0;
      }
    }
  }
  return res;
}