#include "s21_math.h"
#include <check.h>
#include <math.h>
#include <stdlib.h>

START_TEST(s21_math_abs_1) {
    int x = 0;
    ck_assert_int_eq(s21_abs(x), abs(x));
} END_TEST

START_TEST(s21_math_abs_2) {
    int x = -1;
    ck_assert_int_eq(s21_abs(x), abs(x));
} END_TEST

START_TEST(s21_math_abs_3) {
    int x = 1;
    ck_assert_int_eq(s21_abs(x), abs(x));
} END_TEST

START_TEST(s21_math_fabs_1) {
    double x = 0.0;
    ck_assert_int_eq(s21_fabs(x), fabs(x));
} END_TEST

START_TEST(s21_math_fabs_2) {
    double x = -0.000001;
    ck_assert_int_eq(s21_fabs(x), fabs(x));
} END_TEST

START_TEST(s21_math_fabs_3) {
    double x = 0.000001;
    ck_assert_int_eq(s21_fabs(x), fabs(x));
} END_TEST

START_TEST(s21_math_fabs_4) {
    double x = 1.100000;
    ck_assert_int_eq(s21_fabs(x), fabs(x));
} END_TEST

START_TEST(s21_math_sqrt_1) {
    double x = 1;
    ck_assert_int_eq(s21_sqrt(x), sqrt(x));
} END_TEST

START_TEST(s21_math_sqrt_2) {
    double x = 0;
    ck_assert_int_eq(s21_sqrt(x), sqrt(x));
} END_TEST

START_TEST(s21_math_sqrt_3) {
    double x = 25.000000;
    ck_assert_int_eq(s21_sqrt(x), sqrt(x));
} END_TEST

START_TEST(s21_math_sqrt_4) {
    double x = 4.000000;
    ck_assert_int_eq(s21_sqrt(x), sqrt(x));
} END_TEST

START_TEST(s21_math_sqrt_5) {
    double x = 23.214234;
    ck_assert_int_eq(s21_sqrt(x), sqrt(x));
} END_TEST

START_TEST(s21_math_sqrt_6) {
    double x = 34567182.214234;
    ck_assert_int_eq(s21_sqrt(x), sqrt(x));
} END_TEST

START_TEST(s21_math_sqrt_7) {
    double x = 1235891021825672.214234;
    ck_assert_int_eq(s21_sqrt(x), sqrt(x));
} END_TEST

START_TEST(s21_math_sqrt_8) {
    double x = 36.00;
    ck_assert_int_eq(s21_sqrt(x), sqrt(x));
} END_TEST

START_TEST(s21_math_sqrt_9) {
    double x = 78.214234;
    ck_assert_int_eq(s21_sqrt(x), sqrt(x));
} END_TEST

START_TEST(s21_math_sqrt_10) {
    double x = -78.214234;
    ck_assert_int_eq(s21_sqrt(x), sqrt(x));
} END_TEST

START_TEST(s21_math_exp_1) {
    double x = 1;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_2) {
    double x = 0;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_3) {
    double x = 0.234879;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_4) {
    double x = 36.00;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_5) {
    double x =  2.718281;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_6) {
    double x =  6789.234791;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_7) {
    double x = 165.234791;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_8) {
    double x = 10234.000001;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_9) {
    double x = 0.290567;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_10) {
    double x = -0;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_11) {
    double x = -1;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_12) {
    double x = -2.20345;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_14) {
    double x = S21_INF;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_exp_15) {
    double x = -S21_INF;
    ck_assert_int_eq(s21_exp(x), exp(x));
} END_TEST

START_TEST(s21_math_pow_1) {
    double base = 0;
    double exp = 0;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_2) {
    double base = 1;
    double exp = 0;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_3) {
    double base = 0;
    double exp = 1;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_4) {
    double base = 1;
    double exp = 1;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_5) {
    double base = -1;
    double exp = 0;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_6) {
    double base = 0;
    double exp = 234;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_7) {
    double base = 27.21;
    double exp = 23;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_8) {
    double base = 27.21;
    double exp = 4.78;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_9) {
    double base = 278.256791;
    double exp = 2.78;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_10) {
    double base = 28792.2123456;
    double exp = 1.78;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_11) {
    double base = 2.000000;
    double exp = 2.0000001;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_12) {
    double base = 9.203;
    double exp = -3.9542;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_13) {
    double base = S21_INF;
    double exp = -3.9542;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_pow_14) {
    double base = 9.203;
    double exp = S21_INF;
    ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
} END_TEST

