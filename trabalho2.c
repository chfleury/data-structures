#include <stdio.h>

struct Celula
{
  long pontuacao;
  char coordenadas[];
};

int quantidadeEDAZINHOS = 1;
int turnosRestantes = 0;

void fimTurno()
{
  printf("fimturno\n");
  fflush(stdout);
}

void sondar(char coordenadas[])
{
  printf("sondar %s", coordenadas);
}

void dominar(char coordenadas[])
{
  printf("dominar %s", coordenadas);
}

void main()
{
  long x, y, pontuacaoInicial;

  scanf("%d %d %d %d", &x, &y, &pontuacaoInicial, &turnosRestantes);
}