#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

/*
 * Write a function expand(s1, s2) that expands shorthand notations
 * like a-z in the string s1 into the equivalent complete list 
 * abc...xyz in s2. Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally.
 */

void expand(char s1[], char s2[]);
int getaline(char s[], int limit);

int main() {
  int len;
  char line[MAXLINE];
  char expandedline[MAXLINE];

  while ((len = getaline(line, MAXLINE)) != 0) {
    expand(line, expandedline);
    printf("%s", expandedline);
  }
  return 0;
}

void expand(char s1[], char s2[]) {
  int c, i, j;
  int k;

  i = j = 0;
  while ((c = s1[i++]) != '\0') {
    if (isalnum(c) && i <= MAXLINE && s1[i] == '-' && i + 1 <= MAXLINE) {
      if (isalpha(c) && isalpha(s1[i+1]) && c < s1[i+1]) {
        for (k = c; k <= s1[i+1]; ++k)
          s2[j++] = k;
        i += 2;

      } else if ((isdigit(c) && isdigit(s1[i+1])) && c < s1[i+1]) {
        for (k = c; k <= s1[i+1]; ++k)
          s2[j++] = k;
        i += 2;
      } else {
        s2[j++] = c;
      }
    } else {
      s2[j++] = c;
    }
  }
  s2[j] = '\0';
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