START_TEST(s21_math_sin_1) {
    double x = 1.;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_2) {
    double x = 0.25;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_3) {
    double x = 0.256379;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_4) {
    double x = 50.;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_5) {
    double x = 125.2592;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_6) {
    double x = 56789.;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_7) {
    double x = -1;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_8) {
    double x = -125.2592;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_fmod_1) {
    double x = 1;
    double y = 0;
    ck_assert_int_eq(s21_fmod(x, y), fmod(x, y));
} END_TEST

START_TEST(s21_math_fmod_2) {
    double x = 0;
    double y = 1;
    ck_assert_int_eq(s21_fmod(x, y), fmod(x, y));
} END_TEST

START_TEST(s21_math_fmod_3) {
    double x = 0;
    double y = 0;
    ck_assert_int_eq(s21_fmod(x, y), fmod(x, y));
} END_TEST

START_TEST(s21_math_fmod_4) {
    double x = 0.5;
    double y = 1;
    ck_assert_int_eq(s21_fmod(x, y), fmod(x, y));
} END_TEST

START_TEST(s21_math_fmod_5) {
    double x = 0.5;
    double y = -1;
    ck_assert_int_eq(s21_fmod(x, y), fmod(x, y));
} END_TEST

START_TEST(s21_math_fmod_6) {
    double x = 276892.209678;
    double y = -2657.275690;
    ck_assert_int_eq(s21_fmod(x, y), fmod(x, y));
} END_TEST

START_TEST(s21_math_fmod_7) {
    double x = 276.206782;
    double y = 8954.295671;
    ck_assert_int_eq(s21_fmod(x, y), fmod(x, y));
} END_TEST

START_TEST(s21_math_fmod_8) {
    double x = -0.5;
    double y = 2768043657218294.206782;
    ck_assert_int_eq(s21_fmod(x, y), fmod(x, y));
} END_TEST

START_TEST(s21_math_fmod_9) {
    double x = S21_INF;
    double y = S21_INF;
    ck_assert_int_eq(s21_fmod(x, y), fmod(x, y));
} END_TEST

START_TEST(s21_math_floor_1) {
    double x = 0;
    ck_assert_int_eq(s21_floor(x), floor(x));
} END_TEST

START_TEST(s21_math_floor_2) {
    double x = -1;
    ck_assert_int_eq(s21_floor(x), floor(x));
} END_TEST

START_TEST(s21_math_floor_3) {
    double x = 0.000001;
    ck_assert_int_eq(s21_floor(x), floor(x));
} END_TEST

START_TEST(s21_math_floor_4) {
    double x = 263745.296789;
    ck_assert_int_eq(s21_floor(x), floor(x));
} END_TEST

START_TEST(s21_math_floor_5) {
    double x = -203405689128346.000002;
    ck_assert_int_eq(s21_floor(x), floor(x));
} END_TEST

START_TEST(s21_math_floor_6) {
    double x = 0.5;
    ck_assert_int_eq(s21_floor(x), floor(x));
} END_TEST

START_TEST(s21_math_floor_7) {
    double x = S21_INF;
    ck_assert_int_eq(s21_floor(x), floor(x));
} END_TEST

START_TEST(s21_math_floor_8) {
    double x = -S21_INF;
    ck_assert_int_eq(s21_floor(x), floor(x));
} END_TEST

START_TEST(s21_math_floor_9) {
    double x = S21_NAN;
    ck_assert_int_eq(s21_floor(x), floor(x));
} END_TEST

START_TEST(s21_math_floor_10) {
    double x = 0.49;
    ck_assert_int_eq(s21_floor(x), floor(x));
} END_TEST

START_TEST(s21_math_sin_9) {
    double x = 0;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_10) {
    double x = 1;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_11) {
    double x = -1;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_12) {
    double x = 60;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_13) {
    double x = -360;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_14) {
    double x = 1.276892;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_15) {
    double x = 290.023945;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_16) {
    double x = 287902.025671;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_17) {
    double x = 2856926572168692.358673;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_sin_18) {
    double x = -8473285671829563.923945;
    ck_assert_int_eq(s21_sin(x), sin(x));
} END_TEST

