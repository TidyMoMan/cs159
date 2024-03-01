#include <stdio.h>

void calcLetter(short, char*, char*);

int main()
{
    char YDL1;
    char YDL2;
    int year;

    printf("Enter year -> ");
    scanf("%d", &year);

    calcLetter(year, &YDL1, &YDL2);

    printf("YDL1: %c YDL2: %c", YDL1, YDL2);

    return 0;
}


void calcLetter(int year, char* YDL1, char* YDL2)
{
    int day;

    day = ((year - 1) * 365 + ((year - 1 ) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7; //Initial calculation
    day = (day + 1) % 7; //Move from dec 31 to jan 01
    YDL1 = 71 - day; //Convert to char

    year % 4 ? *YDL1 > 'G' ? *YDL2 = YDL1 - 1 : *YDL2 = 'A' : *YDL2 = ' '; //Calculate second YDL if needed
}

