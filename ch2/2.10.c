#include <stdio.h>
#define MAXLINE 1000

/*
 * Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else.
 */

int lower(int c);
int getaline(char line[], int maxline);

int main() {
  char line[MAXLINE];
  int len;

  while ((len = getaline(line, MAXLINE)) != 0) {
    printf("%s", line);
  }
}

int lower(int c) {
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int getaline(char line[], int maxline) {
  int i, c;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = lower(c);
  if (c == '\n') {
    line[i] = c;
    i++;
  }
  line[i] = '\0';
  return i;
}
