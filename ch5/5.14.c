#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Modify the sort program to handle a -r flag, whic indicates
 * sorting in reverse (decreasing) order. Be sure that -r works
 * with -n
 */

#define MAXLINES 5000    // max #lines to be sorted
#define MAXLINE 500      // max length of a line
char *lineptr[MAXLINES]; // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int mystrcmp(char *s, char *t);
int numcmp(char *, char *);

void print_usage(char []);
int reverse = 0; // 1 if reverse sort

// sort input lines
int main(int argc, char *argv[]) {
  int nlines;      // number of input lines read
  int numeric = 0; // 1 if numeric sort

  if (argc > 3) {
    print_usage("Too many arguments");
    return -1;
  } else if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      if (mystrcmp(argv[i], "-n") == 0)
        numeric = 1;
      else if (mystrcmp(argv[i], "-r") == 0)
        reverse = 1;
      else {
        print_usage("Unknown option");
        return -1;
      }
    }
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    myqsort((void **) lineptr, 0, nlines-1,
      (int (*)(void*,void*))(numeric ? numcmp : mystrcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return -1;
  }
}

// myqsort: sort v[left]...v[right] into increasing value
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right) // do nothing if array contains
    return;          // fewer than two elements
  swap(v, left, (left+right)/2);
  last = left;
  for (i = left+1; i <= right; ++i)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  myqsort(v, left,last-1, comp);
  myqsort(v, last+1,right, comp);
}

// numcmp: compare s1 and s2 numerically
int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (reverse) {
    if (v1 < v2)
      return -1;
    else if (v1 > v2)
      return 1;
  } else {
    if (v1 > v2)
      return -1;
    else if (v1 < v2)
      return 1;
  }
  return 0;
}

// mystrcmp: compare s1 and s2 lexicographically
int mystrcmp(char *s, char *t) {
  for ( ; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  if (reverse)
    return *t - *s;
  else
    return *s - *t;
}

void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void writelines(char *lineptr[], int nlines) {
  while (nlines--)
    printf(">  %s", *lineptr++);
}

int readlines(char *linesptr[], int limit) {
  char *p, line[MAXLINE];
  int len, nlines;

  nlines = 0;
  int getaline(char[], int);

  // get a line
  while ((len = getaline(line, MAXLINE)) != 0) {
    // assign storage for line
    p = malloc(len);
    // copy line to new storage
    strcpy(p, line);
    // add pointer to the line to our array
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

void print_usage(char err[]) {
  printf("%s\n", err);
  printf("command [-n] [-r]\n");
}
