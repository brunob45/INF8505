#include <stdio.h>

#define ARRAY_SIZE (1024/32+1)

#include "llconstants.h"
#include "ops.h"

byte B[ARRAY_SIZE], Z[ARRAY_SIZE];

//unsigned chess_storage(DMb%32) A [32] = {0,};

int main()
{
    /*
    array_add(INPUT, INPUT, Z);
    array_print(Z);
    array_div2(INPUT, Z);
    array_print(Z);
    /*
    array_print(INPUT);
    array_set(B, 0xffffffff);
    array_add(INPUT, B, Z);
    array_print(Z);
    array_div2(Z, Z);
    array_print(Z);
    /**/
    
    ModularExponentiation(INPUT, publicExponent, modulus, n, C, Z);
    printf("Z=\n");
    array_print(Z);

    //ModularExponentiation(Z, privateExponent, modulus, n, C, B);
    //printf("B=\n");
    //array_print(B);

    return 0;

}