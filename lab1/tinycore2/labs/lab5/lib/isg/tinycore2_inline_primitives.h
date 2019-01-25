
// File generated by pdg version N-2018.03#7d02e3ca79#180723, Fri Jan 25 16:14:40 2019
// Copyright 2014-2018 Synopsys, Inc. All rights reserved.
// pdg -P -Iisg +wisg -D__tct_patch__=300 -D__checkers__ tinycore2

#ifndef TINYCORE2_INLINE_PRIMITIVES_H
#define TINYCORE2_INLINE_PRIMITIVES_H

#ifdef __checkers__
#include "Mdl_tinycore2.h"
#include "checkers_errors.h"
#endif // __checkers__

#include <sstream>

#include <iostream>
#include <cstdlib>
#ifndef PDG_NATIVE_HANDLE_ERR
#define PDG_NATIVE_HANDLE_ERR(msg, loc) \
  std::cerr << "An error occurred: " << msg << " at: " << loc << std::endl; \
  std::cerr << "Exiting.." << std::endl; \
  exit(1);
#endif

#ifndef PDG_NATIVE_HANDLE_WRN
#define PDG_NATIVE_HANDLE_WRN(msg, loc) \
  std::cerr << "Warning: " << msg << " at: " << loc << std::endl;
#endif

namespace tinycore2_primitive {

    const int controller_module_id = 0;

    inline tinycore2_primitive::word add(tinycore2_primitive::word a, tinycore2_primitive::word b) {
        return (a.val + b.val);
    }

    inline tinycore2_primitive::word sub(tinycore2_primitive::word a, tinycore2_primitive::word b) {
        return (a.val - b.val);
    }

    inline tinycore2_primitive::word bor(tinycore2_primitive::word a, tinycore2_primitive::word b) {
        return (a.val | b.val);
    }

    inline tinycore2_primitive::word band(tinycore2_primitive::word a, tinycore2_primitive::word b) {
        return (a.val & b.val);
    }

    inline tinycore2_primitive::word mul(tinycore2_primitive::word a, tinycore2_primitive::word b) {
        return tinycore2_primitive::word((a.val * b.val));
    }

    inline tinycore2_primitive::word srl(tinycore2_primitive::word a, tinycore2_primitive::word b) {
        return (a.val >> VBit<16, false>(b.val));
    }

    inline bool lt(tinycore2_primitive::word a, tinycore2_primitive::word b) {
        return (a.val < b.val);
    }

    inline bool le(tinycore2_primitive::word a, tinycore2_primitive::word b) {
        return (a.val <= b.val);
    }

    inline bool gt(tinycore2_primitive::word a, tinycore2_primitive::word b) {
        return (a.val > b.val);
    }

    inline bool ge(tinycore2_primitive::word a, tinycore2_primitive::word b) {
        return (a.val >= b.val);
    }

    inline tinycore2_primitive::word ldh(tinycore2_primitive::sbyte a) {
        return concat(a.val, VBit<8, true>(0x0));
    }

    inline tinycore2_primitive::word pc_add(tinycore2_primitive::word a, tinycore2_primitive::sbyte b) {
        return (a.val + VBit<16, true>(b.val));
    }

    inline void nop() {
    }

} // namespace tinycore2_primitive
#endif