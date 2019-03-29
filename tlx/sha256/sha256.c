#include <stdio.h>

#define ARRAY_SIZE (1024/8+1)

#include "ops.h"

byte A[ARRAY_SIZE], B[ARRAY_SIZE], Z[ARRAY_SIZE];

int main()
{
    array_set(A, 0x123456);

    printf("A=\n");
    array_print(A);

    ModularExponentiation(A, publicExponent, Z);
    printf("Z=\n");
    array_print(Z);

    ModularExponentiation(Z, privateExponent, A);
    printf("A=\n");
    array_print(A);

    return 0;

}