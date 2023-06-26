CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -c -std=c11
LDFLAGS := -lcheck -fprofile-arcs
SOURCES := s21_math.c s21_math_test.c
GCOVFLAGS := --coverage
OBJECTS := $(SOURCES:.c=.o)

all: s21_math.a test gcov_report

.c.o:
	$(CC) $(CFLAGS) $< -o $@

s21_math.a: $(SOURCES)
	$(CC) $(CFLAGS) s21_math.c
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a

test:
	$(CC) $(CFLAGS) $(GCOVFLAGS) s21_math.c -o s21_math.o
	$(CC) $(CFLAGS) $(GCOVFLAGS) s21_math_test.c -o s21_math_test.o
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	./$@

gcov_report:
	gcovr --html-details report.html

clean:
	rm -rf *.o test s21_math.a
	rm -rf *.c.gcov
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.css
	rm -rf *.functions.html
	rm -rf *.html
