#include <stdio.h>
// stable and adaptive
// O(n^2) 
void insertionSort(int A[], int n) {
  int x;
  for(int i =1; i<n;i++) {
    int j = i - 1;
    x = A[i];

    while(A[j] > x && j > -1) {
      A[j+1] = A[j];
      j--;
    }

    A[j+1] = x;
  }
}
 

int main () {
  int A[] = {2, 1, 8, 3, 4, 7, 6, 5};

  insertionSort(A, 8);
  for (int i = 0; i<8; i++) {
    printf("%d ", A[i]);
  }

  return 0;
}