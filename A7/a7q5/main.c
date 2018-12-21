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

// Name: Jiadong mai
// login ID: J4mai
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "cs136-trace.h"


void ginorst(void) {
  int len = 0;
  int b[10000];
  char input;
  scanf(" %c", &input);
  b[0] = input;
    
  while(1){
    int stop = scanf(" %c",&input);
    ++len;
    if (stop != 1) {
      break;
    }
    char tmp = input;
    char z;
    for (int i=0; i < len+1; ++i) {
       if (tmp < b[i]) {
         z = b[i];
         b[i] = tmp;
         tmp = z;
       } 
      if (b[i] == 0) {
        b[i] = tmp;
      }
    }
  }
  for (int z = 0; z < len; ++z) {
    printf("%c", b[z]); 
  }
  printf("\n");
}


int main(void) {
  ginorst();
}
