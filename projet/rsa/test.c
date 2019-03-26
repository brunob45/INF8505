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

unsigned Montgomery(unsigned x, unsigned y, unsigned R, unsigned p)
{
    unsigned a = 0;

    for(int i = 0; i < 8; i++)
    {
        a = a + ((x&(1<<i)) * y);
        a = a + ((a&1) * p);
        a = a/2;
    }

    while(a > p) a = a-p;

    return a;
}

unsigned Montgomery2(unsigned x, unsigned y, unsigned R, unsigned p)
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
    x = Montgomery2(x, r_, r, n);
    y = Montgomery2(y, r_, r, n);

    // multiply
    a = Montgomery2(x, y, r, n);
    
    // transform back
    return Montgomery2(a, 1, r, n);
}


int main(int argc, char** argv)
{
    // this works
    printf("result:%d\n", REDC2(43,56,97));

    // test new function
    unsigned a = Montgomery(43, 9, 100, 97);
    unsigned b = Montgomery2(43, 9, 100, 97); // should be 32
    printf("test:%d, correct:%d\n", a, b);

    return 0;

}