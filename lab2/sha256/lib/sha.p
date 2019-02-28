/*
-- File : sha.p
--
-- Contents : Definition of SHA secure hash primitives.
*/

#define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
#define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

void sha256_ci(w32 ai, w32 bi, w32 ci, w32 di, 
                 w32 ei, w32 fi, w32 gi, w32 hi, w32 ki, w32 mi,
                 w32& ao, w32& bo, w32& co, w32& d2, 
                 w32& eo, w32& fo, w32& go, w32& ho)
{
      uint32_t a = ai;
      uint32_t b = bi;
      uint32_t c = ci;
      uint32_t d = di;
      uint32_t e = ei;
      uint32_t f = fi;
      uint32_t g = gi;
      uint32_t h = hi;
      
      uint32_t k = ki;
      uint32_t m = mi;

      uint32_t t1 = h + EP1(e) + CH(e,f,g) + k + m;
      uint32_t t2 = EP0(a) + MAJ(a,b,c);

      ho = g;
      go = f;
      fo = e;
      eo = d + t1;
      d2 = c;
      co = b;
      bo = a;
      ao = t1 + t2;
}

w32 sha256_in1(w32 ai, w32 bi, w32 ci, w32 di)
{
    uint32_t a = ai;
    uint32_t b = bi;
    uint32_t c = ci;
    uint32_t d = di;
    
    return SIG1(a) + b + SIG0(c) + d;
}

w32 sha256_in2(w32 ai, w32 bi, w32 ci, w32 di)
{
    uint32_t a = ai;
    uint32_t b = bi;
    uint32_t c = ci;
    uint32_t d = di;
 
    return (a << 24) | (b << 16) | (c << 8) | d;
}
