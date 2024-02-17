#include <stdio.h>
#include "functions.h"

int main()
{
	system("chcp 1251"); //Русский язык
	system("cls");

	struct TimeData Data_Time; //Структура для даты и времени
	struct TimeData Today_Time = { 10,2,2024,13,45,00 };

	printf("Enter date and time in format day.month.year hours:minuts:seconds: "); //Ввод данных 
	scanf_s("%d.%d.%d %d:%d:%d", &Data_Time.day, &Data_Time.month, &Data_Time.year, &Data_Time.hour, &Data_Time.minute, &Data_Time.second);

	//Проверки на правильность введенных данных 
	if (Data_Time.month > 12 || (Data_Time.month % 2 == 0 ? Data_Time.day > 31 : Data_Time.day > 30) ||
		Data_Time.hour > 23 || Data_Time.minute > 59 || Data_Time.second > 59 || Data_Time.year == 0 || 
		Data_Time.month == 0 || Data_Time.day == 0)
	{
		printf("ERROR DATA\n");
		return 0;
	}

	//Проверка на високосный год и 29 февраля
	if (!IsLeapYear(Data_Time.year))
		if (Data_Time.month == 2 && Data_Time.day > 28)
		{
			printf("ERROR DATA\n");
			return 0;
		}
		else
			printf("It's not a leap year\n");
	else
		printf("It's a leap year\n");

	printf("Date entered: %d.%d.%d %d:%d:%d\n", Data_Time.day, Data_Time.month, Data_Time.year, Data_Time.hour, Data_Time.minute, Data_Time.second);
	printf("Today's date: %d.%d.%d %d:%d:%d\n", Today_Time.day, Today_Time.month, Today_Time.year, Today_Time.hour, Today_Time.minute, Today_Time.second);

	long long int difference = DataDifference(Data_Time, Today_Time);
	printf("Vary in %lld seconds \n in %lld minuts \n in %lld hours \n in %lld days \n in %lld years",
		difference, difference / 60, difference / 60 / 60, difference / 60 / 60 / 24, difference / 60 / 60 / 24 / 365);

	return 0;
}
