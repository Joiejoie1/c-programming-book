#include <stdio.h>
#define BITS (int)(sizeof(int) * 8)

/*
 * Write a function rightrot(x,n) that returns the value  of the integer
 * x rotated to the right by n bit positions
 */

int rightrot(int x, int n);

int main() {
  int num, shift;

  printf("number: ");
  scanf("%d", &num);

  printf("positions to shift: ");
  scanf("%d", &shift);

  printf("result: %d\n", rightrot(num, shift));
}

int rightrot(int x,int n) {
  int result = x;
  int most_sig_bit = 1 << (BITS - 1);

  for (int i = 0; i < n % BITS; ++i) {
    // move all the bits along and zero the msb
    result = (result >> 1) & ~most_sig_bit; 

    if (((x >> i) & 1) == 1){
      // the lsb is a 1 so set the msb in the result to 1
      result |= most_sig_bit;
    } 
  }

  return result;
}
