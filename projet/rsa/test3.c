#include <stdio.h>

#define byte unsigned char
#define uint unsigned int

#define ARRAY_SIZE (1024/8+2)
#define ARRAY_TYPE byte*

#include "ops.h"
#include "keys/keys.h"

byte N[ARRAY_SIZE], R[ARRAY_SIZE], A[ARRAY_SIZE], B[ARRAY_SIZE], Z[ARRAY_SIZE], C[ARRAY_SIZE];

int main()
{
    uint n;
    n = set_constants(modulus, R, C);

    array_set(A, 65);
    
    printf("A=");
    array_print(A);

    ModularExponentiation(A, publicExponent, modulus, n, C, Z);
    printf("Z=");
    array_print(Z);

    ModularExponentiation(Z, privateExponent, modulus, n, C, A);
    printf("A=");
    array_print(A);

    return 0;

}