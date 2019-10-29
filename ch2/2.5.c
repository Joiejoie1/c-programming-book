#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000

/*
 * Write the function any(s1,s2), which returns the first location in
 * the string s1 where any character from string s2 occurs, or -1 if
 * s1 contains no characters from s2
 */

int getaline(char s[], int limit);
int any(char s1[], char s2[]);

int main() {
  int len;
  char line1[MAXLINE];
  char line2[MAXLINE];
  
  printf("enter string: ");
  while ((len = getaline(line1, MAXLINE)) != 0) {
    printf("enter characters to find: ");
    getaline(line2, MAXLINE);
    printf("%d\n", any(line1, line2));
    printf("enter string: ");
  }
  return 0;
}

int any(char s1[], char s2[]) {
  int len_s1, len_s2;
  int i, j;

  // Get length of both strings
  len_s1 = len_s2 = 0;
  while(s1[len_s1++] != '\0')
    ;
  while(s2[len_s2++] != '\0')
    ;

  for(i = 0; i < len_s2 - 1; ++i) {
    for(j = 0; j < len_s1 - 1; ++j) {
      if(s2[i] == s1[j])
        return j; // found a char, return position in s1
    }
  }

  return -1; // no char found
}

int getaline(char s[], int limit) {
  int i, c;

  for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  // Ignore newlines
  s[i] = '\0';
  return i;
}
