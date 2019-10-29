#include <stdio.h>

#define swap(t,x,y) t tmp; tmp = x, x = y, y = tmp 

/* 
 * Define a macro swap(t,x,y) that interchanges two arguments of type t
 */

int main() {
  int x, y;
  x = 1;
  y = 2;
  printf("before\tx: %d  y: %d\n", x, y);
  swap(int, x, y);
  printf("after\tx: %d  y: %d\n", x, y);
  return 0;
}
