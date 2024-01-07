#ifndef S21_DECIMAL_H_
#define S21_DECIMAL_H_

#include <stdint.h>

#define MINUS 0x80000000     // minus 10000000 00000000 00000000 00000000
#define SC 0x00ff0000        // scale 00000000 11111111 00000000 00000000
#define MAX4BITE 0xffffffff  // max4b 11111111 11111111 11111111 11111111
#define FIRST 0xFFFF         // FIRST 00000000 00000000 11111111 11111111
#define SECOND 0x7F000000    // FIRST 01111111 00000000 00000000 00000000

#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

typedef struct {
  int bits[4];
} s21_decimal;

// Расширенный decimal для того чтобы было удобно выполнять все операции
typedef struct {
  uint64_t bits[7];  // используем в два раза больший int на 64 бита
  uint16_t scale;  // для скейла используем маленький int
} work_decimal;

typedef struct {
  s21_decimal decimals[2];
} big_decimal;

// Work convertors
work_decimal decimal_to_work(s21_decimal dec);
s21_decimal work_to_decimal(work_decimal dec);

// Arithmetic Operators
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Comparison Operators
int s21_is_less(s21_decimal dec1, s21_decimal dec2);
int s21_is_less_or_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater_or_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_not_equal(s21_decimal dec1, s21_decimal dec2);

// Convertors and parsers
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Another functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Support functions
int work_is_less(work_decimal dec1_work, work_decimal dec2_work);
int work_is_equal(work_decimal dec1_work, work_decimal dec2_work);
int work_sub(work_decimal value_1, work_decimal value_2, work_decimal *result);
int work_mul(work_decimal dec1_work, work_decimal dec2_work,
             work_decimal *temp_dec);

void bit_left(work_decimal *dec1_work, int shift);
void div_upper_loop(work_decimal *temp_dec, const work_decimal *dec2_work,
                    work_decimal *dec1_work, int sign, int *res,
                    work_decimal *dec3_work);
void div_down_loop(work_decimal *temp_dec, const work_decimal *dec2_work,
                   work_decimal *dec1_work, work_decimal *dec3_work, int *scale,
                   int *temp_div, int *is_it_first_loop);

void point_to_normal(work_decimal *dec1_work, work_decimal *dec2_work);

int getoverflow(work_decimal *dec);
int pointleft(work_decimal *dec);
int pointright(work_decimal *dec);
int normalize(work_decimal *dec, const int summ, const int sign);

