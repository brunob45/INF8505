/*
-- File : tinycore2.h (solution lab2)
--
-- Contents : Primitive header file of tinycore2 processor.
--
-- Copyright (c) 2014-2017 Synopsys, Inc. This Synopsys processor model 
-- captures an ASIP Designer Design Technique. The model and all associated 
-- documentation are proprietary to Synopsys, Inc. and may only be used 
-- pursuant to the terms and conditions of a written license agreement with 
-- Synopsys, Inc.  All other use, reproduction, modification, or distribution 
-- of the Synopsys processor model or the associated  documentation is 
-- strictly prohibited. 
*/

#ifndef _tinycore2_h
#define _tinycore2_h

namespace tinycore2_primitive {

// ---------------------------------
// Primitive data-types declarations
// ---------------------------------

    class word       property(16 bit signed);
    class pmtype     property(14 bit unsigned);   // program memory type    
    class sbyte      property( 8 bit signed);
    class threebitsu property( 3 bit unsigned);

// --------------------
// Primitive operations
// --------------------

    // Lab 2.1: Add primitive functions for ALU operations
    word add (word, word) property(commutative);
    word sub (word, word);
    word band (word, word) property(commutative);
    word bor (word, word) property(commutative);
    
    class word {
       word(sbyte);
    };
    
    // Lab 2.4 (2): Add  a NOP primitive 
    void nop() property(nop);

}

#endif /*_tinycore2_h*/

