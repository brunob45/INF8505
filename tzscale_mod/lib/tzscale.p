/*
-- File : tzscale.p
--
-- Contents : Definition of the tzscale primitives.
--
-- Copyright (c) 2015-2016 Synopsys, Inc. This Synopsys processor model 
-- captures an ASIP Designer Design Technique. The model and all associated 
-- documentation are proprietary to Synopsys, Inc. and may only be used 
-- pursuant to the terms and conditions of a written license agreement with 
-- Synopsys, Inc.  All other use, reproduction, modification, or distribution 
-- of the Synopsys processor model or the associated  documentation is 
-- strictly prohibited. 
*/


w32 add(w32 a, w32 b) { return a + b; }

w32 sub(w32 a, w32 b)
{
    uint33_t aa = (uint32_t)a;
    uint33_t bb = (uint32_t)b;
    uint33_t rr = aa - bb;
    return rr[31:0];
}

w32 mul(w32 a, w32 b)   { return a * b; }

w32 mulh(w32 a, w32 b)
{
    int64_t p = a * b;
    return p[63:32];
} 

w32 mulhsu(w32 a, w32 b)
{
    int64_t p = a * (uint32_t)b;
    return p[63:32];
} 

w32 mulhu(w32 a, w32 b)
{
    int64_t p = (uint32_t)a * (uint32_t)b;
    return p[63:32];
} 

/*
w32 auipc (w32 a, w32 b)
{
    return a + b;
}
*/

w32 band (w32 a, w32 b) { return a &  b; }
w32 bor  (w32 a, w32 b) { return a |  b; }
w32 bxor (w32 a, w32 b) { return a ^ b; } 

w32 slt (w32 a, w32 b) { return a <  b; }

bool eq (w32 a, w32 b) { return a == b;  } 
bool ne (w32 a, w32 b) { return a != b;  }
bool lt (w32 a, w32 b) { return a  < b; }
bool ge (w32 a, w32 b) { return a >= b;   }

bool ltu (w32 a, w32 b) { return (uint32_t)a  < (uint32_t)b; }
bool geu (w32 a, w32 b) { return (uint32_t)a >= (uint32_t)b;   }

w32 sltu(w32 a, w32 b) { return (uint32_t)a <  (uint32_t)b; }

w32 sra (w32 a, w32 b) { return a           >> b[4:0]; }
w32 sll (w32 a, w32 b) { return (uint32_t)a << b[4:0]; }
w32 srl (w32 a, w32 b) { return (uint32_t)a >> b[4:0]; }

w32 extend_sign(w08 a) { return a; }
w32 extend_zero(w08 a) { return (uint8_t)a; }
w32 extend_sign(w16 a) { return a; }
w32 extend_zero(w16 a) { return (uint16_t)a; }
w08 extract_w08(w32 a) { return a[7:0]; }
w16 extract_w16(w32 a) { return a[15:0]; }


void nop() { }

//w32 pcadd(w32 a, w32 b) { return a + b; } 

#if defined(__go__)
addr incr1(addr a) { return a + 1; }
addr incr4(addr a) { return a + 4; }
#endif


#include "tzscale_rsa.p"

#include "tzscale_div.p"

#include "tzscale_io.p"

