#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * Write the program expr, which evaluates a reverse Polish expression
 * from the command line, where each operator or operand is a separate
 * argument. For example: `expr 2 3 4 + *` evaluates to `2 x (3+4)`
 */

double buffer[10];
double *bufp = &buffer[0];
double pop();
void shift(double);

int main(int argc, char *argv[]) {
  double op2;

  while (*++argv != '\0') {
    if (isdigit(**argv)) {
      shift(atoi(*argv));
      continue;
    }
    switch (*argv[0]) {
      case '+':
        shift(pop() + pop());
        break;
      case '-':
        op2 = pop();
        shift(pop() - op2);
        break;
      case '*':
        shift(pop() * pop());
        break;
      case '/':
        op2 = pop();
        shift(pop() / op2);
        break;
      default:
        printf("unknown command %c\n", *argv[0]);
    }
  }
  printf("result: %f\n", pop());
}

double pop() {

  return bufp >= &buffer[0] ? *bufp-- : 0;
}

void shift(double num) {
  *++bufp = num;
}

