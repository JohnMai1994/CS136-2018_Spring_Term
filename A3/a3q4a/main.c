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


// count_lower_case(c) read the character input and prints the number of lower
//     case characters encountered
// effects: read inputs
//          prints number

bool count_lower_case(char c) {
  if ((c >= 'a') && (c <= 'z')) {
    return true;
  } else{
    return false;
  }}
  


int main(void) {
  int lower_case = 0;
  while (1) {
    char c = read_char(false);
    if (c == READ_CHAR_FAIL) {
      break;
    } else if(count_lower_case(c)) {
      ++lower_case;
    }
  }
  printf("%d\n", lower_case);
}

