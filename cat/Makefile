all: cat

cat: cat.o func.o
	gcc -Wall -Werror -Wextra cat.o func.o -o cat

cat.o: cat.c
	gcc -Wall -Werror -Wextra -c cat.c -std=c11

func.o: ../func_cat/func.c
	gcc -Wall -Werror -Wextra -c ../func_cat/func.c -std=c11

clean: 
	rm cat.o cat func.o

rebuild: clean all

