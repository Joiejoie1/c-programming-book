#include <stdio.h>

#define MAXLINE 1000

/*
 * Write the function strrindex(s,t), which returns the positio
 * of the rightmost occurence of t in s, or -1 if there is none.
 */

int getaline(char line[], int max);
int strrindex(char s[], char t[]);

int main() {
  int len;
  char line[MAXLINE];
  char find[] = "hello";

  while ((len = getaline(line, MAXLINE)) != 0)
    printf("%d\n", strrindex(line, find));
}


int strrindex(char string[], char tofind[]) {
  int i, j, k;
  int found = -1;

  for (i = 0; string[i] != '\0'; i++) {
    for (j=i, k=0; tofind[k] != '\0' && string[j] == tofind[k]; j++, k++)
      ;
    if (k > 0 && tofind[k] == '\0')
      found = i;
  }
  return found;
}


int getaline(char line[], int max) {
  int c, i;

  i = 0;
  while (max-- > 0 && (c = getchar()) != EOF && c != '\n')
    line[i++] = c;
  if (c == '\n')
    line[i++] = '\n';
  line[i] = '\0';

  return i;
}
