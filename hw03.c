/*****+--**--******-*------*-***----*--*---**-*--***************************
*
*  Homework #: 03
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description:
*  Computes fluid flow rate through a hose with a nozzle of a given size.
******+--**--******-*------*-***----*--*---**-*--**************************/

#include <stdio.h>
#include <math.h>

double calcSpeed(double, double);
double getFlow(void);
double getRadius(int);
void printResults(double, double);

int main()
{
  double rad1; //radius of hose 1
  double rad2; //radius of hose 2
  double flow; //Flow rate for both hoses

  rad1 = getRadius(1); //get radius 1
  rad2 = getRadius(2); //get radius 2
  flow = getFlow();    //get flow rate

  printResults(calcSpeed(rad1, flow), calcSpeed(rad2, flow)); //Calculate the speed from given radii and flow rate, then print the values.

  return 0;
}

/*****+--*--**-*-*---------*-***----*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: getFlow
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. no input taken
*    2.
*    3.
*
*  Function Description:
*  scans the flow rate from the user
******+--*--**-*-*---------*-***----*--*---**-*--**************************/

double getFlow()
{
  double flowRate; //Local variable for getting flow rate.
  printf("Enter the flow rate (L/s) -> ");
  scanf("%lf", &flowRate);
  return flowRate;
}

/*****+--**-**-*-**-*------*-***----*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: getRadius
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double rad - local variable for radius
*    2.
*    3.
*
*  Function Description:
*  gets the hose radius from the user
******+--**-**-*-**-*------*-***----*--*---**-*--**************************/

double getRadius(int hoseNum)
{
  double rad; //Local variable for radius
  printf("Enter the radius of hose #%d (cm) -> ", hoseNum);
  scanf("%lf", &rad);
  return rad / 100; //convert cm to m
}

/*****+--**-****-**-*------*-***----*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: calcSpeed
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double rad - radius of the hose
*    2. double flowRate - fluid flow rate in L/s
*
*
*  Function Description:
*  Takes radius and flow rate as arguments and returns calculated fluid speed.
******+--**-****-**-*------*-***----*--*---**-*--**************************/

double calcSpeed(double rad, double flowRate)
{
  double area = pow(rad, 2) *  M_PI; //Calculate area from radius
  return (flowRate / area) / 1000; //convert to meters
}

/*****+-***--*-*-*--*------*-***----*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: printResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double res1 - local var for printing result #1
*    2. double res2 - local var for printing result #2
*    3.
*
*  Function Description:
*  Formats and prints the given values
******+-***--*-*-*--*------*-***----*--*---**-*--**************************/

void printResults(double res1, double res2)
{
  printf("\nThe speed of the water in the hose #1: %.2lf m/s", res1);
  printf("\nThe speed of the water in the hose #2: %.2lf m/s", res2);
}
