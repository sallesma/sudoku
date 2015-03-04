#include "../src/exhaustive.h"
#include "../src/basic.h"
#include "../src/constants.h"
#include "../src/sudoku.h"
#include "CUnit/CUnit.h"

void test_get_first_empty(void)
{
   int sudoku[GLOBAL_SIZE];
   load_sudoku(sudoku, "sudoku_basic.txt");
   
   int index = get_first_empty(sudoku);
   CU_ASSERT_EQUAL(index, 0);

   load_sudoku(sudoku, "sudoku_solved.txt");
   index = get_first_empty(sudoku);
   CU_ASSERT_EQUAL(index, GLOBAL_SIZE);
}

void test_get_next_possible_value(void)
{
   int possibilities[GLOBAL_SIZE*POSSIBILITY_LENGTH];
   init_possibilities(possibilities);

   int value = get_next_possible_value(possibilities, 0, 0);
   CU_ASSERT_EQUAL(value, 1);

   value = get_next_possible_value(possibilities, 0, 1);
   CU_ASSERT_EQUAL(value, 2);

   value = get_next_possible_value(possibilities, 0, 9);
   CU_ASSERT_EQUAL(value, POSSIBILITY_LENGTH);

   possibilities[4] = 0;
   value = get_next_possible_value(possibilities, 0, 3);
   CU_ASSERT_EQUAL(value, 5);
}
