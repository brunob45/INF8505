/*
-- File : tinycore2_pcu.p (lab4)
--
-- Contents : Behavioural model of tinycore2 processor's program control unit.
--
-- Copyright (c) 2014-2017 Synopsys, Inc. This Synopsys processor model 
-- captures an ASIP Designer Design Technique. The model and all associated 
-- documentation are proprietary to Synopsys, Inc. and may only be used 
-- pursuant to the terms and conditions of a written license agreement with 
-- Synopsys, Inc.  All other use, reproduction, modification, or distribution 
-- of the Synopsys processor model or the associated  documentation is 
-- strictly prohibited. 
*/

pcu_storages {
    reg reg_booting<uint2_t>;  // prohibit fetch and issue during reset
}

hw_init reg_booting = 2;

void tinycore2::user_issue()
{
 // Get instruction on PM output bus (from PM fetch issued previous cycle)
    pmtype f_instr = pmLdBus;

 // Issue instruction
    if (reg_booting == 0)
        issue_instr(pc_r = PC,1,f_instr);      // new instruction

 // Exit from booting state  
    reg_booting = reg_booting >> 1;
}

void tinycore2::user_next_pc()
{
 // Read old PC 
    pc_r = PC;

 // Set link address
    lnk_pf = pc_r + 1;                  

 // Calculate next PC
    word nextpc=0;
    bool fetch = 1;
    if (reg_booting == 2)
       fetch = 0;
    else if (reg_booting == 1)
       fetch = 1;
    else if (jump_pc_offs_sig)    // relative jump
        nextpc = pc_r + pc_offs;
    else if (jump_pc_trgt_sig)    // absolute jump (call/return)
        nextpc = pc_trgt;
    else                          // increment PC
        nextpc = pc_r + 1;
    PC = pc_w = nextpc;

 // Issue PM fetch
    if (fetch) 
        pmLdBus `1` = PM[pmAddr `0` = nextpc] `1`;
}
