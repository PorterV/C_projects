#include "s21_decimal.h"

int s21_sup_add(s21_sup_decimal value_1, s21_sup_decimal value_2,
                s21_sup_decimal *result) {
  int res = 0;
  int k;
  s21_sup_decimal_init(result);
  s21_sup_diff_scale(&value_1, &value_2);
  if (value_1.sign != value_2.sign) {
    int s1 = value_1.sign;
    int s2 = value_2.sign;
    s21_sup_set_sign(&value_1, 0);
    s21_sup_set_sign(&value_2, 0);
    if (s21_sup_is_less(value_1, value_2)) {
      k = s2;
    } else {
      k = s1;
    }
    res = s21_sup_sub(value_1, value_2, result);
    result->sign = k;
    if (res == 1 && k == 1) res++;
  } else {
    if (value_1.sign && value_2.sign) s21_sup_set_sign(result, 1);
    int per = 0;
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 32; j++) {
        int resu =
            (value_1.bits[i] >> j & 1) + (value_2.bits[i] >> j & 1) + per;
        if (resu > 1) {
          per = 1;
          resu -= 2;
        } else {
          per = 0;
        }
        s21_sup_set_bit(result, i * 32 + j, resu);
      }
    }
    s21_sup_set_scale(result, s21_sup_get_scale(value_1));
    if (per == 1) {
      s21_sup_decimal_init(result);
      if (s21_sup_get_bit(value_1, 255) == 0) {
        res = 1;
      } else {
        res = 2;
      }
    }
  }
  return res;
}

int s21_sup_mul(s21_sup_decimal value_1, s21_sup_decimal value_2,
                s21_sup_decimal *result) {
  int sign = 0;
  if (value_1.sign + value_2.sign == 1) sign = 1;
  int res = 0;
  s21_sup_decimal_init(result);
  s21_sup_decimal tmp;
  s21_sup_decimal result_tmp;
  int res_scale = s21_sup_get_scale(value_1) + s21_sup_get_scale(value_2);
  s21_sup_decimal_init(&tmp);
  s21_sup_decimal_init(&result_tmp);
  s21_sup_set_sign(&value_1, 0);
  s21_sup_set_sign(&value_2, 0);
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 32; j++) {
      if (s21_sup_get_bit(value_2, i * 32 + j) == 1) {
        tmp = value_1;
        s21_sup_decimal tmp1;
        s21_sup_left_shift(&tmp, i * 32 + j);
        if (s21_sup_is_greater(value_1, tmp)) {
          res = 1;
        } else {
          s21_sup_decimal_init(&tmp1);
          res = s21_sup_add(result_tmp, tmp, &tmp1);
        }
        if (res != 0) {
          break;
        }
        result_tmp = tmp1;
      }
    }
  }
  if (res == 0) {
    *result = result_tmp;
    s21_sup_set_scale(result, res_scale);
  }
  if (res == 1 && result->sign == 1) res++;
  result->sign = sign;
  return res;
}

int s21_sup_sub(s21_sup_decimal value_1, s21_sup_decimal value_2,
                s21_sup_decimal *result) {
  s21_sup_decimal_init(result);
  int out = s21_sup_diff_scale(&value_1, &value_2);
  int res = 0;
  if (value_1.sign == value_2.sign) {
    int sign;
    int s1 = value_1.sign;
    int s2 = value_2.sign;
    s21_sup_set_sign(&value_1, 0);
    s21_sup_set_sign(&value_2, 0);
    if (s21_sup_is_greater_or_equal(value_1, value_2)) {
      sign = s1;
    } else {
      sign = !s2;
      s21_sup_decimal tmp = value_1;
      value_1 = value_2;
      value_2 = tmp;
    }
    int tmp;
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 32; j++) {
        res = 0;
        if (s21_sup_get_bit(value_1, i * 32 + j) -
                s21_sup_get_bit(value_2, i * 32 + j) <
            0) {
          s21_sup_get_next_digit(&value_1, i * 32 + j);
          tmp = 1;
        } else {
          tmp = ((s21_sup_get_bit(value_1, i * 32 + j)) -
                 (s21_sup_get_bit(value_2, i * 32 + j)));
        }
        s21_sup_set_bit(result, i * 32 + j, tmp);
      }
    }
    s21_sup_set_scale(result, s21_sup_get_scale(value_1));
    s21_sup_set_sign(result, sign);
  } else {
    int k = 0;
    if (s21_sup_is_greater_or_equal(value_1, value_2)) {
      k = value_1.sign == 1 ? 1 : 0;
    } else {
      k = value_2.sign == 0 ? 1 : 0;
    }
    s21_sup_set_sign(&value_1, 0);
    s21_sup_set_sign(&value_2, 0);
    res = s21_sup_add(value_1, value_2, result);
    s21_sup_set_sign(result, k);
    if (res == 1 && k == 1) res++;
  }
  if (out) s21_sup_set_bit(result, 0, 0);
  return res;
}

