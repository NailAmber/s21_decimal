#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#include "s21_decimal.h"

int main(void) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);

  printf("res = %d\n", res);

  printf("dec1.bits[0] = %d\n", dec1.bits[0]);
  printf("dec1.bits[1] = %x\n", dec1.bits[1]);
  printf("dec1.bits[2] = %x\n", dec1.bits[2]);
  printf("dec1.bits[3] = %x\n\n", dec1.bits[3]);

  printf("dec2.bits[0] = %d\n", dec2.bits[0]);
  printf("dec2.bits[1] = %x\n", dec2.bits[1]);
  printf("dec2.bits[2] = %x\n", dec2.bits[2]);
  printf("dec2.bits[3] = %x\n\n", dec2.bits[3]);
  return 0;
}