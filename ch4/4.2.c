#include <stdio.h>
#include <ctype.h>
#include <math.h>
/*
 * Extend atof to handle scientific notation of the form 123.45e-6 where
 * a floating-point number may be followed by e or E and an optionally
 * signed exponant
 */

double atof(char s[]);

int main() {
  char number[] = "123.45e7";
  printf("%f\n", atof(number));
}

double atof(char s[]) {
  double val, power, exponant, result;
  int i, sign, exponant_sign;

  for (i = 0; isspace(s[i]); i++) //skip whitespace
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  exponant = 0;
  if (toupper(s[i++]) == 'E') {
    exponant_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
      i++;
    exponant = (pow(10, s[i] - '0')) * exponant_sign;
  }

  result = sign * val / power;

  if (exponant) {
    if (exponant > 0)
      result *= exponant;
    else
      result /= exponant;
  }
  
  return result;
}
