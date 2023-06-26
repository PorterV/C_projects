CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: s21_cat

s21_cat:
	$(CC) $(CFLAGS) s21_cat.c -o s21_cat

test: s21_cat
	./test.sh

clean: 
	rm -rf s21_cat
	rm -rf s21_cat_test
	rm -rf cat