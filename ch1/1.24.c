#include <stdio.h>

#define MAXLINE 1000
#define NORMAL 0
#define IN_MULTILINE_COMMENT 1
#define IN_INLINE_COMMENT 2
#define IN_QUOTE 3
#define IN_CHAR 4

/* 
 *  write a program to check a C program for rudimentary syntax
 *  errors like unbalanced parentheses, brackets and braces.
 *  Don't forget about quotes, both single and double, escape
 *  sequences, and comments.
 */

int getaline(char s[], int limit);
void check_syntax(char s[], int strlen);
void reset_counters();
int get_mismatch_count(int count);

int state = NORMAL;
int parens = 0;
int brackets = 0;
int braces = 0;

int main() {
  int c, len, newlen;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) != 0) {
    check_syntax(line, len);
    if (state == NORMAL) {
      if (parens ==0 && brackets == 0 && braces == 0)
        printf("No syntax errors\n");
      else 
        if (parens != 0)
          printf("%d mismatched parentheses ()\n", get_mismatch_count(parens));
        if (brackets != 0)
          printf("%d mismatched brackets []\n", get_mismatch_count(brackets));
        if (braces != 0)
          printf("%d mismatched braces {}\n", get_mismatch_count(braces));
    } else if (state == IN_MULTILINE_COMMENT) {
      printf("missing '*/'\n");
    } else if (state == IN_QUOTE) {
      printf("missing double quote\n");
    } else if (state == IN_CHAR) {
      printf("missing single quote\n");
    }
    reset_counters();
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

int get_mismatch_count(int count) {
  int i;
  if (count < 0) {
    for (i = 0; i > count; i--) 
      continue;
  } else {
    for (i = 0; i < count; i++) 
      continue;   
  }
  return i;
}

void reset_counters() {
  parens = 0;
  brackets = 0;
  braces = 0;
}

void check_syntax(char s[], int strlen) {
  int c;
  
  for (int i = 0; i <= strlen; ++i) {
    c = s[i];
    if (state == NORMAL) {
      if (c == '"') {
        state = IN_QUOTE;
      } else if (c == '\'') { 
        state = IN_CHAR;
      } else if (c == '/' && i < MAXLINE) {
        if (s[i+1] == '*')
          state = IN_MULTILINE_COMMENT;
        else if (s[i+1] == '/')
          state = IN_INLINE_COMMENT;
      } else if (c == '[') {
        ++brackets;
      } else if (c == ']') {
        --brackets;
      } else if (c == '(') {
        ++parens;
      } else if (c == ')') {
        --parens;
      } else if (c == '{') {
        ++braces;
      } else if (c == '}') {
        --braces;
      }
    } else if (state == IN_MULTILINE_COMMENT && c == '*') {
      if (s[i+1] == '/') 
        state = NORMAL;
    } else if (state == IN_INLINE_COMMENT) {
      if (c == '\n')
        state = NORMAL;
    } else if (state == IN_QUOTE && c == '"') {
        if (i > 0 && s[i - 1] != '\\')
          state = NORMAL;
    } else if (state == IN_CHAR && c == '\'') {
        if (i > 0 && s[i - 1] != '\\')
          state = NORMAL;
    }
  }
}
