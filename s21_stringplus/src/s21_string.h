#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define S21_NULL ((void *)0)
typedef long unsigned s21_size_t;
#define MAX_PRECISION (10)

#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "s21_errno.h"

void         *s21_memchr(const void *str, int c, s21_size_t n);
int          s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void         *s21_memcpy(void *dest, const void *src, s21_size_t n);
void         *s21_memmove(void *dest, const void *src, s21_size_t n);
void         *s21_memset(void *str, int c, s21_size_t n);

char         *s21_strcat(char *dest, const char *src);
char         *s21_strncat(char *dest, const char *src, int n);
char         *s21_strchr(const char *str, int c);
int          s21_strcmp(const char *str1, const char *str2);
int          s21_strncmp(const char *str1, const char *str2, int n);

char         *s21_strcpy(char *dest, const char *src);
char         *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t   s21_strcspn(const char *str1, const char *str2);
char         *s21_strerror(int errnum);
s21_size_t   s21_strlen(const char *str);

char         *s21_strpbrk(const char *str1, const char *str2);
char         *s21_strrchr(const char *str, int c);
s21_size_t   s21_strspn(const char *str1, const char *str2);
char         *s21_strstr(const char *haystack, const char *needle);
char         *s21_strtok(char *str, const char *delim);

long int     s21_abs(long int i);
void         s21_swap(char *x, char *y);
char         *s21_reverse(char *buffer, int i, int j);
char         *s21_itoa(long int value, char* buffer, int base, int unint);
char         *s21_ftoa(double f, char* buf, int precision);
char         *s21_exponent(double value, char* buf, int percision);
int          s21_exp(double value);
int          s21_isdigit(char value);
char         *s21_add_space(int field_width, char *str);
char         *s21_add_zero(int percision, char *str);
char         *s21_create_format(int j, int sizeS, char *str, const char *dest);
char         *s21_check_flags(char *flags, const char *format);
char         *s21_check_grid_flag(char flag, const char *format, char *str);
int          s21_create_sizeS(char flag, int percision, char is_zero, char *size_dest);
int          s21_sprintf(char *str, const char *format, ...);

void         *s21_to_upper(const char *str);
void         *s21_to_lower(const char *str);
void         *s21_insert(const char *src, const char *str, s21_size_t start_index);
void         *s21_trim(const char *src, const char *trim_chars);

void         delete_first_letter(char *str);
void         delete_left_part(char *result, const char *src, const char *trim_chars);
void         delete_right_part(char *result, const char *src, const char *trim_chars);
void         *s21_to_lo(const char *str);
void         *s21_to_up(const char *str);

#endif  // SRC_S21_STRING_H_
