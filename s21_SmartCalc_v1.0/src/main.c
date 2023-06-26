#include "lib/polish_notation.h"

// int main() {
//   char *buf;
//   buf = calloc(256, sizeof(char));
//   // scanf("%s", buf);
//   char ch = 0;
//   int i = 0;
//   while (ch != '\n') {
//     scanf("%c", &ch);
//     buf[i] = ch;
//     i++;
//   }
//   buf[i - 1] = '\0';
//   // printf("buf = %s\n", buf);
//   double num = 0;
//   s21_polish_notation(buf, &num, 0);
//   if (s21_polish_notation(buf, &num, 2) == -1) {
//     printf("\nERROR\n");
//     return 0;
//   }
//   printf("num = %f\n", num);
//   // printf("VALID = %d\n", validation(buf));
//   free(buf);
//   return 0;
// }





// double credit_annuity(double s, int n, double p, double *e, double *l, double *v);
// double credit_differ(double s, int n, double p, double *e, double *e_min, double *l, double *v);

int main() {
// Вход: общая сумма кредита(s), срок(n), процентная ставка(p), тип (аннуитетный, дифференцированный)
  double s = 0; int n = 0; double p = 0;
// Выход: ежемесячный платеж(e), переплата по кредиту(l), общая выплата(v)
  double e = 0; double e_min = 0; double l = 0; double v = 0;

  int type = 0;
  printf("тип кредита: 0 - annuity, 1 - differ\n");
  scanf("%d", &type);
  printf("общая сумма кредита\n");
  scanf("%lf", &s);
  printf("срок\n");
  scanf("%d", &n);
  printf("процентная ставка\n");
  scanf("%lf", &p);
  if (type == 0) {
    credit_annuity(s, n, p, &e, &l, &v);
    printf("ежемесячный платеж(e) = %f\n переплата по кредиту(l) = %f\n общая выплата(v) = %f\n", e, l, v);
  } else {
    credit_differ(s, n, p, &e, &e_min, &l, &v);
    printf("ежемесячный платеж(e) = %f ... %f\n переплата по кредиту(l) = %f\n общая выплата(v) = %f\n", e, e_min, l, v);
  }
  return 0;
}


// кредитный калькулятор

// Вход: общая сумма кредита(s), срок(n), процентная ставка(p), тип (аннуитетный, дифференцированный)

// Выход: ежемесячный платеж(e), переплата по кредиту(l), общая выплата(v)

// // аннуитетный
// s - общая сумма кредита
// n - срок в месяцах(!!!!)
// p - 1/100 процентная ставка

// double credit_annuity(double s, int n, double p, double *e, double *l, double *v) {
//   double p_month = p / 100 / 12;
//   // printf("%lf\n", p_month);
//   char *buf = (char *)calloc(256, sizeof(char));
//   // sprintf(buf, "%f * (%f + (%f / ((1 + %f) ^ %d - 1)))", s, p_month, p_month, p_month, n);
//   // printf("buf = %s\n", buf);
//   s21_polish_notation(buf, e, 0);
//   // printf("%lf\n", *e);
//   free(buf);
//   double l_month = 0;
//   double s_left = s;
//   double p_left = 0;
//   for (int i = 0; i < n; i++) {
//     // printf("month = %d\n", i);
//     p_left = s_left * p_month;
//     // printf("p_left = %lf\n", p_left);
//     l_month = *e - p_left;
//     // printf("l_month = %lf\n", l_month);
//     *l += p_left;
//     // printf("l = %lf\n", *l);
//     s_left -= l_month;
//     // printf("s_left = %lf\n", s_left);
//   }
//   *v = s + *l;
//   return 0;
// }

// double credit_differ(double s, int n, double p, double *e, double *e_min, double *l, double *v) {
//   double p_month = p / 100 / 12;
//   double b_month = s / n;
//   *e = s * p_month + b_month;
//   double s_left = s;
//   double l_left = 0;
//   double pl_left = 0;
//   for (int i = 0; i < n; i++) {
//     // printf("month = %d\n", i);
//     l_left = s_left * p_month;
//     // printf("l_left = %lf\n", l_left);
//     pl_left = b_month + l_left;
//     // printf("pl_left = %lf\n", pl_left);
//     *l += l_left;
//     // printf("l = %lf\n", *l);
//     s_left -= b_month;
//     // printf("s_left = %lf\n", s_left);
//   }
//   *e_min = pl_left;
//   *v = s + *l;
//   return 0;
// }
