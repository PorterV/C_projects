#include "s21_string.h"
#include "s21_errno.h"

#include <stdlib.h>
#include <stdarg.h>

#define PLUS        0  // '+' flag
#define SPACE       1  // ' ' flag
#define MINUS       2  // '-' flag
#define POINT       3  // '.' percision only -> zero
#define GRID        4  // '#' out int hex or oct


void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *point = S21_NULL;
    unsigned char *strcp = (unsigned char*)str;

    while (n != 0) {
        if (*strcp != (unsigned char)c) {
            strcp++;
        } else {
            point = strcp;
            break;
        }
        n--;
    }
    return point;
}


int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int res = 0;
    unsigned char* f = (unsigned char*)str1;
    unsigned char* s = (unsigned char*)str2;
    s21_size_t s_str = s21_strlen(str1) > s21_strlen(str2) ? s21_strlen(str2) : s21_strlen(str1);
    int bo = s21_strlen(str1) > s21_strlen(str2) ? 1 : 0;
    int eq = s21_strlen(str1) == s21_strlen(str2) ? 1 : 0;
    while (n != 0 && s_str != 0) {
        int br = 0;
        if (*f != *s) {
            res = *f - *s;
            br = 1;
        }
        if (br == 0) {
            n--;
            s_str--;
            if (bo) {
                if (s_str == 0 && n != 0 && eq != 1) {
                    f++;
                    res = *f;
                    br = 1;
                }
            } else {
                if (s_str == 0 && n != 0 && eq != 1) {
                    s++;
                    res = -*s;
                    br = 1;
                }
            }
        }
        if (br) break;
        f++;
        s++;
    }
    return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *destCopy = (char*)dest;
    const char *srcCopy = (const char*)src;

    while (n != 0) {
        *destCopy = *srcCopy;
        destCopy++, srcCopy++;
        n--;
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *srcCopy = (char*)src;
    char *destCopy = (char*)dest;
    if ((srcCopy == S21_NULL) || (destCopy == S21_NULL)) {
        destCopy = S21_NULL;
    } else if ((srcCopy < destCopy) && (destCopy < srcCopy + n)) {
        for (destCopy = destCopy + n - 1, srcCopy = srcCopy + n - 1; n--;) {
            *destCopy-- = *srcCopy--;
        }
    } else {
        while (n--) {
            *destCopy++ = *srcCopy++;
        }
    }
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    char *strCopy = (char*)str;

    if (n != 0) {
        for (s21_size_t i = 0; i < n; i++) {
            *strCopy = c;
            strCopy++;
        }
    }
    return str;
}

char *s21_strcat(char *dest, const char *src) {
    s21_size_t length = s21_strlen(dest);
    while (*src != '\0') {
        dest[length] = *src;
        length++;
        src++;
    }
    dest[length] = '\0';
    return dest;
}

char *s21_strncat(char *dest, const char *src, int n) {
    int i, j;
    for (i = 0; dest[i] != '\0'; i++) {}
    for (j = 0; src[j] != '\0' && j < n; j++) {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';
    return dest;
}

char *s21_strchr(const char *str, int c) {
    char *strchr = S21_NULL;
    s21_size_t i = 0;
    while (str[i] && str[i] != c) {
        i++;
    }
    if (c == str[i]) {
        strchr = (char*) (str + i);
    }
    return strchr;
}

int s21_strcmp(const char *str1, const char *str2) {
    for (; *str1 && (*str1 == *str2); str1++, str2++) {
    }
    return *str1 - *str2;
}

int s21_strncmp(const char *str1, const char *str2, int n) {
    const char *fin = str1 + n;
    for (; str1 != fin && (*str1 || str2); str1++, str2++) {
    }
    return *str1 - *str2;
}

char *s21_strcpy(char *dest, const char *src) {
    char *tmp = dest;
    if (dest != S21_NULL) {
        while (*src != '\0') {
            *dest = *src;
            dest++;
            src++;
        }
    } else {
        tmp = S21_NULL;
    }
    *dest = '\0';
    return tmp;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    char* ptr = dest;
    if (dest == S21_NULL) {
        dest = S21_NULL;
    } else {
        while (*src && n--) {
            *dest = *src;
            dest++;
            src++;
        }
    }
    return ptr;
}


s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t ans = 0;
  if ((str1 != S21_NULL) && (str2 != S21_NULL)) {
    while (*str1) {
      if (!(s21_strchr(str2, *str1))) {
        str1++;
        ans++;
      } else {
          break;
      }
    }
  }
  return ans;
}