START_TEST(s21_math_cos_1) {
    double x = 0;
    ck_assert_int_eq(s21_cos(x), cos(x));
} END_TEST

START_TEST(s21_math_cos_2) {
    double x = -1;
    ck_assert_int_eq(s21_cos(x), cos(x));
} END_TEST

START_TEST(s21_math_cos_3) {
    double x = 1;
    ck_assert_int_eq(s21_cos(x), cos(x));
} END_TEST

START_TEST(s21_math_cos_4) {
    double x = 0.000001;
    ck_assert_int_eq(s21_cos(x), cos(x));
} END_TEST

START_TEST(s21_math_cos_5) {
    double x = 27;
    ck_assert_int_eq(s21_cos(x), cos(x));
} END_TEST

START_TEST(s21_math_cos_7) {
    double x = 45.293659;
    ck_assert_int_eq(s21_cos(x), cos(x));
} END_TEST

START_TEST(s21_math_cos_8) {
    double x = -0;
    ck_assert_int_eq(s21_cos(x), cos(x));
} END_TEST

START_TEST(s21_math_cos_9) {
    double x = S21_INF;
    ck_assert_int_eq(s21_cos(x), cos(x));
} END_TEST

START_TEST(s21_math_cos_10) {
    double x = S21_NAN;
    ck_assert_int_eq(s21_cos(x), cos(x));
} END_TEST

START_TEST(s21_math_tan_1) {
    double x = 0;
    ck_assert_int_eq(s21_tan(x), tan(x));
} END_TEST

START_TEST(s21_math_tan_2) {
    double x = 1;
    ck_assert_int_eq(s21_tan(x), tan(x));
} END_TEST

START_TEST(s21_math_tan_3) {
    double x = -1;
    ck_assert_int_eq(s21_tan(x), tan(x));
} END_TEST

START_TEST(s21_math_tan_4) {
    double x = 0.5;
    ck_assert_int_eq(s21_tan(x), tan(x));
} END_TEST

START_TEST(s21_math_tan_5) {
    double x = 0.000001;
    ck_assert_int_eq(s21_tan(x), tan(x));
} END_TEST

START_TEST(s21_math_tan_6) {
    double x = 120.023945;
    ck_assert_int_eq(s21_tan(x), tan(x));
} END_TEST

START_TEST(s21_math_tan_7) {
    double x = -60;
    ck_assert_int_eq(s21_tan(x), tan(x));
} END_TEST

START_TEST(s21_math_tan_8) {
    double x = 2545.43;
    ck_assert_int_eq(s21_tan(x), tan(x));
} END_TEST

START_TEST(s21_math_tan_9) {
    double x = 176;
    ck_assert_int_eq(s21_tan(x), tan(x));
} END_TEST

START_TEST(s21_math_asin_1) {
    double x = 0;
    ck_assert_int_eq(s21_asin(x), asin(x));
} END_TEST

START_TEST(s21_math_asin_2) {
    double x = -1;
    ck_assert_int_eq(s21_asin(x), asin(x));
} END_TEST

START_TEST(s21_math_asin_3) {
    double x = 1;
    ck_assert_int_eq(s21_asin(x), asin(x));
} END_TEST

START_TEST(s21_math_asin_4) {
    double x = 0.869723;
    ck_assert_int_eq(s21_asin(x), asin(x));
} END_TEST

START_TEST(s21_math_asin_5) {
    double x = -0.234891;
    ck_assert_int_eq(s21_asin(x), asin(x));
} END_TEST

START_TEST(s21_math_asin_6) {
    double x = 1.23723;
    ck_assert_int_eq(s21_asin(x), asin(x));
} END_TEST

START_TEST(s21_math_asin_7) {
    double x = -2357;
    ck_assert_int_eq(s21_asin(x), asin(x));
} END_TEST

START_TEST(s21_math_acos_1) {
    double x = 0;
    ck_assert_int_eq(s21_acos(x), acos(x));
} END_TEST

START_TEST(s21_math_acos_2) {
    double x = 1;
    ck_assert_int_eq(s21_acos(x), acos(x));
} END_TEST

START_TEST(s21_math_acos_3) {
    double x = -1;
    ck_assert_int_eq(s21_acos(x), acos(x));
} END_TEST

