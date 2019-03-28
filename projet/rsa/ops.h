#ifndef OPS_H
#define OPS_H

#define byte unsigned char
#define uint unsigned int

#ifndef ARRAY_SIZE
#error "ARRAY_SIZE not defined"
#endif

#ifndef ARRAY_TYPE
#error "ARRAY_TYPE not defined"
#endif

void array_add(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out);
void array_sub(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out);
void array_div2(ARRAY_TYPE in, ARRAY_TYPE out);
void array_modulus(ARRAY_TYPE in1, ARRAY_TYPE mod, ARRAY_TYPE out);
void array_mulmod(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE mod, ARRAY_TYPE out);

void array_reset(ARRAY_TYPE inout);
void array_set(ARRAY_TYPE inout, uint value);
void array_copy(ARRAY_TYPE in, ARRAY_TYPE out);

byte array_bit_test(ARRAY_TYPE in, uint bit);
void array_bit_set(ARRAY_TYPE inout, uint bit);

byte array_greater(ARRAY_TYPE in1, ARRAY_TYPE in2);
byte array_lower(ARRAY_TYPE in1, ARRAY_TYPE in2);
byte array_geq(ARRAY_TYPE in1, ARRAY_TYPE in2);
byte array_leq(ARRAY_TYPE in1, ARRAY_TYPE in2);
byte array_equal(ARRAY_TYPE in1, ARRAY_TYPE in2);

void array_print(ARRAY_TYPE in);

void array_add(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    int temp = 0, carry = 0, i;
    for(i = ARRAY_SIZE-1; i >= 0; i--)
    {
        temp = in1[i] + in2[i] + carry;
        out[i] = temp & 0xff;
        carry = temp >> 8;
    }
}

void array_sub(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    int temp = 0, carry = 0, i;
    for(i = ARRAY_SIZE-1; i >= 0; i--)
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
    int temp = 0, carry = 0, i;
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        temp = in[i];
        out[i] = (temp >> 1) | carry;
        carry = temp << 7;
    }
}

void array_reset(ARRAY_TYPE inout)
{
    int i;
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        inout[i] = 0;
    }
}

void array_set(ARRAY_TYPE inout, uint value)
{
    int i, j;
    array_reset(inout);
    for(i = 1; i <= 2; i++)
    {
        j = ARRAY_SIZE-i;
        inout[j] = value >> (8 * (i-1));
    }
}

byte array_bit_test(ARRAY_TYPE in, uint bit)
{
    uint index, shift;

    index = ARRAY_SIZE-1 - (bit/8);
    shift = bit%8;
    return (in[index] >> shift) & 1;
}

byte array_greater(ARRAY_TYPE in1, ARRAY_TYPE in2)
{
    int i;
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        if(in1[i] > in2[i])
        {
            return 1;
        }
        if(in1[i] < in2[i])
        {
            return 0;
        }
    }
    return 0;
}

byte array_leq(ARRAY_TYPE in1, ARRAY_TYPE in2)
{
    return !array_greater(in1, in2);
}

byte array_lower(ARRAY_TYPE in1, ARRAY_TYPE in2)
{
    return array_greater(in2, in1);
}

byte array_geq(ARRAY_TYPE in1, ARRAY_TYPE in2)
{
    return !array_greater(in2, in1);
}

byte array_equal(ARRAY_TYPE in1, ARRAY_TYPE in2)
{
    int i;
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        if(in1[i] != in2[i])
        {
            return 0;
        }
    }
    return 1;
}

void array_print(ARRAY_TYPE in)
{
    int i;
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%x\t", in[i]);
    }
    printf("\n");
}

void array_bit_set(ARRAY_TYPE inout, uint bit)
{
    if(bit < ARRAY_SIZE*8)
    {
        inout[ARRAY_SIZE-1-bit/8] |= 1 << (bit%8);
    }
}

void array_copy(ARRAY_TYPE in, ARRAY_TYPE out)
{
    int i;
    if(in != out)
    {
        for(i = 0; i < ARRAY_SIZE; i++)
        {
            out[i] = in[i];
        }
    }
}

void array_modulus(ARRAY_TYPE in1, ARRAY_TYPE mod, ARRAY_TYPE out)
{
    array_copy(in1, out);
    while(array_geq(out, mod))
    {
        array_sub(out, mod, out);
    }
}

void array_mulmod(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE mod, ARRAY_TYPE res)
{
    byte ZERO[ARRAY_SIZE], a[ARRAY_SIZE], b[ARRAY_SIZE];

    array_copy(in1, a);
    array_copy(in2, b);

    array_reset(res);
    array_reset(ZERO);

    array_modulus(a, mod, a);
    while(!array_equal(b, ZERO))
    {
        if(array_bit_test(b, 0))
        {
            array_add(res, a, res);
            array_modulus(res, mod, res);
        }
        array_add(a, a, a);
        array_modulus(a, mod, a);
        array_div2(b, b);
    }
}

void ModularMultiplication(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE mod, uint n, ARRAY_TYPE out)
{
    int i;
    byte WORK1[ARRAY_SIZE], WORK2[ARRAY_SIZE];

    array_copy(in1, WORK1);
    array_copy(in2, WORK2);
    array_set(out, 0);

    for(i = 0; i<n; i++)
    {
        if(array_bit_test(WORK1, i))
        {
            array_add(out, WORK2, out);
        }
        if(array_bit_test(out, 0))
        {
            array_add(out, mod, out);
        }
        array_div2(out, out);
    }
}

void ModularExponentiation(ARRAY_TYPE m, ARRAY_TYPE e, ARRAY_TYPE mod, uint n, ARRAY_TYPE C, ARRAY_TYPE out)
{
    byte ONE[ARRAY_SIZE];
    array_set(ONE, 1);

    ModularMultiplication(m, C, mod, n, m);
    ModularMultiplication(C, ONE, mod, n, out);

    // step 2
    for(int i = 0; i < n; i++)
    {
        if(array_bit_test(e, i))
        {
            ModularMultiplication(out, m, mod, n, out);
        }
        ModularMultiplication(m, m, mod, n, m);
    }
    ModularMultiplication(out, ONE, mod, n, out);
}

int get_n(ARRAY_TYPE in)
{
    int i;
    for(i = 8*ARRAY_SIZE-1; i >= 0; i--)
    {
        printf("%d>%d\n", i, array_bit_test(in, i));
        if(array_bit_test(in, i))
        {
            return i+1;
        }
    }
    return 0;
}

uint set_constants(ARRAY_TYPE mod, ARRAY_TYPE R, ARRAY_TYPE C)
{
    uint n = get_n(mod)+2;
    printf("n=%d\n", n);
    array_bit_set(R, n);
    array_modulus(R, mod, C);
    array_mulmod(C, C, mod, C);

    printf("N=");
    array_print(mod);
    printf("R=");
    array_print(R);
    printf("C=");
    array_print(C);

    return n;
}


#endif // OPS_H