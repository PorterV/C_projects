#include "s21_string.h"

static const double rounders[MAX_PRECISION + 1] = {
    0.5,                // 0
    0.05,               // 1
    0.005,              // 2
    0.0005,             // 3
    0.00005,            // 4
    0.000005,           // 5
    0.0000005,          // 6
    0.00000005,         // 7
    0.000000005,        // 8
    0.0000000005,       // 9
    0.00000000005       // 10
};

char* s21_ftoa(double f, char* buf, int precision) {
    char * ptr = buf;
    char * p = ptr;
    char * p1;
    char c;
    long intPart;

    if (precision > MAX_PRECISION)
        precision = MAX_PRECISION;

    if (f < 0) {
        f = -f;
        *ptr++ = '-';
    }

/*    if (precision < 0) {
        if (f < 1.0) precision = 6;
        else if (f < 10.0) precision = 5;
        else if (f < 100.0) precision = 4;
        else if (f < 1000.0) precision = 3;
        else if (f < 10000.0) precision = 2;
        else if (f < 100000.0) precision = 1;
        else
        precision = 0;
    }
*/
    // round value according the precision
    if (precision)
        f += rounders[precision];
    // integer part...
    intPart = f;
    f -= intPart;

    if (!intPart) {
        *ptr++ = '0';
    } else {
        p = ptr;
        while (intPart) {
        *p++ = '0' + intPart % 10;
            intPart /= 10;
        }
        p1 = p;
        while (p > ptr) {
            c = *--p;
            *p = *ptr;
            *ptr++ = c;
        }
        ptr = p1;
    }
    if (precision) {
        *ptr++ = '.';
        while (precision--) {
            f *= 10.0;
            c = f;
            *ptr++ = '0' + c;
            f -= c;
        }
    }
    *ptr = 0;
    return buf;
}

char* s21_exponent(double value, char *buf, int percision) {
    int exponent;

    exponent = s21_exp(value);
    if (exponent < 0)
        exponent--;
    if (exponent > 0) {
        for (int i = 0; i < exponent; i++)
            value /= 10;
    } else if (exponent < 0) {
        for (int i = 0; i > exponent; i--)
            value *= 10;
    }
    buf = s21_ftoa(value, buf, percision);
    return buf;
}

int s21_exp(double value) {
    return (int)log10(fabs(value));
}
