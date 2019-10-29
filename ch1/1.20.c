#include <stdio.h>

#define MAXLINE 1000
#define TABLENGTH 4

int getaline(char s[], int limit);
void detab(char s[], int str_len);

/*
 * Write a program "detab" that replaces tabs in
 * the input with the proper number of blanks to
 * achieve the same spacing.
 */

int main() {
  int len;
  char line[MAXLINE];

  while((len = getaline(line, MAXLINE)) != 0) {
    detab(line, len);
    printf("%s", line);
  }
}

int getaline(char s[], int limit) {
  int i, c;

  for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void detab(char s[], int str_len) {
  int i;
  int workspace_idx;
  char workspace[MAXLINE];

  for(i = 0, workspace_idx = 0; i <= str_len; ++i) {
    if(s[i] == '\t') {
      for(int j = 0; j < TABLENGTH; ++j) {
        workspace[workspace_idx] = ' ';
        ++workspace_idx;
      }

    } else {
      workspace[workspace_idx] = s[i];
      ++workspace_idx;
    }
  }
  
  for(i = 0; i <= workspace_idx; ++i)
    s[i] = workspace[i];
}
