#include <stdio.h>
#define LENGTH_RACE 500 

int main()
{
  float velcar1; //Final velocity of car 1
  float velcar2; //Final velocity of car 2
  float accel1; //Acceleration of car 1
  float accel2; //Acceleration of car 2
  float finishTime1; //Time to finish for car 1
  float finishTime2; //Time to finish for car 2

  printf("Enter final velocity for Car 1 -> ");
  scanf("%f", &velcar1);

  printf("Enter final velocity for Car 2 -> ");
  scanf("%f", &velcar2);

  accel1 = (velcar1 * velcar1) / (2 * LENGTH_RACE); //Get the acceleration for both cars from their distance traversed and final velocity
  accel2 = (velcar2 * velcar2) / (2 * LENGTH_RACE);

  finishTime1 = velcar1 / accel1; //Get delta time from delta velocity and acceleration
  finishTime2 = velcar2 / accel2;

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Time for Car 1 to finish the race: %8.2f seconds\n", finishTime1);
  printf("Time for Car 2 to finish the race: %8.2f seconds\n", finishTime2);
  printf("Average acceleration: %21.2f ft/s^2\n", (accel1 + accel2) / 2);
  printf("Time difference (Car 1 - Car 2): %10.2f seconds\n", finishTime1 - finishTime2);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

  return 0;
}
