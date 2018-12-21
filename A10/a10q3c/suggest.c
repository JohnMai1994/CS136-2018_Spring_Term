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
#include "suggest.h"
#include <string.h>
#include "cs136-trace.h"
#include <stdio.h>
#include <assert.h>

// deletion (int pos, const char* string) return the character pointer
//   that delete the position in the pos place
// require: it should be free by client

char* deletion (int pos, const char* string){
  int len = strlen(string);
  char *r = malloc((len+1) * sizeof(char));
  strcpy(r, string);
  for (int i = pos; i<len; ++i) {
    r[i] = r[i+1];
  }
  return r;
}

// insertion(int pos, char character, const char *string) return the character
//   array pointer that insert an extra character in pos position
// require: it should be free by client
char *insertion(int pos, char character, const char *string){
  int len = strlen(string) +2;
  int k = 0;
  char *r = malloc(len * sizeof(char));
  r[pos] = character;
  for (int i = 0; i < len; ++i) {
    if (i == pos) continue; 
    r[i] = string[k++];
  }
  return r;
}
// substitutions(int pos, char character, const char * string) return the 
//    character array pointer that substitution the charater in pos position
//    to character
// require: it should be free by client
char * substitutions(int pos, char character, const char * string){
  int len = strlen(string);
  char *r =  malloc((len+1) * sizeof(char));
  strcpy(r, string);
  r[pos] = character;
  return r;
}

// swap(int pos, const char * string) return the character array pointer that
//    swap the character in pos and pos+1
// require: it should be free by client
char * swap(int pos, const char * string){
  int len = strlen(string);
  char *r =  malloc((len+1) * sizeof(char));
  strcpy(r, string);
  char tmp = r[pos];
  r[pos] = r[pos+1];
  r[pos+1] = tmp;
  return r;
}

struct wordlist *suggest(const char *s,
                         bool (*is_word)(const char *)) {
  struct wordlist *correct = wordlist_create();
  assert(s);
  int len = strlen(s);

  // single deletions
  for (int pos = 0; pos < len; ++pos){
    char *str = deletion(pos, s);
    if (is_word(str)){
      wordlist_add(str, correct);
    }
    free(str);
  }
  // single insertions
  for (int pos = 0; pos< len; ++pos){
    for (int c = 'a'; c <= 'z'; ++c){
      char *str = insertion(pos,c,s);
      if (is_word(str)){
        wordlist_add(str, correct);
      }
      free(str);
    }
  }
  // single substitutions
  for (int pos = 0; pos<len; ++pos){
    for (int c = 'a'; c<= 'z'; ++c){
      char *str = substitutions(pos, c, s);
      if (is_word(str)){
        wordlist_add(str, correct); 
      }
      free(str);
    }
  }
  // adjacent swaps
  if (strlen(s) >= 2){
    for (int pos = 0; pos < len-1; ++pos){
      char *str = swap(pos, s);
      if (is_word(str)){
        wordlist_add(str, correct); 
      }
      free(str);
    }
  }
  if (is_word(s)) {
     wordlist_remove(s, correct); 
  }

  return correct;
}

