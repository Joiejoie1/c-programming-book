#include <stdio.h>
#include <ctype.h>

/*
 * Write getfloat, the floating-point analog of getint.
 * What type does getfloat return as its function value;
 */

int getfloat(double *);

int main() {
  double num;
  while (getfloat(&num) != 0)
    printf("\tyou entered the number %f\n", num);
}

int getch(void);
void ungetch(int);

/* getfloat: get next float from input into *pn */
int getfloat(double *pn) {
  int c, sign;
  int decimal_places = 1;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); // it's not a number
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  if (!isdigit(c)) {
    ungetch(c);
    return 0;
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  if (c == '.' ) {
    while((c = getch()) && isdigit(c)) {
      *pn = 10 * *pn + (c - '0');
      decimal_places *= 10;
    } 
  }
  *pn /= decimal_places;
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int  bufp = 0;      /* next free position in buf */

int getch(void) {   /* get a (possibly pushed back) character */
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {  /* push character back on input */
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
