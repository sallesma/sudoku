#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "sudoku.h"

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