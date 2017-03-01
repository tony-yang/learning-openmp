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
  int sum_local;
  #pragma omp parallel shared(a,sum) private(sum_local)
  {
    sum_local = 0;
    #pragma omp for
    for (i = 0; i < N; i++) {
      sum_local += a[i];
    }

    #pragma omp critical
    {
      sum += sum_local;
    }
  }

  printf("Sum = %d\n", sum);
}
