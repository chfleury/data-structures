#include <stdio.h>
// not stable nor adaptive
// O(n^2) 

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

void selectionSort(int A[], int n) {
  for(int i = 0; i<n - 1; i++) {
    int x = i;
    for(int j = i; j < n; j++) {
       if(A[j] < A[x]){
        x = j;
      }
    }
    swap(&A[x], &A[i]);
  }
}

int main () {
  int A[] = {2, 1, 8, 3, 4, 7, 6, 5};

  selectionSort(A, 8);

  for (int i = 0; i<8; i++) {
    printf("%d ", A[i]);
  }

  return 0;
}