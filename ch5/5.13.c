#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 10000
#define MAXLINE 500

/*
 * Write the program tail, which prints the last n lines of its
 * input. By default, n is 10, let us say, but it can by changed 
 * by an optional argument, so that
 *     tail -n
 * prints the last n lines. The program should behave rationally
 * no matter how unreasonable the input or value of n. Write the
 * program so it makes the best use of available storage as in
 * the sorting program of Section 5.6, not in a two-dimensional
 * array of fixed size.
 */

int getaline(char [], int);
int readlines(char *[], int);

int main(int argc, char *argv[]) {
  int lines_to_print = 10;
  int nlines;
  char *linesptr[MAXLINES]; 

  if (argc == 2)  {
    // move pointer along if option starts with -
    if (*argv[1] == '-') ++argv[1];
    // convert and save input if digit
    if (isdigit(*argv[1])) lines_to_print = atoi(argv[1]);
  }

  if ((nlines = readlines(linesptr, MAXLINES)) > 0) {
    if (lines_to_print > nlines)
      lines_to_print = nlines;
    for (int i = nlines - lines_to_print; i < nlines; i++) {
      printf("> %s", linesptr[i]);
    }
  }
  return 0;
}

int readlines(char *linesptr[], int limit) {
  char *p, line[MAXLINE];
  int len, nlines;

  nlines = 0;

  while ((len = getaline(line, MAXLINE)) != 0) {
    p = malloc(len);
    strcpy(p, line);
    linesptr[nlines++] = p;
  }
  return nlines;
}

int getaline(char s[], int limit) {
  int i,c;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}
