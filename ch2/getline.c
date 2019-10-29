#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000

/*
 * 
 */

int getaline(char s[], int limit);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) != 0) {
    printf("%s", line);
  }
  return 0;
}

int getaline(char s[], int limit) {
  int i, c;

  for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = '\n';
    ++i;
  }
  s[i] = '\0';
  return i;
}
