#include "CUnit/CUnit.h"
#include "../src/basic.h"
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

void test_parse_line(void)
{
   int sudoku[GLOBAL_SIZE];
   load_sudoku(sudoku, "sudoku_basic.txt");

   int possibilities[GLOBAL_SIZE*POSSIBILITY_LENGTH];
   init_possibilities(possibilities);
   
   int result = parse_line(sudoku, 0, 0, possibilities);
   CU_ASSERT_EQUAL(result, 1);
   CU_ASSERT_EQUAL(possibilities[0], 3);
   CU_ASSERT_EQUAL(possibilities[1], 0);
   CU_ASSERT_EQUAL(possibilities[2], 0);
   CU_ASSERT_EQUAL(possibilities[3], 0);
   CU_ASSERT_EQUAL(possibilities[4], 4);
   CU_ASSERT_EQUAL(possibilities[5], 0);
   CU_ASSERT_EQUAL(possibilities[6], 6);
   CU_ASSERT_EQUAL(possibilities[7], 0);
   CU_ASSERT_EQUAL(possibilities[8], 0);
   CU_ASSERT_EQUAL(possibilities[9], 9);
 
   result = parse_line(sudoku, 1, 0, possibilities);
   CU_ASSERT_EQUAL(result, 1);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+0], 7);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+1], 1);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+2], 0);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+3], 3);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+4], 0);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+5], 5);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+6], 6);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+7], 7);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+8], 8);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+9], 9);
 
   result = parse_line(sudoku, 1, 0, possibilities);
   CU_ASSERT_EQUAL(result, 0);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+0], 7);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+1], 1);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+2], 0);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+3], 3);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+4], 0);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+5], 5);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+6], 6);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+7], 7);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+8], 8);
   CU_ASSERT_EQUAL(possibilities[LINE_LENGTH*POSSIBILITY_LENGTH+9], 9);
}

void test_parse_column(void)
{
   int sudoku[GLOBAL_SIZE];
   load_sudoku(sudoku, "sudoku_basic.txt");

   int possibilities[GLOBAL_SIZE*POSSIBILITY_LENGTH];
   init_possibilities(possibilities);
   
   int result = parse_column(sudoku, 0, 0, possibilities);
   CU_ASSERT_EQUAL(result, 1);
   CU_ASSERT_EQUAL(possibilities[0], 5);
   CU_ASSERT_EQUAL(possibilities[1], 0);
   CU_ASSERT_EQUAL(possibilities[2], 2);
   CU_ASSERT_EQUAL(possibilities[3], 0);
   CU_ASSERT_EQUAL(possibilities[4], 0);
   CU_ASSERT_EQUAL(possibilities[5], 5);
   CU_ASSERT_EQUAL(possibilities[6], 6);
   CU_ASSERT_EQUAL(possibilities[7], 7);
   CU_ASSERT_EQUAL(possibilities[8], 0);
   CU_ASSERT_EQUAL(possibilities[9], 9);
 
   result = parse_column(sudoku, 0, 0, possibilities);
   CU_ASSERT_EQUAL(result, 0);
   CU_ASSERT_EQUAL(possibilities[0], 5);
   CU_ASSERT_EQUAL(possibilities[1], 0);
   CU_ASSERT_EQUAL(possibilities[2], 2);
   CU_ASSERT_EQUAL(possibilities[3], 0);
   CU_ASSERT_EQUAL(possibilities[4], 0);
   CU_ASSERT_EQUAL(possibilities[5], 5);
   CU_ASSERT_EQUAL(possibilities[6], 6);
   CU_ASSERT_EQUAL(possibilities[7], 7);
   CU_ASSERT_EQUAL(possibilities[8], 0);
   CU_ASSERT_EQUAL(possibilities[9], 9);
 
   result = parse_column(sudoku, 0, 4, possibilities);
   CU_ASSERT_EQUAL(result, 0);
   CU_ASSERT_EQUAL(possibilities[4*POSSIBILITY_LENGTH+0], 9);
   CU_ASSERT_EQUAL(possibilities[4*POSSIBILITY_LENGTH+1], 1);
   CU_ASSERT_EQUAL(possibilities[4*POSSIBILITY_LENGTH+2], 2);
   CU_ASSERT_EQUAL(possibilities[4*POSSIBILITY_LENGTH+3], 3);
   CU_ASSERT_EQUAL(possibilities[4*POSSIBILITY_LENGTH+4], 4);
   CU_ASSERT_EQUAL(possibilities[4*POSSIBILITY_LENGTH+5], 5);
   CU_ASSERT_EQUAL(possibilities[4*POSSIBILITY_LENGTH+6], 6);
   CU_ASSERT_EQUAL(possibilities[4*POSSIBILITY_LENGTH+7], 7);
   CU_ASSERT_EQUAL(possibilities[4*POSSIBILITY_LENGTH+8], 8);
   CU_ASSERT_EQUAL(possibilities[4*POSSIBILITY_LENGTH+9], 9);
}

