
// File generated by noodle version N-2018.03#7d02e3ca79#180723, Fri Jan 25 16:14:37 2019
// Copyright 2014-2018 Synopsys, Inc. All rights reserved.
// noodle -Pc -Iisg +wisg -D__tct_patch__=300 -D__chess__ -D__programmers_view__ tinycore2

#ifdef __chess__
#error "generated native file not intended for compilation by chess"
#endif

// Processor specific IO functions
// used in Checkers ISS C Variable Info (using Dwarf)
//  and in Checkers ISS hosted IO via stdio.h functions
// (As the same functions can be used for signed and unsigned application types,
//  all values are read sign-extended, and formatted later.)

#include "Mdl_[=getdesign_name=]_iss_io.h"
#include "checkers_api_l_funcs.h"
#include "checkers_api.h"
#include "checkers_hosted_clib.h"


inline void chess_report_cycle_count(Checkers_uicore* uicore, std::ostream& os) {
    long long cycle_count;
    chkapi_l_program_query_user_cyclecount(uicore, cycle_count);
    os << "(cycle=" << std::dec << cycle_count << ')';
}

//  Chess_report ancillary functions (common to ISS and native)

inline void chess_report_hex(int bits, long long val, std::ostream& os)
    { os << " 0x" << std::hex << std::setfill('0') << std::setw((bits+3)/4) << CHESS_MASKLL(val,bits); }
inline void chess_report_signed  (long long  val, std::ostream& os)
    { os << ' ' << std::dec << val; }
inline void chess_report_unsigned(unsigned long long val, std::ostream& os)
    { os << ' ' << std::dec << val; }

//------ chess/checkers compatibility ------

#ifdef checkers_[=getdesign_name=]_PM_si
# define chess_[=getdesign_name=]_PM_si checkers_[=getdesign_name=]_PM_si
#else
# define chess_[=getdesign_name=]_PM_si (-1)
#endif
#ifdef checkers_[=getdesign_name=]_DM_si
# define chess_[=getdesign_name=]_DM_si checkers_[=getdesign_name=]_DM_si
#else
# define chess_[=getdesign_name=]_DM_si (-1)
#endif
#ifdef checkers_[=getdesign_name=]_R_si
# define chess_[=getdesign_name=]_R_si checkers_[=getdesign_name=]_R_si
#else
# define chess_[=getdesign_name=]_R_si (-1)
#endif
#ifdef checkers_[=getdesign_name=]_LR_si
# define chess_[=getdesign_name=]_LR_si checkers_[=getdesign_name=]_LR_si
#else
# define chess_[=getdesign_name=]_LR_si (-1)
#endif
#ifdef checkers_[=getdesign_name=]_SREG_si
# define chess_[=getdesign_name=]_SREG_si checkers_[=getdesign_name=]_SREG_si
#else
# define chess_[=getdesign_name=]_SREG_si (-1)
#endif
#ifdef checkers_[=getdesign_name=]_PC_si
# define chess_[=getdesign_name=]_PC_si checkers_[=getdesign_name=]_PC_si
#else
# define chess_[=getdesign_name=]_PC_si (-1)
#endif

//--- direct read/write ---

int [=getdesign_name=]_read0(Checkers_uicore* uicore, long long* val, int /*n=1*/, int si, AddressType addr)
{
    Checkers_stor_addr sta(si, addr, 1, at_addr);
    Checkers_storage* sti = uicore->core()->storinfo(si);
    if (!sti)
        return chkapi_errorsp->put(chkapi_ERR, "Illegal storage index ", "[=getdesign_name=]_read0");
    DataType vval = sti->vbit(0);
    int rt = chkapi_l_storage_get_vbit(uicore, sta, vval);
    val[0] = vval.to_signedVBitWrapper().to_longlong();
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read value", "[=getdesign_name=]_read0");
    return chkapi_OK;
}

int [=getdesign_name=]_write0(Checkers_uicore* uicore, const long long* val, int /*n=1*/, int si, AddressType addr)
{
    /*const*/ long long* tval = (long long*)val;
    Checkers_stor_addr sta(si, addr, 1, at_addr);
    Checkers_storage* sti = uicore->core()->storinfo(si);
    if (!sti)
        return chkapi_errorsp->put(chkapi_ERR, "Illegal storage index ", "[=getdesign_name=]_write0");
    DataType vval = sti->vbit((int)tval[0]);
    int rt = chkapi_l_storage_put_vbit(uicore, sta, vval);
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not write value", "[=getdesign_name=]_write0");
    return chkapi_OK;
}

