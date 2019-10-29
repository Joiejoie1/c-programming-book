#include <stdio.h>

/*
 * Write a pointer version of the function strcat that
 * we showed in Chapter 2: strcat(s,t) copies the string
 * t to the end of s
 */

void mystrcat(char*, char*);

int main() {
  char s[] = "Hello";
  char t[] = ", World!";
  mystrcat(s, t);
  printf("s: %s\n", s);
}

/* strcat: concatenate t to end of s; s must be big enough */
void mystrcat(char *s, char *t) {
  while (*s++ != '\0') // find end of s
    ;
  s--; // go back one set and overwrite the null character
  while ((*s++ = *t++) != '\0') // copy t
    ;
}
