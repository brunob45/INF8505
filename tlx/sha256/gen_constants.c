#include <stdio.h>

#define ARRAY_SIZE (1024/8+1)

unsigned char ONE[ARRAY_SIZE];

#include "keys/keys.h"
#include "ops.h"

byte N[ARRAY_SIZE], R[ARRAY_SIZE], C[ARRAY_SIZE];


int get_n(ARRAY_TYPE in)
{
    int i;
    for(i = 8*ARRAY_SIZE-1; i >= 0; i--)
    {
        if(array_bit_test(in, i))
        {
            return i+1;
        }
    }
    return 0;
}

uint set_constants(ARRAY_TYPE mod)
{
    uint n = get_n(modulus)+2;
    printf("unsigned int n=%d;\n", n);
    array_bit_set(R, n);
    array_modulus(R, modulus, C);
    array_mulmod(C, C, modulus, C);
    array_set(ONE, 1);

    printf("unsigned char modulus[] = {\n");
    array_print(modulus);
    printf("};\n");

    printf("unsigned char C [] = {\n");
    array_print(C);
    printf("};\n");

    printf("unsigned char ONE [] = {\n");
    array_print(ONE);
    printf("};\n");

    return n;
}

int main()
{
    uint n;
    n = set_constants(modulus);
    printf("unsigned char publicExponent[] = {\n");
    array_print(publicExponent);
    printf("};\n");
    printf("unsigned char privateExponent[] = {\n");
    array_print(privateExponent);
    printf("};\n");
    return 0;

}