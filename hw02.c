#include <stdio.h>
#include <math.h>

#define KM_PER_MI 1.609344
#define CONST_CHILL 35.74
#define CONST_ADD_TEMP 0.6215
#define CONST_SUB_VEL -35.75
#define CONST_ADD_VEL 0.4275
#define VEL_EXP 0.16

int main()
{

  short sel; //Selector variable that controls what unit the result will be in (C or F)
  float windSpeed; //Stores wind speed
  float realTemp; //Stores actual temperature (F)
  float chillTemp; //Stores temperature with windchill (F)
  float chillTempC; //Stores temperature with windchill (C)
  int unit; //Stores unit character

  printf("Enter 1 for US units, 2 for SI -> ");
  scanf("%hu", &sel);
  sel -= 1; //0 for US, 1 for SI

  unit =  (sel + 66) * sel + (((sel - 1)) * -70);

  printf("Enter temperature (\302\260%c) -> ", unit); //prints C or F
  scanf("%f", &realTemp);

  realTemp = (((realTemp * 9) / 5) + 32) * sel + ((sel - 1) *  -realTemp); //C -> F if needed

  unit = (sel + 106) * sel + (((sel - 1)) * -109); //Reuse unit char to save space

  printf("Enter wind speed (%cph) -> ", unit); //prints mph or kph
  scanf("%f", &windSpeed);

  windSpeed = (windSpeed /  KM_PER_MI) * sel + ((sel - 1) * -windSpeed); //KPH -> MPH if needed

  chillTemp = CONST_CHILL + CONST_ADD_TEMP * realTemp + CONST_SUB_VEL * pow(windSpeed, VEL_EXP) + CONST_ADD_VEL * realTemp *  pow(windSpeed, VEL_EXP);
  chillTempC = (((chillTemp - 32.0) * 5) / 9); //Convert to C

  printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("\nTemperature: %+8.1f \302\260F", realTemp);
  printf("\nWind speed: %9.1f mph", windSpeed);
  printf("\nUS wind chill: %+6.1f \302\260F", chillTemp);
  printf("\nSI wind chill: %+6.1f \302\260C", chillTempC);
  printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=");

  return 0;
}