#include <stdio.h>

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

int recursiveBinarySearch (int A[],int start, int end, int x) {
  if (start <= end) {
    int mid = start + (end - start)/2;
    
    if (x == A[mid]) {
      return mid;
    }

    if (x < A[mid]) { 
      end = mid - 1;
    } else {
      start = mid + 1;
    }

    return recursiveBinarySearch(A, start, end, x);
  }

  return -1;
}

int main() {
  int A[] = {2, 4, 5, 7, 10, 15, 20, 40, 55};
  //         0  1  2  3  4   5   6   7   8

  int num = 15;
  int index = binarySearch(A, 9, num);
 
  printf("%d %d\n", index, rIndex);

  return 0;
}

int main()
{
  int n,m;

  scanf("%d%d", &n,&m);

  int A[n], i, B[m];

  for (i = 0; i < n; i++)
    scanf("%d", &A[i]);

  for (i = 0; i < m; i++)
    scanf("%d", &B[i]);

  int index = binarySearch(A, 9, num);

  for (i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");

  return 0;
}