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
void DataDifference(struct TimeData* Data_Time_1, struct TimeData* Data_Time_2, struct TimeData* Data_Time_Dif);


