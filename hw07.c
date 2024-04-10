#include <stdio.h>
#include <stdlib.h>

void getSMM(int*, int*, int*);

int main(){
    int seed; //seed for random generator
    int min; //minimum allowed number 
    int max; //maximum allowed number

    int numbers[];
    int occur[];

    getSMM(&seed, &min, &max);
    srand(seed);
    findNumbers(min, max, numbers[], occur[])



    return 0;
}

void findNumbers(int min, int max, int *numbers[], int *occur[]){
    int i; //lcv
    int j; //lcv2
    for(i = 0; i < max; i++){
        numbers[i] = rand() % (max + 1 - min) + min;
    }

    while(){
        for(i = 0; i <  1000; i++){ //for every number in the array
            for(j = 0; j < 100; j++){ //count each digit
                
            }
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
        printf("Enter the desired maximum range value -> ");
        scanf("%d", max);

        if(*max < *min)
        {
            printf("\nMaximum range value must be greater than minimum range value of %d\n", *min);
        }
    }
}