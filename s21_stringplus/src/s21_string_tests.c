#include "../src/s21_string.h"

#include <check.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

START_TEST(s21_memchr_1) {
    unsigned char src[15]="1234567890";
    ck_assert_str_eq(s21_memchr(src, '3', 3), memchr(src, '3', 3));
}
END_TEST

START_TEST(s21_memchr_2) {
    unsigned char src[15]="Hello world\0";
    ck_assert_str_eq(s21_memchr(src, ' ', 7), memchr(src, ' ', 7));
}
END_TEST

START_TEST(s21_memchr_3) {
    unsigned char src[15] = "Hello world\0";
    ck_assert_pstr_eq(s21_memchr(src, 'o', 1), memchr(src, 'o', 1));
}
END_TEST

START_TEST(s21_memchr_4) {
    unsigned char src[15]="Hello world\n\0";
    ck_assert_str_eq(s21_memchr(src, ' ', 7), memchr(src, ' ', 7));
}
END_TEST

START_TEST(s21_memchr_5) {
    unsigned char src[15]="a\n\0";
    ck_assert_str_eq(s21_memchr(src, 'a', 1), memchr(src, 'a', 1));
}
END_TEST

START_TEST(s21_memchr_6) {
    unsigned char src[15]=" \n\0";
    ck_assert_str_eq(s21_memchr(src, ' ', 7), memchr(src, ' ', 7));
}
END_TEST

START_TEST(s21_memchr_7) {
    unsigned char src[15]=" \0";
    ck_assert_str_eq(s21_memchr(src, ' ', 1), memchr(src, ' ', 1));
}
END_TEST

START_TEST(s21_memchr_8) {
    ck_assert_pstr_eq(s21_memchr("\n\0", '0', 1), memchr("\n\0", '0', 1));
}
END_TEST

START_TEST(s21_memchr_10) {
    unsigned char src[15]="1234567890";
    ck_assert_str_eq(s21_memchr(src, '1', 6), memchr(src, '1', 6));
}
END_TEST

START_TEST(s21_memcmp_1) {
    unsigned char s1[10] = "1234\0";
    unsigned char s2[10] = "1\0";;
    ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
}
END_TEST

START_TEST(s21_memcmp_2) {
    unsigned char s1[10] = "1234\0";
    unsigned char s2[10] = "5678\0";
    ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
}
END_TEST

START_TEST(s21_memcmp_3) {
    unsigned char s1[20] = "Hello\0";
    unsigned char s2[20] = "Hello world\0";
    ck_assert_int_eq(s21_memcmp(s1, s2, 7), memcmp(s1, s2, 7));
}
END_TEST

START_TEST(s21_memcmp_4) {
    unsigned char s1[10] = "Hello\0";
    unsigned char s2[10] = "Bye\0";
    ck_assert_int_eq(s21_memcmp(s1, s2, 10), memcmp(s1, s2, 10));
}
END_TEST


START_TEST(s21_memcpy_1) {
    char str1[20] = "42\0";
    char str2[20] = "Hello\0";
    ck_assert_str_eq(s21_memcpy(str1, str2, 20), memcpy(str1, str2, 20));
}
END_TEST