int multiplication(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
big_decimal binary_mul(s21_decimal value_1, s21_decimal value_2);
s21_decimal s21_round_banking(s21_decimal integral, s21_decimal fractional);
int s21_int128_binary_compare(s21_decimal d1, s21_decimal d2);
int work_decimal_binary_compare(work_decimal d1, work_decimal d2);

static const s21_decimal all_ten_pows[39] = {
    [0] = {{0x1, 0x0, 0x0, 0x0}},
    [1] = {{0xA, 0x0, 0x0, 0x0}},
    [2] = {{0x64, 0x0, 0x0, 0x0}},
    [3] = {{0x3E8, 0x0, 0x0, 0x0}},
    [4] = {{0x2710, 0x0, 0x0, 0x0}},
    [5] = {{0x186A0, 0x0, 0x0, 0x0}},
    [6] = {{0xF4240, 0x0, 0x0, 0x0}},
    [7] = {{0x989680, 0x0, 0x0, 0x0}},
    [8] = {{0x5F5E100, 0x0, 0x0, 0x0}},
    [9] = {{0x3B9ACA00, 0x0, 0x0, 0x0}},
    [10] = {{0x540BE400, 0x2, 0x0, 0x0}},
    [11] = {{0x4876E800, 0x17, 0x0, 0x0}},
    [12] = {{0xD4A51000, 0xE8, 0x0, 0x0}},
    [13] = {{0x4E72A000, 0x918, 0x0, 0x0}},
    [14] = {{0x107A4000, 0x5AF3, 0x0, 0x0}},
    [15] = {{0xA4C68000, 0x38D7E, 0x0, 0x0}},
    [16] = {{0x6FC10000, 0x2386F2, 0x0, 0x0}},
    [17] = {{0x5D8A0000, 0x1634578, 0x0, 0x0}},
    [18] = {{0xA7640000, 0xDE0B6B3, 0x0, 0x0}},
    [19] = {{0x89E80000, 0x8AC72304, 0x0, 0x0}},
    [20] = {{0x63100000, 0x6BC75E2D, 0x5, 0x0}},
    [21] = {{0xDEA00000, 0x35C9ADC5, 0x36, 0x0}},
    [22] = {{0xB2400000, 0x19E0C9BA, 0x21E, 0x0}},
    [23] = {{0xF6800000, 0x2C7E14A, 0x152D, 0x0}},
    [24] = {{0xA1000000, 0x1BCECCED, 0xD3C2, 0x0}},
    [25] = {{0x4A000000, 0x16140148, 0x84595, 0x0}},
    [26] = {{0xE4000000, 0xDCC80CD2, 0x52B7D2, 0x0}},
    [27] = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x0}},
    [28] = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}},
    [29] = {{0xA0000000, 0x6D7217CA, 0x431E0FAE, 0x1}},
    [30] = {{0x40000000, 0x4674EDEA, 0x9F2C9CD0, 0xC}},
    [31] = {{0x80000000, 0xC0914B26, 0x37BE2022, 0x7E}},
    [32] = {{0x0, 0x85ACEF81, 0x2D6D415B, 0x4EE}},
    [33] = {{0x0, 0x38C15B0A, 0xC6448D93, 0x314D}},
    [34] = {{0x0, 0x378D8E64, 0xBEAD87C0, 0x1ED09}},
    [35] = {{0x0, 0x2B878FE8, 0x72C74D82, 0x134261}},
    [36] = {{0x0, 0xB34B9F10, 0x7BC90715, 0xC097CE}},
    [37] = {{0x0, 0xF436A0, 0xD5DA46D9, 0x785EE10}},
    [38] = {{0x0, 0x98A2240, 0x5A86C47A, 0x4B3B4CA8}}};

static const float fails_big[] = {
    340282346638528859811704183484516925440.f,
    340282326356119256160033759537265639424.f,
    340282306073709652508363335590014353408.f,
    170141173319264429905852091742258462720.f,
    226854897759019239874469455656344616960.f,
    283568632339978851668922031544056414208.f,
    85070586659632214952926045871129231360.f,
    85070591730234615865843651857942052864.f,
    5316911666227013434557877866945576960.f,
    2658455991569831745807614120560689152.f,
    20769186196199271228741710417756160.f,
    10384593717069655257060992658440192.f,
    158456325028528675187087900672.0f,
    158456315583795709447797473280.0f,
    158456306139062743708507045888.0f,
    316912631167591418895594946560.f,
    158456325028528675187087900672.f,
    79228190848463234811415232512.f,
    79228181403730269072124805120.f,
    79228171958997303332834377728.f,
    79228162514264337593543950336.f,
    79228162514264337593543950335.f,
};

static const float fails_small[] = {
    0.00000000000000000000000000009999999429857660888699309391359540480357727713304344f,
    0.00000000000000000000000000009999998828004553267688105311366433422567940670147579f,
    0.00000000000000000000000000009999998226151445646676901231373326364778153626990814f,
    0.00000000000000000000000000009000000028539691658739462124217382784332763280814999f,
    0.00000000000000000000000000005000000015855384254855256735676323769073757378230555f,
    0.00000000000000000000000000004999999714928830444349654695679770240178863856652172f,
    4.999999414002276633844052655683216711283970335073789659219301029224880039691925048828125E-29f,
    1.2621774483536188886587657044524579674771302961744368076324462890625E-29f,
    1.0000000031710768509710513471352647538147514756461109453056224083411507308483123779296875E-29f,
    7.7037193183714626222678539700519994217126886949453196668630670929101000865557580254971981E-34f,
    4.8148245739821641389174087312824996385704304343408247917894169330688125540973487659357488E-35f,
    1.1754943508222875079687365372222456778186655567720875215087517062784172594547271728515625E-38f,
    1.4012984643248170709237295832899161312802619418765157717570682838897910826858606014866381E-45f,
};

#endif  // S21_DECIMAL_H_