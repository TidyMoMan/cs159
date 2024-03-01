#include <stdio.h>

void calcLetter(int, int*, char*, char*);
int getYear();
void printData(int, int, char, char);

int main()
{
    char YDL1;
    char YDL2;
    int year;
    int day;

    getYear(&year);
    calcLetter(year, &day, &YDL1, &YDL2);
    printData(year, day, YDL1, YDL2);

    return 0;
}

int getYear(int *year)
{
    printf("Enter year -> ");
    scanf("%d", year);
}

void calcLetter(int year, int *day, char *YDL1, char *YDL2)
{
    *day = ((year - 1) * 365 + ((year - 1 ) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7; //Initial calculation
    *day = (*day + 1) % 7; //Move from dec 31 to jan 01

    if(year % 4 == 0) //if leap year
    {
        *YDL1 = (char)71 - *day; //Convert to correct char
        *YDL2 = *YDL1;
        (*YDL1 != 'G') ? (*YDL1 += 1) : (*YDL1 = 'A');
    }
    else //if not leap year
    {
        *YDL1 = (char)65 + *day; //Convert to correct char
        *YDL2 = ' '; //no second YDL needed if leap year
    }
}

void printData(int year, int day, char YDL1, char YDL2){

    switch(day) //print out the correct day of the week
    {
        case 1:
            printf("01 January %d falls on a: Monday", year);
        break;
        case 2:
            printf("01 January %d falls on a: Tuesday", year);
        break;
        case 3:
            printf("01 January %d falls on a: Wednesday", year);
        break;
        case 4:
            printf("01 January %d falls on a: Thursday", year);
        break;
        case 5:
            printf("01 January %d falls on a: Friday", year);
        break;
        case 6:
            printf("01 January %d falls on a: Saturday", year);
        break;
        case 7:
            printf("01 January %d falls on a: Sunday", year);
        break;
    }

    (YDL2 != ' ') ? printf("\nDominical leters:           %c%c\n", YDL1, YDL2) : printf("\nDominical leters:           %c\n", YDL1);

    if(YDL1 == 'A' && YDL2 == ' ')
    {
        printf("Friday the 13th falls in:   January, October");
    }
    else if(YDL1 == 'B' && YDL2 == 'A')
    {
        printf("Friday the 13th falls in:   October");
    }
           


}