#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

/* 
 * Suppose that there will never be more than one character of
 * pushback. Modify getch and ungetch accordingly
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
void set_variable(double, char);
double get_variable(char v);

double $, a, b, c, d, e, f, g, h, i, j, k, l, m;
double n, o, p, q, r, s, t, u, v, w, x, y, z;

/* reverse Polish calculator */
int main() {
  int type, v_op, v_val, variable, c;
  double op2, result;
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
          printf("\terror: zero divisor\n");
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
      case 'v':
        /* to set a variable use 'vs' followed by the letter of
         * the variable and the value e.g. vsa1 (variable set 'a' with 1)
         *
         * to use a variable use 'vg' followed by the letter of
         * the variable e.g. vga (variable get 'a')
         *
         * the last printed result will be saved in the variable $
         *
         * example: vsa1
         *          vga 1 +
         *                2
         *          vg$ 2 +
         *                4
         */
        v_op = getop(s);
        if (v_op == 's') {
          variable = getop(s);
          getop(s); // pull out value to store in variable
          v_val = atof(s);
          set_variable(v_val, variable);
        } else if (v_op == 'g') {
          variable = getop(s);
          push(get_variable(variable));
        } else {
          printf("\terror: unknown variable operation\n");
        }

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
        result = pop();
        printf("\t%.8g\n", result);
        set_variable(result, '$');
        break;
      default:
        printf("\terror: unkown command %s\n", s);
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
    printf("\terror: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("\terror: stack empty\n");
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
    printf("\terror: stack empty, nothing to duplicate\n");
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
    printf("\terror: not emough elements to swap");
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

#define BUFFULL  1
#define BUFEMPTY 0

char buf[1];  /* buffer for ungetch */
int bufstate = BUFEMPTY;

int getch(void) {   /* get a (possibly pushed back) character */
  char c;
  if (bufstate == BUFFULL) {
    c = buf[0];
    bufstate = BUFEMPTY;
  } else {
    c = getchar();
  }
  
  return c;
}

void ungetch(int c) {  /* push character back on input */
  buf[0] = c;
  bufstate = BUFFULL;
}

/* set_variable: set number to a single letter variable */
void set_variable(double n, char v) {
  switch (v) {
    case 'a':
      a = n;
      break;
    case 'b':
      b = n;
      break;
    case 'c':
      c = n;
      break;
    case 'd':
      d = n;
      break;
    case 'e':
      e = n;
      break;
    case 'f':
      f = n;
      break;
    case 'g':
      g = n;
      break;
    case 'h':
      h = n;
      break;
    case 'i':
      i = n;
      break;
    case 'j':
      j = n;
      break;
    case 'k':
      k = n;
      break;
    case 'l':
      l = n;
      break;
    case 'm':
      m = n;
      break;
    case 'n':
      n = n;
      break;
    case 'o':
      o = n;
      break;
    case 'p':
      p = n;
      break;
    case 'q':
      q = n;
      break;
    case 'r':
      r = n;
      break;
    case 's':
      s = n;
      break;
    case 't':
      t = n;
      break;
    case 'u':
      u = n;
      break;
    case 'v':
      v = n;
      break;
    case 'w':
      w = n;
      break;
    case 'x':
      x = n;
      break;
    case 'y':
      y = n;
      break;
    case 'z':
      z = n;
      break;
    case '$':
      $ = n;    // last printed value 
      break;
    default:
      printf("\terror: unable to set variable %c\n", v);
  }
}

double get_variable(char v) {
  switch (v) {
    case 'a':
      return a;
      break;
    case 'b':
      return b;
      break;
    case 'c':
      return c;
      break;
    case 'd':
      return d;
      break;
    case 'e':
      return e;
      break;
    case 'f':
      return f;
      break;
    case 'g':
      return g;
      break;
    case 'h':
      return h;
      break;
    case 'i':
      return i;
      break;
    case 'j':
      return j;
      break;
    case 'k':
      return k;
      break;
    case 'l':
      return l;
      break;
    case 'm':
      return m;
      break;
    case 'n':
      return n;
      break;
    case 'o':
      return o;
      break;
    case 'p':
      return p;
      break;
    case 'q':
      return q;
      break;
    case 'r':
      return r;
      break;
    case 's':
      return s;
      break;
    case 't':
      return t;
      break;
    case 'u':
      return u;
      break;
    case 'v':
      return v;
      break;
    case 'w':
      return w;
      break;
    case 'x':
      return x;
      break;
    case 'y':
      return y;
      break;
    case 'z':
      return z;
      break;
    case '$':
      return $;
      break;
    default:
      printf("\terror: not a variable\n");
      return 0;
      break;
  }
}
