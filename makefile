
run: compile
	./main sudoku.txt

compile: main.c solve.c
	gcc -o main main.c solve.c

autocompile: main.c
	while true; do inotifywait -e modify *.c *.h; gcc -o main main.c solve.c; done

autorun: main.c
	while true; do inotifywait -e modify *.c *.h; gcc -o main main.c solve.c; ./main sudoku.txt; done

pull:
	git pull origin master

push:
	git push origin master
