#include <stdio.h>

#define ARRAY_TYPE unsigned*

unsigned n;
unsigned N[1], R[1], C[1], ONE[1];

unsigned BIT_TEST(ARRAY_TYPE x, int n)
{
    return (*x >> n) & 0x01;
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
    while(work > *N) work = work-*N;

    // step 4
    *out = work;
}

unsigned ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    *out = *in1 * *in2;
    while(*out % *R != 0)
        *out += *N;
    *out /= *R;
    // return a;
}

void REDC2(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    // transform
    ModularMultiplication(in1, C, in1);
    ModularMultiplication(in2, C, in2);

    // multiply
    ModularMultiplication(in1, in2, out);
    
    // transform back
    ModularMultiplication(out, ONE, out);
}

unsigned ModularExponentiation(ARRAY_TYPE m, ARRAY_TYPE e, ARRAY_TYPE out)
{
    // step 1
    ModularMultiplication(m, C, m);
    ModularMultiplication(C, ONE, out);

    // step 2
    for(int i = 0; i < n; i++)
    {
        //2a
        if(*e>>i & 1) ModularMultiplication(out, m, out);
        //2b
        ModularMultiplication(m, m, m);
    }
    // step 3
    ModularMultiplication(out, ONE, out);
    // step 4
    // return r;
}


int main(int argc, char** argv)
{
    unsigned a[1], b[1], c[1], x[1], y[1];

    *ONE = 1;
    *N = 97;
    n = 8;
    *R = 1<<n;
    *C = (*R**R)%*N;

    // this works
    *x = 43; *y = 56;
    REDC2(x,y,c);
    printf("Modular Multiplication:%d (should be 80)\n",*c);

    // test new function
    *x = 43; *y = 9;
    ModularMultiplication2(x, y, a);
    ModularMultiplication(x, y, b); // should be 25
    printf("test:%d, correct:%d\n", *a, *b);

    
    // below works too!
    *N = 13;
    *x = 12;
    *y = 2;
    ModularExponentiation(x, y, c);
    printf("Modular Exponentiation:%d (should be 1)\n", *c);

    return 0;

}