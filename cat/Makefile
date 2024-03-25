all: s21_cat

s21_cat: s21_cat.o func.o
	gcc -Wall -Werror -Wextra s21_cat.o func.o -o s21_cat

s21_cat.o: s21_cat.c
	gcc -Wall -Werror -Wextra -c s21_cat.c -std=c11

func.o: ../func_cat/func.c
	gcc -Wall -Werror -Wextra -c ../func_cat/func.c -std=c11

clean: 
	rm s21_cat.o s21_cat func.o

rebuild: clean all

