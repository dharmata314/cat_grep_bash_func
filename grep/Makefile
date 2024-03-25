all: s21_grep

s21_grep: s21_grep.o func.o
	gcc -Wall -Werror -Wextra s21_grep.o func.o -o s21_grep

s21_grep.o: s21_grep.c
	gcc -Wall -Werror -Wextra -c s21_grep.c -std=c11

func.o: ../func_grep/func.c
	gcc -Wall -Werror -Wextra -c ../func_grep/func.c -std=c11

clean: 
	rm s21_grep.o s21_grep func.o

rebuild: clean all
