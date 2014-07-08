#include<stdio.h>
#include<stdlib.h>

#define GLOBAL_SIZE 81
#define LINE_LENGTH 9

int* load_sudoku() {
	static int sudoku[GLOBAL_SIZE];
	int i, j;
    for(i=0 ; i<LINE_LENGTH ; i++)
		for(j=0 ; j<LINE_LENGTH ; j++) {
            printf("%d", j);
			*(sudoku+i*LINE_LENGTH+j) = j;
        }
	return sudoku;
}

void display_sudoku(int * sudoku) {
	int i, j;
	for(i=0 ; i<LINE_LENGTH ; i++) {
		for(j=LINE_LENGTH ; j<LINE_LENGTH ; j++)
			printf("%d ", *(sudoku+i*LINE_LENGTH+j));
		printf("\n");
	}
}

int main(int argc, char** argv) {
	int * s = load_sudoku();
	display_sudoku(s);
	return 0;
}
