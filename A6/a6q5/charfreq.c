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
#include "charfreq.h"
#include <stdio.h>

void charfreq(int freqs[]) {
  char a;
  while (1) {
    int end_read_in = scanf("%c", &a);
    if (end_read_in != 1) {
      break;
    }
    
    if ((a >= 'A') && (a <= 'Z')) {
      int position = a - 'A' +1;
      ++freqs[position];
    } else if ((a >= 'a') && (a <= 'z')) {
      int position = a - 'a' +1;
      ++freqs[position];
    } else {
      ++freqs[0];
    }
  }   
}

