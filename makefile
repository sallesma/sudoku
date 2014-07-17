################
# git commands

pull:
	git pull origin master

push:
	git push origin master

sync: pull push


######################
# compilation commands

OUT = sudoku
CC = gcc
ODIR = obj
SDIR = src

_OBJS = main.o solve.o utils.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

run:
	./$(OUT) sudoku_basic.txt

compile-run: compile
	./$(OUT) sudoku_basic.txt

compile: $(OBJS) 
	$(CC) -o $(OUT) $(OBJS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c -o $@ $<

clean:
	rm -f $(ODIR)/*.o $(OUT)

#Broken since compile has changed
#autocompile:
#	while true; do inotifywait -e modify src/*; gcc -o main src/main.c src/solve.c ; done
#
#autorun:
#	while true; do inotifywait -e modify src/*; gcc -o main src/main.c src/solve.c src/utils.c; ./main sudoku_basic.txt; done
