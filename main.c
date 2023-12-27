#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#include "s21_decimal.h"

int main(void) {
  s21_decimal a, b;
  s21_from_float_to_decimal(0.01448, &b);
  printf("b = %d\n", b.bits[0]);

  a.bits[0] = UINT_MAX;
  a.bits[1] = UINT_MAX;
  a.bits[2] = UINT_MAX;
  a.bits[3] = 0;

  b.bits[0] = 0;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_from_float_to_decimal(0.01448, &b);
  printf("b.scale = %x\n", b.bits[3]);

  printf("add = %d\n", s21_add(a, b, &a));
  return 0;
}