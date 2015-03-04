#include "constants.h"
#include "sudoku.h"
#include "solve.h"


int get_first_empty(int * sudoku)
{
   int i = 0;
   while(i < GLOBAL_SIZE && sudoku[i] != 0)
   {
      i++;
   }
   return i;
}

int get_next_possible_value(int * possibilities, int box_index, int previous)
{
   if(previous < 0)
      previous = 0;
   int i = previous + 1;
   while(possibilities[box_index*POSSIBILITY_LENGTH+i] == 0 && i < POSSIBILITY_LENGTH)
   {
      i++;
   }
   return i;
}

int try_to_solve(int * sudoku, int * possibilities)
{
   // if solvable directly, solve and move up
   if(auto_solve(sudoku, possibilities))
      return 1;

   //Else try to solve guessing first empty box 
   int first_empty_index = get_first_empty(sudoku);
   if(first_empty_index == GLOBAL_SIZE)
      return 0;

   int possible_value = get_next_possible_value(possibilities, first_empty_index, 0);
   while(possible_value < POSSIBILITY_LENGTH)
   {
      // duplicate S and P
      int sudoku_temp[GLOBAL_SIZE];
      int possibilities_temp[GLOBAL_SIZE*POSSIBILITY_LENGTH];
      int i;
      for(i = 0 ; i<GLOBAL_SIZE ; i++)
         sudoku_temp[i] = sudoku[i];
      for(i = 0 ; i<GLOBAL_SIZE*POSSIBILITY_LENGTH ; i++)
         possibilities_temp[i] = possibilities[i];

      //update sudoku
      sudoku_temp[first_empty_index] = possible_value;
      
      //try to solve with temp sdoku and possibilities 
      int result = try_to_solve(sudoku_temp, possibilities_temp);
      if(result)
      {
         for(i = 0 ; i<GLOBAL_SIZE ; i++)
            sudoku[i] = sudoku_temp[i];
         for(i = 0 ; i<GLOBAL_SIZE*POSSIBILITY_LENGTH ; i++)
            possibilities[i] = possibilities_temp[i];
         return 1;
      }

      possible_value = get_next_possible_value(possibilities, first_empty_index, possible_value);
   }
   return 0;
}

int solve_sudoku_exhaustive(int * sudoku)
{
   int possibilities[GLOBAL_SIZE*POSSIBILITY_LENGTH];
   init_possibilities(possibilities);

   int result = try_to_solve(sudoku, possibilities);
}
