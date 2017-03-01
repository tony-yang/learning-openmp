#include <iostream>
#include <omp.h>
#define N 1000
#define CHUNKSIZE 100

int main(int argc, char *argv[]) {
  int i, chunk;
  float a[N], b[N], c[N];
  for (i = 0; i < N; i++) {
    a[i] = i * 1.0;
    b[i] = i * 1.0;
    printf("a[%d] = %f and b[%d] = %f\n", i, a[i], i, b[i]);
  }

  chunk = CHUNKSIZE;

  #pragma omp parallel shared(a, b, c, chunk) private(i)
  {
    #pragma omp for schedule(dynamic, chunk) nowait
    for (i = 0; i < N; i++) {
      c[i] = a[i] + b[i];
    }
  }

  for (i = 0; i < N; i++) {
      printf("c[%d] = %f\n", i, c[i]);
  }
}
