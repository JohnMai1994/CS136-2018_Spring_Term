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

#include "passcheck.h"
#include "cs136-trace.h"
#include <assert.h>
#include <string.h>

////////////////////////////////////
// do not modify the following line:
const int MIN_PASSWORD_LENGTH = 8;
////////////////////////////////////

bool is_valid_password(const char *s){
  assert(s);
  if (strlen(s) < MIN_PASSWORD_LENGTH) return false;
  int upper_num =0;
  int lower_num =0;
  int digit=0;
  int special_num=0;
  int i = 0;
  while (i <= MIN_PASSWORD_LENGTH){
    if (('A' <= s[i]) &&  (s[i] <='Z')) {
      ++upper_num;
      ++i;
      continue;
    } else if(('a' <= s[i]) &&  (s[i] <='z')){
     ++lower_num;
      ++i;
      continue;
    } else if(('0' <= s[i]) &&  (s[i] <='9')){
     ++digit;
      ++i;
      continue;
    } else if ((33 <= s[i]) &&  (s[i] <=126)){
     ++special_num;
      ++i;
      continue;
    } else{
      break;
    }
  }
  if ((upper_num>= 1) && (lower_num >= 1) && (digit >= 1) && (special_num >=1)){
    return true;
  }
  return false;
}

