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

#include "cs136.h"


// bot_13(c) reads in an arbitrary number of characters. follow the ROT13 rules
//     the equivalent ROT13 character is printed
// effects: read inputs
//          prints output
char bot_13(char c){
  if ((c >= 'a') && (c <= 'm')) {
    return c + 13;
  } else if ((c >= 'n')&&(c<='z')){
    return c - 13;
  } else if ((c >= 'A')&&(c<='M')){
    return c + 13;
  } else if ((c >= 'N')&&(c<='Z')){
    return c - 13;
  } else{
    return c;
  }
}


int main(void) {
  while(1){
    char c = read_char(false);
    if (c == READ_CHAR_FAIL ) {
      break;
    }
    printf("%c", bot_13(c));
  }}
  

