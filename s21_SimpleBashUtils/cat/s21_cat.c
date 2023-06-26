// copyright 2022 goblinar
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

struct cat_flag {
    int b_flag;
    int e_flag;
    int n_flag;
    int s_flag;
    int t_flag;
    int v_flag;
} flag;

const struct option long_options[] = {
    {"number-nonblank", no_argument, NULL, 'b'},
    {"number", no_argument, NULL, 'n'},
    {"squeeze-blank", no_argument, NULL, 's'},
};

void s21_cat(char* argv[]);
int find_flag(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    int error = 0;
    int amount_flag = 0;

    for (int i = 0; i < argc; i++) {
        error = find_flag(argc, argv);
        if (error == -1) {
            continue;
        } else if (error == '?') {
            exit(0);
        } else {
            amount_flag++;
        }
    }
    for (int i = 1 + amount_flag; i < argc; i++) {
        s21_cat(&argv[i]);
    }
    return 0;
}

int find_flag(int argc, char *argv[]) {
    int flag_t;
    int option_index = 0;
    flag_t = getopt_long(argc, argv, "benstET", long_options, &option_index);
    if (flag_t != -1) {
        switch (flag_t) {
            case 'e':
                flag.e_flag = 1;
                flag.v_flag = 1;
                break;
            case 'b':
                flag.b_flag = 1;
                break;
            case 'n':
                flag.n_flag = 1;
                break;
            case 's':
                flag.s_flag = 1;
                break;
            case 't':
                flag.t_flag = 1;
                flag.v_flag = 1;
                break;
            case 'T':
                flag.t_flag = 1;
                break;
            case 'E':
                flag.e_flag = 1;
                break;
            case '?':
                break;
        }
    }
    return flag_t;
}

void s21_cat(char* argv[]) {
    FILE *file = NULL;
    file = fopen(*argv, "r");

    if (file == NULL) {
        fprintf(stderr, "s21_cat: %s: No such file or directory\n", *argv);
    } else {
        int count_line = 1;
        int empty_lines = -1;
        char read_char = '\0';
        char last = '\n';
        while ((read_char = fgetc(file)) != EOF) {
            if (flag.s_flag == 1 && read_char == '\n') {
                if (empty_lines >= 1) {
                    continue;
                }
                empty_lines++;
            } else {
                empty_lines = -1;
            }
            if ((flag.b_flag != 1 && flag.n_flag == 1 && last == '\n') ||
                (flag.b_flag == 1 && read_char != '\n' && last == '\n')) {
                fprintf(stdout, "%6d\t", count_line++);
            }
            if (flag.v_flag == 1 && read_char != '\t' && read_char != '\n') {
                if (read_char >= 32 && read_char <= 126) {
                    fprintf(stdout, "%c", read_char);
                    continue;
                } else {
                    fprintf(stdout, "^%c", read_char + 64);
                    continue;
                }
            }
            if (flag.e_flag == 1 && read_char == '\n') {
                fprintf(stdout, "%c", '$');
            }
            if (flag.t_flag == 1 && read_char == '\t') {
                fprintf(stdout, "^I");
                continue;
            }
            fprintf(stdout, "%c", read_char);
            last = read_char;
        }
    }
    fclose(file);
}
