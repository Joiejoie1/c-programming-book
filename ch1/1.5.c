#include <stdio.h>
/* use a for loop to print out the ºF to ºC
 * table in reverse order
 */

int main(){
  for (float fahr = 300.0; fahr >= 0; fahr -= 20.0) {
    printf("%3.0f %6.1f\n", fahr, (5.0/9.0) * ( fahr - 32.0 ));
  }
}
