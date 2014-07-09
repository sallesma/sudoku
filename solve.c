#include"main.h"

int parse_line(int * sudoku, int line, int column) {
   return 0;
}

int parse_column(int * sudoku, int line, int column) {
   return 0;
}

int parse_square(int * sudoku, int line, int column) {
   return 0;
}

// should return 1 if the possibilities or sudoku have been updated
int solve_sudoku(int * sudoku) {
   int changed = 0;
   int i, j;
 	for(i=0 ; i<LINE_LENGTH ; i++)
		for(j=0 ; j<LINE_LENGTH ; j++)
         if (sudoku[i*LINE_LENGTH+j] == 0) {
            changed += parse_line(sudoku, i, j);
            changed += parse_column(sudoku, i, j);
            changed += parse_square(sudoku, i, j);
         }
   return changed;
}


