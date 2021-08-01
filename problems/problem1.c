#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pair
{
  char value[20];
  int key;
};

void merge(struct Pair *V, int l, int m, int r)
{

  struct Pair *R = malloc(sizeof(struct Pair) * (r - l + 1));
  int i = l, j = m + 1, k = 0;

  while (i <= m && j <= r)
  {
    if (V[i].key <= V[j].key)
    {
      R[k].key = V[i].key;
      strcpy(R[k].value, V[i].value);
      k++;
      i++;
    }

    else
    {
      R[k].key = V[j].key;
      strcpy(R[k].value, V[j].value);

      k++;
      j++;
    }
  }

  while (i <= m)
  {
    R[k].key = V[i].key;
    strcpy(R[k].value, V[i].value);
    k++;
    i++;
  }

  while (j <= r)
  {
    R[k].key = V[j].key;
    strcpy(R[k].value, V[j].value);
    k++;
    j++;
  }

  k = 0;
  for (i = l; i <= r; i++)
  {

    V[i].key = R[k].key;
    strcpy(V[i].value, R[k].value);
    k++;
  }

  free(R);
}

void mergesort(struct Pair *V, int l, int r)
{

  if (l >= r)
    return;
  int meio = (l + r) / 2;
  mergesort(V, l, meio);
  mergesort(V, meio + 1, r);
  merge(V, l, meio, r);
}

int binarySearch(struct Pair A[], int n, int x)
{
  int start = 0, end = n;

  while (start <= end)
  {
    int mid = start + (end - start) / 2; // (start + end)/2 might overflow

    if (x == A[mid].key)
    {
      return mid;
    }

    if (x < A[mid].key)
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

void main()
{
  int n;
  scanf("%d", &n);
  struct Pair pairs[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d%s", &pairs[i].key, &pairs[i].value);
  }

  int A[100000];
  int c = 0;

  while (scanf("%d", &A[c]) != EOF)
    c++;

  mergesort(pairs, 0, n - 1);

  int index;
  for (int i = 0; i < c; i++)
  {
    index = binarySearch(pairs, n - 1, A[i]);
    if (index == -1)
      printf("undefined\n");
    else
      printf("%s\n", pairs[index].value);
  }
}