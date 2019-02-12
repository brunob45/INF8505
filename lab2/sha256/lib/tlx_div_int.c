


namespace tlx_primitive {


int mul_called(int a, int b) property(functional)
{
    int p = 0;
    int nsteps = chess_bitsof(int);
    while (nsteps-- > 0) {
        if (b & 1) p += a;
        a <<= 1;
        b >>= 1;
    }
    return p;
}

long long lmul_called(long long a, long long b) property(functional)
{
    long long p = 0;
    int nsteps = chess_bitsof(long long);
    while (nsteps-- > 0) {
        if (b & 1) p += a;
        a <<= 1;
        b >>= 1;
    }
    return p;
}



}
