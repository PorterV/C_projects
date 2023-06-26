CC = gcc
CFLAGC = -Wall -Werror -Wextra -c -g -std=c11
LDFLAGS := -lcheck -fprofile-arcs
SOURCES := s21_string.c s21_ftoi.c s21_itoa.c s21_lib.c s21_string_tests.c
GCOVFLAGS := --coverage
OBJECTS := $(SOURCES:.c=.o)

all: test s21_string.a gcov_report

.c.o: 
	$(CC) $(CFLAGC) $< -o $@

s21_string.a: $(SOURCES)
	$(CC) $(CFLAGC) s21_string.c s21_ftoi.c s21_itoa.c s21_lib.c
	ar rcs s21_string.a s21_string.o s21_ftoi.o s21_itoa.o s21_lib.o
	ranlib s21_string.a

test: 
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_string.c -o s21_string.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_ftoi.c -o s21_ftoi.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_itoa.c -o s21_itoa.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_lib.c -o s21_lib.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_string_tests.c -o s21_string_tests.o
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	./$@

gcov_report:
	gcovr --html-details report.html

style:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h

leaks:
	leaks -atExit -- ./test

rebuild: clean all

clean:
	rm -rf *.o test s21_string.a
	rm -rf *.c.gcov
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.css
	rm -rf *.functions.html
	rm -rf *.html