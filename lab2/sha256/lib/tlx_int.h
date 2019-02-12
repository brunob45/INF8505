/*
-- File : tlx_int.h
--
-- Contents : Integer application layer for the TLX processor.
--
-- Copyright (c) 2014-2016 Synopsys, Inc. This Synopsys processor model 
-- captures an ASIP Designer Design Technique. The model and all associated 
-- documentation are proprietary to Synopsys, Inc. and may only be used 
-- pursuant to the terms and conditions of a written license agreement with 
-- Synopsys, Inc.  All other use, reproduction, modification, or distribution 
-- of the Synopsys processor model or the associated  documentation is 
-- strictly prohibited. 
*/




#ifndef _tlx_int_h
#define _tlx_int_h

// type conversions

namespace tlx_primitive {
    promotion w32(int) = nil;  // for the count of zloop 
}

promotion operator signed char(unsigned char)     = { w32 sign_extend_08(w32),
                                                      w08 extract_w08(w32),
						      w32 extend_sign(w08) };
promotion operator signed char(signed short)      = { w32 sign_extend_08(w32),
                                                      w08 extract_w08(w32) };
promotion operator signed char(unsigned short)    = { w32 sign_extend_08(w32),
                                                      w08 extract_w08(w32) };
promotion operator signed char(int)	          = { w32 sign_extend_08(w32),
                                                      w08 extract_w08(w32) };
promotion operator signed char(unsigned)          = { w32 sign_extend_08(w32),
                                                      w08 extract_w08(w32) };
promotion operator unsigned char(signed char)     = { w32 zero_extend_08(w32),
                                                      w08 extract_w08(w32),
						      w32 extend_zero(w08) };
promotion operator unsigned char(signed short)    = { w32 zero_extend_08(w32),
                                                      w08 extract_w08(w32) };
promotion operator unsigned char(unsigned short)  = { w32 zero_extend_08(w32),
                                                      w08 extract_w08(w32) };
promotion operator unsigned char(int)	          = { w32 zero_extend_08(w32),
                                                      w08 extract_w08(w32) };
promotion operator unsigned char(unsigned)	  = { w32 zero_extend_08(w32),
                                                      w08 extract_w08(w32) };

promotion operator  signed short(signed char)     = nil; 
promotion operator  signed short(unsigned char)   = nil;
promotion operator  signed short(unsigned short)  = { w32 sign_extend_16(w32),
                                                      w16 extract_w16(w32),
						      w32 extend_sign(w16) };
promotion operator  signed short(int)             = { w32 sign_extend_16(w32),
                                                      w16 extract_w16(w32) };
promotion operator  signed short(unsigned)        = { w32 sign_extend_16(w32),
                                                      w16 extract_w16(w32) };
promotion operator  unsigned short(signed char)   = { w32 zero_extend_16(w32),
                                                      w16 extract_w16(w32) };
promotion operator  unsigned short(unsigned char) = nil;
promotion operator  unsigned short(signed short)  = { w32 zero_extend_16(w32),
                                                      w16 extract_w16(w32),
						      w32 extend_zero(w16) };
promotion operator  unsigned short(int)           = { w32 zero_extend_16(w32),
                                                      w16 extract_w16(w32) };
promotion operator  unsigned short(unsigned)      = { w32 zero_extend_16(w32),
                                                      w16 extract_w16(w32) };

promotion operator  int(signed char)          = nil; 
promotion operator  int(unsigned char)        = nil; 
promotion operator  int(signed short)         = nil; 
promotion operator  int(unsigned short)       = nil; 
promotion operator  int(unsigned)             = nil;

promotion operator  unsigned(signed char)     = nil; 
promotion operator  unsigned(unsigned char)   = nil; 
promotion operator  unsigned(signed short)    = nil; 
promotion operator  unsigned(unsigned short)  = nil; 
promotion operator  unsigned(int)             = nil;

// pointer conversions

promotion operator void* (int)                = nil; 
promotion operator int (void*)                = nil; 
promotion operator void* (unsigned)           = nil; 
promotion operator unsigned (void*)           = nil; 

promotion operator void*(unsigned short)      = undefined;
promotion operator unsigned short(void*)      = undefined;
promotion operator void*(short)               = undefined;
promotion operator short(void*)               = undefined;
promotion operator void*(unsigned char)       = undefined;
promotion operator unsigned char(void*)       = undefined;
promotion operator void*(signed char)         = undefined;
promotion operator signed char(void*)         = undefined;

// pointer operators :

promotion void* operator+(void*,int)   = { w32 add(w32,w32,uint1&),
					   w32 add(w32,w32) };
promotion void* operator-(void*,int)   = w32 sub(w32,w32,uint1&);
promotion int   operator-(void*,void*) = w32 sub(w32,w32,uint1&);

// add, subtract and bitwise operators on ALU 

promotion  int operator+(int,int) = { w32 add(w32,w32,uint1&),
                                      w32 add(w32,w32) };
promotion  int operator-(int,int) = w32 sub(w32,w32,uint1&);
promotion  int operator&(int,int) = w32 band(w32,w32);
promotion  int operator|(int,int) = w32 bor (w32,w32);
promotion  int operator^(int,int) = w32 bxor(w32,w32);
inline int operator~(int a)  { return int(a) ^ -1; }

