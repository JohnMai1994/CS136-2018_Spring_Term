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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void overwrite(char *s1, const char *s2){ 
  assert(s1);
  assert(s2);
  while (*s2) {
    *s1 = *s2;
    ++s1;
    ++s2;
  }
  *s1 = '\0';   
}


int main(void) {
  char lexi[99] = {0};
  char first[99] = {0};
  char last[99] = {0};
  
  while(1) {
    int stop = scanf("%s", lexi);
    if (stop <= 0) {
     break; 
    }
    if (first[0] == 0) {
      overwrite(first,lexi) ;
    } else if (strcmp(first, lexi) > 0){
      overwrite(first, lexi);
      
    } 
    if (strcmp(last, lexi) < 0){
      overwrite(last, lexi);
    }
  }
  if (lexi[0] == 0){
    printf("NO STRINGS\n");
  } else{
    printf("%s %s\n", first, last);
  }
  
  
}
