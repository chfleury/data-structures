#include <stdio.h>

void fun(int n) {
  if(n < 3) {
    printf("Going %d \n", n);

    fun(n + 1);

    printf("Returning %d \n", n);
  }
}

int main() {
  fun(0);
  return 0;
}