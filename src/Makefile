GCC := g++
CXX_FLAGS := -Wall -Werror -Wextra --std=c++17
GCOV_FLAGS := --coverage
LIBS := -lgtest -lgtest_main
TEST_SUITS_SRC := ./tests/test_suits/*/*.cc
CONTAINERS_H := ./s21_containers/*/*.h
CONTAINERS_TPP := ./s21_containers/*/*.tpp

OS := $(shell uname -s)
ifeq ($(OS), Linux)
	OPEN := google-chrome
else
	OPEN = open
endif

.PHONY: valgrind gcov_report clang clean

all: clang test gcov_report

test: s21_containers.h
	$(GCC) $(CXX_FLAGS) -o test ./tests/tests_main.cc $(TEST_SUITS_SRC) $(LIBS)
	./$@

valgrind: test
	CK_FORK=no valgrind -s  --track-origins=yes --tool=memcheck --leak-check=full --show-leak-kinds=all --log-file=RESULT_VALGRIND.txt ./test

gcov_report: s21_containers.h
	$(GCC) $(CXX_FLAGS) $(GCOV_FLAGS) -o coverage_test ./tests/tests_main.cc $(TEST_SUITS_SRC) $(LIBS)
	./coverage_test
	lcov -t "s21_containers_tests_coverage" -o coverage.info --no-external -c -d .
	genhtml -o report coverage.info
	rm *.info *.gcda *.gcno coverage_test
	$(OPEN) report/index.html

clang: $(CONTAINERS_H) ./tests/*.h
	clang-format -style=Google -n ./*.h $(CONTAINERS_TPP) ./tests/*.cc  $(TEST_SUITS_SRC)

clean:
	rm -rf test RESULT_VALGRIND.txt report

rebuild: clean all