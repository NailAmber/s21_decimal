#include "s21_decimal.h"

#include <stdio.h>

int getoverflow(work_decimal *dec) {
  int overflow = 0;
  for (int i = 0; i < 7; i++) {
    dec->bits[i] += overflow;
    overflow = (dec->bits[i] >> 32);
    dec->bits[i] &= MAX4BITE;
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
      temp_dec.bits[0]++;
    }
  }
  for (int i = 3; i < 7; i++) {
    if (temp_dec.bits[i] != 0 && temp_dec.scale == 0) {
      error = 1;
      i = 7;
    }
  }

  if (!error) {
    for (int i = 0; i < 7; i++) {
    }
    *dec = temp_dec;
  }

  return error;
}
work_decimal decimal_to_work(s21_decimal dec) {
  work_decimal result;
  result.bits[0] = dec.bits[0] & MAX4BITE;
  result.bits[1] = dec.bits[1] & MAX4BITE;
  result.bits[2] = dec.bits[2] & MAX4BITE;
  result.bits[3] = 0;
  result.bits[4] = 0;
  result.bits[5] = 0;
  result.bits[6] = 0;
  result.scale = (dec.bits[3] & SC) >> 16;
  return result;
}
s21_decimal work_to_decimal(work_decimal dec) {
  s21_decimal result;
  result.bits[0] = dec.bits[0] & MAX4BITE;
  result.bits[1] = dec.bits[1] & MAX4BITE;
  result.bits[2] = dec.bits[2] & MAX4BITE;
  result.bits[3] = 0;
  result.bits[3] |= (dec.scale << 16);
  return result;
}

void point_to_normal(work_decimal *dec1_work, work_decimal *dec2_work) {
  if (dec1_work->scale < dec2_work->scale) {
    while (dec1_work->scale != dec2_work->scale && !pointleft(dec1_work))
      ;
  } else if (dec2_work->scale < dec1_work->scale) {
    while (dec1_work->scale != dec2_work->scale && !pointleft(dec2_work))
      ;
  }
}
int s21_is_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;
  if ((dec1.bits[3] & MINUS) != (dec2.bits[3] & MINUS)) {
    res = 0;
  } else {
    work_decimal dec1_work, dec2_work;
    dec1_work = decimal_to_work(dec1);
    dec2_work = decimal_to_work(dec2);
    point_to_normal(&dec1_work, &dec2_work);
    for (int i = 2; i >= 0; i--) {
      if (dec1_work.bits[i] != dec2_work.bits[i]) {
        res = 0;
      }
    }
  }
  return res;
}
int s21_is_less(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;
  if ((dec1.bits[3] & MINUS) < (dec2.bits[3] & MINUS) ||
      s21_is_equal(dec1, dec2)) {
    res = 0;
  } else if ((dec1.bits[3] & MINUS) > (dec2.bits[3] & MINUS)) {
    res = 1;
  } else {
    work_decimal dec1_work, dec2_work;
    dec1_work = decimal_to_work(dec1);
    dec2_work = decimal_to_work(dec2);
    point_to_normal(&dec1_work, &dec2_work);
    for (int i = 2; i >= 0; i--) {
      if (dec1_work.bits[i] < dec2_work.bits[i]) {
        res = 1;
        i = -1;
      } else if (dec1_work.bits[i] > dec2_work.bits[i]) {
        res = 0;
        i = -1;
      }
    }
    if (dec1.bits[3] & MINUS) {
      res ? (res = 0) : (res = 1);
    }
  }
  return res;
}

int s21_is_less_or_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  if (s21_is_equal(dec1, dec2) || s21_is_less(dec1, dec2)) {
    res = 1;
  }
  return res;
}

int s21_is_greater(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;
  if (s21_is_less_or_equal(dec1, dec2)) {
    res = 0;
  }
  return res;
}

int s21_is_greater_or_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;
  if (s21_is_less(dec1, dec2)) {
    res = 0;
  }
  return res;
}

int s21_is_not_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;
  if (s21_is_equal(dec1, dec2)) {
    res = 0;
  }
  return res;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  work_decimal dec1_work = decimal_to_work(value_1),
               dec2_work = decimal_to_work(value_2);
  work_decimal temp_result = decimal_to_work(*result);
  if ((value_1.bits[3] & MINUS) == (value_2.bits[3] & MINUS)) {
    for (int i = 0; i < 3; i++) {
      temp_result.bits[i] += dec1_work.bits[i] + dec2_work.bits[i];
      getoverflow(&temp_result);
    }
    if (normalize(&temp_result)) {
      if (value_1.bits[3] & MINUS) {
        res = 2;
      } else {
        res = 1;
      }
    } else {
      *result = work_to_decimal(temp_result);
      if (value_1.bits[3] & MINUS) {
        result->bits[3] |= MINUS;
      }
    }
  } else {
    int first_minus = (value_1.bits[3] & MINUS);
    int second_minus = (value_2.bits[3] & MINUS);
    value_1.bits[3] &= ~MINUS;
    value_2.bits[3] &= ~MINUS;
    for (int i = 0; i < 3; i++) {
      if (s21_is_less(value_1, value_2)) {
        temp_result.bits[i] += dec2_work.bits[i] + (~dec1_work.bits[i] + 1);
      } else {
        temp_result.bits[i] += dec1_work.bits[i] + (~dec2_work.bits[i] + 1);
      }
      getoverflow(&temp_result);
    }

    normalize(&temp_result);
    *result = work_to_decimal(temp_result);
    if ((s21_is_less(value_1, value_2) && second_minus) ||
        (s21_is_greater(value_1, value_2) && first_minus)) {
      result->bits[3] |= MINUS;
    }
  }
  return res;
}