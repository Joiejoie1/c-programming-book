#include <stdio.h>

int main(){
  float celsius, fahr;
  int upper, lower, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf(" %s %6s\n", "ºC", "ºF");
  celsius = lower;
  while(celsius <= upper){
    fahr = celsius * (9.0 / 5.0) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius += step;
  }
}
