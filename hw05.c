#include <stdio.h>
#include <stdlib.h>

void getSMM(int*, int*, int*);
void calcNumbers(int, int);
int getRandInRange(int, int);
int shiftDigits(int, int);

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
    printf("Enter the desired seed value -> ");
    scanf("%d", seed);

    printf("Enter the desired minimum value -> ");
    scanf("%d", min);

    printf("Enter the desired maximum value -> ");
    scanf("%d", max);
}

void calcNumbers(int seed, int randomNum)
{
    printf("Larger numbers generated from %d: ", seed);
    printf("%d", shiftDigits(seed, 1));  
}

int shiftDigits(int input, int n)
{
    int nthDigit;
    nthDigit = input % (10 * n);
       
}

int getNumDigits(int n)
{
    while
}