//--- read/write for chess_convert or keep_in_registers representation ---

int [=getdesign_name=]_read1_record0(Checkers_uicore* uicore, long long* val, int /*n=1*/, int si, AddressType addr)
{
    val[0] = 0;
    long long fval[1] = {0};
    int rt;
    // component 0 : 1 bits at 0
    rt = [=getdesign_name=]_read0(uicore, fval,1, si, addr + 0);
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read component 0 of record value", "[=getdesign_name=]_read1_record0");
    val[0] |= CHESS_MASKLL(fval[0], 1) << 0;
    // complete
    val[0] = CHESS_EXTENDLL(val[0],1);
    return chkapi_OK;
}

int [=getdesign_name=]_write1_record0(Checkers_uicore* uicore, const long long* val, int /*n=1*/, int si, AddressType addr)
{
    /*const*/ long long* tval = (long long*)val;
    long long fval[1] = {0};
    int rt;
    // component 0 : 1 bits at 0
    fval[0] = CHESS_EXTENDLL(tval[0] >> 0, 1);
    rt = [=getdesign_name=]_write0(uicore, fval,1, si, addr + 0);
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not write component 0 of record value", "[=getdesign_name=]_write1_record0");
    // complete
    return chkapi_OK;
}


//------- Stack va_list -------

// ! no suitable stack memory for type `bool'

// ! no suitable stack memory for type `bool'

// ! no suitable stack memory for type `char'

// ! no suitable stack memory for type `char'

// ! no suitable stack memory for type `signed char'

// ! no suitable stack memory for type `signed char'

// ! no suitable stack memory for type `unsigned char'

// ! no suitable stack memory for type `unsigned char'

// ! no suitable stack memory for type `short'

// ! no suitable stack memory for type `short'

// ! no suitable stack memory for type `unsigned short'

// ! no suitable stack memory for type `unsigned short'

// ! no suitable stack memory for type `int'

// ! no suitable stack memory for type `int'

// ! no suitable stack memory for type `unsigned'

// ! no suitable stack memory for type `unsigned'

// ! no suitable stack memory for type `long'

// ! no suitable stack memory for type `long'

// ! no suitable stack memory for type `unsigned long'

// ! no suitable stack memory for type `unsigned long'

// ! no suitable stack memory for type `long long'

// ! no suitable stack memory for type `long long'

// ! no suitable stack memory for type `unsigned long long'

// ! no suitable stack memory for type `unsigned long long'

// ! no suitable stack memory for type `float'

// ! no suitable stack memory for type `float'

// ! no suitable stack memory for type `double'

// ! no suitable stack memory for type `double'

// ! no suitable stack memory for type `long double'

// ! no suitable stack memory for type `long double'

// ! no suitable stack memory for type `void *'

// ! no suitable stack memory for type `void *'

// ! no suitable stack memory for type `void chess_storage(PM) *'

// ! no suitable stack memory for type `void chess_storage(PM) *'

// ! no suitable stack memory for type `void chess_storage(DM) *'

// ! no suitable stack memory for type `void chess_storage(DM) *'

// ! no suitable stack memory for type `word'

// ! no suitable stack memory for type `word'

// ! no suitable stack memory for type `pmtype'

// ! no suitable stack memory for type `pmtype'

// ! no suitable stack memory for type `sbyte'

// ! no suitable stack memory for type `sbyte'

// ! no suitable stack memory for type `ubyte'

// ! no suitable stack memory for type `ubyte'

// ! no suitable stack memory for type `threebitsu'

// ! no suitable stack memory for type `threebitsu'

// ! no suitable stack memory for char string

// ! no suitable stack memory for char string

// ! no definition for type `short'

// ! no definition for type `short'

// ! no definition for type `unsigned short'

// ! no definition for type `unsigned short'

// ! no definition for type `signed char'

// ! no definition for type `signed char'

// ! no definition for type `unsigned char'

