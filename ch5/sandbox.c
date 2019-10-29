#include <stdio.h>

int main() {
  int nums[10] = {1,2,3,4,5,6,7,8,9,10};
  int *pn;

  pn = &nums[0];
  *pn = 11;
  *nums = 7;
  printf("%d\n", nums[0]);
}
