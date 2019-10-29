#include <stdio.h>

#define IN  1
#define OUT 0

/* print every word from the input on its own line */

int main() {
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t'){
      if (state == IN) {
        putchar('\n');
        state = OUT;
      }     
    } else {
        putchar(c);
        state = IN;
    }
  }
}
