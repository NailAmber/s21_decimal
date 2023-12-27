#include <limits.h>
#include <stdio.h>

#include "s21_decimal.h"

int main(void) {
  s21_decimal src;
  src.bits[0] = 462461;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  float a;
  s21_from_decimal_to_float(src, &a);
  printf("a = %f\n", a + 15);
  return 0;
}