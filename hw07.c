#include <stdio.h>
#include <stdlib.h>
#define PRINT printf("hello world") 

void getSMM(int*, int*, int*);
void findNumbers(int, int, int*, int*);

int main(){
    int seed; //seed for random generator
    int min; //minimum allowed number 
    int max; //maximum allowed number

    int numbers[1000];
    int occur[100];

    getSMM(&seed, &min, &max);
    srand(seed);
    findNumbers(min, max, numbers, occur);

    PRINT;

    return 0;
}

void findNumbers(int min, int max, int numbers[], int occur[]){
    // int i; //lcv
    // int j; //lcv2
    // int maxnum = 0; //counter
    // int digits = 0; //digit counter

    // for(i = 0; i < max; i++){ //fill with random numbers
    //     numbers[i] = rand() % (max + 1 - min) + min;
    // }

    // while(true){
    //     for(i = 0; i <  1000; i++){ //for every number in the array
    //         for(j = 0; j < numbers[i] / 10 + 1; j++){ //count each digit
    //             occur[numbers[j] % 10]++;
    //             numbers[j] /= 10;
    //             digits++;
    //         }

    //         for(j = j; j > 0; j--){ //check if there is any digit that makes up more than half of the digit
    //             *occur[j] > maxnum ? maxnum = *occur[j] : 0;     
    //         }
    //         if(max > digits/2){
    //             printf("true");
    //         }

    //     }
    // }
    
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
        printf("Enter the desired maximum range value -> ");
        scanf("%d", max);

        if(*max < *min)
        {
            printf("\nMaximum range value must be greater than minimum range value of %d\n", *min);
        }
    }
}