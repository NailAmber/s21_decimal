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

// Work convertors
work_decimal decimal_to_work(s21_decimal dec);
s21_decimal work_to_decimal(work_decimal dec);

// Arithmetic Operators
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Comparison Operators
int s21_is_less(s21_decimal dec1, s21_decimal dec2);
int s21_is_less_or_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater_or_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_not_equal(s21_decimal dec1, s21_decimal dec2);

// Convertors and parsers
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Another functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Support functions
int work_is_less(work_decimal dec1_work, work_decimal dec2_work);
int work_is_equal(work_decimal dec1_work, work_decimal dec2_work);
int work_sub(work_decimal value_1, work_decimal value_2, work_decimal *result);
int work_mul(work_decimal dec1_work, work_decimal dec2_work,
             work_decimal *temp_dec);

void bit_left(work_decimal *dec1_work, int shift);
void div_upper_loop(work_decimal *temp_dec, const work_decimal *dec2_work,
                    work_decimal *dec1_work, int sign, int *res,
                    work_decimal *dec3_work);
void div_down_loop(work_decimal *temp_dec, const work_decimal *dec2_work,
                   work_decimal *dec1_work, work_decimal *dec3_work, int *scale,
                   int *temp_div, int *is_it_first_loop);

void point_to_normal(work_decimal *dec1_work, work_decimal *dec2_work);

int getoverflow(work_decimal *dec);
int pointleft(work_decimal *dec);
int pointright(work_decimal *dec);
// int bankround(double x);
int normalize(work_decimal *dec, const int summ, const int sign);

#endif  // S21_DECIMAL_H_