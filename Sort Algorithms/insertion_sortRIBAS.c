#include <stdio.h>
// stable and adaptive
// O(n^2)
void insertionSort(int A[], int l, int r)
{
  int x;
  for (int i = l + 1; i < r; i++)
  {
    int j = i - 1;
    x = A[i];

    while (A[j] > x && j > -1)
    {
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = x;
  }
}

int main()
{
  int A[1000];
  int i = 0;

  while (scanf("%d", &A[i]) != EOF)
    i++;

  insertionSort(A, 0, i);

  for (int j = 0; j < i; j++)
  {
    printf("%d ", A[j]);
  }

  return 0;
}