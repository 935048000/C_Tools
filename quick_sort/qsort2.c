void quicksort2(int *A, int len) {
  if (len < 2) return;

  int pivot = A[len / 2];

  int i, j;
  for (i = 0, j = len - 1; ; i++, j--) {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;

    if (i >= j) break;

    int temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }

  quicksort2(A, i);
  quicksort2(A + i, len - i);
}

//Output:
//4 65 2 -31 0 99 2 83 782 1
//-31 0 1 2 2 4 65 83 99 782
//Randomized sort with separated components.