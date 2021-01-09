#include <stdio.h>

// A head recursion is when you start your function calling itself before doing anything else,
// and then after the function exits you do stuff

void head(int n) {
  if(n < 3) {
    head(n + 1);

    printf("%d \n", n);
  }
}

void notHead(int n) {
  if(n < 3) {
    printf("%d \n", n);

    notHead(n + 1);
  }
}


int main() {
  head(0);
  return 0;
}