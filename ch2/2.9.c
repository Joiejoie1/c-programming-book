#include <stdio.h>

/*
 * In a two's complement number system, x &= (x-1) deletes
 * the right most 1-bit in x. Explain why. Use this observation
 * to write a faster version of bitcount.
 *
 * Answer: if you have number like 14 (1110) and you take one away
 *         you get 13 (1101), when you use the bitwise & operator
 *         it will result in 1100, effectively removing the right
 *         most bit. This result is saved back into x when &= is used.
 */

int bitcount(unsigned x); 

int main() {
  int num;
  printf("number: ");
  scanf("%d", &num);

  printf("there are %d bits in the number %d\n", bitcount(num), num);
}

int bitcount(unsigned x) {
  int b = 0;

  while (x) {
    b++;
    x &= (x - 1);
  }

  return b;
}
