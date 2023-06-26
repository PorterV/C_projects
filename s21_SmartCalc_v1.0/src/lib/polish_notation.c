#include "polish_notation.h"

int s21_polish_notation(char *str, double *result, double X) {
  if (str == NULL) return ERROR;
  if (s21_validation(str) == ERROR) {
    return ERROR;
  }
  int err = 0;
  int stop = strlen(str);
  list *work = NULL;
  list *oper = NULL;
  int num_counter = 0;
  int oper_counter = 0;
  int x_counter = 0;
  int br_counter = 0;
  int prev_oper = 1;
  for (int i = 0; i < stop;) {
    if (*str == '(' || *str == ')') {
      if (i == 0 && *str == ')') {
        err = ERROR;
      }
      br_counter++;
    }
    if (err == ERROR) {
      *result = 0;
    } else if (*str == 'x') {
      s21_push(&work, 0, 0, 999);
      x_counter++;
      str++;
      i++;
      prev_oper = 0;
      num_counter++;
    } else if (s21_check_number(str) > 0) {
      i += s21_check_number(str);
      s21_push_number(str, &work, s21_check_number(str), 0);
      str += s21_check_number(str);
      num_counter++;
      prev_oper = 0;
    } else if (s21_check_operand(str) > 0) {
      if (s21_error_operand(str, i, stop - 1)) {
        err = ERROR;
      } else {
        if (*str == '-' && prev_oper == 1) {
          err = s21_with_operand(str, &work, &oper, 1);
        } else {
          err = s21_with_operand(str, &work, &oper, 0);
        }
        if (*str != ')') {
          prev_oper = 1;
        }
        str += s21_check_operand(str);
        i += err;
        oper_counter++;
      }
    } else if (*str == ' ') {
      prev_oper = 0;
      str++;
      i++;
    } else if (*str == '\0') {
      i = stop;
    } else {
      err = ERROR;
    }
    if (err == ERROR) {
      break;
    }
  }
  while (oper) {
    s21_push(&work, s21_peek_number(oper), s21_peek_operand(oper), 0);
    s21_pop(&oper);
  }
  if (oper_counter == 0 && num_counter == 1 && x_counter == 1) {
    *result = X;
  } else if (br_counter % 2 != 0) {
    err = ERROR;
    *result = 0;
  } else if (num_counter == 1 && oper_counter == 0 && x_counter == 0) {
    *result = s21_peek_number(work);
  } else {
    *result = s21_calculator(work, X);
  }

  return err;
}

int s21_with_operand(const char *str, list **work, list **oper,
                     int unary_minus) {
  char *buf = NULL;
  int result = 0;
  if (unary_minus == 1) {
    s21_push(oper, 0, 16, 3);
  } else if (*str == '(') {
    s21_push(oper, 0, F_BR, 0);
    result = 1;
  } else if (*str == ')') {
    while (s21_peek_operand(*oper) != F_BR) {
      s21_push(work, 0, s21_peek_operand(*oper), (*oper)->priority);
      s21_pop(oper);
    }
    s21_pop(oper);
    result = 1;
  } else {
    buf = calloc(s21_check_operand(str) + 1, sizeof(char));
    strncpy(buf, str, s21_check_operand(str));
    int prio_buf = s21_priority_operand(buf);
    if (prio_buf > s21_peek_priority(*oper) || *oper == NULL) {
      s21_push(oper, 0, s21_what_operand(buf), prio_buf);
    } else {
      int flag = 1;
      while (prio_buf <= s21_peek_priority(*oper) && *oper != NULL && flag) {
        if (s21_peek_operand(*oper) == F_BR) break;
        if (s21_what_operand(buf) == POW && s21_peek_operand(*oper) == POW) {
          flag = 0;
        }
        if (flag == 1) {
          s21_push(work, 0, s21_peek_operand(*oper), s21_peek_priority(*oper));
          s21_pop(oper);
        }
      }
      s21_push(oper, 0, s21_what_operand(buf), prio_buf);
    }
    free(buf);
  }
  return result;
}

int s21_what_operand(char *buf) {
  int res = 0;
  if (strstr(buf, "+")) {
    res = ADD;
  } else if (strncmp(buf, "-", 1) == 0) {
    res = SUB;
  } else if (strncmp(buf, "*", 1) == 0) {
    res = MUL;
  } else if (strncmp(buf, "/", 1) == 0) {
    res = DIV;
  } else if (strncmp(buf, "%", 1) == 0) {
    res = MOD;
  } else if (strncmp(buf, "sin", 3) == 0) {
    res = SIN;
  } else if (strncmp(buf, "cos", 3) == 0) {
    res = COS;
  } else if (strncmp(buf, "tan", 3) == 0) {
    res = TAN;
  } else if (strncmp(buf, "asin", 4) == 0) {
    res = ASIN;
  } else if (strncmp(buf, "acos", 4) == 0) {
    res = ACOS;
  } else if (strncmp(buf, "atan", 4) == 0) {
    res = ATAN;
  } else if (strncmp(buf, "^", 1) == 0) {
    res = POW;
  } else if (strncmp(buf, "sqrt", 4) == 0) {
    res = SQRT;
  } else if (strncmp(buf, "ln", 4) == 0) {
    res = LN;
  } else if (strncmp(buf, "log", 4) == 0) {
    res = LOG;
  }
  return res;
}

