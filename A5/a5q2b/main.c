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

// read_and_calc_stats(sum, mean, var) mutate the contents of their
//   pointers through sum mean and variance different calcuation methods
// effects: modifies *sum, *mean, *var
int read_and_calc_stats(int *sum, double *mean, double *var) {
  int a;
  int first_input = scanf("%d", &a);
  if (first_input != 1){
    return 0;
  }
  *sum = a;
  *mean = a;
  int member = a*a;
  int total_number = 1;
  
  while(1) {
    int i;
    int input = scanf("%d", &i);
    if (input != 1){
      break;
    }
    ++total_number;
    (*sum) += i;
    (*mean) = (*sum)/ total_number;
    int double_i = (i * i);
    member += double_i;
    int denominator = (total_number);
    (*var) = member / denominator -((*mean) * (*mean));
  }
  return total_number;
      
}


// For our simple test, we use low accuracy (i.e.: two decimal places)
// Which is also likely sufficient for your own tests

int main(void) {
  int sum = 0;
  double mean = 0;
  double var = 0;
  int count = read_and_calc_stats(&sum, &mean, &var);
  printf("sum = %d\n", sum);
  printf("mean = %.2f\n", mean);
  printf("variance = %.2f\n", var);
  printf("count = %d\n", count);
}
