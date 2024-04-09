#include <stdio.h>
#include <math.h>

void toBin(long long, int[]);
void toFloat(int[]);
void printValues(int, int, float, int[]);

int main(){
    long long input = -1; //input long / validation var
    int binary[32]; //array of binary digits

    while(input < 1){
        printf("Enter raw value -> ");
        scanf("%lld", &input);
        (input < 1) ? printf("\nError! Raw value must be non-negative.\n"):0;
    }

    toBin(input, binary);
    toFloat(binary);

    return 0;
}

void toBin(long long input, int binary[]){
    int i; //lcv
    binary[31] = 1; //annoying lvalue workaround
    input > -1 ? binary[31] = 0:0;

    for(i = 0; i < 32; i++){
        binary[i] = (input / (int)pow(2, i)) % 2;
    }
}

void toFloat(int binary[]){
    int i; //lcv
    float mantissa = 0; //fractional value
    int exp = 0; //exponent
    float result = 0; //final floating point result

    for(i = 0; i < 23; i++){
        mantissa += binary[i] * pow(2, (-23 + i));
    }

    for(i = 23; i < 31; i++){
        exp += (binary[i] * pow(2, (i - 23)));
    }

    result = pow(-1, binary[31]) * pow(2, (exp - 127)) * (1 + mantissa);

    printValues(binary[31], exp, result, binary);
}

void printValues(int sign, int exp, float value, int rawBinary[]){
    int i; //lcv

    printf("\nSign: %d (%+d)", sign, sign);

    printf("\nExponent: ");
    for(i = 31; i != 23; i--){
        i % 4 != 0 ? printf("%d",rawBinary[i - 1]) : printf("%d ",rawBinary[i - 1]);
    }
    printf(" (%d)", exp);

    printf("\nSignificand: ");
    for(i = 23; i != 0; i--){
        i % 4 != 0 ? printf("%d",rawBinary[i - 1]) : printf("%d ",rawBinary[i - 1]);
    }

    printf("\nValue: %+8e", value);
}
