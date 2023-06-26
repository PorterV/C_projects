#include "s21_string.h"

char* s21_itoa(long int value, char* buffer, int base, int unint) {
    if (unint == 1 && value < 0) {
        return buffer;
    }
    if (base < 2 || base > 32) {
        return buffer;
    }
    long int n = s21_abs(value);
    int i = 0;
    while (n) {
        long int r = n % base;
        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        } else {
            buffer[i++] = 48 + r;
        }
        n = n / base;
    }
    if (i == 0) {
        buffer[i++] = '0';
    }
    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }
    buffer[i] = '\0';
    return s21_reverse(buffer, 0, i - 1);
}
