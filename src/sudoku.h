#ifndef SUDOKU_H
#define SUDOKU_H

void load_sudoku(int *sudoku, char *filename);

void display_sudoku(int * sudoku);

int is_solved(int* sudoku);

#endif
