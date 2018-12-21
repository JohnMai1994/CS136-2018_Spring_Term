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

#include "cs136-trace.h"
#include "speak.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

void speak_io(const char *msg, const char *alphabet[]) {
  assert(msg);
  assert(alphabet[0] != NULL);
  
  int i;
  int len = strlen(msg);
  for(int k = 0; k < len; ++k) {
    i = msg[k];
    if ((i == 32)||(i == '\n')) continue;
    if (alphabet[i] == NULL) break;
    printf("%s ", alphabet[i]);
  }
  printf("Stop\n");
}

void speak_str(const char *msg, const char *alphabet[], char *s, int maxlen) {
  assert(msg);
  assert(alphabet[0] != NULL);
  assert(s);
  assert(maxlen>0);
  int i;

  int len = strlen(msg);
  int position = 0;
  for (int k = 0; k < len; ++k) {
    i = msg[k];
    if ((i == ' ')||(i == '\n')) continue;
    if (alphabet[i] == 0) break;
    int length = strlen(alphabet[i]);
    int z;
    for (z = 0; z < length; ++z){
      if (alphabet[i][z] == 0){
        break;
      }
      s[position++] =  alphabet[i][z]; 
    }
    s[position++] = ' '; 
  }
  int stop_len = strlen(alphabet[0]);
  for (int i=0; i <stop_len; ++i){
    if (alphabet[0][i] == 0){
        break;
      }
    s[position++] =  alphabet[0][i]; 
  }
  
}
