#include "polish_notation.h"

void s21_push(list **head, double num, int oper, int prio) {
  list *tmp = calloc(1, sizeof(list));
  tmp->next = *head;
  tmp->num = num;
  tmp->operand = oper;
  tmp->priority = prio;
  *head = tmp;
}

double s21_pop(list **head) {
  list *out;
  double value;
  out = *head;
  *head = (*head)->next;
  value = out->num;
  free(out);
  return value;
}

double s21_peek_number(const list *head) {
  if (head == NULL) return 0;
  return head->num;
}

int s21_peek_operand(const list *head) {
  if (head == NULL) return 0;
  return head->operand;
}

int s21_peek_priority(const list *head) {
  if (head == NULL) return 0;
  return head->priority;
}
