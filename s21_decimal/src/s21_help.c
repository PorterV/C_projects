#include "s21_decimal.h"

int s21_get_bit(s21_decimal d, int i) {
  unsigned int mask = 1U << (i % 32);
  return !!(d.bits[i / 32] & mask);
}

void s21_decimal_init(s21_decimal *d) {
  d->bits[0] = d->bits[1] = d->bits[2] = d->bits[3] = 0;
}

void s21_set_bit(s21_decimal *d, int bit, int i) {
  unsigned int mask = 1U << (bit % 32);
  if (bit / 32 < 4) {
    if (i == 0) {
      d->bits[bit / 32] &= ~mask;
    } else {
      d->bits[bit / 32] |= mask;
    }
  }
}
void s21_set_sign(s21_decimal *d, int sign) { s21_set_bit(d, 127, sign); }

int s21_get_scale(s21_decimal d) {
  s21_set_bit(&d, 127, 0);
  return d.bits[3] >> 16;
}

int s21_diff_scale(s21_decimal *value_1, s21_decimal *value_2) {
  int s1 = s21_get_scale(*value_1);
  int s2 = s21_get_scale(*value_2);
  s21_decimal value1_tmp;
  s21_decimal value2_tmp;
  s21_decimal_cmp(value_1, &value1_tmp);
  s21_decimal_cmp(value_2, &value2_tmp);
  s21_decimal ten;
  s21_decimal_init(&ten);
  s21_decimal one;
  s21_decimal_init(&one);
  s21_from_int_to_decimal(1, &one);
  s21_from_int_to_decimal(10, &ten);
  s21_decimal buff;
  s21_decimal_init(&buff);
  int out = 0;
  int d = abs(s1 - s2);
  if (s2 > s1) {
    for (int i = 0; i < d; i++) {
      out = s21_decimal_scale(value_1);
      if (out != 0) {
        s21_truncate(*value_2, value_2);
        break;
      }
    }
  } else {
    for (int i = 0; i < d; i++) {
      out = s21_decimal_scale(value_2);
      if (out) {
        s21_truncate(*value_1, value_1);
        break;
      }
    }
  }
  return out;
}

void s21_set_scale(s21_decimal *d, int scale) {
  int bit = s21_get_bit(*d, 127);
  unsigned int mask = scale << 16;
  d->bits[3] = 0;
  d->bits[3] |= mask;
  s21_set_sign(d, bit);
}

void s21_left_shift(s21_decimal *d, int n) {
  if (n > 96) {
    s21_decimal_init(d);
  } else {
    for (int i = 95; i >= n; i--) {
      s21_set_bit(d, i, s21_get_bit(*d, i - n));
    }
    for (int i = 0; i < n; i++) {
      s21_set_bit(d, i, 0);
    }
  }
}

int s21_decimal_scale(s21_decimal *d) {
  int out = 0;
  s21_decimal tmp1 = *d;
  s21_decimal tmp2 = *d;
  s21_left_shift(&tmp1, 1);
  s21_left_shift(&tmp2, 3);
  s21_decimal_init(d);
  out = s21_add(tmp1, tmp2, d);
  if (out == 1) {
    d->bits[0] = -1;
    d->bits[1] = -1;
    d->bits[2] = -1;
  }
  if (out == 0) s21_set_scale(d, s21_get_scale(*d) + 1);
  return out;
}

void s21_decimal_cmp(s21_decimal *src, s21_decimal *dest) {
  for (int i = 0; i < 4; i++) {
    dest->bits[i] = src->bits[i];
  }
}

void s21_show_decimal(s21_decimal d) {
  for (int i = 3; i >= 0; i--) {
    unsigned int *tmp;
    tmp = &d.bits[i];
    int y = sizeof(*tmp) * 8 - 1;
    for (int i = y; i >= 0; i--) {
      printf("%d", (*tmp) >> i & 1);
    }
    printf(" ");
  }
  printf("\n");
}

int s21_is_null(s21_decimal d) {
  int res = 0;
  if (d.bits[0] == 0 && d.bits[1] == 0 && d.bits[2] == 0) {
    res = 1;
  }
  return res;
}

unsigned int s21_get_bin_exp(unsigned int src) {
  int bin_exp = 0;
  int i = 0;
  for (unsigned int mask = 1U << 23; mask < 1U << 31;) {
    bin_exp += (!!(src & mask)) * pow(2, i);
    i++;
    mask <<= 1;
  }
  return bin_exp - 127;
}
