CC = gcc
CFLAGC = -Wall -Werror -Wextra -g -std=c11
GCOVFLAGS := --coverage
SOURCES_C := Viewer/c_libs/s21_parse.c Viewer/c_libs/test/s21_test.c
OBJECTS := *.o
TEST := Viewer/c_libs/test/test
LDFLAGS := -lcheck -lm -lpthread
PRO := ./Viewer/Viewer.pro
MAKEFILE := ./Viewer/Makefile
TEXI2DVI := cp
INSTRUCTION := ./Viewer/3DViewer.pdf
INSTRUCTION_DVI :=./3DViewer.pdf
pth=./

all: clean uninstall install test gcov_report

install:
	qmake $(PRO)
	make
	make install INSTALL_ROOT=$(HOME)/$(pth)
	rm Makefile
	cp $(MAKEFILE) ./

uninstall:
	rm -rf *.h
	rm -rf *.o
	rm -rf *.app
	rm -rf *.cpp

true_dvi:
	texi2dvi ./instriction.tex

dvi:
	$(TEXI2DVI) $(INSTRUCTION) ./
	open $(INSTRUCTION_DVI)

dist:
	mkdir gcc-99
	cp -r ./Viewer/ ./gcc-99
	rm -rf ./gcc-99/c_libs/test
	cp Makefile ./gcc-99
	tar -zcvf gcc-99.tar.gz ./gcc-99
	rm -rf gcc-99


rebuild: uninstall clean all

style:
	clang-format -n ./*/*/*.c ./*/*/*.h ./*/*.cpp ./*/*.h

clean:
	rm -rf *.pdf
	rm -rf *.a
	rm -rf *.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.html
	rm -rf *.css
	rm -rf *.pdf
	rm -rf *.tex
	rm -rf *.app
	rm -rf $(TEST)
	
test:
	$(CC) $(CFLAGC) $(GCOVFLAGS) $(SOURCES_C) $(LDFLAGS) -o $(TEST)
	./$(TEST)


gcov_report:
	gcovr --html-details report.html
	open report.html

.PHONY: test gcov_report
