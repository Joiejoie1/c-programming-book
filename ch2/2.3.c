#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000

/*
 * Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into
 * its equivalent integer value. The allowable digits are 0
 * through 9, a through f, and A through F.
 */

int getaline(char s[], int limit);
long int htoi(char s[], int len);

int main() {
  long int result;
  int len;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) != 0) {
    result = htoi(line, len);
    printf("%s = %ld\n", line, result);
  }
  return 0;
}

// This is far from perfect, but it does the basic job
long int htoi(char s[], int len) {
  long int result;
  int exponent, c;
  
  result = 0;
 
  for (int i = len - 1; i >= 0; --i) {
    // set the exponent
    if (i == len-1)
      exponent = 0;
    else
      ++exponent;

    if (isxdigit(s[i])) {
      if (isalpha(s[i]))  {
        c = tolower(s[i]);

        if (c >= 'a' && c <= 'f') {
          c -= 87; // Minus 87 to get decimal value
          if (exponent > 0)
            result += c * pow(16, exponent); 
          else
            result += c;
        } else {
          continue;
        }
      } else {
        // if not alpha then it's a digit
        c = s[i];
        if (c == 0 && i == 0 && i+1 < len && (s[i+1] == 'x' || s[i+1] != 'X')) {
          continue; // we have reach the beginning of the string 0x or 0X
        }
        else {
          c -= 48; // convert to decimal value
          if (exponent > 0)
            result += c * pow(16, exponent); 
          else
            result += c - 48;
        }
      }
    }
  }
  return result;
}

int getaline(char s[], int limit) {
  int i, c;

  for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  // ignore the newline for now
  s[i] = '\0';
  return i;
}
