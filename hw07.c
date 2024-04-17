/*****+--**--***-**-*-*-*--******-*---**--**--*--***************************
 *
 *  Homework #: 07
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description:
 *   generates and outputs dominant numbers (an integer in which more than half of its digits are the same) according to a user-specified seed and range.
 ******+--**--***-**-*-*-*--******-*---**--**--*--**************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAL 1001 //standard array length
#define UAL 10   //unusual array length

void getSMM(int*, int*, int*);
void findNumbers(int, int, int*, int*);
void printValues(int*, int*);

int main()
{
  int seed; //seed for random generator
  int min; //minimum allowed number 
  int max; //maximum allowed number

  int numbers[SAL]; //array for dominant numbers
  int occur[SAL]; //array for dominant digits

  getSMM(&seed, &min, &max);
  srand(seed);
  findNumbers(min, max, numbers, occur);
  printValues(numbers, occur);

  return 0;
}

/*****+--*--**-*-**---*-*--******-*---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: findNumbers
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int min - minumum range
 *    2. int max - maximum range
 *    3. int numbers[] - array to fill with numbers
 *    4. int numberIndex[] - array to fill with digits
 *  Function Description:
 *
 ******+--*--**-*-**---*-*--******-*---**--**--*--**************************/
void findNumbers(int min, int max, int numbers[], int numberIndex[])
{
  int i = 0; //lcv
  int j = 0; //lcv2
  int temp = 0; //temporarily holds the random number
  int digit[UAL] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //occurances of a digit in a number
  int digitCounter = 0; //counts the digits in a number

  //0 for not dominant, 1 for dominant

  for(i = 0; i < 1001; i++)
  { //fill with 1000 random numbers
    temp = rand() % (max + 1 - min) + min;
    numbers[i] = temp;

    while(temp > 0)
    {
      digit[(temp % 10)]++; //add 1 to the counter of each digit
      temp /= 10; //make temp smaller
      digitCounter++; //one more digit
      //printf("\ndigitcounter = %d\n", digitCounter);
    }

    numberIndex[i] = -1; //set dom digit to -1 by default (not a domnum)

    for(j = 0; j < 10; j++)
    { //count all the digits
      if(digit[j] * 2 > digitCounter)
      { //if there is a number with more than half of its digits made of one digit, it's a dominant number
        numberIndex[i] = j;
      }
      digit[j] = 0;
    }

    digitCounter = 0; //reset digit counter

    //printf("\n i = %d number: %d is dominant: %d\n", i ,numbers[i], numberIndex[i]); //more debug
  }
}

/*****+--**-**-*-**---*-*--******-*---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: printValues
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int dom[] - array of dominant numbers
 *    2. int domDigit[] - array of digits that make the number dominant
 *    3.
 *
 *  Function Description:
 *  Prints all numbers & formats nicely :)
 ******+--**-**-*-**---*-*--******-*---**--**--*--**************************/
void printValues(int dom[], int domDigit[])
{
  int i = 0; //lcv
  int largestDom = 0; //largest dominant number
  int largestDomIndex = 0; //the index of the largest number
  int domDigitCount[UAL] = {0, 0, 0}; //keeps track of domdigits
  int printCounter = 5; //makes the print statements pretty
  int printCounter2 = 1; //tried to get rid of this without success
  int flag = 1; //flag
  int originalDom = 0; //original dominant number

  for(i = 0; i < 1001; i++)
  {
    domDigitCount[domDigit[i]]++;
  }

  printf("\nDominant values by digit:");

  for(i = 0; i < 10; i++)
  {
    printf(" %d", domDigitCount[i]);
    if(domDigitCount[i] > largestDom)
    {
      largestDom = domDigitCount[i];
      largestDomIndex = i;
    }
  }
  originalDom = largestDom;
  //print everything
  printCounter2 = 0;

  while(flag)
  {
    flag = 0;
    for(i = 0; i < 1001; i++)
    {
      if(printCounter == 5)
      {
        printCounter2++;
        printCounter = 0;
        printf("\nDominant values #%d:", printCounter2);
      }

      if(dom[i] != -1 && (domDigit[i] == largestDomIndex))
      {
        printf(" %d", dom[i]);
        printCounter++;
        flag = 1;
      }
    }

    domDigitCount[largestDomIndex] = 0;

    largestDom = 0;
    for(i = 0; i < 10; i++)
    {
      //printf(" %d", domDigitCount[i]); //for debugging
      if(domDigitCount[i] > largestDom)
      {
        largestDom = domDigitCount[i];
        largestDomIndex = i;
      }
    }
    if(largestDom < originalDom)
    {
      flag = 0; //don't go around again
    }
  }
}

/*****+--*---***-**---*-*--******-*---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getSSM
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int *seed - the seed
 *    2. int *min - minimum range
 *    3. int *max - maximum range
 * 
 *  Function Description:
 *  Gets the seed, minimum limit, and maximum limit from the user
 ******+--*---***-**---*-*--******-*---**--**--*--**************************/
void getSMM(int *seed, int *min, int *max)
{ //(get seed, min, max)
  *seed = -1;
  *min = -1;
  *max = -1;

  while(*seed < 1)
  {
    printf("Enter desired seed value -> ");
    scanf("%d", seed);

    if(*seed < 1)
    {
      printf("\nError! Seed value must be positive!\n\n");
    }
  }

  while(*min < 1)
  {
    printf("Enter desired minimum range value -> ");
    scanf("%d", min);

    if(*min < 1)
    {
      printf("\nError! Minimum range value must be positive!\n\n");
    }
  }

  while(*max < *min || *max == *min)
  {
    printf("Enter desired maximum range value -> ");
    scanf("%d", max);

    if(*max <= *min)
    {
      printf("\nError! Maximum range value must be greater than minimum range value of %d!\n\n", *min);
    }
  }
}