int s21_sup_div(s21_sup_decimal value_1, s21_sup_decimal value_2,
                s21_sup_decimal *result) {
  int res;
  s21_sup_decimal copy_value_1 = value_1;
  int sign = value_1.sign == value_2.sign ? 0 : 1;
  s21_sup_set_sign(&value_1, 0);
  s21_sup_set_sign(&value_2, 0);
  s21_sup_decimal_init(result);
  s21_sup_decimal null;
  s21_sup_decimal_init(&null);
  s21_sup_div_dec(value_1, value_2, result);
  int f = 0;
  s21_sup_diff_scale(&value_1, &value_2);
  res = s21_sup_mod(value_1, value_2, &value_1);
  s21_sup_decimal tmp;
  s21_sup_decimal_init(&tmp);
  s21_sup_decimal flot = value_1;
  while (s21_sup_is_not_equal_man(flot, null)) {
    s21_sup_decimal_init(&tmp);
    s21_sup_decimal_scale(&value_1);
    s21_sup_div_dec_man(value_1, value_2, &tmp);
    s21_sup_mod_man(value_1, value_2, &flot);
    value_1 = flot;
    s21_sup_set_scale(&tmp, f + 1);
    s21_sup_add(*result, tmp, result);
    if (f == 29) break;
    f++;
  }
  if (s21_sup_is_not_equal_man(flot, null)) {
    s21_sup_set_bit(result, 0, 1);
    f++;
  }
  s21_sup_set_scale(result, f);
  s21_sup_set_sign(result, sign);
  value_1 = copy_value_1;
  if (s21_sup_is_equal_man(*result, null) &&
      s21_sup_is_not_equal_man(value_1, null) && res != 3) {
    res = sign == 1 ? 2 : 1;
  }
  return res;
}

int s21_sup_div_dec(s21_sup_decimal value_1, s21_sup_decimal value_2,
                    s21_sup_decimal *result) {
  s21_sup_decimal_init(result);
  s21_sup_decimal tmp = value_2;
  int sign = (value_1.sign + value_2.sign) % 2;
  value_1.sign = 0;
  value_2.sign = 0;
  s21_sup_diff_scale(&value_1, &value_2);
  int del = s21_sup_decimal_len(value_1) - s21_sup_decimal_len(value_2);
  int res = s21_sup_to_max_bit(value_1, &value_2);
  while (res <= del && s21_sup_is_greater_or_equal(value_2, tmp)) {
    s21_sup_left_shift(result, 1);
    if (s21_sup_is_greater_or_equal(value_1, value_2)) {
      s21_sup_sub(value_1, value_2, &value_1);
      result->bits[0]++;
    }
    s21_sup_right_shift(&value_2, 1);
    res++;
  }
  result->sign = sign;
  return res;
}

int s21_sup_mod(s21_sup_decimal value_1, s21_sup_decimal value_2,
                s21_sup_decimal *result) {
  int res = 0;
  int sign = (value_1.sign | value_2.sign);
  value_1.sign = 0;
  value_2.sign = 0;
  s21_sup_decimal_init(result);
  s21_sup_decimal tmp;
  s21_sup_decimal tmp1;
  s21_sup_decimal_init(&tmp);
  s21_sup_decimal_init(&tmp1);
  s21_sup_div_dec(value_1, value_2, &tmp);
  res = s21_sup_mul(value_2, tmp, &tmp1);
  if (res == 0) res = s21_sup_sub(value_1, tmp1, result);
  result->sign = sign;
  return res;
}

