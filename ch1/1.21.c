#include <stdio.h>

#define MAXLINE 1000
#define TABLENGTH 4

/* 
 *  Write a program "entab" that replaces strings of blanks
 *  by the minimum number of tabs and blanks to achieve the
 *  same spacing.
 */

int getaline(char s[], int limit);
void entab(char s[], int strlen);

int main() {
  int c, len;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) != 0) {
    entab(line, len);
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

void entab(char s[], int strlen) {
  char scratch[MAXLINE];
  int scratch_i = 0;
  int space_count;
  int old_i;

  for(int i = 0; i <= strlen; ++i) {
    if(s[i] == ' ') {
      old_i = i; // remember place in array before searching forward
      space_count = 1;
      for(int j = 1; j < TABLENGTH && i <= strlen && s[i] == ' '; ++j) {
        ++space_count;
        ++i;
      }
      if (space_count == TABLENGTH) {
        /* scratch[scratch_i] = '\t'; */
        // Tabs are hard to see so let's use an % 
        scratch[scratch_i] = '%';
      } else {
        i = old_i;
        scratch[scratch_i] = s[i];
      }
      ++scratch_i;
    } else {
      scratch[scratch_i] = s[i];
      ++scratch_i;
    }
  }

  for(int i = 0; i <= scratch_i; ++i)
    s[i] = scratch[i];
}
