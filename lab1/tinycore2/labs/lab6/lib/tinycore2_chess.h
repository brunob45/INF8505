/*
-- File : tinycore2_chess.h (lab6)
--
-- Contents : Comnpiler header file of tinycore2 processor.
--            
-- Copyright (c) 2014-2017 Synopsys, Inc. This Synopsys processor model 
-- captures an ASIP Designer Design Technique. The model and all associated 
-- documentation are proprietary to Synopsys, Inc. and may only be used 
-- pursuant to the terms and conditions of a written license agreement with 
-- Synopsys, Inc.  All other use, reproduction, modification, or distribution 
-- of the Synopsys processor model or the associated  documentation is 
-- strictly prohibited. 
*/

#ifndef _tinycore2_chess_h
#define _tinycore2_chess_h

#include "tinycore2.h"

chess_properties {

 // General processor properties :

    default_memory  : DM;
    status_register : SREG;

 // Representation of built-in types

    representation char, signed char, unsigned char,
                   signed short, unsigned short,
                   signed long, unsigned long,
                   signed long long, unsigned long long,
                   float, double, long double            : undefined;

    representation int      : word;
    representation unsigned : word;
    representation void*    : word;                 // data pointers

    // Lab 6.1 (8): Add properties to specify the stack organisation

 // ABI

    argument_registers : R;
    link_register   : LR;

 // Stop when instruction enters this stage
    breakpoint_focus_stage : E1;

}

// Definition of built-in operators

promotion operator unsigned(int) = nil;
promotion operator int(unsigned) = nil;

promotion int operator+(int,int) = word add(word,word);
promotion int operator-(int,int) = word sub(word,word);
promotion int operator|(int,int) = word bor(word,word);
promotion int operator&(int,int) = word band(word,word);

promotion bool operator< (int,int) = bool lt(word,word);
promotion bool operator<=(int,int) = bool le(word,word);
promotion bool operator> (int,int) = bool gt(word,word);
promotion bool operator>=(int,int) = bool ge(word,word);

promotion unsigned operator+(unsigned,unsigned) = word add(word,word);
promotion unsigned operator-(unsigned,unsigned) = word sub(word,word);
promotion unsigned operator|(unsigned,unsigned) = word bor(word,word);
promotion unsigned operator&(unsigned,unsigned) = word band(word,word);

promotion void* operator+(void*,int) = word add(word,word);
promotion void* operator-(void*,int)   = word sub(word,word);
promotion int   operator-(void*,void*) = word sub(word,word);

promotion bool operator< (void*,void*) = bool lt(word,word);
promotion bool operator> (void*,void*) = bool gt(word,word);
promotion bool operator<=(void*,void*) = bool le(word,word);
promotion bool operator>=(void*,void*) = bool ge(word,word);

promotion operator void*(int)      = nil;
promotion operator void*(unsigned) = nil;
promotion operator int(void*)      = nil;
promotion operator unsigned(void*) = nil;

// Undefined built-in operators (avoid warnings)

promotion int operator* (int,int) = undefined;
promotion int operator/ (int,int) = undefined;
promotion int operator% (int,int) = undefined;
promotion int operator^ (int,int) = undefined;
promotion int operator<<(int,int) = undefined;
promotion int operator>>(int,int) = undefined;
promotion int operator~ (int) = undefined;

promotion bool operator==(int,int) = undefined;
promotion bool operator!=(int,int) = undefined;

promotion bool operator< (unsigned,unsigned) = undefined;
promotion bool operator> (unsigned,unsigned) = undefined;
promotion bool operator<=(unsigned,unsigned) = undefined;
promotion bool operator>=(unsigned,unsigned) = undefined;
promotion bool operator==(unsigned,unsigned) = undefined;
promotion bool operator!=(unsigned,unsigned) = undefined;

promotion unsigned operator* (unsigned,unsigned) = undefined;
promotion unsigned operator/ (unsigned,unsigned) = undefined;
promotion unsigned operator% (unsigned,unsigned) = undefined;
promotion unsigned operator^ (unsigned,unsigned) = undefined;
promotion unsigned operator<<(unsigned,int) = undefined;
promotion unsigned operator>>(unsigned,int) = undefined;
promotion unsigned operator~ (unsigned) = undefined;

promotion bool operator==(void*,void*) = undefined;
promotion bool operator!=(void*,void*) = undefined;

// Two-step generation of 16 bit constants

namespace tinycore2_primitive {
    inline void chess_convert(sbyte msb, ubyte lsb, word& L) property(big_endian)
    {
        L = bor(ldh(msb),lsb);
    }
};

chess_properties {
    convert_routing_const word : R;
}

#endif /*_tinycore2_chess_h*/
