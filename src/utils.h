#ifndef UTILS_H
#define UTILS_H

int is_solved(int* sudoku);

int parse_line(int* sudoku, int line, int column, int* possibilities);

int parse_column(int* sudoku, int line, int column, int* possibilities);

int parse_square(int* sudoku, int line, int column, int* possibilities);

#endif