int s21_sup_div_dec_man(s21_sup_decimal value_1, s21_sup_decimal value_2,
                        s21_sup_decimal *result) {
  int scale = s21_sup_get_scale(value_1);
  s21_sup_decimal_init(result);
  s21_sup_decimal tmp = value_2;
  int del = s21_sup_decimal_len(value_1) - s21_sup_decimal_len(value_2);
  int dec = s21_sup_to_max_bit(value_1, &value_2);
  while (dec <= del && s21_sup_is_greater_or_equal_man(value_2, tmp)) {
    s21_sup_left_shift(result, 1);
    if (s21_sup_is_greater_or_equal_man(value_1, value_2)) {
      ;
      s21_sup_sub_man(value_1, value_2, &value_1);
      result->bits[0]++;
    }
    s21_sup_right_shift(&value_2, 1);
    dec++;
  }
  s21_sup_set_scale(result, scale);
  return dec;
}

int s21_sup_mod_man(s21_sup_decimal value_1, s21_sup_decimal value_2,
                    s21_sup_decimal *result) {
  s21_sup_decimal_init(result);
  s21_sup_decimal tmp;
  s21_sup_decimal tmp1;
  s21_sup_decimal_init(&tmp);
  s21_sup_decimal_init(&tmp1);
  s21_sup_div_dec_man(value_1, value_2, &tmp);
  s21_sup_mul_man(value_2, tmp, &tmp1);
  s21_sup_sub_man(value_1, tmp1, result);
  return 1;
}

int s21_sup_mul_man(s21_sup_decimal value_1, s21_sup_decimal value_2,
                    s21_sup_decimal *result) {
  s21_sup_decimal_init(result);
  s21_sup_decimal tmp;
  s21_sup_decimal res;
  int res_scale = s21_sup_get_scale(value_1) + s21_sup_get_scale(value_2);
  s21_sup_decimal_init(&res);
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 32; j++) {
      if (s21_sup_get_bit(value_2, i * 32 + j) == 1) {
        tmp = value_1;
        s21_sup_left_shift(&tmp, i * 32 + j);
        s21_sup_decimal tmp1;
        s21_sup_decimal_init(&tmp1);
        s21_sup_add_man(res, tmp, &tmp1);
        res = tmp1;
      }
    }
  }
  *result = res;
  return res_scale;
}

int s21_sup_sub_man(s21_sup_decimal value_1, s21_sup_decimal value_2,
                    s21_sup_decimal *result) {
  s21_sup_decimal_init(result);
  int err = 0;
  int res;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 32; j++) {
      res = 0;
      if (s21_sup_get_bit(value_1, i * 32 + j) -
              s21_sup_get_bit(value_2, i * 32 + j) <
          0) {
        if (s21_sup_get_next_digit(&value_1, i * 32 + j)) {
          res = 1;
        } else {
          err = 1;
        }
      } else {
        res = ((s21_sup_get_bit(value_1, i * 32 + j)) -
               (s21_sup_get_bit(value_2, i * 32 + j)));
      }
      if (err) {
        s21_sup_decimal_init(result);
        break;
      }
      s21_sup_set_bit(result, i * 32 + j, res);
    }
    if (err) {
      break;
    }
  }
  return err;
}

int s21_sup_add_man(s21_sup_decimal value_1, s21_sup_decimal value_2,
                    s21_sup_decimal *result) {
  s21_sup_decimal_init(result);
  int per = 0;
  for (int i = 0; i < 7; i++) {
    unsigned result1 = 0;
    for (int j = 0; j < 32; j++) {
      int res = (value_1.bits[i] >> j & 1) + (value_2.bits[i] >> j & 1) + per;
      if (res > 1) {
        per = 1;
        res -= 2;
      } else {
        per = 0;
      }
      result1 += res * pow(2, j);
    }
    result->bits[i] = result1;
  }
  return 1;
}
