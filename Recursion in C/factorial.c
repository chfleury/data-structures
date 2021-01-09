#include <stdio.h>

int factorial(int n) {
  if(n > 0 ){
    return factorial(n - 1) * n;
  } else {
    return 1;
  }
}

int main() {
  int input;

  scanf("%d", &input);

  printf(
    "%d",
    factorial(input)
  );

  return 0;
}
