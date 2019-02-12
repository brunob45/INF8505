/*
-- File : tlx_sha.h
*/

#ifndef _tlx_sha_h
#define _tlx_sha_h

promotion
    void sha256_ci(unsigned a, unsigned b, unsigned c, unsigned d, 
                       unsigned e, unsigned f, unsigned g, unsigned h, unsigned ki, unsigned mi,
                       unsigned& n, unsigned& o, unsigned& p, unsigned& q, 
                       unsigned& r, unsigned& s, unsigned& t, unsigned& u)
    =
    void sha256_ci(w32 a, w32 b, w32 c, w32 d, w32 e, w32 f, w32 g, w32 h, w32 ki, w32 mi,
                w32& n, w32& o, w32& p, w32& q, w32& r, w32& s, w32& t, w32& u);
 
inline void sha256_ci(unsigned& a, unsigned& b, unsigned& c, unsigned& d, 
                        unsigned& e, unsigned& f, unsigned& g, unsigned& h, unsigned ki, unsigned mi)
{
    sha256_ci(a,b,c,d,e,f,g,h,ki,mi,a,b,c,d,e,f,g,h);          
}             
#endif /* _tlx_sha_h */