START_TEST(s21_memcpy_2) {
    char str1[20] = "a\n\0";
    char str2[20] = " \n\0";
    ck_assert_str_eq(s21_memcpy(str1, str2, 1), memcpy(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcpy_3) {
    char str1[20] = "\0";
    char str2[20] = "\n\0";
    ck_assert_str_eq(s21_memcpy(str1, str2, 1), memcpy(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcpy_4) {
    char str2[20] = "42";
    char str1[20] = "Hello";
    ck_assert_str_eq(s21_memcpy(str1, str2, 20), memcpy(str1, str2, 20));
}
END_TEST

START_TEST(s21_memmove_1) {
    char str[20] = "1234567890";
    ck_assert_str_eq(s21_memmove(&str[4], &str[3], 3), memmove(&str[4], &str[3], 3));
}
END_TEST

START_TEST(s21_memmove_2) {
    char str[20] = "Hello world";
    ck_assert_str_eq(s21_memmove(&str[4], &str[3], 3), memmove(&str[4], &str[3], 3));
}
END_TEST

START_TEST(s21_memmove_3) {
    char str[20] = "Hello world\0";
    ck_assert_str_eq(s21_memmove(&str[4], &str[3], 3), memmove(&str[4], &str[3], 3));
}
END_TEST

START_TEST(s21_memmove_4) {
    char str[20] = "Hello world\n\0";
    ck_assert_str_eq(s21_memmove(&str[4], &str[3], 3), memmove(&str[4], &str[3], 3));
}
END_TEST

START_TEST(s21_memmove_5) {
    char str[20] = "a\n\0";
    ck_assert_str_eq(s21_memmove(&str[1], &str[1], 1), memmove(&str[1], &str[1], 1));
}
END_TEST

START_TEST(s21_memmove_6) {
    char str[20] = " \n\0";
    ck_assert_str_eq(s21_memmove(&str[1], &str[1], 1), memmove(&str[1], &str[1], 1));
}
END_TEST

START_TEST(s21_memmove_7) {
    char str[20] = " \0";
    ck_assert_str_eq(s21_memmove(&str[1], &str[1], 1), memmove(&str[1], &str[1], 1));
}
END_TEST

START_TEST(s21_memmove_8) {
    char str[20] = "\n\0";
    ck_assert_str_eq(s21_memmove(&str[1], &str[1], 1), memmove(&str[1], &str[1], 1));
}
END_TEST

START_TEST(s21_memmove_9) {
    char str[20] = "\0";
    ck_assert_str_eq(s21_memmove(&str[1], &str[1], 1), memmove(&str[1], &str[1], 1));
}
END_TEST

START_TEST(s21_memset_1) {
    char str[20] = "1234567890";
    ck_assert_str_eq(s21_memset(str, '1', 5), memset(str, '1', 5));
}
END_TEST

START_TEST(s21_memset_2) {
    char str[20] = "Hello world\0";
    ck_assert_str_eq(s21_memset(str, 'H', 12), memset(str, 'H', 12));
}
END_TEST

START_TEST(s21_memset_3) {
    char str[20] = "Hello world\n\0";
    ck_assert_str_eq(s21_memset(str, 'H', 12), memset(str, 'H', 12));
}
END_TEST

START_TEST(s21_memset_4) {
    char str[20] = "a\n\0";
    ck_assert_str_eq(s21_memset(str, 'm', 3), memset(str, 'H', 3));
}
END_TEST

START_TEST(s21_memset_5) {
    char str[20] = " \n\0";
    ck_assert_str_eq(s21_memset(str, 'm', 3), memset(str, 'H', 3));
}
END_TEST

START_TEST(s21_memset_6) {
    char str[20] = " \0";
    ck_assert_str_eq(s21_memset(str, 'm', 3), memset(str, 'H', 3));
}
END_TEST

START_TEST(s21_memset_7) {
    char str[20] = "\n\0";
    ck_assert_str_eq(s21_memset(str, 'm', 3), memset(str, 'H', 3));
}
END_TEST

START_TEST(s21_memset_8) {
    char str[3] = "\0";
    ck_assert_str_eq(s21_memset(str, 'm', 1), memset(str, 'H', 1));
}
END_TEST

START_TEST(s21_strlen_test_1) {
    ck_assert_int_eq(s21_strlen("Hello world\0"), strlen("Hello world\0"));
} END_TEST

START_TEST(s21_strlen_test_2) {
    ck_assert_int_eq(s21_strlen("Hello world\n\0"), strlen("Hello world\n\0"));
} END_TEST

START_TEST(s21_strlen_test_3) {
    ck_assert_int_eq(s21_strlen("a\n\0"), strlen("a\n\0"));
} END_TEST

START_TEST(s21_strlen_test_4) {
    ck_assert_int_eq(s21_strlen(" \n\0"), strlen(" \n\0"));
} END_TEST

START_TEST(s21_strlen_test_5) {
    ck_assert_int_eq(s21_strlen(" \0"), strlen(" \0"));
} END_TEST

START_TEST(s21_strlen_test_6) {
    ck_assert_int_eq(s21_strlen("\n\0"), strlen("\n\0"));
} END_TEST

START_TEST(s21_strlen_test_7) {
    ck_assert_int_eq(s21_strlen("\0"), strlen("\0"));
} END_TEST

START_TEST(s21_strcat_1) {
    char s1[50] = "Hello world\0";
    char s2[50] = " world\0";
    char s3[50] = "Hello world\0";
    ck_assert_str_eq(s21_strcat(s1, s2), strcat(s3, s2));
} END_TEST

START_TEST(s21_strcat_2) {
    char s1[50] = "a\n\0";
    char s2[50] = " \n\0";
    char s3[50] = "a\n\0";
    ck_assert_str_eq(s21_strcat(s1, s2), strcat(s3, s2));
} END_TEST

START_TEST(s21_strcat_3) {
    char s1[50] = " \0";
    char s2[50] = "\n\0";
    char s3[50] = " \0";
    ck_assert_str_eq(s21_strcat(s1, s2), strcat(s3, s2));
} END_TEST

START_TEST(s21_strcat_4) {
    char s1[50] = "\0";
    char s2[50] = "\n\0";
    char s3[50] = "\0";
    ck_assert_str_eq(s21_strcat(s1, s2), strcat(s3, s2));
} END_TEST

START_TEST(s21_strncat_1) {
    char s1[50] = "Hello world\0";
    char s2[50] = " world\0";
    char s3[50] = "Hello world\0";
    ck_assert_str_eq(s21_strncat(s1, s2, 3), strncat(s3, s2, 3));
} END_TEST

START_TEST(s21_strncat_2) {
    char s1[50] = "a\n\0";
    char s2[50] = " \n\0";
    char s3[50] = "a\n\0";
    ck_assert_str_eq(s21_strncat(s1, s2, 3), strncat(s3, s2, 3));
} END_TEST

START_TEST(s21_strncat_3) {
    char s1[50] = " \0";
    char s2[50] = "\n\0";
    char s3[50] = " \0";
    ck_assert_str_eq(s21_strncat(s1, s2, 1), strncat(s3, s2, 1));
} END_TEST

START_TEST(s21_strncat_4) {
    char s1[50] = "\0";
    char s2[50] = "\n\0";
    char s3[50] = "\0";
    ck_assert_str_eq(s21_strncat(s1, s2, 1), strncat(s3, s2, 1));
} END_TEST

START_TEST(s21_strchr_1) {
    char s1[50] = "asdf\0";
    char s3[50] = "asdf\0";
    ck_assert_str_eq(s21_strchr(s1, 'a'), strchr(s3, 'a'));
} END_TEST

START_TEST(s21_strchr_2) {
    char s1[50] = "Hello world\0";
    char s3[50] = "Hello world\0";
    ck_assert_str_eq(s21_strchr(s1, 'o'), strchr(s3, 'o'));
} END_TEST

START_TEST(s21_strchr_3) {
    char s1[50] = "Hello world\n\0";
    char s3[50] = "Hello world\n\0";
    ck_assert_str_eq(s21_strchr(s1, '\n'), strchr(s3, '\n'));
} END_TEST

START_TEST(s21_strchr_4) {
    char s1[50] = "Hello world\0";
    char s3[50] = "Hello world\0";
    ck_assert_str_eq(s21_strchr(s1, '\0'), strchr(s3, '\0'));
} END_TEST

START_TEST(s21_strchr_5) {
    char s1[50] = "Hello.world\0";
    char s3[50] = "Hello.world\0";
    ck_assert_str_eq(s21_strchr(s1, '.'), strchr(s3, '.'));
} END_TEST

START_TEST(s21_strchr_6) {
    char s1[50] = "Hello world\0";
    char s3[50] = "Hello world\0";
    ck_assert_str_eq(s21_strchr(s1, ' '), strchr(s3, ' '));
} END_TEST

START_TEST(s21_strcmp_1) {
    char s1[50] = "Hello world\0";
    char s3[50] = "Hello worl\0";
    ck_assert_int_eq(s21_strcmp(s1, s3), strcmp(s1, s3));
} END_TEST

START_TEST(s21_strcmp_2) {
    char s1[50] = " ";
    char s3[50] = " ";
    ck_assert_int_eq(s21_strcmp(s1, s3), strcmp(s1, s3));
} END_TEST

START_TEST(s21_strcmp_3) {
    char s1[50] = "\n\0";
    char s3[50] = "\n\0";
    ck_assert_int_eq(s21_strcmp(s1, s3), strcmp(s1, s3));
} END_TEST

START_TEST(s21_strcmp_4) {
    char s1[50] = "privet\0";
    char s3[50] = "privet medved\0";
    ck_assert_int_eq(s21_strcmp(s1, s3), strcmp(s1, s3));
} END_TEST

START_TEST(s21_strncmp_1) {
    char s1[50] = "Hello world\0";
    char s3[50] = "Hello worl\0";
    ck_assert_int_eq(s21_strncmp(s1, s3, 3), strncmp(s1, s3, 3));
} END_TEST

START_TEST(s21_strncmp_2) {
    char s1[50] = "Hello world\0";
    char s3[50] = "Hello\0";
    ck_assert_int_eq(s21_strncmp(s1, s3, 4), strncmp(s1, s3, 4));
} END_TEST

START_TEST(s21_strncmp_3) {
    char s1[50] = "\n\0";
    char s3[50] = "\n\0";
    ck_assert_int_eq(s21_strncmp(s1, s3, 1), strncmp(s1, s3, 1));
} END_TEST

START_TEST(s21_strncmp_4) {
    char s1[50] = "privet\0";
    char s3[50] = "privet medved\0";
    ck_assert_int_eq(s21_strncmp(s1, s3, 2), strncmp(s1, s3, 2));
} END_TEST

START_TEST(s21_strcpy_test_1) {
    char s1[] = "Hello world\0";
    char s2[] = "Hello \0";
    char s3[] = "Hello world\0";
    char s4[] = "Hello \0";
    s21_strcpy(s1, s2);
    strcpy(s3, s4);
    ck_assert_str_eq(s1, s3);
} END_TEST

START_TEST(s21_strcpy_test_2) {
    char s1[] = "Hello\0";
    char s2[] = "\0";
    char s3[] = "Hello\0";
    char s4[] = "\0";
    s21_strcpy(s1, s2);
    strcpy(s3, s4);
    ck_assert_str_eq(s1, s3);
} END_TEST

START_TEST(s21_strcpy_test_3) {
    char s1[] = " \n\0";
    char s2[] = " \0";
    char s3[] = " \n\0";
    char s4[] = " \0";
    s21_strcpy(s1, s2);
    strcpy(s3, s4);
    ck_assert_str_eq(s1, s3);
} END_TEST

START_TEST(s21_strcpy_test_4) {
    char s1[] = "\0";
    char s2[] = "\0";
    char s3[] = "\0";
    char s4[] = "\0";
    s21_strcpy(s1, s2);
    strcpy(s3, s4);
    ck_assert_str_eq(s1, s3);
} END_TEST

START_TEST(s21_strcpy_test_5) {
    char s1[] = "H e l l o\0";
    char s2[] = "H E L L O\0";
    char s3[] = "H e l l o\0";
    char s4[] = "H E L L O\0";
    s21_strcpy(s1, s2);
    strcpy(s3, s4);
    ck_assert_str_eq(s1, s3);
} END_TEST

START_TEST(s21_strncpy_test_1) {
    char s1[] = "Hello world\0";
    char s2[] = "Hello \0";
    char s3[] = "Hello world\0";
    char s4[] = "Hello \0";
    s21_strncpy(s1, s2, 3);
    strncpy(s3, s4, 3);
    ck_assert_str_eq(s1, s3);
} END_TEST

START_TEST(s21_strncpy_test_2) {
    char s1[] = "Hello\0";
    char s2[] = "123\0";
    char s3[] = "Hello\0";
    char s4[] = "123\0";
    s21_strncpy(s1, s2, 2);
    strncpy(s3, s4, 2);
    ck_assert_str_eq(s1, s3);
} END_TEST

START_TEST(s21_strncpy_test_3) {
    char s1[] = " \n\0";
    char s2[] = " \0";
    char s3[] = " \n\0";
    char s4[] = " \0";
    s21_strncpy(s1, s2, 1);
    strncpy(s3, s4, 1);
    ck_assert_str_eq(s1, s3);
} END_TEST

START_TEST(s21_strncpy_test_4) {
    char s1[] = "\0";
    char s2[] = "\0";
    char s3[] = "\0";
    char s4[] = "\0";
    s21_strncpy(s1, s2, 1);
    strncpy(s3, s4, 1);
    ck_assert_str_eq(s1, s3);
} END_TEST

START_TEST(s21_strncpy_test_5) {
    char s1[] = "H e l l o\0";
    char s2[] = "H E L L O\0";
    char s3[] = "H e l l o\0";
    char s4[] = "H E L L O\0";
    s21_strncpy(s1, s2, 5);
    strncpy(s3, s4, 5);
    ck_assert_str_eq(s1, s3);
} END_TEST

START_TEST(s21_strcspn_test_1) {
    char s1[] = "H e l l o\0";
    char s2[] = "lo\0";
    ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
} END_TEST

START_TEST(s21_strcspn_test_2) {
    char s1[] = "Hello\0";
    char s2[] = "HE\0";
    ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
} END_TEST

START_TEST(s21_strcspn_test_3) {
    char s1[] = "Hello\0";
    char s2[] = "\0";
    ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
} END_TEST

START_TEST(s21_strcspn_test_4) {
    char s1[] = "Hello\0";
    char s2[] = "Hello\0";
    ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
} END_TEST

START_TEST(s21_strcspn_test_5) {
    char s1[] = "Hello\0";
    char s2[] = "hELLO\0";
    ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
} END_TEST

START_TEST(s21_strpbrk_test_1) {
    char s1[] = "H e l l o\0";
    char s2[] = "lo\0";
    ck_assert_str_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
} END_TEST

START_TEST(s21_strpbrk_test_2) {
    char s1[] = "Hello\0";
    char s2[] = "HE\0";
    ck_assert_str_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
} END_TEST

START_TEST(s21_strpbrk_test_3) {
    char s1[] = "Hello\0";
    char s2[] = "\0";
    ck_assert_ptr_null(s21_strpbrk(s1, s2));
} END_TEST

START_TEST(s21_strpbrk_test_4) {
    char s1[] = "Hello\0";
    char s2[] = "Hello\0";
    ck_assert_str_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
} END_TEST

START_TEST(s21_strpbrk_test_5) {
    char s1[] = "Hello\0";
    char s2[] = "hELLO\0";
    ck_assert_ptr_null(s21_strpbrk(s1, s2));
} END_TEST

START_TEST(s21_strrchr_test_1) {
    char s[] = "H e l l o\0";
    int c = ' ';
    ck_assert_str_eq(s21_strrchr(s, c), strrchr(s, c));
} END_TEST

START_TEST(s21_strrchr_test_2) {
    char s[] = "Hello\0";
    int c = 'l';
    ck_assert_str_eq(s21_strrchr(s, c), strrchr(s, c));
} END_TEST

START_TEST(s21_strrchr_test_3) {
    char s[] = "Hello\0";
    int c = ' ';
    ck_assert_ptr_null(s21_strrchr(s, c));
} END_TEST

START_TEST(s21_strrchr_test_4) {
    char s[] = "Hello\n\0";
    int c = '\n';
    ck_assert_str_eq(s21_strrchr(s, c), strrchr(s, c));
} END_TEST

START_TEST(s21_strrchr_test_5) {
    char s[] = "Hello\0";
    int c = 'p';
    ck_assert_ptr_null(s21_strrchr(s, c));
} END_TEST

START_TEST(s21_strspn_test_1) {
    char s1[] = "H e l l o\0";
    char s2[] = "He ";
    ck_assert_int_eq(s21_strspn(s1, s2), strspn(s1, s2));
} END_TEST

START_TEST(s21_strspn_test_2) {
    char s1[] = "H el l o\0";
    char s2[] = "Hle ";
    ck_assert_int_eq(s21_strspn(s1, s2), strspn(s1, s2));
} END_TEST

START_TEST(s21_strspn_test_3) {
    char s1[] = "H e l l o\0";
    char s2[] = "";
    ck_assert_int_eq(s21_strspn(s1, s2), strspn(s1, s2));
} END_TEST

START_TEST(s21_strspn_test_4) {
    char s1[] = "H e l l o\0";
    char s2[] = "H el";
    ck_assert_int_eq(s21_strspn(s1, s2), strspn(s1, s2));
} END_TEST

START_TEST(s21_strspn_test_5) {
    char s1[] = "H e l l o\0";
    char s2[] = "  ";
    ck_assert_int_eq(s21_strspn(s1, s2), strspn(s1, s2));
} END_TEST

START_TEST(s21_strstr_test_1) {
    char s1[] = "H e l l o\0";
    char s2[] = "H e l\0";
    ck_assert_str_eq(s21_strstr(s1, s2), strstr(s1, s2));
} END_TEST

START_TEST(s21_strstr_test_2) {
    char s1[] = "Hello\0";
    char s2[] = "llo\0";
    ck_assert_str_eq(s21_strstr(s1, s2), strstr(s1, s2));
} END_TEST

START_TEST(s21_strstr_test_3) {
    char s1[] = "Hello\0";
    char s2[] = "ll\0";
    ck_assert_str_eq(s21_strstr(s1, s2), strstr(s1, s2));
} END_TEST

START_TEST(s21_strstr_test_4) {
    char s1[] = "H e l l o\0";
    char s2[] = "\0";
    ck_assert_str_eq(s21_strstr(s1, s2), strstr(s1, s2));
} END_TEST

START_TEST(s21_strstr_test_5) {
    char s1[] = "Hello\0";
    char s2[] = "Hello\0";
    ck_assert_str_eq(s21_strstr(s1, s2), strstr(s1, s2));
} END_TEST

START_TEST(s21_strtok_test_1) {
    char s1[] = "H e l l o\0";
    char s2[] = " ";
    char *r = s21_strtok(s1, s2);
    ck_assert_str_eq(r, strtok(s1, s2));
    free(r);
} END_TEST

START_TEST(s21_strtok_test_2) {
    char s1[] = "Hello\0";
    char s2[] = "l";
    char *r = s21_strtok(s1, s2);
    ck_assert_str_eq(r, strtok(s1, s2));
    free(r);
} END_TEST

START_TEST(s21_strtok_test_3) {
    char s1[] = "H.el.lo\0";
    char s2[] = ".\0";
    char *r = s21_strtok(s1, s2);
    ck_assert_str_eq(r, strtok(s1, s2));
    free(r);
} END_TEST

START_TEST(s21_strtok_test_4) {
    char s1[] = "abbabba\0";
    char s2[] = "bb\0";
    char *r = s21_strtok(s1, s2);
    ck_assert_str_eq(r, strtok(s1, s2));
    free(r);
} END_TEST

START_TEST(s21_strtok_test_5) {
    char s1[] = "Hello\0";
    char s2[] = "Hello\0";
    char *r = s21_strtok(s1, s2);
    ck_assert_ptr_null(r);
    free(r);
} END_TEST

START_TEST(s21_strerror_test_1) {
    char *e = s21_strerror(1);
    ck_assert_str_eq(e, strerror(1));
    free(e);
} END_TEST

START_TEST(s21_strerror_test_2) {
    char *e = s21_strerror(2);
    ck_assert_str_eq(e, strerror(2));
    free(e);
} END_TEST

START_TEST(s21_strerror_test_3) {
    char *e = s21_strerror(3);
    ck_assert_str_eq(e, strerror(3));
    free(e);
} END_TEST

START_TEST(s21_strerror_test_4) {
    char *e = s21_strerror(4);
    ck_assert_str_eq(e, strerror(4));
    free(e);
} END_TEST

START_TEST(s21_strerror_test_5) {
    char *e = s21_strerror(5);
    ck_assert_str_eq(e, strerror(5));
    free(e);
} END_TEST

START_TEST(s21_to_upper_1) {
    char *str = "HELLO world";
    char *a = s21_to_upper(str);
    ck_assert_str_eq(a, "HELLO WORLD");
    free(a);
}
END_TEST

START_TEST(s21_to_upper_2) {
    char *str = "12345";
    char *a = s21_to_upper(str);
    ck_assert_str_eq(a, "12345");
    free(a);
}
END_TEST

START_TEST(s21_to_upper_3) {
    char *str = "\n\0";
    char *a = s21_to_upper(str);
    ck_assert_str_eq(a, "\n\0");
    free(a);
}
END_TEST

START_TEST(s21_to_upper_4) {
    char *str = "AaAa";
    char *a = s21_to_upper(str);
    ck_assert_str_eq(a, "AAAA");
    free(a);
}
END_TEST

START_TEST(s21_to_lower_1) {
    char *str = "HELLO world";
    char *a = s21_to_lower(str);
    ck_assert_str_eq(a, "hello world");
    free(a);
}
END_TEST

START_TEST(s21_to_lower_2) {
    char *str = "12345";
    char *a = s21_to_lower(str);
    ck_assert_str_eq(a, "12345");
    free(a);
}
END_TEST

START_TEST(s21_to_lower_3) {
    char *str = "\n\0";
    char *a = s21_to_lower(str);
    ck_assert_str_eq(a, "\n\0");
    free(a);
}
END_TEST

START_TEST(s21_to_lower_4) {
    char *str = "aAaAaA";
    char *a = s21_to_lower(str);
    ck_assert_str_eq(a, "aaaaaa");
    free(a);
}
END_TEST


START_TEST(test_s_sprintf) {
    char str[100];
    char str2[100];

    ck_assert_int_eq(
        (int)s21_sprintf(str, "Hello %s", "medgarha"), (int)sprintf(str2, "Hello %s", "medgarha"));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello %-s", "medgarha"), sprintf(str2, "Hello %-s", "medgarha"));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello %-20s", "medgarha"), sprintf(str2, "Hello %-20s", "medgarha"));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello %-20.s", "medgarha"), sprintf(str2, "Hello %-20.s", "medgarha"));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello %-.s", "medgarha"), sprintf(str2, "Hello %-.s", "medgarha"));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello %.s", "medgarha"), sprintf(str2, "Hello %.s", "medgarha"));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello %-10.20s", "medgarha"), sprintf(str2, "Hello %-10.20s", "medgarha"));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello %-.20s", "medgarha"), sprintf(str2, "Hello %-.20s", "medgarha"));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello %21.20s", "medgarha"), sprintf(str2, "Hello %21.20s", "medgarha"));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello %21.20s and %-2.4s", "medgarha", "school"),
         sprintf(str2, "Hello %21.20s and %-2.4s", "medgarha", "school"));
} END_TEST

