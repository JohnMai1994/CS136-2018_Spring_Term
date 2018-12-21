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

void reword(void){
  int i = 1;
  char k = 0;
  while (1) {
    char c = read_char(false);
    if (c == READ_CHAR_FAIL) {
      break;
    }
    if (i%2 == 1) {
      k = c;
      ++i;
    }else{
      printf("%c%c", c, k);
      ++i;
    }
  }
  printf("\n");
}
    
    

int main(void) {
  reword();  
}
