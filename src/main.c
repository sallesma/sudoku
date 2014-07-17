#include"constants.h"
#include"utils.h"

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


int main(int argc, char** argv) {
   char * filename = argv[1];
   int sudoku[GLOBAL_SIZE];
   load_sudoku(sudoku, filename);
   display_sudoku(sudoku);
   if (solve_sudoku(sudoku))
      printf("\n\nSuccess:\n");
   else
      printf("\n\nFailure:\n");
   display_sudoku(sudoku);
   return 0;
}