s21_size_t s21_strlen(const char *str) {
    const char *tmp = str;
    s21_size_t ans = 0;
    while (*tmp != '\0') {
        ans++;
        tmp++;
    }
    return ans;
}

char *s21_strerror(int errnum) {
    char *errors[] = S21_ERRORS;
    char *msg = malloc(sizeof(char) * 30);
    if (msg != S21_NULL) {
        if (errnum <= 0 || errnum >= S21_ERRNUMS) {
            s21_sprintf(msg, "Unknown error: %d", errnum);
        } else {
            s21_strcpy(msg, errors[errnum]);
        }
    }
    return (char *)msg;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    s21_size_t i, j, pos, flag = 0;
    for (i = 0; str1[i] != '\0'; i++) {}
    pos = i;
    for (i = 0; str2[i] != '\0'; i++) {
        for (j = 0; str1[j] != '\0'; j++) {
            if (str2[i] == str1[j]) {
                if (j <= pos) {
                    pos = j;
                    flag = 1;
                }
            }
        }
    }
    if (flag == 1) {
        return (char *)&str1[pos];
    } else {
        return S21_NULL;
    }
}

char *s21_strrchr(const char *str, int c) {
    char *ans = 0;
    do {
        if (*str == c) {
            ans = (char*) str;
        }
    } while (*str++);
    return ans;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t ans = 0;
    if ((str1 != S21_NULL) && (str2 != S21_NULL)) {
        while (*str1 && s21_strchr(str2, *str1++)) {
            ans++;
        }
    }
    return ans;
}

char *s21_strstr(const char *haystack, const char *needle) {
    while (*haystack != '\0') {
        char *begin = (char *)haystack;
        char *pattern = (char *)needle;
        while (*haystack && *pattern && *haystack == *pattern) {
            haystack++;
            pattern++;
        }
        if (!*pattern) {
            return begin;
        }
        haystack = begin + 1;
    }
    return S21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
    char* input = str;
    char* result = malloc((s21_strlen(input) + 1) * sizeof(char));
    if (result != S21_NULL) {
        int i = 0;
        if (input != S21_NULL) {
            for (; input[i] != '\0'; i++) {
                if (input[i] != *delim) {
                    result[i] = input[i];
                } else {
                    result[i] = '\0';
                    input = input + i + 1;
                }
            }
        }
        result[i] = '\0';
        input = S21_NULL;
    }
    char* tmp =  result;
    if (s21_strlen(result) == 0) {
        tmp = S21_NULL;
        free(result);
    }
    return tmp;
}

