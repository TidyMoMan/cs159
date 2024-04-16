#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PRINT printf("hei")

void getSMM(int*, int*, int*);
void findNumbers(int, int, int*, int*);
void printValues(int*, int*);

int main(){
    int seed; //seed for random generator
    int min; //minimum allowed number 
    int max; //maximum allowed number

    int numbers[1001];
    int occur[1001];

    //getSMM(&seed, &min, &max);
    srand(2200);
    printf("\nseed = %d", seed);
    findNumbers(1000, 9999, numbers, occur);
    printValues(numbers, occur);

    return 0;
}

void findNumbers(int min, int max, int numbers[], int numberIndex[]){
    int i = 0; //lcv
    int j = 0; //lcv2
    int temp = 0;
    
    int digit[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //occurances of a digit in a number
    int digitCounter = 0;

    //0 for not dominant, 1 for dominant

    for(i = 0; i < 1001; i++){ //fill with 1000 random numbers
        temp = rand() % (max + 1 - min) + min;
        numbers[i] = temp;

        while(temp > 0){
            digit[(temp % 10)]++; //add 1 to the counter of each digit
            temp /= 10; //make temp smaller
            digitCounter++; //one more digit
            //printf("\ndigitcounter = %d\n", digitCounter);
        }

        for(int g = 0; g < 10; g++){ //debug stuff
            printf(" %d ",digit[g]);
        }

        numberIndex[i] = -1; //set dominant digit to -1 by default (not a domnum)

        for(j = 0; j < 10; j++){ //count all the digits
            if(digit[j]*2 > digitCounter){ //if there is a number with more than half of its digits made of one digit, it's a dominant number
                numberIndex[i] = j;
            }
            digit[j] = 0;
        }

        // if(numbers[i] < 10){
        //     numbers[i] = 0;
        //     numberIndex[i] = 0;
        // }

        //(numberIndex[i] != -1) ? (numbers[i] = numbers[i]) : (numbers[i] = -1); //sets number to -1 if it isn't dominant
        digitCounter = 0; //reset digit counter
        printf("\n\n");

    
        printf("\n i = %d number: %d is dominant: %d\n", i ,numbers[i], numberIndex[i]); //more debug
    }
}

void printValues(int dom[], int domDigit[]){
    int i = 0; //lcv
    int largestDom = 0;
    int largestDomIndex = 0;
    int domDigitCount[10] = {0, 0, 0};

    for(i = 0; i < 1001; i++){
        domDigitCount[domDigit[i]]++;
    }
    
    printf("Dominant values by digit:");

    for(i = 0; i < 10; i++){
        printf(" %d", domDigitCount[i]);
        if(domDigitCount[i] > largestDom){
            largestDom = domDigitCount[i];
            largestDomIndex = i;
        }
    }

    printf("\nlargest dom = %d, index = %d", largestDom, largestDomIndex);

    printf("\nDominant values ");
    for(i = 0; i < 1001; i++){        //the actual number with the most occurances
        if(dom[i] != -1 && domDigit[i] == largestDomIndex){
            printf(" %d", dom[i]);
        }
    }
}

void getSMM(int *seed, int *min, int *max){ //(get seed, min, max)
    *seed = -1;
    *min = -1;
    *max = -1;

    while(*seed < 0)
    {
        printf("Enter desired seed value -> ");
        scanf("%d", seed);

        if(*seed < 0)
        {
            printf("\nError! Seed value must be positive!\n");
        }
    }

    while(*min < 0)
    {
        printf("Enter desired minimum range value -> ");
        scanf("%d", min);

        if(*min < 0)
        {
            printf("\nError! Minimum range value must be positive!\n");
        }
    }

    while(*max < *min)
    {
        printf("Enter desired maximum range value -> ");
        scanf("%d", max);

        if(*max < *min)
        {
            printf("\nMaximum range value must be greater than minimum range value of %d\n", *min);
        }
    }
}