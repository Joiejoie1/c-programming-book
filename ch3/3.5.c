#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
/*
 * Write the function itob(n,s,b) that converts the integer n
 * into a base b character representation in the string s. In
 * particular, itob(n,s,16) formats n as a hexadecimal integer
 * in s.
 */

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
  int num;
  int base;
  char s[MAXLINE];

  printf("number to convert: ");
  scanf("%d", &num);

  printf("base to convert to: ");
  scanf("%d", &base);

  if (base > 36) {
    printf("Base 36 is the highest base this program can deal with\n");
    return 1;
  }
  itob(num, s, base);

  printf("%d = %s in base %d\n", num, s, base);
  return 0;
}

void itob(int n, char s[], int b) {
  int num;
  int i = 0;

  do {
    num = n % b;

    if (num > 9)
      num = (num - 10) + 'a';
    else
      num += '0';

    s[i++] = num;
  } while ((n /= b) > 0);
  
  reverse(s);
  s[++i] = '\0';
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