int s21_sprintf(char *str, const char *format, ...) {
    char *buf;
    const char *stroke;
    char number[1024];
    char flags[10];
    char type_exp_num[10];
    char sizeT;
    double value_exp;
    int field_width;
    int type, type_exp;
    s21_size_t percision, sizeS, j;
    va_list arg;
    va_start(arg, format);

    for (buf = str; *format; ++format) {
        if (*format != '%') {
            *str++ = *format;
            continue;
        }
        j = 0;
        // skip %
        format++;
        // shutdown flag
        flags[PLUS] = '1';
        flags[SPACE] = '1';
        flags[MINUS] = '1';
        flags[POINT] = '1';
        flags[GRID] = '1';
        format = s21_check_flags(flags, format);
        //  Width
        field_width = 0;
        while (s21_isdigit(*format)) {
            field_width = field_width * 10 + *format - '0';
            format++;
        }

        // Percision
        percision = 0;
        if (*format == '.') {
            flags[POINT] = '.';
            format++;
            while (s21_isdigit(*format)) {
                percision = percision * 10 + *format - '0';
                format++;
            }
        }

        // Type size
        sizeT = '0';
        if (*format == 'l' || *format == 'h') {
            sizeT = *format;
            format++;
        }

        switch (*format) {
            case 'c':
                field_width--;
                if (flags[MINUS] != '-')
                    str = s21_add_space(field_width, str);
                *str++ = (unsigned char)va_arg(arg, int);
                if (flags[MINUS] == '-')
                    str = s21_add_space(field_width, str);
                continue;
            case 's':
                stroke = va_arg(arg, char *);
                if (flags[POINT] == '.' && percision == 0)
                    sizeS = 0;
                else if (percision > 0 && percision < s21_strlen(stroke))
                    sizeS = percision;
                else
                    sizeS = s21_strlen(stroke);
                field_width -= sizeS;
                if (flags[MINUS] != '-')
                    str = s21_add_space(field_width, str);
                str = s21_create_format(j, sizeS, str, stroke);
                if (flags[MINUS] == '-')
                    str = s21_add_space(field_width, str);
                continue;
            case '%':
                *str++ = '%';
                continue;
            case 'i':
            case 'd':
                if (*format == 'i' || *format == 'd')
                    type = 10;
                if (sizeT == 'l')
                    s21_itoa(va_arg(arg, long), number, type, 0);
                else if (sizeT == 'h')
                    s21_itoa((short int)va_arg(arg, int), number, type, 0);
                else
                    s21_itoa(va_arg(arg, int), number, type, 0);
                sizeS = s21_create_sizeS(flags[POINT], percision, number[0], number);
                if (percision > 0)
                    percision -= sizeS;
                field_width -= sizeS + percision;
                if (flags[SPACE] == ' ' && number[0] != '-' && flags[PLUS] != '+') {
                    *str++ = ' ';
                    field_width--;
                }
                if (flags[PLUS] == '+' && number[0] != '-')
                    field_width--;
                if (flags[MINUS] != '-')
                    str = s21_add_space(field_width, str);
                if (flags[PLUS] == '+' && number[0] != '-') {
                    *str++ = '+';
                } else if (number[0] == '-') {
                    *str++ = '-';
                    j++;
                }
                if (number[0] == '-' && percision > sizeS)
                    percision++;
                str = s21_add_zero(percision, str);
                str = s21_create_format(j, sizeS, str, number);
                if (flags[MINUS] == '-')
                    str = s21_add_space(field_width, str);
                break;
            case 'p':
            case 'x':
            case 'X':
            case 'o':
            case 'u':
                if (*format == 'o') {
                    s21_itoa(va_arg(arg, unsigned long), number, 8, 1);
                } else if (*format == 'x') {
                    s21_itoa(va_arg(arg, unsigned int), number, 16, 1);
                    s21_to_lo(number);
                    if (flags[GRID] == '#')
                        field_width -= 2;
                } else if (*format == 'X') {
                    s21_itoa(va_arg(arg, unsigned int), number, 16, 1);
                    s21_to_up(number);
                    if (flags[GRID] == '#')
                        field_width -= 2;
                } else if (*format == 'p') {
                    s21_itoa((long)va_arg(arg, void *), number, 16, 1);
                    s21_to_lo(number);
                    field_width -= 2;
                } else {
                    s21_itoa(va_arg(arg, int), number, 10, 1);
                }
                sizeS = s21_create_sizeS(flags[POINT], percision, number[0], number);
                if (percision > 0)
                    percision -= sizeS;
                field_width -= sizeS + percision;
                if (flags[SPACE] == ' ' && flags[PLUS] != '+') {
                    *str++ = ' ';
                    field_width--;
                }
                if (flags[MINUS] != '-')
                    str = s21_add_space(field_width, str);
                str = s21_check_grid_flag(flags[GRID], format, str);
                str = s21_add_zero(percision, str);
                str = s21_create_format(j, sizeS, str, number);
                if (flags[MINUS] == '-')
                    str = s21_add_space(field_width, str);
                break;
            case 'g':
            case 'G':
            case 'E':
            case 'e':
            case 'f':
                if (*format == 'e' || *format == 'E' ||
                   (*format == 'g' && flags[POINT] == '.') ||
                   (*format == 'G' && flags[POINT] == '.')) {
                    value_exp = va_arg(arg, double);
                    type_exp = s21_exp(value_exp);
                    s21_itoa(type_exp, type_exp_num, 10, 0);
                    if (percision > 0)
                        s21_exponent(value_exp, number, percision);
                    else if (flags[POINT] == '.' && percision == 0)
                        s21_exponent(value_exp, number, 0);
                    else
                        s21_exponent(value_exp, number, 6);
                    sizeS = s21_create_sizeS(flags[POINT], percision, number[0], number);
                    if (percision > 0)
                        percision -= sizeS - 3;
                    field_width -= sizeS + percision + 4;
                } else if (*format == 'f' || (*format == 'g' && flags[POINT] != '.') ||
                          (*format == 'G' && flags[POINT] != '.')) {
                    if (percision > 0)
                        s21_ftoa(va_arg(arg, double), number, percision);
                    else if (flags[POINT] == '.' && percision == 0)
                        s21_ftoa(va_arg(arg, double), number, 0);
                    else if (*format == 'G' || *format == 'g')
                        s21_ftoa(va_arg(arg, double), number, 4);
                    else
                        s21_ftoa(va_arg(arg, double), number, 6);
                    sizeS = s21_create_sizeS(flags[POINT], percision, number[0], number);
                    if (*format == 'g' || *format == 'G') {
                        while (number[sizeS - 1] == '0')
                            sizeS--;
                    }
                    field_width -= sizeS;
                }
                if (flags[SPACE] == ' ' && number[0] != '-' && flags[PLUS] != '+') {
                    *str++ = ' ';
                    field_width--;
                }
                 if (flags[PLUS] == '+' && number[0] != '-')
                    field_width--;
                if (flags[MINUS] != '-')
                    str = s21_add_space(field_width, str);
                if (flags[PLUS] == '+' && number[0] != '-') {
                    *str++ = '+';
                } else if (number[0] == '-') {
                    *str++ = '-';
                    j++;
                }
                if (number[0] == '-' && percision > sizeS)
                    percision++;
                str = s21_create_format(j, sizeS, str, number);
                if (*format == 'e' || *format == 'E' ||
                   (*format == 'g' && flags[POINT] == '.' && percision == 0) ||
                   (*format == 'G' && flags[POINT] == '.' && percision == 0)) {
                    if (*format == 'e' || *format == 'g')
                        *str++ = 'e';
                    else if (*format == 'E' || *format == 'G')
                        *str++ = 'E';
                    if (type_exp < 9 && type_exp >= 0) {
                        *str++ = '+';
                        *str++ = '0';
                        *str++ = type_exp_num[0];
                    } else if (type_exp > 9) {
                        *str++ = '+';
                        for (s21_size_t k = 0; k < s21_strlen(type_exp_num); k++)
                            *str++ = type_exp_num[k];
                    } else if (type_exp < 0 && type_exp >= -9) {
                        *str++ = '-';
                        *str++ = '0';
                        *str++ = type_exp_num[1];
                    } else if (type_exp < -9) {
                        *str++ = '-';
                        for (s21_size_t k = 1; k < s21_strlen(type_exp_num); k++)
                            *str++ = type_exp_num[k];
                    }
                }
                if (flags[MINUS] == '-')
                    str = s21_add_space(field_width, str);
                break;
        }
    }
    va_end(arg);
    *str = '\0';
    return str - buf;
}

