#include <stdio.h>

#define BUFFER 81 // a length of 80 characters and space for a null
#define SHORT_LINE 0
#define LONG_LINE  1

/* write a program that will print lines that are longer than 
 * 80 characters in length
 */
int main() {
  char buffer[BUFFER];
  int c, i, state;
  
  i = 0;
  while((c = getchar()) != EOF) {
    if(i < BUFFER - 1) { // store shorter strings in buffer
      if (c != '\n') {
        buffer[i] = c;
        ++i;
        continue;
      } else {
        i = 0; // got a short string, reset buffer counter
      }
    } else {
      // we have a longer string so print the buffer
      if(state == SHORT_LINE && c != '\n') {
        buffer[i] = c;
        buffer[i + 1] = '\0'; // terminate the string with a null
        printf("%s", buffer);
        state = LONG_LINE;
      } else if(c == '\n') {
        // got a new line so rest everything
        putchar(c);
        state = SHORT_LINE;
        i = 0;
      } else {
        putchar(c);
      }
    }
  }
}

