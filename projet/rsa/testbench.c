#include <stdio.h>

#define ARRAY_SIZE 4
#define ARRAY_TYPE unsigned char *
#define MAX 0xffffffff

#include "ops.h"

byte A[ARRAY_SIZE], B[ARRAY_SIZE], C[ARRAY_SIZE], N[ARRAY_SIZE];

uint equal(ARRAY_TYPE in1, unsigned in2)
{
    uint i, temp;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        temp = (8 * (ARRAY_SIZE - 1 - i));
        temp = ((in2 >> temp) & 0xff);
        if (in1[i] != temp)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    unsigned int a, b, c, z, passed;

    // add
    printf("add... ");
    passed = 1;
    for(a = 1; a < -1 && passed; a=2*a+1)
    {
        for(b = 0; b <= a && passed; b=2*b+1)
        {
            c = a + b;

            array_set(A, a);
            array_set(B, b);
            array_add(A, B, C);
            passed = equal(C, c);
        }
    }
    if(equal(C, c))
    {
        printf("passed\n");
    }
    else
    {
        printf("failed: %x + %x = %x. Got:\n", a, b, c);
        array_print(C);
    }
    
    // sub
    printf("sub... ");
    passed = 1;
    for(a = 1; a < -1 && passed; a=2*a+1)
    {
        for(b = 1; b <= a && passed; b=3*b-1)
        {
            c = a - b;

            array_set(A, a);
            array_set(B, b);
            array_sub(A, B, C);
            passed = equal(C, c);
        }
    }
    if(equal(C, c))
    {
        printf("passed\n");
    }
    else
    {
        printf("failed: %x - %x = %x. Got:\n", a, b, c);
        array_print(C);
    }

    // div2
    printf("div2... ");
    passed = 1;
    for(a = 1; a < -1 && passed; a=2*a+1)
    {
        c = a/2;

        array_set(A, a);
        array_div2(A, C);
        passed = equal(C, c);
    }
    if(equal(C, c))
    {
        printf("passed\n");
    }
    else
    {
        printf("failed: %x /2 = %x. Got:\n", a, b, c);
        array_print(C);
    }

    // greater
    printf("greater... ");
    passed = 1;
    for(a = 1; a < 0xfffffff && passed; a=4*a+1)
    {
        for(b = 1; b <= 0xfffffff && passed; b=9*b-1)
        {
            c = (a > b);

            array_set(A, a);
            array_set(B, b);
            array_set(C, array_greater(A, B));
            passed = equal(C, c);
        }
    }
    if(equal(C, c))
    {
        printf("passed\n");
    }
    else
    {
        printf("failed: %x > %x = %x. Got:\n", a, b, c);
        array_print(C);
    }

    // equal
    printf("equal... ");
    passed = 1;
    for(a = 1; a < 0xfffffff && passed; a=4*a+1)
    {
        for(b = 1; b < 0xfffffff && passed; b=9*b-1)
        {
            c = (a == b);

            array_set(A, a);
            array_set(B, b);
            array_set(C, array_equal(A, B));
            passed = equal(C, c);
        }
    }
    if(equal(C, c))
    {
        printf("passed\n");
    }
    else
    {
        printf("failed: %x == %x = %x. Got:\n", a, b, c);
        array_print(C);
    }

    // mulmod
    printf("mulmod... ");
    passed = 1;
    array_set(N, 761);
    for(a = 1; a < 0xffff && passed; a=4*a+1)
    {
        for(b = 1; b < 0xffff && passed; b=9*b-1)
        {
            c = (a*b)%761;

            array_set(A, a);
            array_set(B, b);
            array_mulmod(A, B, N, C);
            passed = equal(C, c);
        }
    }
    if(equal(C, c))
    {
        printf("passed\n");
    }
    else
    {
        printf("failed: (%x * %x) %% %x = %x. Got:\n", a, b, 13, c);
        array_print(C);
    }
}