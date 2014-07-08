#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GLOBAL_SIZE 81
#define LINE_LENGTH 9

void init_possibilities(int * p) {
	int i, j;
 	for(i=0 ; i<GLOBAL_SIZE ; i++)
		for(j=0 ; j<LINE_LENGTH+1 ; j++)
         p[i*(LINE_LENGTH+1)+j] = (j+8)%LINE_LENGTH+1; //we want 9 1 2 3 4 5 6 7 8 9
}

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

void display_possibilities(int * possibilities) {
	int i, j;
	printf("\n\n\n");
	for(i=0 ; i<GLOBAL_SIZE ; i++) {
		for(j=0 ; j<LINE_LENGTH+1 ; j++)
			printf("%d ", *(possibilities+i*(LINE_LENGTH+1)+j));
		printf("\n");
	}
}

int is_solved(int * sudoku) {
	int i, j;
 	for(i=0 ; i<LINE_LENGTH ; i++)
		for(j=0 ; j<LINE_LENGTH ; j++)
			if (sudoku[i*LINE_LENGTH+j] == 0)
            return 0;
   return 1;
}

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

int main(int argc, char** argv) {
   char * filename = argv[1];
   int sudoku[GLOBAL_SIZE];

   int possibilities[GLOBAL_SIZE*(LINE_LENGTH+1)];
   init_possibilities(possibilities);
   display_possibilities(possibilities);
   load_sudoku(sudoku, filename);
   display_sudoku(sudoku);
   while (!is_solved(sudoku) && solve_sudoku(sudoku));
   display_sudoku(sudoku);
   return 0;
}
