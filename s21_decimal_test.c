#include "s21_decimal_test.h"

#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "s21_decimal.h"
// надо доделать
START_TEST(test_add) {
  int num1, num2, sum_int, res_int;
  s21_decimal a, b, res_dec;

  num1 = 42;
  num2 = 30;
  sum_int = 72;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
  ck_assert_int_eq(s21_add(a, b, &res_dec), 0);

  num1 = 1000;
  num2 = 2000;
  sum_int = 3000;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);

  num1 = 0;
  num2 = 0;
  sum_int = 0;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);

  num1 = -15;
  num2 = 5;
  sum_int = -10;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);

  num1 = 11115;
  num2 = 5;
  sum_int = 11120;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);

  num1 = -1;
  num2 = -10;
  sum_int = -11;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);

  num1 = -1234;
  num2 = 234;
  sum_int = -1000;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);

  num1 = -9403;
  num2 = 234;
  sum_int = -9169;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);

  num1 = 9403;
  num2 = 202;
  sum_int = 9605;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);

  num1 = 450;
  num2 = -50;
  sum_int = 400;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);

  float fnum1 = 7.25;
  float fnum2 = 9.5;
  float res_origin = 16.75;
  s21_from_float_to_decimal(fnum1, &a);
  s21_from_float_to_decimal(fnum2, &b);
  float res_float = 0.0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);

  num1 = -1234;
  fnum2 = 1.234;
  res_origin = -1232.766;
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(fnum2, &b);

  res_float = 0.0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);

  num1 = -1234;
  fnum2 = -1.234;
  res_origin = -1235.234;
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(fnum2, &b);

  res_float = 0.0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);

  fnum1 = -94;
  fnum2 = 0.00234;
  res_origin = fnum1 + fnum2;
  s21_from_float_to_decimal(fnum1, &a);
  s21_from_float_to_decimal(fnum2, &b);

  s21_add(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);

  fnum1 = -940.3;
  fnum2 = 0.000234;
  res_origin = -940.299766;
  s21_from_float_to_decimal(fnum1, &a);
  s21_from_float_to_decimal(fnum2, &b);

  res_float = 0.0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);

  fnum1 = -0.9403;
  fnum2 = 0.000234;
  res_origin = -0.940066;
  s21_from_float_to_decimal(fnum1, &a);
  s21_from_float_to_decimal(fnum2, &b);

  res_float = 0.0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);

  fnum1 = -0.9403;
  fnum2 = 2.0234;
  res_origin = fnum1 + fnum2;
  s21_from_float_to_decimal(fnum1, &a);
  s21_from_float_to_decimal(fnum2, &b);

  res_float = 0.0;
  s21_add(a, b, &res_dec);

  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq_tol(res_float, res_origin, 1e-6);

  fnum1 = -0.9403;
  fnum2 = -112.0234;
  res_origin = -112.9637;
  s21_from_float_to_decimal(fnum1, &a);
  s21_from_float_to_decimal(fnum2, &b);

  res_float = 0.0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);

  fnum1 = -0.94e03;
  fnum2 = -112.0234;
  res_origin = -1052.0234;
  s21_from_float_to_decimal(fnum1, &a);
  s21_from_float_to_decimal(fnum2, &b);

  res_float = 0.0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);

  fnum1 = -0.94e03;
  fnum2 = -112.0e2;
  res_origin = -12140;
  s21_from_float_to_decimal(fnum1, &a);
  s21_from_float_to_decimal(fnum2, &b);

  res_float = 0.0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);

  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = 100099;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &a);
  s21_from_int_to_decimal(tmp2, &b);
  s21_add(a, b, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);

  tmp1 = -100;
  tmp2 = -99999;
  res_s21 = 0;
  res = -100099;

  s21_from_int_to_decimal(tmp1, &a);
  s21_from_int_to_decimal(tmp2, &b);
  s21_add(a, b, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);

  tmp1 = 2147483647;
  tmp2 = -2147483647;
  res_s21 = 0;
  res = 0;

  s21_from_int_to_decimal(tmp1, &a);
  s21_from_int_to_decimal(tmp2, &b);
  s21_add(a, b, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);

  a.bits[3] = 0x300000;
  a.bits[2] = 0;
  a.bits[1] = 0xF;
  a.bits[0] = 0x67E4FEEF;
  b.bits[3] = 0x300000;
  b.bits[2] = 0;
  b.bits[1] = 0xFF;
  b.bits[0] = 0x67E4FFFF;
  s21_decimal dec_res;
  dec_res.bits[3] = 0x300000;
  dec_res.bits[2] = 0;
  dec_res.bits[1] = 0x10E;
  dec_res.bits[0] = 0xCFC9FEEE;

  s21_add(a, b, &res1);
  ck_assert_int_eq(dec_res.bits[3], res1.bits[3]);
  ck_assert_int_eq(dec_res.bits[2], res1.bits[2]);
  ck_assert_int_eq(dec_res.bits[1], res1.bits[1]);
  ck_assert_int_eq(dec_res.bits[0], res1.bits[0]);

  tmp1 = -2147483647;
  tmp2 = 2147483647;
  res_s21 = 0;
  res = 0;

  s21_from_int_to_decimal(tmp1, &a);
  s21_from_int_to_decimal(tmp2, &b);
  s21_add(a, b, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);

  a.bits[0] = UINT_MAX;
  a.bits[1] = UINT_MAX;
  a.bits[2] = UINT_MAX;
  a.bits[3] = 0;

  b.bits[0] = 1;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;

  int ret_s21 = s21_add(a, b, &res1);
  ck_assert_int_eq(1, ret_s21);

  a.bits[0] = 0xffffffff;
  a.bits[1] = 0xffffffff;
  a.bits[2] = 0xffffffff;
  a.bits[3] = MINUS;

  b.bits[0] = 1;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = MINUS;

  ret_s21 = s21_add(a, b, &res1);
  ck_assert_int_eq(2, ret_s21);

  float float_a = -10758.218750;
  float float_b = 6268.843750;

  float float_res = float_a + float_b;

  s21_decimal expected = {0};
  s21_from_float_to_decimal(float_res, &expected);

  s21_decimal dec_a = {0};
  s21_from_float_to_decimal(float_a, &dec_a);
  s21_decimal dec_b = {0};
  s21_from_float_to_decimal(float_b, &dec_b);

  s21_decimal result = {0};
  int code = s21_add(dec_a, dec_b, &result);

  float got_float = 0;
  s21_from_decimal_to_float(result, &got_float);

  ck_assert_int_eq(code, 0);
  ck_assert_float_eq_tol(got_float, float_res, 1e06);

  a.bits[0] = UINT_MAX;
  a.bits[1] = UINT_MAX;
  a.bits[2] = UINT_MAX;
  a.bits[3] = 0;

  b.bits[0] = 0;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_from_float_to_decimal(0.01448, &b);

  s21_add(a, b, &res_dec);
  ck_assert_int_eq(s21_add(a, b, &res_dec), 1);

  a.bits[0] = UINT_MAX;
  a.bits[1] = UINT_MAX;
  a.bits[2] = UINT_MAX;
  a.bits[3] = ~(INT_MAX);

  b.bits[0] = 0;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_from_float_to_decimal(-0.01448, &b);

  s21_add(a, b, &res_dec);
  ck_assert_int_eq(s21_add(a, b, &res_dec), 2);

  /*
  s21_decimal val1 = {{15, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


  s21_decimal val1 = {{15, 0, 0, 0}};
  s21_decimal val2 = {{15, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


  s21_decimal val1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(1, s21_add(val1, val2, &res));


   s21_decimal val1 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(2, s21_add(val1, val2, &res));


  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


   s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


  s21_decimal val1 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


s21_decimal val1 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


   s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


    s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


   s21_decimal val1 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal val2 = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


   s21_decimal val1 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


   s21_decimal val1 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
  s21_decimal val2 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(2, s21_add(val1, val2, &res));


   s21_decimal val1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  s21_decimal val2 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


   s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


  s21_decimal val1 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal val2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));


  s21_decimal val1 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal val2 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(2, s21_add(val1, val2, &res));


  s21_decimal c = {{5, 0, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{10, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{100, 0, 0, 0}};
  s21_decimal d = {{100, 0, 0, 0}};
  s21_decimal etalon = {{100, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);;
  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, S21_FALSE);


  s21_decimal c = {{2147483647, 0, 0, 0}};
  s21_decimal d = {{2147483647, 0, 0, 0}};
  s21_decimal etalon = {{4294967294, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal* p_result = &result;

  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);;
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{1000, 0, 0, 0}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{2000, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal* p_result = &result;

  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);;
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{1000, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal* p_result = &result;

  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);;
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal* p_result = &result;

  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);;
  int equal = s21_is_equal(*p_result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{0, 0, 0, 0}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{2, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{1000, 0, 0, 0}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{2000, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{4294967294, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{UINT32_MAX, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 1, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{0, S21_MAX_UINT - 1, 0, 0}};
  s21_decimal d = {{0, 1, 0, 0}};
  s21_decimal etalon = {{0, S21_MAX_UINT, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{0, 0, S21_MAX_UINT - 1, 0}};
  s21_decimal d = {{0, 0, 1, 0}};
  s21_decimal etalon = {{0, 0, S21_MAX_UINT, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{11, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{21, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{121, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_2}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1111, 0, 0, EXPONENT_PLUS_2}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


 s21_decimal c = {0};
  c.bits[0] = 0b11111111111111111111111111111110;
  c.bits[1] = 0b00000000000000000000000000000000;
  c.bits[2] = 0b00000000000000000000000000000000;
  c.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {0};
  etalon.bits[0] = 0b11111111111111111111111111111111;
  etalon.bits[1] = 0b00000000000000000000000000000000;
  etalon.bits[2] = 0b00000000000000000000000000000000;
  etalon.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



 s21_decimal c = {{UINT32_MAX - 1, UINT32_MAX, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{UINT32_MAX, UINT32_MAX, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



  s21_decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
  s21_decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
  s21_decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



  s21_decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0}};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  s21_decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



  s21_decimal c = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 1, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



  s21_decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
  s21_decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



  s21_decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  s21_decimal d = {
      {0b01001000000110110001111110011000, 0b11111011111111011000100101101101,
       0b00000000000001000110110101110111, 0b10000000000110000000000000000000}};
  s21_decimal etalon = {
      {0b10110110001010011011010111011010, 0b11111001111010100000110001111111,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



  a, b, origin;
  a.bits[0] = 0b01001110111001000011100101110110;
  a.bits[1] = 0b01001011001101011010000111011001;
  a.bits[2] = 0b00011001101110010111010010111111;
  a.bits[3] = 0b00000000000011110000000000000000;
  b.bits[0] = 0b00000000000000000000000000000000;
  b.bits[1] = 0b00000000000000000000000000000000;
  b.bits[2] = 0b00000000000000000000000000000000;
  b.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal* p_res = &result;
  int add = s21_add(a, b, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);

  int equal = s21_is_equal(
      result, origin);
  ck_assert_int_eq(equal, S21_TRUE);




  s21_decimal c = {{0, 0, 0, 0}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);




  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{2, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);




  s21_decimal c = {{1000, 0, 0, 0}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{2000, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);





   s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{4294967294, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



   s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



   s21_decimal c = {{S21_MAX_UINT, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 1, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



   s21_decimal c = {{0, S21_MAX_UINT - 1, 0, 0}};
  s21_decimal d = {{0, 1, 0, 0}};
  s21_decimal etalon = {{0, S21_MAX_UINT, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



   s21_decimal c = {{0, 0, S21_MAX_UINT - 1, 0}};
  s21_decimal d = {{0, 0, 1, 0}};
  s21_decimal etalon = {{0, 0, S21_MAX_UINT, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);


 s21_decimal c = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);




   s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);


  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{11, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);




   s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{21, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);





  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{121, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);




  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_2}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1111, 0, 0, EXPONENT_PLUS_2}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);



  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);





  s21_decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
  s21_decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
  s21_decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);





   s21_decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0}};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  s21_decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);




  s21_decimal c = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 1, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;


  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);



s21_decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
  s21_decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(dec_res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(dec_res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(dec_res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(dec_res.bits[3], etalon.bits[3]);
  int equal =
      s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);





 a = {0};
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0b11111111111111111111111111111111;
  a.bits[2] = 0b11111111111111111111111111111111;
  a.bits[3] = 0b00000000000000000000000000000000;
  b = {0};
  b.bits[0] = 0b00000000000000000000000000000010;
  b.bits[1] = 0b00000000000000000000000000000000;
  b.bits[2] = 0b00000000000000000000000000000000;
  b.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(a, b, &s21_res), 1);




   a = {0};
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0b11111111111111111111111111111111;
  a.bits[2] = 0b11111111111111111111111111111111;
  a.bits[3] = 0b00000000000000000000000000000000;
  b = {0};
  b.bits[0] = 0b00000000000000000000000000000101;
  b.bits[1] = 0b00000000000000000000000000000000;
  b.bits[2] = 0b00000000000000000000000000000000;
  b.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(a, b, &s21_res), 1);




  a = {0};
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0b11111111111111111111111111111111;
  a.bits[2] = 0b11111111111111111111111111111111;
  a.bits[3] = 0b00000000000000000000000000000000;
  b = {0};
  b.bits[0] = 0b00000000000000000000000000000001;
  b.bits[1] = 0b00000000000000000000000000000000;
  b.bits[2] = 0b00000000000000000000000000000000;
  b.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(a, b, &s21_res), 1);



  a = {0};
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0b11111111111111111111111111111111;
  a.bits[2] = 0b11111111111111111111111111111111;
  a.bits[3] = 0b10000000000000000000000000000000;
  b = {0};
  b.bits[0] = 0b00000000000000000000000000000010;
  b.bits[1] = 0b00000000000000000000000000000000;
  b.bits[2] = 0b00000000000000000000000000000000;
  b.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal original_res = {0};
  original_dec_res.bits[0] = 0b11111111111111111111111111111110;
  original_dec_res.bits[1] = 0b11111111111111111111111111111111;
  original_dec_res.bits[2] = 0b11111111111111111111111111111111;
  original_dec_res.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_add(a, b, &s21_res);
  ck_assert_int_eq(s21_add(a, b, &s21_res), 0);
  ck_assert_int_eq(original_dec_res.bits[0], s21_dec_res.bits[0]);
  ck_assert_int_eq(original_dec_res.bits[1], s21_dec_res.bits[1]);
  ck_assert_int_eq(original_dec_res.bits[2], s21_dec_res.bits[2]);
  ck_assert_int_eq(original_dec_res.bits[3], s21_dec_res.bits[3]);





  a = {0};
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0b11111111111111111111111111111111;
  a.bits[2] = 0b11111111111111111111111111111111;
  a.bits[3] = 0b10000000000000000000000000000000;
  b = {0};
  b.bits[0] = 0b00000000000000000000000000000101;
  b.bits[1] = 0b00000000000000000000000000000000;
  b.bits[2] = 0b00000000000000000000000000000000;
  b.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal original_res = {0};
  original_dec_res.bits[0] = 0b11111111111111111111111111111110;
  original_dec_res.bits[1] = 0b11111111111111111111111111111111;
  original_dec_res.bits[2] = 0b11111111111111111111111111111111;
  original_dec_res.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_add(a, b, &s21_res);
  ck_assert_int_eq(s21_add(a, b, &s21_res), 0);
  ck_assert_int_eq(original_dec_res.bits[0], s21_dec_res.bits[0]);
  ck_assert_int_eq(original_dec_res.bits[1], s21_dec_res.bits[1]);
  ck_assert_int_eq(original_dec_res.bits[2], s21_dec_res.bits[2]);
  ck_assert_int_eq(original_dec_res.bits[3], s21_dec_res.bits[3]);




  a = {0};
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0b11111111111111111111111111111111;
  a.bits[2] = 0b11111111111111111111111111111111;
  a.bits[3] = 0b10000000000000000000000000000000;
  b = {0};
  b.bits[0] = 0b00000000000000000000000000000001;
  b.bits[1] = 0b00000000000000000000000000000000;
  b.bits[2] = 0b00000000000000000000000000000000;
  b.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal original_res = {0};
  original_dec_res.bits[0] = 0b11111111111111111111111111111110;
  original_dec_res.bits[1] = 0b11111111111111111111111111111111;
  original_dec_res.bits[2] = 0b11111111111111111111111111111111;
  original_dec_res.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_add(a, b, &s21_res);
  ck_assert_int_eq(s21_add(a, b, &s21_res), 0);
  ck_assert_int_eq(original_dec_res.bits[0], s21_dec_res.bits[0]);
  ck_assert_int_eq(original_dec_res.bits[1], s21_dec_res.bits[1]);
  ck_assert_int_eq(original_dec_res.bits[2], s21_dec_res.bits[2]);
  ck_assert_int_eq(original_dec_res.bits[3], s21_dec_res.bits[3]);




  a = {0};
  a.bits[0] = 0b00000000000000000000001111111111;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000010000000000000000;
  b = {0};
  b.bits[0] = 0b00000000000000000000001111111111;
  b.bits[1] = 0b00000000000000000000000000000000;
  b.bits[2] = 0b00000000000000000000000000000000;
  b.bits[3] = 0b00000000000000100000000000000000;
  s21_decimal original_res = {0};
  original_dec_res.bits[0] = 0b00000000000000000010101111110101;
  original_dec_res.bits[1] = 0b00000000000000000000000000000000;
  original_dec_res.bits[2] = 0b00000000000000000000000000000000;
  original_dec_res.bits[3] = 0b00000000000000100000000000000000;
  s21_decimal s21_res = {0};
  s21_add(a, b, &s21_res);
  ck_assert_int_eq(s21_add(a, b, &s21_res), 0);
  ck_assert_int_eq(original_dec_res.bits[0], s21_dec_res.bits[0]);
  ck_assert_int_eq(original_dec_res.bits[1], s21_dec_res.bits[1]);
  ck_assert_int_eq(original_dec_res.bits[2], s21_dec_res.bits[2]);
  ck_assert_int_eq(original_dec_res.bits[3], s21_dec_res.bits[3]);
*/
}
END_TEST

