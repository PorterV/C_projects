#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int ans = 0;
  if (s21_is_null(value_1) && s21_is_null(value_2)) {
    ans = 0;
  } else {
    s21_sup_decimal v1, v2;
    s21_sup_decimal_init(&v1);
    s21_sup_decimal_init(&v2);
    s21_from_decimal_to_sup(&v1, value_1);
    s21_from_decimal_to_sup(&v2, value_2);
    ans = s21_sup_is_less(v1, v2);
  }
  return ans;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int ans = 0;
  if (s21_is_null(value_1) && s21_is_null(value_2)) {
    ans = 1;
  } else {
    s21_sup_decimal v1, v2;
    s21_sup_decimal_init(&v1);
    s21_sup_decimal_init(&v2);
    s21_from_decimal_to_sup(&v1, value_1);
    s21_from_decimal_to_sup(&v2, value_2);
    ans = s21_sup_is_less_or_equal(v1, v2);
  }
  return ans;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return !(s21_is_less_or_equal(value_1, value_2));
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return !(s21_is_less(value_1, value_2));
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int ans = 1;
  if (s21_is_null(value_1) && s21_is_null(value_2)) {
    ans = 1;
  } else {
    s21_diff_scale(&value_1, &value_2);
    for (int i = 0; i < 3; i++) {
      if (value_1.bits[i] == value_2.bits[i]) {
        continue;
      } else {
        ans = 0;
        break;
      }
    }
  }
  return ans;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}
