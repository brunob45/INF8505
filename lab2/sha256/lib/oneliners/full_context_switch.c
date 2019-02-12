
// File generated by noodle version N-2018.03#7d02e3ca79#180723, Thu Jan 24 11:26:26 2019
// Copyright 2014-2018 Synopsys, Inc. All rights reserved.
// noodle -Pc -B -Iisg +wisg -I../../io_modules -I/CMC/tools/synopsys/asip_designer_vN-2018.03-SP3/linux64/chessdir/../examples/io_modules -D__tct_patch__=300 -D__chess__ -D__programmers_view__ tlx

// File: full_context_switch.c
// Test full context switch  (requires spilling)
// (Unlike other tests, these functions may generate quite a lot of code.
//  More specific tests can be found in file  register_spilling.c .
//  In particular, check for relevant registers reported to be not spillable.)

extern "C" {

void foo() property(loop_free);


void test_save_restore_all_clobbered_registers() clobbers()
{
    // must save all caller-saved registers
    foo();
    // must restore all caller-saved registers
}


} //extern "C"  (1 functions)
