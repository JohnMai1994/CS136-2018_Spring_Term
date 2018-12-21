#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minheap.h"

// a simple I/O-based test client for minheap:


// pretty_print(a, len) pretty prints an array a
void pretty_print(int a[], int len) {
  if (len <= 0) {
    printf("[empty]\n");
  } else {
    printf("[%d", a[0]);
    for (int i = 1; i < len; ++i) {
      printf(",%d", a[i]);
    }
    printf("]\n");  
  }
}


int main(void) {
  struct minheap *h = minheap_create();
  assert(h);
  
  char command[11];
  int n = 0;
  while (scanf("%s", command) == 1 && strcmp(command, "exit")) {
    if (!strcmp(command,"add")) {
      assert(scanf("%d", &n) == 1);
      minheap_insert(n, h);
    } else if (!strcmp(command, "remove")) {
      if (minheap_is_empty(h)) {
        printf("remove error: empty\n");
      } else {
        printf("remove: %d\n", minheap_remove(h));
      }
    } else if (!strcmp(command, "top")) {
      if (minheap_is_empty(h)) {
        printf("top error: empty\n");
      } else {
        printf("top: %d\n", minheap_top(h));
      }
    } else if (!strcmp(command, "print")) {
      pretty_print(h->data, h->len);
    } else if (!strcmp(command, "sort")) {
      assert(scanf("%d", &n) == 1);
      assert(n > 0);
      int *arr = malloc(n * sizeof(int));
      for (int i = 0; i < n; ++i) {
        assert(scanf("%d", arr + i) == 1);
      }
      heapsort(arr, n);
      pretty_print(arr, n);
      free(arr);
    } else {
      printf("unexpected command: %s\n", command);
      break;
    }
  }
  
  minheap_destroy(h);
}
