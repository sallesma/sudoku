
run: compile
	./main sudoku_basic.txt

compile:
	gcc -o main src/main.c src/solve.c

autocompile:
	while true; do inotifywait -e modify src/*; gcc -o main src/main.c src/solve.c; done

autorun:
	while true; do inotifywait -e modify src/*; gcc -o main src/main.c src/solve.c; ./main sudoku_basic.txt; done

pull:
	git pull origin master

push:
	git push origin master

sync: pull push
