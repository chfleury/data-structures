#include <stdio.h>

int fun(int n) {
  static int x = 0;
  if (n > 0) {
    x++;
    return fun(n - 1) + x;
  }

  return 0;
}

int main() {
  printf("%d", fun(5));
  
  return 0;
}