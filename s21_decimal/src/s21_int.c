#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int sign = src < 0 ? 1 : 0;
  if (sign) src *= -1;
  unsigned int tmp = src;
  int result = 0;
  s21_decimal_init(dst);
  dst->bits[0] = tmp;
  s21_set_sign(dst, sign);
  return result;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int result = 0;
  if (!src.bits[1] && !src.bits[2] && !s21_get_bit(src, 31) && dst != NULL) {
    *dst = src.bits[0];
    if (s21_get_bit(src, 127)) {
      *dst *= -1;
    }
    *dst /= (int)pow(10, s21_get_scale(src));
  } else {
    result = 1;
  }
  return result;
}
