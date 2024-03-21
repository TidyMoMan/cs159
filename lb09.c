#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcNumbers(int);
int getNumDigits(int);
int getLargestDigit(int);

int  main()
{

    long long target = 1902830928136879;
    int curMax = 0;
    int curdigit;

    int digits = ceil(log10(target)); //gets the number of digits in the number

    for(int i = 1; i < digits; i++){
        curdigit = target % (int)(pow(10, i));
        if(curdigit >= curMax){
            curMax = curdigit;
            printf("curdigit = %d\n", curdigit);
            printf("curmax = %d\n",  curMax);
        }
    }
    printf("\n%d", curMax);
    printf("\n%d", digits);

    // int target = 123456789;
    // int curNum;
    // curNum = target;

    // while(getNumDigits(target) >= 1){
    //     if(curNum % 10 == getLargestDigit(target)){
    //         printf("%d", target % 10);
    //     }else{
    //         curNum = calcNumbers(curNum);
    //     }
    // }

    // return 0;
}

int getLargestDigit(int target){
    int i;
    int large = 0;
    int digit = 0;

    for(i = 0; i < getNumDigits(target); i++){
            digit = target % (10 * i);
            if(digit >= large){
                large = digit;
            }
        }
    return large;
}


int calcNumbers(int number)
{
    int original = 0; //holds the original
    int onesPlace; //the ones place of the current number
    int newNum; //the new number generated from the old one
    int i; //for loop index

    original = number;
    
    onesPlace = number % 10; //get last digit
    number = number / 10; //remove last digit
    newNum = 0; //reset newNum

    newNum = (int)(number + (pow(10, getNumDigits(number)) * onesPlace));

    if(newNum > original){
        printf("%d ", newNum);
    }

    return newNum;
    
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