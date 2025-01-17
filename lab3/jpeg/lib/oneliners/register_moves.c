
// File generated by noodle version N-2018.03#7d02e3ca79#180723, Sun Apr 14 19:29:10 2019
// Copyright 2014-2018 Synopsys, Inc. All rights reserved.
// noodle -Pc -B -Iisg +wisg -I../../io_modules -I/CMC/tools/synopsys/asip_designer_vN-2018.03-SP3/linux64/chessdir/../examples/io_modules -D__tct_patch__=300 -D__chess__ -D__programmers_view__ tlx

// File: register_moves.c
// Test register moves
// (Output is written as an in-out reference, so that it cannot be overlayed with the input)

//! Connection analysis may reveal that certain moves are not available, and those tests are skipped.
//! Note that the connection may be direct or indirect.
//! However, indirect connections via spill memory are not considered at this time!

extern "C" {

//-- signed char

void move___schar_R_R(signed char& chess_storage(R) r, signed char chess_storage(R) a) { r = a; }

//-- unsigned char

void move___uchar_R_R(unsigned char& chess_storage(R) r, unsigned char chess_storage(R) a) { r = a; }

//-- short

void move___sshort_R_R(short& chess_storage(R) r, short chess_storage(R) a) { r = a; }

//-- unsigned short

void move___ushort_R_R(unsigned short& chess_storage(R) r, unsigned short chess_storage(R) a) { r = a; }

//-- int

void move___sint_R_R(int& chess_storage(R) r, int chess_storage(R) a) { r = a; }

//-- unsigned

void move___uint_R_R(unsigned& chess_storage(R) r, unsigned chess_storage(R) a) { r = a; }

//-- long long

//-- unsigned long long

//-- float

void move___ffloat_R_R(float& chess_storage(R) r, float chess_storage(R) a) { r = a; }

//-- double

//-- void *

void move___Pvoid_R_R(void *& chess_storage(R) r, void * chess_storage(R) a) { r = a; }


} //extern "C"  (8 functions)
