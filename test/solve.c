#include "solve.h"
#include "CUnit/CUnit.h"
#include "../src/solve.h"
#include "../src/constants.h"
#include "../src/sudoku.h"

void test_init_possibilities(void)
{
   int possibilities[GLOBAL_SIZE*POSSIBILITY_LENGTH];
   init_possibilities(possibilities);

   int i;
   for(i=0 ; i<GLOBAL_SIZE ; i++)
   {
      CU_ASSERT_EQUAL(possibilities[i*POSSIBILITY_LENGTH], 9);
      CU_ASSERT_EQUAL(possibilities[i*POSSIBILITY_LENGTH+1], 1);
      CU_ASSERT_EQUAL(possibilities[i*POSSIBILITY_LENGTH+2], 2);
      CU_ASSERT_EQUAL(possibilities[i*POSSIBILITY_LENGTH+3], 3);
      CU_ASSERT_EQUAL(possibilities[i*POSSIBILITY_LENGTH+4], 4);
      CU_ASSERT_EQUAL(possibilities[i*POSSIBILITY_LENGTH+5], 5);
      CU_ASSERT_EQUAL(possibilities[i*POSSIBILITY_LENGTH+6], 6);
      CU_ASSERT_EQUAL(possibilities[i*POSSIBILITY_LENGTH+7], 7);
      CU_ASSERT_EQUAL(possibilities[i*POSSIBILITY_LENGTH+8], 8);
      CU_ASSERT_EQUAL(possibilities[i*POSSIBILITY_LENGTH+9], 9);
   }
}

void test_remove_possibility(void)
{
   int possibilities[GLOBAL_SIZE*POSSIBILITY_LENGTH];
   init_possibilities(possibilities);
   
   remove_possibility(possibilities, 0, 0, 1);
   CU_ASSERT_EQUAL(possibilities[0], 8);
   CU_ASSERT_EQUAL(possibilities[1], 0);
   
   remove_possibility(possibilities, 0, 0, 1);
   CU_ASSERT_EQUAL(possibilities[0], 8);
   CU_ASSERT_EQUAL(possibilities[1], 0);
   
   remove_possibility(possibilities, 0, 0, 2);
   CU_ASSERT_EQUAL(possibilities[0], 7);
   CU_ASSERT_EQUAL(possibilities[2], 0);
}
