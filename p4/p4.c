#include <stdio.h>

int
isPalindrome(unsigned long n) {
  unsigned long nreverse = 0, orign = n;

  while (n > 0) {
    nreverse = nreverse * 10 + n % 10;
    n /= 10;
  }

  return(orign == nreverse);
}

int
main(void) {
  unsigned long palindrome = 0, prod;
  int i1, i2;

  for (i1 = 99; i1 < 999; ++i1) {
    for (i2 = 99; i2 < 999; ++i2) {
      prod = i1 * i2;
      if (isPalindrome(prod) && palindrome < prod)
        palindrome = prod;
    }
  }

  printf("%d\n", palindrome);

  return 0;
}
