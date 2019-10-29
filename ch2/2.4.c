#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000
enum newline { NO_NEWLINE, NEWLINE };
enum boolean { NO_MATCH, MATCH };

/*
 * write an alternate version of squeeze(s1, s2) that deletes
 * each character in s1 that matches any character in the string s2.
 */

int getaline(char s[], int limit, int newline);
void squeeze(char s1[], char s2[]);

int main() {
  int len;
  char line1[MAXLINE];
  char line2[MAXLINE];
  
  printf("enter a string: ");
  while ((len = getaline(line1, MAXLINE, NEWLINE)) != 0) {
    printf("chars to remove: ");
    getaline(line2, MAXLINE, NO_NEWLINE);
    squeeze(line1, line2);
    printf("%s", line1);
    printf("enter a string: ");
  }
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j, match;
  int len_s1, len_s2;

  len_s1 = len_s2 = 0;

  for (i = 0; s1[i] != '\0'; i++)
    len_s1++; // find length of s1
  
  for (j = 0; s2[j] != '\0'; j++)
    len_s2++; // find length of s2

  char result[len_s1 + 1]; // leave room for null char
  int result_len = 0;

  for (i = 0; i <= len_s1; ++i) {
    match = NO_MATCH; // Fresh start, no match yet
    for (j = 0; j <= len_s2; ++j) {
      if (s1[i] == s2[j])
        match = MATCH;
    }
    if (match == MATCH)
      continue;
    else
      result[result_len++] = s1[i];
  }
  result[result_len] = '\0';
  
  // copy result back into original char array
  for (i = 0; i <= result_len; ++i)
    s1[i] = result[i];
}

int getaline(char s[], int limit, int newline) {
  int i, c;

  for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n' && newline == NEWLINE) {
    s[i] = '\n';
    ++i;
  }
  s[i] = '\0';
  return i;
}
