#include"sudoku.h"
#include"constants.h"

void load_sudoku(int *sudoku, char *filename) {
   int i, j;
   char line[256];
   char *record = 0;
   FILE* f = fopen(filename, "r");
   
   if (f == NULL) {
      printf("\nCould not open file !");
      exit(0);
   }
   for (i = 0 ; i<LINE_LENGTH ; i++) {
      fgets(line, sizeof(line), f);
      record = strtok(line, ",");
     
      j = 0;
      for(j=0 ; j<LINE_LENGTH ; j++) {
         sudoku[i*LINE_LENGTH+j] = atoi(record);
         record = strtok(NULL, ",");
      }
   }
   fclose(f);
}

void display_sudoku(int * sudoku) {
   int i, j;
   printf("\n\n\n");
   for(i=0 ; i<LINE_LENGTH ; i++) {
      for(j=0 ; j<LINE_LENGTH ; j++)
         printf("%d ", *(sudoku+i*LINE_LENGTH+j));
      printf("\n");
   }
}

int is_valid_value(int * sudoku, int line, int column) {
   int i,j;
   //Check line
   for(j = 0 ; j < LINE_LENGTH ; j++)
      if(j!=column && sudoku[line*LINE_LENGTH+j] == sudoku[line*LINE_LENGTH+column])
         return 0;
   //Check column
   for(i = 0 ; i < LINE_LENGTH ; i++)
      if(i!=line && sudoku[i*LINE_LENGTH+column] == sudoku[line*LINE_LENGTH+column])
         return 0;
   //Check square
   int k, l;
   i = line - line%3;
   for(k=0 ; k<3 ; k++){
      j = column - column%3;
      for(l=0 ; l<3 ; l++) {
         if (i != line && j != column && sudoku[i*LINE_LENGTH+j] == sudoku[line*LINE_LENGTH+column])
            return 0;
         j++;
      }
      i++;
   }
   return 1;
}

int is_solved(int * sudoku) {
   int i, j;
   for(i=0 ; i<LINE_LENGTH ; i++)
      for(j=0 ; j<LINE_LENGTH ; j++)
         if (sudoku[i*LINE_LENGTH+j] == 0 || !is_valid_value(sudoku, i, j))
            return 0;
   return 1;
}

