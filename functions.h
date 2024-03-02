#pragma once
#include <stdbool.h>
#include "structs.h"

/*
* @brief Проверка на високосный год
* @param year Год требующий проверки
* @return 1 Если год високосный, 0 иначе
*/
bool IsLeapYear(unsigned int year);

/*
* @brief Разница между двумя датами
* @param Data_Time Дата #1
* @param Today_Time Дата #2
*/
void DataDifference(TimeData* Data_Time_1, TimeData* Data_Time_2, TimeData* Data_Time_Dif);


int DaysInMonth(int month);

int FromMonthsToDays(int month);

int CountLeapYears(int year_big, int year_small);

int WhichDateIsGreater(TimeData* Data_Time_1, TimeData* Data_Time_2);