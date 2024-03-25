all: grep

grep: grep.o func.o
	gcc -Wall -Werror -Wextra grep.o func.o -o grep

grep.o: grep.c
	gcc -Wall -Werror -Wextra -c grep.c -std=c11

func.o: ../func_grep/func.c
	gcc -Wall -Werror -Wextra -c ../func_grep/func.c -std=c11

clean: 
	rm grep.o grep func.o

rebuild: clean all
