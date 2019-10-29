#include <stdio.h>

#define MAX_LEN 15 // 15 characters long seems sensible

/* prints a histogram of the lengths of words coming
 * from the standard in
 */

int main() {
  int c, i, len;
  int wordLen[MAX_LEN]; 

  len = 0;

  for (i = 0; i < MAX_LEN; ++i)
    wordLen[i] = 0;
  
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (len > 0) { 
        ++wordLen[len - 1];
        len = 0;
      } 
    } else {
      ++len;
    } 
  }

  for (i = 0; i < MAX_LEN; ++i){  
    printf("%2d: ", i + 1); 
    for(int j = 1; j <= wordLen[i]; ++j)
      putchar('-');
    printf("\n");
  }
}
