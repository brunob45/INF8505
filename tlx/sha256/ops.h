#ifndef OPS_H
#define OPS_H

#ifndef ARRAY_SIZE
#error "ARRAY_SIZE not defined"
#endif

// #define I_AM_SPECIAL

typedef unsigned char *ARRAY_TYPE;
typedef unsigned char byte;
typedef unsigned int uint;

void array_add(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out);
void array_div2(ARRAY_TYPE in, ARRAY_TYPE out);
byte array_bit_test(ARRAY_TYPE in, uint bit);

void array_reset(ARRAY_TYPE inout);
void array_copy(ARRAY_TYPE in, ARRAY_TYPE out);

void ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE mod, uint n, ARRAY_TYPE out);
void ModularExponentiation(ARRAY_TYPE m, ARRAY_TYPE e, ARRAY_TYPE mod, uint n, ARRAY_TYPE c, ARRAY_TYPE out);

// below are only used to generate constants or testbench
void array_sub(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out);
void array_modulus(ARRAY_TYPE in1, ARRAY_TYPE mod, ARRAY_TYPE out);
void array_mulmod(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE mod, ARRAY_TYPE out);
void array_set(ARRAY_TYPE inout, uint value);
void array_bit_set(ARRAY_TYPE inout, uint bit);
byte array_notzero(ARRAY_TYPE in1);
byte array_geq(ARRAY_TYPE in1, ARRAY_TYPE in2);
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
        add_ci(in1[i], in2[i], carry, temp, carry);
        out[i] = temp;
#else
        temp = in1[i] + in2[i] + carry;
        carry = temp >> 8;
        out[i] = temp;
#endif
    }
    cpt_add++;
}

void array_sub(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    byte temp = 0, carry = 0;
    int i;
    // from the least significant byte to the most
    for (i = ARRAY_SIZE - 1; i >= 0; i--)
    {
#ifdef I_AM_SPECIAL
        sub_ci(in1[i], in2[i], carry, temp, carry);
        out[i] = temp;
#else
        temp = in1[i] - in2[i] - carry;
        carry = in2[i] > (in1[i] - carry);
        out[i] = temp;
#endif
    }
}

void array_div2(ARRAY_TYPE in, ARRAY_TYPE out)
{
    int temp = 0, carry = 0, i;
    // from the most significant byte to the least
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        temp = (in[i] >> 1) | carry;
        carry = in[i] << 7;
        out[i] = temp;
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
    for (i = 1; i <= 4; i++)
    {
        j = ARRAY_SIZE - i;
        inout[j] = value >> (8 * (i - 1));
    }
}

byte array_bit_test(ARRAY_TYPE in, uint bit)
{
    uint index, shift;

    cpt_test++;
    index = ARRAY_SIZE - 1 - (bit / 8);
    shift = bit % 8;
    return (in[index] >> shift) & 1;
}

byte array_geq(ARRAY_TYPE in1, ARRAY_TYPE in2)
{
    int i;
    // from the most significant byte to the least
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (in1[i] > in2[i])
        {
            return 1;
        }
        if (in1[i] < in2[i])
        {
            return 0;
        }
    }
    return 1;
}

byte array_notzero(ARRAY_TYPE in1)
{
    int i;
    // from the most significant byte to the least
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (in1[i])
        {
            return 1;
        }
    }
    return 0;
}

void array_print(ARRAY_TYPE in)
{
    int i;
    printf("  ");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("0x%x, ", in[i]);
        if (i % 16 == 15)
        {
            printf("\n  ");
        }
    }
    printf("\n");
}

void array_bit_set(ARRAY_TYPE inout, uint bit)
{
    array_reset(inout);
    if (bit < ARRAY_SIZE * 8)
    {
        inout[ARRAY_SIZE - 1 - bit / 8] |= 1 << (bit % 8);
    }
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

void array_modulus(ARRAY_TYPE in1, ARRAY_TYPE mod, ARRAY_TYPE out)
{
    array_copy(in1, out);
    while (array_geq(out, mod))
    {
        array_sub(out, mod, out);
    }
}

void array_mulmod(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE mod, ARRAY_TYPE res)
{
    array_copy(in1, WORK1);
    array_copy(in2, WORK2);

    array_reset(res);
    array_modulus(WORK1, mod, WORK1);
    while (array_notzero(WORK2))
    {
        if (array_bit_test(WORK2, 0))
        {
            array_add(res, WORK1, res);
            array_modulus(res, mod, res);
        }
        array_add(WORK1, WORK1, WORK1);
        array_modulus(WORK1, mod, WORK1);
        array_div2(WORK2, WORK2);
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