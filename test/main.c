#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "sudoku.h"
#include "basic.h"
#include "exhaustive.h"
#include "../src/constants.h"
#include "../src/sudoku.h"
#include "../src/basic.h"
#include "../src/exhaustive.h"

void test_functional(void);

int main()
{
   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add suites to the registry */
   CU_pSuite pSuiteSudoku = CU_add_suite("Suite Sudoku", NULL, NULL);
   if (NULL == pSuiteSudoku) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   CU_pSuite pSuiteSolve = CU_add_suite("Suite Solve", NULL, NULL);
   if (NULL == pSuiteSolve) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   CU_pSuite pSuiteExhaustive = CU_add_suite("Suite Exhaustive", NULL, NULL);
   if (NULL == pSuiteExhaustive) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   CU_pSuite pSuiteFunctional = CU_add_suite("Suite Functional", NULL, NULL);
   if (NULL == pSuiteFunctional) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suites */
   if (NULL == CU_add_test(pSuiteSudoku, "test load_sudoku", test_load_sudoku)
         || NULL == CU_add_test(pSuiteSudoku, "test is_solved", test_is_solved))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if (NULL == CU_add_test(pSuiteSolve, "test init_possibilities", test_init_possibilities)
         || NULL == CU_add_test(pSuiteSolve, "test remove_possibility", test_remove_possibility)
         || NULL == CU_add_test(pSuiteSolve, "test parse_line", test_parse_line)
         || NULL == CU_add_test(pSuiteSolve, "test parse_column", test_parse_column)
         || NULL == CU_add_test(pSuiteSolve, "test parse_square", test_parse_square))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if (NULL == CU_add_test(pSuiteExhaustive, "test get_first_empty", test_get_first_empty)
      || NULL == CU_add_test(pSuiteExhaustive, "test get_next_possible_value", test_get_next_possible_value))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if (NULL == CU_add_test(pSuiteFunctional, "test functional", test_functional))
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

void test_functional(void)
{
   int sudoku[GLOBAL_SIZE];
   load_sudoku(sudoku, "sudoku_basic.txt");
   
   CU_ASSERT(solve_sudoku_basic(sudoku));
   CU_ASSERT(solve_sudoku_exhaustive(sudoku));

   load_sudoku(sudoku, "sudoku_exhaustive.txt");
   CU_ASSERT_FALSE(solve_sudoku_basic(sudoku));
   CU_ASSERT(solve_sudoku_exhaustive(sudoku));

   load_sudoku(sudoku, "sudoku_empty.txt");
   CU_ASSERT_FALSE(solve_sudoku_basic(sudoku));
   CU_ASSERT(solve_sudoku_exhaustive(sudoku));
}
