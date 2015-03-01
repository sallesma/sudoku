#include"utils.h"
#include"constants.h"

int is_solved(int * sudoku) {
   int i, j;
   for(i=0 ; i<LINE_LENGTH ; i++)
      for(j=0 ; j<LINE_LENGTH ; j++)
         if (sudoku[i*LINE_LENGTH+j] == 0)
            return 0;
   return 1;
}

int parse_line(int * sudoku, int line, int column, int * possibilities) {
   int changed = 0;
   int j;
for(j=0 ; j<LINE_LENGTH ; j++)
      if (sudoku[line*LINE_LENGTH+j] != 0)
         changed = remove_possibility(possibilities, line, column, sudoku[line*LINE_LENGTH+j]);
   return changed;
}

int parse_column(int * sudoku, int line, int column, int * possibilities) {
   int changed = 0;
   int i;
   for(i=0 ; i<LINE_LENGTH ; i++)
      if (sudoku[i*LINE_LENGTH+column] != 0)
         changed = remove_possibility(possibilities, line, column, sudoku[i*LINE_LENGTH+column]);
   return changed;
}

int parse_square(int * sudoku, int line, int column, int * possibilities) {
   int changed = 0;
   int i,j;
   int k, l;
   i = line - line%3;
   
   for(k=0 ; k<3 ; k++){
      j = column - column%3;
      for(l=0 ; l<3 ; l++) {
         if (sudoku[i*LINE_LENGTH+j] != 0)
            changed = remove_possibility(possibilities, line, column, sudoku[i*LINE_LENGTH+j]);
         j++;
      }
      i++;
   }
   return changed;
}

