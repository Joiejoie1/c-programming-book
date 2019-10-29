#include <stdio.h>
#include <string.h>

/* Rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage. How much faster
 * is the program?
 */

#define MAXLINES 5000   // max lines to be sorted
#define ALLOCSIZE 10000 // available storage space

int readlines(char *lineptr[], int nlines, char lines[]);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

char *lineptr[MAXLINES]; // pointers to text lines
char *allocp;

/* sort input lines */
int main() {
  int nlines; // number of input lines read

  char allocbuf[ALLOCSIZE];
  allocp = allocbuf;

  if ((nlines = readlines(lineptr, MAXLINES, allocbuf)) >= 0) {
    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too large to sort\n");
    return 1;
  }
}

#define MAXLEN 1000 // max length of line
int my_getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char buffer[]) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = my_getline(line, MAXLEN)) > 0)
  {
    if (buffer + ALLOCSIZE - allocp >= len) {
      p = allocp;
      allocp += len;
    } else {
      p = NULL;
    }
    if (nlines >= maxlines || p == NULL) {
      return -1;
    }
    else {
      line[len-1] = '\0'; // delete new line
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

int my_getline(char s[], int lim) {
  int c, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

