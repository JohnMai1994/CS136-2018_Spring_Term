#include <stdio.h>
#include "desll.h"
#include <assert.h>
#include "cs136-trace.h"

// check_result(result) returns false if result is 1
//   otherwise true
// effects: prints a message
bool check_result(int result) {
  if (result != 1) {
    printf("Something went wrong, bad input!\n");
    return true;
  }
  return false;
}

int main(void) {
  char c;
  int n;
  struct destack *des;

  des = destack_create();
  while(1) {
    if (check_result(scanf(" %c", &c))) break;

    // You should add more cases here for I/O testing
    if (c == 'p') { // push
      if (check_result(scanf(" %c", &c))) break;
      if (check_result(scanf("%d", &n))) break;
      if (c == 't') {
        destack_push_top(n, des);
      } else if (c == 'b') {
        destack_push_bot(n, des);
      } else {
        printf("Invalid parameter for PUSH operation.\n");
        continue;
      }
    } else if (c == 'z') {
      if (check_result(scanf(" %c", &c))) break;
      if (c == 't') {
        trace_int(destack_pop_top(des));
      } else if (c == 'b') {
        trace_int(destack_pop_bot(des));
      } else {
        printf("Invalid parameter for PUSH operation.\n");
        continue;
      }

    }else if (c == 'r') { // print
      destack_print(des);
    } else if (c == 'q') { // quit
      break;
    } else {
      printf("Invalid operation request.\n");
      continue;
    }
  }
  destack_destroy(des);
}