START_TEST(s21_math_acos_4) {
    double x = 0.000001;
    ck_assert_int_eq(s21_acos(x), acos(x));
} END_TEST

START_TEST(s21_math_acos_5) {
    double x = 0.89999;
    ck_assert_int_eq(s21_acos(x), acos(x));
} END_TEST

START_TEST(s21_math_acos_6) {
    double x = -0.89999;
    ck_assert_int_eq(s21_acos(x), acos(x));
} END_TEST

START_TEST(s21_math_acos_7) {
    double x = 25;
    ck_assert_int_eq(s21_acos(x), acos(x));
} END_TEST

START_TEST(s21_math_acos_8) {
    double x = 2978.201293;
    ck_assert_int_eq(s21_acos(x), acos(x));
} END_TEST

START_TEST(s21_math_acos_9) {
    double x = 2934956021234067.201238;
    ck_assert_int_eq(s21_acos(x), acos(x));
} END_TEST

START_TEST(s21_math_acos_10) {
    double x = -297829302123.201293;
    ck_assert_int_eq(s21_acos(x), acos(x));
} END_TEST

START_TEST(s21_math_atan_1) {
    double x = 0;
    ck_assert_int_eq(s21_atan(x), atan(x));
} END_TEST

START_TEST(s21_math_atan_2) {
    double x = 1;
    ck_assert_int_eq(s21_atan(x), atan(x));
} END_TEST

START_TEST(s21_math_atan_3) {
    double x = -1;
    ck_assert_int_eq(s21_atan(x), atan(x));
} END_TEST

START_TEST(s21_math_atan_4) {
    double x = 0.000001;
    ck_assert_int_eq(s21_atan(x), atan(x));
} END_TEST

START_TEST(s21_math_atan_5) {
    double x = 0.999999;
    ck_assert_int_eq(s21_atan(x), atan(x));
} END_TEST

START_TEST(s21_math_atan_6) {
    double x = -0.25;
    ck_assert_int_eq(s21_atan(x), atan(x));
} END_TEST

START_TEST(s21_math_atan_7) {
    double x = 30;
    ck_assert_int_eq(s21_atan(x), atan(x));
} END_TEST

START_TEST(s21_math_atan_8) {
    double x = 25.25;
    ck_assert_int_eq(s21_atan(x), atan(x));
} END_TEST

START_TEST(s21_math_atan_9) {
    double x = -25.25;
    ck_assert_int_eq(s21_atan(x), atan(x));
} END_TEST

START_TEST(s21_math_atan_10) {
    double x = 1023967812934501.203945;
    ck_assert_int_eq(s21_atan(x), atan(x));
} END_TEST

START_TEST(s21_math_log_1) {
    double x = 0;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_2) {
    double x = 1;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_3) {
    double x = -1;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_4) {
    double x = 69;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_5) {
    double x = -69;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_6) {
    double x = 0.555555;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_7) {
    double x = 8679;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_8) {
    double x = 0.65;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_9) {
    double x = 25.2142;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_10) {
    double x = -0.5;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_11) {
    double x = S21_INF;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_log_12) {
    double x = S21_NAN;
    ck_assert_int_eq(s21_log(x), log(x));
} END_TEST

START_TEST(s21_math_ceil_1) {
    double x = 0.;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
} END_TEST

START_TEST(s21_math_ceil_2) {
    double x = 1.;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
} END_TEST

START_TEST(s21_math_ceil_3) {
    double x = -1.;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
} END_TEST

START_TEST(s21_math_ceil_4) {
    double x = 0.000001;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
} END_TEST

START_TEST(s21_math_ceil_5) {
    double x = 0.000049;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
} END_TEST

START_TEST(s21_math_ceil_6) {
    double x = 0.999999;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
} END_TEST

START_TEST(s21_math_ceil_7) {
    double x = 0.333333;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
} END_TEST

START_TEST(s21_math_ceil_8) {
    double x = 128394590123.000005;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
} END_TEST

START_TEST(s21_math_ceil_9) {
    double x = 0.000005;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
} END_TEST

START_TEST(s21_math_ceil_10) {
    double x = 1028475692103578.203485;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
} END_TEST

