#include <stdio.h>

#define MAXLINE 1000
#define MAX_COL_WIDTH 30

/* 
 * write a program to "fold" long input lines into
 * two or more shorter lines after the last non-block 
 * character that occurs before the n-th column of input
 */

int getaline(char s[], int limit);
void fold_lines(char s[], int strlen);

int main() {
  int c, len;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) != 0) {
    fold_lines(line, len);
    printf("%s", line);
  }
}
 
int getaline(char s[], int limit) {
  int i, c;

  for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void fold_lines(char s[], int strlen) {
  char scratch[MAXLINE];
  int col = 0;
  int last_space_i;

  for(int i = 0; i <= strlen; ++i) {
    if(s[i] == ' ')
      last_space_i = i;
    if(col == MAX_COL_WIDTH) {
      if(s[i] == ' ' || s[i] == '\n') {
        scratch[i] = '\n';
        col = 0;
      }
      else {
        scratch[last_space_i] = '\n';
        scratch[i] = s[i];
        col = i - last_space_i; 
      }
    } else {
      scratch[i] = s[i];
      ++col;
    }
  }
  
  for(int i = 0; i <= strlen; ++i)
    s[i] = scratch[i];
}
