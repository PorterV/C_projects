#include "s21_decimal.h"

int s21_sup_get_bit(s21_sup_decimal d, int i) {
  unsigned int mask = 1U << (i % 32);
  return !!(d.bits[i / 32] & mask);
}

void s21_sup_decimal_init(s21_sup_decimal *d) {
  d->sign = d->bits[0] = d->bits[1] = d->bits[2] = d->bits[3] = d->bits[4] =
      d->bits[5] = d->bits[6] = d->bits[7] = 0;
}

void s21_sup_set_bit(s21_sup_decimal *d, int bit, int i) {
  unsigned int mask = 1U << (bit % 32);
  if (bit / 32 < 8) {
    if (i == 0) {
      d->bits[bit / 32] &= ~mask;
    } else {
      d->bits[bit / 32] |= mask;
    }
  }
}

void s21_sup_set_sign(s21_sup_decimal *d, int sign) { d->sign = sign; }

int s21_sup_get_scale(s21_sup_decimal d) { return d.bits[7]; }

int s21_sup_diff_scale(s21_sup_decimal *value_1, s21_sup_decimal *value_2) {
  int s1 = s21_sup_get_scale(*value_1);
  int s2 = s21_sup_get_scale(*value_2);
  s21_sup_decimal buff;
  s21_sup_decimal_init(&buff);
  int out = 0;
  int d = abs(s1 - s2);
  if (s2 > s1) {
    for (int i = 0; i < d; i++) {
      ;
      s21_sup_decimal_scale(value_1);
    }
  } else {
    for (int i = 0; i < d; i++) {
      s21_sup_decimal_scale(value_2);
    }
  }
  return out;
}

void s21_sup_set_scale(s21_sup_decimal *d, int scale) { d->bits[7] = scale; }

void s21_sup_left_shift(s21_sup_decimal *d, int n) {
  if (n > 224) {
    s21_sup_decimal_init(d);
  } else {
    for (int i = 223; i >= n; i--) {
      s21_sup_set_bit(d, i, s21_sup_get_bit(*d, i - n));
    }
    for (int i = 0; i < n; i++) {
      s21_sup_set_bit(d, i, 0);
    }
  }
}

void s21_sup_right_shift(s21_sup_decimal *d, int n) {
  for (int i = 0; i <= 5; i++) {
    for (int j = 0; j < n; j++) {
      d->bits[i] = (d->bits[i] >> 1) + (d->bits[i + 1] >> j & 1) * pow(2, 31);
    }
  }
  d->bits[6] = d->bits[6] >> n;
}

int s21_sup_decimal_scale(s21_sup_decimal *d) {
  int out = 0;
  int scale = s21_sup_get_scale(*d);
  s21_sup_decimal tmp1 = *d;
  s21_sup_decimal tmp2 = *d;
  s21_sup_left_shift(&tmp1, 1);
  s21_sup_left_shift(&tmp2, 3);
  s21_sup_decimal_init(d);
  out = s21_sup_add(tmp1, tmp2, d);
  if (out == 1) {
    d->bits[0] = -1;
    d->bits[1] = -1;
    d->bits[2] = -1;
  }
  if (out == 0) s21_sup_set_scale(d, scale + 1);
  return out;
}

int s21_sup_get_next_digit(s21_sup_decimal *d, int n) {
  int f = 1;
  if (n == 224) {
    f = 0;
  } else {
    if (s21_sup_get_bit(*d, n + 1) == 0) {
      if (s21_sup_get_next_digit(d, n + 1) == 0) {
        f = 0;
      }
    } else {
      s21_sup_set_bit(d, n + 1, s21_sup_get_bit(*d, n + 1) - 1);
    }
    if (f) s21_sup_set_bit(d, n, 1);
  }
  return f;
}

void s21_sup_decimal_cmp(s21_sup_decimal src, s21_sup_decimal *dest) {
  for (int i = 0; i < 8; i++) {
    dest->bits[i] = src.bits[i];
  }
}

int s21_sup_decimal_len(s21_sup_decimal d1) {
  int i = 223;
  for (; i >= 0; i--) {
    if (s21_sup_get_bit(d1, i) == 1) {
      break;
    }
  }
  return i;
}

int s21_sup_to_max_bit(s21_sup_decimal value_1, s21_sup_decimal *value_2) {
  int len1 = s21_sup_decimal_len(value_1);
  int len2 = s21_sup_decimal_len(*value_2);
  int dec = 0;
  if (len1 > len2) {
    s21_sup_left_shift(value_2, len1 - len2);
    dec = 0;
    if (s21_sup_is_less_man(value_1, *value_2)) {
      s21_sup_right_shift(value_2, 1);
      dec++;
    }
  }
  return dec;
}

void s21_sup_show_decimal(s21_sup_decimal d) {
  for (int i = 7; i >= 0; i--) {
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

void s21_from_decimal_to_sup(s21_sup_decimal *dst, s21_decimal src) {
  dst->bits[0] = src.bits[0];
  dst->bits[1] = src.bits[1];
  dst->bits[2] = src.bits[2];
  dst->bits[7] = s21_get_scale(src);
  dst->sign = s21_get_bit(src, 127);
}

int s21_sup_div_dec_null(s21_sup_decimal *d) {
  int res = 1;
  if (d->bits[7] != 0) {
    d->bits[7] = d->bits[7] - 1;
    s21_sup_decimal tmp;
    s21_sup_decimal_init(&tmp);
    tmp.bits[0] = 10;
    s21_sup_decimal mod1;
    s21_sup_decimal mod2;
    s21_sup_decimal cpy = *d;
    int scale = s21_sup_get_scale(cpy);
    s21_sup_mod_man(cpy, tmp, &mod1);
    s21_sup_div_dec_man(cpy, tmp, &cpy);
    s21_sup_mod_man(cpy, tmp, &mod2);
    tmp.bits[0] = 1;
    if (mod1.bits[0] > 5 || (mod1.bits[0] == 5 && mod2.bits[0] % 2 == 1)) {
      s21_sup_add_man(cpy, tmp, &cpy);
    }
    s21_sup_set_scale(&cpy, scale);
    *d = cpy;
  } else {
    res = 0;
  }
  return res;
}

int s21_from_sup_to_decimal(s21_decimal *dst, s21_sup_decimal src) {
  int res = 1;
  int sign = src.sign;
  src.sign = 0;
  for (int i = 6; i >= 3; i--) {
    while (src.bits[i] != 0) {
      res = s21_sup_div_dec_null(&src);
      if (res == 0) break;
    }
    if (res == 0) break;
  }
  if (res == 1) {
    while (src.bits[7] > 28) {
      res = s21_sup_div_dec_null(&src);
      if (res == 0) break;
    }
  }
  if (res == 1) {
    for (int i = 0; i < 3; ++i) {
      dst->bits[i] = src.bits[i];
    }
    s21_set_scale(dst, src.bits[7]);
    s21_set_sign(dst, sign);
  }
  return res;
}

int s21_sup_is_null(s21_sup_decimal d) {
  int res = 1;
  for (int i = 0; i < 7; i++) {
    if (d.bits[i] != 0) {
      res = 0;
      break;
    }
  }
  return res;
}
