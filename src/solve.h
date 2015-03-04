#ifndef SOLVE_H
#define SOLVE_H

int init_possibilities(int* p);

int display_possibilities(int* possibilities);

int remove_possibility(int* possibilities, int line, int column, int value);

int parse_line(int* sudoku, int line, int column, int* possibilities);

int parse_column(int* sudoku, int line, int column, int* possibilities);

int parse_square(int* sudoku, int line, int column, int* possibilities);

int update_sudoku(int* sudoku, int* possibilities);

int auto_solve(int* sudoku, int* possibilities);

int solve_sudoku_basic(int* sudoku);

#endif