void *s21_to_lower(const char *str) {
    char *temp_str = S21_NULL;

    if (str != S21_NULL) {
        temp_str = calloc((s21_strlen(str) + 1), sizeof(char));
        if (temp_str != S21_NULL) {
            s21_strcpy(temp_str, str);
            for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
                if (temp_str[i] >= 65 && temp_str[i] <= 90) {
                     temp_str[i] = temp_str[i] + 32;
                }
            }
        }
        temp_str[s21_strlen(str)] = '\0';
    }

    return temp_str;
}


void *s21_to_upper(const char *str) {
    char *temp_str = S21_NULL;
    if (str != S21_NULL) {
        temp_str = calloc((s21_strlen(str) + 1), sizeof(char));
        if (temp_str != S21_NULL) {
            s21_strcpy(temp_str, str);
            for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
                if (temp_str[i] >= 97 && temp_str[i] <= 122) {
                temp_str[i] = temp_str[i] - 32;
                }
            }
        }
        temp_str[s21_strlen(str)] = '\0';
    }
    return temp_str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *str_insert = S21_NULL;
    str_insert = calloc((s21_strlen(src) + s21_strlen(str) + 1), sizeof(char));
    if (str_insert != S21_NULL) {
        for (s21_size_t i = 0, q = 0; i < s21_strlen(src); i++, q++) {
            if (i == start_index) {
                s21_strcat(str_insert, str);
                q += s21_strlen(str);
            }
            str_insert[q] = src[i];
        }
    }
    return str_insert;
}

