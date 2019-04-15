/*
-- File : tlx_sha.h
--
-- Contents : Integer application layer for the SHA intrinsic functions.
--
-- Copyright (c) 2017 Synopsys, Inc. This Synopsys processor model 
-- captures an ASIP Designer Design Technique. The model and all associated 
-- documentation are proprietary to Synopsys, Inc. and may only be used 
-- pursuant to the terms and conditions of a written license agreement with 
-- Synopsys, Inc.  All other use, reproduction, modification, or distribution 
-- of the Synopsys processor model or the associated  documentation is 
-- strictly prohibited. 
*/

#ifndef _tlx_sha_h
#define _tlx_sha_h


promotion unsigned DUCbCr(unsigned R, unsigned G, unsigned B, int Cb_in, int Cr_in,
                          int& Cb_out, int& Cr_out)
          =
          w32 DUCbCr(w32 R, w32 G, w32 B, w32 Cb_in, w32 Cr_in, w32& Cb_out, w32& Cr_out);

inline unsigned DUCbCr(unsigned R, unsigned G, unsigned B, int& Cb, int& Cr)
{
    return DUCbCr(R, G, B, Cb, Cr, Cb, Cr);
}

promotion
    void jpeg_fdct(int a, int b, int c, int d, 
                       int e, int f, int g, int h,
                       int& n, int& o, int& p, int& q, 
                       int& r, int& s, int& t, int& u)
    =
    void jpeg_fdct(w32 a, w32 b, w32 c, w32 d, w32 e, w32 f, w32 g, w32 h,
                w32& n, w32& o, w32& p, w32& q, w32& r, w32& s, w32& t, w32& u);
 
inline void jpeg_fdct(int& a, int& b, int& c, int& d, 
                        int& e, int& f, int& g, int& h)
{
    jpeg_fdct(a,b,c,d,e,f,g,h,a,b,c,d,e,f,g,h);          
}       


#endif /* _tlx_sha_h */

