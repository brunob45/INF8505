
// File generated by noodle version N-2018.03#7d02e3ca79#180723, Thu Feb 28 14:33:23 2019
// Copyright 2014-2018 Synopsys, Inc. All rights reserved.
// noodle -Pc -B -Iisg +wisg -I../../io_modules -I/CMC/tools/synopsys/asip_designer_vN-2018.03-SP3/linux64/chessdir/../examples/io_modules -D__tct_patch__=300 -D__chess__ -D__programmers_view__ tlx

#ifdef __chess__
#error "generated native file not intended for compilation by chess"
#endif

#ifndef _tlx_chess_opns_h
#define _tlx_chess_opns_h

// Native equivalent of Chess promoted operations

bool land(bool, bool);
bool lor(bool, bool);
bool lxor(bool, bool);
bool nez(int);
bool eqz(int);
bool nez(unsigned);
bool eqz(unsigned);
//!bool nez(void *);
//!bool eqz(void *);
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint to_dint_se(int);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint to_dint_ze(int);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ int to_int(dint);
} //namespace tlx_primitive
#endif//!
namespace tlx_primitive{
unsigned add(unsigned, unsigned, uint1 &);
} //namespace tlx_primitive
namespace tlx_primitive{
unsigned sub(unsigned, unsigned, uint1 &);
} //namespace tlx_primitive
namespace tlx_primitive{
unsigned addx(unsigned, unsigned, uint1, uint1 &);
} //namespace tlx_primitive
namespace tlx_primitive{
unsigned subx(unsigned, unsigned, uint1, uint1 &);
} //namespace tlx_primitive
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint l_add(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint l_sub(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint l_and(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint l_or(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint l_xor(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint l_complement(dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ bool l_lts(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ bool l_les(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ bool l_ltu(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ bool l_leu(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ bool l_eq(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ bool l_ne(dint, dint);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint l_lsl(dint, int);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint l_asr(dint, int);
} //namespace tlx_primitive
#endif//!
#if 0//!
namespace tlx_primitive{
    /*inline*/ dint l_lsr(dint, int);
} //namespace tlx_primitive
#endif//!
void sha256_ci(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned &, unsigned &, unsigned &, unsigned &, unsigned &, unsigned &, unsigned &, unsigned &);
unsigned sha256_in1(unsigned, unsigned, unsigned, unsigned);
unsigned sha256_in2(unsigned, unsigned, unsigned, unsigned);


// do_generate[_native] inline functions

namespace tlx_primitive{
extern int mul_called(int, int);
} //namespace tlx_primitive

extern int div_called(int, int, chess_output int &);

    inline int div_remainder(int a, int b, int &r)
    {
     return div_called(a,b,r);
    }

extern unsigned div_called(unsigned, unsigned, chess_output unsigned &);

    inline unsigned long div_remainder(unsigned a, unsigned b, unsigned &r)
    {
     return div_called(a,b,r);
    }

namespace tlx_primitive{
extern long long lmul_called(long long, long long);
} //namespace tlx_primitive

extern long long div_called(long long, long long, chess_output long long &);

    inline long long div_remainder(long long a, long long b, long long &r)
    {
     return div_called(a,b,r);
    }

extern unsigned long long div_called(unsigned long long, unsigned long long, chess_output unsigned long long &);

    inline unsigned long long div_remainder(unsigned long long a, unsigned long long b, unsigned long long &r)
    {
     return div_called(a,b,r);
    }

    inline void char_memory_copy(volatile char *l, const volatile char *r, const int sz)
    {
     char *ll = (char *)l;
     char *rr = (char *)r;
     if (sz < 5)
      {
       if (sz >= 1)
        * ll++ = * rr++;
       else
        ;
       if (sz >= 2)
        * ll++ = * rr++;
       else
        ;
       if (sz >= 3)
        * ll++ = * rr++;
       else
        ;
       if (sz >= 4)
        *ll = *rr;
       else
        ;
      }
     else
      for (int ii = 0;
           ii < sz; ii++)
       ll[ii] = rr[ii];
    }

    inline void short_memory_copy(volatile short *l, const volatile short *r, const int sz)
    {
     short *ll = (short *)l;
     short *rr = (short *)r;
     if (sz < 5)
      {
       if (sz >= 1)
        * ll++ = * rr++;
       else
        ;
       if (sz >= 2)
        * ll++ = * rr++;
       else
        ;
       if (sz >= 3)
        * ll++ = * rr++;
       else
        ;
       if (sz >= 4)
        *ll = *rr;
       else
        ;
      }
     else
      for (int ii = 0;
           ii < sz; ii++)
       ll[ii] = rr[ii];
    }

    inline void int_memory_copy(volatile int *l, const volatile int *r, const int sz)
    {
     int *ll = (int *)l;
     int *rr = (int *)r;
     if (sz < 5)
      {
       if (sz >= 1)
        * ll++ = * rr++;
       else
        ;
       if (sz >= 2)
        * ll++ = * rr++;
       else
        ;
       if (sz >= 3)
        * ll++ = * rr++;
       else
        ;
       if (sz >= 4)
        *ll = *rr;
       else
        ;
      }
     else
      for (int ii = 0;
           ii < sz; ii++)
       ll[ii] = rr[ii];
    }

    inline void float_raise(int flags)
    {
    }

extern unsigned int32_to_float32(int);

extern tlx_primitive::dint int32_to_float64(int);

extern int float32_to_int32(unsigned);

extern int float32_to_int32_round_to_zero(unsigned);

extern tlx_primitive::dint float32_to_float64(unsigned);

extern unsigned float32_round_to_int(unsigned);

extern unsigned float32_add(unsigned, unsigned);

extern unsigned float32_sub(unsigned, unsigned);

extern unsigned float32_mul(unsigned, unsigned);

extern unsigned float32_div(unsigned, unsigned);

extern unsigned float32_rem(unsigned, unsigned);

extern unsigned float32_sqrt(unsigned);

extern int float32_eq(unsigned, unsigned);

extern int float32_le(unsigned, unsigned);

extern int float32_lt(unsigned, unsigned);

extern int float32_eq_signaling(unsigned, unsigned);

extern int float32_le_quiet(unsigned, unsigned);

extern int float32_lt_quiet(unsigned, unsigned);

    inline int float32_is_signaling_nan(unsigned a)
    {
     return (a >> 22 & 511) == 510 && a & 4194303;
    }

extern int float64_to_int32(tlx_primitive::dint);

extern int float64_to_int32_round_to_zero(tlx_primitive::dint);

extern unsigned float64_to_float32(tlx_primitive::dint);

extern tlx_primitive::dint float64_round_to_int(tlx_primitive::dint);

extern tlx_primitive::dint float64_add(tlx_primitive::dint, tlx_primitive::dint);

extern tlx_primitive::dint float64_sub(tlx_primitive::dint, tlx_primitive::dint);

extern tlx_primitive::dint float64_mul(tlx_primitive::dint, tlx_primitive::dint);

extern tlx_primitive::dint float64_div(tlx_primitive::dint, tlx_primitive::dint);

extern tlx_primitive::dint float64_rem(tlx_primitive::dint, tlx_primitive::dint);

extern tlx_primitive::dint float64_sqrt(tlx_primitive::dint);

extern int float64_eq(tlx_primitive::dint, tlx_primitive::dint);

extern int float64_le(tlx_primitive::dint, tlx_primitive::dint);

extern int float64_lt(tlx_primitive::dint, tlx_primitive::dint);

extern int float64_eq_signaling(tlx_primitive::dint, tlx_primitive::dint);

extern int float64_le_quiet(tlx_primitive::dint, tlx_primitive::dint);

extern int float64_lt_quiet(tlx_primitive::dint, tlx_primitive::dint);

    inline int float64_is_signaling_nan(tlx_primitive::dint a)
    {
     return (a.high >> 19 & 4095) == 4094 && (a.low || a.high & 524287);
    }

    inline int f32_to_i32(unsigned a)
    {
     return float32_to_int32_round_to_zero(a);
    }

    inline unsigned i32_to_f32(int a)
    {
     return int32_to_float32(a);
    }

    inline unsigned f32_add(unsigned a, unsigned b)
    {
     return float32_add(a,b);
    }

    inline unsigned f32_sub(unsigned a, unsigned b)
    {
     return float32_sub(a,b);
    }

    inline unsigned f32_mul(unsigned a, unsigned b)
    {
     return float32_mul(a,b);
    }

    inline unsigned f32_div(unsigned a, unsigned b)
    {
     return float32_div(a,b);
    }

    inline bool f32_le(unsigned a, unsigned b)
    {
     return float32_le(a,b);
    }

    inline bool f32_lt(unsigned a, unsigned b)
    {
     return float32_lt(a,b);
    }

    inline bool f32_eq(unsigned a, unsigned b)
    {
     return float32_eq(a,b);
    }

    inline int f64_to_i32(tlx_primitive::dint a)
    {
     return float64_to_int32_round_to_zero(a);
    }

    inline tlx_primitive::dint i32_to_f64(int a)
    {
     return int32_to_float64(a);
    }

    inline tlx_primitive::dint f32_to_f64(unsigned a)
    {
     return float32_to_float64(a);
    }

    inline unsigned f64_to_f32(tlx_primitive::dint a)
    {
     return float64_to_float32(a);
    }

    inline tlx_primitive::dint f64_add(tlx_primitive::dint a, tlx_primitive::dint b)
    {
     return float64_add(a,b);
    }

    inline tlx_primitive::dint f64_sub(tlx_primitive::dint a, tlx_primitive::dint b)
    {
     return float64_sub(a,b);
    }

    inline tlx_primitive::dint f64_mul(tlx_primitive::dint a, tlx_primitive::dint b)
    {
     return float64_mul(a,b);
    }

    inline tlx_primitive::dint f64_div(tlx_primitive::dint a, tlx_primitive::dint b)
    {
     return float64_div(a,b);
    }

    inline bool f64_le(tlx_primitive::dint a, tlx_primitive::dint b)
    {
     return float64_le(a,b);
    }

    inline bool f64_lt(tlx_primitive::dint a, tlx_primitive::dint b)
    {
     return float64_lt(a,b);
    }

    inline bool f64_eq(tlx_primitive::dint a, tlx_primitive::dint b)
    {
     return float64_eq(a,b);
    }

    inline void sha256_ci(unsigned &a, unsigned &b, unsigned &c, unsigned &d, unsigned &e, unsigned &f, unsigned &g, unsigned &h, unsigned ki, unsigned mi)
    {
     sha256_ci(a,b,c,d,e,f,g,h,ki,mi,a,b,c,d,e,f,g,h);
    }



// composed promotion conversions
namespace tlx_primitive {
    w32 __promo_bool_on_w32(bool);
    bool __promo_w32_to_bool(w32);
} //namespace tlx_primitive


#endif /*_tlx_chess_opns_h*/
