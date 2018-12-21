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

// my_pow(n,k) produce the number of n to the power of k 
// requires: k >= 0
int my_pow(int n, int k) {
  int	pow = 1;
  int	result = 1;
  if (k == 0)
    return 1;
  while (pow <= k){
      result *= n;
      ++pow;
    }
  return result;
}

// count_digits(n) produce the number by counting digits of n
// requires: n >= 0
int count_digits(int n) {
  int count = 1;
  while (n/10 > 0){
    ++count;
    n = n/10;
  }
  return count;
}

// is_prime(n) determine the number n is prime number
// requires: n >= 2
bool is_prime(int n) {
  if (n <= 1){
    return false;
  }
  int k = 2;
  while (k <= n){
    if (n%k != 0) {
      return true;
      ++k;
      break;
    }
    if (n%k == 0){
      if (n == k){
        return true;
        break;
      }
      return false;
    }
  }
  return false;
}

// fibonacci(n) produce the number the at n fibonacci position
// requires: n >= 0
int fibonacci(int n) {
  if (n <= 2) {
    return 1;
  }
  int k = 2;
  int a = 1;
  int b = 1;
  while (k < n){
    int c = b;
    b = a+b;
    a = c;
    ++k;
  }
  return b;
}

// reverse_digits(n) produce the number at the reverse order of n
// requires: n >= 0
int reverse_digits(int n) {
  int remainder = 0;
  int reversedigits = 0;
  int k = count_digits(n);
  while (k>0){
    remainder = n%10;
    reversedigits = reversedigits*10 + remainder;
    n = n/10;
    --k;
  }
  return reversedigits;
}


int main(void) {
  assert(my_pow(1, 1) == 1);  
  assert(my_pow(5,5)== 3125);
  assert(my_pow(2,3)== 8);
  assert(count_digits(0) == 1);
  assert(count_digits(123) == 3);
  assert(count_digits(1234) == 4);
  assert(count_digits(10) == 2);
  assert(count_digits(6) == 1);
  assert(is_prime(2));
  assert(is_prime(10) == false);
  assert(is_prime(4) == false);
  assert(is_prime(5));
  assert(is_prime(11));
  assert(fibonacci(1) == 1);
  assert(fibonacci(4) == 3);
  assert(fibonacci(6) == 8);
  assert(reverse_digits(1) == 1);
  assert(reverse_digits(312) == 213);
  assert(reverse_digits(1990) == 991);
}
