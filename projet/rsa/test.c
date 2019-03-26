#include <stdio.h>

unsigned BIT_TEST(unsigned x, unsigned n)
{
    return (x >> n) & 0x01;
}

unsigned get_b(unsigned x)
{
    int n = sizeof(unsigned)*8 - 1;
    while(n >= 0 && !BIT_TEST(x, n))
    {
        n--;
    }
    return n+1;
}

unsigned get_r(unsigned x)
{
    return 1<<get_b(x);
}

unsigned ModularMultipliaction2(unsigned A, unsigned B, unsigned n, unsigned N)
{
    // step 1
    unsigned R = 0;

    // step2
    for(int i = 0; i <= n; i++)
    {
        R = R + ((A&(1<<i)) * B);
        R = R + ((R&(1<<0)) * N);
        R = R/2;
    }

    // step 3
    while(R > N) R = R-N;

    // step 4
    return R;
}

unsigned ModularMultipliaction(unsigned x, unsigned y, unsigned R, unsigned p)
{
    unsigned a = x * y;
    while(a % R != 0)
        a += p;
    a /= R;
    return a;
}

unsigned REDC2(unsigned x, unsigned y, unsigned n)
{
    unsigned r = get_r(n);
    unsigned r_ = (r*r)%n;
    unsigned a;

    // transform
    x = ModularMultipliaction(x, r_, r, n);
    y = ModularMultipliaction(y, r_, r, n);

    // multiply
    a = ModularMultipliaction(x, y, r, n);
    
    // transform back
    return ModularMultipliaction(a, 1, r, n);
}

unsigned ModularExponentiation(unsigned M, unsigned e, unsigned N)
{
    unsigned n = get_b(N);
    unsigned r = get_r(N);
    unsigned C = (r*r)%N;

    // step 1
    unsigned M_ = ModularMultipliaction(M, C, r, N);
    unsigned R = ModularMultipliaction(C, 1, r, N);

    // step 2
    for(int i = 0; i < n; i++)
    {
        //2a
        if(e>>i & 1) R = ModularMultipliaction(R, M_, r, N);
        //2b
        M_ = ModularMultipliaction(M_, M_, r, N);
    }
    // step 3
    R = ModularMultipliaction(R, 1, r, N);
    // step 4
    return R;
}


int main(int argc, char** argv)
{
    // this works
    printf("result:%d\n", REDC2(43,56,97));

    // test new function
    unsigned a = ModularMultipliaction2(43, 9, 7, 97);
    unsigned b = ModularMultipliaction(43, 9, 1<<7, 97); // should be 25
    printf("test:%d, correct:%d\n", a, b);

    // below works too!
    unsigned c = ModularExponentiation(12, 2, 13);
    printf("%d\n", c);

    return 0;

}