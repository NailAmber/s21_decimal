#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#include "s21_decimal.h"

int main(void) {
  s21_decimal a, b;

  a.bits[0] = 100;
  a.bits[1] = 0x0;
  a.bits[2] = 0x0;
  a.bits[3] = 0x00000000;

  b.bits[0] = 200;
  b.bits[1] = 0x0;
  b.bits[2] = 0x0;
  b.bits[3] = 0x80000000;
  printf("s21_add = %d\n", s21_sub(a, b, &a));

  printf("a.bits[0] = %d\n", a.bits[0]);
  printf("a.bits[1] = %x\n", a.bits[1]);
  printf("a.bits[2] = %x\n", a.bits[2]);
  printf("a.bits[3] = %x\n\n", a.bits[3]);
  return 0;
}