#include <stdio.h>

#define byte unsigned char
#define uint unsigned int

#define ARRAY_SIZE 4
#define ARRAY_TYPE byte*

uint n;
byte N[ARRAY_SIZE], R[ARRAY_SIZE], ONE[ARRAY_SIZE], A[ARRAY_SIZE], B[ARRAY_SIZE], Z[ARRAY_SIZE], C[ARRAY_SIZE];

void array_add(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out);
void array_sub(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out);
void array_div2(ARRAY_TYPE in, ARRAY_TYPE out);
void array_set(ARRAY_TYPE inout, uint value);
byte array_bit_test(ARRAY_TYPE in, uint bit);
byte array_greater(ARRAY_TYPE in1, ARRAY_TYPE in2);
void array_print(ARRAY_TYPE in);
void array_bit_set(ARRAY_TYPE inout, uint bit);

void array_add(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    uint temp = 0, carry = 0;
    for(int i = ARRAY_SIZE; i >= 0; i--)
    {
        temp = in1[i] + in2[i] + carry;
        out[i] = temp & 0xff;
        carry = temp >> 8;
    }
}

void array_sub(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    uint temp = 0, carry = 0;
    for(int i = ARRAY_SIZE; i >= 0; i--)
    {
        if(in2[i] > (in1[i]-carry))
        {
            temp = 0x100+in1[i]-in2[i]-carry;
            carry = 1;
        }
        else
        {
            temp = in1[i]-in2[i]-carry;
            carry = 0;
        }
        out[i] = temp & 0xff;
    }
}

void array_div2(ARRAY_TYPE in, ARRAY_TYPE out)
{
    int temp = 0, carry = 0;
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        temp = in[i];
        out[i] = (temp >> 1) | carry;
        carry = temp << 7;
    }
}

void array_set(ARRAY_TYPE inout, uint value)
{
    for(int i = 1; i <= 4; i++)
    {
        int j = ARRAY_SIZE-i;
        inout[j] = value >> (8 * (i-1));
    }
}

byte array_bit_test(ARRAY_TYPE in, uint bit)
{
    uint index = ARRAY_SIZE-1 - (bit/8);
    uint shift = bit%8;
    return (in[index] >> shift) & 1;
}

byte array_greater(ARRAY_TYPE in1, ARRAY_TYPE in2)
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        if(in1[i] > in2[i])
            return 1;
        if(in1[i] < in2[i])
            return 0;
    }
    return 0;
}

void array_print(ARRAY_TYPE in)
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%x\t", in[i]);
    }
    printf("\n");
}

void array_bit_set(ARRAY_TYPE inout, uint bit)
{
    if(bit < ARRAY_SIZE*8)
        inout[ARRAY_SIZE-1-bit/8] |= 1 << (bit%8);
}

void array_copy(ARRAY_TYPE in, ARRAY_TYPE out)
{
    for(int i = 0; i < ARRAY_SIZE; i++)
        out[i] = in[i];
}

void array_mulmod(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    byte i[ARRAY_SIZE], work[ARRAY_SIZE];
    array_set(i, 0);
    array_set(work, 0);
    while(array_greater(in2, i))
    {
        array_add(i, ONE, i);
        array_add(work, in1, work);
        if(array_greater(work, N)) array_sub(work, N, work);
    }
    array_copy(work, out);
}

unsigned ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    // printf("(%d x %d) %% %d\n", *in1, *in2, *N);
    byte work[ARRAY_SIZE];
    array_set(work, 0);
    for(int i = 0; i<n; i++)
    {
        if(array_bit_test(in1, i)) array_add(work, in2, work);
        if(array_bit_test(work, 0)) array_add(work, N, work);
        array_div2(work, work);
    }
    array_copy(work, out);
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

void set_constants()
{
    array_set(ONE, 1);
    n = 0;
    array_bit_set(R, n);
    printf("N=");
    array_print(N);
    while(array_greater(N, R))//*R < *N)
    {
        n = n+1;
        array_set(R, 0);
        array_bit_set(R, n);
    }
    printf("R=");
    array_print(R);
    array_mulmod(R, ONE, C);
    array_mulmod(C, C, C);
    printf("C=");
    array_print(C);
}

void ModularExponentiation(ARRAY_TYPE m, ARRAY_TYPE e)
{
    ModularMultiplication(m, C, m);
    ModularMultiplication(C, ONE, Z);

    // step 2
    for(int i = 0; i < n; i++)
    {
        if(array_bit_test(e, i)) ModularMultiplication(Z, m, Z);
        ModularMultiplication(m, m, m);
    }
    ModularMultiplication(Z, ONE, Z);
}


int main(int argc, char** argv)
{
    array_set(N, 3233);
    set_constants();

    // *N = 3233; *A = 65; *B = 17;
    array_set(A, 65);
    array_set(B, 17);
    
    ModularExponentiation(A, B);
    printf("Z=");
    array_print(Z);

    array_copy(Z, A);
    array_set(B, 413);
    ModularExponentiation(A, B);
    printf("Z=");
    array_print(Z);

    return 0;

}