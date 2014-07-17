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

autocompile:
	while true; do inotifywait -e modify src/*; make compile ; done

autorun:
	while true; do inotifywait -e modify src/*; make compile; make run; done
