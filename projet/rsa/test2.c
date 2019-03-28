#include <stdio.h>

#define ARRAY_SIZE 5
#define ARRAY_TYPE unsigned char*

#include "ops.h"

byte N[ARRAY_SIZE], R[ARRAY_SIZE], A[ARRAY_SIZE], B[ARRAY_SIZE], Z[ARRAY_SIZE], C[ARRAY_SIZE];

int main()
{
    uint n;

    array_set(N, 3233);
    n = set_constants(N, R, C);

    // 65 ^ 17 mod 3233 = 2790
    // 2790 ^ 413 mod 3233 = 65
    array_set(A, 65);
    array_set(B, 17);
    
    printf("A=");
    array_print(A);

    ModularExponentiation(A, B, N, n, C, Z);
    printf("Z=");
    array_print(Z);

    array_copy(Z, A);
    array_set(B, 413);
    ModularExponentiation(A, B, N, n, C, Z);
    printf("Z=");
    array_print(Z);

    return 0;

}