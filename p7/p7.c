/*  Not very optimized at this point. Took about 2.5 seconds. */

#include <stdio.h>

#define MAXCOUNT 10001

int
isPrime(int n) {
  int i;

  if (n % 2 == 0)
    return 0;

  for (i = 3; i < n; i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int
main(void) {
  unsigned int i, primecount = 0;

  for (i = 2;; ++i) {
    if (isPrime(i)) {
      ++primecount;
    }
    if (primecount == MAXCOUNT)
      break;
  }

  printf("%lu\n", i);

  return 0;
}
