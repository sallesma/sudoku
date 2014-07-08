
run: compile
	./main sudoku.txt

compile: main.c
	gcc -o main main.c

