#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getSMM(int*, int*, int*);
void calcNumbers(int, int);
int getRandInRange(int, int);
int getNumDigits(int);

int  main()
{
    int seed; //seed for random generator
    int min; //minimum allowed number 
    int max; //maximum allowed number

    getSMM(&seed, &min, &max);
    srand((unsigned int)(seed));
    calcNumbers(seed, getRandInRange(min, max));

    return 0;
}

int getRandInRange(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}

void getSMM(int *seed, int *min, int *max) //(get seed, min, max)
{
    *seed = -1;
    *min = -1;
    *max = -1;

    while(*seed < 0)
    {
        printf("Enter the desired seed value -> ");
        scanf("%d", seed);

        if(*seed < 0)
        {
            printf("\nError! Minimum must be a non-negative integer.\n");
        }
    }

    while(*min < 0)
    {
        printf("Enter the desired minimum value -> ");
        scanf("%d", min);

        if(*min < 0)
        {
            printf("\nError! Minimum must be a non-negative integer.\n");
        }
    }

    while(*max < *min)
    {
        printf("Enter the desired maximum value -> ");
        scanf("%d", max);

        if(*max < *min)
        {
            printf("\nError! Maximum must be greater than %d\n", *min);
        }
    }
}

void calcNumbers(int seed, int randomNum)
{
    int total = 0; //total of numbers larger than the original
    int original = 0; //holds the original
    int onesPlace; //the ones place of the current number
    int newNum; //the new number generated from the old one
    int i; //for loop index

    original = randomNum;

    printf("\nLarger numbers generated from %d: ", original);
    
    for (i = 0; i < getNumDigits(randomNum); i++){    
    
    onesPlace = randomNum % 10; //get last digit
    randomNum = randomNum / 10; //remove last digit
    newNum = 0; //reset newNum

    newNum = (int)(randomNum + (pow(10, getNumDigits(randomNum)) * onesPlace));
    
    //printf("\ntotal: %d newNum: %d", total, newNum);
    if(newNum > original){
        printf("%d ", newNum);
        total++;
    }
    randomNum = newNum;
    }

    printf("\nCount of larger numbers generated from %d: %d", original, total);

    // firstDigit = num % 10 //get last digit
    // num /= 10 //remove last digit
    // newNum += numDigits(num) * 10 * firstFigit //move last digit to first digit
}

int getNumDigits(int input)
{
    int digits = 0; //the number of digits
    while(input / 10 != 0)
    {
        input /= 10;
        digits++;
    }
    digits++;
    return digits;
}