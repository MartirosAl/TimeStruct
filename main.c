#include <stdio.h>
#include "structs.h"

int main()
{
	struct TimeData Data_Time;

	printf("Enter date and time in format day month year hours minuts seconds: ");
	scanf_s("%d %d %d %d %d %d", &Data_Time.year, &Data_Time.month, &Data_Time.day, &Data_Time.hour, &Data_Time.minute, &Data_Time.second);
	if (Data_Time.month > 12 || Data_Time.day > 31 || Data_Time.hour > 23 || Data_Time.minute > 59 || Data_Time.second > 59)
	{
		printf("ERROR DATA");
		return 0;
	}
	printf("%d", Data_Time.day);
	return 0;
}