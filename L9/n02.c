#include <stdio.h>

typedef enum __DayOfWeek {
    Sunday = 0, 
    Monday = 1, 
    Tuesday = 2, 
    Wednesday = 3, 
    Thursday = 4, 
    Friday = 5, 
    Saturday = 6
} DayOfWeek;

DayOfWeek findDayOfWeek(int day, int month){
    int ttday = day;
    switch(month){
        case 1: ttday += 0;break;
        case 2: ttday += 31;break;
        case 3: ttday += 59;break;
        case 4: ttday += 90;break;
        case 5: ttday += 120;break;
        case 6: ttday += 151;break;
        case 7: ttday += 181;break;
        case 8: ttday += 212;break;
        case 9: ttday += 243;break;
        case 10: ttday += 273;break;
        case 11: ttday += 304;break;
        case 12: ttday += 334;break;
    }
    DayOfWeek result = (ttday % 7);
    return result;
}

int main()
{
	int day, month;
	DayOfWeek dow;

	printf("Day:1 Month:1 of Year 2013 is Tuesday.\n");
	printf("Enter Day and Month: ");
	scanf("%d %d", &day, &month);
	dow = findDayOfWeek(day, month);
	printf("Day:%d Month:%d of Year 2013 is ", day, month);
	switch(dow){
		case 6: printf("Sunday.\n"); break;
		case 0: printf("Monday.\n"); break;
		case 1: printf("Tuesday.\n"); break;
		case 2: printf("Wednesday.\n"); break;
		case 3: printf("Thursday.\n"); break;
		case 4: printf("Friday.\n"); break;
		case 5: printf("Saturday.\n"); break;
	}
}