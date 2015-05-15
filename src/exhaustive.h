#ifndef EXHAUSTIVE_H
#define EXHAUSTIVE_H

int get_first_empty(int * sudoku);

int get_next_possible_value(int * possibilities, int box_index, int previous);

int solve_sudoku_exhaustive(int * sudoku);

#endif