void *s21_trim(const char *src, const char *trim_chars) {
    int is_error = 0;
    char *result = S21_NULL;
    if (src) {
        char default_chars[7] = " \t\n\v\r\f\0";
        if (trim_chars == S21_NULL || s21_strlen(trim_chars) == 0) trim_chars = default_chars;
        result = (char *) calloc(s21_strlen(src) + 10, sizeof(char));
        if (result == S21_NULL) {
            is_error = 1;
        }
        s21_strcpy(result, (char *)src);
        delete_left_part(result, src, trim_chars);
        delete_right_part(result, src, trim_chars);
    } else {
        is_error = 1;
    }
    return is_error ? S21_NULL : (void *)result;
}

void delete_first_letter(char *str) {
    s21_size_t counter = 0;
    while (str[counter]) {
        str[counter] = str[counter + 1];
        counter++;
    }
}

void delete_left_part(char *result, const char *src, const char *trim_chars) {
    s21_size_t format_length = s21_strlen(trim_chars);
    s21_size_t str_length = s21_strlen(src);
    for (s21_size_t i = 0; i < str_length; i++) {
        int is_break = 0;
        for (s21_size_t j = 0; j < format_length; j++) {
            if (src[i] == trim_chars[j]) {
                delete_first_letter(result);
                break;
            }
            if (j == format_length - 1 && src[i] != trim_chars[format_length]) {
                is_break = 1;
            }
        }
        if (is_break) break;
    }
}

void delete_right_part(char *result, const char *src, const char *trim_chars) {
    s21_size_t format_length = s21_strlen(trim_chars);
    s21_size_t result_length = s21_strlen(result);
    for (int i = (int) result_length - 1; i >= 0; i--) {
        int is_break = 0;
        for (s21_size_t j = 0; j < format_length; j++) {
            if (result[i] == trim_chars[j]) {
                result[i] = '\0';
                break;
            }
            if (j == format_length - 1 && src[i] != trim_chars[format_length]) {
                is_break = 1;
            }
        }
        if (is_break) break;
    }
}

void *s21_to_lo(const char *str) {
    char *s = (char*)str;
    if (s != S21_NULL) {
        while (*s != '\0') {
            if (*s >= 'A' && *s <= 'Z') {
                *s += 32;
            }
            s++;
        }
    }
    return s;
}

void *s21_to_up(const char *str) {
    char *s = (char*)str;
    if (s != S21_NULL) {
        while (*s != '\0') {
            if (*s >= 'a' && *s <= 'z') {
                *s -= 32;
            }
            s++;
        }
    }
    return s;
}

