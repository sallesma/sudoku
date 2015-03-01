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

_OBJS = main.o solve.o sudoku.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

run: compile
	./$(OUT) sudoku_basic.txt

compile: $(OBJS) 
	$(CC) -o $(OUT) $(OBJS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c -o $@ $<

clean:
	rm -f $(ODIR)/*.o $(OUT) $(TESTODIR)/*.o


######################
# test compilation commands

OUTTEST = test_sudoku
TESTDIR = test
TESTODIR = test/obj

_TESTOBJS = sudoku.o
TESTOBJS = $(patsubst %,$(TESTODIR)/%,$(_TESTOBJS))
TESTOBJSLIB = $(patsubst %,$(ODIR)/%,$(_TESTOBJS))

$(TESTODIR)/%.o: $(TESTDIR)/%.c
	$(CC) -c -o $@ $<

compile-test: compile $(TESTOBJS) 
	$(CC) -Wall -o $(OUTTEST) $(TESTOBJS) $(TESTOBJSLIB) -lcunit

test: compile-test
	./$(OUTTEST)


###################
# Automatic compile, test, run

autocompile:
	while true; do inotifywait -e modify src/*; make compile ; done

autotest:
	while true; do inotifywait -e modify src/* test/*; make test ; done

autorun:
	while true; do inotifywait -e modify src/*; make compile; make run; done
