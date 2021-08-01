#include <stdio.h>

#define less(A, B) ((A) < (B))
#define lesseq(A, B) ((A) <= (B))
#define exch(A, B) \
  {                \
    int t;         \
    t = A;         \
    A = B;         \
    B = t;         \
  }
#define cmpexch(A, B) \
  {                   \
    if (less(B, A))   \
      exch(A, B);     \
  }

void bubblesort(int v[], int l, int r)
{
  for (int i = l; i < r - 1; i++)
    for (int j = l; j < r - 1 - i; j++)
      cmpexch(v[j], v[j + 1]);
}

int main()
{
  int A[1000];
  int i = 0;

  while (scanf("%d", &A[i]) != EOF)
    i++;

  bubblesort(A, 0, i);

  for (int j = 0; j < i; j++)
  {
    printf("%d ", A[j]);
  }

  return 0;
}