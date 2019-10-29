#include <stdio.h>

#define IN_WORD  1
#define OUT_WORD 0
#define BUFFER 5000

/* 
 * removes all trailing whitespace from the
 * end of input lines. skips entirely blank
 * lines
 */

int main() {
  int c, i, state, position;
  char line[BUFFER];

  i = 0;
  while ((c = getchar()) != EOF) {
    line[i] = c;

    if (c != '\n') {
      ++i;
    } else {
      if(i == 0)
        continue; //ignore blank lines
      for(int j = 0; j <= i; ++j) {
        if(line[j] == ' ' || line[j] == '\t') {
          if(state == IN_WORD) 
            position = j;
          state = OUT_WORD;
        } else if (line[j] == '\n') {
          continue; // don't let newline affect state
        } else {
          state = IN_WORD;
        }
      }
      if (state == OUT_WORD) 
        line[position] = '\n'; // replace the new line after the last letter
      else 
        position = i;
      
      for(int j = 0; j <= position; ++j)
        putchar(line[j]);
      i = 0;
    } 
  }
}
