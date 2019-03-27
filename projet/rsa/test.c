#include <stdio.h>

#define ARRAY_TYPE unsigned*

unsigned n;
unsigned N[1], R[1], C[1], ONE[1], A[1], B[1], Z[1];

unsigned BIT_TEST(ARRAY_TYPE x, int n)
{
    return (*x >> n) & 0x01;
}

unsigned ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    *out = *in1 * *in2;
    while(*out % *R != 0)
        *out += *N;
    *out /= *R;
    // return a;
}

unsigned ModularMultiplication2(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    // step 1
    unsigned work = 0;

    // step2
    for(int i = 0; i <= n; i++)
    {
        work = work + ((*in1&(1<<i)) * *in2);
        work = work + ((work&(1<<0)) * *N);
        work = work/2;
    }

    // step 3
    if(work > *N) work = work-*N;

    // step 4
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

void REDC2()
{
    // transform
    ModularMultiplication(A, C, B);
    ModularMultiplication(B, C, B);

    // multiply
    ModularMultiplication2(A, B, Z);
    
    // transform back
    ModularMultiplication(Z, C, Z);
}

unsigned ModularExponentiation(ARRAY_TYPE m, ARRAY_TYPE e)
{
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
    unsigned i = 13, j = 112;
    unsigned x, y;

    *ONE = 1;
    *N = 97;
    n = 7;
    *R = 1<<n;
    *C = (*R**R)%*N;

    // this works
    *A = i; *B = j;
    REDC();
    x = *Z;
    *A = i; *B = j;
    REDC2();
    y = *Z;
    printf("correct:%d, test:%d\n", x, y);

    
    // below works too!
    *N = 97;
    for(i = 1; i < 35; i++)
    {
        x = i;
        for(j = 1; j < 12; j++)
        {
            *A = i; *B = j;
            ModularExponentiation(A, B);
            if(*Z != x) printf("ModularExponentiation failed i:%d, j:%d, expected:%d, result:%d\n", i, j, x, *Z);
            x = (x*i) % *N;
        }
    }

    return 0;

}