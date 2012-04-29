#include <stdio.h>

int
main(void) {
  // one, two, three, four, five, six, seven, eight, nine
  unsigned int ones[] = {0,3,3,5,4,4,3,5,5,4};
  // ten, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
  unsigned int tens[] = {0,3,6,6,5,5,5,7,6,6};
  // eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen,
  // nineteen
  unsigned int except[] = {0,6,6,8,8,7,7,9,8,8};
  unsigned int and = 3, hundred = 7, thousand = 8;
  unsigned int sum = 0, i;

  char dummy;

  // 1-9
  for (i = 1; i < 10; ++i)
    sum += ones[i];

  // 10
  sum += tens[1];

  // 11-19 (exceptions)
  for (i = 1; i < 10; ++i)
    sum += except[i];

  // 20 - 99
  for (i = 20; i < 100; ++i) {
    sum += tens[i / 10];
    sum += ones[i % 10];
  }

  // 100 - 999
  for (i = 100; i < 1000; ++i) {
    // thousands place word length
    sum += ones[i / 100];
    sum += hundred;

    // checks for the 11-19 exceptions
    if (i % 100 != 0) {
      sum += and;
      if (i % 100 >= 11 && i % 100 <= 19) {
        sum += except[(i % 100) % 10];
        continue;
      }

      // if no 11-19 exceptions continues as usual
      sum += tens[(i % 100) / 10];
      sum += ones[i % 10];
    }
  }

  // 1000
  sum += ones[1] + thousand;

  printf("%u\n", sum);
  return 0;
}
