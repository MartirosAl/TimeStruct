#include "functions.h"
#include <stdlib.h>
#include <stdbool.h>

bool IsLeapYear(unsigned int year)
{
   if (year % 400 == 0)
      return true;
   else if (year % 100 == 0)
      return false;
   else if (year % 4 == 0)
      return true;

   return false;
}

long long int DataDifference(struct TimeData Data_Time_1, struct TimeData Data_Time_2)
{
   int yearstoday1 = FromYearsToDays(Data_Time_1.year);
   int yearstoday2 = FromYearsToDays(Data_Time_2.year);

   int monthinday1 = FromMonthsToDays(Data_Time_1.month) - (IsLeapYear(Data_Time_1.year) == 0 ? 2 : 1);
   int monthinday2 = FromMonthsToDays(Data_Time_2.month) - (IsLeapYear(Data_Time_2.year) == 0 ? 2 : 1);
   
   return (abs(yearstoday1 - yearstoday2)*24*60*60 + 
       abs(monthinday1 - monthinday2) *24*60*60 + 
       abs(Data_Time_1.day - Data_Time_2.day) *24*60*60 + 
       abs(Data_Time_1.hour - Data_Time_2.hour) *60*60 + 
       abs(Data_Time_1.minute - Data_Time_2.minute) *60 +
       abs(Data_Time_1.second - Data_Time_2.second));
}

int FromMonthsToDays(int month)
{
    int days = 0;
    while (month != 0)
    {
        month -= 1;
        days = days + month % 2 == 0 ? 31 : 30;
        days = days + month == 7 ? 1 : 0;
    }
    return days;
}

unsigned int FromYearsToDays(int year)
{
    int days = 0;
    while (year > 1)
    {
        year -= 1;
        if (IsLeapYear(year))
            days += 366;
        else
            days += 365;
    }
    return days;
}