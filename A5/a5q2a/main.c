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

#include <stdio.h>
#include "cs136-trace.h"

// read_and_range(max, min, count_max, count_min) mutate the contents of their
//   pointers
// effests: modifies *max, *min, *count_max, *count_min
int read_and_range(int *max, int *min, int *count_max, int *count_min) {
  int a;
  int first_input = scanf("%d", &a);
  if (first_input != 1) {
   return 0; 
  }
  *max = a;
  *min = a;
  *count_max = 1;
  *count_min = 1;
  int total_num = 1;
  
  while(1) {
    int i = 0;
    int k = scanf("%d", &i);
    if (k != 1){
      break;
    }
    
    if (i < *min) {
      *min = i;
      *count_min = 1;
    } 
    if (i == *min) {
      (*count_min) += 1;
    } 
     
    if (i == *max) {
      (*count_max) += 1;
    } 
    if (i > *max){
      *max = i;
      *count_max = 1;
    } 
    ++total_num;
  }
  return total_num;
}


// There is no need to modify this main function

int main(void) {
  int min = 0;
  int max = 0;
  int count_min = 0;
  int count_max = 0;
  int count = read_and_range(&max, &min, &count_max, &count_min);
  printf("min = %d\n", min);
  printf("max = %d\n", max);
  printf("count_min = %d\n", count_min);
  printf("count_max = %d\n", count_max);
  printf("count = %d\n", count);
}
