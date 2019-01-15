
// File generated by noodle version N-2018.03#7d02e3ca79#180723, Fri Jan 11 17:23:01 2019
// Copyright 2014-2018 Synopsys, Inc. All rights reserved.
// noodle -Pc -B -Iisg +wisg -D__tct_patch__=300 +NOrlt -D__chess__ -D__programmers_view__ tinycore2

// File: register_spilling.c
// Test spilling of registers to stack
// (Each function is required to save and restore one specific register(file) around the call of `foo'.
//  Note that the connection may be direct or indirect, atomic or complex.
//  If a value is moved through some other register, that need not be spilled itself, as it may be clobbered.)

//! Connection analysis may reveal that certain registers are not spillable, and those tests are skipped.

// (It is possible that certain component-registers are not (individually) spillable, yet that the structure is.
//  These are then not a problem for, e.g., a full context switch.)

extern "C" {

void foo() property(loop_free);


//! not spillable! void spill_R() clobbers_not(R) { foo(); }


} //extern "C"  (1 functions of which 1 skipped)
