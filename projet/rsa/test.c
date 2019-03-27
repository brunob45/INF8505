#include <stdio.h>

#define ARRAY_TYPE unsigned*

unsigned n, base = 10;
unsigned N[1], R[1], C[1], ONE[1], A[1], B[1], Z[1];

unsigned BIT_TEST(ARRAY_TYPE x, int n)
{
    return (*x >> n) & 0x01;
}

// unsigned ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
// {
//     *out = *in1 * *in2;
//     while(*out % *R != 0)
//         *out += *N;
//     *out /= *R;
//     // return a;
// }

unsigned ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    printf("(%d x %d) %% %d\n", *in1, *in2, *N);
    // step 1
    unsigned work = 0, a, b;
    unsigned l = 1;
    // step2
    for(int i = 0; i<n-1; i++)
    {
        a = (*in1/l)%base;
        b = *in2;
        // printf("%d + %d x %d = ", work, a, b);
        work = work + (a * b);

        a = 0;
        while((work + (a* *N)) % base != 0)
            a += 1;
        b = *N;
        // printf("%d\n%d + %d x %d = ", work, work, a, b);
        work = work + (a * b);

        // printf("%d\n%d / %d = ", work, work, base);
        work = work/base;
        // printf("%d\n-----\n", work);
        l *= base;
    }

    // step 3
    // printf("%d %% %d = ", work, *N);
    // if(work > *N) work = work-*N;
    // printf("%d\n\n", work);

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
    *N = 3233;
    n = 1;
    *R = 1;
    while(*R < *N)
    {
        n = n+1;
        *R *= base;
    }
    *C = (*R**R)%*N;

    *A = 65; *B = 17;
    ModularExponentiation(A, B);
    printf("%d\n", *Z);
    *A = 2790; *B = 413;
    ModularExponentiation(A, B);
    printf("%d\n", *Z);
    return 0;

    // this works
    // *A = i; *B = j;
    // REDC();
    // x = *Z;
    // *A = i; *B = j;
    // REDC2();
    // y = *Z;
    // printf("correct:%d, test:%d\n", x, y);

    
    // below works too!
    // *N = 97;
    // for(i = 1; i < 35; i++)
    // {
    //     x = i;
    //     for(j = 1; j < 12; j++)
    //     {
    //         *A = i; *B = j;
    //         ModularExponentiation(A, B);
    //         if(*Z != x) printf("ModularExponentiation failed i:%d, j:%d, expected:%d, result:%d\n", i, j, x, *Z);
    //         x = (x*i) % *N;
    //     }
    // }

    return 0;

}