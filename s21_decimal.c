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

int work_is_equal(work_decimal dec1_work, work_decimal dec2_work) {
  int res = 1;
  // point_to_normal(&dec1_work, &dec2_work);
  for (int i = 6; i >= 0; i--) {
    if (dec1_work.bits[i] != dec2_work.bits[i]) {
      res = 0;
    }
  }
  return res;
}

int s21_is_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;
  if ((dec1.bits[3] & MINUS) != (dec2.bits[3] & MINUS) &&
      ((dec1.bits[0] == dec2.bits[0]) && (dec1.bits[1] == dec2.bits[1]) &&
       (dec1.bits[2] == dec2.bits[2]) && (dec1.bits[0] == 0))) {
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

int work_is_less(work_decimal dec1_work, work_decimal dec2_work) {
  int res = 0;
  // point_to_normal(&dec1_work, &dec2_work);
  for (int i = 6; i >= 0; i--) {
    if (dec1_work.bits[i] < dec2_work.bits[i]) {
      res = 1;
      i = -1;
    } else if (dec1_work.bits[i] > dec2_work.bits[i]) {
      res = 0;
      i = -1;
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

int work_add(work_decimal dec1_work, work_decimal dec2_work,
             work_decimal *temp_result) {
  int res = 0;
  point_to_normal(&dec1_work, &dec2_work);
  for (int i = 0; i < 7; i++) {
    temp_result->bits[i] += dec1_work.bits[i] + dec2_work.bits[i];
    getoverflow(temp_result);
  }
  return res;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  work_decimal dec1_work = decimal_to_work(value_1),
               dec2_work = decimal_to_work(value_2);
  work_decimal temp_result = {{0, 0, 0, 0, 0, 0, 0}, 0};
  point_to_normal(&dec1_work, &dec2_work);
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
      result->bits[3] |= (dec1_work.scale << 16) & SC;
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
    result->bits[3] |= (dec1_work.scale << 16) & SC;
  }
  return res;
}

int work_sub(work_decimal value_1, work_decimal value_2, work_decimal *result) {
  int res = 0;
  work_decimal temp_result = {{0, 0, 0, 0, 0, 0, 0}, 0};
  // point_to_normal(&value_1, &value_2);

  for (int i = 0; i < 7; i++) {
    temp_result.bits[i] += value_1.bits[i] + (~value_2.bits[i] + 1);
    getoverflow(&temp_result);
  }
  *result = temp_result;
  // result->scale = value_1.scale;
  return res;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  work_decimal dec1_work = decimal_to_work(value_1),
               dec2_work = decimal_to_work(value_2);
  work_decimal temp_result = {{0, 0, 0, 0, 0, 0, 0}, 0};
  point_to_normal(&dec1_work, &dec2_work);
  if ((value_1.bits[3] & MINUS) == (value_2.bits[3] & MINUS)) {
    int first_minus = (value_1.bits[3] & MINUS);
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
    if ((s21_is_less(value_1, value_2) && !first_minus) ||
        (s21_is_greater(value_1, value_2) && first_minus)) {
      result->bits[3] |= MINUS;
    }
    result->bits[3] |= (dec1_work.scale << 16) & SC;
  } else {
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
      result->bits[3] |= (dec1_work.scale << 16) & SC;
    }
  }
  return res;
}

int work_mul(work_decimal dec1_work, work_decimal dec2_work,
             work_decimal *temp_dec) {
  int res = 0;
  temp_dec->bits[0] = dec1_work.bits[0] * dec2_work.bits[0];
  temp_dec->bits[1] = dec1_work.bits[1] * dec2_work.bits[0] +
                      dec1_work.bits[0] * dec2_work.bits[1];
  temp_dec->bits[2] = dec1_work.bits[2] * dec2_work.bits[0] +
                      dec1_work.bits[1] * dec2_work.bits[1] +
                      dec1_work.bits[0] * dec2_work.bits[2];
  temp_dec->bits[3] = dec1_work.bits[1] * dec2_work.bits[2] +
                      dec1_work.bits[2] * dec2_work.bits[1];
  temp_dec->bits[4] = dec1_work.bits[2] * dec2_work.bits[2];
  getoverflow(temp_dec);
  return res;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  work_decimal dec1_work = decimal_to_work(value_1),
               dec2_work = decimal_to_work(value_2);
  work_decimal temp_dec = {{0, 0, 0, 0, 0, 0, 0}, 0};
  temp_dec.bits[0] = dec1_work.bits[0] * dec2_work.bits[0];
  temp_dec.bits[1] = dec1_work.bits[1] * dec2_work.bits[0] +
                     dec1_work.bits[0] * dec2_work.bits[1];
  temp_dec.bits[2] = dec1_work.bits[2] * dec2_work.bits[0] +
                     dec1_work.bits[1] * dec2_work.bits[1] +
                     dec1_work.bits[0] * dec2_work.bits[2];
  temp_dec.bits[3] = dec1_work.bits[1] * dec2_work.bits[2] +
                     dec1_work.bits[2] * dec2_work.bits[1];
  temp_dec.bits[4] = dec1_work.bits[2] * dec2_work.bits[2];
  getoverflow(&temp_dec);
  if (normalize(&temp_dec)) {
    if ((value_1.bits[3] & MINUS) != (value_2.bits[3] & MINUS)) {
      res = 2;
    } else {
      res = 1;
    }
  } else {
    *result = work_to_decimal(temp_dec);
    if ((value_1.bits[3] & MINUS) != (value_2.bits[3] & MINUS)) {
      result->bits[3] |= MINUS;
    }
    result->bits[3] |= (value_1.bits[3] & SC) + (value_2.bits[3] & SC);
  }
  return res;
}

void bit_left(work_decimal *dec1_work, int shift) {
  int max = shift / 32;
  for (int i = 0; i < max; i++) {
    for (int j = 0; j < 7; j++) {
      dec1_work->bits[j] <<= 32;
    }
    getoverflow(dec1_work);
  }
  for (int i = 0; i < shift % 32; i++) {
    for (int j = 0; j < 7; j++) {
      dec1_work->bits[j] <<= 1;
    }
  }
  getoverflow(dec1_work);
}

void div_upper_loop(
    work_decimal *temp_dec,
    const work_decimal *dec2_work,  // добавил тут const в параметр, если не
                                    // работает, можно попробовать удалить это
    work_decimal *dec1_work, int sign, int *res, work_decimal *dec3_work) {
  for (int i = 96; i >= 0; i--) {
    *temp_dec = *dec2_work;
    bit_left(temp_dec, i);
    if (work_is_less(*temp_dec, *dec1_work) && i == 96) {
      if (!sign) {
        *res = 1;
      } else {
        *res = 2;
      }
      i = -1;
    }
    if ((work_is_less(*temp_dec, *dec1_work) ||
         work_is_equal(*dec1_work, *temp_dec)) &&
        i >= 0) {  // добавил условие && i >=0, если не будет работать, имеет
                   // смысл пересмотреть решение
      dec3_work->bits[i / 32] |= 1 << (i % 32);
      work_sub(*dec1_work, *temp_dec, dec1_work);
    }
  }
}

void div_down_loop(
    work_decimal *temp_dec,
    const work_decimal *dec2_work,  // добавил тут const в параметр, если не
                                    // работает, можно попробовать удалить это
    work_decimal *dec1_work, work_decimal *dec3_work, int *scale, int *temp_div,
    int *is_it_first_loop) {
  pointleft(dec1_work);
  pointleft(dec3_work);
  *scale = (*scale) + 1;
  *temp_div = 0;
  for (int i = 3; i >= 0; i--) {
    *temp_dec = *dec2_work;
    bit_left(temp_dec, i);
    if (work_is_less(*temp_dec, *dec1_work) ||
        work_is_equal(*dec1_work, *temp_dec)) {
      if (*is_it_first_loop) {
        dec3_work->bits[0] |= 1 << i;
      } else {
        *temp_div = *temp_div | 1 << i;
      }
      *is_it_first_loop = 0;
      work_sub(*dec1_work, *temp_dec, dec1_work);
    }
  }
  if (!(*is_it_first_loop)) {
    dec3_work->bits[0] = dec3_work->bits[0] + *temp_div;
  }
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  if (s21_is_equal(value_2, (s21_decimal){{0, 0, 0, 0}})) {
    res = 3;
  } else {
    int sign = 0;
    if ((value_1.bits[3] & MINUS) != (value_2.bits[3] & MINUS)) {
      sign = 1;
    }
    work_decimal dec1_work = decimal_to_work(value_1),
                 dec2_work = decimal_to_work(value_2),
                 dec3_work = {{0, 0, 0, 0, 0, 0, 0}, 0};
    point_to_normal(&dec1_work, &dec2_work);
    int scale = dec1_work.scale - dec2_work.scale;
    work_decimal temp_dec = dec2_work;
    div_upper_loop(&temp_dec, &dec2_work, &dec1_work, sign, &res, &dec3_work);
    int temp_div = 0;
    int is_it_first_loop = 1;
    while (
        scale < 30 && !res &&
        !work_is_equal(dec1_work, (work_decimal){{0, 0, 0, 0, 0, 0, 0}, 0})) {
      div_down_loop(&temp_dec, &dec2_work, &dec1_work, &dec3_work, &scale,
                    &temp_div, &is_it_first_loop);
    }
    if (normalize(&dec3_work)) {
      if (!sign) {
        res = 1;
      } else {
        res = 2;
      }
    } else {
      dec3_work.scale = 0;
      *result = work_to_decimal(dec3_work);
      if (sign) {
        result->bits[3] |= MINUS;
      } else {
        result->bits[3] &= ~MINUS;
      }
      result->bits[3] |= (scale << 16) & SC;
    }
  }
  return res;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  s21_decimal temp_dec = {{0, 0, 0, 0}};
  temp_dec.bits[3] = (src < 0) ? MINUS : 0;
  temp_dec.bits[0] = src & ~MINUS;
  *dst = temp_dec;
  return res;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  work_decimal dec_work = decimal_to_work(src);
  for (int i = 0; i < ((src.bits[3] & SC) >> 16); i++) {
    pointright(&dec_work);
  }
  for (int i = 6; i > 0; i--) {
    if (dec_work.bits[i] != 0) {
      res = 1;
      i = 0;
    }
  }
  if (!res && !(dec_work.bits[0] & MINUS)) {
    *dst = dec_work.bits[0];
    *dst |= (dec_work.bits[0] & MINUS) << 31;
    *dst |= (src.bits[3] & MINUS);
  }
  return res;
}