START_TEST(test_c_sprintf) {
    char str[100];
    char str2[100];

    ck_assert_int_eq(
        s21_sprintf(str, "Hello school %c %lc", '2', '&'), sprintf(str2, "Hello school %c %lc", '2', '&'));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello school %-c %c %%%%", '2', '1'),
         sprintf(str2, "Hello school %-c %c %%%%", '2', '1'));
    ck_assert_int_eq(
        s21_sprintf(str, "Hello school %20c %-10lc", '2', 0x61),
         sprintf(str2, "Hello school %20c %-10lc", '2', 0x61));
} END_TEST

START_TEST(test_d_sprintf) {
    char str[100];
    char str2[100];

    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %d ! = %d", +4, -1),
         sprintf(str2, "2 + 2 = %d ! = %d", +4, -1));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %-d ! = %+d", 4, 10),
         sprintf(str2, "2 + 2 = %-d ! = %+d", 4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % -d ! = %+-d", +4, 10),
         sprintf(str2, "2 + 2 = % -d ! = %+-d", +4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10d ! = %+-20d", -4, 10),
         sprintf(str2, "2 + 2 = % 10d ! = %+-20d", -4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10.d ! = %+-20.20d", 0, -182),
         sprintf(str2, "2 + 2 = % 10.d ! = %+-20.20d", 0, -182));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10.hd ! = %+-20.20ld", 4, 276892067102856),
         sprintf(str2, "2 + 2 = % 10.hd ! = %+-20.20ld", (short)4, 276892067102856));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10.hd ! = %+-20.20ld", 010, 0x1275623445),
         sprintf(str2, "2 + 2 = % 10.hd ! = %+-20.20ld", (short)010, 0x1275623445));
} END_TEST