START_TEST(test_from_decimal_to_int) {
  s21_decimal src;
  int result = 0, number = 0;

  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 2147483647);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 133141;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 133141);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 2147483647;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = MINUS;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -2147483647);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 123451234;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = MINUS;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -123451234);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 18;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = MINUS;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -18);
  ck_assert_int_eq(result, 0);

  number = 0;

  src.bits[0] = 0xffffffff;
  src.bits[1] = 0xffffffff;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 0);
  ck_assert_int_eq(result, 1);

  result = 0;

  src.bits[0] = 0x1fffffff;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 536870911);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 100;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 100);
  ck_assert_int_eq(result, 0);

  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, INT_MAX);
  ck_assert_int_eq(result, 0);

  src.bits[0] = INT_MAX;
  src.bits[1] = INT_MAX;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(result, 1);

  src.bits[0] = INT_MAX;
  src.bits[1] = INT_MAX;
  src.bits[2] = INT_MAX;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(result, 1);

  src.bits[0] = INT_MAX;
  src.bits[1] = INT_MAX;
  src.bits[2] = INT_MAX;
  src.bits[3] = INT_MAX;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 3);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -1);
  ck_assert_int_eq(result, 0);

  src.bits[0] = UINT_MAX;
  src.bits[1] = UINT_MAX;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(result, 1);

  src.bits[0] = UINT_MAX;
  src.bits[1] = UINT_MAX;
  src.bits[2] = UINT_MAX;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(result, 1);

  src.bits[0] = UINT_MAX;
  src.bits[1] = UINT_MAX;
  src.bits[2] = UINT_MAX;
  src.bits[3] = UINT_MAX;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -7);
  ck_assert_int_eq(result, 0);

  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = MINUS;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -INT_MAX);
  ck_assert_int_eq(result, 0);

  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0x00010000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 214748364);
  ck_assert_int_eq(result, 0);

  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0x801C0000;  // MINUS + exp 28
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 0);
  ck_assert_int_eq(result, 0);

  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0x001C0000;  // exp 28
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 0);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b10000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000001;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -2147483648);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b00000000000000000000000000000001;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 1);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b10000000000000000000000000000001;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -2147483647);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b00000000000000000000000000000010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 2);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b00000000000000000000000000100011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 3);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b00000000000000000000000000101101;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -4);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b10110011000011000010101010010001;
  src.bits[1] = 0b00000000000000000000000000001100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -5454);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b00000111100110110001111110011000;
  src.bits[1] = 0b01100110010010001001000110100011;
  src.bits[2] = 0b00000000000001001000101100011101;
  src.bits[3] = 0b10000000000110000000000000000000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -5);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b00011011110101100011100010001010;
  src.bits[1] = 0b00000000000000101101010000010100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001100000000000000000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 796132784);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b01111000100010101111010011001010;
  src.bits[1] = 0b01100010000010101110010010000111;
  src.bits[2] = 0b00100111111001000001101011010101;
  src.bits[3] = 0b10000000000101010000000000000000;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -12345677);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal) {
  s21_decimal val;

  s21_from_int_to_decimal(0, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  s21_from_int_to_decimal(-128, &val);
  ck_assert_int_eq(val.bits[0], 128);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], -2147483648);

  s21_from_int_to_decimal(127, &val);
  ck_assert_int_eq(val.bits[0], 127);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  s21_from_int_to_decimal(-2147483648, &val);
  ck_assert_int_eq(val.bits[0], -2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], -2147483648);

  s21_from_int_to_decimal(2147483647, &val);
  ck_assert_int_eq(val.bits[0], 2147483647);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_from_decimal_to_float) {
  s21_decimal src;
  int result;
  float number;

  src.bits[0] = 18122;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0x80030000;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -18.122);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 1812;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = MINUS;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0xffffff;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 16777215);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 23450987;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0x80040000;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0xFFFFFFFF;
  src.bits[1] = 0xFFFFFFFF;
  src.bits[2] = 0;
  src.bits[3] = 0;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, (float)0xffffffffffffffff);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 18122;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0x80030000;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -18.122);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 1812;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0x80000000;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0b00000000000000001011010101110101;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001010000000000000000;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -0.46453);
  ck_assert_int_eq(result, 0);

  src.bits[0] = 0x65EEE000;
  src.bits[1] = 0x5C254346;
  src.bits[2] = 1;
  src.bits[3] = 0b00000000000100110000000000000000;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 2.5086531268974139743);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal) {
  s21_decimal val;
  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;
  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);

  fl1 = -128.023;
  fl2 = 12345.37643764;
  fl1_res = 0;
  fl2_res = 0;
  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);

  float num = -2.1474836E+09;
  s21_from_float_to_decimal(num, &val);
  ck_assert_int_eq(val.bits[0], -2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], -2147483648);

  fl1 = 22.14836E+03;
  fl2 = -2.1474836E+09;
  fl1_res = 0;
  fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);

  s21_from_float_to_decimal(1.02E+09, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  fl1 = -333.2222;
  fl2 = -2.1474836E+20;
  fl1_res = 0;
  fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);

  float a = 1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  a = 1e-30;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  s21_decimal dec;
  float tmp = 0;
  float tmp1 = 0.03;
  s21_from_float_to_decimal(tmp1, &dec);
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, tmp1, 1e-06);

  s21_from_float_to_decimal(-128.023, &dec);
  tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -128.023, 1e-06);

  s21_from_float_to_decimal(-2.1474836E+09, &dec);
  tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -2.1474836E+09, 1e-06);

  s21_from_float_to_decimal(22.14836E+03, &dec);
  tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 22.14836E+03, 1e-06);

  s21_from_float_to_decimal(1.02E+08, &dec);
  tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 1.02E+08, 1e-06);

  s21_from_float_to_decimal(-333.2222, &dec);
  tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -333.2222, 1e-06);

  a = 1.0 / 0.0;
  int ret = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);

  a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(dec.bits[0], 0);
  ck_assert_int_eq(dec.bits[1], 0);
  ck_assert_int_eq(dec.bits[2], 0);
  ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

Suite *suite_s21_decimal(void) {
  Suite *s;
  TCase *tc_tests;

  s = suite_create("test_s21_decimal_suite");
  tc_tests = tcase_create("s21_decimal");

  tcase_add_test(tc_tests, test_add);
  tcase_add_test(tc_tests, test_from_decimal_to_int);
  tcase_add_test(tc_tests, test_from_int_to_decimal);
  tcase_add_test(tc_tests, test_from_decimal_to_float);
  tcase_add_test(tc_tests, test_from_float_to_decimal);

  suite_add_tcase(s, tc_tests);
  return s;
}

int main(void) {
  Suite *s = suite_s21_decimal();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? 0 : 1;
}