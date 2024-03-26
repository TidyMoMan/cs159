#include <stdio.h>
#include <math.h>

long long toBin(long long);

int main(){
    long long input = 0;

    printf("Enter raw value -> ");
    scanf("%lld", &input);

    toBin(input);


    return 0;
}

long long toBin(long long input){
    int i;
    int binary[32];
    input > -1 ? binary[32] = 0 : binary [32] = 1;

    for(i = 0; i < 23; i++){
        binary[i] = (input / (int)pow(2, i)) % 2;
        printf("%d", binary[i]);
    }

    
    
}
