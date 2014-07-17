#ifndef SOLVE_H
#define SOLVE_H

int init_possibilities(int* p);

int display_possibilities(int* possibilities);

int remove_possibility(int* possibilities, int line, int column, int value);

int update_sudoku(int* sudoku, int* possibilities);

int solve_sudoku(int* sudoku);
#endif