int s21_priority_operand(char *buf) {
  int res = 0;
  if (strlen(buf) > 1)
    while (*buf == ' ') buf++;
  if (*buf == '+' || *buf == '-') {
    res = 1;
  } else if (*buf == '*' || *buf == '/' || *buf == '%') {
    res = 2;
  } else if (strncmp(buf, "sin", 3) == 0 || strncmp(buf, "cos", 3) == 0 ||
             strncmp(buf, "tan", 3) == 0 || strncmp(buf, "asin", 4) == 0 ||
             strncmp(buf, "acos", 4) == 0 || strncmp(buf, "atan", 4) == 0 ||
             strncmp(buf, "sqrt", 4) == 0 || strncmp(buf, "log", 4) == 0 ||
             strncmp(buf, "ln", 4) == 0) {
    res = 4;
  } else if (*buf == '^') {
    res = 3;
  }
  return res;
}

void s21_push_number(char *str, list **work, int len, int unary_minus) {
  char *buf = calloc(1, sizeof(char) * len);
  strncpy(buf, str, len);
  double num = atof(buf);
  if (unary_minus) num = -num;
  s21_push(work, num, 0, 0);
  free(buf);
}

int s21_check_number(const char *str) {
  int result = strspn(str, NUMBER_STR);
  if (result > 0) {
    str += result;
    if (*str == '.') {
      str++;
      result++;
      if (strspn(str, NUMBER_STR) > 0 && str[strspn(str, NUMBER_STR)] != '.') {
        result += strspn(str, NUMBER_STR);
      } else {
        result = ERROR;
      }
    }
  }
  return result;
}

int s21_check_operand(const char *str) {
  int result = 0;
  if (*str == '+' || *str == '-' || *str == '(' || *str == ')' || *str == '*' ||
      *str == '/' || *str == '%' || *str == '^') {
    result = 1;
  } else {
    result = s21_check_function(str);
  }
  return result;
}

int s21_check_function(const char *str) {
  int res = 0;
  if (strncmp(str, "sin", 3) == 0) {
    res = 3;
  } else if (strncmp(str, "cos", 3) == 0) {
    res = 3;
  } else if (strncmp(str, "tan", 3) == 0) {
    res = 3;
  } else if (strncmp(str, "asin", 4) == 0) {
    res = 4;
  } else if (strncmp(str, "acos", 4) == 0) {
    res = 4;
  } else if (strncmp(str, "atan", 4) == 0) {
    res = 4;
  } else if (strncmp(str, "sqrt", 4) == 0) {
    res = 4;
  } else if (strncmp(str, "ln", 2) == 0) {
    res = 2;
  } else if (strncmp(str, "log", 3) == 0) {
    res = 3;
  }
  return res;
}

int s21_error_operand(const char *buf, int i, int stop_val) {
  int res = 0;
  if (i == 0 && s21_check_function(buf) < 0 && *buf != '-' &&
      strncmp(buf, "sqrt", 4) != 0 && *buf != '(') {
    res = 1;
  } else if (i == stop_val && *buf != ')') {
    res = 1;
  }
  return res;
}

int s21_validation(char *str) {
  if (strlen(str) > 255) {
    return ERROR;
  }
  int res = 0;
  char *buf = NULL;
  buf = (char *)calloc(strlen(str) + 1, sizeof(char));
  *buf = '\0';
  while (*str != '\0') {
    if (*str == ' ') {
      str++;
    } else if (*str == '(') {
      if (*buf == ')' || s21_check_number(buf) > 0) {
        res = ERROR;
      }
      buf = str;
      str++;
    } else if (*str == ')') {
      if (*buf == '(') {
        res = ERROR;
      }
      if (s21_check_operand(buf) > 0 && *buf != ')') {
        res = ERROR;
      }
      buf = str;
      str++;
    } else if (s21_check_operand(str) > 0) {
      if (s21_check_operand(buf) > 0 && *str != '-' && *buf != ')' &&
          s21_check_function(str) == 0) {
        res = ERROR;
      }
      buf = str;
      str += s21_check_operand(str);
    } else if (s21_check_number(str) > 0 || *str == 'x') {
      if (*buf == ')') {
        res = ERROR;
      }
      buf = str;
      if (*str == 'x') {
        str++;
      } else {
        str += s21_check_number(str);
      }
    } else {
      res = ERROR;
    }
    if (*str == '\0' && s21_check_operand(buf) > 0 && *buf != ')') {
      res = ERROR;
    }
    if (res == ERROR) {
      break;
    }
  }
  return res;
}
