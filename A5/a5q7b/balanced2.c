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

#include "cs136-trace.h"
#include "stack.h"
#include <stdio.h>

int main(void) {
  int round_bracket_num = 0;
  int square_bracket_num = 0;
  int middle_bracket_num = 0;
  int arrow_bracket_num = 0;
  while (1) {
    char read_in = ' ';
    int is_it_char = scanf("%c", &read_in);
    if (is_it_char != 1) {
      break; 
    }
    if (read_in == '(') {
       ++round_bracket_num;
    }
    if (read_in == ')') {
       --round_bracket_num; 
    }
    if (read_in == '<') {
       ++arrow_bracket_num;
    }
    if (read_in == '>') {
       --arrow_bracket_num; 
    }
    if (read_in == '{') {
       ++middle_bracket_num;
    }
    if (read_in == '}') {
       --middle_bracket_num; 
    }
    if (read_in == '[') {
       ++square_bracket_num;
    }
    if (read_in == ']') {
       --square_bracket_num; 
    }
  }
    if ((round_bracket_num ==0) && (square_bracket_num ==0) && 
      (middle_bracket_num ==0) && (arrow_bracket_num ==0)) {
      printf("balanced\n"); 
    } else {
      printf("unbalanced\n") ;
    }
    
}
