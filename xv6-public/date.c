#include "types.h"
#include "user.h"
#include "date.h"

int
main(int argc, char *argv[])
{
  struct rtcdate r;
  
  if (date(&r)) {
    printf(2, "date failed\n");
    exit();
  }
  char month[4];
  switch (r.month){
    case 1:
      strcpy(month, "Jan\0");
      break;
    case 2:
      strcpy(month, "Feb\0");
      break;
    case 3:
      strcpy(month, "Mar\0");
      break;
    case 4:
      strcpy(month, "Apr\0");
      break;
    case 5:
      strcpy(month, "May\0");
      break;
    case 6:
      strcpy(month, "Jun\0");
      break;
    case 7:
      strcpy(month, "Jul\0");
      break;
    case 8:
      strcpy(month, "Aug\0");
      break;
    case 9:
      strcpy(month, "Sep\0");
      break;
    case 10:
      strcpy(month, "Oct\0");
      break;
    case 11:
      strcpy(month, "Nov\0");
      break;
    case 12:
      strcpy(month, "Dec\0");
      break;
  }
  
  int sum = (r.year % 100) + 0.25 * (r.year%100);
  int day = sum % 7;
  
  char d[4];
  switch (day){
    case 0:
      strcpy(d, "Mon\0");
      break;
    case 1:
      strcpy(d, "Tue\0");
      break;
    case 2:
      strcpy(d, "Wed\0");
      break;
    case 3:
      strcpy(d, "Thu\0");
      break;
    case 4:
      strcpy(d, "Fri\0");
      break;
    case 5:
      strcpy(d, "Sat\0");
      break;
    case 6:
      strcpy(d, "Sun\0");
      break;
  }
  if(argc == 1){
    if(r.hour > 9 && r.minute > 9)
      printf(1, "%s %s  %d %d:%d EET %d\n", d, month, r.day, r.hour, r.minute, r.year); 
    else if(r.hour > 9 && r.minute < 9)
      printf(1, "%s %s  %d %d:0%d EET %d\n", d, month, r.day, r.hour, r.minute, r.year); 
    else if(r.hour < 9 && r.minute < 9)
      printf(1, "%s %s  %d 0%d:0%d EET %d\n", d, month, r.day, r.hour, r.minute, r.year); 
    else
      printf(1, "%s %s  %d 0%d:%d EET %d\n", d, month, r.day, r.hour, r.minute, r.year); 
   }
  exit();
}
