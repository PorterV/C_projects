#include "s21_decimal.h"

int s21_sup_is_less(s21_sup_decimal value_1, s21_sup_decimal value_2) {
  s21_sup_diff_scale(&value_1, &value_2);
  int sign_1 = value_1.sign;
  int sign_2 = value_2.sign;
  int ans = 0;
  int f = 0;
  if (sign_1 < sign_2) {
    ans = 0;
  } else if (sign_1 > sign_2) {
    ans = 1;
  } else {
    for (int i = 6; i >= 0; i--) {
      if (value_1.bits[i] == value_2.bits[i]) {
        continue;
      } else if (value_1.bits[i] < value_2.bits[i]) {
        ans = 1;
        f = 1;
        break;
      } else {
        ans = 0;
        f = 1;
        break;
      }
    }
    if (sign_1 == 1) ans = !ans;
    if (f == 0) ans = 0;
  }
  return ans;
}
int s21_sup_is_less_or_equal(s21_sup_decimal value_1, s21_sup_decimal value_2) {
  s21_sup_diff_scale(&value_1, &value_2);
  int sign_1 = value_1.sign;
  int sign_2 = value_2.sign;
  int f = 0;
  int ans = 1;
  if (sign_1 < sign_2) {
    ans = 0;
  } else if (sign_1 > sign_2) {
    ans = 1;
  } else {
    for (int i = 6; i >= 0; i--) {
      if (value_1.bits[i] == value_2.bits[i]) {
        continue;
      } else if (value_1.bits[i] < value_2.bits[i]) {
        f = 1;
        ans = 1;
        break;
      } else {
        f = 1;
        ans = 0;
        break;
      }
    }
    if (sign_1 == 1 && f) ans = !ans;
  }
  return ans;
}

int s21_sup_is_greater(s21_sup_decimal value_1, s21_sup_decimal value_2) {
  return !(s21_sup_is_less_or_equal(value_1, value_2));
}

int s21_sup_is_greater_or_equal(s21_sup_decimal value_1,
                                s21_sup_decimal value_2) {
  return !(s21_sup_is_less(value_1, value_2));
}

int s21_sup_is_greater_or_equal_man(s21_sup_decimal value_1,
                                    s21_sup_decimal value_2) {
  return !(s21_sup_is_less_man(value_1, value_2));
}

int s21_sup_is_less_man(s21_sup_decimal value_1, s21_sup_decimal value_2) {
  int sign_1 = value_1.sign;
  int sign_2 = value_2.sign;
  int ans = 0;
  if (sign_1 < sign_2) {
    ans = 0;
  } else if (sign_1 > sign_2) {
    ans = 1;
  } else {
    for (int i = 6; i >= 0; i--) {
      if (value_1.bits[i] == value_2.bits[i]) {
        continue;
      } else if (value_1.bits[i] < value_2.bits[i]) {
        ans = 1;
        break;
      } else {
        ans = 0;
        break;
      }
    }
    if (sign_1 == 1) ans = !ans;
  }
  return ans;
}

int s21_sup_is_not_equal_man(s21_sup_decimal value_1, s21_sup_decimal value_2) {
  return !s21_sup_is_equal_man(value_1, value_2);
}

int s21_sup_is_equal_man(s21_sup_decimal value_1, s21_sup_decimal value_2) {
  return s21_sup_is_less_or_equal_man(value_1, value_2) &&
         s21_sup_is_greater_or_equal_man(value_1, value_2);
}

int s21_sup_is_less_or_equal_man(s21_sup_decimal value_1,
                                 s21_sup_decimal value_2) {
  int sign_1 = value_1.sign;
  int sign_2 = value_2.sign;
  int ans = 1;
  if (sign_1 < sign_2) {
    ans = 0;
  } else if (sign_1 > sign_2) {
    ans = 1;
  } else {
    for (int i = 6; i >= 0; i--) {
      if (value_1.bits[i] == value_2.bits[i]) {
        continue;
      } else if (value_1.bits[i] < value_2.bits[i]) {
        ans = 1;
        break;
      } else {
        ans = 0;
        break;
      }
    }
    if (sign_1 == 1) ans = !ans;
  }
  return ans;
}
