CC = gcc
CFLAGC = -Wall -Werror -Wextra -c -g -std=c11
LDFLAGS := -lcheck -fprofile-arcs
SOURCES := s21_arithmetic.c s21_compare.c s21_float.c s21_help.c s21_int.c s21_another.c s21_sup_arithmetic.c s21_help_sup_decimal.c s21_sup_compare.c
GCOVFLAGS := --coverage
OBJECTS := $(SOURCES:.c=.o)

all: test s21_decimal.a gcov_report

.c.o: 
	$(CC) $(CFLAGC) $< -o $@

s21_decimal.a: $(SOURCES)
	$(CC) $(CFLAGC) s21_sup_arithmetic.c s21_help_sup_decimal.c s21_sup_compare.c s21_arithmetic.c s21_compare.c s21_float.c s21_help.c s21_int.c s21_another.c
	ar rcs s21_decimal.a s21_arithmetic.o s21_compare.o s21_float.o s21_help.o s21_int.o s21_another.o s21_sup_arithmetic.o s21_sup_compare.o s21_help_sup_decimal.o
	ranlib s21_decimal.a
	
test: 
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_arithmetic.c -o s21_arithmetic.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_sup_arithmetic.c -o s21_sup_arithmetic.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_compare.c -o s21_compare.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_sup_compare.c -o s21_sup_compare.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_float.c -o s21_float.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_help.c -o s21_help.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_help_sup_decimal.c -o s21_help_sup_decimal.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_int.c -o s21_int.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_another.c -o s21_another.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_decimal_test.c -o s21_decimal_test.o
	$(CC) $(LDFLAGS) $(OBJECTS) s21_decimal_test.o -o $@
	./$@

gcov_report:
	gcovr --html-details report.html

style:
	cp ../materials/build/scripts/.clang-format .
	clang-format -n *.c *.h

leaks:
	leaks -atExit -- ./test

check:
	cppcheck *.c

rebuild: clean all

clean:
	rm -rf *.o test s21_decimal.a
	rm -rf *.c.gcov
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.css
	rm -rf *.functions.html
	rm -rf *.html
	rm -rf *.gcov