#include "s21_math.h"

int s21_abs(int x) {
    return x < 0 ? x * -1 : x;
}

long double s21_fabs(double x) {
    long double fabs = x;
    return fabs >= 0 ? fabs : -fabs;
}

long double s21_sqrt(double x) {
    long double sqrt = x / 2;
    long double mid = 0;

    if (x == S21_NAN) {
        sqrt = S21_NAN;
    } else if (x == 0) {
        sqrt = 0;
    } else if (x == 1) {
        sqrt = 1;
    } else if (x < 0) {
        sqrt = S21_NAN;
    } else {
        while (sqrt != mid) {
            mid = sqrt;
            sqrt = (x / mid + mid) / 2;
        }
    }
    return sqrt;
}

long double s21_fmod(double x, double y) {
    long double fmod = 0.;
    if (x == S21_INF || y == 0) {
        fmod = S21_NAN;
    } else if (y == S21_INF || y == -S21_INF) {
        fmod = (int)x;
    } else {
        long double xl = x;
        long double yl = y;
        long long t_fmod = xl / yl;
        xl = xl - t_fmod * yl;
        fmod = xl;
    }
    return fmod;
}

long double s21_floor(double x) {
    long double floor = x;

    if (x == S21_INF) {
        floor = S21_INF;
    } else if (x == -S21_INF) {
        floor = -S21_INF;
    } else if (x == S21_NAN) {
        floor = S21_NAN;
    } else {
        if (floor >= 0) {
        floor = floor - s21_fmod(x, 1);
        } else if (s21_fabs(s21_fmod(x, 1)) > S21_EPS) {
            floor = floor - 1;
            floor = floor - s21_fmod(x, 1);
        }
    }
    return floor;
}

long double s21_exp(double x) {
    long double n = 0.0;
    long double tailor = 1.0;
    int min = 0;

    if (x < 0) {
        min = 1;
        x = x * (-1.0l);
    }

    if (x == S21_NAN) {
        n = S21_NAN;
    } else if (x == S21_INF) {
        n = S21_INF;
    } else if (x == -S21_INF) {
        n = 0;
    } else {
        for (int i = 1; s21_fabs(tailor) > S21_EPS; i++) {
            n = n + tailor;
            tailor = (tailor * x) / i;
        }
    }
    if (min == 1) {
        n = 1 / n;
    }
    return n;
}

long double s21_pow(double base, double exp) {
    long double z = 0.;
    int is_negative = 0;
    double exp_negative = 1.;
    if (base == S21_INF || base == S21_NAN) {
        z = 0;
    } else if (exp == S21_INF || exp == S21_NAN) {
        z = S21_NAN;
    } else if (exp == 0) {
        z = 1;
    } else if (base == 0) {
        z = 0;
    } else if (base == 1) {
        z = 1;
    } else if (base == -1) {
        z = -1;
    } else {
        if (base < 0) {
            base = s21_fabs(base);
            if ((int)exp % 2 != 0) {
                is_negative = 1;
            }
        }
        if (exp < 0) {
            exp_negative = exp;
            exp = s21_fabs(exp);
        }
        while (base < 1. / S21_E || base > S21_E || s21_fabs(exp) > S21_EPS) {
            if (base < 1. / S21_E) {
                base *= S21_E;
                z -= exp;
            } else if (base > S21_E) {
                base /= S21_E;
                z += exp;
            } else {
                base *= base;
                exp /= 2.;
            }
        }
        if (exp_negative < 0) {
            z = 1 / s21_exp(z);
        } else {
            z = s21_exp(z);
        }
    }
    if (is_negative)
        z *= -1;
    return z;
}

long double s21_sin(double x) {
    long double row = 0;
    if (x == S21_NAN) {
        row = S21_NAN;
    } else if (s21_fabs(x) > S21_PI) {
        x = s21_fmod(x, 2. * S21_PI);
        if (x > S21_PI)
            x -= 2. * S21_PI;
        else if (x < -S21_PI)
            x += 2. * S21_PI;
    } else {
        long double n = 1.;
        long double a = x;

        while (s21_fabs(a) > S21_EPS) {
            row += a;
            a = ((-a) * x * x) / ((n + 1.) * (n + 2.));
            n += 2.;
        }
    }
    return row;
}

long double s21_cos(double x) {
    double pow = 0.;
    long double cos = 1.;
    long double tail = 1.;
    long double xl = s21_fmod(x, 2.0 * S21_PI);

    if (x == S21_NAN || s21_fabs(x) == S21_INF) {
        cos = S21_NAN;
    } else {
        while (s21_fabs(tail / cos) > S21_EPS) {
            pow = pow + 2.;
            tail = (-tail * xl * xl) / ((pow - 1) * (pow));
            cos += tail;
        }
    }
    return cos;
}

long double s21_tan(double x) {
    return s21_sin(x) / s21_cos(x);
}

long double s21_asin(double x) {
    int pow = 0;
    long double asin = x;
    long double tail = x;

    if (x == 1.0) {
        asin = S21_PI / 2;
    } else if (x == -1.0) {
        asin = -S21_PI / 2;
    } else if (x > 1.0 || x < -1.0) {
        asin = S21_NAN;
    } else {
        while (s21_fabs(tail) > S21_EPS) {
            pow++;
            tail = (tail * x * x * s21_pow((2 * pow - 1), 2)) / ((2 * pow + 1) * (2 * pow));
            asin += tail;
        }
    }
    return asin;
}

long double s21_acos(double x) {
    return S21_PI / 2 - s21_asin(x);
}

long double s21_atan(double x) {
    long double atan;
    if (x >= 1.0) {
        atan = 1.0;
        if (x == 1.0)
            atan = 0;
    } else if (x <= -1.0) {
        atan = -1;
        if (x == -1.0)
            atan = 0;
    } else {
        atan = s21_asin(x / s21_sqrt(1 + s21_pow(x, 2)));
    }
    return atan;
}

long double s21_log(double x) {
    long double log;
    if (x < 0) {
        log = S21_NAN;
    } else if (x == 0) {
        log = -S21_INF;
    } else if (x == S21_INF) {
        log = S21_INF;
    } else {
        int exp = 0;
        int tr = x < 1.0l;
        if (tr) {
            x = 1.0l / x;
        }
        while (x > S21_E) {
            x = x / S21_E;
            exp++;
        }
        long double temp = x - 1.0;
        long double term = 0.0;

        while (s21_fabs(term - temp) > S21_EPS) {
            term = temp;
            temp = term + ((2 * (x - s21_exp(term))) / (x + s21_exp(term)));
        }

        if (tr != 1.0) {
            log = temp + exp;
        } else {
            log = (temp + exp) * -1;
        }
    }
    return log;
}

long double s21_ceil(double x) {
    if (x == S21_INF) {
        x = S21_INF;
    } else if (x == -S21_INF) {
        x = -S21_INF;
    } else if (x == S21_NAN) {
        x = S21_NAN;
    } else if (s21_fabs(s21_fmod(x, 1)) > 0) {
        if (x > 0.0) {
            x = (long int)(x + 1.0);
        } else {
            x = (long int)x;
        }
    }
    return x;
}
