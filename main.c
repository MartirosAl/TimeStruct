#include <stdio.h>
#include "functions.h"

int main()
{
	system("chcp 1251"); //Русский язык
	system("cls");

	//Структуры для даты и времени
	struct TimeData* Data_Time_1 = malloc(sizeof(struct TimeData)); 
	struct TimeData* Data_Time_2 = malloc(sizeof(struct TimeData));
	struct TimeData* Data_Time_Dif = malloc(sizeof(struct TimeData));

	printf("Enter first date and time in format day.month.year hours:minuts:seconds: "); //Ввод данных 
	scanf_s("%d.%d.%d %d:%d:%d", &Data_Time_1->day, &Data_Time_1->month, &Data_Time_1->year, &Data_Time_1->hour, &Data_Time_1->minute, &Data_Time_1->second);

	printf("Enter second date and time in format day.month.year hours:minuts:seconds: "); //Ввод данных 
	scanf_s("%d.%d.%d %d:%d:%d", &Data_Time_2->day, &Data_Time_2->month, &Data_Time_2->year, &Data_Time_2->hour, &Data_Time_2->minute, &Data_Time_2->second);

	//Проверки на правильность введенных данных 
	if (Data_Time_1->month > 12 || (Data_Time_1->month % 2 == 0 ? Data_Time_1->day > 31 : Data_Time_1->day > 30) ||
		Data_Time_1->hour > 23 || Data_Time_1->minute > 59 || Data_Time_1->second > 59 || Data_Time_1->year == 0 ||
		Data_Time_1->month == 0 || Data_Time_1->day == 0)
	{
		printf("ERROR DATA\n");
		return 0;
	}
	if (Data_Time_2->month > 12 || (Data_Time_2->month % 2 == 0 ? Data_Time_2->day > 31 : Data_Time_2->day > 30) ||
		Data_Time_2->hour > 23 || Data_Time_2->minute > 59 || Data_Time_2->second > 59 || Data_Time_2->year == 0 ||
		Data_Time_2->month == 0 || Data_Time_2->day == 0)
	{
		printf("ERROR DATA\n");
		return 0;
	}

	//Проверка на високосный год и 29 февраля
	if (!IsLeapYear(Data_Time_1->year))
		if (Data_Time_1->month == 2 && Data_Time_1->day > 28)
		{
			printf("ERROR DATA\n");
			return 0;
		}
		else
			printf("It's not a leap year\n");
	else
		printf("It's a leap year\n");

	if (!IsLeapYear(Data_Time_2->year))
		if (Data_Time_2->month == 2 && Data_Time_2->day > 28)
		{
			printf("ERROR DATA\n");
			return 0;
		}
		else
			printf("It's not a leap year\n");
	else
		printf("It's a leap year\n");


	printf("First date entered: %d.%d.%d %d:%d:%d\n", Data_Time_1->day, Data_Time_1->month, Data_Time_1->year, Data_Time_1->hour, Data_Time_1->minute, Data_Time_1->second);
	printf("Second date entered: %d.%d.%d %d:%d:%d\n", Data_Time_2->day, Data_Time_2->month, Data_Time_2->year, Data_Time_2->hour, Data_Time_2->minute, Data_Time_2->second);

	DataDifference(&Data_Time_1, &Data_Time_2, &Data_Time_Dif);
	printf("%d ");

	return 0;
}
