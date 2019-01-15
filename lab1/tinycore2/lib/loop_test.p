/*
-- File : loop_test.p
--
-- Contents : Behavioural model of tinycore2 processor's loop test function.
--            
-- Copyright (c) 2014-2017 Synopsys, Inc. This Synopsys processor model 
-- captures an ASIP Designer Design Technique. The model and all associated 
-- documentation are proprietary to Synopsys, Inc. and may only be used 
-- pursuant to the terms and conditions of a written license agreement with 
-- Synopsys, Inc.  All other use, reproduction, modification, or distribution 
-- of the Synopsys processor model or the associated  documentation is 
-- strictly prohibited. 
*/

bool tinycore2::loop_test()
{
    bool loop_jump = 0;
    if ((lc_r = LC) != 1 && (le_r = LE) == pc_r) {
        loop_jump = 1;
        LC = lc_w = lc_r - 1;
    }
    return loop_jump;
}
