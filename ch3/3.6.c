#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * Write a version of itoathat accepts three arguments instead
 * of two. The third argument is a minimum field width; the 
 * converted number must be padded with blanks on the left if
 * necessary to make it wide enough.
 */

void itoa(int n, char s[], int min);
void reverse(char s[]);

int main() {
  int num, min;
  char s[50]; // 50 digits is quite a lot, we won't need them all
  
  printf("number: ");
  scanf("%d", &num);

  printf("min field width: ");
  scanf("%d", &min);

  itoa(num, s, min);
  printf("%s\n", s);
}

void itoa(int n, char s[], int min) {
  int i, sign;

  sign = n;            // record sign
  i = 0;

  do {                            // generate digits in reverse order
    s[i++] = abs(n % 10) + '0';   // get next digit
  } while (n /= 10);   // delete it

  if (i < min) 
    while (i < min)
      s[i++] = ' ';

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}
  

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
