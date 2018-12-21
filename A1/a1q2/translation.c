#include "cs136.h"

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


bool pay_duty1(int duration, int goods, bool alcohol, bool diplomat) {
  if (diplomat == true) {
    return false;
  } else if (duration < 24) {
    return (goods > 0);
  } else if (duration >= 48) {
    return (goods > 800);
  } else if (goods <= 200) {
    return alcohol;
  } else {
    return true;
  }
}


bool pay_duty2(int duration, int goods, bool alcohol, bool diplomat) {
  return (diplomat == false) && 
    (((duration < 24) && (goods > 0)) ||
     ((duration < 48) && 
      ((goods > 200) || alcohol)) ||
     (goods > 800));
}


int my_pow(int n, int k) {
  if (k == 0) {
    return 1;
  } else {
    return (n * my_pow(n, (k-1)));
  }
}


int count_digits(int n) {
  if (n < 10) {
    return 1;
  } else {
    return 1 + count_digits(n / 10);
  }
}


bool is_prime_core(int k, int n) {
  if (k == 1) {
    return true;
  } else if ((n % k) == 0) {
    return false;
  } else {
    return is_prime_core((k-1), n);
  }
}


bool is_prime(int n) {
  return is_prime_core ((n-1), n);
}


int fibonacci_countup(int f2, int f1, int k, int n) {
  if (k == n) {
    return (f2 + f1);
  } else {
    return fibonacci_countup(f1, (f2 + f1), (k +1), n);
  }
}


int fibonacci(int n) {
  if (n < 2) {
    return n;
  } else {
    return fibonacci_countup(0, 1, 2, n);
  }
}


int reverse_digits(int n) {
  if (n == 0) {
    return 0;
  } else {
    return (n % 10) * my_pow(10, (count_digits(n)-1)) + 
      reverse_digits(n / 10);
  }
}


int median3(int a, int b, int c) {
  if (((a <= b) && (a >= c)) || ((a >= b) && (a <= c))) {
    return a;
  } else if (((b <= a) && (b >= c)) || ((b >= a) && (b <= c))) {
    return b;
  } else {
    return c;
  }
}


int main(void) {
  assert(pay_duty1(1, 1, false, false));
  assert(pay_duty2(1, 1, false, false) == 
         pay_duty1(1, 1, false, false));
  assert(my_pow(1, 1) == 1);  
  assert(count_digits(0) == 1);
  assert(is_prime(2));
  assert(fibonacci(1) == 1);
  assert(reverse_digits(1) == 1);
  assert(median3(1, 1, 1) == 1);
  // add more asserts below to test your code
  // pay_duty1
  assert(pay_duty1(1,2,false, true) == false);
  assert(pay_duty1(23,-1,false, false) == false );
  assert(pay_duty1(23,5,false, false));
  assert(pay_duty1(55,100,false, false) == false );
  assert(pay_duty1(55,805,false, false) == true);
  assert(pay_duty1(35,205,true, false));
  assert(pay_duty1(35,150,false, false) == false);
  // pay_duty2
  assert(pay_duty2(1,2,false, true) == false);
  assert(pay_duty2(23,-1,false, false) == false );
  assert(pay_duty2(23,5,false, false));
  assert(pay_duty2(55,100,false, false) == false );
  assert(pay_duty2(55,805,false, false) == true);
  assert(pay_duty2(35,205,true, false));
  assert(pay_duty2(35,150,false, false) == false);
  // my_pow
  assert(my_pow(1, 0) == 1);
  assert(my_pow(6, 2) == 36);
  //count_digits
  assert(count_digits(1234) == 4);
  assert(count_digits(15) == 2);
  assert(count_digits(5) == 1);
  //is-prime
  assert(is_prime(3));
  assert(is_prime(13));
  assert(is_prime(12) == false);
  assert(is_prime(39)== false);
  assert(is_prime(37));
  //fibonacci
  assert(fibonacci(2) == 1);
  assert(fibonacci(3) == 2);
  assert(fibonacci(4) == 3);
  assert(fibonacci(5) == 5);
  assert(fibonacci(6) == 8);
  //reverse-digits
  assert(reverse_digits(7) == 7);
  assert(reverse_digits(10) == 1);
  assert(reverse_digits(0) == 0);
  assert(reverse_digits(1100) == 11);
  assert(reverse_digits(11530) == 3511);
  //median3
  assert(median3(1, 5, 7) == 5);
  assert(median3(5, 1, 7) == 5);
  assert(median3(5, 5, 7) == 5);
  assert(median3(5, 5, 5) == 5);
  assert(median3(-5, 5, 0) == 0);
  assert(median3(-1, 8, 7) == 7);
  
}
