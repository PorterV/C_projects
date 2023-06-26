#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = 0;
  if (!(src == S21_INF || src == -S21_INF || isnan(src) || dst == NULL)) {
    s21_decimal_init(dst);
    int sign = 0;
    if (src < 0) sign = 1;
    unsigned int fbits = *((unsigned int *)&src);
    int bin_exp = s21_get_bin_exp(fbits);
    if (bin_exp > 95) {
      error = 1;
    } else if (bin_exp < 95) {
      int scale = 0;
      for (; !((int)src) && scale < 28; src *= 10, scale++) {
      }
      for (int i = 0; i < 8; i++, scale++, src *= 10) {
      }
      fbits = *((unsigned int *)&src);
      bin_exp = s21_get_bin_exp(fbits);
      if (bin_exp < -94 || scale > 28) {
        error = 1;
        scale = 0;
      } else {
        unsigned int mask = 1U << 22;
        s21_set_bit(dst, bin_exp, 1);
        fbits = *((unsigned int *)&src);
        for (int pos = 22; pos > 0; mask >>= 1) {
          s21_set_bit(dst, bin_exp - (23 - pos), !!(mask & fbits));
          pos--;
        }
      }
      scale += s21_get_scale(*dst);
      s21_set_scale(dst, scale);
      s21_set_sign(dst, sign);
    }
  } else {
    s21_decimal_init(dst);
    error = 1;
  }
  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = 0;
  if (dst == NULL) {
    result = 1;
  } else {
    double num = 0;
    int scale = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 32; j++) {
        int res = s21_get_bit(src, i * 32 + j);
        if (res == 1) {
          num += pow(2, i * 32 + j);
        }
      }
    }
    scale = s21_get_scale(src);
    num /= (double)pow(10.0, (double)scale);
    if (s21_get_bit(src, 127) == 1) {
      num *= -1;
    }
    *dst = (float)num;
  }
  return result;
}
