#include <stdio.h>

/* count lines, blanks, and tabs in input */

int main() {
  int c, nl, b, t;

  nl = 0;
  b = 0;
  t = 0;
  while((c = getchar()) != EOF)
    if (c == '\n'){
      ++nl;
    } else if (c == '\t'){
      ++t;
    } else if (c == ' ') {
      ++b;
    }
  printf("newlines: %3d\n", nl);
  printf("tabs:     %3d\n", t);
  printf("blanks:   %3d\n", b);
}
