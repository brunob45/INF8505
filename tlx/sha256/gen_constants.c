#include <stdio.h>

#define ARRAY_SIZE (1024/8+1)
#define ARRAY_TYPE unsigned char*

#include "ops.h"
#include "keys/keys.h"

byte N[ARRAY_SIZE], R[ARRAY_SIZE], A[ARRAY_SIZE], B[ARRAY_SIZE], Z[ARRAY_SIZE], C[ARRAY_SIZE], ONE[ARRAY_SIZE];

uint set_constants(ARRAY_TYPE mod, ARRAY_TYPE R, ARRAY_TYPE C)
{
    uint n = get_n(mod)+2;
    printf("unsigned int n=%d;\n", n);
    array_bit_set(R, n);
    array_modulus(R, mod, C);
    array_mulmod(C, C, mod, C);

    printf("unsigned char modulus[] = {\n");
    array_print(mod);
    printf("};\n");

    printf("unsigned char C [] = {\n");
    array_print(C);
    printf("};\n");

    return n;
}

int main()
{
    uint n;
    n = set_constants(modulus, R, C);
    printf("unsigned char publicExponent[] = {\n");
    array_print(publicExponent);
    printf("};\n");
    printf("unsigned char privateExponent[] = {\n");
    array_print(privateExponent);
    printf("};\n");
    return 0;

}