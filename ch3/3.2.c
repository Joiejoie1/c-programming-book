#include <stdio.h>

#define MAXLINE 1000

/*
 * Write a function escape(s,t) that converts characters like newline
 * and tab into visible escape sequences like \n and \t as it copies
 * the string t to s. Use a switch. Write a function for the other
 * direction as well, converting escape sequences into real charcters.
 */

int getaline(char s[], int limit);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
  int len;
  char line[MAXLINE];
  char escapedline[MAXLINE];
  char unescapedline[MAXLINE];

  while ((len = getaline(line, MAXLINE)) != 0) {
    escape(escapedline, line);
    printf("escaped:   %s\n", escapedline);

    unescape(unescapedline, line);
    printf("unescaped: %s", unescapedline);
  }
  return 0;
}

int getaline(char s[], int limit) {
  int i, c;

  for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n'){
    s[i] = '\n'; 
    ++i;
  }
  s[i] = '\0';
  return i;
}

void escape(char escapedline[], char line[]) {
  int c, i, j;
  i = j = 0;

  while ((c = line[i++]) != '\0') {
    switch (c) {
      case '\t':
        escapedline[j++] = '\\';
        escapedline[j++] = 't';
        break;
      case '\n':
        escapedline[j++] = '\\';
        escapedline[j++] = 'n';
        break;
      default:
        escapedline[j++] = c;
    }
  }
  escapedline[j] = '\0';
}

void unescape(char unescapedline[], char line[]) {
  int c, i, j;
  i = j = 0;

  while ((c = line[i++]) != '\0') {
    if (c == '\\' && i <= MAXLINE) {
      switch (line[i]) {
        case 'n':
          unescapedline[j++] = '\n';
          i++;
          break;
        case 't':
          unescapedline[j++] = '\t';
          i++;
          break;
        default:
          unescapedline[j++] = c;
      }
    } else {
      unescapedline[j++] = c;
    }
  }
  unescapedline[j] = '\0';
}
