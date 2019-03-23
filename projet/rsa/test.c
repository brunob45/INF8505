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

unsigned montgomery_domain(unsigned x, unsigned r, unsigned n)
{
    if(r <= n) return -1;
    unsigned temp = r-n;
    unsigned ret = 0;
    while(temp--)
    {
        ret = ret + x;
        if(ret > n) ret = ret - n;
    }
    return ret;
}

unsigned modular_inverse(unsigned x, unsigned n)
{
    int result;
    for(result = 0; result < n; result++)
    {
        if( (x *result) % n == 1)
            break;
    }
    return result;
}

int main(int argc, char** argv)
{
    unsigned x = 35;
    unsigned n = 97;
    unsigned r = get_r(n);
    unsigned r_ = modular_inverse(r, n);
    printf("%d, %d\n", r%n, r_);
    return 0;

    unsigned m = montgomery_domain(x, r, n);
    unsigned z = montgomery_domain(x, modular_inverse(r, n), n);
    printf("%d: %d: %d\n", r, m, z);
    return 0;


    // unsigned a = 2;
    // unsigned b = 3;
    // unsigned r = 256; // 2^k
    // unsigned n = 11; // modulo
    // unsigned k = 8; // bits
    // unsigned S[k+1];
    // unsigned q;

    // unsigned A = ((a%n)*(r%n))%n;
    // unsigned B = ((b%n)*(r%n))%n;

    // S[0] = 0;
    // for(int i = 0; i < k; i++)
    // {
    //     q = ((S[i]&1) + (A>>i & 1)*(B&1)) % 2;
    //     S[i+1] = (S[i]+(A>>i & 1)*(B)+q*n)/2;
    // }
    // printf("%d", S[k]);
}