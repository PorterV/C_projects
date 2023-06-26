#include <check.h>

#include "../lib/polish_notation.h"

START_TEST(t1) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "1+2+3");
  s21_polish_notation(buf, &res, 0);
  ck_assert_double_eq(res, 1 + 2 + 3);
  free(buf);
}
END_TEST

START_TEST(t2) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "sin(1)^tan(1)+43/2*0+cos(45)");
  s21_polish_notation(buf, &res, 0);
  ck_assert_double_eq_tol(res, 1.289607, 1e-6);
  free(buf);
}
END_TEST

START_TEST(t3) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "tan(x)-5");
  s21_polish_notation(buf, &res, 1);
  ck_assert_double_eq_tol(res, -3.442592275, 1e-6);
  free(buf);
}
END_TEST

START_TEST(t4) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "5----5+66*312.24^sin(45)");
  s21_polish_notation(buf, &res, 0);
  ck_assert_double_eq_tol(res, 8762.115184, 1e-6);
  free(buf);
}
END_TEST

START_TEST(t5) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "5-()()()()---5+66*312.24^sin(45)");
  ck_assert_int_eq(ERROR, s21_polish_notation(buf, &res, 0));
  free(buf);
}
END_TEST

START_TEST(t6) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "asin(0.123)+acos(0.32)-atan(1)");
  ck_assert_int_eq(1, s21_polish_notation(buf, &res, 0));
  free(buf);
}
END_TEST

START_TEST(t7) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "sqrt(2536745.2354)");
  s21_polish_notation(buf, &res, 0);
  ck_assert_double_eq_tol(res, sqrt(2536745.2354), 1e-6);
  free(buf);
}
END_TEST

START_TEST(t8) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "sqrt(2536745.2354)%%2");
  s21_polish_notation(buf, &res, 0);
  ck_assert_double_eq_tol(res, fmod(sqrt(2536745.2354), 2), 1e-6);
  free(buf);
}
END_TEST

START_TEST(t9) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "1/(1+3-5)*1000");
  s21_polish_notation(buf, &res, 0);
  ck_assert_double_eq_tol(res, 1 / (1 + 3 - 5) * 1000, 1e-6);
  free(buf);
}
END_TEST

START_TEST(t10) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "x");
  s21_polish_notation(buf, &res, 5);
  ck_assert_double_eq_tol(res, 5, 1e-6);
  free(buf);
}
END_TEST

START_TEST(t11) {
  list *lol = NULL;
  ck_assert_int_eq(0, s21_peek_number(lol));
  ck_assert_int_eq(0, s21_peek_operand(lol));
  ck_assert_int_eq(0, s21_peek_priority(lol));
}
END_TEST

START_TEST(t12) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "1 +  2");
  s21_polish_notation(buf, &res, 0);
  ck_assert_double_eq_tol(res, 3, 1e-6);
  free(buf);
}
END_TEST

START_TEST(t13) {
  char *buf = (char *)calloc(256, sizeof(char));
  double res = 0;
  sprintf(buf, "ln(123)^log(321)-222");
  s21_polish_notation(buf, &res, 0);
  ck_assert_double_eq_tol(res, pow(log(123), log10(321)) - 222, 1e-6);
  free(buf);
}
END_TEST

START_TEST(credit_annuity_test) {
  double s = 200000;
  int n = 12;
  double p = 13;
  double e = 0;
  double l = 0;
  double v = 0;
  s21_credit_annuity(s, n, p, &e, &l, &v);
  ck_assert_double_eq_tol(e, 17863.417609, 1e-6);
  ck_assert_double_eq_tol(l, 14361.489538, 1e-6);
  ck_assert_double_eq_tol(v, 214361.489538, 1e-6);
}

START_TEST(credit_differ_test) {
  double s = 200000;
  int n = 12;
  double p = 15;
  double e = 0;
  double l = 0;
  double v = 0;
  double e_min = 0;
  s21_credit_differ(s, n, p, &e, &e_min, &l, &v);
  ck_assert_double_eq_tol(e, 19166.666667, 1e-6);
  ck_assert_double_eq_tol(l, 16250.000000, 1e-6);
  ck_assert_double_eq_tol(v, 216250.000000, 1e-6);
  ck_assert_double_eq_tol(e_min, 16875, 1e-6);
}

END_TEST
int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, t1);
  tcase_add_test(tc1_1, t2);
  tcase_add_test(tc1_1, t3);
  tcase_add_test(tc1_1, t4);
  tcase_add_test(tc1_1, t5);
  tcase_add_test(tc1_1, t6);
  tcase_add_test(tc1_1, t7);
  tcase_add_test(tc1_1, t8);
  tcase_add_test(tc1_1, t9);
  tcase_add_test(tc1_1, t10);
  tcase_add_test(tc1_1, t11);
  tcase_add_test(tc1_1, t12);
  tcase_add_test(tc1_1, t13);
  tcase_add_test(tc1_1, credit_annuity_test);
  tcase_add_test(tc1_1, credit_differ_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}