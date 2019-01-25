
// File generated by noodle version N-2018.03#7d02e3ca79#180723, Fri Jan 25 16:14:37 2019
// Copyright 2014-2018 Synopsys, Inc. All rights reserved.
// noodle -Pc -Iisg +wisg -D__tct_patch__=300 -D__chess__ -D__programmers_view__ tinycore2

// File: constant_generation.c
// Test constant generation

extern "C" {

//-- int                        // property( 16 bit   signed )

int                 ctgen___sint_0000() { return 0; }
int                 ctgen___sint_0009() { return 9; }
int                 ctgen___sint_fff7() { return -9; }
int                 ctgen___sint_32b1() { return 12977; }
int                 ctgen___sint_b2b1() { return -19791; }

//-- unsigned                   // property( 16 bit unsigned )

unsigned            ctgen___uint_0000() { return 0; }
unsigned            ctgen___uint_0009() { return 9; }
unsigned            ctgen___uint_fff7() { return 65527U; }
unsigned            ctgen___uint_32b1() { return 12977; }
unsigned            ctgen___uint_b2b1() { return 45745U; }



// Relocatable addresses, range determined by memory
// (Type of object is irrelevant, but must be allocatable, so using the primitive type)

extern tinycore2_primitive::pmtype chess_storage(PM) o_PM;
void chess_storage(PM) * ctptr_PM() { return &o_PM; }

extern tinycore2_primitive::word chess_storage(DM) o_DM;
void chess_storage(DM) * ctptr_DM() { return &o_DM; }


} //extern "C"  (12 functions)