promotion  unsigned operator+(unsigned,unsigned) = { 
                                      w32 add(w32,w32,uint1&), 
	                              w32 add(w32,w32) };
promotion  unsigned operator-(unsigned,unsigned) = w32 sub(w32,w32,uint1&);
promotion  unsigned operator&(unsigned,unsigned) = w32 band(w32,w32);
promotion  unsigned operator|(unsigned,unsigned) = w32 bor (w32,w32);
promotion  unsigned operator^(unsigned,unsigned) = w32 bxor(w32,w32);
inline unsigned operator~(unsigned a)  { return int(a) ^ -1; }

// multiply operators

// promotion int operator*(int,int)  = w32 mul(w32,w32);
// promotion unsigned operator*(unsigned,unsigned)  = w32 mul(w32,w32);

namespace tlx_primitive {
    int mul_called(int a, int b) property(functional);
};

inline   signed int operator*(  signed int a,  signed int b) {
    return tlx_primitive::mul_called(a,b);
}
inline unsigned int operator*(unsigned int a,unsigned int b) {
    return tlx_primitive::mul_called((int)a,(int)b);
}

// shift operators 

promotion int operator<<(int,int) = w32 sll(w32,w32);
promotion int operator>>(int,int) = w32 sra(w32,w32);
promotion unsigned operator<<(unsigned,int) = w32 sll(w32,w32);
promotion unsigned operator>>(unsigned,int) = w32 srl(w32,w32);

// compare operators

promotion bool operator< (int,int) = w32 slt(w32,w32);
promotion bool operator<=(int,int) = w32 sle(w32,w32);
promotion bool operator> (int,int) = w32 sgt(w32,w32);
promotion bool operator>=(int,int) = w32 sge(w32,w32);
promotion bool operator==(int,int) = w32 seq(w32,w32);
promotion bool operator!=(int,int) = w32 sne(w32,w32);

promotion bool operator< (unsigned,unsigned) = w32 sltu(w32,w32);
promotion bool operator<=(unsigned,unsigned) = w32 sleu(w32,w32);
promotion bool operator> (unsigned,unsigned) = w32 sgtu(w32,w32);
promotion bool operator>= (unsigned,unsigned) = w32 sgeu(w32,w32);
promotion bool operator==(unsigned,unsigned) = w32 seq(w32,w32);
promotion bool operator!=(unsigned,unsigned) = w32 sne(w32,w32);

promotion  bool operator< (void*,void*) = w32 sltu(w32,w32);
promotion  bool operator<=(void*,void*) = w32 sleu(w32,w32);
promotion  bool operator> (void*,void*) = w32 sgtu(w32,w32);
promotion  bool operator>=(void*,void*) = w32 sgeu(w32,w32);
promotion  bool operator==(void*,void*) = w32 seq(w32,w32);
promotion  bool operator!=(void*,void*) = w32 sne(w32,w32);

promotion bool operator!(bool) = { bool eqz(w32) , w32 seq0(w32) }; 
promotion bool land(bool,bool) = w32 band(w32,w32);
promotion bool lor(bool,bool)  = w32 bor (w32,w32);
promotion bool lxor(bool,bool) = w32 bxor(w32,w32);

promotion bool nez(int)      = { bool nez(w32), w32 sne0(w32) };
promotion bool eqz(int)      = { bool eqz(w32), w32 seq0(w32) };
promotion bool nez(unsigned) = { bool nez(w32), w32 sne0(w32) };
promotion bool eqz(unsigned) = { bool eqz(w32), w32 seq0(w32) };
promotion bool nez(void*)    = { bool nez(w32), w32 sne0(w32) };
promotion bool eqz(void*)    = { bool eqz(w32), w32 seq0(w32) };

promotion operator int(bool) = nil;  

chess_properties {
    complements: bool eqz(w32), bool nez(w32);
    
    complements: bool ::eqz(int), bool ::nez(int);
    complements: bool ::eqz(unsigned), bool ::nez(unsigned);
    complements: bool ::eqz(void*), bool ::nez(void*);
}

// signed divide and modulo

extern "C++"
int div_called(int, int, chess_output int&) property(functional);

inline int div_remainder(int a, int b, int& r) property(functional)
{
    return div_called(a,b,r);
}

inline int operator/(int a, int b)
{
    int r;
    return div_remainder(a,b,r);
}

inline int operator%(int a, int b)
{
    int r;
    div_remainder(a,b,r);
    return r;
}

// unsigned divide and modulo

extern "C++"
unsigned div_called(unsigned, unsigned, chess_output unsigned &) property(functional);

inline unsigned long div_remainder(unsigned a,
                                   unsigned b,
                                   unsigned & r)
                                   property(functional)
{
    return div_called(a,b,r);
}

inline unsigned operator/(unsigned a, unsigned b)
{
    unsigned r;
    return div_remainder(a,b,r);
}

inline unsigned operator%(unsigned a, unsigned b)
{
    unsigned r;
    div_remainder(a,b,r);
    return r;
}

#endif /* _tlx_int_h */

