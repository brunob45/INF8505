/*
-- File : tinycore2.h (lab5)
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
    class ubyte      property( 8 bit unsigned);
    class threebitsu property( 3 bit unsigned);

// --------------------
// Primitive operations
// --------------------

// Functional operations

    word add (word, word) property(commutative);
    word sub (word, word);
    word band(word, word) property(commutative);
    word bor (word, word) property(commutative);
    word mul (word, word) property(commutative);
    word srl (word, word);

    bool lt(word, word);
    bool le(word, word);
    bool gt(word, word);
    bool ge(word, word);

    word ldh(sbyte);

// Control operations

    void jumpi(sbyte)         property(relative jump);
    void jumpci(bool,sbyte)   property(relative jump);
    word bsr(word)            property(absolute call);
    void rts(word)            property(ret);

    void nop()                property(nop);

 // Primitive data type conversions

    class word {
        word(sbyte);
        word(ubyte);
    };
}

#endif
