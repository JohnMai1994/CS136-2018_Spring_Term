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

#include "rotten.h"
#include <assert.h>


bool is_exist(char head, char *array[], const int num_array, int position) {
   for(int i = 0; i< num_array; ++i){
      if (head == array[i][position]){
         return true; 
      }
   }
  return false;
}

bool is_fresh(char *review[], const int review_length, 
              char *positive[], const int num_positive, 
              char *negative[], const int num_negative) {
  assert(review);
  assert(positive);
  assert(negative);
  assert(review_length >0);
  assert(num_positive >= 0);
  assert(num_negative >= 0);
  
  int number_of_positive = 0;
  int number_of_negative = 0;
  
  if (num_negative == 0) return true;
  if (num_positive == 0) return false;
 
  
  for (int i = 0; i < review_length; ++i){
    int review_posi = 0; 
    if (is_exist(review[i][review_posi], positive, num_positive, 0)) {
      for (int j = 0; j < num_positive; ++j){
        if (strcmp(review[i], positive[j]) == 0) {
           ++number_of_positive; 
        }
      } 
    }
    
    if (is_exist(review[i][review_posi], negative, num_negative, 0)){
      for (int k = 0; k < num_negative; ++k){
        if (strcmp(review[i], negative[k]) == 0) {
           ++number_of_negative; 
        }
      }
    }
  }

  if ((number_of_positive >= 2* number_of_negative)||
      (number_of_positive == 0)){  
    return true; 
  }      
  return false;
}
