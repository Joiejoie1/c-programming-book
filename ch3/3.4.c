#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
/*
 * In a 2s complement number representation, our verion of
 * itoa does not handle the largest negative number, that is, the
 * value of n equal to -(2ʷᵒʳᵈˢᶦᶻᵉ⁻¹). Explain why not. Modify
 * it to print that value correctly regardless of the machine
 * on which it runs.
 *
 * Explanation: assuming we are working with an 8bit system;
 * in a 1s complement system you get the negative of a number 
 * just by flipping the bits, e.g. 
 *
 *          signed    binary   unsigned 
 *               5 = 00000101  = 5
 *              -5 = 11111010  = 250
 *
 *             127 = 01111111  = 127
 *            -127 = 10000000  = 128
 *
 * In a 2s complement system you get the negative of a number 
 * by finding the 1s complement (flipping the bits) and adding
 * one, e.g.
 *
 *          signed    binary   unsigned 
 *               5 = 00000101  = 5
 *              -5 = 11111011  = 251
 *
 *             127 = 01111111  = 127
 *            -127 = 10000001  = 129
 *
 *               0 = 00000000  = 0
 *              -1 = 11111111  = 255
 *
 * Note there are two ways to represent zero in a 1s complement
 * system, 0000000 or 11111111, a 2s complement system only has
 * one, 0000000, all one bits would be -1.
 *
 * This means the full range of signed integers on a 2s complment 
 * system would range from -128 to 127 which is one more than a 1s 
 * complement.
 * 
 * The itoa function flips the sign to make n positive but on a 2s
 * complement system 128 can not be represented, remember the 
 * range goes up to 127. So, due to all of the above when you try to
 * flip -128 you don't get 128 you just get -128 again. i.e.
 *
 *                 128 = 10000000
 *       1s complement = 01111111
 *            plus one = 10000000 = -128
 *
 * After one iteration of the do-while loop the function checks if 
 * (n / 10) > 0 which it won't be, the loop is exited.
 *
 *
 *   The original itoa method for reference
 *
 *   void itoa(int n, char s[]) {
 *     int i, sign;
 *
 *     if ((sign = n) < 0) // record sign
 *       n = -n;           // make n positive
 *     i = 0;
 *
 *     do {                       // generate digits in reverse order
 *       s[i++] = n % 10 + '0';   // get next digit
 *     } while ((n /= 10) > 0);   // delete it
 *
 *     if (sign < 0)
 *       s[i++] = '-';
 *     s[i] = '\0';
 *     reverse(s);
 *   }
 * 
 */
void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
  char buffer[20];

  printf("Min int: %d\n", INT_MIN);
  itoa(INT_MIN, buffer);
  printf("%s\n", buffer);
}

void itoa(int n, char s[]) {
  int i, sign;

  sign = n;            // record sign
  i = 0;

  do {                            // generate digits in reverse order
    s[i++] = abs(n % 10) + '0';   // get next digit
  } while (n /= 10);   // delete it

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
