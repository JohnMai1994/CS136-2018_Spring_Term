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
#include "array-eq.h"
#include <assert.h>

// number_is_prime(num) determine the num is the prime number or not
// require: num >=0
bool number_is_prime(int num){
  assert(num >= 0);
  if (num <= 1) {
    return false;
  }
  for (int i = num-1; i>1; --i) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

// divisors_prime(k) determine the number of divisors in the number k are the 
//   prime number
// requires: k>= 0
int divisors_prime(int k){
  assert(k >= 0);
  int sum = 0;
  if (k ==0) {
    return sum;
  } 
  for (int i = 1; i<=k; ++i) {
    if ((k%i == 0) && (number_is_prime(i))) {
       sum += 1;
       }
    }
  return sum;
}

// number_of_prime_divisors(a[], len) mutate the array a and replace the number
//   of distinct prime divisors of its index
// requires: a[] is vaild
//           len>=0
// effect: a[] have been mutated
void number_of_prime_divisors(int a[], int len){
  // Your code goes here
  assert(len >0);
  assert(a);
  for (int k = 0; k < len; ++k){
    a[k] = divisors_prime(k);
  }
}


int main(void) {
  assert(number_is_prime(2) == true);
  assert(divisors_prime(2)==1);
  int a[8] = {0};
  int ans[8] = {0,0,1,1,1,1,2,1};
  number_of_prime_divisors(a, 8);
  assert(array_equal(a, ans, 8));
  
  int b[13] = {0};
  int bns[13] = {0,0,1,1,1,1,2,1,1,1,2,1,2};
  number_of_prime_divisors(b, 8);
  assert(array_equal(b, bns, 8));
}