START_TEST(test_i_sprintf) {
    char str[100];
    char str2[100];

    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %i ! = %i", 4, 10),
         sprintf(str2, "2 + 2 = %i ! = %i", 4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %-i ! = %+i", 4, 10),
         sprintf(str2, "2 + 2 = %-i ! = %+i", 4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % -i ! = %+-i", 4, -10),
         sprintf(str2, "2 + 2 = % -i ! = %+-i", 4, -10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10d ! = %+-20i", 4, 10),
         sprintf(str2, "2 + 2 = % 10i ! = %+-20i", 4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10.i ! = %+-20.20i", 4, -10),
         sprintf(str2, "2 + 2 = % 10.i ! = %+-20.20i", 4, -10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10.hi ! = %+-20.20li", -4, +276892067102856),
        sprintf(str2, "2 + 2 = % 10.hi ! = %+-20.20li", (short)-4, +276892067102856));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10.hi ! = %+-20.20li", 010, 0x1275623445),
         sprintf(str2, "2 + 2 = % 10.hi ! = %+-20.20li", (short)010, 0x1275623445));
} END_TEST

START_TEST(test_u_sprintf) {
    char str[100];
    char str2[100];

    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %d ! = %u", -4, 10),
        sprintf(str2, "2 + 2 = %d ! = %u", -4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %-d ! = %u", 4, 10),
        sprintf(str2, "2 + 2 = %-d ! = %u", 4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % -i ! = %-u", 4, 10),
        sprintf(str2, "2 + 2 = % -i ! = %-u", 4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10d ! = %-20u", 4, 10),
        sprintf(str2, "2 + 2 = % 10d ! = %-20u", 4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10.i ! = %-20.20u", 4, 10),
        sprintf(str2, "2 + 2 = % 10.i ! = %-20.20u", 4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %10.hu ! = %-20.20lu", 4, 276892067102856),
        sprintf(str2, "2 + 2 = %10.hu ! = %-20.20lu", (unsigned short)4, 276892067102856));
} END_TEST

START_TEST(test_f_sprintf) {
    char str[100];
    char str2[100];

    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %f ! = %f", -4.21, +42.21),
        sprintf(str2, "2 + 2 = %f ! = %f", -4.21, +42.21));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %-f ! = %+f", -4.21, +42.21),
        sprintf(str2, "2 + 2 = %-f ! = %+f", -4.21, +42.21));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %-10f ! = %+12f", -4.21, +42.21),
        sprintf(str2, "2 + 2 = %-10f ! = %+12f", -4.21, +42.21));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %- 10.f ! = %+12.5f", -4.21, +42.21),
        sprintf(str2, "2 + 2 = %- 10.f ! = %+12.5f", -4.21, +42.21));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %- 10.f ! = %+12.5lf", -4.21, +42.21),
        sprintf(str2, "2 + 2 = %- 10.f ! = %+12.5lf", -4.21, +42.21));
} END_TEST

START_TEST(test_o_sprintf) {
    char str[100];
    char str2[100];

    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %d ! = %o", -4, 10), sprintf(str2, "2 + 2 = %d ! = %o", -4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %-d ! = %-o", 4, 00210), sprintf(str2, "2 + 2 = %-d ! = %o", 4, 00210));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % -i ! = %-.10o", 4, 0), sprintf(str2, "2 + 2 = % -i ! = %-.10o", 4, 0));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10d ! = %-20.o", 4, 0), sprintf(str2, "2 + 2 = % 10d ! = %-20.o", 4, 0));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = % 10.i ! = %-20.20o", 0, 0x124),
         sprintf(str2, "2 + 2 = % 10.i ! = %-20.20o", 0, 0x124));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %10.ho ! = %-20.20lo", 4, 276892067102856),
        sprintf(str2, "2 + 2 = %10.ho ! = %-20.20lo", (unsigned short)4, 276892067102856));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %10.ho ! = %-20.20lo", 4, 0),
        sprintf(str2, "2 + 2 = %10.ho ! = %-20.20lo", (unsigned short)0, 276892067102856));
} END_TEST

