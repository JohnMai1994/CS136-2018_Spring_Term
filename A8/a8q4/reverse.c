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
#include "reverse.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>



void reverse(char *s) {
  assert(s);
  int length = strlen(s);
  char *p;
  p = s;
  char tmp;
  for (int i = 0; i < length/2; ++i){
      tmp = p[i];
    p[i] = p[length -i -1];
    p[length-i-1] = tmp;
  }
}


void reverse_helper(char *begin, char *end){
  char temp;
  while (begin < end) {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
 


void reverse_words(char *s) {
  assert(s);
  char *word_begin = s;
  char *temp = s;
  while(*temp) {
    temp++;
    if (*temp == '\0'){
      reverse_helper(word_begin, temp-1);
    } else if (*temp == ' '){
      reverse_helper(word_begin, temp-1);
      word_begin = temp +1;
    }
  }
  reverse_helper(s, temp-1);
}
