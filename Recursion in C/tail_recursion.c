#include <stdio.h>

// A tail recursion is when you end your function calling itself and there is nothing else for it to do after
// It's better to write a loop when you have a tail recursion

void tail(int n) {
  if(n < 3) {
    printf("%d \n", n);

    tail(n + 1);
  }
}

void notTail(int n) {
  if(n < 3) {
    printf("%d \n", n);

    notTail(n + 1);

    // This is not a tail recursion because after calling the function it still prints n
    // even if you have something like:
    // return fun(n) + n 
    // it wont be a tail recursion because you add n after the called function exits

    printf("%d \n", n);
  }
}

int main() {
  tail(0);
  return 0;
}