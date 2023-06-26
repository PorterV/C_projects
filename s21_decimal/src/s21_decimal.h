#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_MAX_UINT 4294967295

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
  int sign;
} s21_sup_decimal;

#define S21_EPS 1e-6
#define S21_INF 1 / 0.0

int s21_from_float_to_decimal(float src, s21_decimal *dst);

int s21_from_int_to_decimal(int src, s21_decimal *dst);

int s21_from_decimal_to_int(s21_decimal src, int *dst);

// arithmatic

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// int              s21_div_dec(s21_decimal value_1, s21_decimal value_2,
// s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// int              s21_add_man(s21_decimal value_1, s21_decimal value_2,
// s21_decimal *result); int              s21_mul_man(s21_decimal value_1,
// s21_decimal value_2, s21_decimal *result); int s21_sub_man(s21_decimal
// value_1, s21_decimal value_2, s21_decimal *result); int
// s21_div_dec_man(s21_decimal value_1, s21_decimal value_2, s21_decimal
// *result); int              s21_mod_man(s21_decimal value_1, s21_decimal
// value_2, s21_decimal *result);

// support

void s21_decimal_init(s21_decimal *d);

void s21_show_decimal(s21_decimal d);

int s21_get_bit(s21_decimal d, int i);

void s21_set_bit(s21_decimal *d, int bit, int i);

void s21_set_scale(s21_decimal *d, int scale);

int s21_get_scale(s21_decimal d);

void s21_set_sign(s21_decimal *d, int sign);

void s21_left_shift(s21_decimal *d, int n);

int s21_decimal_scale(s21_decimal *d);

int s21_diff_scale(s21_decimal *value_1, s21_decimal *value_2);

void s21_decimal_cmp(s21_decimal *src, s21_decimal *dest);

void s21_show_decimal(s21_decimal d);

int s21_is_null(s21_decimal d);

// float

int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_from_float_to_decimal(float src, s21_decimal *dst);

int s21_get_digit_part(float src);

// compare

int s21_is_less(s21_decimal value_1, s21_decimal value_2);

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);

int s21_is_greater(s21_decimal value_1, s21_decimal value_2);

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// another

int s21_negate(s21_decimal value, s21_decimal *result);

int s21_truncate(s21_decimal value, s21_decimal *result);

int s21_round(s21_decimal value, s21_decimal *result);

int s21_floor(s21_decimal value, s21_decimal *result);

// SUP_DECIMAL

// help

void s21_sup_decimal_init(s21_sup_decimal *d);

void s21_sup_show_decimal(s21_sup_decimal d);

int s21_sup_get_bit(s21_sup_decimal d, int i);

void s21_sup_set_bit(s21_sup_decimal *d, int bit, int i);

void s21_sup_set_scale(s21_sup_decimal *d, int scale);

int s21_sup_get_scale(s21_sup_decimal d);

void s21_sup_set_sign(s21_sup_decimal *d, int sign);

void s21_sup_left_shift(s21_sup_decimal *d, int n);

void s21_sup_right_shift(s21_sup_decimal *d, int n);

int s21_sup_decimal_scale(s21_sup_decimal *d);

int s21_sup_diff_scale(s21_sup_decimal *value_1, s21_sup_decimal *value_2);

int s21_sup_get_next_digit(s21_sup_decimal *d, int n);

int s21_sup_get_max_digit(s21_sup_decimal d);

void s21_sup_decimal_cmp(s21_sup_decimal src, s21_sup_decimal *dest);

int s21_sup_decimal_len(s21_sup_decimal d1);

int s21_sup_to_max_bit(s21_sup_decimal value_1, s21_sup_decimal *value_2);

void s21_sup_show_decimal(s21_sup_decimal d);

void s21_from_decimal_to_sup(s21_sup_decimal *dst, s21_decimal src);

int s21_sup_div_dec_null(s21_sup_decimal *d);

int s21_from_sup_to_decimal(s21_decimal *dst, s21_sup_decimal src);

unsigned int s21_get_bin_exp(unsigned int src);

int s21_sup_is_null(s21_sup_decimal d);

// arithmetic

int s21_sup_add(s21_sup_decimal value_1, s21_sup_decimal value_2,
                s21_sup_decimal *result);

int s21_sup_mul(s21_sup_decimal value_1, s21_sup_decimal value_2,
                s21_sup_decimal *result);

int s21_sup_sub(s21_sup_decimal value_1, s21_sup_decimal value_2,
                s21_sup_decimal *result);

int s21_sup_div(s21_sup_decimal value_1, s21_sup_decimal value_2,
                s21_sup_decimal *result);

int s21_sup_div_dec(s21_sup_decimal value_1, s21_sup_decimal value_2,
                    s21_sup_decimal *result);

int s21_sup_mod(s21_sup_decimal value_1, s21_sup_decimal value_2,
                s21_sup_decimal *result);

int s21_sup_add_man(s21_sup_decimal value_1, s21_sup_decimal value_2,
                    s21_sup_decimal *result);

int s21_sup_mul_man(s21_sup_decimal value_1, s21_sup_decimal value_2,
                    s21_sup_decimal *result);

int s21_sup_sub_man(s21_sup_decimal value_1, s21_sup_decimal value_2,
                    s21_sup_decimal *result);

int s21_sup_div_dec_man(s21_sup_decimal value_1, s21_sup_decimal value_2,
                        s21_sup_decimal *result);

int s21_sup_mod_man(s21_sup_decimal value_1, s21_sup_decimal value_2,
                    s21_sup_decimal *result);

// compare

int s21_sup_is_less(s21_sup_decimal value_1, s21_sup_decimal value_2);

int s21_sup_is_less_or_equal(s21_sup_decimal value_1, s21_sup_decimal value_2);

int s21_sup_is_greater(s21_sup_decimal value_1, s21_sup_decimal value_2);

int s21_sup_is_greater_or_equal(s21_sup_decimal value_1,
                                s21_sup_decimal value_2);

int s21_sup_is_equal(s21_sup_decimal value_1, s21_sup_decimal value_2);

int s21_sup_is_not_equal(s21_sup_decimal value_1, s21_sup_decimal value_2);

int s21_sup_is_less_man(s21_sup_decimal value_1, s21_sup_decimal value_2);

int s21_sup_is_greater_or_equal_man(s21_sup_decimal value_1,
                                    s21_sup_decimal value_2);

int s21_sup_is_not_equal_man(s21_sup_decimal value_1, s21_sup_decimal value_2);

int s21_sup_is_less_or_equal_man(s21_sup_decimal value_1,
                                 s21_sup_decimal value_2);

int s21_sup_is_equal_man(s21_sup_decimal value_1, s21_sup_decimal value_2);

#endif  //  SRC_S21_DECIMAL_H_
