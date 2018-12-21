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

#include <stdlib.h>
#include "cs136-trace.h"
#include "ddoouubbllee.h"
#include <string.h>
#include <assert.h>

char* ddoouubbllee(const char* s) {
  assert(s);
  int len = strlen(s);
  int maxlen = 2*len;
  char *str = malloc(maxlen* sizeof(char));
  for (int k = 0; k < len; ++k) {
    str[2*k] = s[k];
    str[2*k+1] = s[k];
  }
  str = realloc(str, (maxlen+1)*sizeof(char));
  str[maxlen] = '\0';
  return str;
    
    
  }


