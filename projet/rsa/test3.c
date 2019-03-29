#include <stdio.h>

#define byte unsigned char
#define uint unsigned int

#define ARRAY_SIZE (1024/8+2)
#define ARRAY_TYPE byte*

#include "ops.h"
#include "keys/keys.h"

uint n;
byte N[ARRAY_SIZE], R[ARRAY_SIZE], A[ARRAY_SIZE], B[ARRAY_SIZE], Z[ARRAY_SIZE], C[ARRAY_SIZE], ONE[ARRAY_SIZE], WORK1[ARRAY_SIZE], WORK2[ARRAY_SIZE];

void ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    // printf("(%d x %d) %% %d\n", *in1, *in2, *N);
    array_copy(in1, WORK1);
    array_copy(in2, WORK2);
    array_set(out, 0);

    for(int i = 0; i<n; i++)
    {
        if(array_bit_test(WORK1, i)) array_add(out, WORK2, out);
        if(array_bit_test(out, 0)) array_add(out, N, out);
        array_div2(out, out);
    }
}

void REDC()
{
    // transform
    ModularMultiplication(A, C, A);
    ModularMultiplication(B, C, B);

    // multiply
    ModularMultiplication(A, B, Z);
    
    // transform back
    ModularMultiplication(Z, ONE, Z);
}

void set_constants()
{
    array_set(ONE, 1);
    n = 8*sizeof(modulus);
    printf("n=%d\n", n);
    array_bit_set(R, n);
    printf("N=");
    array_print(N);
    printf("R=");
    array_print(R);

    array_modulus(R, N, C);
    printf("C=");
    array_print(C);

    array_mulmod(C, C, N, C);
    printf("C=");
    array_print(C);
}

void ModularExponentiation(ARRAY_TYPE m, ARRAY_TYPE e)
{
    ModularMultiplication(m, C, m);
    ModularMultiplication(C, ONE, Z);

    // step 2
    for(int i = 0; i < n; i++)
    {
        if(array_bit_test(e, i)) ModularMultiplication(Z, m, Z);
        ModularMultiplication(m, m, m);
    }
    ModularMultiplication(Z, ONE, Z);
}


int main()
{
    array_copy(modulus, N);
    // array_set(N, 3233);
    set_constants();

    // *N = 3233; *A = 65; *B = 17;
    array_set(A, 65);
    // array_set(B, 17);
    
    ModularExponentiation(A, publicExponent);
    printf("Z=");
    array_print(Z);

    array_copy(Z, A);
    array_set(B, 413);
    ModularExponentiation(A, B);
    printf("Z=");
    array_print(Z);

    return 0;

}