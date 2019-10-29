#include <stdio.h>

#define BUFFER 1000
/*
 * Write a function 'reverse' that reverse
 * the character string 's'. Use it to write
 * a program that reverse it's input a line 
 * at a time.
 */

void reverse(char s[], int len);
int my_getline(char s[], int limit);

int main() {
  int len;
  char line[BUFFER];

  while ((len = my_getline(line, BUFFER)) != 0) {
    reverse(line, len); 
    printf("%s", line);
  }
}

int my_getline(char s[], int limit) {
  int c, i;

  for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
    s[i] = c;
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void reverse(char s[], int total_len) {
  int a, b;
  int str_len = total_len - 1;
  for(int i = 0; i < str_len / 2; ++i) {
    a = s[i];
    b = s[(str_len - i)-1];
    s[i] = b;
    s[(str_len - i)-1] = a;
  }
}
