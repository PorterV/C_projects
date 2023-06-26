#include <check.h>

#include "../parse.h"

START_TEST(case_parse) {
  float *vershs;
  unsigned int *poverhs;
  int a = 0;
  int b = 0;

  int res = s21_parse("./Viewer/c_libs/test/cat.obj", &vershs, &poverhs, &a, &b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(case_rotate_1) {
  float *point = malloc(3 * sizeof(float));
  float *point_check = malloc(3 * sizeof(float));

  int res = 0;
  point[0] = 1;
  point[1] = 1;
  point[2] = 1;

  point_check[0] = 1;
  point_check[1] = -1;
  point_check[2] = -1;

  s21_rotate(point, 3, M_PI, 1, 0, 0, 0);

  for (int i = 0; i < 3; i++) {
    if (point[i] == point_check[i]) {
      res = 1;
    }
  }

  ck_assert_int_eq(res, 1);

  free (point);
  free (point_check);
}
END_TEST

START_TEST(case_rotate_2) {
  float *point = malloc(3 * sizeof(float));
  float *point_check = malloc(3 * sizeof(float));

  int res = 0;
  point[0] = 1;
  point[1] = 1;
  point[2] = 1;

  point_check[0] = -1;
  point_check[1] = 1;
  point_check[2] = -1;

  s21_rotate(point, 3, M_PI, 2, 0, 0, 0);

  for (int i = 0; i < 3; i++) {
    if (point[i] == point_check[i]) {
      res = 1;
    }
  }

  ck_assert_int_eq(res, 1);

  free (point);
  free (point_check);
}
END_TEST

START_TEST(case_rotate_3) {
  float *point = malloc(3 * sizeof(float));
  float *point_check = malloc(3 * sizeof(float));

  int res = 0;

  point[0] = 1;
  point[1] = 1;
  point[2] = 1;

  point_check[0] = -1;
  point_check[1] = -1;
  point_check[2] = 1;

  s21_rotate(point, 3, M_PI, 3, 0, 0, 0);

  for (int i = 0; i < 3; i++) {
    if (point[i] == point_check[i]) {
      res = 1;
    }
  }

  ck_assert_int_eq(res, 1);

  free (point);
  free (point_check);
}
END_TEST

START_TEST(case_scale_1) {
  float *point = malloc(3 * sizeof(float));
  float *point_check = malloc(3 * sizeof(float));

  int res = 0;

  point[0] = 1;
  point[1] = 1;
  point[2] = 1;

  point_check[0] = 2;
  point_check[1] = 2;
  point_check[2] = 2;

  s21_scale(point, 2, 3);

  for (int i = 0; i < 3; i++) {
    if (point[i] == point_check[i]) {
      res = 1;
    }
  }

  ck_assert_int_eq(res, 1);

  free (point);
  free (point_check);
}
END_TEST

START_TEST(case_movement_1) {
  float *point = malloc(3 * sizeof(float));
  float *point_check = malloc(3 * sizeof(float));

  int res = 0;

  point[0] = 1;
  point[1] = 1;
  point[2] = 1;

  point_check[0] = 3;
  point_check[1] = 1;
  point_check[2] = 1;

  s21_movement(point, 3, 2, 1);

  for (int i = 0; i < 3; i++) {
    if (point[i] == point_check[i]) {
      res = 1;
    }
  }

  ck_assert_int_eq(res, 1);

  free (point);
  free (point_check);
}
END_TEST

START_TEST(case_movement_2) {
  float *point = malloc(3 * sizeof(float));
  float *point_check = malloc(3 * sizeof(float));

  int res = 0;

  point[0] = 1;
  point[1] = 1;
  point[2] = 1;

  point_check[0] = 1;
  point_check[1] = 3;
  point_check[2] = 1;

  s21_movement(point, 3, 2, 2);

  for (int i = 0; i < 3; i++) {
    if (point[i] == point_check[i]) {
      res = 1;
    }
  }

  ck_assert_int_eq(res, 1);

  free (point);
  free (point_check);
}
END_TEST

START_TEST(case_movement_3) {
  float *point = malloc(3 * sizeof(float));
  float *point_check = malloc(3 * sizeof(float));

  int res = 0;

  point[0] = 1;
  point[1] = 1;
  point[2] = 1;

  point_check[0] = 1;
  point_check[1] = 1;
  point_check[2] = 3;

  s21_movement(point, 3, 2, 3);

  for (int i = 0; i < 3; i++) {
    if (point[i] == point_check[i]) {
      res = 1;
    }
  }

  ck_assert_int_eq(res, 1);

  free (point);
  free (point_check);
}
END_TEST

START_TEST(case_parse_bug_1) {
  float *vershs;
  unsigned int *poverhs;
  int a = 0;
  int b = 0;

  int res = s21_parse("./Viewer/c_libs/test/cat_bug_1.obj", &vershs, &poverhs, &a, &b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(case_parse_bug_2) {
  float *vershs;
  unsigned int *poverhs;
  int a = 0;
  int b = 0;

  int res = s21_parse("./Viewer/c_libs/test/cat_bug_2.obj", &vershs, &poverhs, &a, &b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(case_parse_bug_3) {
  float *vershs;
  unsigned int *poverhs;
  int a = 0;
  int b = 0;

  int res = s21_parse("./Viewer/c_libs/test/cat_bug_3.obj", &vershs, &poverhs, &a, &b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(case_parse_bug_4) {
  float *vershs;
  unsigned int *poverhs;
  int a = 0;
  int b = 0;

  int res = s21_parse("./Viewer/c_libs/test/cat_bug_4.obj", &vershs, &poverhs, &a, &b);
  ck_assert_int_eq(res, 0);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, case_parse);  
  tcase_add_test(tc1_1, case_rotate_1);  
  tcase_add_test(tc1_1, case_rotate_2); 
  tcase_add_test(tc1_1, case_rotate_3); 
  tcase_add_test(tc1_1, case_scale_1); 
  tcase_add_test(tc1_1, case_movement_1); 
  tcase_add_test(tc1_1, case_movement_2); 
  tcase_add_test(tc1_1, case_movement_3); 
  tcase_add_test(tc1_1, case_parse_bug_1);
  tcase_add_test(tc1_1, case_parse_bug_2); 
  tcase_add_test(tc1_1, case_parse_bug_3); 
  tcase_add_test(tc1_1, case_parse_bug_4); 

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
