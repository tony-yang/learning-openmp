#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {
  int x = 2;
  #pragma omp parallel shared(x)
  {
    int tid = omp_get_thread_num();
    if (tid == 0) {
      x = 5;
    } else {
      printf("[1] thread %2d: x = %d\n", tid, x);
    }

    #pragma omp barrier

    printf("[2] thread %2d: x = %d\n", tid, x);
  }
}
