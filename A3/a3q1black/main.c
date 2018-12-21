/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from the following sources:

// None    

// Name: Jiadong Mai
// login ID: j4mai
/////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

// empty_board(rows, columns): print the sample output
// requires: rows, columns >= 0
// effects: print output

void empty_board(int rows, int columns) {
  assert (rows >= 0);
  assert (columns >= 0);
  while (rows > 0) {
    int first_line = columns;
    int second_line = columns;
    while (first_line > 0){
      printf("+-");
      --first_line;
    } printf("+\n");
    while (second_line >0){
      printf("| ");
      --second_line;
    } printf("|\n");
    --rows;
  }
  while (columns > 0){
      printf("+-");
      --columns;
    } printf("+\n");
}
    
// empty_board(rows, columns, player_1, player_2): print the sample output, 
//     and the player_1 and player_2 obey the require on Question
// requires: rows, columns >= 0
// effects: print output
void filled_board(int rows, int columns, char player_1, char player_2) {
  assert (rows > 0);
  assert (columns > 0);
  int begin_row = 0;
  while (begin_row < rows) {
    if (begin_row%2 == 0) {
      int first_line = columns;
      int second_line = columns;
      int position = 1;
      while (first_line > 0){
        printf("+-");
        --first_line;
      } printf("+\n");
      while (position <= second_line){
        if ((((position+1)/2)%2) == 1){
          printf("|%c", player_1);
        }else{
          printf("|%c", player_2);
        }
        ++position;
      } printf("|\n");
      ++begin_row;
    } else{
      int first_line = columns;
      int second_line = columns;
      int position = 1;
      while (first_line > 0){
        printf("+-");
        --first_line;
      } printf("+\n");
      while (position <= second_line){
        if ((((position+1)/2)%2) == 1){
          printf("|%c", player_2);
        }else{
          printf("|%c", player_1);
        }
        ++position;
      } printf("|\n");
      ++begin_row;
    }
  }
  while (columns > 0){
      printf("+-");
      --columns;
    } printf("+\n");
}

int main(void) {
  empty_board(2,1);
  empty_board(3,5);
  filled_board(3,3,'O','X');
  filled_board(4,7,'1','2');
  // student test
  empty_board(0,0);
  empty_board(6,6);
  empty_board(1,3);
  
  filled_board(1,1,'M','J');
  filled_board(9,9,'m','j');
  
}
