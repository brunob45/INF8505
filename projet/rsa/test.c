#include <stdio.h>

unsigned BIT_TEST(unsigned x, unsigned n)
{
    return (x >> n) & 0x01;
}

unsigned get_r(unsigned x)
{
    int n = sizeof(unsigned)*8 - 1;
    while(n >= 0 && !BIT_TEST(x, n))
    {
        n--;
    }
    return 2<<(n);
}

// unsigned montgomery_domain(unsigned x, unsigned n)
// {
//     return  (x*b) % n;
// }

unsigned modulo_inverse(unsigned x, unsigned n)
{
    int result;
    for(result = 0; result < n; result++)
    {
        if( (x *result) % n == 1)
            break;
    }
    return result;
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
    printf("%d\n", a);
    while(a % R != 0)
    {
        a += p;
        printf("%d\n", a);
    }
    a /= R;
    printf("%d\n", a);
    return a;
}


int main(int argc, char** argv)
{
    unsigned n = 97;
    unsigned b = get_r(n);
    unsigned r_ = (b*b)%n;

    unsigned x, y, a, result, z;

    x = Montgomery2(43, r_, b, n);
    y = Montgomery2(56, r_, b, n);
    a = Montgomery2(x, y, b, n);
    
    result = Montgomery2(a, 1, b, n);
    printf("result:%d\n", result);

    return 0;

}