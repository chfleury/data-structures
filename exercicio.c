#include <stdio.h>
// Christian fleury github: chfleury
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


int binarySearch (int A[], int n, int x) {
  int start = 0, end = n - 1;

  while (start <= end) {
    int mid = start + (end - start)/2; // (start + end)/2 might overflow 
    
    if (x == A[mid]) {
      return mid;
    }

    if (x < A[mid]) { 
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return -1; // Not found
}


int main () {
  int N;
  scanf("%d", &N);
  int A[N];

  for(int i = 0; i<N;i++){
    scanf("%d", &A[i]);
  }

  selectionSort(A, N);

  int tmp;
  while(scanf("%d", &tmp) == 1){
    scanf("%d", &tmp);

    binarySearch(A, N, tmp ) > 0 ? printf("sim\n"):printf("nao\n");
  }

 
  return 0;
}