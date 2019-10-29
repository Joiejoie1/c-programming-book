#include <stdio.h>

#define MAXSTR 100
/*
 * Adapt the ideas of printd to write a recursive version
 * of itoa; that is, convert an integer into a string by
 * calling a recursive routine
 */

void itoa(int, char[]);
char printch(int);

int main(int argc, const char *argv[]) {
  char s[MAXSTR];
  itoa(-34567, s);
  printf("%s\n", s);
  return 0;
}

void itoa(int n, char s[]) {
  static int str_idx = 0;

  if (n < 0) {
    s[str_idx++] = '-';
    n = -n;
  }
  if (n / 10)
    itoa(n / 10, s);
  s[str_idx++] = n % 10 + '0';
}

