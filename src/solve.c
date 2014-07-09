#include"main.h"


void init_possibilities(int * p) {
	int i, j;
 	for(i=0 ; i<GLOBAL_SIZE ; i++)
		for(j=0 ; j<POSSIBILITY_LENGTH ; j++)
         p[i*POSSIBILITY_LENGTH+j] = (j+8)%LINE_LENGTH+1; //we want 9 1 2 3 4 5 6 7 8 9
}

void display_possibilities(int * possibilities) {
	int i, j;
	printf("\n\n\n");
	for(i=0 ; i<GLOBAL_SIZE ; i++) {
		for(j=0 ; j<POSSIBILITY_LENGTH ; j++)
			printf("%d ", *(possibilities+i*POSSIBILITY_LENGTH+j));
		printf("\n");
	}
}

int remove_possibility(int * possibilities, int line, int column, int value) {
   if (possibilities[(line*LINE_LENGTH+column)*POSSIBILITY_LENGTH+value] != 0) {
      possibilities[(line*LINE_LENGTH+column)*POSSIBILITY_LENGTH]--;
      possibilities[(line*LINE_LENGTH+column)*POSSIBILITY_LENGTH+value] = 0;
      return 1;
   }
   return 0;
}

int update_sudoku(int * sudoku, int * possibilities){
   int changed = 0;
   int i;
   int k;
   for(i=0 ; i<GLOBAL_SIZE ; i++)
      if(sudoku[i] == 0 && possibilities[i*POSSIBILITY_LENGTH] == 1)
         for (k=1 ; k<POSSIBILITY_LENGTH ; k++)
            if (possibilities[i*POSSIBILITY_LENGTH+k] !=0) {
               sudoku[i] = possibilities[i*POSSIBILITY_LENGTH+k];
               changed = 1;
            }
   return changed;
}

int solve_sudoku(int * sudoku) {
   int possibilities[GLOBAL_SIZE*(LINE_LENGTH+1)];
   init_possibilities(possibilities);

   int changed = 1;
   while (!is_solved(sudoku) && changed != 0) {
      changed = 0;
      int i, j;
 	   for(i=0 ; i<LINE_LENGTH ; i++)
	   	for(j=0 ; j<LINE_LENGTH ; j++)
            if (sudoku[i*LINE_LENGTH+j] == 0) {
               changed += parse_line(sudoku, i, j, possibilities);
               changed += parse_column(sudoku, i, j, possibilities);
               changed += parse_square(sudoku, i, j, possibilities);
               changed += update_sudoku(sudoku, possibilities);
            }
   }
   return changed;
}


