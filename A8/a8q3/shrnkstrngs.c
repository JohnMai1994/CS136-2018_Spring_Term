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
#include "shrnkstrngs.h"
#include <assert.h>


void remove_whitespace(char *s) {
  assert(s);
  int count = 0;
  for (int i = 0; s[i]; ++i) {
    if (s[i] != ' '){
       s[count] = s[i];
       ++count;
    }
  }
  s[count] = '\0';
}


void remove_char(char *s, char c) {
  assert(s);
  int count = 0;
  for (int i = 0; s[i]; ++i) {
    if (s[i] != c){
       s[count] = s[i];
       ++count;
    }
  }
  s[count] = '\0';
}


void remove_chars(char *s, const char *remove) {
  assert(s);
  for (int i = 0; remove[i]; ++i) {
     remove_char(s, remove[i]); 
  }
    
  
  
}