START_TEST(test_x_and_X_sprintf) {
    char str[100];
    char str2[100];

    ck_assert_int_eq(s21_sprintf(str, "2 + 2 = %X ! = %x", 4, 10), sprintf(str2, "2 + 2 = %X ! = %x", 4, 10));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %-X ! = %-x", 4, 132445), sprintf(str2, "2 + 2 = %-X ! = %-x", 4, 132445));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %-X ! = %-.x", 4, 0), sprintf(str2, "2 + 2 = %-X ! = %-.x", 4, 0));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %10X ! = %-20.x", 4, 0), sprintf(str2, "2 + 2 = %10X ! = %-20.x", 4, 0));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %10.X ! = %04x", 0, 0x124),
         sprintf(str2, "2 + 2 = %10.X ! = %04x", 0, 0x124));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %10.hX ! = %-20.20lx", 5, 276892067102856),
         sprintf(str2, "2 + 2 = %10.hX ! = %-20.20lx", (unsigned short)5, 276892067102856));
    ck_assert_int_eq(
        s21_sprintf(str, "2 + 2 = %10.hX ! = %-20.lx", 21, 276892067102856),
         sprintf(str2, "2 + 2 = %10.hX ! = %-20.lx", (unsigned short)21, 276892067102856));
} END_TEST

