#ifndef OPS_H
#define OPS_H

#ifndef ARRAY_SIZE
#error "ARRAY_SIZE not defined"
#endif

#define I_AM_SPECIAL

typedef unsigned int *ARRAY_TYPE;
typedef unsigned int byte;
typedef unsigned int uint;

void array_add(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out);
void array_div2(ARRAY_TYPE in, ARRAY_TYPE out);
byte array_bit_test(ARRAY_TYPE in, uint bit);

void array_reset(ARRAY_TYPE inout);
void array_copy(ARRAY_TYPE in, ARRAY_TYPE out);

void ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE mod, uint n, ARRAY_TYPE out);
void ModularExponentiation(ARRAY_TYPE m, ARRAY_TYPE e, ARRAY_TYPE mod, uint n, ARRAY_TYPE c, ARRAY_TYPE out);

// below are only used in testbenches
void array_set(ARRAY_TYPE inout, uint value);
void array_print(ARRAY_TYPE in);

byte WORK1[ARRAY_SIZE], WORK2[ARRAY_SIZE];
unsigned cpt_add, cpt_div, cpt_test, cpt_mod;

void array_add(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    unsigned int temp = 0, carry = 0;
    int i;
    // from the least significant byte to the most
    for (i = ARRAY_SIZE - 1; i >= 0; i--)
    {
#ifdef I_AM_SPECIAL
        out[i] = rsa_add(in1[i], in2[i], carry);
#else
        temp = in1[i] + in2[i] + carry;
        carry = temp >> 32;
        out[i] = temp;
#endif
    }
    cpt_add++;
}

void array_div2(ARRAY_TYPE in, ARRAY_TYPE out)
{
    unsigned carry = 0;
    int temp = 0, i;
    // from the most significant byte to the least
    for (i = 0; i < ARRAY_SIZE; i++)
    {
#ifdef I_AM_SPECIAL
        out[i] = rsa_div2(in[i], carry);
#else
        temp = (in[i] >> 1) | carry;
        carry = in[i] << 31;
        out[i] = temp;
#endif
    }
    cpt_div++;
}

void array_reset(ARRAY_TYPE inout)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        inout[i] = 0;
    }
}

void array_set(ARRAY_TYPE inout, uint value)
{
    int i, j;
    array_reset(inout);
    inout[ARRAY_SIZE-1] = value;
}

byte array_bit_test(ARRAY_TYPE in, uint bit)
{
    uint index, shift;

    cpt_test++;
    index = ARRAY_SIZE - 1 - (bit / 8);
    shift = bit % 8;
    return (in[index] >> shift) & 1;
}

void array_print(ARRAY_TYPE in)
{
    int i;
    printf("  ");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("0x%08x, ", in[i]);
        if (i % 4 == 3)
        {
            printf("\n  ");
        }
    }
    printf("\n");
}

void array_copy(ARRAY_TYPE in, ARRAY_TYPE out)
{
    int i;
    if (in != out)
    {
        for (i = 0; i < ARRAY_SIZE; i++)
        {
            out[i] = in[i];
        }
    }
}

void ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE mod, uint n, ARRAY_TYPE out)
{
    unsigned int i;

    array_copy(in1, WORK1);
    array_copy(in2, WORK2);
    array_reset(out);

    for (i = 0; i < n; i++)
    {
        if (array_bit_test(WORK1, i))
        {
            array_add(out, WORK2, out);
        }
        if (array_bit_test(out, 0))
        {
            array_add(out, mod, out);
        }
        array_div2(out, out);
    }
    cpt_mod++;
}

void ModularExponentiation(ARRAY_TYPE m, ARRAY_TYPE e, ARRAY_TYPE mod, uint n, ARRAY_TYPE c, ARRAY_TYPE out)
{
    unsigned int i;

    cpt_add = cpt_div = cpt_mod = cpt_test = 0;

    ModularMultiplication(m, c, mod, n, m);
    ModularMultiplication(c, ONE, mod, n, out);

    // step 2
    for (i = 0; i < n; i++)
    {
        if (array_bit_test(e, i))
        {
            ModularMultiplication(out, m, mod, n, out);
        }
        ModularMultiplication(m, m, mod, n, m);
    }
    ModularMultiplication(out, ONE, mod, n, out);

    printf("add:%d\ndiv:%d\ntest:%d\nmod:%d\n", cpt_add, cpt_div, cpt_test, cpt_mod);
}

#endif // OPS_H