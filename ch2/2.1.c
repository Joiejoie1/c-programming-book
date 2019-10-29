#include <stdio.h>
#include <limits.h>
#include <float.h>

/* 
 * Write a program to determine the ranges of char, short,
 * int, and long variables, both signed and unsigned by 
 * printing appropriate values from standard headers and
 * by direct computation. Harder if you compute them:
 * determine the ranges of various floating point types.
 */

int main() {
  printf("Limits from header\n");
  printf("%27s%20s\n", "MIN", "MAX");
  printf("char: %21d%20d\n", CHAR_MIN, CHAR_MAX);
  printf("uchar: %20d%20d\n", 0, UCHAR_MAX);
  printf("short: %20d%20d\n", SHRT_MIN, SHRT_MAX);
  printf("ushort: %19d%20d\n", 0, USHRT_MAX);
  printf("int:  %21d%20d\n", INT_MIN, INT_MAX);
  printf("uint:  %20d%20u\n", 0, UINT_MAX);
  printf("long: %21ld%20ld\n", LONG_MIN, LONG_MAX);
  
  // compute the maxes somehow?
}
