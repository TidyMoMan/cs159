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

    printf("day = %d\n", day);

    switch(day) //print out the correct day of the week
    {
        case 0:
            printf("01 January %d falls on a: Monday", year);
        break;
        case 1:
            printf("01 January %d falls on a: Tuesday", year);
        break;
        case 2:
            printf("01 January %d falls on a: Wednesday", year);
        break;
        case 3:
            printf("01 January %d falls on a: Thursday", year);
        break;
        case 4:
            printf("01 January %d falls on a: Friday", year);
        break;
        case 5:
            printf("01 January %d falls on a: Saturday", year);
        break;
        case 6:
            printf("01 January %d falls on a: Sunday", year);
        break;
        default:
            printf("day: %d", day);
        break;
    }

    (YDL2 != ' ') ? printf("\nDominical leters:           %c%c\n", YDL1, YDL2) : printf("\nDominical leters:           %c\n", YDL1);

    /* gigantic ugly if-else statement that prints the months of friday the 13th */
    if(YDL1 == 'A' && YDL2 == ' ')
    {
        printf("Friday the 13th falls in:   January, October");
    }
    else if(YDL1 == 'B' && YDL2 == 'A')
    {
        printf("Friday the 13th falls in:   October");
    }
    else if(YDL1 == 'C' && YDL2 == 'B')
    {
        printf("Friday the 13th falls in:   May");
    }
    else if(YDL1 == 'C' && YDL2 == ' ')
    {
        printf("Friday the 13th falls in:   August");
    }
    else if(YDL1 == 'D' && YDL2 == ' ')
    {
        printf("Friday the 13th falls in:   Febuary, March, November");
    }
    else if(YDL1 == 'E' || (YDL1 == 'F' && YDL2 == 'E'))
    {
        printf("Friday the 13th falls in:   June");
    }
    else if(YDL1 == 'F' || (YDL1 == 'G' && YDL2 == 'F'))
    {
        printf("Friday the 13th falls in:   September, December");
    }
    else if(YDL1 == 'G' && YDL2 == ' ')
    {
        printf("Friday the 13th falls in:   April, July");
    }
    else if(YDL1 == 'A' && YDL2 == 'G')
    {
        printf("Friday the 13th falls in:   January, April, July");
    }
}