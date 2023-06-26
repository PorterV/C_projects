CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: s21_grep

s21_cat:
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep

test: s21_grep
	./test.sh

clean: 
	rm -rf s21_grep
	rm -rf s21_grep_test
	rm -rf grep