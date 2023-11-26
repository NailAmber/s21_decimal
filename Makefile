CFLAGS=-Wall -Werror -Wextra -std=gnu11
POSIX=-D_POSIX_C_SOURCE=200809L
COVER=-O0 --coverage

all: clean s21_decimal.a
	gcc $(CFLAGS) $(POSIX) main.c s21_decimal.a -o main

clean:
	rm -rf *.a *.o main

test:

s21_decimal.a:
	gcc $(CFLAGS) $(POSIX) s21_decimal.c -O -c
	ar rcs s21_decimal.a s21_decimal.o

gcov_report: