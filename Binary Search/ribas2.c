#include <stdio.h>
#include <stdlib.h>
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

void merge(Item *V, int l, int m, int r)
{
  Item *R = malloc(sizeof(Item) * (r - l + 1));
  int i = l, j = m + 1, k = 0;

  while (i <= m && j <= r)
  {
    if (lesseq(V[i], V[j]))
      R[k++] = V[i++];
    else
      R[k++] = V[j++];
  }

  while (i <= m)
    R[k++] = V[i++];
  while (j <= r)
    R[k++] = V[j++];

  k = 0;
  for (i = l; i <= r; i++)
    V[i] = R[k++];
  free(R);
}

void mergesort(Item *V, int l, int r)
{
  if (l >= r)
    return;
  int meio = (l + r) / 2;
  mergesort(V, l, meio);
  mergesort(V, meio + 1, r);
  merge(V, l, meio, r);
}

int binarySearch(int A[], int n, int x)
{
  int start = 0, end = n - 1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2; // (start + end)/2 might overflow

    if (x == A[mid])
    {
      return mid;
    }

    if (x < A[mid])
    {
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }

  return -1; // Not found
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  int A[n], i, B[m], C[n];

  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
    C[i] = A[i];
  }
  for (i = 0; i < m; i++)
  {
    scanf("%d", &B[i]);
  }
  mergesort(A, 0, n - 1);
  int t;
  for (i = 0; i < m; i++)
  {
    t = binarySearch(A, n, B[i]);
    if (t != -1)
    {
      for (int j = 0; j < n; j++)
      {
        if (B[i] == C[j])
        {
          printf("%d\n", j);
        }
      }
    }
    else
    {
      printf("%d\n", t);
    }
  }
}