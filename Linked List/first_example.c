#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} * first;

void create(int A[], int n)
{
  struct Node *last;

  if (!n)
  {
    return;
  }

  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;

  struct Node *t;
  for (int i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

void display(struct Node *p)
{
  while (p)
  {
    printf("%d ", p->data);
    p = p->next;
  }

  printf("\n");
}

void recursiveDisplay(struct Node *p)
{
  if (p)
  {
    printf("%d ", p->data);

    recursiveDisplay(p->next);
  }
  else
  {
    printf("\n");
  }
}

void backwardsRecursiveDisplay(struct Node *p)
{
  if (p)
  {
    backwardsRecursiveDisplay(p->next);

    printf("%d ", p->data);
  }
}

int lenght(struct Node *p)
{

  int c = 0;

  while (p)
  {
    c++;

    p = p->next;
  }

  return c;
}

int max(struct Node *p)
{
  int max = INT_MIN;

  while (p)
  {
    if (p->data > max)
    {
      max = p->data;
    }

    p = p->next;
  }

  return max;
}

int min(struct Node *p)
{
  int min = INT_MAX;

  while (p)
  {
    if (p->data < min)
    {
      min = p->data;
    }

    p = p->next;
  }

  return min;
}

void insert(struct Node *p, int index, int value)
{
  if (index < 0 || index > lenght(p))
    return;

  struct Node *t;
  t = malloc(sizeof(struct Node));
  t->data = value;

  if (index == 0)
  {
    t->next = first;
    first = t;
  }
  else
  {

    for (int i = 0; i < index - 1; i++)
    {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

void replace(struct Node *p, int x, int value)
{ // x is index to be inserted
  if (x < 0 || x > lenght(p))
    return;

  struct Node *t;
  t = malloc(sizeof(struct Node));
  t->data = value;

  if (x == 0)
  {
    t->next = first->next;
    first = t;
  }
  else
  {
    struct Node *q;

    for (int i = 0; i < x; i++)
    {
      q = p;
      p = p->next;
    }

    t->next = p->next;
    q->next = t;
  }
}

int main()
{
  int A[] = {3, 5, 6, 10, 16, 11};
  create(A, 6);

  printf("Loop Display: ");
  display(first);

  printf("Recursive Display: ");
  recursiveDisplay(first);

  printf("Backwards Recursive Display: ");
  backwardsRecursiveDisplay(first);
  printf("\n");

  printf("Lenght: %d\n", lenght(first));

  printf("Min: %d  Max: %d\n", min(first), max(first));

  insert(first, 0, 2);
  printf("Display after inserting 2 in first position: ");
  display(first);

  insert(first, 4, 1000000);
  printf("Display after inserting 1000000 in index 4: ");
  display(first);

  printf("Display after replacing element of index 4 for 9: ");
  replace(first, 4, 9);
  display(first);

  printf("Display after adding element 90 at the end of the list: ");
  insert(first, lenght(first), 90);
  display(first);

  return 0;
}