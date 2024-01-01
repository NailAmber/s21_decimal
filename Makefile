CFLAGS=-Wall -Werror -Wextra -std=gnu11
POSIX=-D_POSIX_C_SOURCE=200809L
COVER=--coverage
TESTS=s21_decimal_test.h s21_decimal_test.c

all: clean s21_decimal.a
	gcc $(CFLAGS) $(POSIX) main.c s21_decimal.a -o main $(COVER)

clean:
	rm -rf *.a *.o main *gcno *.gcda test *gcov ./coverage *.info *gch

test: clean s21_decimal.a
	gcc $(COVER) $(CFLAGS) $(TESTS) s21_decimal.a -lcheck -o test
	chmod +x test
	./test

s21_decimal.a:
	gcc $(CFLAGS) $(POSIX) s21_decimal.c -c $(COVER)
	ar rcs s21_decimal.a s21_decimal.o

gcov_report: clean test
	gcov *.gcno
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory coverage