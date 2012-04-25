#include <stdio.h>

int
main(void) {
  int sumofsquares, sum, squareofsum, i;
  sumofsquares = sum = 0;

  for (i = 0; i <= 100; ++i) {
    sumofsquares += i * i;
    sum += i;
  }
  squareofsum = sum * sum;

  printf("%d\n", squareofsum - sumofsquares);

  return 0;
}
