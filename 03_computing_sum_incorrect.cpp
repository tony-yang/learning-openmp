#include <iostream>
#include <omp.h>
#define N 1000

int main(int argc, char *argv[]) {
  int i;
  int a[N];
  for (i = 0; i < N; i++) {
    a[i] = i;
  }

  int sum = 0;
  #pragma omp parallel for
  for (i = 0; i < N; i++) {
    sum += a[i];
  }

  printf("Sum = %d\n", sum);
}
