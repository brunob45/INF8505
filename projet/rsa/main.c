#include <stdio.h>

#define byte unsigned char

// #define ARRAY_SIZE 1024/sizeof(unsigned char)
#define ARRAY_SIZE 3
#define ARRAY_TYPE byte*

// Inputs
unsigned int n;
//byte N[ARRAY_SIZE] = {0,0,12};
byte M[ARRAY_SIZE] = {0,0,72};
byte E[ARRAY_SIZE] = {0,0,107};

// Temporary
byte Mp[ARRAY_SIZE];

// Constants
byte ONE[ARRAY_SIZE];
byte C[ARRAY_SIZE];

// Output
byte R[ARRAY_SIZE];

byte N[ARRAY_SIZE] = {0,0,12};
byte A[ARRAY_SIZE] = {0,0,7};
byte B[ARRAY_SIZE] = {0,0,5};

// byte Z[ARRAY_SIZE];


void add_array(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out);
void sub_array(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out);
void div2_array(ARRAY_TYPE in, ARRAY_TYPE out);
void set_array(ARRAY_TYPE inout, unsigned int value);
byte check_bit_array(ARRAY_TYPE in, unsigned int bit);
byte greater_array(ARRAY_TYPE in1, ARRAY_TYPE in2);
void print_array(ARRAY_TYPE in);
void set_bit_array(ARRAY_TYPE inout, unsigned int bit);

unsigned int get_n(ARRAY_TYPE in)
{
  return ARRAY_SIZE*8;

  int n = ARRAY_SIZE*8 - 1;
  while(n >= 0 && !check_bit_array(in, n))
  {
    n--;
  }
  return n+1;
}


void add_array(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    unsigned int temp = 0, carry = 0;
    for(int i = ARRAY_SIZE; i >= 0; i--)
    {
        temp = in1[i] + in2[i] + carry;
        out[i] = temp & 0xff;
        carry = temp >> 8;
    }
}

void sub_array(ARRAY_TYPE in1, ARRAY_TYPE in2, ARRAY_TYPE out)
{
    unsigned int temp = 0, carry = 0;
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

void div2_array(ARRAY_TYPE in, ARRAY_TYPE out)
{
    int temp = 0, carry = 0;
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        temp = in[i];
        out[i] = (temp >> 1) | carry;
        carry = temp << 7;
    }
}

void set_array(ARRAY_TYPE inout, unsigned int value)
{
    for(int i = 1; i <= 4; i++)
    {
        int j = ARRAY_SIZE-i;
        inout[j] = value >> (8 * (i-1));
    }
}

byte check_bit_array(ARRAY_TYPE in, unsigned int bit)
{
    return !!(in[ARRAY_SIZE-1-bit/8] & 1<<(bit%8));
}

byte greater_array(ARRAY_TYPE in1, ARRAY_TYPE in2)
{
    for(int i = ARRAY_SIZE-1; i >= 0; i--)
    {
        if(in1[i] > in2[i])
            return 1;
        if(in1[i] < in2[i])
            return 0;
    }
    return 0;
}

void print_array(ARRAY_TYPE in)
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%x\t", in[i]);
    }
    printf("\n");
}

void set_bit_array(ARRAY_TYPE inout, unsigned int bit)
{
    if(bit < ARRAY_SIZE*8)
        inout[ARRAY_SIZE-1-bit/8] |= 1 << (bit%8);
}

int MMM(ARRAY_TYPE _A, ARRAY_TYPE _B, ARRAY_TYPE _R)
{
    set_array(_R, 0);

    for(int i = 0; i < n; i++)
    {
      print_array(_R);
        if(check_bit_array(_A, i))
            add_array(_R, _B, _R);
      print_array(_R);
        if(check_bit_array(_R, 0))
            add_array(_R, N, _R);
      print_array(_R);
        div2_array(_R, _R);
    }
    print_array(_R);
    if(greater_array(_R, N))
        sub_array(_R, N, _R);
    print_array(_R);
}

void MME(ARRAY_TYPE _M, ARRAY_TYPE _e, ARRAY_TYPE _C, ARRAY_TYPE _R)
{
    MMM(_M, _C, Mp);
    MMM(_C, ONE, _R);
    print_array(_R);

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        if(check_bit_array(_e, i))
            MMM(_R, Mp, _R);
        MMM(Mp, Mp, Mp);
    }
    MMM(_R, ONE, _R);
}

int main(int argc, char** argv)
{
  n = get_n(N);
  printf("n:%d\n", n);
  set_array(ONE, 1);
  
  set_array(C, 0);
  set_bit_array(C, 2*(ARRAY_SIZE+2));

  MMM(A, B, R);
  print_array(A);
  print_array(B);
  print_array(R);

  return 0;
  MME(M, E, C, R);
  print_array(R);

}
