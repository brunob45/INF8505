
// File generated by noodle version N-2018.03#7d02e3ca79#180723, Fri Jan 25 16:14:37 2019
// Copyright 2014-2018 Synopsys, Inc. All rights reserved.
// noodle -Pc -Iisg +wisg -D__tct_patch__=300 -D__chess__ -D__programmers_view__ tinycore2

// File: memory_DM.c
// Test memory DM pointer arithmetic stand-alone and with load/store

#ifndef N // arbitrary value, adapt at will
#define N 7
#endif

extern "C" {

//-- int                        // size=1 alignment=1

void pointer_p1___sint_DM(int chess_storage(DM)*& p) { ++p; }
void pointer_m1___sint_DM(int chess_storage(DM)*& p) { --p; }
void pointer_pN___sint_DM(int chess_storage(DM)*& p) { p += N; }
void pointer_mN___sint_DM(int chess_storage(DM)*& p) { p -= N; }
//!? unimplemented pointer add, direct access only
//!void pointer_pI___sint_DM(int chess_storage(DM)*& p, int i) { p += i; }
//!void pointer_mI___sint_DM(int chess_storage(DM)*& p, int i) { p -= i; }

int chess_storage(DM) global___sint_DM;
int chess_storage(DM) garray___sint_DM[N+1];

int load_global___sint_DM() { return global___sint_DM; }
int load_garray_pN___sint_DM() { return garray___sint_DM[N]; }
//!? unimplemented pointer add, direct access only
//!int load_garray_pI___sint_DM(int i) { return garray___sint_DM[i]; }

void store_global___sint_DM(int a) { global___sint_DM = a; }
void store_garray_pN___sint_DM(int a) { garray___sint_DM[N] = a; }
//!? unimplemented pointer add, direct access only
//!void store_garray_pI___sint_DM(int a, int i) { garray___sint_DM[i] = a; }


int load_indirect0___sint_DM(int chess_storage(DM)* p) { return *p; }
int load_indexedp1___sint_DM(int chess_storage(DM)* p) { return p[ 1]; }
int load_indexedm1___sint_DM(int chess_storage(DM)* p) { return p[-1]; }
int load_indexedpN___sint_DM(int chess_storage(DM)* p) { return p[ N]; }
int load_indexedmN___sint_DM(int chess_storage(DM)* p) { return p[-N]; }
//!? unimplemented pointer add, direct access only
//!int load_indexedpI___sint_DM(int chess_storage(DM)* p, int i) { return p[ i]; }
//!int load_indexedmI___sint_DM(int chess_storage(DM)* p, int i) { return p[-i]; }

//!int load_postmodp1___sint_DM(int chess_storage(DM)*& p) { return *p++; }
//!int load_postmodm1___sint_DM(int chess_storage(DM)*& p) { return *p--; }
//!int load_postmodpN___sint_DM(int chess_storage(DM)*& p) { int t = *p; p += N; return t; }
//!int load_postmodmN___sint_DM(int chess_storage(DM)*& p) { int t = *p; p -= N; return t; }
//!? unimplemented pointer add, direct access only
//!int load_postmodpI___sint_DM(int chess_storage(DM)*& p, int i) { int t = *p; p += i; return t; }
//!int load_postmodmI___sint_DM(int chess_storage(DM)*& p, int i) { int t = *p; p -= i; return t; }

//!int load_premod_p1___sint_DM(int chess_storage(DM)*& p) { return *++p; }
//!int load_premod_m1___sint_DM(int chess_storage(DM)*& p) { return *--p; }
//!int load_premod_pN___sint_DM(int chess_storage(DM)*& p) { p += N; return *p; }
//!int load_premod_mN___sint_DM(int chess_storage(DM)*& p) { p -= N; return *p; }
//!? unimplemented pointer add, direct access only
//!int load_premod_pI___sint_DM(int chess_storage(DM)*& p, int i) { p += i; return *p; }
//!int load_premod_mI___sint_DM(int chess_storage(DM)*& p, int i) { p -= i; return *p; }

void store_indirect0___sint_DM(int a, int chess_storage(DM)* p) { *p = a; }
void store_indexedp1___sint_DM(int a, int chess_storage(DM)* p) { p[ 1] = a; }
void store_indexedm1___sint_DM(int a, int chess_storage(DM)* p) { p[-1] = a; }
void store_indexedpN___sint_DM(int a, int chess_storage(DM)* p) { p[ N] = a; }
void store_indexedmN___sint_DM(int a, int chess_storage(DM)* p) { p[-N] = a; }
//!? unimplemented pointer add, direct access only
//!void store_indexedpI___sint_DM(int a, int chess_storage(DM)* p, int i) { p[ i] = a; }
//!void store_indexedmI___sint_DM(int a, int chess_storage(DM)* p, int i) { p[-i] = a; }

//!void store_postmodp1___sint_DM(int a, int chess_storage(DM)*& p) { *p++ = a; }
//!void store_postmodm1___sint_DM(int a, int chess_storage(DM)*& p) { *p-- = a; }
//!void store_postmodpN___sint_DM(int a, int chess_storage(DM)*& p) { *p = a; p += N; }
//!void store_postmodmN___sint_DM(int a, int chess_storage(DM)*& p) { *p = a; p -= N; }
//!? unimplemented pointer add, direct access only
//!void store_postmodpI___sint_DM(int a, int chess_storage(DM)*& p, int i) { *p = a; p += i; }
//!void store_postmodmI___sint_DM(int a, int chess_storage(DM)*& p, int i) { *p = a; p -= i; }

//!void store_premod_p1___sint_DM(int a, int chess_storage(DM)*& p) { *++p = a; }
//!void store_premod_m1___sint_DM(int a, int chess_storage(DM)*& p) { *--p = a; }
//!void store_premod_pN___sint_DM(int a, int chess_storage(DM)*& p) { p += N; *p = a; }
//!void store_premod_mN___sint_DM(int a, int chess_storage(DM)*& p) { p -= N; *p = a; }
//!? unimplemented pointer add, direct access only
//!void store_premod_pI___sint_DM(int a, int chess_storage(DM)*& p, int i) { p += i; *p = a; }
//!void store_premod_mI___sint_DM(int a, int chess_storage(DM)*& p, int i) { p -= i; *p = a; }

//-- unsigned                   // size=1 alignment=1

void pointer_p1___uint_DM(unsigned chess_storage(DM)*& p) { ++p; }
void pointer_m1___uint_DM(unsigned chess_storage(DM)*& p) { --p; }
void pointer_pN___uint_DM(unsigned chess_storage(DM)*& p) { p += N; }
void pointer_mN___uint_DM(unsigned chess_storage(DM)*& p) { p -= N; }
//!? unimplemented pointer add, direct access only
//!void pointer_pI___uint_DM(unsigned chess_storage(DM)*& p, int i) { p += i; }
//!void pointer_mI___uint_DM(unsigned chess_storage(DM)*& p, int i) { p -= i; }

unsigned chess_storage(DM) global___uint_DM;
unsigned chess_storage(DM) garray___uint_DM[N+1];

unsigned load_global___uint_DM() { return global___uint_DM; }
unsigned load_garray_pN___uint_DM() { return garray___uint_DM[N]; }
//!? unimplemented pointer add, direct access only
//!unsigned load_garray_pI___uint_DM(int i) { return garray___uint_DM[i]; }

void store_global___uint_DM(unsigned a) { global___uint_DM = a; }
void store_garray_pN___uint_DM(unsigned a) { garray___uint_DM[N] = a; }
//!? unimplemented pointer add, direct access only
//!void store_garray_pI___uint_DM(unsigned a, int i) { garray___uint_DM[i] = a; }


unsigned load_indirect0___uint_DM(unsigned chess_storage(DM)* p) { return *p; }
unsigned load_indexedp1___uint_DM(unsigned chess_storage(DM)* p) { return p[ 1]; }
unsigned load_indexedm1___uint_DM(unsigned chess_storage(DM)* p) { return p[-1]; }
unsigned load_indexedpN___uint_DM(unsigned chess_storage(DM)* p) { return p[ N]; }
unsigned load_indexedmN___uint_DM(unsigned chess_storage(DM)* p) { return p[-N]; }
//!? unimplemented pointer add, direct access only
//!unsigned load_indexedpI___uint_DM(unsigned chess_storage(DM)* p, int i) { return p[ i]; }
//!unsigned load_indexedmI___uint_DM(unsigned chess_storage(DM)* p, int i) { return p[-i]; }

//!unsigned load_postmodp1___uint_DM(unsigned chess_storage(DM)*& p) { return *p++; }
//!unsigned load_postmodm1___uint_DM(unsigned chess_storage(DM)*& p) { return *p--; }
//!unsigned load_postmodpN___uint_DM(unsigned chess_storage(DM)*& p) { unsigned t = *p; p += N; return t; }
//!unsigned load_postmodmN___uint_DM(unsigned chess_storage(DM)*& p) { unsigned t = *p; p -= N; return t; }
//!? unimplemented pointer add, direct access only
//!unsigned load_postmodpI___uint_DM(unsigned chess_storage(DM)*& p, int i) { unsigned t = *p; p += i; return t; }
//!unsigned load_postmodmI___uint_DM(unsigned chess_storage(DM)*& p, int i) { unsigned t = *p; p -= i; return t; }

//!unsigned load_premod_p1___uint_DM(unsigned chess_storage(DM)*& p) { return *++p; }
//!unsigned load_premod_m1___uint_DM(unsigned chess_storage(DM)*& p) { return *--p; }
//!unsigned load_premod_pN___uint_DM(unsigned chess_storage(DM)*& p) { p += N; return *p; }
//!unsigned load_premod_mN___uint_DM(unsigned chess_storage(DM)*& p) { p -= N; return *p; }
//!? unimplemented pointer add, direct access only
//!unsigned load_premod_pI___uint_DM(unsigned chess_storage(DM)*& p, int i) { p += i; return *p; }
//!unsigned load_premod_mI___uint_DM(unsigned chess_storage(DM)*& p, int i) { p -= i; return *p; }

void store_indirect0___uint_DM(unsigned a, unsigned chess_storage(DM)* p) { *p = a; }
void store_indexedp1___uint_DM(unsigned a, unsigned chess_storage(DM)* p) { p[ 1] = a; }
void store_indexedm1___uint_DM(unsigned a, unsigned chess_storage(DM)* p) { p[-1] = a; }
void store_indexedpN___uint_DM(unsigned a, unsigned chess_storage(DM)* p) { p[ N] = a; }
void store_indexedmN___uint_DM(unsigned a, unsigned chess_storage(DM)* p) { p[-N] = a; }
//!? unimplemented pointer add, direct access only
//!void store_indexedpI___uint_DM(unsigned a, unsigned chess_storage(DM)* p, int i) { p[ i] = a; }
//!void store_indexedmI___uint_DM(unsigned a, unsigned chess_storage(DM)* p, int i) { p[-i] = a; }

//!void store_postmodp1___uint_DM(unsigned a, unsigned chess_storage(DM)*& p) { *p++ = a; }
//!void store_postmodm1___uint_DM(unsigned a, unsigned chess_storage(DM)*& p) { *p-- = a; }
//!void store_postmodpN___uint_DM(unsigned a, unsigned chess_storage(DM)*& p) { *p = a; p += N; }
//!void store_postmodmN___uint_DM(unsigned a, unsigned chess_storage(DM)*& p) { *p = a; p -= N; }
//!? unimplemented pointer add, direct access only
//!void store_postmodpI___uint_DM(unsigned a, unsigned chess_storage(DM)*& p, int i) { *p = a; p += i; }
//!void store_postmodmI___uint_DM(unsigned a, unsigned chess_storage(DM)*& p, int i) { *p = a; p -= i; }

//!void store_premod_p1___uint_DM(unsigned a, unsigned chess_storage(DM)*& p) { *++p = a; }
//!void store_premod_m1___uint_DM(unsigned a, unsigned chess_storage(DM)*& p) { *--p = a; }
//!void store_premod_pN___uint_DM(unsigned a, unsigned chess_storage(DM)*& p) { p += N; *p = a; }
//!void store_premod_mN___uint_DM(unsigned a, unsigned chess_storage(DM)*& p) { p -= N; *p = a; }
//!? unimplemented pointer add, direct access only
//!void store_premod_pI___uint_DM(unsigned a, unsigned chess_storage(DM)*& p, int i) { p += i; *p = a; }
//!void store_premod_mI___uint_DM(unsigned a, unsigned chess_storage(DM)*& p, int i) { p -= i; *p = a; }

//-- void *                     // size=1 alignment=1

void pointer_p1___Pvoid_DM(void * chess_storage(DM)*& p) { ++p; }
void pointer_m1___Pvoid_DM(void * chess_storage(DM)*& p) { --p; }
void pointer_pN___Pvoid_DM(void * chess_storage(DM)*& p) { p += N; }
void pointer_mN___Pvoid_DM(void * chess_storage(DM)*& p) { p -= N; }
//!? unimplemented pointer add, direct access only
//!void pointer_pI___Pvoid_DM(void * chess_storage(DM)*& p, int i) { p += i; }
//!void pointer_mI___Pvoid_DM(void * chess_storage(DM)*& p, int i) { p -= i; }

void * chess_storage(DM) global___Pvoid_DM;
void * chess_storage(DM) garray___Pvoid_DM[N+1];

void * load_global___Pvoid_DM() { return global___Pvoid_DM; }
void * load_garray_pN___Pvoid_DM() { return garray___Pvoid_DM[N]; }
//!? unimplemented pointer add, direct access only
//!void * load_garray_pI___Pvoid_DM(int i) { return garray___Pvoid_DM[i]; }

void store_global___Pvoid_DM(void * a) { global___Pvoid_DM = a; }
void store_garray_pN___Pvoid_DM(void * a) { garray___Pvoid_DM[N] = a; }
//!? unimplemented pointer add, direct access only
//!void store_garray_pI___Pvoid_DM(void * a, int i) { garray___Pvoid_DM[i] = a; }


void * load_indirect0___Pvoid_DM(void * chess_storage(DM)* p) { return *p; }
void * load_indexedp1___Pvoid_DM(void * chess_storage(DM)* p) { return p[ 1]; }
void * load_indexedm1___Pvoid_DM(void * chess_storage(DM)* p) { return p[-1]; }
void * load_indexedpN___Pvoid_DM(void * chess_storage(DM)* p) { return p[ N]; }
void * load_indexedmN___Pvoid_DM(void * chess_storage(DM)* p) { return p[-N]; }
//!? unimplemented pointer add, direct access only
//!void * load_indexedpI___Pvoid_DM(void * chess_storage(DM)* p, int i) { return p[ i]; }
//!void * load_indexedmI___Pvoid_DM(void * chess_storage(DM)* p, int i) { return p[-i]; }

//!void * load_postmodp1___Pvoid_DM(void * chess_storage(DM)*& p) { return *p++; }
//!void * load_postmodm1___Pvoid_DM(void * chess_storage(DM)*& p) { return *p--; }
//!void * load_postmodpN___Pvoid_DM(void * chess_storage(DM)*& p) { void * t = *p; p += N; return t; }
//!void * load_postmodmN___Pvoid_DM(void * chess_storage(DM)*& p) { void * t = *p; p -= N; return t; }
//!? unimplemented pointer add, direct access only
//!void * load_postmodpI___Pvoid_DM(void * chess_storage(DM)*& p, int i) { void * t = *p; p += i; return t; }
//!void * load_postmodmI___Pvoid_DM(void * chess_storage(DM)*& p, int i) { void * t = *p; p -= i; return t; }

//!void * load_premod_p1___Pvoid_DM(void * chess_storage(DM)*& p) { return *++p; }
//!void * load_premod_m1___Pvoid_DM(void * chess_storage(DM)*& p) { return *--p; }
//!void * load_premod_pN___Pvoid_DM(void * chess_storage(DM)*& p) { p += N; return *p; }
//!void * load_premod_mN___Pvoid_DM(void * chess_storage(DM)*& p) { p -= N; return *p; }
//!? unimplemented pointer add, direct access only
//!void * load_premod_pI___Pvoid_DM(void * chess_storage(DM)*& p, int i) { p += i; return *p; }
//!void * load_premod_mI___Pvoid_DM(void * chess_storage(DM)*& p, int i) { p -= i; return *p; }

void store_indirect0___Pvoid_DM(void * a, void * chess_storage(DM)* p) { *p = a; }
void store_indexedp1___Pvoid_DM(void * a, void * chess_storage(DM)* p) { p[ 1] = a; }
void store_indexedm1___Pvoid_DM(void * a, void * chess_storage(DM)* p) { p[-1] = a; }
void store_indexedpN___Pvoid_DM(void * a, void * chess_storage(DM)* p) { p[ N] = a; }
void store_indexedmN___Pvoid_DM(void * a, void * chess_storage(DM)* p) { p[-N] = a; }
//!? unimplemented pointer add, direct access only
//!void store_indexedpI___Pvoid_DM(void * a, void * chess_storage(DM)* p, int i) { p[ i] = a; }
//!void store_indexedmI___Pvoid_DM(void * a, void * chess_storage(DM)* p, int i) { p[-i] = a; }

//!void store_postmodp1___Pvoid_DM(void * a, void * chess_storage(DM)*& p) { *p++ = a; }
//!void store_postmodm1___Pvoid_DM(void * a, void * chess_storage(DM)*& p) { *p-- = a; }
//!void store_postmodpN___Pvoid_DM(void * a, void * chess_storage(DM)*& p) { *p = a; p += N; }
//!void store_postmodmN___Pvoid_DM(void * a, void * chess_storage(DM)*& p) { *p = a; p -= N; }
//!? unimplemented pointer add, direct access only
//!void store_postmodpI___Pvoid_DM(void * a, void * chess_storage(DM)*& p, int i) { *p = a; p += i; }
//!void store_postmodmI___Pvoid_DM(void * a, void * chess_storage(DM)*& p, int i) { *p = a; p -= i; }

//!void store_premod_p1___Pvoid_DM(void * a, void * chess_storage(DM)*& p) { *++p = a; }
//!void store_premod_m1___Pvoid_DM(void * a, void * chess_storage(DM)*& p) { *--p = a; }
//!void store_premod_pN___Pvoid_DM(void * a, void * chess_storage(DM)*& p) { p += N; *p = a; }
//!void store_premod_mN___Pvoid_DM(void * a, void * chess_storage(DM)*& p) { p -= N; *p = a; }
//!? unimplemented pointer add, direct access only
//!void store_premod_pI___Pvoid_DM(void * a, void * chess_storage(DM)*& p, int i) { p += i; *p = a; }
//!void store_premod_mI___Pvoid_DM(void * a, void * chess_storage(DM)*& p, int i) { p -= i; *p = a; }


} //extern "C"  (150 functions of which 96 skipped)
