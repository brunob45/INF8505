
// File generated by noodle version N-2018.03#7d02e3ca79#180723, Fri Jan 25 16:14:37 2019
// Copyright 2014-2018 Synopsys, Inc. All rights reserved.
// noodle -Pc -Iisg +wisg -D__tct_patch__=300 -D__chess__ -D__programmers_view__ tinycore2

// File: builtin_operators.c
// Test C built-in operators  (except any left undefined)
// (Reference in-out argument avoids additional moves i.c.o. read-modify-write)

#ifndef N // arbitrary value, adapt at will
#define N 13
#endif

extern "C" {

//-- int

void biopr___sint__pl(int& a, int b) { a += b; }
void biopr___sint__mi(int& a, int b) { a -= b; }
void biopr___sint__ml(int& a, int b) { a *= b; }
//!! biopr___sint__dv(int& a, int b) { a /= b; }
//!! biopr___sint__md(int& a, int b) { a %= b; }
//!! biopr___sint__ad(int& a, int b) { a &= b; }
//!! biopr___sint__or(int& a, int b) { a |= b; }
//!! biopr___sint__er(int& a, int b) { a ^= b; }
//!! biopr___sint__ls(int& a, int b) { a <<= b; }
void biopr___sint__rs(int& a, int b) { a >>= b; }
//!! biopr___sint__co(int& a) { a = ~a; }

void biopr___sint__plN(int& a) { a += N; }
void biopr___sint__miN(int& a) { a -= N; }
void biopr___sint__mlN(int& a) { a *= N; }
//!! biopr___sint__dvN(int& a) { a /= N; }
//!! biopr___sint__mdN(int& a) { a %= N; }
//!! biopr___sint__adN(int& a) { a &= N; }
//!! biopr___sint__orN(int& a) { a |= N; }
//!! biopr___sint__erN(int& a) { a ^= N; }
//!! biopr___sint__lsN(int& a) { a <<= N; }
void biopr___sint__rsN(int& a) { a >>= N; }

void biopr___sint__miR(int& a) { a = N - a; }
//!! biopr___sint__lsR(int& a) { a = N << a; }
void biopr___sint__rsR(int& a) { a = N >> a; }

//!! biopr___sint__lt(int a, int b) { return a < b; }
//!! biopr___sint__gt(int a, int b) { return a > b; }
//!! biopr___sint__le(int a, int b) { return a <= b; }
//!! biopr___sint__ge(int a, int b) { return a >= b; }
//!! biopr___sint__eq(int a, int b) { return a == b; }
//!! biopr___sint__ne(int a, int b) { return a != b; }

//!! biopr___sint__ltN(int a) { return a < N; }
//!! biopr___sint__gtN(int a) { return a > N; }
//!! biopr___sint__leN(int a) { return a <= N; }
//!! biopr___sint__geN(int a) { return a >= N; }
//!! biopr___sint__eqN(int a) { return a == N; }
//!! biopr___sint__neN(int a) { return a != N; }

//-- unsigned

//!! biopr___uint__pl(unsigned& a, unsigned b) { a += b; }
//!! biopr___uint__mi(unsigned& a, unsigned b) { a -= b; }
//!! biopr___uint__ml(unsigned& a, unsigned b) { a *= b; }
//!! biopr___uint__dv(unsigned& a, unsigned b) { a /= b; }
//!! biopr___uint__md(unsigned& a, unsigned b) { a %= b; }
//!! biopr___uint__ad(unsigned& a, unsigned b) { a &= b; }
//!! biopr___uint__or(unsigned& a, unsigned b) { a |= b; }
//!! biopr___uint__er(unsigned& a, unsigned b) { a ^= b; }
//!! biopr___uint__ls(unsigned& a, int b) { a <<= b; }
//!! biopr___uint__rs(unsigned& a, int b) { a >>= b; }
//!! biopr___uint__co(unsigned& a) { a = ~a; }

//!! biopr___uint__plN(unsigned& a) { a += N; }
//!! biopr___uint__miN(unsigned& a) { a -= N; }
//!! biopr___uint__mlN(unsigned& a) { a *= N; }
//!! biopr___uint__dvN(unsigned& a) { a /= N; }
//!! biopr___uint__mdN(unsigned& a) { a %= N; }
//!! biopr___uint__adN(unsigned& a) { a &= N; }
//!! biopr___uint__orN(unsigned& a) { a |= N; }
//!! biopr___uint__erN(unsigned& a) { a ^= N; }
//!! biopr___uint__lsN(unsigned& a) { a <<= N; }
//!! biopr___uint__rsN(unsigned& a) { a >>= N; }

//!! biopr___uint__miR(unsigned& a) { a = N - a; }
//!! biopr___uint__lsR(unsigned& a) { a = N << a; }
//!! biopr___uint__rsR(unsigned& a) { a = N >> a; }

//!! biopr___uint__lt(unsigned a, unsigned b) { return a < b; }
//!! biopr___uint__gt(unsigned a, unsigned b) { return a > b; }
//!! biopr___uint__le(unsigned a, unsigned b) { return a <= b; }
//!! biopr___uint__ge(unsigned a, unsigned b) { return a >= b; }
//!! biopr___uint__eq(unsigned a, unsigned b) { return a == b; }
//!! biopr___uint__ne(unsigned a, unsigned b) { return a != b; }

//!! biopr___uint__ltN(unsigned a) { return a < N; }
//!! biopr___uint__gtN(unsigned a) { return a > N; }
//!! biopr___uint__leN(unsigned a) { return a <= N; }
//!! biopr___uint__geN(unsigned a) { return a >= N; }
//!! biopr___uint__eqN(unsigned a) { return a == N; }
//!! biopr___uint__neN(unsigned a) { return a != N; }


} //extern "C"  (72 functions of which 62 skipped)
