void quicksort3(int A[], int p, int q) {
  if(p < q) {
    int pivotIndx = partition(A, p, q);

    quicksort3(A, p, pivotIndx - 1);
    quicksort3(A, pivotIndx + 1, q);
  }
}