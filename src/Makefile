CC = gcc
OS :=$(shell uname -s)
CFLAGS =-lstdc++ -std=c++17 -Wall -Wextra -Werror -g
ifeq ($(OS), Darwin)
	TEST_LIBS =-lgtest --coverage
else
	TEST_LIBS =-lgtest -lrt -lm -lpthread --coverage
endif

all: clean uninstall install gcov_report dvi dist linc

uninstall:
	rm -rf build

install: gui core

clean :
	rm -rf temp_build build reports tests report test.info gcov f test main *.txt *dSYM *.a *.o *.g* */*.o */*.a */*/*.o *.g* */*.g* */*/*.g*


gui:
	mkdir temp_build
	mkdir build
	

core:
	cd temp_build/ && qmake ../calc/calk.pro && make && mv calk.app ../build/
	open ./build
	rm -rf temp_build


gcov_report: clean
	${CC} --coverage ./test.cpp ./calc/stack.cpp ./calc/s21_controller.cpp ./calc/s21_model.cpp ./calc/credit.cpp ${TEST_LIBS} ${CFLAGS} -o gcov
	./gcov gs21_calc.a
	gcov gs21_calc.a
	make lcov
# ~/goinfre/homebrew/bin/
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

lcov: lcov_install
ifeq ("", "$(wildcard ~/goinfre/homebrew/bin/lcov)")
	make lcov_install
endif

lcov_install :  brew
	brew install lcov

brew:
ifeq ("", "$(wildcard ~/goinfre/homebrew)")
	git clone https://github.com/Homebrew/brew ~/goinfre/homebrew
#   curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
endif


.PHONY: tests
tests: clean
	${CC} ./test.cpp ./calc/stack.cpp ./calc/s21_controller.cpp ./calc/s21_model.cpp ./calc/credit.cpp ${TEST_LIBS} ${CFLAGS} -o test
	./test

linc: tests
	valgrind --tool=memcheck --leak-check=yes ./test
	@echo '------------------------------------'

check:
	cd calc && clang-format -style=Google -n *.h *.cpp *.cc
