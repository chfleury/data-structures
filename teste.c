#include <stdio.h>
#include <stdlib.h>
int repetido = 0;

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

void insertionSort(int A[], int x, int j)
{
  --j;
  while (A[j] > x && j > -1)
  {
    A[j + 1] = A[j];
    j--;
  }

  A[j + 1] = x;
}

int Merge(int A[], int l, int mid, int h)
{
  int i = l, j = mid + 1, k = l;
  int B[132000];
  while (i <= mid && j <= h)
  {
    if (A[i] < A[j])
    {
      B[k++] = A[i++];
    }
    // checando para tirar os elementos repetidos
    else if (A[i] == A[j])
    {
      B[k++] = A[i++];
      B[k++] = -918472194;
      ++j;
      repetido += 1;
    }

    else
    {
      B[k++] = A[j++];
    }
  }

  for (; i <= mid; i++)
    B[k++] = A[i];
  for (; j <= h; j++)
    B[k++] = A[j];

  for (i = l; i <= h; i++)
    A[i] = B[i];
}

//l h = low high como se fosse left e right
int MergeSort(int A[], int l, int h)
{
  int mid;
  if (l < h)
  {
    mid = (l + h) / 2;
    MergeSort(A, l, mid);
    MergeSort(A, mid + 1, h);
    Merge(A, l, mid, h);
  }
}
int main()
{

  int n;
  scanf("%d\n", &n);
  int A[2 * n];
  int i;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  MergeSort(A, 0, n - 1);

  int tamanho = n - repetido;

  if (tamanho % 2 != 0)
  {
    n++;
    tamanho++;
    A[n - 1] = 1000000000;
  }

  int j = 0;
  int x = 0;
  int tmp = 0;
  for (i = 0; i < n; i++)
  {
    if (A[i] != -918472194)
    {
      tmp += A[i];

      x++;
      if (x == 2)
      {

        if (binarySearch(A, n, tmp) == -1)
        {
          insertionSort(A, tmp, n);
          n += 1;
          tamanho += 1;
        }
        j++;
        x = 0;

        tmp = 0;
      }
    }
    else
    {
    }
  }
  tmp = 4;
  // printf("teste\n");

  // for(i= 0 ; i<n; i++){
  //   printf("%d ", A[i]);
  // }

  for (i = 0; i < n; i++)
  {
    if (tmp == 4 && A[i] != -918472194)
    {
      printf("%d\n", A[i]);
      tmp = 0;
    }
    else
    {
      tmp++;
    }
  }

  printf("Elementos: %d", tamanho);
  printf("\n");
  return 0;
}