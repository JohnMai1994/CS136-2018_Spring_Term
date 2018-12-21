#include "array-eq.h"

bool array_equal(const int a[], const int b[], int len) {
  for(int i = 0; i < len; ++i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}
