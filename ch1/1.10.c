#include <stdio.h>

/* replace each tab and backspace with
 * escape characters instead
 *
 * note: input is buffered so backspaces
 *       won't work.
 */

int main() {
  int c;

  while ((c =getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    } else if (c == '\b') {
      printf("\\b");
    } else if (c == '\\') {
      printf("\\\\");
    } else {
      putchar(c);
    }
  }
}
