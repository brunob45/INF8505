#include <stdio.h>

#define ARRAY_SIZE 1
#define ARRAY_TYPE unsigned*

unsigned n;
unsigned N[ARRAY_SIZE], R[ARRAY_SIZE], C[ARRAY_SIZE], ONE[ARRAY_SIZE], A[ARRAY_SIZE], B[ARRAY_SIZE], Z[ARRAY_SIZE];

unsigned BIT_TEST(ARRAY_TYPE x, int n)
{
    return (*x >> n) & 0x01;
}

unsigned ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    printf("(%d x %d) %% %d\n", *in1, *in2, *N);
    unsigned work = 0;
    for(int i = 0; i<n-1; i++)
    {
        if(BIT_TEST(in1, i)) work = work + *in2;
        if(BIT_TEST(&work, 0)) work = work + *N;
        work = work>>1;
    }
    *out = work;
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

unsigned ModularExponentiation(ARRAY_TYPE m, ARRAY_TYPE e)
{
    printf("-- %d ^ %d mod %d\n", *m, *e, *N);

    // constants
    *ONE = 1;
    n = 1;
    *R = 1;
    while(*R < *N)
    {
        n = n+1;
        *R *= 2;
    }
    *C = (*R**R)%*N;

    // step 1
    ModularMultiplication(m, C, m);
    ModularMultiplication(C, ONE, Z);

    // step 2
    for(int i = 0; i < n; i++)
    {
        //2a
        if(*e>>i & 1) ModularMultiplication(Z, m, Z);
        //2b
        ModularMultiplication(m, m, m);
    }
    // step 3
    ModularMultiplication(Z, ONE, Z);
    // step 4
    // return r;
}


int main(int argc, char** argv)
{
    *N = 3233; *A = 65; *B = 17;
    ModularExponentiation(A, B);
    printf("%d\n", *Z);
    *N = 3233; *A = *Z; *B = 413;
    ModularExponentiation(A, B);
    printf("%d\n", *Z);

    return 0;

}