#include <stdio.h>
#include <string.h>

/*
 * Write a recursive version of the function reverse(s), which
 * reverses the string s in its place
 */

void reverse(char[], int);

int main(int argc, const char *argv[])
{
  char s[] = "skip";
  reverse(s, strlen(s)-1);
  printf("%s\n", s);
  return 0;
}

void reverse(char s[], int right) {
  int c;
  // unable to set the string len as a static variable :(
  static int left = 0;

  if (left < right)
  {
    left++;
    reverse(s, right-1);
  } else {
    left--;
    return;
  }
  
  c = s[left];
  s[left] = s[right];
  s[right] = c;
  left--;
}
