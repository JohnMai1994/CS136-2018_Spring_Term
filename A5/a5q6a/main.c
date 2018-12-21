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
// login ID: J4mai
/////////////////////////////////////////////////////////////////////////////

#include "cs136-trace.h"
#include "stack.h"
#include <stdio.h>

int main(void) {
  struct stack *k = stack_create();
  while(1){
    int number = 1;
    int is_it_number = scanf("%d", &number);
    if (is_it_number != 1) {
      break; 
    }
    printf("%d\n", number);
    stack_push(number, k);
  }
  while(!stack_is_empty(k)) {
    printf("%d\n",stack_top(k));
    stack_pop(k);
  }
  stack_destroy(k);
}
