/*
-- File : tlx_pcu.p
--
-- Contents : Definition of the TLX controller in PDG.
--
-- Copyright (c) 2014-2016 Synopsys, Inc. This Synopsys processor model 
-- captures an ASIP Designer Design Technique. The model and all associated 
-- documentation are proprietary to Synopsys, Inc. and may only be used 
-- pursuant to the terms and conditions of a written license agreement with 
-- Synopsys, Inc.  All other use, reproduction, modification, or distribution 
-- of the Synopsys processor model or the associated  documentation is 
-- strictly prohibited. 
*/

#if defined(TLX_HAS_ADAPTERS)
wait_state_nop;
#endif

pcu_storages {
  reg reg_booting<bool>;

  reg reg_stall_trgt<addr>;   // record target address when stall occurs 
  reg reg_stall_trgt_valid<bool>;
}

hw_init reg_booting = 1;

void tlx::user_issue()
{
    bool interruptible = !(ds1 || ds2);

    bool stop_issue = reg_booting;

    pcr = PC;
    if (!hw_stall_sig() && !stop_issue) {
        iword ii =  pm_rd;
        issue_instr(pcr, 1, ii);
        DEBUG_PRINT("II :  %d  %x",pcr,ii);
    }

}

void tlx::user_next_pc()
{
 // next PC computation

    bool fetch = 1;  

    bool loop_jump = 0;
    lcr = LC;
    lsr = LS;
    ler = LE;
    if (pcr==ler && lcr > 1) {
        loop_jump = 1;
        LC = lcw = lcr - 1;
    }

    bool abs_jump = (vd_jr_trgt_EX_sig || vd_jalr_trgt_EX_sig);
    bool r26_jump = (vd_j_of26_ID_sig || vd_jal_of26_ID_sig);
    bool r16_jump = vd_br_cnd_of16_EX_sig && cnd;

    bool del_jump = !hw_stall_sig() && reg_stall_trgt_valid;
    addr next_pc=pcr;
    if (reg_booting)    next_pc = 0;
    else if (abs_jump)       next_pc = trgt;
    else if (r26_jump)       next_pc = pcr + of26;
    else if (r16_jump)       next_pc = pcr + of16;
    else if (del_jump)       next_pc = reg_stall_trgt;
    else if (loop_jump)      next_pc = lsr;
    else if (hw_stall_sig())    next_pc = pcr;
    else                     next_pc = pcr + 1;

    if (hw_stall_sig()) {
        PC = pcw = pcr;
        if (ds2 && (abs_jump || r16_jump))  {
            reg_stall_trgt = next_pc;
            reg_stall_trgt_valid = 1;
        }
    }
    else  
        PC = pcw = next_pc;

    if (reg_booting) reg_booting = 0;
    if (del_jump) reg_stall_trgt_valid = 0;

 // instruction pre fetch  

    addr fetch_pc = hw_stall_sig() ? (addr)pcr : next_pc;
    if (fetch)
        pm_rd`1` = PM[pm_addr = fetch_pc]`1`;
    
    DEBUG_PRINT("NPC : %d : %d,%d,%d,%d, %d : %d/%d", 
           pcr,hw_stall_sig(),abs_jump,r26_jump,r16_jump,ds2,next_pc,fetch_pc);
    DEBUG_PRINT("STALL TRGT :  %d %d",reg_stall_trgt_valid, reg_stall_trgt);
}


