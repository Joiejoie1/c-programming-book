#include <stdio.h>

/*
 * Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and 
 * vice versa), leaving the others unchanged.
 */

int invert(int x, int p, int n);

int main() {
  int num, num_of_bits, position;

  printf("number to change: ");
  scanf("%d", &num);

  printf("number of bits to invert: ");
  scanf("%d", &num_of_bits);

  printf("position of bits (zero indexed): ");
  scanf("%d", &position);

  printf("result: %d\n", invert(num,position,num_of_bits));
}

int invert(int x, int p, int n) {
  int mask = ~(~0 << n) << (p - n + 1);
  int set_bits = ~x & mask;

  return (x & ~mask) | set_bits;
}
