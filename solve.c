#include"main.h"

int parse_line(int * sudoku, int line, int column, int * possibilities) {
   int j;
   for(j=0 ; j<LINE_LENGTH ; j++)
      if (sudoku[line*LINE_LENGTH+j] != 0)
         //Remove from possibilities
   return 0;
}

int parse_column(int * sudoku, int line, int column, int * possibilities) {
   int i;
   for(i=0 ; i<LINE_LENGTH ; i++)
      if (sudoku[i*LINE_LENGTH+column] != 0)
         //Remove from possibilities
   return 0;
}

int parse_square(int * sudoku, int line, int column, int * possibilities) {
   int i,j;
   int k, l;
   i = line - line%3;
   
   for(k=0 ; k<3 ; k++){
      j = column - column%3;
      for(l=0 ; l<3 ; l++) {
         if (sudoku[i*LINE_LENGTH+j] != 0)
            //Remove from possibilities
            //printf("%d %d\n", i, j);;
            0;
         j++;
      }
      i++;
   }
   return 0;
}

int update_sudoku(int * sudoku, int * possibilities){
   int i;
   for(i=0 ; i<GLOBAL_SIZE ; i++)
      if(possibilities[i*POSSIBILITY_LENGTH] == 1)
         //update sudoku
         0;
   return 0;
}

// should return 1 if the possibilities or sudoku have been updated
int solve_sudoku(int * sudoku, int * possibilities) {
   int changed = 0;
   int i, j;
 	for(i=0 ; i<LINE_LENGTH ; i++)
		for(j=0 ; j<LINE_LENGTH ; j++)
         if (sudoku[i*LINE_LENGTH+j] == 0) {
            changed += parse_line(sudoku, i, j, possibilities);
            changed += parse_column(sudoku, i, j, possibilities);
            changed += parse_square(sudoku, i, j, possibilities);
            changed += update_sudoku(sudoku, possibilities);
         }
   printf("%d", changed);
   return changed;
}


