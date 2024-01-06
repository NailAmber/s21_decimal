#ifndef S21_DECIMAL_TEST_H_
#define S21_DECIMAL_TEST_H_

#include <check.h>

#include "s21_decimal.h"

Suite *suite_s21_decimal(void);
void test_mul1(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_mul_fail1(s21_decimal decimal1, s21_decimal decimal2, int code_check);
void test_mul_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check);
                    void test_round(s21_decimal decimal, s21_decimal decimal_check);

#endif  // S21_DECIMAL_TEST_H_