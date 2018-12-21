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
#include "patterns.h"
#include <stdio.h>

int main(void) {
  char i = 'a';
  while (1) {
    int k = scanf(" %c", &i);
    if(k!=1){
      break;
    }
    if (i == 't') {
      int a ;
      scanf("%d", &a);
      star_triangle(a);
      printf("\n");
    } else if (i == 'T') {
      int a ;
      scanf("%d", &a);
      digit_triangle(a);
      printf("\n");
    } else if (i == 'd') {
      int a;
      scanf("%d", &a);
      star_diamond(a);
      printf("\n");
    } else if (i == 'r') {
      int a,b;
      scanf("%d", &a);
      scanf("%d", &b);
      star_rectangle(a,b);
      printf("\n");
    } else if (i == 'R') {
      int a,b;
      scanf("%d", &a);
      scanf("%d", &b);
      digit_rectangle(a,b);
      printf("\n");
    } else {
      break;
    }
  }
}