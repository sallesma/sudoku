
run: compile
	./main sudoku.txt

compile: main.c
	gcc -o main main.c

autocompile: main.c
	while true; do inotifywait -e modify main.c; gcc -o main main.c; done

autorun: main.c
	while true; do inotifywait -e modify main.c; gcc -o main main.c; ./main sudoku.txt; done

