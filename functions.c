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

void DataDifference(struct TimeData* Data_Time_1, struct TimeData* Data_Time_2,struct TimeData* Data_Time_Dif)
{
   Data_Time_Dif->year = Data_Time_1->year - Data_Time_2->year - 1;
   Data_Time_Dif->month = (12 - Data_Time_1->month) + (12 - Data_Time_2->month) + (Data_Time_Dif->year * 12);
   Data_Time_Dif->day = (FromMonthToDays(Data_Time_1->month) + DaysInMonth(Data_Time_1->month) - Data_Time_1->day) +
      (FromMonthToDays(Data_Time_2->month) + DaysInMonth(Data_Time_2->month) - Data_Time_2->day) +
      (CountLeapYears(WhichDateIsGreater(&Data_Time_1, &Data_Time_2) == 1 ? Data_Time_1->year : Data_Time_2->year,
                      WhichDateIsGreater(&Data_Time_1, &Data_Time_2) == 1 ? Data_Time_2->year : Data_Time_1->year));
   Data_Time_Dif->hour = abs(Data_Time_1->hour - Data_Time_2->hour);
   Data_Time_Dif->minute = abs(Data_Time_1->minute - Data_Time_2->minute);
   Data_Time_Dif->second = abs(Data_Time_1->second - Data_Time_2->second);
}

int DaysInMonth(int month)
{
   if (month % 2 == 0 && month != 2 && month != 7)
      return 30;
   else if (month == 2)
      return 28;
   else if (month == 7)
      return 31;
   return 31;
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

int CountLeapYears(int year_big, int year_small)
{
   int counter = 0;
   while (year_big > year_small)
   {
      if (IsLeapYear(year_small))
         counter++;
      year_small++;
   }
   return counter;
}

int WhichDateIsGreater(struct TimeData* Data_Time_1, struct TimeData* Data_Time_2)
{
   if (Data_Time_1->year == Data_Time_2->year)
      if (Data_Time_1->month == Data_Time_2->month)
         if (Data_Time_1->day == Data_Time_2->day)
            if (Data_Time_1->hour == Data_Time_2->hour)
               if (Data_Time_1->minute == Data_Time_2->minute)
                  if (Data_Time_1->second == Data_Time_2->second)
                     return 0;
                  else if (Data_Time_1->second > Data_Time_2->second)
                     return 1;
                  else
                     return 2;
               else if (Data_Time_1->minute > Data_Time_2->minute)
                  return 1;
               else
                  return 2;
            else if (Data_Time_1->hour > Data_Time_2->hour)
               return 1;
            else
               return 2;
         else if (Data_Time_1->day > Data_Time_2->day)
            return 1;
         else
            return 2;
      else if (Data_Time_1->month > Data_Time_2->month)
         return 1;
      else
         return 2;
   else if (Data_Time_1->year > Data_Time_2->year)
      return 1;
   else
      return 2;
}
