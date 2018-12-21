#include <assert.h>
#include "passcheck.h"

// simple test for passcheck

int main(void){
  assert(is_valid_password("Tru$tNo1"));
  assert(is_valid_password("12345)Ft"));
  assert(is_valid_password("12341245") == false);
  assert(is_valid_password("abceAB12") == false);
  assert(is_valid_password("abceAB\n123") == false);
   assert(is_valid_password("aBc*B123") == true);
}
