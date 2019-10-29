#include <stdio.h>

/* replace each string of one or more blanks
 * with a single blank
 */

int main() {
  int seenBlank, c;

  seenBlank = 0;
  while ((c =getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
      seenBlank = 0;
    } else if (c == ' ' && seenBlank == 0){
      putchar(c);
      seenBlank = 1;
    }
  }
}
