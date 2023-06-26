#include "polish_notation.h"

double s21_calculator(list *stack, double X) {
  list *head = NULL;
  list *work = NULL;
  double res = 0;
  while (stack) {
    s21_push(&head, s21_peek_number(stack), s21_peek_operand(stack),
             s21_peek_priority(stack));
    s21_pop(&stack);
  }
  while (head) {
    if (s21_peek_operand(head) == 0) {
      if (s21_peek_priority(head) == 999) {
        s21_push(&work, X, 0, 0);
      } else {
        s21_push(&work, s21_peek_number(head), 0, 0);
      }
    } else {
      if ((s21_peek_operand(head) >= ADD && s21_peek_operand(head) <= MOD) ||
          s21_peek_operand(head) == POW) {
        double a = s21_pop(&work);
        double b = s21_pop(&work);
        res = s21_arithmetic(b, a, s21_peek_operand(head));
        s21_push(&work, res, 0, 0);
      } else {
        res = s21_functions(s21_pop(&work), s21_peek_operand(head));
        s21_push(&work, res, 0, 0);
      }
    }
    s21_pop(&head);
  }
  while (work != NULL) s21_pop(&work);
  return res;
}

double s21_arithmetic(double a, double b, int oper) {
  double res = 0;
  switch (oper) {
    case ADD:
      res = a + b;
      break;
    case SUB:
      res = a - b;
      break;
    case MUL:
      res = a * b;
      break;
    case DIV:
      res = a / b;
      break;
    case MOD:
      res = fmod(a, b);
      break;
    case POW:
      res = pow(a, b);
      break;
  }
  return res;
}

double s21_functions(double a, int oper) {
  double res = 0;
  switch (oper) {
    case SIN:
      res = sin(a);
      break;
    case COS:
      res = cos(a);
      break;
    case TAN:
      res = tan(a);
      break;
    case ASIN:
      res = asin(a);
      break;
    case ACOS:
      res = acos(a);
      break;
    case ATAN:
      res = atan(a);
      break;
    case SQRT:
      res = sqrt(a);
      break;
    case UNARY_MIN:
      res = -a;
      break;
    case LN:
      res = log(a);
      break;
    case LOG:
      res = log10(a);
      break;
  }
  return res;
}

double s21_credit_annuity(double s, int n, double p, double *e, double *l,
                          double *v) {
  double p_month = p / 100 / 12;
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "%f * (%f + (%f / ((1 + %f) ^ %d - 1)))", s, p_month, p_month,
          p_month, n);
  s21_polish_notation(buf, e, 0);
  free(buf);
  double l_month = 0;
  double s_left = s;
  double p_left = 0;
  for (int i = 0; i < n; i++) {
    p_left = s_left * p_month;
    l_month = *e - p_left;
    *l += p_left;
    s_left -= l_month;
  }
  *v = s + *l;
  return 0;
}

double s21_credit_differ(double s, int n, double p, double *e, double *e_min,
                         double *l, double *v) {
  double p_month = p / 100 / 12;
  double b_month = s / n;
  *e = s * p_month + b_month;
  double s_left = s;
  double l_left = 0;
  double pl_left = 0;
  for (int i = 0; i < n; i++) {
    l_left = s_left * p_month;
    pl_left = b_month + l_left;
    *l += l_left;
    s_left -= b_month;
  }
  *e_min = pl_left;
  *v = s + *l;
  return 0;
}
