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
DDIR = data

_OBJS = main.o basic.o exhaustive.o sudoku.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

run: compile
	./$(OUT) $(DDIR)/sudoku_basic.txt

run-exhaustive: compile
	./$(OUT) $(DDIR)/sudoku_exhaustive.txt

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

_TESTOBJS = sudoku.o basic.o exhaustive.o
TESTOBJS = $(patsubst %,$(TESTODIR)/%,$(_TESTOBJS))
TESTOBJSLIB = $(patsubst %,$(ODIR)/%,$(_TESTOBJS))

$(TESTODIR)/%.o: $(TESTDIR)/%.c
	$(CC) -c -o $@ $<

compile-test: compile test/obj/main.o $(TESTOBJS) 
	$(CC) -Wall -o $(OUTTEST) test/obj/main.o $(TESTOBJS) $(TESTOBJSLIB) -lcunit

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
