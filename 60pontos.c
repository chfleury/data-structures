#include <stdio.h>
#include <stdlib.h>

struct Celula
{
  int dado;
  struct Celula *prox;
};

struct Celula *intercala(struct Celula *a, struct Celula *b)
{
  struct Celula *resultado = NULL;
  if (a == NULL)
    return b;
  else if (b == NULL)
    return a;
  if (a->dado <= b->dado)
  {
    resultado = a;
    resultado->prox = intercala(a->prox, b);
  }
  else
  {
    resultado = b;
    resultado->prox = intercala(a, b->prox);
  }
  return resultado;
}

void divide_lista(struct Celula *lista, struct Celula **inicio, struct Celula **fim)
{
  struct Celula *a = lista;
  struct Celula *b = lista->prox;
  while (b != NULL)
  {
    b = b->prox;
    if (b != NULL)
    {
      a = a->prox;
      b = b->prox;
    }
  }
  *inicio = lista;
  *fim = a->prox;
  a->prox = NULL;
}

void merge_sort(struct Celula **le)
{
  struct Celula *inicio = *le;
  struct Celula *a;
  struct Celula *b;
  if (inicio == NULL || inicio->prox == NULL)
    return;
  divide_lista(inicio, &a, &b);
  merge_sort(&a);
  merge_sort(&b);
  *le = intercala(a, b);
}

void imprime_intervalo(struct Celula *celula, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", celula->dado);
    celula = celula->prox;
  }
  printf("\n");
}

void adiciona_item(struct Celula **le, int novoDado)
{
  struct Celula *novaCelula = (struct Celula *)malloc(sizeof(struct Celula));
  novaCelula->dado = novoDado;
  novaCelula->prox = *le;
  *le = novaCelula;
}

void imprimeTudo(struct Celula *celula)
{
  while (celula != NULL)
  {
    printf("%d ", celula->dado);
    celula = celula->prox;
  }
}

void removeMaiorQueCem(struct Celula **celula)
{
  int count = 0;
  if (*celula != NULL)
  {
    if ((*celula)->prox == NULL)
    {
      *celula = NULL;
    }
    else
    {
      struct Celula *temp = *celula;
      while (temp->prox->prox != NULL)
      {
        temp = temp->prox;
        if (count > 150)
        {
          temp->prox = NULL;
          break;
        }
        count++;
      }
    }
  }
}

int main()
{
  struct Celula *listaPlacas = NULL;
  struct Celula *listaTemp = NULL;
  int op, aux, quantConsulta = 0;

  while (scanf("%d %d", &op, &aux) != EOF)
  {
    if (op == 1)
      adiciona_item(&listaTemp, aux);
    else if (op == 2)
    {
      merge_sort(&listaTemp);
      removeMaiorQueCem(&listaPlacas);
      listaPlacas = intercala(listaPlacas, listaTemp);
      imprime_intervalo(listaPlacas, aux);
      listaTemp = NULL;
    }
  }

  return 0;
}