#include "s21_decimal_test.h"

#include <check.h>
#include <limits.h>

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

Suite *suite_s21_decimal(void) {
  Suite *s;
  TCase *tc_tests;

  s = suite_create("test_s21_decimal_suite");
  tc_tests = tcase_create("s21_decimal");

  tcase_add_test(tc_tests, test_add);
  tcase_add_test(tc_tests, test_from_decimal_to_int);
  tcase_add_test(tc_tests, test_from_int_to_decimal);
  tcase_add_test(tc_tests, test_from_decimal_to_float);

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