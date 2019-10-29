#include <stdio.h>

#define MAXLINE 1000

/* 
 * Write a loop equivalent to this for loop:
 * for (i = 0; i<lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
 * without using && or ||
 */

int getaline(char s[], int max);

int main () {
  int len;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) != 0)
    printf("%s", line);
}

int getaline(char s[], int max) {
  int c;
  int i = 0;

  while (1) {
    if (!(i < max - 1))
      break;
    c = getchar();
    if (c == '\n') {
      s[i] = c;
      ++i;
      break;
    }
    if (c == EOF)
      break;
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  ++i;

  return i;
}

