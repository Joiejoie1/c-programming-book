#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000
#define NUMBER '0'  /* signal that a number was found */

/*
 * Rewrite appropriate proframms from earlier chapters and
 * exercises with pointers instead of array indexing. Good
 * possibilities include getline (Chapters 1 and 4), atoi,
 * itoa, and their variants (Chapters 2, 3, and 4), reverse
 * (Chapter 3), and strindex and getop (Chapter 4).
 */

int mygetline(char *, int);
int atoi(char *);
int atoi2(char *);
double atof(char *);
int atoi3(char *);
void reverse(char *);
int strindex(char *, char *);
int getop(char *);

int main() {
  /* mygetline */

  /* char s[MAXLINE]; */
  /* while (mygetline(s, MAXLINE) > 0) { */
  /*   printf("you entered: %s", s); */
  /* } */

  /* atoi */

  char s[] = "12345 hello";
  printf("atoi return: %d\n", atoi(s));
  
  /* atoi2 */

  char s2[] = "12345 world";
  printf("atoi2 return %d\n", atoi2(s2));

  /* atoi3 */

  char s3[] = "12.345 extra";
  printf("atoi3 return %d\n", atoi3(s3));

  /* reverse */
  char s4[] = "reverse me";
  reverse(s4);
  printf("reverse: %s\n", s4);

  /* strindex */
  char s5[] = "hello, world";
  char s6[] = "world";
  printf("strindex: %d\n", strindex(s5,s6));

  /* getop */
  
  int type;
  char s7[100]; // 100 is max size of operand or operator

  printf("enter a character for getop > ");
  switch (type = getop(s)) {
    default:
      printf("getop: %c\n", type);
      break;
  }
}

/* mygetline: read a line into 3, return length */
int mygetline(char *s, int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
    *s++ = c;
  if (c == '\n') {
    *s++ = c;
    ++i;
  }
  *s = '\0';
  return i;
}

/* atoi: convert s to int */
int atoi(char *s) {
  int n = 0;
  while (*s >= '0' && *s <= '9')
    n = 10 * n + (*s++ - '0');
  return n;
}

/*atoi2: convert s to int version 2 */
int atoi2(char *s) {
  int n, sign;

  while (isspace(*s))
    s++;

  sign = (*s == '-') ? -1 : 1;

  if (*s == '+' || *s == '-')
    s++;

  n = 0;
  while (isdigit(*s)) {
    n = 10 * n + (*s++ - '0');
  }
  return sign * n;
}

/* atof: convert s to double */
double atof(char *s) {
  double val, power;
  int sign;

  while (isspace(*s))
    s++;

  sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-')
    s++;

  val = 0.0;
  while (isdigit(*s)) {
    val = 10.0 * val + (*s - '0');
    s++;
  }

  if (*s == '.')
    s++;

  power = 1.0;
  while (isdigit(*s)) {
    val = 10.0 * val + (*s - '0');
    power *= 10.0;
    s++;
  }
  return sign * val / power;
}

/* atoi3: convert s to int using atof */
int atoi3(char *s) {
  return (int)atof(s);
}

/* reverse: reverse string s in place */
void reverse(char *start) {
  int c;
  char *end = start;

  while (*end != '\0')
    end++;

  end--; // back up one so we are on a letter not null

  while (start < end) {
    c = *start;
    *start = *end;
    *end = c;
    start++;
    end--;
  } 
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t) {
  int i;
  char *start_of_t = t;
  char *s_iterator;

  for (i = 0; *s != '\0'; i++) {
    t = start_of_t;
    s_iterator = s;
    while (*t != '\0' && *s_iterator == *t)
      t++, s_iterator++;
    if (t > start_of_t && *t == '\0')
      return i;
    s++;
  }
  return -1;
}

// functions required by getop to work
int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char *s) {
  int i, c;

  while ((*s = c = getch()) == ' ' || c == '\t')
    ;
  *++s = '\0';
  if (!isdigit(c) && c != '.')
    return c;     /* not a number */

  if (isdigit(c)) /* collect integer part */
    while (isdigit(*s++ = c = getch()))
      ;
  if (c == '.')   /* collect fraction part */
    while  (isdigit(*s++ = c = getch()))
      ;
  *s = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
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

