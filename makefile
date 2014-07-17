
run: compile
	./main sudoku_basic.txt

compile: main.o solve.o utils.o
	gcc -o main main.o solve.o utils.o

#Broken since compile has changed
#autocompile:
#	while true; do inotifywait -e modify src/*; gcc -o main src/main.c src/solve.c ; done
#
#autorun:
#	while true; do inotifywait -e modify src/*; gcc -o main src/main.c src/solve.c src/utils.c; ./main sudoku_basic.txt; done

pull:
	git pull origin master

push:
	git push origin master

sync: pull push

main.o: 
	gcc -c src/main.c

solve.o:
	gcc -c src/solve.c

utils.o:
	gcc -c src/utils.c
