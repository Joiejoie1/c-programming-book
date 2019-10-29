#include <stdio.h>
#include <string.h>

/*
 * Write versions of the library functions strncopy, strncat, and
 * strncmp, which operate on at most the first n characters of
 * their argument strings. For example, strncopy(s,t,n) copies
 * at most n characters of t to s.
 */

char *mystrncopy(char *, char *, int);
char *mystrncat(char *, char *, int);
int mystrncmp(char *, char *, int);

int main() {
  char s[] = "hello";
  char t[] = "new string";
  
  printf("mystrncopy n=8: %s\n", mystrncopy(s,t,8));

  /* because the compiler puts these s2 and t2 strings
   * in contiguous places in memory, extending the 
   * string s2 will overwrite t2 in memory. If we don't
   * care about t2 then this works fine, although I'm 
   * not sure how to do this with pointers and not
   * be destructive
   */
  char s2[] = "hello";
  char t2[] = ", world!";

  printf("mystrncat n=40: %s\n", mystrncat(s2,t2, 40));

  char s3[] = "hellp";
  char t3[] = "hello";

  printf("mystrncmp n=2: %d\n", mystrncmp(s3, t3, 2));
  return 0;
}

/* 
 * mystrncopy: copy at most n chars of string t
 * to s, return s. Pad with '\0's if t has
 * fewer than n characters
 */
char *mystrncopy(char *s, char *t, int n) {
  char *os = s;

  for (; n > 0; n--) {
    if (*t == '\0')
      *s++ = '\0';
    else
      *s++ = *t++;
  }
  *s = '\0';

  return os;
}

/*
 * mystrncat: concatenate at most n chars of
 * string t to string s, terminate s with '\0';
 * return s.
 */
char *mystrncat(char *s, char *t, int n) {
  char *os = s;

  while (*s != '\0')
    s++;
  for (;*t != '\0' && n > 0; n --) {
    *s++ = *t++;
  }
  *s = '\0';
  return os;
}

/*
 * mystrncmp: compare at most n characters of
 * string s to string t; return <0 if s<t,
 * 0 if s == t, or >0 if s>t
 */
int mystrncmp(char *s, char *t, int n) {
  char *os = s;

  while (n != 0) {
    if (*s != *t) {
      return *s - *t;
    }
    s++;
    t++;
    n--;
  }
  return 0;
}

