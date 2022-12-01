#include <stdio.h>

int sum(int k);

int main() {
  int boys = 4;
  int* ptr = &boys;
  // printf("There are %d boys", boys);
  // printf("Hello World!");
  // printf("%d", *ptr);
  int result = sum(5);
  printf("%d", result);
  return 0;
}

int sum(int k) {
  if (k == 0) {
    return 0;
  } else {
    return k + sum(k - 1);
  }
}