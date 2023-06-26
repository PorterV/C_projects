// copyright 2022 goblinar
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <regex.h>
#include <limits.h>
#include <string.h>

struct grep_flag {
    int e_flag;
    int i_flag;
    int v_flag;
    int c_flag;
    int l_flag;
    int n_flag;
    int h_flag;
    int s_flag;
    int f_flag;
    int o_flag;
} flag;

int find_flag(int argc, char *argv[]);
void output_string(int amount_str, char* string, char* argv[], int amount_file);
void s21_grep(char* argv[], char* pattern[], int count_file);

int main(int argc, char *argv[]) {
    int error = 0;
    int amount_flag = 0;

    for (int i = 1; i < argc; i++) {
        error = find_flag(argc, argv);
        if (error == -1) {
            break;
        } else if (error == '?') {
            exit(0);
        }
    }

    int c = '-';
    for (int i = 1; i < argc; i++) {
        if (strchr(argv[i], c) != NULL) {
            amount_flag++;
        }
    }

    if (flag.f_flag != 1) {
        for (int print = amount_flag + 2; print < argc; print++) {
            s21_grep(&argv[print], &argv[amount_flag + 1], (argc - amount_flag - 2));
        }
    } else {
        FILE *file_pattern = NULL;
        char string_pattern[1024];
        file_pattern = fopen(argv[amount_flag + 1], "r");
        if (file_pattern != NULL) {
            for (int print = amount_flag + 2; print < argc; print++) {
                while (fgets(string_pattern, 1024, file_pattern) != NULL) {
                    char* pattern = string_pattern;
                    s21_grep(&argv[print], &pattern, (argc - amount_flag - 2));
                }
            }
        }
        fclose(file_pattern);
    }

    return 0;
}

int find_flag(int argc, char *argv[]) {
    int flag_t;
    flag_t = getopt(argc, argv, "eivclnhsfo");
    if (flag_t != -1) {
        switch (flag_t) {
            case 'e':
                flag.e_flag = 1;
                break;
            case 'i':
                flag.i_flag = 1;
                break;
            case 'v':
                flag.v_flag = 1;
                break;
            case 'c':
                flag.c_flag = 1;
                break;
            case 'l':
                flag.l_flag = 1;
                break;
            case 'n':
                flag.n_flag = 1;
                break;
            case 'h':
                flag.h_flag = 1;
                break;
            case 's':
                flag.s_flag = 1;
                break;
            case 'f':
                flag.f_flag = 1;
                break;
            case 'o':
                flag.o_flag = 1;
                break;
            case '?':
                break;
        }
    }
    return flag_t;
}

void s21_grep(char* argv[], char* pattern[], int count_file) {
    FILE *file = NULL;
    char string[LINE_MAX];

    int amount_str = 0;
    int same_str = 0;

    regex_t preg;
    regmatch_t pmatch[1];

    file = fopen(*argv, "r");

    if (file == NULL) {
        if (flag.s_flag != 1) {
            fprintf(stderr, "s21_grep: %s: No such file or directory\n", *argv);
        }
    } else {
        if (flag.i_flag == 1) {
            regcomp(&preg, *pattern, REG_ICASE);
        } else {
            regcomp(&preg, *pattern, 0);
        }
        while (fgets(string, LINE_MAX, file) != NULL) {
            if (flag.n_flag == 1) {
                amount_str++;
            }
            if (flag.c_flag == 1 || flag.l_flag == 1 || flag.o_flag == 1) {
                if (flag.v_flag == 1) {
                    if (regexec(&preg, string, 1, pmatch, 0) != 0) {
                        same_str++;
                    }
                } else {
                    if (regexec(&preg, string, 1, pmatch, 0) == 0) {
                        same_str++;
                    }
                }
            } else {
                if (flag.v_flag == 1) {
                    if (regexec(&preg, string, 1, pmatch, 0) != 0) {
                        output_string(amount_str, string, argv, count_file);
                    }
                } else {
                    if (regexec(&preg, string, 1, pmatch, 0) == 0) {
                        output_string(amount_str, string, argv, count_file);
                    }
                }
            }
        }
        if ((flag.c_flag == 1 && flag.l_flag != 1) || flag.o_flag == 1) {
            if (count_file > 1) {
                if (flag.c_flag == 1) {
                    if (flag.h_flag == 1) {
                        fprintf(stdout, "%d\n", same_str);
                    } else {
                        fprintf(stdout, "%s:%d\n", *argv, same_str);
                    }
                } else if (flag.o_flag == 1) {
                    while (same_str != 0) {
                        if (flag.h_flag == 1) {
                            fprintf(stdout, "%s\n", *pattern);
                            same_str--;
                        } else {
                            fprintf(stdout, "%s:%s\n", *argv, *pattern);
                            same_str--;
                        }
                    }
                }
            } else {
                if (flag.c_flag == 1) {
                    fprintf(stdout, "%d\n", same_str);
                } else if (flag.o_flag == 1) {
                    while (same_str != 0) {
                        fprintf(stdout, "%s\n", *pattern);
                        same_str--;
                    }
                }
            }
        } else if (flag.l_flag == 1 && same_str > 0) {
            fprintf(stdout, "%s\n", *argv);
        }
    }
    regfree(&preg);
    fclose(file);
}

void output_string(int amount_str, char* string,
                   char* argv[], int amount_file) {
    if (amount_file > 1) {
        if (flag.n_flag == 1) {
            if (flag.h_flag == 1) {
                fprintf(stdout, "%d:%s", amount_str, string);
            } else {
                fprintf(stdout, "%s:%d:%s", *argv, amount_str, string);
            }
        } else {
            if (flag.h_flag == 1) {
                fprintf(stdout, "%s", string);
            } else {
                fprintf(stdout, "%s:%s", *argv, string);
            }
        }
    } else {
        if (flag.n_flag == 1) {
            fprintf(stdout, "%d:%s", amount_str, string);
        } else {
            fprintf(stdout, "%s", string);
        }
    }
}
