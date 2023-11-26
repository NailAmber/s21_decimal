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
    a.bits[0] = 10000;
    a.bits[1] = 0x00000000;
    a.bits[2] = 0x00000000;
    a.bits[3] = 0x80030000;

    b.bits[0] = 10;
    b.bits[1] = 0x00000000;
    b.bits[2] = 0x00000000;
    b.bits[3] = 0x80000000;

    if (s21_is_equal(a, b)) {
        printf("True");
    }


  return 0;
}