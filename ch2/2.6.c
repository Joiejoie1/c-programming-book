#include <stdio.h>

/*
 * Write a function setbits(x,p,n,y) that returns x  with the n bits
 * that begin at position p set to the rightmost n bits of y, leaving
 * the others unchanged.
 */

int setbits(int first_num, int position, int num_bits, int second_num);

int main() {
  int first_num, second_num, num_bits, position, result;

  printf("first number: ");
  scanf("%d", &first_num);

  printf("bit position to change (zero indexed): ");
  scanf("%d", &position);

  printf("number of bits: ");
  scanf("%d", &num_bits);

  printf("second number: ");
  scanf("%d", &second_num);

  result = setbits(first_num, position, num_bits, second_num);

  printf("%d\n", result);
  return 0;
}

int setbits(int first_num, int position, int num_bits, int second_num) {
  int first_mask = ~0 << (position + 1);
  int end_mask = ~(~0 << (position - num_bits + 1));
  int middle_mask = (second_num & ~(~0 << num_bits)) << (position - num_bits + 1);


  int mask = first_mask | end_mask | middle_mask;
  return first_num & mask;
}


