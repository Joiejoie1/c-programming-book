#include <stdio.h>

/* 
 * Rewrite the routine day_of_year and month_day with
 * pointers instead of indexing
 */

int day_of_year(int year, int month, int day);
void month_day(int, int, int *, int *);

int main() {
  int year, month, day;

  printf("Day of year\nyear? ");
  scanf("%d", &year);

  printf("month? ");
  scanf("%d", &month);

  printf("day? ");
  scanf("%d", &day);

  int day_year = day_of_year(year, month, day);

  if (day_year < 0) {
    printf("Error calculating day of year\n");
    return -1;
  }
  printf("Day of the year for %d-%d-%d is %d\n", year, month, day, day_year);
  
  int pday, pmonth;
  month_day(year, day_year, &pmonth, &pday);
  printf("Month: %d\n", pmonth);
  printf("Day: %d\n", pday);
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int is_leap_year(int year);

int day_of_year(int year, int month, int day) {

  if (month < 1 || month > 12 || day < 1 || day > 31)
    return -1;

  char *pyear = &daytab[is_leap_year(year)][1];

  while (month > 1) {
    day += *pyear++;
    month--;
  }
  return day;
}
  
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  leap = is_leap_year(year);
  if (yearday < 0 || (leap == 1 && yearday > 366) || (leap == 0 && yearday > 365)) {
    *pmonth = -1;
    *pday = -1;
  }
  char *pyear = &daytab[leap][1];
  i = 1;
  do{
    yearday -= *pyear++;
    i++;
  } while (yearday > *pyear);

  *pmonth = i;
  *pday = yearday;
}

int is_leap_year(int year) {
  return year%4 == 0 && (year%100 != 0 || year%400 == 0);
}
