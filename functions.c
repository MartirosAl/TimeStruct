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

long long int DataDifference(struct TimeData Data_Time, struct TimeData Today_Time)
{
   int monthinday1 = 0;
   int monthinday2 = 0;

   while (Data_Time.month != 0)
   {
      Data_Time.month -= 1;
      monthinday1 = Data_Time.month % 2 == 0 ? monthinday1 + 31 : monthinday1 + 30;
   }
   while (Today_Time.month != 0)
   {
      Today_Time.month -= 1;
      monthinday2 = Today_Time.month % 2 == 0 ? monthinday2 + 31 : monthinday2 + 30;
   }

   if (Data_Time.month > 2)
      monthinday1 = IsLeapYear == 0 ? monthinday1 - 2 : monthinday1 - 1;
   if (Today_Time.month > 2)
      monthinday2 = IsLeapYear == 0 ? monthinday2 - 2 : monthinday2 - 1;

   return (abs(Data_Time.year - Today_Time.year)*365*24*60*60 + abs(monthinday1 - monthinday2)*24*60*60 + abs(Data_Time.day - Today_Time.day)*24*60*60 
               + abs(Data_Time.hour - Today_Time.hour)*60*60 + abs(Data_Time.minute - Today_Time.minute)*60 + abs(Data_Time.second - Today_Time.second));
}