START_TEST(test_p_sprintf) {
    char str[100];
    char str2[100];
    int digit = 1;
    char *f = "Hello";
    int *g = &digit;

    ck_assert_int_eq(s21_sprintf(str, "char p - %p, int p - %-p", f, &g),
    sprintf(str2, "char p - %p, int p - %-p", f, g));
    ck_assert_int_eq(s21_sprintf(str, "char p - %20p, int p - %-5p", f, g),
    sprintf(str2, "char p - %20p, int p - %-5p", f, g));
} END_TEST

START_TEST(test_e_and_E_sprintf) {
    char str[100];
    char str2[100];

    ck_assert_int_eq(s21_sprintf(str, "2 + 2 = %e ! = %E", -4.21, +42.21),
    sprintf(str2, "2 + 2 = %e ! = %E", -4.21, +42.21));
    ck_assert_int_eq(s21_sprintf(str, "2 + 2 = %-e ! = %+E", -2345729.2012657810, -2345729.2012657810),
    sprintf(str2, "2 + 2 = %-e ! = %+E", -2345729.2012657810, -2345729.2012657810));
    ck_assert_int_eq(s21_sprintf(str, "2 + 2 = %-10e ! = %+12E", 0000.0025672, 0000.0025672),
    sprintf(str2, "2 + 2 = %-10e ! = %+12E", 0000.0025672, 0000.0025672));
    ck_assert_int_eq(s21_sprintf(str, "2 + 2 = %- 10.e ! = %+12.5E", +0.00213434, +0.00213434),
    sprintf(str2, "2 + 2 = %- 10.e ! = %+12.5E", +0.00213434, +0.00213434));
    ck_assert_int_eq(s21_sprintf(str, "2 + 2 = %- 10.e ! = %+12.5lE", -25672.02123, +25672.02123),
    sprintf(str2, "2 + 2 = %- 10.e ! = %+12.5lE", -25672.02123, +25672.02123));
} END_TEST

START_TEST(test_g_and_G_sprintf) {
    char str[100];
    char str2[100];

    ck_assert_int_eq(s21_sprintf(str, "2 + 2 = %-g ! = %+G", -2345729.2012657810, -2345729.2012657810),
    sprintf(str2, "2 + 2 = %-e ! = %+E", -2345729.2012657810, -2345729.2012657810));
    ck_assert_int_eq(s21_sprintf(str, "2 + 2 = %-10g ! = %+12G", 0000.0025672, 0000.0025672),
    sprintf(str2, "2 + 2 = %-10g ! = %+12G", 0000.0025672, 0000.0025672));
    ck_assert_int_eq(s21_sprintf(str, "2 + 2 = %- 10.g ! = %+12.G", +0.00213434, +0.00213434),
    sprintf(str2, "2 + 2 = %- 10.g ! = %+12.G", +0.00213434, +0.00213434));
    ck_assert_int_eq(s21_sprintf(str, "2 + 2 = %- 10.g ! = %+12.lG", -25672.02123, +25672.02123),
    sprintf(str2, "2 + 2 = %- 10.g ! = %+12.lG", -25672.02123, +25672.02123));
} END_TEST

START_TEST(test_n_sprintf) {
    char str[100];
    char str2[100];
    int val, sval;
    sval = 10;

    ck_assert_int_eq(s21_sprintf(str, "What is n?%n is %n", &val, &sval),
    sprintf(str2,  "What is n?%n is %n", &val, &sval));
} END_TEST


START_TEST(s21_trim_1) {
    const char *s1 = "88Hello my world888\0";
    const char *s2 = "8";
    char *a = s21_trim(s1, s2);
    ck_assert_str_eq(a, "Hello my world");
    free(a);
} END_TEST

START_TEST(s21_trim_2) {
    const char *s1 = "11Hello world321";
    const char *s2 = "321";
    char *a = s21_trim(s1, s2);
    ck_assert_str_eq(a, "Hello world");
    free(a);
} END_TEST

START_TEST(s21_trim_3) {
    const char *s1 = "00g0000";
    const char *s2 = "0";
    char *a = s21_trim(s1, s2);
    ck_assert_str_eq(a, "g");
    free(a);
} END_TEST

START_TEST(s21_insert_1) {
    char s1[] = "Hello !";
    char s2[] = "world";
    char *a = s21_insert(s1, s2, 6);
    ck_assert_str_eq(a, "Hello world!");
    free(a);
} END_TEST

