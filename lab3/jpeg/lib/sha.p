#define CONST_BITS  8
#define FIX_0_382683433  ((uint32_t)   98)		/* FIX(0.382683433) */
#define FIX_0_541196100  ((uint32_t)  139)		/* FIX(0.541196100) */
#define FIX_0_707106781  ((uint32_t)  181)		/* FIX(0.707106781) */
#define FIX_1_306562965  ((uint32_t)  334)		/* FIX(1.306562965) */

w32 DUCbCr(w32 R, w32 G, w32 B, w32 Cb_in, w32 Cr_in, w32& Cb_out, w32& Cr_out)
{
    w32 Cb = Cb_in;
    w32 Cr = Cr_in;
    w32 DU;
    
    DU = ((int8_t)( ( 19595*R + 38470*G +  7471*B)>>16 ) - 128);
    Cb += (w32)((int8_t)( (-11058*R - 21708*G + 32768*B)>>16 ) );
    Cr += (w32)((int8_t)( ( 32768*R - 27438*G -  5328*B)>>16 ) );
    Cb_out = Cb;
    Cr_out = Cr;
    
    return DU;
}

void jpeg_fdct(w32 i0, w32 i1, w32 i2, w32 i3,
           w32 i4, w32 i5, w32 i6, w32 i7,
           w32& o0, w32& o1, w32& o2, w32& o3,
           w32& o4, w32& o5, w32& o6, w32& o7)
{  
    uint32_t tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
    uint32_t tmp10, tmp11, tmp12, tmp13;
    uint32_t z1, z2, z3, z4, z5, z11, z13;
    
    tmp0 = i0 + i7;
    tmp7 = i0 - i7;
    tmp1 = i1 + i6;
    tmp6 = i1 - i6;
    tmp2 = i2 + i5;
    tmp5 = i2 - i5;
    tmp3 = i3 + i4;
    tmp4 = i3 - i4;

    z1 = (((tmp1 - tmp2) + (tmp0 - tmp3)) * FIX_0_707106781)>>CONST_BITS; // c4 

    /* The rotator is modified from fig 4-8 to avoid extra negations. */
    z5 = (((tmp4 + tmp5) - (tmp6 + tmp7)) * FIX_0_382683433)>>CONST_BITS; /* c6 */
    z2 = (((tmp4 + tmp5) * FIX_0_541196100)>>CONST_BITS) + z5; /* c2-c6 */
    z4 = (((tmp6 + tmp7) * FIX_1_306562965)>>CONST_BITS) + z5; /* c2+c6 */
    z3 = (((tmp5 + tmp6) * FIX_0_707106781)>>CONST_BITS); /* c4 */

    z11 = tmp7 + z3;		/* phase 5 */
    z13 = tmp7 - z3;
    
    o0 = (tmp0 + tmp3) + (tmp1 + tmp2); // phase 3
    o4 = (tmp0 + tmp3) - (tmp1 + tmp2);
    o2 = (tmp0 - tmp3) + z1;	// phase 5
    o6 = (tmp0 - tmp3) - z1;
    o5 = z13 + z2;	/* phase 6 */
    o3 = z13 - z2;
    o1 = z11 + z4;
    o7 = z11 - z4;
}




