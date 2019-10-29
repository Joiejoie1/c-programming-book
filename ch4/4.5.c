#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

/* 
 * Add access to library functions like sin, exp, and pow.
 */

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void print_top(void);
void duplicate(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        push(fmod(pop(), op2));
        break;
      case 'e':
        push(exp(pop()));
        break;
      case 's':
        push(sin(pop()));
        break;
      case 'p':
        op2 = pop();
        push(pow(pop(), op2));
        break;
      case '>':
        print_top();
        break;
      case 'd':
        duplicate();
        break;
      case '~':
        swap();
        break;
      case 'c':
        clear();
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unkown command %s\n", s);
        break;
    }
  }
  return 0;
}

#define MAXVAL 100   /* maximum depth of val stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* print_top: print top value on stack */
void print_top(void) {
  if (sp > 0)
    printf("\ttop value on the stack: %g\n", val[sp-1]);
  else
    printf("\tthere is nothing on the stack to print\n");
}

/* duplicate: duplicate the item on the top of the stack */
void duplicate(void) {
  double item;
  if (sp > 0) {
    item = val[sp-1];
    val[sp++] = item;
  } else {
    printf("error: stack empty, nothing to duplicate\n");
  }

}

/* swap: swap the top two elements on the top of the stack */
void swap(void) {
  double temp;
  if (sp > 1) {
    temp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = temp;
  }
  else
    printf("error: not emough elements to swap");
}

/* clear: clear the val stack */
void clear(void) {
  sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
    return c;     /* not a number */
  i = 0;

  if (c == '-') { /* check if - is for negative number */
    if (isdigit(s[++i] = c = getch())) {
      s[0] = '-';
      while (isdigit(s[++i] = c = getch()))
        ;
    } else {
      ungetch(c);
      return '-';
    }
  }

  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.')   /* collect fraction part */
    while  (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';

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
