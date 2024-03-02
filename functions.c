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

void DataDifference(TimeData* Data_Time_1, TimeData* Data_Time_2, TimeData* Data_Time_Dif)
{
   Data_Time_Dif->second = abs(60 - abs(Data_Time_1->second - Data_Time_2->second));
   Data_Time_Dif->minute = abs(60 - abs(Data_Time_1->minute - Data_Time_2->minute) - ((Data_Time_Dif->second > 0) ? 1 : 0));
   Data_Time_Dif->hour = abs(24 - abs(Data_Time_1->hour - Data_Time_2->hour) - ((Data_Time_Dif->minute > 0) ? 1 : 0));
   Data_Time_Dif->year = abs(Data_Time_1->year - Data_Time_2->year);
   Data_Time_Dif->month = abs((12 - Data_Time_1->month) - (12 - Data_Time_2->month) + (Data_Time_Dif->year * 12));
   Data_Time_Dif->day = abs(abs((DaysInMonth(Data_Time_1->month) - Data_Time_1->day) -
      (DaysInMonth(Data_Time_2->month) - Data_Time_2->day)) +
      (CountLeapYears(Data_Time_1->year, Data_Time_2->year)));

   if (Data_Time_1->year == Data_Time_2->year && 
      (Data_Time_Dif->second > 0 || Data_Time_Dif->minute > 0 || Data_Time_Dif->hour > 0 || Data_Time_1->month != Data_Time_2->month || Data_Time_1->day != Data_Time_2->day))
      Data_Time_Dif->year = Data_Time_Dif->year - 1;

   if (Data_Time_1->month == Data_Time_2->month && 
      (Data_Time_Dif->second > 0 || Data_Time_Dif->minute > 0 || Data_Time_Dif->hour > 0 || Data_Time_1->day != Data_Time_2->day))
      Data_Time_Dif->month = Data_Time_Dif->month - 12;

   if (Data_Time_1->day == Data_Time_2->day &&
      (Data_Time_Dif->second > 0 || Data_Time_Dif->minute > 0 || Data_Time_Dif->hour > 0))
      Data_Time_Dif->day = Data_Time_Dif->day - 1;
   
   
}

int DaysInMonth(int month)
{
   if (month % 2 == 0 && month != 2 && month < 8)
      return 30;
   else if (month == 2)
      return 28;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   else if (month % 2 == 0)
      return 31;
   else 
      return 30;
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
   int temp;
   if (year_big < year_small)
   {
      temp = year_small;
      year_small = year_big;
      year_big = temp;
   }
   while (year_big > year_small)
   {
      if (IsLeapYear(year_small))
         counter++;
      year_small++;
   }
   return counter;
}

int WhichDateIsGreater(TimeData* Data_Time_1, TimeData* Data_Time_2)
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
