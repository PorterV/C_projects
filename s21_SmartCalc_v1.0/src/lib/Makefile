CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRC = lib/calculate.c \
		lib/polish_notation.c \
		lib/stack.c
OBJ = $(SRC:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

all: clean tests install

main: polish_notation.a
	$(CC) $(CFLAGS) main.c polish_notation.a -o test.out

polish_notation.a: $(OBJ) lib/polish_notation.h
	ar rcs polish_notation.a $(OBJ)
	ranlib polish_notation.a

install:
	cmake ./Calculator/CMakeLists.txt
	make
	cp ./lib/Makefile ./
	open Calculator.app

uninstall:
	rm -rf CMakeFiles
	rm -rf Calculator_autogen
	rm -rf CMakeCache.txt
	rm -rf cmake_install.cmake
	rm -rf Calculator.app

tests: 
	$(CC) $(CFLAGS) --coverage test/s21_test.c $(SRC) -lcheck -lm -lpthread -o tests
	./tests

gcov_report: 
	gcovr --html-details report.html
	open report.html

style:
	clang-format -n test/*.c
	clang-format -n lib/*.c

dvi:
	open dvi.txt

dist:
	mkdir calc_dist
	cp -r ./Calculator ./calc_dist
	cp -r ./lib ./calc_dist
	cp -r ./test ./calc_dist
	cp dvi.txt ./calc_dist
	cp main.c ./calc_dist
	cp Makefile ./calc_dist
	tar -zcvf calc_dist.tar.gz ./calc_dist
	rm -rf calc_dist

clean: uninstall
	rm -rf *.out polish_notation.a
	rm -rf lib/*.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf tests
	rm -rf *.html
	rm -rf *.css

.PHONY: all main polish_notation.a install uninstall tests gcov_report style dvi dist clean