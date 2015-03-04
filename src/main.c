#include "constants.h"
#include "sudoku.h"
#include "solve.h"
#include "exhaustive.h"

int main(int argc, char** argv) {
   char * filename = argv[1];
   int sudoku[GLOBAL_SIZE];
   load_sudoku(sudoku, filename);
   display_sudoku(sudoku);
   if (solve_sudoku_exhaustive(sudoku))
      printf("\n\nSuccess:\n");
   else
      printf("\n\nFailure:\n");
   display_sudoku(sudoku);
   return 0;
}
