#include "s21_string.h"

long int s21_abs(long int i) {
  return i < 0 ? -i : i;
}

void s21_swap(char *x, char *y) {
    char t = *x;
    *x = *y;
    *y = t;
}

char* s21_reverse(char *buffer, int i, int j) {
    while (i < j) {
        s21_swap(&buffer[i++], &buffer[j--]);
    }
    return buffer;
}

int s21_isdigit(char value) {
    return (value >= '0' && value <= '9' ? 1 : 0);
}

char *s21_add_space(int field_width, char *str) {
    while (field_width-- > 0)
        *str++ = ' ';
    return str;
}

char *s21_add_zero(int percision, char *str) {
    while (percision-- > 0)
        *str++ = '0';
    return str;
}

char *s21_create_format(int j, int sizeS, char *str, const char *dest) {
    for (; j < sizeS; j++)
        *str++ = dest[j];
    return str;
}

char *s21_check_flags(char *flags, const char *format) {
    while (*format == '-' || *format == '+' || *format == ' ' ||
        *format == '#') {
        if (*format == '+')
            flags[0] = *format;
        if (*format == ' ')
            flags[1] = *format;
        if (*format == '-')
            flags[2] = *format;
        if (*format == '#')
            flags[4] = *format;
        format++;
    }
    return (char *)format;
}

char *s21_check_grid_flag(char flag, const char *format, char *str) {
    if ((flag == '#' && *format == 'x') || *format == 'p') {
        *str++ = '0';
        *str++ = 'x';
    } else if (flag == '#' && *format == 'X') {
        *str++ = '0';
        *str++ = 'X';
    } else if (flag == '#' && *format == 'o') {
        *str++ = '0';
    }
    return str;
}

int s21_create_sizeS(char flag, int percision, char is_zero, char *size_dest) {
    int sizeS;

    if (flag == '.' && percision == 0 && is_zero == '0')
        sizeS = 0;
    else
        sizeS = s21_strlen(size_dest);
    return sizeS;
}
