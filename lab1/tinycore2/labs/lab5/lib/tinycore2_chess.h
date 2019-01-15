/*
-- File : tinycore2_chess.h (lab5)
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

    // Lab 5.1 (3): Add a representation for types int, unsigned and void* 
    representation int      : word;
    representation unsigned : word;
    representation void*    : word;
    
 // ABI

    // Lab 5.1 (5): Add a property to organize the argument passing 
    argument_registers : R;
    link_register   : LR;

 // Stop when instruction enters this stage
    breakpoint_focus_stage : E1;

}

// Definition of built-in operators

// Lab 5.1 (4): Define a mapping for the int+int and int-int operators
promotion int operator+(int,int) = word add(word,word);
promotion int operator-(int,int) = word sub(word,word);

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
