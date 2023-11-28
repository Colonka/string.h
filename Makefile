FLAGS= -Wall -Wextra -Werror
STD= -std=c11

all: s21_string.a

style:
	clang-format -i -style=google *.c
	clang-format -style=google -n *.c

s21_string.a: clean s21_string
	ar rc libs21_string.a s21_*.o
	ranlib libs21_string.a

s21_string: s21_string.c s21_sprintf.c s21_string.h
	gcc ${FLAGS} ${STD} -c s21_string.c s21_sprintf.c

test: s21_string.a test/test.c
	gcc ${FLAGS} ${STD} -c test/test.c
	gcc -fprofile-arcs -ftest-coverage -L. -ls21_string test.o -lcheck -lm -lpthread -o run_tests
	./run_tests

dvi: 
	mkdir -p docs
	doxygen Doxyfile
	mv html latex docs
	open docs/html/index.html

docs:
	open docs/html/index.html

git: clean
	git add -A
	git commit -m "$m"
	git push origin "$b"

gcov_report: test
	mkdir report
	./run_tests
	gcov -f *.gcno
	gcovr -r . --html --html-details -o report/report.html

clean:
	rm -rf *.o *.gcov *.gcno *.gcda run_tests s21_string libs21_string.a report