// ! no definition for type `unsigned char'


//------- Access to C Types: built-in, primitive and application -------

struct Ctp_access_fn {
    int strg_idx;
    const char* type_nm;
    checkers_read_signed_ptr read_fn;
    checkers_write_signed_ptr write_fn;
};

static Ctp_access_fn acfns[] = {
#ifdef checkers_[=getdesign_name=]_PM_si
    { checkers_[=getdesign_name=]_PM_si, "pmtype", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
#endif //checkers_[=getdesign_name=]_PM_si
#ifdef checkers_[=getdesign_name=]_DM_si
    { checkers_[=getdesign_name=]_DM_si, "bool", [=getdesign_name=]_read1_record0, [=getdesign_name=]_write1_record0 },
    { checkers_[=getdesign_name=]_DM_si, "__sint", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_DM_si, "__uint", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_DM_si, "__Pvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_DM_si, "__PPMvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_DM_si, "__PDMvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_DM_si, "word", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
#endif //checkers_[=getdesign_name=]_DM_si
#ifdef checkers_[=getdesign_name=]_R_si
    { checkers_[=getdesign_name=]_R_si, "bool", [=getdesign_name=]_read1_record0, [=getdesign_name=]_write1_record0 },
    { checkers_[=getdesign_name=]_R_si, "__sint", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_R_si, "__uint", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_R_si, "__Pvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_R_si, "__PPMvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_R_si, "__PDMvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_R_si, "word", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
#endif //checkers_[=getdesign_name=]_R_si
#ifdef checkers_[=getdesign_name=]_LR_si
    { checkers_[=getdesign_name=]_LR_si, "bool", [=getdesign_name=]_read1_record0, [=getdesign_name=]_write1_record0 },
    { checkers_[=getdesign_name=]_LR_si, "__sint", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_LR_si, "__uint", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_LR_si, "__Pvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_LR_si, "__PPMvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_LR_si, "__PDMvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_LR_si, "word", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
#endif //checkers_[=getdesign_name=]_LR_si
#ifdef checkers_[=getdesign_name=]_SREG_si
    { checkers_[=getdesign_name=]_SREG_si, "bool", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
#endif //checkers_[=getdesign_name=]_SREG_si
#ifdef checkers_[=getdesign_name=]_PC_si
    { checkers_[=getdesign_name=]_PC_si, "bool", [=getdesign_name=]_read1_record0, [=getdesign_name=]_write1_record0 },
    { checkers_[=getdesign_name=]_PC_si, "__sint", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_PC_si, "__uint", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_PC_si, "__Pvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_PC_si, "__PPMvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_PC_si, "__PDMvoid", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
    { checkers_[=getdesign_name=]_PC_si, "word", [=getdesign_name=]_read0, [=getdesign_name=]_write0 },
#endif //checkers_[=getdesign_name=]_PC_si
    { -1, 0, 0, 0 } /* sentinel */
};


//------- Type-specific chess_assert functions -------

int [=getdesign_name=]_chess_assert_bool(Checkers_uicore* uicore, int& oval)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read1_record0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_assert value", "[=getdesign_name=]_chess_assert_bool");
    val[0] |= CHESS_MASKLL(fval[0], 1) << 0;
    oval = val[0] != 0 ? 1 : 0;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_assert___sint(Checkers_uicore* uicore, int& oval)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_assert value", "[=getdesign_name=]_chess_assert___sint");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    val[0] = CHESS_EXTENDLL(val[0],16);
    oval = val[0] != 0 ? 1 : 0;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_assert___uint(Checkers_uicore* uicore, int& oval)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_assert value", "[=getdesign_name=]_chess_assert___uint");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    oval = val[0] != 0 ? 1 : 0;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_assert___Pvoid(Checkers_uicore* uicore, int& oval)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_assert value", "[=getdesign_name=]_chess_assert___Pvoid");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    oval = val[0] != 0 ? 1 : 0;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_assert___PPMvoid(Checkers_uicore* uicore, int& oval)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_assert value", "[=getdesign_name=]_chess_assert___PPMvoid");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    oval = val[0] != 0 ? 1 : 0;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_assert___PDMvoid(Checkers_uicore* uicore, int& oval)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_assert value", "[=getdesign_name=]_chess_assert___PDMvoid");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    oval = val[0] != 0 ? 1 : 0;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_assert_word(Checkers_uicore* uicore, int& oval)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_assert value", "[=getdesign_name=]_chess_assert_word");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    val[0] = CHESS_EXTENDLL(val[0],16);
    oval = val[0] != 0 ? 1 : 0;
    return chkapi_OK;
}

struct Chess_assert_fn {
    const char* type_nm;
    checkers_chess_assert_ptr assert_fn;
};

static Chess_assert_fn cafns[] = {
    { "bool", [=getdesign_name=]_chess_assert_bool },
    { "__sint", [=getdesign_name=]_chess_assert___sint },
    { "__uint", [=getdesign_name=]_chess_assert___uint },
    { "__Pvoid", [=getdesign_name=]_chess_assert___Pvoid },
    { "__PPMvoid", [=getdesign_name=]_chess_assert___PPMvoid },
    { "__PDMvoid", [=getdesign_name=]_chess_assert___PDMvoid },
    { "word", [=getdesign_name=]_chess_assert_word },
    { 0, 0 } /* sentinel */
};


//------- Type-specific chess_report functions -------

int [=getdesign_name=]_chess_report_bool(Checkers_uicore* uicore, std::ostream& os)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read1_record0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_report value", "[=getdesign_name=]_chess_report_bool");
    val[0] |= CHESS_MASKLL(fval[0], 1) << 0;
    os << "chess_report(bool):";
    chess_report_hex(1, val[0], os);
    os << " //";
    chess_report_cycle_count(uicore, os);
    chess_report_unsigned(val[0], os);
    os << std::endl;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_report___sint(Checkers_uicore* uicore, std::ostream& os)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_report value", "[=getdesign_name=]_chess_report___sint");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    val[0] = CHESS_EXTENDLL(val[0],16);
    os << "chess_report(int):";
    chess_report_hex(16, val[0], os);
    os << " //";
    chess_report_cycle_count(uicore, os);
    chess_report_signed(val[0], os);
    os << std::endl;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_report___uint(Checkers_uicore* uicore, std::ostream& os)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_report value", "[=getdesign_name=]_chess_report___uint");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    os << "chess_report(unsigned):";
    chess_report_hex(16, val[0], os);
    os << " //";
    chess_report_cycle_count(uicore, os);
    chess_report_unsigned(val[0], os);
    os << std::endl;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_report___Pvoid(Checkers_uicore* uicore, std::ostream& os)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_report value", "[=getdesign_name=]_chess_report___Pvoid");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    os << "chess_report(void*):";
    chess_report_hex(16, (unsigned long long)val[0], os);
    os << " //";
    chess_report_cycle_count(uicore, os);
    chess_report_unsigned((unsigned long long)val[0], os);
    os << std::endl;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_report___PPMvoid(Checkers_uicore* uicore, std::ostream& os)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_report value", "[=getdesign_name=]_chess_report___PPMvoid");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    os << "chess_report(void*):";
    chess_report_hex(16, (unsigned long long)val[0], os);
    os << " //";
    chess_report_cycle_count(uicore, os);
    chess_report_unsigned((unsigned long long)val[0], os);
    os << std::endl;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_report___PDMvoid(Checkers_uicore* uicore, std::ostream& os)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_report value", "[=getdesign_name=]_chess_report___PDMvoid");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    os << "chess_report(void*):";
    chess_report_hex(16, (unsigned long long)val[0], os);
    os << " //";
    chess_report_cycle_count(uicore, os);
    chess_report_unsigned((unsigned long long)val[0], os);
    os << std::endl;
    return chkapi_OK;
}

int [=getdesign_name=]_chess_report_word(Checkers_uicore* uicore, std::ostream& os)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_report value", "[=getdesign_name=]_chess_report_word");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    val[0] = CHESS_EXTENDLL(val[0],16);
    os << "chess_report(tinycore2_primitive::word):";
    chess_report_hex(16, val[0], os);
    os << " //";
    chess_report_cycle_count(uicore, os);
    chess_report_signed(val[0], os);
    os << std::endl;
    return chkapi_OK;
}

struct Chess_report_fn {
    const char* type_nm;
    checkers_chess_report_ptr report_fn;
};

static Chess_report_fn crfns[] = {
    { "bool", [=getdesign_name=]_chess_report_bool },
    { "__sint", [=getdesign_name=]_chess_report___sint },
    { "__uint", [=getdesign_name=]_chess_report___uint },
    { "__Pvoid", [=getdesign_name=]_chess_report___Pvoid },
    { "__PPMvoid", [=getdesign_name=]_chess_report___PPMvoid },
    { "__PDMvoid", [=getdesign_name=]_chess_report___PDMvoid },
    { "word", [=getdesign_name=]_chess_report_word },
    { 0, 0 } /* sentinel */
};


//------- Type-specific chess_return_value functions -------

int [=getdesign_name=]_chess_return_value___sint(Checkers_uicore* uicore, DataType& ovbit)
{
    DataType vbit(16, 1, 0);
    int rt = chkapi_OK;
    rt = chkapi_l_storage_get_vbit(uicore, Checkers_stor_addr(chess_[=getdesign_name=]_R_si, AddressType(01), at_addr), vbit);
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_return_value value", "[=getdesign_name=]_chess_return_value___sint");
    ovbit.cloneFrom(vbit);
    return chkapi_OK;
}

int [=getdesign_name=]_chess_return_value___uint(Checkers_uicore* uicore, DataType& ovbit)
{
    DataType vbit(16, 0, 0);
    int rt = chkapi_OK;
    rt = chkapi_l_storage_get_vbit(uicore, Checkers_stor_addr(chess_[=getdesign_name=]_R_si, AddressType(01), at_addr), vbit);
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_return_value value", "[=getdesign_name=]_chess_return_value___uint");
    ovbit.cloneFrom(vbit);
    return chkapi_OK;
}

int [=getdesign_name=]_chess_return_value___Pvoid(Checkers_uicore* uicore, DataType& ovbit)
{
    DataType vbit(16, 0, 0);
    int rt = chkapi_OK;
    rt = chkapi_l_storage_get_vbit(uicore, Checkers_stor_addr(chess_[=getdesign_name=]_R_si, AddressType(01), at_addr), vbit);
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_return_value value", "[=getdesign_name=]_chess_return_value___Pvoid");
    ovbit.cloneFrom(vbit);
    return chkapi_OK;
}

int [=getdesign_name=]_chess_return_value___PPMvoid(Checkers_uicore* uicore, DataType& ovbit)
{
    DataType vbit(16, 0, 0);
    int rt = chkapi_OK;
    rt = chkapi_l_storage_get_vbit(uicore, Checkers_stor_addr(chess_[=getdesign_name=]_R_si, AddressType(01), at_addr), vbit);
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_return_value value", "[=getdesign_name=]_chess_return_value___PPMvoid");
    ovbit.cloneFrom(vbit);
    return chkapi_OK;
}

int [=getdesign_name=]_chess_return_value___PDMvoid(Checkers_uicore* uicore, DataType& ovbit)
{
    DataType vbit(16, 0, 0);
    int rt = chkapi_OK;
    rt = chkapi_l_storage_get_vbit(uicore, Checkers_stor_addr(chess_[=getdesign_name=]_R_si, AddressType(01), at_addr), vbit);
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_return_value value", "[=getdesign_name=]_chess_return_value___PDMvoid");
    ovbit.cloneFrom(vbit);
    return chkapi_OK;
}

int [=getdesign_name=]_chess_return_value_word(Checkers_uicore* uicore, DataType& ovbit)
{
    DataType vbit(16, 1, 0);
    int rt = chkapi_OK;
    rt = chkapi_l_storage_get_vbit(uicore, Checkers_stor_addr(chess_[=getdesign_name=]_R_si, AddressType(01), at_addr), vbit);
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_return_value value", "[=getdesign_name=]_chess_return_value_word");
    ovbit.cloneFrom(vbit);
    return chkapi_OK;
}

struct Chess_return_value_fn {
    const char* type_nm;
    checkers_chess_return_value_ptr return_value_fn;
};

static Chess_return_value_fn cvfns[] = {
    { "__sint", [=getdesign_name=]_chess_return_value___sint },
    { "__uint", [=getdesign_name=]_chess_return_value___uint },
    { "__Pvoid", [=getdesign_name=]_chess_return_value___Pvoid },
    { "__PPMvoid", [=getdesign_name=]_chess_return_value___PPMvoid },
    { "__PDMvoid", [=getdesign_name=]_chess_return_value___PDMvoid },
    { "word", [=getdesign_name=]_chess_return_value_word },
    { 0, 0 } /* sentinel */
};


//------- chess_cycle_count function -------

// return type on [=getdesign_name=] : unsigned (largest suitable)
int [=getdesign_name=]_chess_cycle_count(Checkers_uicore* uicore, long long val)
{
    long long fval = 0;
    int rt;
    fval = CHESS_MASKLL(val >> 0,16);
    rt = [=getdesign_name=]_write0(uicore, &fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not write chess_cycle_count value", "[=getdesign_name=]_chess_cycle_count");
    return chkapi_OK;
}


//------- chess_exit function -------

int [=getdesign_name=]_chess_exit___sint(Checkers_uicore* uicore, int& oval)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_exit value", "[=getdesign_name=]_chess_exit___sint");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    val[0] = CHESS_EXTENDLL(val[0],16);
    oval = val[0];
    return chkapi_OK;
}


//------- chess_hosted_io function -------

int [=getdesign_name=]_chess_hosted_io___Pvoid(Checkers_uicore* uicore, AddressType& oval)
{
    long long val[1] = {0};
    int rt;
    long long fval[1] = {0};
    rt = [=getdesign_name=]_read0(uicore, fval,1, chess_[=getdesign_name=]_R_si, AddressType(0));
    if (rt != chkapi_OK)
        return chkapi_errorsp->put(rt, "Could not read chess_hosted_io value", "[=getdesign_name=]_chess_hosted_io___Pvoid");
    val[0] |= CHESS_MASKLL(fval[0], 16) << 0;
    oval = val[0];
    return chkapi_OK;
}


//------- Passing argc/argv arguments to main -------


// ! cannot find suitable stack for char (or string)

int [=getdesign_name=]_uicore::hosted_clib_init()
{
    // no hosted IO via stdio.h

    // Initialise storage/type-specific read/write functions map
    for (Ctp_access_fn* p = acfns; p->type_nm; p++) {
        read_signed_map [p->strg_idx][p->type_nm] = p->read_fn;
        write_signed_map[p->strg_idx][p->type_nm] = p->write_fn;
    }
    // Initialise type-specific chess_assert/chess_report functions map
    for (Chess_assert_fn* p = cafns; p->type_nm; p++) {
        chess_assert_map[p->type_nm] = p->assert_fn;
    }
    for (Chess_report_fn* p = crfns; p->type_nm; p++) {
        chess_report_map[p->type_nm] = p->report_fn;
    }
    for (Chess_return_value_fn* p = cvfns; p->type_nm; p++) {
        chess_return_value_map[p->type_nm] = p->return_value_fn;
    }
    chess_cycle_count_ptr = [=getdesign_name=]_chess_cycle_count;
    chess_exit_code_ptr = [=getdesign_name=]_chess_exit___sint;
    chess_hosted_io_ptr = [=getdesign_name=]_chess_hosted_io___Pvoid;
    // Initialise built-in type unparse map
    unparse_map["bool"] = "bool";
    unparse_map["__cchar"] = "char";
    unparse_map["__schar"] = "signed char";
    unparse_map["__uchar"] = "unsigned char";
    unparse_map["__sshort"] = "short";
    unparse_map["__ushort"] = "unsigned short";
    unparse_map["__sint"] = "int";
    unparse_map["__uint"] = "unsigned";
    unparse_map["__slong"] = "long";
    unparse_map["__ulong"] = "unsigned long";
    unparse_map["__slonglong"] = "long long";
    unparse_map["__ulonglong"] = "unsigned long long";
    unparse_map["__ffloat"] = "float";
    unparse_map["__fdouble"] = "double";
    unparse_map["__flongdouble"] = "long double";
    unparse_map["__Pvoid"] = "void *";
    unparse_map["__PPMvoid"] = "void chess_storage(PM) *";
    unparse_map["__PDMvoid"] = "void chess_storage(DM) *";
    return chkapi_OK;
}
