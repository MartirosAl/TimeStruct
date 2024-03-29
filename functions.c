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
   //Yandere hello
   Data_Time_Dif->second = Data_Time_1->second - Data_Time_2->second;

   Data_Time_Dif->minute = Data_Time_1->minute - Data_Time_2->minute;
   if (Data_Time_Dif->second < 0)
   {
      Data_Time_Dif->second = abs(Data_Time_Dif->second);
      if (Data_Time_Dif->minute != 0)
         Data_Time_Dif->minute = Data_Time_Dif->minute + Data_Time_Dif->minute < 0 ? 1 : -1;
      else if (Data_Time_Dif->hour != 0)
         Data_Time_Dif->hour = Data_Time_Dif->hour + Data_Time_Dif->hour < 0 ? 1 : -1;
      else if (Data_Time_Dif->day != 0)
         Data_Time_Dif->day = Data_Time_Dif->day + Data_Time_Dif->day < 0 ? 1 : -1;
      else if (Data_Time_Dif->month != 0)
         Data_Time_Dif->month = Data_Time_Dif->month + Data_Time_Dif->month < 0 ? 1 : -1;
      else
         Data_Time_Dif->year = Data_Time_Dif->year - 1;
   }

   Data_Time_Dif->hour = Data_Time_1->hour - Data_Time_2->hour;
   if (Data_Time_Dif->minute < 0)
   {
      Data_Time_Dif->minute = abs(Data_Time_Dif->minute);
      if (Data_Time_Dif->hour != 0)
         Data_Time_Dif->hour = Data_Time_Dif->hour + Data_Time_Dif->hour < 0 ? 1 : -1;
      else if (Data_Time_Dif->day != 0)
         Data_Time_Dif->day = Data_Time_Dif->day + Data_Time_Dif->day < 0 ? 1 : -1;
      else if (Data_Time_Dif->month != 0)
         Data_Time_Dif->month = Data_Time_Dif->month + Data_Time_Dif->month < 0 ? 1 : -1;
      else
         Data_Time_Dif->year = Data_Time_Dif->year - 1;
   }

   Data_Time_Dif->day = Data_Time_1->day - Data_Time_2->day;
   if (Data_Time_Dif->hour < 0)
   {
      Data_Time_Dif->hour = abs(Data_Time_Dif->hour);
      if (Data_Time_Dif->day != 0)
         Data_Time_Dif->day = Data_Time_Dif->day + Data_Time_Dif->day < 0 ? 1 : -1;
      else if (Data_Time_Dif->month != 0)
         Data_Time_Dif->month = Data_Time_Dif->month + Data_Time_Dif->month < 0 ? 1 : -1;
      else
         Data_Time_Dif->year = Data_Time_Dif->year - 1;
   }

   Data_Time_Dif->month = Data_Time_1->month - Data_Time_2->month;
   if (Data_Time_Dif->day < 0)
   {
      Data_Time_Dif->day = abs(Data_Time_Dif->day);
      if (Data_Time_Dif->month != 0)
         Data_Time_Dif->month = Data_Time_Dif->month + Data_Time_Dif->month < 0 ? 1 : -1;
      else
         Data_Time_Dif->year = Data_Time_Dif->year - 1;
   }

   Data_Time_Dif->year = Data_Time_1->year - Data_Time_2->year;
   if (Data_Time_Dif->month < 0)
   {
      Data_Time_Dif->month = abs(Data_Time_Dif->month);
      Data_Time_Dif->year = Data_Time_Dif->year - 1;
   }
   

   
}

int DaysInMonth(int month)
{
   switch (month)
   {
   case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      return 31;
   case 4: case 6: case 9: case 11:
      return 30;
   case 2:
      return 28;
   }

}

int FromMonthsToDays(int month)
{
   int days = 0;
   while (month != 0)
   {
      month -= 1;
      days = days + DaysInMonth(month);
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
                     return 0;
                  else
                     return 1;
               else if (Data_Time_1->minute > Data_Time_2->minute)
                  return 0;
               else
                  return 1;
            else if (Data_Time_1->hour > Data_Time_2->hour)
               return 0;
            else
               return 1;
         else if (Data_Time_1->day > Data_Time_2->day)
            return 0;
         else
            return 1;
      else if (Data_Time_1->month > Data_Time_2->month)
         return 0;
      else
         return 1;
   else if (Data_Time_1->year > Data_Time_2->year)
      return 0;
   else
      return 1;
}
