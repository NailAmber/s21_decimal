#include <limits.h>
#include <stdio.h>

#include "s21_decimal.h"

int main(void) {
  /*
      s21_decimal a;
      work_decimal b;

      a.bits[0] = 0x800000ff;
      a.bits[1] = 0xf0ff0000;
      a.bits[2] = 0xf0000ff0;
      a.bits[3] = 0x00000000;

      b.bits[0] = a.bits[0] & MAX4BITE;
      b.bits[1] = a.bits[1] & MAX4BITE;
      b.bits[2] = a.bits[2] & MAX4BITE;

      b.bits[3] = 0xffff0000ffffffff;
      b.bits[4] = 0xffff0000;
      b.bits[5] = 0xffff0000;
      b.bits[6] = 0xffff0000ff;

      printf("%lx\n", b.bits[0]);
      printf("%lx\n", b.bits[1]);
      printf("%lx\n", b.bits[2]);

      printf("overflowed = %d\n", getoverflow(&b));

      printf("%lx\n", b.bits[3]);
      printf("%lx\n", b.bits[6]);
      printf("%lx\n", b.bits[2]);


  work_decimal dec;
  dec.bits[0] = 1294967295;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  // dec.bits[4] = 500000;
  // dec.bits[5] = 500000;
  printf("dec 0 = %ld\n", dec.bits[0]);
  printf("dec 1 = %ld\n", dec.bits[1]);
  printf("dec 2 = %ld\n\n", dec.bits[2]);
  pointleft(&dec);
  printf("dec 0 = %ld\n", dec.bits[0]);
  printf("dec 1 = %ld\n", dec.bits[1]);
  printf("dec 2 = %ld\n\n", dec.bits[2]);
  pointright(&dec);
  printf("dec 0 = %ld\n", dec.bits[0]);
  printf("dec 1 = %ld\n", dec.bits[1]);
  printf("dec 2 = %ld\n\n", dec.bits[2]);

  printf("error = %d\n", normalize(&dec));
  printf("dec 0 = %ld\n", dec.bits[0]);
  printf("dec 1 = %ld\n", dec.bits[1]);
  printf("dec 2 = %ld\n\n", dec.bits[2]);
  printf("dec 3 = %ld\n\n", dec.bits[3]);

  s21_decimal a;
  a.bits[0] = dec.bits[0] & MAX4BITE;
  printf("a 0 = %d\n", a.bits[0]); */

  s21_decimal a, b;
  a.bits[0] = 335;
  a.bits[1] = 0x00000000;
  a.bits[2] = 0x00000000;
  a.bits[3] = 0x80000000;

  b.bits[0] = 6;
  b.bits[1] = 0x00000000;
  b.bits[2] = 0x00000000;
  b.bits[3] = 0x80010000;

  printf("a.bits[0] = %x\n", a.bits[0]);
  printf("a.bits[1] = %x\n", a.bits[1]);
  printf("a.bits[2] = %x\n", a.bits[2]);
  printf("a.bits[3] = %x\n\n", a.bits[3]);

  printf("b.bits[0] = %x\n", b.bits[0]);
  printf("b.bits[1] = %x\n", b.bits[1]);
  printf("b.bits[2] = %x\n", b.bits[2]);
  printf("b.bits[3] = %x\n\n", b.bits[3]);

  s21_decimal c;
  printf("add = %d\n", s21_sub(a, b, &c));
  printf("c.bits[0] = %d\n", c.bits[0]);
  printf("c.bits[1] = %d\n", c.bits[1]);
  printf("c.bits[2] = %d\n", c.bits[2]);
  printf("c.bits[3] = %x\n\n", c.bits[3]);

  printf("is a < b : %d\n", s21_is_less(a, b));
  printf("is a <= b: %d\n", s21_is_less_or_equal(a, b));
  printf("is a > b : %d\n", s21_is_greater(a, b));
  printf("is a >= b: %d\n", s21_is_greater_or_equal(a, b));
  printf("is a == b: %d\n", s21_is_equal(a, b));
  printf("is a != b: %d\n", s21_is_not_equal(a, b));

  return 0;
}