#ifndef SRC_LIB_POLISH_NOTATION_H_
#define SRC_LIB_POLISH_NOTATION_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_STR "1234567890"
#define ERROR -1

typedef struct node_t {
  double num;
  int operand;
  int priority;
  struct node_t *next;
} list;

enum opers {
  ADD = 1,
  SUB = 2,
  MUL = 3,
  DIV = 4,
  MOD = 5,
  SIN = 6,
  COS = 7,
  TAN = 8,
  ASIN = 9,
  ACOS = 10,
  ATAN = 11,
  POW = 12,
  SQRT = 13,
  F_BR = 14,
  L_BR = 15,
  UNARY_MIN = 16,
  LOG = 17,
  LN = 18
};

void s21_push(list **head, double num, int oper, int prio);
double s21_pop(list **head);
double s21_peek_number(const list *head);
int s21_peek_operand(const list *head);
int s21_peek_priority(const list *head);

int s21_polish_notation(char *str, double *result, double X);
int s21_with_operand(const char *str, list **work, list **oper,
                     int unary_minus);
int s21_what_operand(char *buf);
int s21_priority_operand(char *buf);
void s21_push_number(char *str, list **work, int len, int unary_minus);
int s21_check_number(const char *str);
int s21_check_operand(const char *str);
int s21_check_function(const char *str);
int s21_error_operand(const char *buf, int i, int stop_val);
int s21_validation(char *str);

double s21_calculator(list *stack, double X);
double s21_arithmetic(double a, double b, int oper);
double s21_functions(double a, int oper);

double s21_credit_annuity(double s, int n, double p, double *e, double *l, double *v);
double s21_credit_differ(double s, int n, double p, double *e, double *e_min, double *l, double *v);

#endif  // SRC_LIB_POLISH_NOTATION_H_

