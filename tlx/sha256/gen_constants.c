#include <stdio.h>

#define ARRAY_SIZE (1024/8+1)

#include "ops.h"

byte N[ARRAY_SIZE], R[ARRAY_SIZE], C[ARRAY_SIZE], ONE[ARRAY_SIZE];

uint set_constants()
{
    uint n = get_n(modulus)+2;
    printf("unsigned int n=%d;\n", n);
    array_bit_set(R, n);
    array_modulus(R, C);
    array_mulmod(C, C, C);
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
    n = set_constants();
    printf("unsigned char publicExponent[] = {\n");
    array_print(publicExponent);
    printf("};\n");
    printf("unsigned char privateExponent[] = {\n");
    array_print(privateExponent);
    printf("};\n");
    return 0;

}