Suite *s21_math_suite(void) {
    Suite *s = suite_create("s21_math_test");

    // add Tcase
    TCase *tc_mathabs;
    tc_mathabs = tcase_create("s21_math_abs");

    tcase_add_test(tc_mathabs, s21_math_abs_1);
    tcase_add_test(tc_mathabs, s21_math_abs_2);
    tcase_add_test(tc_mathabs, s21_math_abs_3);
    suite_add_tcase(s, tc_mathabs);

    TCase *tc_mathfabs;
    tc_mathfabs = tcase_create("s21_math_fabs");

    tcase_add_test(tc_mathfabs, s21_math_fabs_1);
    tcase_add_test(tc_mathfabs, s21_math_fabs_2);
    tcase_add_test(tc_mathfabs, s21_math_fabs_3);
    tcase_add_test(tc_mathfabs, s21_math_fabs_4);
    suite_add_tcase(s, tc_mathfabs);

    TCase *tc_mathsqrt;
    tc_mathsqrt = tcase_create("s21_math_sqrt");

    tcase_add_test(tc_mathsqrt, s21_math_sqrt_1);
    tcase_add_test(tc_mathsqrt, s21_math_sqrt_2);
    tcase_add_test(tc_mathsqrt, s21_math_sqrt_3);
    tcase_add_test(tc_mathsqrt, s21_math_sqrt_4);
    tcase_add_test(tc_mathsqrt, s21_math_sqrt_5);
    tcase_add_test(tc_mathsqrt, s21_math_sqrt_6);
    tcase_add_test(tc_mathsqrt, s21_math_sqrt_7);
    tcase_add_test(tc_mathsqrt, s21_math_sqrt_8);
    tcase_add_test(tc_mathsqrt, s21_math_sqrt_9);
    tcase_add_test(tc_mathsqrt, s21_math_sqrt_10);
    suite_add_tcase(s, tc_mathsqrt);

    TCase *tc_mathexp;
    tc_mathexp = tcase_create("s21_math_exp");

    tcase_add_test(tc_mathexp, s21_math_exp_1);
    tcase_add_test(tc_mathexp, s21_math_exp_2);
    tcase_add_test(tc_mathexp, s21_math_exp_3);
    tcase_add_test(tc_mathexp, s21_math_exp_4);
    tcase_add_test(tc_mathexp, s21_math_exp_5);
    tcase_add_test(tc_mathexp, s21_math_exp_6);
    tcase_add_test(tc_mathexp, s21_math_exp_7);
    tcase_add_test(tc_mathexp, s21_math_exp_8);
    tcase_add_test(tc_mathexp, s21_math_exp_9);
    tcase_add_test(tc_mathexp, s21_math_exp_10);
    tcase_add_test(tc_mathexp, s21_math_exp_11);
    tcase_add_test(tc_mathexp, s21_math_exp_12);
    tcase_add_test(tc_mathexp, s21_math_exp_14);
    tcase_add_test(tc_mathexp, s21_math_exp_15);
    suite_add_tcase(s, tc_mathexp);

    TCase *tc_mathpow;
    tc_mathpow = tcase_create("s21_math_pow");

    tcase_add_test(tc_mathpow, s21_math_pow_1);
    tcase_add_test(tc_mathpow, s21_math_pow_2);
    tcase_add_test(tc_mathpow, s21_math_pow_3);
    tcase_add_test(tc_mathpow, s21_math_pow_4);
    tcase_add_test(tc_mathpow, s21_math_pow_5);
    tcase_add_test(tc_mathpow, s21_math_pow_6);
    tcase_add_test(tc_mathpow, s21_math_pow_7);
    tcase_add_test(tc_mathpow, s21_math_pow_8);
    tcase_add_test(tc_mathpow, s21_math_pow_9);
    tcase_add_test(tc_mathpow, s21_math_pow_10);
    tcase_add_test(tc_mathpow, s21_math_pow_11);
    tcase_add_test(tc_mathpow, s21_math_pow_12);
    tcase_add_test(tc_mathpow, s21_math_pow_13);
    tcase_add_test(tc_mathpow, s21_math_pow_14);
    suite_add_tcase(s, tc_mathpow);

    TCase *tc_mathsin;
    tc_mathsin = tcase_create("s21_math_sin");

    tcase_add_test(tc_mathsin, s21_math_sin_1);
    tcase_add_test(tc_mathsin, s21_math_sin_2);
    tcase_add_test(tc_mathsin, s21_math_sin_3);
    tcase_add_test(tc_mathsin, s21_math_sin_4);
    tcase_add_test(tc_mathsin, s21_math_sin_5);
    tcase_add_test(tc_mathsin, s21_math_sin_6);
    tcase_add_test(tc_mathsin, s21_math_sin_7);
    tcase_add_test(tc_mathsin, s21_math_sin_8);
    tcase_add_test(tc_mathsin, s21_math_sin_9);
    tcase_add_test(tc_mathsin, s21_math_sin_10);
    tcase_add_test(tc_mathsin, s21_math_sin_11);
    tcase_add_test(tc_mathsin, s21_math_sin_12);
    tcase_add_test(tc_mathsin, s21_math_sin_13);
    tcase_add_test(tc_mathsin, s21_math_sin_14);
    tcase_add_test(tc_mathsin, s21_math_sin_15);
    tcase_add_test(tc_mathsin, s21_math_sin_16);
    tcase_add_test(tc_mathsin, s21_math_sin_17);
    tcase_add_test(tc_mathsin, s21_math_sin_18);
    suite_add_tcase(s, tc_mathsin);

    TCase *tc_mathfmod;
    tc_mathfmod = tcase_create("s21_math_fmod");

    tcase_add_test(tc_mathfmod, s21_math_fmod_1);
    tcase_add_test(tc_mathfmod, s21_math_fmod_2);
    tcase_add_test(tc_mathfmod, s21_math_fmod_3);
    tcase_add_test(tc_mathfmod, s21_math_fmod_4);
    tcase_add_test(tc_mathfmod, s21_math_fmod_5);
    tcase_add_test(tc_mathfmod, s21_math_fmod_6);
    tcase_add_test(tc_mathfmod, s21_math_fmod_7);
    tcase_add_test(tc_mathfmod, s21_math_fmod_8);
    tcase_add_test(tc_mathfmod, s21_math_fmod_9);
    suite_add_tcase(s, tc_mathfmod);

    TCase *tc_mathfloor;
    tc_mathfloor = tcase_create("s21_math_floor");

    tcase_add_test(tc_mathfloor, s21_math_floor_1);
    tcase_add_test(tc_mathfloor, s21_math_floor_2);
    tcase_add_test(tc_mathfloor, s21_math_floor_3);
    tcase_add_test(tc_mathfloor, s21_math_floor_4);
    tcase_add_test(tc_mathfloor, s21_math_floor_5);
    tcase_add_test(tc_mathfloor, s21_math_floor_6);
    tcase_add_test(tc_mathfloor, s21_math_floor_7);
    tcase_add_test(tc_mathfloor, s21_math_floor_8);
    tcase_add_test(tc_mathfloor, s21_math_floor_9);
    tcase_add_test(tc_mathfloor, s21_math_floor_10);
    suite_add_tcase(s, tc_mathfloor);

    TCase *tc_mathcos;
    tc_mathcos = tcase_create("s21_math_cos");

    tcase_add_test(tc_mathcos, s21_math_cos_1);
    tcase_add_test(tc_mathcos, s21_math_cos_2);
    tcase_add_test(tc_mathcos, s21_math_cos_3);
    tcase_add_test(tc_mathcos, s21_math_cos_4);
    tcase_add_test(tc_mathcos, s21_math_cos_5);
    tcase_add_test(tc_mathcos, s21_math_cos_7);
    tcase_add_test(tc_mathcos, s21_math_cos_8);
    tcase_add_test(tc_mathcos, s21_math_cos_9);
    tcase_add_test(tc_mathcos, s21_math_cos_10);
    suite_add_tcase(s, tc_mathcos);

    TCase *tc_mathtan;
    tc_mathtan = tcase_create("s21_math_tan");

    tcase_add_test(tc_mathtan, s21_math_tan_1);
    tcase_add_test(tc_mathtan, s21_math_tan_2);
    tcase_add_test(tc_mathtan, s21_math_tan_3);
    tcase_add_test(tc_mathtan, s21_math_tan_4);
    tcase_add_test(tc_mathtan, s21_math_tan_5);
    tcase_add_test(tc_mathtan, s21_math_tan_6);
    tcase_add_test(tc_mathtan, s21_math_tan_7);
    tcase_add_test(tc_mathtan, s21_math_tan_8);
    tcase_add_test(tc_mathtan, s21_math_tan_9);
    suite_add_tcase(s, tc_mathtan);

    TCase *tc_mathasin;
    tc_mathasin = tcase_create("s21_math_asin");

    tcase_add_test(tc_mathasin, s21_math_asin_1);
    tcase_add_test(tc_mathasin, s21_math_asin_2);
    tcase_add_test(tc_mathasin, s21_math_asin_3);
    tcase_add_test(tc_mathasin, s21_math_asin_4);
    tcase_add_test(tc_mathasin, s21_math_asin_5);
    tcase_add_test(tc_mathasin, s21_math_asin_6);
    tcase_add_test(tc_mathasin, s21_math_asin_7);
    suite_add_tcase(s, tc_mathasin);

    TCase *tc_mathacos;
    tc_mathacos = tcase_create("s21_math_acos");

    tcase_add_test(tc_mathacos, s21_math_acos_1);
    tcase_add_test(tc_mathacos, s21_math_acos_2);
    tcase_add_test(tc_mathacos, s21_math_acos_3);
    tcase_add_test(tc_mathacos, s21_math_acos_4);
    tcase_add_test(tc_mathacos, s21_math_acos_5);
    tcase_add_test(tc_mathacos, s21_math_acos_6);
    tcase_add_test(tc_mathacos, s21_math_acos_7);
    tcase_add_test(tc_mathacos, s21_math_acos_8);
    tcase_add_test(tc_mathacos, s21_math_acos_9);
    tcase_add_test(tc_mathacos, s21_math_acos_10);
    suite_add_tcase(s, tc_mathacos);

    TCase *tc_mathatan;
    tc_mathatan = tcase_create("s21_math_atan");

    tcase_add_test(tc_mathatan, s21_math_atan_1);
    tcase_add_test(tc_mathatan, s21_math_atan_2);
    tcase_add_test(tc_mathatan, s21_math_atan_3);
    tcase_add_test(tc_mathatan, s21_math_atan_4);
    tcase_add_test(tc_mathatan, s21_math_atan_5);
    tcase_add_test(tc_mathatan, s21_math_atan_6);
    tcase_add_test(tc_mathatan, s21_math_atan_7);
    tcase_add_test(tc_mathatan, s21_math_atan_8);
    tcase_add_test(tc_mathatan, s21_math_atan_9);
    tcase_add_test(tc_mathatan, s21_math_atan_10);
    suite_add_tcase(s, tc_mathatan);

    TCase *tc_mathlog;
    tc_mathlog = tcase_create("s21_math_log");

    tcase_add_test(tc_mathlog, s21_math_log_1);
    tcase_add_test(tc_mathlog, s21_math_log_2);
    tcase_add_test(tc_mathlog, s21_math_log_3);
    tcase_add_test(tc_mathlog, s21_math_log_4);
    tcase_add_test(tc_mathlog, s21_math_log_5);
    tcase_add_test(tc_mathlog, s21_math_log_6);
    tcase_add_test(tc_mathlog, s21_math_log_7);
    tcase_add_test(tc_mathlog, s21_math_log_8);
    tcase_add_test(tc_mathlog, s21_math_log_9);
    tcase_add_test(tc_mathlog, s21_math_log_10);
    tcase_add_test(tc_mathlog, s21_math_log_11);
    tcase_add_test(tc_mathlog, s21_math_log_12);
    suite_add_tcase(s, tc_mathlog);

    TCase *tc_mathceil;
    tc_mathceil = tcase_create("s21_math_ceil");

    tcase_add_test(tc_mathceil, s21_math_ceil_1);
    tcase_add_test(tc_mathceil, s21_math_ceil_2);
    tcase_add_test(tc_mathceil, s21_math_ceil_3);
    tcase_add_test(tc_mathceil, s21_math_ceil_4);
    tcase_add_test(tc_mathceil, s21_math_ceil_5);
    tcase_add_test(tc_mathceil, s21_math_ceil_6);
    tcase_add_test(tc_mathceil, s21_math_ceil_7);
    tcase_add_test(tc_mathceil, s21_math_ceil_8);
    tcase_add_test(tc_mathceil, s21_math_ceil_9);
    tcase_add_test(tc_mathceil, s21_math_ceil_10);
    suite_add_tcase(s, tc_mathceil);

    return s;
}

int main(void) {
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = s21_math_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? 0 : -1;
}