Suite *s21_string_suite(void) {
    Suite *s = suite_create("s21_string_test");

    TCase *tc_memchr;
    tc_memchr = tcase_create("s21_memchr_test");

    tcase_add_test(tc_memchr, s21_memchr_1);
    tcase_add_test(tc_memchr, s21_memchr_2);
    tcase_add_test(tc_memchr, s21_memchr_3);
    tcase_add_test(tc_memchr, s21_memchr_4);
    tcase_add_test(tc_memchr, s21_memchr_5);
    tcase_add_test(tc_memchr, s21_memchr_6);
    tcase_add_test(tc_memchr, s21_memchr_7);
    tcase_add_test(tc_memchr, s21_memchr_8);
    tcase_add_test(tc_memchr, s21_memchr_10);
    suite_add_tcase(s, tc_memchr);

    TCase *tc_memcmp;
    tc_memcmp = tcase_create("s21_memcmp_test");

    tcase_add_test(tc_memcmp, s21_memcmp_1);
    tcase_add_test(tc_memcmp, s21_memcmp_2);
    tcase_add_test(tc_memcmp, s21_memcmp_3);
    tcase_add_test(tc_memcmp, s21_memcmp_4);
    suite_add_tcase(s, tc_memcmp);

    TCase *tc_memcpy;
    tc_memcpy = tcase_create("s21_memcpy_test");

    tcase_add_test(tc_memcpy, s21_memcpy_1);
    tcase_add_test(tc_memcpy, s21_memcpy_2);
    tcase_add_test(tc_memcpy, s21_memcpy_3);
    tcase_add_test(tc_memcpy, s21_memcpy_4);
    suite_add_tcase(s, tc_memcpy);

    TCase *tc_memmove;
    tc_memmove = tcase_create("s21_memmove");

    tcase_add_test(tc_memcpy, s21_memmove_1);
    tcase_add_test(tc_memcpy, s21_memmove_2);
    tcase_add_test(tc_memcpy, s21_memmove_3);
    tcase_add_test(tc_memcpy, s21_memmove_4);
    tcase_add_test(tc_memcpy, s21_memmove_5);
    tcase_add_test(tc_memcpy, s21_memmove_6);
    tcase_add_test(tc_memcpy, s21_memmove_7);
    tcase_add_test(tc_memcpy, s21_memmove_8);
    tcase_add_test(tc_memcpy, s21_memmove_9);
    suite_add_tcase(s, tc_memmove);

    TCase *tc_memset;
    tc_memset = tcase_create("s21_memset");

    tcase_add_test(tc_memcpy, s21_memset_1);
    tcase_add_test(tc_memcpy, s21_memset_2);
    tcase_add_test(tc_memcpy, s21_memset_3);
    tcase_add_test(tc_memcpy, s21_memset_4);
    tcase_add_test(tc_memcpy, s21_memset_5);
    tcase_add_test(tc_memcpy, s21_memset_6);
    tcase_add_test(tc_memcpy, s21_memset_7);
    tcase_add_test(tc_memcpy, s21_memset_8);
    suite_add_tcase(s, tc_memset);

    TCase *tc_strcat;
    tc_strcat = tcase_create("s21_strcat_test");

    tcase_add_test(tc_strcat, s21_strcat_1);
    tcase_add_test(tc_strcat, s21_strcat_2);
    tcase_add_test(tc_strcat, s21_strcat_3);
    tcase_add_test(tc_strcat, s21_strcat_4);
    suite_add_tcase(s, tc_strcat);

    TCase *tc_strncat;
    tc_strncat = tcase_create("s21_strncat_test");

    tcase_add_test(tc_strncat, s21_strncat_1);
    tcase_add_test(tc_strncat, s21_strncat_2);
    tcase_add_test(tc_strncat, s21_strncat_3);
    tcase_add_test(tc_strncat, s21_strncat_4);
    suite_add_tcase(s, tc_strncat);

    TCase *tc_strchr;
    tc_strchr = tcase_create("s21_strchr_test");

    tcase_add_test(tc_strchr, s21_strchr_1);
    tcase_add_test(tc_strchr, s21_strchr_2);
    tcase_add_test(tc_strchr, s21_strchr_3);
    tcase_add_test(tc_strchr, s21_strchr_4);
    tcase_add_test(tc_strchr, s21_strchr_5);
    tcase_add_test(tc_strchr, s21_strchr_6);
    suite_add_tcase(s, tc_strchr);

    TCase *tc_strcmp;
    tc_strcmp = tcase_create("s21_strcmp_test");

    tcase_add_test(tc_strcmp, s21_strcmp_1);
    tcase_add_test(tc_strcmp, s21_strcmp_2);
    tcase_add_test(tc_strcmp, s21_strcmp_3);
    tcase_add_test(tc_strcmp, s21_strcmp_4);
    suite_add_tcase(s, tc_strcmp);

    TCase *tc_strncmp;
    tc_strncmp = tcase_create("s21_strncmp_test");

    tcase_add_test(tc_strncmp, s21_strncmp_1);
    tcase_add_test(tc_strncmp, s21_strncmp_2);
    tcase_add_test(tc_strncmp, s21_strncmp_3);
    tcase_add_test(tc_strncmp, s21_strncmp_4);
    suite_add_tcase(s, tc_strncmp);

    TCase *tc_strcpy = tcase_create("s21_strcpy_test");

    tcase_add_test(tc_strcpy, s21_strcpy_test_1);
    tcase_add_test(tc_strcpy, s21_strcpy_test_2);
    tcase_add_test(tc_strcpy, s21_strcpy_test_3);
    tcase_add_test(tc_strcpy, s21_strcpy_test_4);
    tcase_add_test(tc_strcpy, s21_strcpy_test_5);
    suite_add_tcase(s, tc_strcpy);

    TCase *tc_strncpy = tcase_create("s21_strncpy_test");

    tcase_add_test(tc_strncpy, s21_strncpy_test_1);
    tcase_add_test(tc_strncpy, s21_strncpy_test_2);
    tcase_add_test(tc_strncpy, s21_strncpy_test_3);
    tcase_add_test(tc_strncpy, s21_strncpy_test_4);
    tcase_add_test(tc_strncpy, s21_strncpy_test_5);
    suite_add_tcase(s, tc_strncpy);

    TCase *tc_strcspn = tcase_create("s21_strcspn_test");

    tcase_add_test(tc_strcspn, s21_strcspn_test_1);
    tcase_add_test(tc_strcspn, s21_strcspn_test_2);
    tcase_add_test(tc_strcspn, s21_strcspn_test_3);
    tcase_add_test(tc_strcspn, s21_strcspn_test_4);
    tcase_add_test(tc_strcspn, s21_strcspn_test_5);
    suite_add_tcase(s, tc_strcspn);

    TCase *tc_strlen = tcase_create("s21_strlen_test");

    tcase_add_test(tc_strlen, s21_strlen_test_1);
    tcase_add_test(tc_strlen, s21_strlen_test_2);
    tcase_add_test(tc_strlen, s21_strlen_test_3);
    tcase_add_test(tc_strlen, s21_strlen_test_4);
    tcase_add_test(tc_strlen, s21_strlen_test_5);
    tcase_add_test(tc_strlen, s21_strlen_test_6);
    tcase_add_test(tc_strlen, s21_strlen_test_7);
    suite_add_tcase(s, tc_strlen);

    TCase *tc_strpbrk = tcase_create("s21_strpbrk_test");

    tcase_add_test(tc_strpbrk, s21_strpbrk_test_1);
    tcase_add_test(tc_strpbrk, s21_strpbrk_test_2);
    tcase_add_test(tc_strpbrk, s21_strpbrk_test_3);
    tcase_add_test(tc_strpbrk, s21_strpbrk_test_4);
    tcase_add_test(tc_strpbrk, s21_strpbrk_test_5);
    suite_add_tcase(s, tc_strpbrk);

    TCase *tc_strrchr = tcase_create("s21_strrchr_test");

    tcase_add_test(tc_strrchr, s21_strrchr_test_1);
    tcase_add_test(tc_strrchr, s21_strrchr_test_2);
    tcase_add_test(tc_strrchr, s21_strrchr_test_3);
    tcase_add_test(tc_strrchr, s21_strrchr_test_4);
    tcase_add_test(tc_strrchr, s21_strrchr_test_5);
    suite_add_tcase(s, tc_strrchr);

    TCase *tc_strspn = tcase_create("s21_strspn_test");

    tcase_add_test(tc_strspn, s21_strspn_test_1);
    tcase_add_test(tc_strspn, s21_strspn_test_2);
    tcase_add_test(tc_strspn, s21_strspn_test_3);
    tcase_add_test(tc_strspn, s21_strspn_test_4);
    tcase_add_test(tc_strspn, s21_strspn_test_5);
    suite_add_tcase(s, tc_strspn);

    TCase *tc_strstr = tcase_create("s21_strstr_test");

    tcase_add_test(tc_strstr, s21_strstr_test_1);
    tcase_add_test(tc_strstr, s21_strstr_test_2);
    tcase_add_test(tc_strstr, s21_strstr_test_3);
    tcase_add_test(tc_strstr, s21_strstr_test_4);
    tcase_add_test(tc_strstr, s21_strstr_test_5);
    suite_add_tcase(s, tc_strstr);

    TCase *tc_strtok = tcase_create("s21_strtok_test");

    tcase_add_test(tc_strtok, s21_strtok_test_1);
    tcase_add_test(tc_strtok, s21_strtok_test_2);
    tcase_add_test(tc_strtok, s21_strtok_test_3);
    tcase_add_test(tc_strtok, s21_strtok_test_4);
    tcase_add_test(tc_strtok, s21_strtok_test_5);
    suite_add_tcase(s, tc_strtok);

    TCase *tc_strerror = tcase_create("s21_strerror_test");

    tcase_add_test(tc_strerror, s21_strerror_test_1);
    tcase_add_test(tc_strerror, s21_strerror_test_2);
    tcase_add_test(tc_strerror, s21_strerror_test_3);
    tcase_add_test(tc_strerror, s21_strerror_test_4);
    tcase_add_test(tc_strerror, s21_strerror_test_5);
    suite_add_tcase(s, tc_strerror);

    TCase *tcase_stroke_sprintf = tcase_create("Stroke test");
    TCase *tcase_char_sprintf = tcase_create("Char test");
    TCase *tcase_decimal_sprintf = tcase_create("Decimal/integer/unsigned test");

    tcase_add_test(tcase_stroke_sprintf, test_s_sprintf);
    tcase_add_test(tcase_char_sprintf, test_c_sprintf);
    tcase_add_test(tcase_decimal_sprintf, test_d_sprintf);
    tcase_add_test(tcase_decimal_sprintf, test_i_sprintf);
    tcase_add_test(tcase_decimal_sprintf, test_u_sprintf);
    tcase_add_test(tcase_decimal_sprintf, test_f_sprintf);
    tcase_add_test(tcase_decimal_sprintf, test_o_sprintf);
    tcase_add_test(tcase_decimal_sprintf, test_x_and_X_sprintf);
    tcase_add_test(tcase_decimal_sprintf, test_p_sprintf);
    tcase_add_test(tcase_decimal_sprintf, test_e_and_E_sprintf);
    tcase_add_test(tcase_decimal_sprintf, test_g_and_G_sprintf);
    tcase_add_test(tcase_decimal_sprintf, test_n_sprintf);

    suite_add_tcase(s, tcase_stroke_sprintf);
    suite_add_tcase(s, tcase_char_sprintf);
    suite_add_tcase(s, tcase_decimal_sprintf);

    TCase *tc_to_upper;
    tc_to_upper = tcase_create("s21_to_upper");

    tcase_add_test(tc_to_upper, s21_to_upper_1);
    tcase_add_test(tc_to_upper, s21_to_upper_2);
    tcase_add_test(tc_to_upper, s21_to_upper_3);
    tcase_add_test(tc_to_upper, s21_to_upper_4);
    suite_add_tcase(s, tc_to_upper);

    TCase *tc_to_lower;
    tc_to_lower = tcase_create("s21_to_lower");

    tcase_add_test(tc_to_lower, s21_to_lower_1);
    tcase_add_test(tc_to_lower, s21_to_lower_2);
    tcase_add_test(tc_to_lower, s21_to_lower_3);
    tcase_add_test(tc_to_lower, s21_to_lower_4);
    suite_add_tcase(s, tc_to_lower);

    TCase *tc_trim;
    tc_trim = tcase_create("s21_trim");

    tcase_add_test(tc_trim, s21_trim_1);
    tcase_add_test(tc_trim, s21_trim_2);
    tcase_add_test(tc_trim, s21_trim_3);
    suite_add_tcase(s, tc_trim);

    TCase *tc_insert;
    tc_insert = tcase_create("s21_insert");

    tcase_add_test(tc_insert, s21_insert_1);
    suite_add_tcase(s, tc_insert);


    return s;
}


int main(void) {
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = s21_string_suite();
    runner = srunner_create(s);

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return(no_failed == 0) ? 0 : -1;
}
