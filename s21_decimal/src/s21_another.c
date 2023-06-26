#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int out = 0;
  if (result == NULL) {
    out = 1;
  } else {
    s21_decimal_init(result);
    s21_decimal_cmp(&value, result);
    s21_set_sign(result, !s21_get_bit(value, 127));
  }
  return out;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int out = 0;
  if (result != NULL) {
    s21_sup_decimal sup, res, one = {{1, 0, 0, 0, 0, 0, 0, 0}, 0};
    s21_sup_decimal_init(&sup);
    s21_sup_decimal_init(&res);
    s21_from_decimal_to_sup(&sup, value);
    s21_sup_div_dec(sup, one, &res);
    s21_from_sup_to_decimal(result, res);
  } else {
    out = 1;
  }
  return out;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int out = 0;
  if (result == NULL) {
    out = 1;
  } else {
    s21_decimal_init(result);
    s21_decimal tmp = value;
    s21_truncate(tmp, &tmp);
    s21_decimal dec = value;
    s21_decimal mod, last;
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal two = {{2, 0, 0, 0}};
    s21_decimal point = {{5, 0, 0, 0}};
    s21_decimal mpoint = {{5, 0, 0, 0}};
    s21_set_sign(&mpoint, 1);
    s21_set_scale(&point, 1);
    s21_set_scale(&mpoint, 1);
    s21_mod(dec, one, &mod);
    s21_sub(dec, mod, &last);
    s21_mod(last, two, &last);
    if (s21_is_greater_or_equal(mod, point)) {
      if (s21_is_greater(mod, point) || s21_is_equal(last, one))
        s21_add(tmp, one, &tmp);
    } else if (s21_is_less_or_equal(mod, mpoint)) {
      s21_set_sign(&one, 1);
      if (s21_is_less(mod, mpoint) || s21_is_equal(last, one))
        s21_add(tmp, one, &tmp);
    }
    *result = tmp;
  }
  return out;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int out = 0;
  if (result == NULL) {
    out = 1;
  } else {
    float flt = 0;
    s21_decimal_init(result);
    s21_from_decimal_to_float(value, &flt);
    int a = floorf(flt);
    s21_from_int_to_decimal(a, result);
  }
  return out;
}
