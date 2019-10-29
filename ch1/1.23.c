#include <stdio.h>

#define MAXLINE 1000
#define NORMAL 0
#define CHAR 1
#define QUOTE 2
#define COMMENT 3
#define MULTI_COMMENT 4

/* 
 *  Write a program to remove all comments from a C program.
 *  Don't forget to handle quoted strings and character
 *  constants properly.
 */

int getaline(char s[], int limit);
int remove_comments(char s[], int strlen);

int multiline_state = NORMAL;

int main() {
  int c, len, newlen;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) != 0) {
    newlen = remove_comments(line, len);
    if(newlen > 0)
      printf("> %s", line);
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

int remove_comments(char s[], int strlen) {
  char scratch[MAXLINE];
  int scratch_i, str_i, state, c;
  /* int state = NORMAL; */

  if(multiline_state == NORMAL)
    state = NORMAL;
  else
    state = MULTI_COMMENT;
  
  for(str_i = scratch_i = 0; str_i <= strlen; ++str_i) {
    c = s[str_i];
    if(state == NORMAL) {
      if(c == '"' ) {
        state = QUOTE;
      } else if(c == '\'') {
        state = CHAR;
      } else if(c == '/' && str_i + 1 < MAXLINE){
        if (s[str_i + 1] == '/') {
          state = COMMENT;
        } else if (s[str_i + 1] == '*') {
          state = MULTI_COMMENT;
          multiline_state = MULTI_COMMENT;
        }      
      }
      if(state != COMMENT && state != MULTI_COMMENT) {
        scratch[scratch_i] = c;
        ++scratch_i;
      }
    } else if (state == COMMENT && c == '\n') {
      scratch[scratch_i] = c;
      state = NORMAL;
      ++scratch_i;
    } else if (state == MULTI_COMMENT && c == '*') {
      if(s[str_i + 1] == '/') {
        state = NORMAL;
        multiline_state = NORMAL;
        str_i += 1;
      }
    } else if (state == QUOTE) {
      if(c == '"' && s[str_i - 1] != '\\')
        state = NORMAL;
      scratch[scratch_i] = c;
      ++scratch_i;
    } else if (state == CHAR) {
      if(c == '\'') {
        state = NORMAL;
      }
      scratch[scratch_i] = c;
      ++scratch_i;
    }
  }

  for(int i = 0; i < scratch_i; ++i)
    s[i] = scratch[i];
  return scratch_i;
}
