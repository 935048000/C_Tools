#include <stdio.h>

void quicksort(int *A, int len);

int main (void) {
  int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
  int n = sizeof a / sizeof a[0];

  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  quicksort(a, n);

  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
