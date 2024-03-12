#include <stdio.h>
#include <stdlib.h>

void getSMM(int*, int*, int*);
void calcNumbers(int, int);
int getRandInRange(int, int);
int getNthDigit(int, int);
int getNumDigits(int);

int  main()
{
    int seed;
    int min;
    int max;

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
    printf("Larger numbers generated from %d: ", seed);
    int toMult = 0;
    int digits = 0;
    printf("original: %d", randomNum);
    toMult = randomNum % getNumDigits(randomNum);
    digits = getNumDigits(randomNum);
    randomNum = (randomNum - (randomNum % 10))/10;
    randomNum += toMult * (digits * 10);
    printf("\ngenerated: %d", randomNum);
}

int getNthDigit(int input, int n)
{
    return input % (10 * n);
}

int getNumDigits(int input)
{
    int digits = 0;
    while(input % 10 == 0)
    {
        input /= 10;
        digits++;
    }
    return digits;
}