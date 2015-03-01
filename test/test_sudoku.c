#include <CUnit/CUnit.h>
#include "CUnit/Basic.h"
#include "../src/constants.h"
#include "../src/sudoku.h"

void test_load_sudoku(void)
{
   int sudoku[GLOBAL_SIZE];
   load_sudoku(sudoku, "sudoku_basic.txt");
   //Check first line
   CU_ASSERT_EQUAL(sudoku[0], 0);
   CU_ASSERT_EQUAL(sudoku[1], 2);
   CU_ASSERT_EQUAL(sudoku[2], 3);
   CU_ASSERT_EQUAL(sudoku[3], 1);
   CU_ASSERT_EQUAL(sudoku[4], 0);
   CU_ASSERT_EQUAL(sudoku[5], 5);
   CU_ASSERT_EQUAL(sudoku[6], 7);
   CU_ASSERT_EQUAL(sudoku[7], 8);
   CU_ASSERT_EQUAL(sudoku[8], 0);
   //Check Last line
   CU_ASSERT_EQUAL(sudoku[8*LINE_LENGTH+0], 0);
   CU_ASSERT_EQUAL(sudoku[8*LINE_LENGTH+1], 3);
   CU_ASSERT_EQUAL(sudoku[8*LINE_LENGTH+2], 4);
   CU_ASSERT_EQUAL(sudoku[8*LINE_LENGTH+3], 6);
   CU_ASSERT_EQUAL(sudoku[8*LINE_LENGTH+4], 0);
   CU_ASSERT_EQUAL(sudoku[8*LINE_LENGTH+5], 7);
   CU_ASSERT_EQUAL(sudoku[8*LINE_LENGTH+6], 8);
   CU_ASSERT_EQUAL(sudoku[8*LINE_LENGTH+7], 5);
   CU_ASSERT_EQUAL(sudoku[8*LINE_LENGTH+8], 0);
}

void test_is_solved(void)
{
   int sudoku[GLOBAL_SIZE];
   load_sudoku(sudoku, "sudoku_basic.txt");
   CU_ASSERT_NOT_EQUAL(is_solved(sudoku), 1);

   load_sudoku(sudoku, "sudoku_solved.txt");
   CU_ASSERT_EQUAL(is_solved(sudoku), 1);
}

int main()
{
   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   CU_pSuite pSuiteSudoku = CU_add_suite("Suite Sudoku", NULL, NULL);
   if (NULL == pSuiteSudoku) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if (NULL == CU_add_test(pSuiteSudoku, "test load_sudoku", test_load_sudoku)
         || NULL == CU_add_test(pSuiteSudoku, "test is_solved", test_is_solved))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
