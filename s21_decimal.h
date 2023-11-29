#ifndef S21_DECIMAL_H_
#define S21_DECIMAL_H_

#include <stdint.h>

#define MINUS 0x80000000  // minus 10000000 00000000 00000000 00000000
#define SC 0x00ff0000     // scale 00000000 11111111 00000000 00000000
#define MAX4BITE 0xffffffff

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  uint64_t bits[7];
  uint16_t scale;
} work_decimal;

work_decimal decimal_to_work(s21_decimal dec);
s21_decimal work_to_decimal(work_decimal dec);
void point_to_normal(work_decimal *dec1_work, work_decimal *dec2_work);

int getoverflow(work_decimal *dec);
int pointleft(work_decimal *dec);
int pointright(work_decimal *dec);
int bankround(double x);
int normalize(work_decimal *dec);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal dec1, s21_decimal dec2);
int s21_is_less_or_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater_or_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_not_equal(s21_decimal dec1, s21_decimal dec2);

#endif  // S21_DECIMAL_H_