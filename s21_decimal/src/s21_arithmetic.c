#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  s21_decimal_init(result);
  s21_sup_decimal v1, v2, r;
  s21_sup_decimal_init(&v1);
  s21_sup_decimal_init(&v2);
  s21_sup_decimal_init(&r);
  s21_from_decimal_to_sup(&v1, value_1);
  s21_from_decimal_to_sup(&v2, value_2);
  s21_sup_add(v1, v2, &r);
  int tmp = s21_from_sup_to_decimal(result, r);
  if (tmp == 0) {
    if (r.sign == 1) {
      res = 2;
    } else {
      res = 1;
    }
  }
  return res;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  s21_decimal_init(result);
  s21_sup_decimal v1, v2, r;
  s21_sup_decimal_init(&v1);
  s21_sup_decimal_init(&v2);
  s21_sup_decimal_init(&r);
  s21_from_decimal_to_sup(&v1, value_1);
  s21_from_decimal_to_sup(&v2, value_2);
  s21_sup_mul(v1, v2, &r);
  int tmp = s21_from_sup_to_decimal(result, r);
  if (tmp == 0) {
    if (r.sign == 1) {
      res = 2;
    } else {
      res = 1;
    }
  }
  return res;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  s21_decimal_init(result);
  s21_sup_decimal v1, v2, r;
  s21_sup_decimal_init(&v1);
  s21_sup_decimal_init(&v2);
  s21_sup_decimal_init(&r);
  s21_from_decimal_to_sup(&v1, value_1);
  s21_from_decimal_to_sup(&v2, value_2);
  s21_sup_sub(v1, v2, &r);
  int tmp = s21_from_sup_to_decimal(result, r);
  if (tmp == 0) {
    if (r.sign == 1) {
      res = 2;
    } else {
      res = 1;
    }
  }
  return res;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    res = 3;
  } else {
    s21_decimal_init(result);
    s21_sup_decimal v1, v2, r;
    s21_sup_decimal_init(&v1);
    s21_sup_decimal_init(&v2);
    s21_sup_decimal_init(&r);
    s21_from_decimal_to_sup(&v1, value_1);
    s21_from_decimal_to_sup(&v2, value_2);
    s21_sup_div(v1, v2, &r);
    int tmp = s21_from_sup_to_decimal(result, r);
    if (tmp == 0) {
      if (r.sign == 1) {
        res = 2;
      } else {
        res = 1;
      }
    }
  }
  return res;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    res = 3;
  } else {
    s21_decimal_init(result);
    s21_sup_decimal v1, v2, r;
    s21_sup_decimal_init(&v1);
    s21_sup_decimal_init(&v2);
    s21_sup_decimal_init(&r);
    s21_from_decimal_to_sup(&v1, value_1);
    s21_from_decimal_to_sup(&v2, value_2);
    s21_sup_mod(v1, v2, &r);
    int tmp = s21_from_sup_to_decimal(result, r);
    if (tmp == 0) {
      if (r.sign == 1) {
        res = 2;
      } else {
        res = 1;
      }
    }
  }
  return res;
}
