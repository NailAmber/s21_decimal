#include "s21_decimal.h"

#include <limits.h>

#include "s21_decimal_test.h"

START_TEST(test_add) {
  {
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
  }
  {
    s21_decimal val1 = {{15, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{15, 0, 0, 0}};
    s21_decimal val2 = {{15, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal val2 = {{1, 0, 0, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(1, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(2, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{8, 0, 0, 0}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{2, 0, 0, 0}};
    s21_decimal val2 = {{8, 0, 0, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{8, 0, 0, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {0};
    s21_decimal val2 = {0};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{4, 0, 0, 0}};
    s21_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {0};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{4, 0, 0, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(2, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{4, 0, 0, 0}};
    s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
  }
  {
    s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(2, s21_add(val1, val2, &res));
  }
  {
    s21_decimal c = {{5, 0, 0, 0}};
    s21_decimal d = {{5, 0, 0, 0}};
    s21_decimal etalon = {{10, 0, 0, 0}};
    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(add, 0);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{100, 0, 0, 0}};
    s21_decimal d = {{100, 0, 0, 0}};
    s21_decimal etalon = {{100, 0, 0, 0}};
    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;
    int add = s21_add(c, d, p_res);
    ;
    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(add, 0);
    ck_assert_int_eq(equal, 0);
  }
  {
    s21_decimal c = {{2147483647, 0, 0, 0}};
    s21_decimal d = {{2147483647, 0, 0, 0}};
    s21_decimal etalon = {{0xFFFFFFFE, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal* p_result = &result;

    int add = s21_add(c, d, p_result);
    ck_assert_int_eq(add, 0);
    ;
    int equal = s21_is_equal(result, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1000, 0, 0, 0}};
    s21_decimal d = {{1000, 0, 0, 0}};
    s21_decimal etalon = {{2000, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal* p_result = &result;

    int add = s21_add(c, d, p_result);
    ck_assert_int_eq(add, 0);
    ;
    int equal = s21_is_equal(result, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1000, 0, 0, ~(INT_MAX)}};
    s21_decimal d = {{1000, 0, 0, 0}};
    s21_decimal etalon = {{0, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal* p_result = &result;

    int add = s21_add(c, d, p_result);
    ck_assert_int_eq(add, 0);
    ;
    int equal = s21_is_equal(result, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
    s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
    s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal* p_result = &result;

    int add = s21_add(c, d, p_result);
    ck_assert_int_eq(add, 0);
    ;
    int equal = s21_is_equal(*p_result, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0, 0, 0, 0}};
    s21_decimal d = {{0, 0, 0, 0}};
    s21_decimal etalon = {{0, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1, 0, 0, 0}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{2, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1000, 0, 0, 0}};
    s21_decimal d = {{1000, 0, 0, 0}};
    s21_decimal etalon = {{2000, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{INT_MAX, 0, 0, 0}};
    s21_decimal d = {{INT_MAX, 0, 0, 0}};
    s21_decimal etalon = {{0xFFFFFFFE, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{INT_MAX, 0, 0, 0}};
    s21_decimal d = {{INT_MAX, 0, 0, 0}};
    s21_decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{UINT32_MAX, 0, 0, 0}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{0, 1, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[3], etalon.bits[3]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[0], etalon.bits[0]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0, UINT_MAX - 1, 0, 0}};
    s21_decimal d = {{0, 1, 0, 0}};
    s21_decimal etalon = {{0, UINT_MAX, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0, 0, UINT_MAX - 1, 0}};
    s21_decimal d = {{0, 0, 1, 0}};
    s21_decimal etalon = {{0, 0, UINT_MAX, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }

  {
    s21_decimal c = {{0, 0, 0, ~(INT_MAX)}};
    s21_decimal d = {{0, 0, 0, ~(INT_MAX)}};
    s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{0, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
    s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
    s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[3], etalon.bits[3]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[0], etalon.bits[0]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{11, 0, 0, 65536}};
    s21_decimal d = {{0, 0, 0, 0}};
    s21_decimal etalon = {{11, 0, 0, 65536}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{11, 0, 0, 65536}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{21, 0, 0, 65536}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{111, 0, 0, 65536}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{121, 0, 0, 65536}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{111, 0, 0, 196608}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{1111, 0, 0, 196608}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
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

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{UINT32_MAX - 1, UINT32_MAX, 0, 0}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{UINT32_MAX, UINT32_MAX, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
    s21_decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
    s21_decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0b10001001111001111111111111111111,
                      0b10001010110001110010001100000100, 0, 0}};
    s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
    s21_decimal etalon = {{0b10001001111010000000000000000000,
                           0b10001010110001110010001100000100, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{UINT_MAX, UINT_MAX, 0, 0}};
    s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
    s21_decimal etalon = {{0, 0, 1, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }

  {
    s21_decimal c = {{0b10000010111000100101101011101101,
                      0b11111001111010000010010110101101,
                      0b10110000001111101111000010010100,
                      0b10000000000011100000000000000000}};
    s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
    s21_decimal etalon = {{0b01110001001010101101101011101101,
                           0b00101110001111001110000111111000,
                           0b10110000001111101110111101101101,
                           0b10000000000011100000000000000000}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0b10000010111000100101101011101101,
                      0b11111001111010000010010110101101,
                      0b10110000001111101111000010010100,
                      0b10000000000011100000000000000000}};
    s21_decimal d = {{0b01001000000110110001111110011000,
                      0b11111011111111011000100101101101,
                      0b00000000000001000110110101110111,
                      0b10000000000110000000000000000000}};
    s21_decimal etalon = {{0b10110110001010011011010111011010,
                           0b11111001111010100000110001111111,
                           0b10110000001111101111000010010100,
                           0b10000000000011100000000000000000}};
    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);
    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal a, b, origin;
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

    int equal = s21_is_equal(result, origin);
    ck_assert_int_eq(equal, 1);
  }

  {
    s21_decimal c = {{0, 0, 0, 0}};
    s21_decimal d = {{0, 0, 0, 0}};
    s21_decimal etalon = {{0, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1, 0, 0, 0}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{2, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1000, 0, 0, 0}};
    s21_decimal d = {{1000, 0, 0, 0}};
    s21_decimal etalon = {{2000, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);
    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{INT_MAX, 0, 0, 0}};
    s21_decimal d = {{INT_MAX, 0, 0, 0}};
    s21_decimal etalon = {{0xFFFFFFFE, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{INT_MAX, 0, 0, 0}};
    s21_decimal d = {{INT_MAX, 0, 0, 0}};
    s21_decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{UINT_MAX, 0, 0, 0}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{0, 1, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[3], etalon.bits[3]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[0], etalon.bits[0]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0, UINT_MAX - 1, 0, 0}};
    s21_decimal d = {{0, 1, 0, 0}};
    s21_decimal etalon = {{0, UINT_MAX, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0, 0, UINT_MAX - 1, 0}};
    s21_decimal d = {{0, 0, 1, 0}};
    s21_decimal etalon = {{0, 0, UINT_MAX, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0, 0, 0, ~(INT_MAX)}};
    s21_decimal d = {{0, 0, 0, ~(INT_MAX)}};
    s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{0, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
    s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
    s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{11, 0, 0, 65536}};
    s21_decimal d = {{0, 0, 0, 0}};
    s21_decimal etalon = {{11, 0, 0, 65536}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{11, 0, 0, 65536}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{21, 0, 0, 65536}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{111, 0, 0, 65536}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{121, 0, 0, 65536}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{111, 0, 0, 196608}};
    s21_decimal d = {{1, 0, 0, 0}};
    s21_decimal etalon = {{1111, 0, 0, 196608}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);
    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
    s21_decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
    s21_decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0b10001001111001111111111111111111,
                      0b10001010110001110010001100000100, 0, 0}};
    s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
    s21_decimal etalon = {{0b10001001111010000000000000000000,
                           0b10001010110001110010001100000100, 0, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{UINT_MAX, UINT_MAX, 0, 0}};
    s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
    s21_decimal etalon = {{0, 0, 1, 0}};

    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;

    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal c = {{0b10000010111000100101101011101101,
                      0b11111001111010000010010110101101,
                      0b10110000001111101111000010010100,
                      0b10000000000011100000000000000000}};
    s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
    s21_decimal etalon = {{0b01110001001010101101101011101101,
                           0b00101110001111001110000111111000,
                           0b10110000001111101110111101101101,
                           0b10000000000011100000000000000000}};
    s21_decimal res = {{0, 0, 0, 0}};
    s21_decimal* p_res = &res;
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);
    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);
    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(equal, 1);
  }

  {
    s21_decimal a = {0};
    a.bits[0] = 0b11111111111111111111111111111111;
    a.bits[1] = 0b11111111111111111111111111111111;
    a.bits[2] = 0b11111111111111111111111111111111;
    a.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal b = {0};
    b.bits[0] = 0b00000000000000000000000000000010;
    b.bits[1] = 0b00000000000000000000000000000000;
    b.bits[2] = 0b00000000000000000000000000000000;
    b.bits[3] = 0b00000000000000110000000000000000;
    s21_decimal s21_res = {0};
    ck_assert_int_eq(s21_add(a, b, &s21_res), 1);
  }
  {
    s21_decimal a = {0};
    a.bits[0] = 0b11111111111111111111111111111111;
    a.bits[1] = 0b11111111111111111111111111111111;
    a.bits[2] = 0b11111111111111111111111111111111;
    a.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal b = {0};
    b.bits[0] = 0b00000000000000000000000000000101;
    b.bits[1] = 0b00000000000000000000000000000000;
    b.bits[2] = 0b00000000000000000000000000000000;
    b.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal s21_res = {0};
    ck_assert_int_eq(s21_add(a, b, &s21_res), 1);
  }
  {
    s21_decimal a = {0};
    a.bits[0] = 0b11111111111111111111111111111111;
    a.bits[1] = 0b11111111111111111111111111111111;
    a.bits[2] = 0b11111111111111111111111111111111;
    a.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal b = {0};
    b.bits[0] = 0b00000000000000000000000000000001;
    b.bits[1] = 0b00000000000000000000000000000000;
    b.bits[2] = 0b00000000000000000000000000000000;
    b.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal s21_res = {0};
    ck_assert_int_eq(s21_add(a, b, &s21_res), 1);
  }
  {
    s21_decimal src1 = {0};
    src1.bits[0] = 0xffffffff;
    src1.bits[1] = 0xffffffff;
    src1.bits[2] = 0xffffffff;
    src1.bits[3] = 0x80000000;
    s21_decimal src2 = {0};
    src2.bits[0] = 0x00000002;  // 0.002
    src2.bits[1] = 0x00000000;
    src2.bits[2] = 0x00000000;
    src2.bits[3] = 0x00030000;
    s21_decimal original_res = {0};
    original_res.bits[0] = 0xfffffffe;
    original_res.bits[1] = 0xffffffff;
    original_res.bits[2] = 0xffffffff;
    original_res.bits[3] = 0x80000000;
    s21_decimal s21_res = {0};
    // s21_add(src1, src2, &s21_res);
    ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
    ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
    ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
    ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
    ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
  }
  {
    s21_decimal a = {0};
    a.bits[0] = 0b11111111111111111111111111111111;
    a.bits[1] = 0b11111111111111111111111111111111;
    a.bits[2] = 0b11111111111111111111111111111111;
    a.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal b = {0};
    b.bits[0] = 0b00000000000000000000000000000101;
    b.bits[1] = 0b00000000000000000000000000000000;
    b.bits[2] = 0b00000000000000000000000000000000;
    b.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal original_res = {0};
    original_res.bits[0] = 0b11111111111111111111111111111110;
    original_res.bits[1] = 0b11111111111111111111111111111111;
    original_res.bits[2] = 0b11111111111111111111111111111111;
    original_res.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal s21_res = {0};
    s21_add(a, b, &s21_res);
    ck_assert_int_eq(s21_add(a, b, &s21_res), 0);
    ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
    ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
    ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
    ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
  }
  {
    s21_decimal a = {0};
    a.bits[0] = 0b11111111111111111111111111111111;
    a.bits[1] = 0b11111111111111111111111111111111;
    a.bits[2] = 0b11111111111111111111111111111111;
    a.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal b = {0};
    b.bits[0] = 0b00000000000000000000000000000001;
    b.bits[1] = 0b00000000000000000000000000000000;
    b.bits[2] = 0b00000000000000000000000000000000;
    b.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal original_res = {0};
    original_res.bits[0] = 0b11111111111111111111111111111110;
    original_res.bits[1] = 0b11111111111111111111111111111111;
    original_res.bits[2] = 0b11111111111111111111111111111111;
    original_res.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal s21_res = {0};
    s21_add(a, b, &s21_res);
    ck_assert_int_eq(s21_add(a, b, &s21_res), 0);
    ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
    ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
    ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
    ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
  }
  {
    s21_decimal a = {0};
    a.bits[0] = 0b00000000000000000000001111111111;
    a.bits[1] = 0b00000000000000000000000000000000;
    a.bits[2] = 0b00000000000000000000000000000000;
    a.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal b = {0};
    b.bits[0] = 0b00000000000000000000001111111111;
    b.bits[1] = 0b00000000000000000000000000000000;
    b.bits[2] = 0b00000000000000000000000000000000;
    b.bits[3] = 0b00000000000000100000000000000000;
    s21_decimal original_res = {0};
    original_res.bits[0] = 0b00000000000000000010101111110101;
    original_res.bits[1] = 0b00000000000000000000000000000000;
    original_res.bits[2] = 0b00000000000000000000000000000000;
    original_res.bits[3] = 0b00000000000000100000000000000000;
    s21_decimal s21_res = {0};
    s21_add(a, b, &s21_res);
    ck_assert_int_eq(s21_add(a, b, &s21_res), 0);
    ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
    ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
    ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
    ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
  }

  {
    s21_decimal src1 = {0};
    src1.bits[0] = 0x00000000;
    src1.bits[1] = 0x0000000f;
    src1.bits[2] = 0x00000000;
    src1.bits[3] = 0x00000000;
    s21_decimal src2 = {0};
    src2.bits[0] = 0x00000001;
    src2.bits[1] = 0x00000000;
    src2.bits[2] = 0x00000000;
    src2.bits[3] = 0x80000000;
    s21_decimal original_res = {0};
    original_res.bits[0] = 0xffffffff;
    original_res.bits[1] = 0x0000000e;
    original_res.bits[2] = 0x00000000;
    original_res.bits[3] = 0x00000000;
    s21_decimal s21_res = {0};
    ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
    ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
    ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
    ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
    ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
  }
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

START_TEST(test_div) {
  {
    int num1 = 100;
    int num2 = 50;
    int res_origin = 2;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
  }
  {
    int num1 = -32768;
    int num2 = 2;
    int res_origin = -16384;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
  }
  {
    int num1 = 2;
    int num2 = 2;
    int res_origin = 1;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
  }
  {
    int num1 = 0;
    int num2 = 5;
    int res_origin = num1 / num2;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
  }
  {
    s21_decimal dec1 = {{100, 0, 0, 0}};
    s21_decimal dec2 = {{99999, 0, 0, 0}};

    float res_s21 = 0;
    float res = 100.0 / 99999.0;

    s21_decimal res1;
    s21_div(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
  }
  {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = 100;
    float tmp2 = 999.99;
    float res_s21 = 0.0;
    float res = 0.100001;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_float_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_div(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
  }
  {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = -100;
    int tmp2 = -99999;
    float res_s21 = 0;
    float res = 0.00100001;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_div(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
  }
  {
    s21_decimal dec1 = {{10.0e3, 0, 0, 0}};
    s21_decimal dec2 = {{2.00e2, 0, 0, 0}};

    int res_s21 = 0;
    int res = 50;

    s21_decimal res1;
    s21_div(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
  }
  {
    s21_decimal dec1 = {{1110, 0, 0, 0}};
    s21_decimal dec2 = {{0, 0, 0, 0}};

    s21_decimal res1;
    int res = s21_div(dec1, dec2, &res1);
    ck_assert_int_eq(res, 3);
  }

  {
    s21_decimal dec1 = {{0xffffffff, 0xffffffff, 0xffff, 0}};
    s21_decimal dec2 = {{0xf, 0, 0, 0x00ff0000}};

    s21_decimal res1;
    int res = s21_div(dec1, dec2, &res1);
    ck_assert_int_eq(res, 1);
  }

  {
    s21_decimal dec1 = {{0xffffffff, 0xffffffff, 0xffff, 0}};
    s21_decimal dec2 = {{0xf, 0, 0, 0x80ff0000}};

    s21_decimal res1;
    int res = s21_div(dec1, dec2, &res1);
    ck_assert_int_eq(res, 2);
  }
  {
    s21_decimal dec1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
    s21_decimal dec2 = {{0x1, 0, 0, 0x80000000}};
    s21_decimal res_dec = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80000000}};

    s21_decimal res1;
    int res = s21_div(dec1, dec2, &res1);
    ck_assert_int_eq(res, 0);
    ck_assert_int_eq(res_dec.bits[0], res1.bits[0]);
    ck_assert_int_eq(res_dec.bits[1], res1.bits[1]);
    ck_assert_int_eq(res_dec.bits[2], res1.bits[2]);
    ck_assert_int_eq(res_dec.bits[3], res1.bits[3]);
  }
}
END_TEST

START_TEST(test_mul) {
  {
    int num1 = -10;
    int num2 = -10;
    int prod_int = 100;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_mul(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, prod_int);
  }
  {
    int num1 = 10;
    int num2 = 20;
    int prod_int = 200;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_mul(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, prod_int);
  }
  {
    int num1 = -10;
    int num2 = 20;
    int prod_int = -200;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_mul(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, prod_int);
  }
  {
    int num1 = 9403;
    int num2 = 202;
    int res_origin = 1899406;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_mul(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
  }
  {
    int num1 = -32768;
    int num2 = 2;
    int res_origin = -65536;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_mul(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
  }
  {
    int num1 = -32768;
    int num2 = 32768;
    int res_origin = -1073741824;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_mul(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
  }
  {
    float num1 = 9403.0e2;
    int num2 = 202;
    float res_origin = (float)189940600;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_float_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    float res_float = 0;
    s21_mul(a, b, &res_dec);
    s21_from_decimal_to_float(res_dec, &res_float);
    ck_assert_float_eq(res_float, res_origin);
  }
  {
    float num1 = 9403.0e2;
    float num2 = 9403.0e2;
    float res_origin = (float)884164090000;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_float_to_decimal(num1, &a);
    s21_from_float_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    float res_float = 0;
    s21_mul(a, b, &res_dec);
    s21_from_decimal_to_float(res_dec, &res_float);
    ck_assert_float_eq(res_float, res_origin);
  }
  {
    s21_decimal dec1 = {{4, 0, 0, 0}};
    s21_decimal dec2 = {{10, 0, 0, 0}};

    s21_decimal d22;
    s21_mul(dec1, dec2, &d22);

    int qqqq = 0;
    s21_from_decimal_to_int(d22, &qqqq);
    ck_assert_int_eq(qqqq, 40);
  }

  {
    s21_decimal dst1;
    dst1.bits[0] = 0b01110000000000000000000000000000;
    dst1.bits[1] = 0b10110011000000110001000010100111;
    dst1.bits[2] = 0b11100010001011101010010010010011;
    dst1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal dst2;
    dst2.bits[0] = 0b00000000000000000000000000000001;
    dst2.bits[1] = 0b10000000000000100000000000000000;
    dst2.bits[2] = 0b00000000000000000000000000000000;
    dst2.bits[3] = 0b00000000000000000000000000000000;

    s21_decimal d22;
    int error = s21_mul(dst1, dst2, &d22);

    // int qqqq = 0;
    // s21_from_decimal_to_int(d22, &qqqq);
    ck_assert_int_eq(error, 1);
  }

  {
    s21_decimal dst1;
    dst1.bits[0] = 0b01110000000000000000000000000000;
    dst1.bits[1] = 0b10110011000000110001000010100111;
    dst1.bits[2] = 0b11100010001011101010010010010011;
    dst1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal dst2;
    dst2.bits[0] = 0b00000000000000000000000000000001;
    dst2.bits[1] = 0b10000000000000100000000000000000;
    dst2.bits[2] = 0b00000000000000000000000000000000;
    dst2.bits[3] = 0b10000000000000000000000000000000;

    s21_decimal d22;
    int error = s21_mul(dst1, dst2, &d22);

    // int qqqq = 0;
    // s21_from_decimal_to_int(d22, &qqqq);
    ck_assert_int_eq(error, 2);
  }
}
END_TEST

START_TEST(test_sub) {
  {
    int num1 = -10;
    int num2 = -10;
    int dif_int = 0;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_sub(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, dif_int);
  }

  {
    int num1 = 10;
    int num2 = 20;
    int dif_int = -10;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_sub(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, dif_int);
  }
  {
    int num1 = -10;
    int num2 = 20;
    int dif_int = -30;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_sub(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, dif_int);
  }
  {
    float num1 = 9403.0;
    float num2 = 202.09e8;
    float dif_float = num1 - num2;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_float_to_decimal(num1, &a);
    s21_from_float_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    float res_float = 0.0;
    s21_sub(a, b, &res_dec);
    s21_from_decimal_to_float(res_dec, &res_float);
    ck_assert_float_eq(res_float, dif_float);
  }
  {
    float num1 = -1.0 / 0.0;
    int num2 = 202;
    double dif_float = 0 - num2;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_float_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    float res_float = 0.0;
    s21_sub(a, b, &res_dec);
    s21_from_decimal_to_float(res_dec, &res_float);
    ck_assert_float_eq(res_float, dif_float);
  }
  {  // 1045
    s21_decimal src1, src2, origin;
    // src1 = 4;
    // src2 = 97623323;

    src1.bits[0] = 0b00000000000000000000000000000100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;

    src2.bits[0] = 0b00000101110100011001110100011011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_sub(src1, src2, &result);

    origin.bits[0] = 0b00000101110100011001110100010111;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 1331
    s21_decimal src1, src2, origin;
    // src1 = 12345677.987654345678987654346;
    // 12345677.987654345678987654346
    // src2 = 87654323456.9876545678987653;
    // 87654323456.9876545678987653
    // printf("\ns21_subTest19 s21_subTest19 s21_subTest19\n\n");

    src1.bits[0] = 0b10010001000010101111010011001010;
    src1.bits[1] = 0b11000000010001011101010111110010;
    src1.bits[2] = 0b00100111111001000001101100000000;
    src1.bits[3] = 0b00000000000101010000000000000000;

    src2.bits[0] = 0b00010001110011011101000110000101;
    src2.bits[1] = 0b11110101101111000110111111000000;
    src2.bits[2] = 0b00000010110101010000111100111111;
    src2.bits[3] = 0b00000000000100000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_sub(src1, src2, &result);
    // 87641977779.00000022221977764 exp 17

    origin.bits[0] = 0b10010010000001100111100010100100;
    origin.bits[1] = 0b10001011011010100100100011011111;
    origin.bits[2] = 0b00011100010100011001001100010001;
    origin.bits[3] = 0b10000000000100010000000000000000;
    // print_2(&src1);
    // print_2(&src2);
    // print_2(&result);
    // print_2(&origin);
    // 87641977779.00000022221977765 exp 17
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
}
END_TEST

START_TEST(test_is_equal) {
  {
    float num1 = 1.375342323523;
    float num2 = 1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    float num1 = 1.39;
    float num2 = 1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    float num1 = 1.39;
    float num2 = -1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    int num1 = 0;
    int num2 = 0;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    int num1 = -3;
    int num2 = -3;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    float num1 = 7.9e+28;
    float num2 = 1.342;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    float num1 = NAN;
    float num2 = 2.3;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(0, &dec1);
    s21_from_int_to_decimal(0, &dec2);
    dec1.bits[3] = 0;
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
  }

  {
    s21_decimal dec1 = {{0, 0, 0, 0x80000000}}, dec2 = {{0, 0, 0, 0}};
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
  }
}
END_TEST

START_TEST(test_is_less) {
  {
    float num1 = 1.375342323523;
    float num2 = 1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_less(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    float num1 = 1.39;
    float num2 = 1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_less(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    float num1 = 1.39;
    float num2 = -1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_less(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    int num1 = 3;
    int num2 = 9;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_less(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    int num1 = -3;
    int num2 = -3;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_less(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    float num1 = -34534534.232446543232446543;
    float num2 = -3.232323233232323233;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_less(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }

  s21_decimal dec5 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000}};  // -1.2
  ck_assert_int_eq(s21_is_less(dec5, dec6), 0);
  ck_assert_int_eq(s21_is_less(dec6, dec5), 1);

  s21_decimal dec7 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  s21_decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(s21_is_less(dec7, dec8), 1);
  ck_assert_int_eq(s21_is_less(dec8, dec7), 0);

  s21_decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(s21_is_less(dec1, dec2), 0);
  ck_assert_int_eq(s21_is_less(dec2, dec1), 1);

  s21_decimal dec3 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  s21_decimal dec4 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;
  ck_assert_int_eq(s21_is_less(dec3, dec4), 1);
  ck_assert_int_eq(s21_is_less(dec4, dec3), 0);

  s21_decimal dec9 = {{12345, 0, 0, 0}};
  s21_decimal dec10 = {{12345, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(dec9, dec10), 0);
  ck_assert_int_eq(s21_is_less(dec10, dec9), 0);

  s21_decimal dec11 = {{0, 0, 0, 0}};
  s21_decimal dec12 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(dec11, dec12), 0);
  ck_assert_int_eq(s21_is_less(dec12, dec11), 0);
}
END_TEST

START_TEST(test_is_greater_or_equal) {
  {
    float num1 = 1.375323;
    float num2 = 1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    int num1 = 2;
    int num2 = 1;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    float num1 = 1.39;
    float num2 = -1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    int num1 = 0;
    int num2 = 0;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    int num1 = 3;
    int num2 = 9;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    int num1 = -3;
    int num2 = -3;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    int num1 = 10;
    int num2 = 3;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    float num1 = 10423546.34534534;
    float num2 = 3.34534534;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    float num1 = -3.34534534;
    float num2 = 3.34534534;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }

  {
    float num1 = 1042634.34534534;
    float num2 = 10424546.34534534;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    float num1 = 10426.34534534;
    float num2 = 104234.345345;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    float num1 = 1042.5667777;
    float num2 = 1042.345345;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_greater_or_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
}
END_TEST

START_TEST(test_is_not_equal) {
  {
    float num1 = 1.375342323523;
    float num2 = 1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_not_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    float num1 = 1.39;
    float num2 = 1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_not_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    float num1 = 1.39;
    float num2 = -1.39;
    s21_decimal dec1, dec2;
    s21_from_float_to_decimal(num1, &dec1);
    s21_from_float_to_decimal(num2, &dec2);
    int res = s21_is_not_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    int num1 = 0;
    int num2 = 0;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_not_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
  {
    int num1 = 3;
    int num2 = 9;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_not_equal(dec1, dec2);
    ck_assert_int_eq(res, 1);
  }
  {
    int num1 = -3;
    int num2 = -3;
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(num1, &dec1);
    s21_from_int_to_decimal(num2, &dec2);
    int res = s21_is_not_equal(dec1, dec2);
    ck_assert_int_eq(res, 0);
  }
}
END_TEST

START_TEST(test_floor) {
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b10010011111100000001110001010010;
    dec1.bits[1] = 0b00000000000000000000000100100000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000010100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000001111011;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b00000000000000000000000010100101;
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000010000;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] = 0x93FFFC52;  // 2483027.026
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000000110000000000000000;  // 3
    s21_decimal result;
    result.bits[0] = 0x25E353;  // 2483027
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }

  {
    s21_decimal dec1;
    dec1.bits[0] = 0x93FFFC53;  // 2483027.027
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0x80030000;  // 3
    s21_decimal result;
    result.bits[0] = 0x25E354;  // 2483028
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0x80000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }

  {
    s21_decimal dec1;

    dec1.bits[0] = 0b00001111111111111111111111111111;
    dec1.bits[1] = 0b00111110001001010000001001100001;
    dec1.bits[2] = 0b00100000010011111100111001011110;
    dec1.bits[3] = 0b00000000000010100000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b10100111011000111111111111111111;
    result.bits[1] = 0b00001101111000001011011010110011;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b00001111111111111111111111111111;
    dec1.bits[1] = 0b00111110001001010000001001100001;
    dec1.bits[2] = 0b00100000010011111100111001011110;
    dec1.bits[3] = 0b10000000000010100000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b10100111011001000000000000000000;
    result.bits[1] = 0b00001101111000001011011010110011;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0xBD278452;  // 3173483602
    dec1.bits[1] = 0x1C;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000010010000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000001111100;  // 124
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b10010011111100000001110001010010;
    dec1.bits[1] = 0b00000000000000000000000100100000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000010100000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000001111011;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b01010101001110101110101110110001;
    dec1.bits[1] = 0b00001101101101001101101001011111;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000100100000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000000001;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b01010101001110101110101110110001;
    dec1.bits[1] = 0b00001101101101001101101001011111;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000100100000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000000000;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b10010111011100111001111111111111;
    dec1.bits[1] = 0b00111100000010000011000110001101;
    dec1.bits[2] = 0b00000000000000000000000000000001;
    dec1.bits[3] = 0b00000000000001110000000000000000;
    s21_decimal result;
    s21_floor(dec1, &result);
    s21_decimal result_origin;
    result_origin.bits[3] = 0;
    result_origin.bits[2] = 0;
    result_origin.bits[1] = 0b00000000000000000000001000010010;
    result_origin.bits[0] = 0b00110110101101101000110000111111;
    ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
    ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
    ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
    ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
  }

  {
    s21_decimal dec1;
    dec1.bits[0] = 0b10010011111100000001110001010010;
    dec1.bits[1] = 0b00000000000000000000000100100000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000010100000000000000000;
    float num = 0.0;
    s21_from_decimal_to_float(dec1, &num);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000001111011;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b00000000000000000000000010100101;
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000000010000000000000000;
    float num = 0.0;
    s21_from_decimal_to_float(dec1, &num);
    // printf("%f", num);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000010000;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }

  {  // 7130
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = 2;

    src1.bits[0] = 0b00000000000000000000000000000010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 7151
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = 3.5;

    src1.bits[0] = 0b00000000000000000000000000100011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    origin.bits[0] = 0b00000000000000000000000000000011;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 7172
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = -3.5;

    src1.bits[0] = 0b00000000000000000000000000100011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    origin.bits[0] = 0b00000000000000000000000000000100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 7193
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = 0;

    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 7214
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = -1.2;

    src1.bits[0] = 0b00000000000000000000000000001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 7235
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = -545454512454545.35265454545645;

    src1.bits[0] = 0b10000010111000100101101011101101;
    src1.bits[1] = 0b11111001111010000010010110101101;
    src1.bits[2] = 0b10110000001111101111000010010100;
    src1.bits[3] = 0b10000000000011100000000000000000;
    origin.bits[0] = 0b10000110011101001011101110010010;
    origin.bits[1] = 0b00000000000000011111000000010110;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 7256
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = -5.492654545456454545645464;

    src1.bits[0] = 0b00000111100110110001111110011000;
    src1.bits[1] = 0b01100110010010001001000110100011;
    src1.bits[2] = 0b00000000000001001000101100011101;
    src1.bits[3] = 0b10000000000110000000000000000000;
    origin.bits[0] = 0b00000000000000000000000000000110;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 7277
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = 7961327845421.879754123131254;

    src1.bits[0] = 0b01001110111001000011100101110110;
    src1.bits[1] = 0b01001011001101011010000111011001;
    src1.bits[2] = 0b00011001101110010111010010111111;
    src1.bits[3] = 0b00000000000011110000000000000000;
    origin.bits[0] = 0b10100100000111100100000000101101;
    origin.bits[1] = 0b00000000000000000000011100111101;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 7298
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = -12345677.187654345678987654346;

    src1.bits[0] = 0b01111000100010101111010011001010;
    src1.bits[1] = 0b01100010000010101110010010000111;
    src1.bits[2] = 0b00100111111001000001101011010101;
    src1.bits[3] = 0b10000000000101010000000000000000;

    origin.bits[0] = 0b00000000101111000110000101001110;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 7319
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = 2.1986531268974139743;

    src1.bits[0] = 0b00010010001110001101100101011111;
    src1.bits[1] = 0b00110001000111111101100110110011;
    src1.bits[2] = 0b00000000000000000000000000000001;
    src1.bits[3] = 0b00000000000100110000000000000000;
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 7340
    s21_decimal src1, origin, result = {{0, 0, 0, 0}};
    // src1 = 1;

    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    s21_floor(src1, &result);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
}
END_TEST

START_TEST(test_round) {
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b10010011111100000001110001010010;
    dec1.bits[1] = 0b00000000000000000000000100100000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000010100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000001111100;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b00000000000000000000000010100101;  // -16.5
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000000010000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000010000;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b11111111111111111111111111111111;  // 18014398509481.983
    dec1.bits[1] = 0b00000000001111111111111111111111;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000000110000000000000000;
    s21_decimal result;

    result.bits[0] = 0b01001101110100101111000110101001;  // 18014398509481
    result.bits[1] = 0b00000000000000000001000001100010;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b00000000000011110111001001110100;  // -10123.40
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000000110000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000001111110100;  // -1012
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b10000000000000000000001111110100;  // 112590205.4327284
    dec1.bits[1] = 0b00000000000001000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000001110000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000110101101011111110101111101;  // 112590205
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result;
    result.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b01100011000011111111111111111111;
    dec1.bits[1] = 0b01101011110001110101111000101101;
    dec1.bits[2] = 0b00000000000000000000000000000101;
    dec1.bits[3] = 0b10000000000010100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b01010100000010111110010000000000;
    result.bits[1] = 0b00000000000000000000000000000010;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b01010101001110101110101110110001;
    dec1.bits[1] = 0b00001101101101001101101001011111;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000100100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000000001;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b10010011111100000001110001010010;
    dec1.bits[1] = 0b00000000000000000000000100100000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000010100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000001111100;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b11001101110001110111110001000000;
    dec1.bits[1] = 0b00111110001001010000001001100000;
    dec1.bits[2] = 0b00100000010011111100111001011110;
    dec1.bits[3] = 0b10000000000001000000000000000000;
    s21_decimal result;
    result.bits[0] = 0b10100000111111100100111000000100;
    result.bits[1] = 0b00011011110011101100110011101101;
    result.bits[2] = 0b00000000000000001101001111000010;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b10100000111111100100111000000100;
    dec1.bits[1] = 0b00011011110011101100110011101101;
    dec1.bits[2] = 0b00000000000000001101001111000010;
    dec1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b10100000111111100100111000000100;
    result.bits[1] = 0b00011011110011101100110011101101;
    result.bits[2] = 0b00000000000000001101001111000010;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b10010111011100111001111111111111;
    dec1.bits[1] = 0b00111100000010000011000110001101;
    dec1.bits[2] = 0b00000000000000000000000000000001;
    dec1.bits[3] = 0b00000000000001110000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00110110101101101000110001000000;
    result.bits[1] = 0b00000000000000000000001000010010;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b10010111011100111001111111111111;
    dec1.bits[1] = 0b00111100000010000011000110001101;
    dec1.bits[2] = 0b00000000000000000000000000000001;
    dec1.bits[3] = 0b10000000000001110000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00110110101101101000110001000000;
    result.bits[1] = 0b00000000000000000000001000010010;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;

    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {  // 8053
    s21_decimal src1, origin;
    // src1 = 2;

    src1.bits[0] = 2;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 2;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8074
    s21_decimal src1, origin;
    // src1 = 3.5;

    src1.bits[0] = 0b00000000000000000000000000100011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8095
    s21_decimal src1, origin;
    // src1 = -3.5;

    src1.bits[0] = 0b00000000000000000000000000100011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8116
    s21_decimal src1, origin;
    // src1 = 0;

    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8137
    s21_decimal src1, origin;
    // src1 = -9878798789;

    src1.bits[0] = 0b01001100110100101000000111000101;
    src1.bits[1] = 0b00000000000000000000000000000010;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b01001100110100101000000111000101;
    origin.bits[1] = 0b00000000000000000000000000000010;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8158
    s21_decimal src1, origin;
    // src1 = -545454512454545.35265;

    src1.bits[0] = 0b11011110101101001010101001100001;
    src1.bits[1] = 0b11110100111110000101111011101001;
    src1.bits[2] = 0b00000000000000000000000000000010;
    src1.bits[3] = 0b10000000000001010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b10000110011101001011101110010001;
    origin.bits[1] = 0b00000000000000011111000000010110;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8179
    s21_decimal src1, origin;
    // src1 = -5.492654545456454545645464;

    src1.bits[0] = 0b00000111100110110001111110011000;
    src1.bits[1] = 0b01100110010010001001000110100011;
    src1.bits[2] = 0b00000000000001001000101100011101;
    src1.bits[3] = 0b10000000000110000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8200
    s21_decimal src1, origin;
    // src1 = 7961327845421.879754123131254;

    src1.bits[0] = 0b01001110111001000011100101110110;
    src1.bits[1] = 0b01001011001101011010000111011001;
    src1.bits[2] = 0b00011001101110010111010010111111;
    src1.bits[3] = 0b00000000000011110000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b10100100000111100100000000101110;
    origin.bits[1] = 0b00000000000000000000011100111101;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8221
    s21_decimal src1, origin;
    // src1 = -12345677.187654345678987654346;

    src1.bits[0] = 0b01111000100010101111010011001010;
    src1.bits[1] = 0b01100010000010101110010010000111;
    src1.bits[2] = 0b00100111111001000001101011010101;
    src1.bits[3] = 0b10000000000101010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000101111000110000101001101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8242
    s21_decimal src1, origin;
    // src1 = 2.5986531268974139743;

    src1.bits[0] = 0xAFC8D95F;
    src1.bits[1] = 0x68A2B481;
    src1.bits[2] = 0x1;
    src1.bits[3] = 0b00000000000100110000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000011;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8263
    s21_decimal src1, origin;
    // src1 = 1;

    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8284
    s21_decimal src1, origin;
    // src1 = 1.1;

    src1.bits[0] = 0b00000000000000000000000000001011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8305
    s21_decimal src1, origin;
    // src1 = -1.1;

    src1.bits[0] = 0b00000000000000000000000000001011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8326
    s21_decimal src1, origin;
    // src1 = 24.56;

    src1.bits[0] = 0b00000000000000000000100110011000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000100000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000011001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 8347
    s21_decimal src1, origin;
    // src1 = -2.124;

    src1.bits[0] = 0b00000000000000000000100001001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000110000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }

  {
    s21_decimal src1, origin;

    src1.bits[0] = 25;
    src1.bits[1] = 0x0;
    src1.bits[2] = 0x0;
    src1.bits[3] = 0x00010000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 2;
    origin.bits[1] = 0x0;
    origin.bits[2] = 0x0;
    origin.bits[3] = 0x0;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {
    s21_decimal src1, origin;

    src1.bits[0] = 29;
    src1.bits[1] = 0x0;
    src1.bits[2] = 0x0;
    src1.bits[3] = 0x00010000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 3;
    origin.bits[1] = 0x0;
    origin.bits[2] = 0x0;
    origin.bits[3] = 0x0;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {
    s21_decimal src1, origin;

    src1.bits[0] = 21;
    src1.bits[1] = 0x0;
    src1.bits[2] = 0x0;
    src1.bits[3] = 0x00010000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 2;
    origin.bits[1] = 0x0;
    origin.bits[2] = 0x0;
    origin.bits[3] = 0x0;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {
    s21_decimal src1, origin;

    src1.bits[0] = 19;
    src1.bits[1] = 0x0;
    src1.bits[2] = 0x0;
    src1.bits[3] = 0x00010000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 2;
    origin.bits[1] = 0x0;
    origin.bits[2] = 0x0;
    origin.bits[3] = 0x0;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {
    s21_decimal src1, origin;

    src1.bits[0] = 15;
    src1.bits[1] = 0x0;
    src1.bits[2] = 0x0;
    src1.bits[3] = 0x00010000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 2;
    origin.bits[1] = 0x0;
    origin.bits[2] = 0x0;
    origin.bits[3] = 0x0;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {
    s21_decimal src1, origin;

    src1.bits[0] = 25;
    src1.bits[1] = 0x0;
    src1.bits[2] = 0x0;
    src1.bits[3] = 0x80010000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 2;
    origin.bits[1] = 0x0;
    origin.bits[2] = 0x0;
    origin.bits[3] = 0x80000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
}
END_TEST

START_TEST(test_truncate) {
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b00000000000000000000000011010011;  // 21.1
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000010101;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    ck_assert_int_eq(res1.bits[0], result.bits[0]);
    ck_assert_int_eq(res1.bits[1], result.bits[1]);
    ck_assert_int_eq(res1.bits[2], result.bits[2]);
    ck_assert_int_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b00000000000000000000000010100101;
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000010000;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] =
        0b11111111111111111111111111111111;  // 7922816251426433759354395033.5
    dec1.bits[1] = 0b11111111111111111111111111111111;
    dec1.bits[2] = 0b11111111111111111111111111111111;
    dec1.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal result;
    result.bits[0] = 0b10011001100110011001100110011001;
    result.bits[1] = 0b10011001100110011001100110011001;
    result.bits[2] = 0b00011001100110011001100110011001;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    ck_assert_int_eq(res1.bits[0], result.bits[0]);
    ck_assert_int_eq(res1.bits[1], result.bits[1]);
    ck_assert_int_eq(res1.bits[2], result.bits[2]);
    ck_assert_int_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;
    dec1.bits[0] = 0b10000000000000000000000010100101;  // 214.7483813
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000001110000000000000000;
    float num = 0.0;
    s21_from_decimal_to_float(dec1, &num);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000011010110;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    ck_assert_int_eq(res1.bits[0], result.bits[0]);
    ck_assert_int_eq(res1.bits[1], result.bits[1]);
    ck_assert_int_eq(res1.bits[2], result.bits[2]);
    ck_assert_int_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[3] = 0x000A0000;
    dec1.bits[2] = 0x0;
    dec1.bits[1] = 0xFFFFFFFF;
    dec1.bits[0] = 0xFFFFFFFF;
    s21_decimal result;
    result.bits[3] = 0x0;
    result.bits[2] = 0x0;
    result.bits[1] = 0x0;
    result.bits[0] = 0x6DF37F67;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[3] = 0b10000000000011000000000000000000;
    dec1.bits[2] = 0x0;
    dec1.bits[1] = 0xFFFFFFFF;
    dec1.bits[0] = 0xFFFFFFFF;
    s21_decimal result;
    result.bits[3] = 0b10000000000000000000000000000000;
    result.bits[2] = 0x0;
    result.bits[1] = 0x0;
    result.bits[0] = 0x1197998;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[3] = 0x80000000;
    dec1.bits[2] = 0x0;
    dec1.bits[1] = 0xFFFFFFFF;
    dec1.bits[0] = 0xFFFFFFFF;
    s21_decimal result;
    result.bits[3] = 0x80000000;
    result.bits[2] = 0x0;
    result.bits[1] = 0xFFFFFFFF;
    result.bits[0] = 0xFFFFFFFF;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b00000000000000000000000001101101;
    dec1.bits[1] = 0b00000000000011000110010101011011;
    dec1.bits[2] = 0b00000000000000000011000000111001;
    dec1.bits[3] = 0b00000000000011100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b10000111101111000001011000011110;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b11011110101001001000000010110110;
    dec1.bits[1] = 0b01011111101001011101111110100000;
    dec1.bits[2] = 0b00011111111010011010111101100000;
    dec1.bits[3] = 0b00000000000010010000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00110100101011011100000100111110;
    result.bits[1] = 0b10001001000100001000011110111001;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {
    s21_decimal dec1;

    dec1.bits[3] = 0x80090000;
    dec1.bits[2] = 0;
    dec1.bits[1] = 0xFFFFEA34;
    dec1.bits[0] = 0xFF837E4F;
    s21_decimal result;
    s21_truncate(dec1, &result);
    s21_decimal res1;

    res1.bits[3] = 0x80000000;
    res1.bits[2] = 0;
    res1.bits[1] = 0x4;
    res1.bits[0] = 0x4B829C70;
    ck_assert_int_eq(res1.bits[3], result.bits[3]);
    ck_assert_int_eq(res1.bits[2], result.bits[2]);
    ck_assert_int_eq(res1.bits[1], result.bits[1]);
    ck_assert_int_eq(res1.bits[0], result.bits[0]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b11010000101000110011000001101101;
    dec1.bits[1] = 0b00011111100110100110101101011000;
    dec1.bits[2] = 0;
    dec1.bits[3] = 0b00000000000010010000000000000000;
    s21_decimal result;
    s21_truncate(dec1, &result);
    s21_decimal result_origin;
    result_origin.bits[3] = 0;
    result_origin.bits[2] = 0;
    result_origin.bits[1] = 0;
    result_origin.bits[0] = 0b10000111101111000001011000011110;
    ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
    ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
    ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
    ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
  }
  {
    s21_decimal dec1;

    dec1.bits[0] = 0b01111000101001111011110011000110;
    dec1.bits[1] = 0b10011111111111001111101010000100;
    dec1.bits[2] = 0b00011111111010011010111101101101;
    dec1.bits[3] = 0b00000000000111000000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000000000;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
  }
  {  // 6766
    s21_decimal src1, origin;
    // src1 = 2;

    src1.bits[0] = 0b00000000000000000000000000000010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 6787
    s21_decimal src1, origin;
    // src1 = 3.5;

    src1.bits[0] = 0b00000000000000000000000000100011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b00000000000000000000000000000011;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 6808
    s21_decimal src1, origin;
    // src1 = 0;

    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 6829
    s21_decimal src1, origin;
    // src1 = 0;

    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 6850
    s21_decimal src1, origin;
    // src1 = -9878798789;

    src1.bits[0] = 0b01001100110100101000000111000101;
    src1.bits[1] = 0b00000000000000000000000000000010;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b01001100110100101000000111000101;
    origin.bits[1] = 0b00000000000000000000000000000010;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 6871
    s21_decimal src1, origin;
    // src1 = -545454512454545.35265454545645;

    src1.bits[0] = 0b10000010111000100101101011101101;
    src1.bits[1] = 0b11111001111010000010010110101101;
    src1.bits[2] = 0b10110000001111101111000010010100;
    src1.bits[3] = 0b10000000000011100000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b10000110011101001011101110010001;
    origin.bits[1] = 0b00000000000000011111000000010110;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 6892
    s21_decimal src1, origin;
    // src1 = -5.492654545456454545645464;

    src1.bits[0] = 0b00000111100110110001111110011000;
    src1.bits[1] = 0b01100110010010001001000110100011;
    src1.bits[2] = 0b00000000000001001000101100011101;
    src1.bits[3] = 0b10000000000110000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b00000000000000000000000000000101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 6913
    s21_decimal src1, origin;
    // src1 = 7961327845421.879754123131254;

    src1.bits[0] = 0b01001110111001000011100101110110;
    src1.bits[1] = 0b01001011001101011010000111011001;
    src1.bits[2] = 0b00011001101110010111010010111111;
    src1.bits[3] = 0b00000000000011110000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b10100100000111100100000000101101;
    origin.bits[1] = 0b00000000000000000000011100111101;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 6934
    s21_decimal src1, origin;
    // src1 = -12345677.187654345678987654346;

    src1.bits[0] = 0b01111000100010101111010011001010;
    src1.bits[1] = 0b01100010000010101110010010000111;
    src1.bits[2] = 0b00100111111001000001101011010101;
    src1.bits[3] = 0b10000000000101010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b00000000101111000110000101001101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 6955
    s21_decimal src1, origin;
    // src1 = 2.5086531268974139743;

    src1.bits[0] = 0b01100101111011101101100101011111;
    src1.bits[1] = 0b01011100001001010100001101000110;
    src1.bits[2] = 0b00000000000000000000000000000001;
    src1.bits[3] = 0b00000000000100110000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
  {  // 6976
    s21_decimal src1, origin;
    // src1 = 1;

    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);

    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
  }
}
END_TEST

START_TEST(test_negate) {
  {
    int a = 15;
    int res_a = 0;
    s21_decimal src;
    s21_decimal res;
    s21_from_int_to_decimal(a, &src);
    s21_negate(src, &res);
    s21_from_decimal_to_int(res, &res_a);
    ck_assert_int_eq(-15, res_a);
  }
  {
    float a = 10.12345;
    float res_a = 0;
    s21_decimal src;
    s21_decimal res;
    s21_from_float_to_decimal(a, &src);
    s21_negate(src, &res);
    s21_from_decimal_to_float(res, &res_a);
    ck_assert_float_eq(-10.12345, res_a);
  }
  {
    float a = 10.1234e5;
    float res_a = 0;
    s21_decimal src;
    s21_decimal res;
    s21_from_float_to_decimal(a, &src);
    s21_negate(src, &res);
    s21_from_decimal_to_float(res, &res_a);
    ck_assert_float_eq(-10.1234e5, res_a);
  }
  {
    float a = -10.1234e5;
    float res_a = 0;
    s21_decimal src;
    s21_decimal res;
    s21_from_float_to_decimal(a, &src);
    s21_negate(src, &res);
    s21_from_decimal_to_float(res, &res_a);
    ck_assert_float_eq(10.1234e5, res_a);
  }
  {
    int a = -15;
    int res_a = 0;
    s21_decimal src;
    s21_decimal res;
    s21_from_int_to_decimal(a, &src);
    s21_negate(src, &res);
    s21_from_decimal_to_int(res, &res_a);
    ck_assert_int_eq(15, res_a);
  }
  {
    s21_decimal b = {{0, 0, 0, 0}};
    s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};
    int negate = s21_negate(b, &etalon);
    ck_assert_int_eq(negate, 0);
  }
  {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal etalon = {{1, 0, 0, ~(INT_MAX)}};
    s21_decimal b = {{0, 0, 0, 0}};
    s21_decimal* ptr_b = &b;
    int add = s21_negate(a, ptr_b);
    ck_assert_int_eq(add, 0);
    int equal = s21_is_equal(b, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal a = {{1, 0, 0, ~(INT_MAX)}};
    s21_decimal etalon = {{1, 0, 0, 0}};
    s21_decimal b = {{0, 0, 0, 0}};
    s21_decimal* ptr_b = &b;
    int add = s21_negate(a, ptr_b);
    ck_assert_int_eq(add, 0);
    int equal = s21_is_equal(b, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal a = {{100, 0, 0, 0}};
    s21_decimal etalon = {{100, 0, 0, ~(INT_MAX)}};
    s21_decimal b = {{0, 0, 0, 0}};
    s21_decimal* ptr_b = &b;
    int add = s21_negate(a, ptr_b);
    ck_assert_int_eq(add, 0);
    int equal = s21_is_equal(b, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal a = {{100, 0, 0, ~(INT_MAX)}};
    s21_decimal etalon = {{100, 0, 0, 0}};
    s21_decimal b = {{0, 0, 0, 0}};
    s21_decimal* ptr_b = &b;
    int add = s21_negate(a, ptr_b);
    ck_assert_int_eq(add, 0);
    int equal = s21_is_equal(b, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal a = {{UINT_MAX, 0, 0, 0}};
    s21_decimal etalon = {{UINT_MAX, 0, 0, ~(INT_MAX)}};
    s21_decimal b = {{0, 0, 0, 0}};
    s21_decimal* ptr_b = &b;
    int add = s21_negate(a, ptr_b);
    ck_assert_int_eq(add, 0);
    int equal = s21_is_equal(b, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal etalon = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal b = {{0, 0, 0, 0}};
    s21_decimal* ptr_b = &b;
    int add = s21_negate(a, ptr_b);
    ck_assert_int_eq(add, 0);
    int equal = s21_is_equal(b, etalon);
    ck_assert_int_eq(equal, 0);
  }
  {
    s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal etalon = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(INT_MAX)}};
    s21_decimal b = {{0, 0, 0, 0}};
    s21_decimal* ptr_b = &b;
    int add = s21_negate(a, ptr_b);
    ck_assert_int_eq(add, 0);
    int equal = s21_is_equal(b, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(INT_MAX)}};
    s21_decimal etalon = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal b = {{0, 0, 0, 0}};
    s21_decimal* ptr_b = &b;
    int add = s21_negate(a, ptr_b);
    ck_assert_int_eq(add, 0);
    int equal = s21_is_equal(b, etalon);
    ck_assert_int_eq(equal, 1);
  }
  {
    s21_decimal val = {{2, 0, 0, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_negate(val, &res));
  }
  {
    s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_negate(val, &res));
  }
  {
    s21_decimal val = {{0, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_negate(val, &res));
  }
  {
    s21_decimal val = {0};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_negate(val, &res));
  }
}
END_TEST

Suite* suite_s21_decimal(void) {
  Suite* s;
  TCase* tc_tests;

  s = suite_create("test_s21_decimal_suite");
  tc_tests = tcase_create("s21_decimal");

  tcase_add_test(tc_tests, test_add);
  tcase_add_test(tc_tests, test_from_decimal_to_int);
  tcase_add_test(tc_tests, test_from_int_to_decimal);
  tcase_add_test(tc_tests, test_from_decimal_to_float);
  tcase_add_test(tc_tests, test_from_float_to_decimal);
  tcase_add_test(tc_tests, test_div);
  tcase_add_test(tc_tests, test_mul);
  tcase_add_test(tc_tests, test_sub);
  tcase_add_test(tc_tests, test_is_equal);
  tcase_add_test(tc_tests, test_is_less);
  tcase_add_test(tc_tests, test_is_greater_or_equal);
  tcase_add_test(tc_tests, test_is_not_equal);
  tcase_add_test(tc_tests, test_floor);
  tcase_add_test(tc_tests, test_round);
  tcase_add_test(tc_tests, test_truncate);
  tcase_add_test(tc_tests, test_negate);

  suite_add_tcase(s, tc_tests);
  return s;
}

int main(void) {
  Suite* s = suite_s21_decimal();
  SRunner* runner = srunner_create(s);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? 0 : 1;
}