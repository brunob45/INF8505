/*
-- File : tinycore2.p (lab3)
--
-- Contents : PDG description of tinycore2 processor.
--
-- Copyright (c) 2014-2017 Synopsys, Inc. This Synopsys processor model
-- captures an ASIP Designer Design Technique. The model and all associated
-- documentation are proprietary to Synopsys, Inc. and may only be used
-- pursuant to the terms and conditions of a written license agreement with
-- Synopsys, Inc.  All other use, reproduction, modification, or distribution
-- of the Synopsys processor model or the associated  documentation is
-- strictly prohibited.
*/

word add(word a, word b) { return a + b; }

word sub(word a, word b) { return a - b; }

word band(word a, word b) { return a & b; }

word bor(word a, word b) { return a | b; }
   
bool lt(word a, word b) { return a < b; }

bool le(word a, word b) { return a <= b; }

bool gt(word a, word b) { return a > b; }

bool ge(word a, word b) { return a >= b; }

word ldh(sbyte a) { return a::"00000000"; }

void nop() { }

