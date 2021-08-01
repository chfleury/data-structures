#include <stdio.h>

typedef int Item;
#define less(A, B) ((A) < (B))
#define lesseq(A, B) ((A) <= (B))
#define exch(A, B) \
  {                \
    Item t;        \
    t = A;         \
    A = B;         \
    B = t;         \
  }
#define cmpexch(A, B) \
  {                   \
    if (less(B, A))   \
      exch(A, B);     \
  }

void insertionSort(Item *v, int l, int r)
{
  for (int i = r; i > l; i--)
    cmpexch(v[i - i], v[i]);

  for (int i = l + 2; i <= r; i++)
  {
    int j = i;
    Item tmp = v[j];
    while (less(tmp, v[j - 1]))
    {
      v[j] = v[j - 1];
      j--;
    }
    v[j] = tmp;
  }
}

int main()
{
  Item A[50000];
  int i = 0;

  while (scanf("%d", &A[i]) != EOF)
    i++;

  insertionSort(A, 0, i - 1);

  for (int j = 0; j < i; j++)
  {
    printf("%d ", A[j]);
  }

  return 0;
}