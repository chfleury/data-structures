#include <stdio.h>
// not stable nor adaptive
// O(n^2)

void swap(int *x, int *y)
{
  int t = *x;
  *x = *y;
  *y = t;
}

void selectionSort(int A[], int l, int r)
{
  for (int i = l; i < r - 1; i++)
  {
    int x = i;
    for (int j = i; j < r; j++)
    {
      if (A[j] < A[x])
      {
        x = j;
      }
    }
    swap(&A[x], &A[i]);
  }
}

int main()
{
  int A[1000];
  int i = 0;

  while (scanf("%d", &A[i]) != EOF)
    i++;

  selectionSort(A, 0, i);

  for (int j = 0; j < i; j++)
  {
    printf("%d ", A[j]);
  }

  return 0;
}