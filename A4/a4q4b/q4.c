#include "cs136.h"

// SEASHELL_READONLY

// This code doesn't do anything special.
// We just wanted some fun names (identifiers)

const int first_speaker = 8;
int elijah_baley = 2;

int daneel_olivaw(int d, int e) {
  printf("printing within daneel_olivaw(%d, %d)\n", d, e);
  int f = first_speaker - elijah_baley * 2;
  if (d >= 5) {
    return d * f;
  } else if (d <= 0) {
    return e * f;
  }
  return d - e;
}

int hari_seldon(int b, int acc) {
  printf("printing within hari_seldon(%d, %d)\n", b, acc);
  ++elijah_baley;
  const int y = first_speaker / elijah_baley;
  if (b > 0) {
    return hari_seldon(b - 2, acc + y);
  }
  return acc;
}

void the_mule(int a) {
  printf("printing within the_mule(%d)\n", a);
  int g = daneel_olivaw(4, 2) + hari_seldon(-1, 1);
  int k = 0;
  while (a > 0) {
    int t = g + k;
    a /= t;
    k++;
  }
  printf("the_mule is finished\n");
}

int main(void) {
  the_mule(30);
  int z = daneel_olivaw(-2, 2);
  printf("The return value of daneel_olivaw(-2, 2) is %d\n", z);
  int x = hari_seldon(3, 2);
  printf("printing within main(), x = %d\n", x);
}