void test_parse_square(void)
{
   int sudoku[GLOBAL_SIZE];
   load_sudoku(sudoku, "sudoku_basic.txt");

   int possibilities[GLOBAL_SIZE*POSSIBILITY_LENGTH];
   init_possibilities(possibilities);

   int result = parse_square(sudoku, 0, 0, possibilities);
   CU_ASSERT_EQUAL(result, 1);
   CU_ASSERT_EQUAL(possibilities[0], 5);
   CU_ASSERT_EQUAL(possibilities[1], 1);
   CU_ASSERT_EQUAL(possibilities[2], 0);
   CU_ASSERT_EQUAL(possibilities[3], 0);
   CU_ASSERT_EQUAL(possibilities[4], 0);
   CU_ASSERT_EQUAL(possibilities[5], 0);
   CU_ASSERT_EQUAL(possibilities[6], 6);
   CU_ASSERT_EQUAL(possibilities[7], 7);
   CU_ASSERT_EQUAL(possibilities[8], 8);
   CU_ASSERT_EQUAL(possibilities[9], 9);

   result = parse_square(sudoku, 0, 0, possibilities);
   CU_ASSERT_EQUAL(result, 0);
   CU_ASSERT_EQUAL(possibilities[0], 5);
   CU_ASSERT_EQUAL(possibilities[1], 1);
   CU_ASSERT_EQUAL(possibilities[2], 0);
   CU_ASSERT_EQUAL(possibilities[3], 0);
   CU_ASSERT_EQUAL(possibilities[4], 0);
   CU_ASSERT_EQUAL(possibilities[5], 0);
   CU_ASSERT_EQUAL(possibilities[6], 6);
   CU_ASSERT_EQUAL(possibilities[7], 7);
   CU_ASSERT_EQUAL(possibilities[8], 8);
   CU_ASSERT_EQUAL(possibilities[9], 9);

   result = parse_square(sudoku, 1, 1, possibilities);
   CU_ASSERT_EQUAL(result, 1);
   CU_ASSERT_EQUAL(possibilities[(LINE_LENGTH+1)*POSSIBILITY_LENGTH+0], 5);
   CU_ASSERT_EQUAL(possibilities[(LINE_LENGTH+1)*POSSIBILITY_LENGTH+1], 1);
   CU_ASSERT_EQUAL(possibilities[(LINE_LENGTH+1)*POSSIBILITY_LENGTH+2], 0);
   CU_ASSERT_EQUAL(possibilities[(LINE_LENGTH+1)*POSSIBILITY_LENGTH+3], 0);
   CU_ASSERT_EQUAL(possibilities[(LINE_LENGTH+1)*POSSIBILITY_LENGTH+4], 0);
   CU_ASSERT_EQUAL(possibilities[(LINE_LENGTH+1)*POSSIBILITY_LENGTH+5], 0);
   CU_ASSERT_EQUAL(possibilities[(LINE_LENGTH+1)*POSSIBILITY_LENGTH+6], 6);
   CU_ASSERT_EQUAL(possibilities[(LINE_LENGTH+1)*POSSIBILITY_LENGTH+7], 7);
   CU_ASSERT_EQUAL(possibilities[(LINE_LENGTH+1)*POSSIBILITY_LENGTH+8], 8);
   CU_ASSERT_EQUAL(possibilities[(LINE_LENGTH+1)*POSSIBILITY_LENGTH+9], 9);
}
