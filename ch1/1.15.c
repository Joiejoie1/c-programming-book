#include <stdio.h>

#define UPPER 300
#define STEP  20

/*
 * Fahrenheit to Celsius using a function
 */

float ftoc(float fahr) {
  return (5.0/9.0) * (fahr - 32.0);
}

int main() {
  
  printf(" ºF    ºC\n");
  for (float fahr = 0.0; fahr < UPPER; fahr += STEP) {
    printf("%3.0f %6.1f\n", fahr, ftoc(fahr));
  }

  return 0;
}
