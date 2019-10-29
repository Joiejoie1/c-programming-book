#include <stdio.h>

/*
 * Write the function strend(s,t), which returns 1 if the string
 * t occurs at the end of the string s, and zero otherwise.
 */


int strend(char *, char *);

int main() {
  char s[] = "hello world";
  char t[] = "world";

  printf("%d\n", strend(s, t));
}

int strend(char *s, char *t) {
  int tlen = 0;
  while (*s != '\0')
    s++;
  while (*t != '\0') {
    t++;
    tlen++;
  }
  
  while (tlen != 0 && (*s-- == *t--)) 
    tlen--;

  if (tlen == 0)
    return 1;

  return 0;
}
