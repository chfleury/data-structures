#include <stdio.h>
// stable and adaptive
// O(n^2)
void swap(int *x, int *y)
{
  int t = *x;
  *x = *y;
  *y = t;
}

void bubbleSort(int A[], int l, int r)
{
  int flag;

  for (int i = l; i < r - 1; i++)
  {
    flag = 0;

    for (int j = l; j < r - 1 - i; j++)
    {
      if (A[j] > A[j + 1])
      {

        swap(&A[j], &A[j + 1]);
        flag = 1;
      }
    }
    // if it didn't make any swap the array is already sorted so it breaks the for loop (i)
    if (!flag)
    {
      break;
    }
  }
}

int main()
{
  int A[1000];
  int i = 0;

  while (scanf("%d", &A[i]) != EOF)
    i++;

   bubbleSort(A, 0, i);

  for (int j = 0; j < i; j++)
  {
    printf("%d ", A[j]);
  }

  return 0;
}