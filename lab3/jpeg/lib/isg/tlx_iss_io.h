
// File generated by noodle version N-2018.03#7d02e3ca79#180723, Sun Apr 14 19:29:10 2019
// Copyright 2014-2018 Synopsys, Inc. All rights reserved.
// noodle -Pc -B -Iisg +wisg -I../../io_modules -I/CMC/tools/synopsys/asip_designer_vN-2018.03-SP3/linux64/chessdir/../examples/io_modules -D__tct_patch__=300 -D__chess__ -D__programmers_view__ tlx

#ifdef __chess__
#error "generated native file not intended for compilation by chess"
#endif

// Processor specific IO functions
// used in Checkers ISS C Variable Info (using Dwarf)
//  and in Checkers ISS hosted IO via stdio.h functions

#include <string>
#include "Mdl_[=getdesign_name=]_uicore.h"

int [=getdesign_name=]_read0(Checkers_uicore* uicore, long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_write0(Checkers_uicore* uicore, const long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_read0_pad16(Checkers_uicore* uicore, long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_write0_pad16(Checkers_uicore* uicore, const long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_read0_DMw(Checkers_uicore* uicore, long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_write0_DMw(Checkers_uicore* uicore, const long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_read0_DMh(Checkers_uicore* uicore, long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_write0_DMh(Checkers_uicore* uicore, const long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_read0_pad16_DMw(Checkers_uicore* uicore, long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_write0_pad16_DMw(Checkers_uicore* uicore, const long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_read0_DMw_stat(Checkers_uicore* uicore, long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_write0_DMw_stat(Checkers_uicore* uicore, const long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_read0_DMh_stat(Checkers_uicore* uicore, long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_write0_DMh_stat(Checkers_uicore* uicore, const long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_read0_pad16_DMw_stat(Checkers_uicore* uicore, long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_write0_pad16_DMw_stat(Checkers_uicore* uicore, const long long* val, int n, int /*si*/, AddressType addr);
int [=getdesign_name=]_read1_record0(Checkers_uicore* uicore, long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_write1_record0(Checkers_uicore* uicore, const long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_read1_record1(Checkers_uicore* uicore, long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_write1_record1(Checkers_uicore* uicore, const long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_read1_record2(Checkers_uicore* uicore, long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_write1_record2(Checkers_uicore* uicore, const long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_read1_record3(Checkers_uicore* uicore, long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_write1_record3(Checkers_uicore* uicore, const long long* val, int /*n=1*/, int si, AddressType addr);
int [=getdesign_name=]_readstring0(Checkers_uicore* uicore, std::string& val, int si, int csz, AddressType addr);
int [=getdesign_name=]_writestring0(Checkers_uicore* uicore, std::string val, int si, int csz, AddressType addr, int term_zero);
int [=getdesign_name=]_writestring0(Checkers_uicore* uicore, const char* val, int sz, int si, int csz, AddressType addr, int term_zero);
int [=getdesign_name=]_readstring_DMb(Checkers_uicore* uicore, std::string& val, AddressType addr);
int [=getdesign_name=]_writestring_DMb(Checkers_uicore* uicore, std::string val, AddressType addr, int term_zero);
int [=getdesign_name=]_writestring_DMb(Checkers_uicore* uicore, const char* val, int sz, AddressType addr, int term_zero);
int [=getdesign_name=]_readstring_DMh(Checkers_uicore* uicore, std::string& val, AddressType addr);
int [=getdesign_name=]_writestring_DMh(Checkers_uicore* uicore, std::string val, AddressType addr, int term_zero);
int [=getdesign_name=]_writestring_DMh(Checkers_uicore* uicore, const char* val, int sz, AddressType addr, int term_zero);
int [=getdesign_name=]_readstring_DMw(Checkers_uicore* uicore, std::string& val, AddressType addr);
int [=getdesign_name=]_writestring_DMw(Checkers_uicore* uicore, std::string val, AddressType addr, int term_zero);
int [=getdesign_name=]_writestring_DMw(Checkers_uicore* uicore, const char* val, int sz, AddressType addr, int term_zero);
int [=getdesign_name=]_readstring_DMb_stat(Checkers_uicore* uicore, std::string& val, AddressType addr);
int [=getdesign_name=]_writestring_DMb_stat(Checkers_uicore* uicore, std::string val, AddressType addr, int term_zero);
int [=getdesign_name=]_writestring_DMb_stat(Checkers_uicore* uicore, const char* val, int sz, AddressType addr, int term_zero);
int [=getdesign_name=]_readstring_DMh_stat(Checkers_uicore* uicore, std::string& val, AddressType addr);
int [=getdesign_name=]_writestring_DMh_stat(Checkers_uicore* uicore, std::string val, AddressType addr, int term_zero);
int [=getdesign_name=]_writestring_DMh_stat(Checkers_uicore* uicore, const char* val, int sz, AddressType addr, int term_zero);
int [=getdesign_name=]_readstring_DMw_stat(Checkers_uicore* uicore, std::string& val, AddressType addr);
int [=getdesign_name=]_writestring_DMw_stat(Checkers_uicore* uicore, std::string val, AddressType addr, int term_zero);
int [=getdesign_name=]_writestring_DMw_stat(Checkers_uicore* uicore, const char* val, int sz, AddressType addr, int term_zero);
int [=getdesign_name=]_get_DMb_bool(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb_bool(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb_bool(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb_bool(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___cchar(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb___cchar(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___cchar(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___cchar(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_get_DMb___schar(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb___schar(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___schar(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___schar(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_get_DMb___uchar(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___uchar(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___uchar(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___uchar(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___sshort(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb___sshort(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___sshort(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___sshort(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_get_DMb___ushort(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___ushort(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___ushort(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___ushort(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___sint(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb___sint(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___sint(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___sint(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_get_DMb___uint(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___uint(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___uint(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___uint(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___slong(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb___slong(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___slong(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___slong(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_get_DMb___ulong(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___ulong(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___ulong(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___ulong(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___slonglong(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb___slonglong(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___slonglong(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___slonglong(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_get_DMb___ulonglong(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___ulonglong(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___ulonglong(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___ulonglong(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___ffloat(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb___ffloat(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_gete_DMb___ffloat(Checkers_uicore* uicore, double& val, AddressType& addr);
int [=getdesign_name=]_pute_DMb___ffloat(Checkers_uicore* uicore, double val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___ffloat(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___ffloat(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getealt_DMb___ffloat(Checkers_uicore* uicore, double& val, AddressType& addr);
int [=getdesign_name=]_putealt_DMb___ffloat(Checkers_uicore* uicore, double val, AddressType& addr);
int [=getdesign_name=]_get_DMb___fdouble(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb___fdouble(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_gete_DMb___fdouble(Checkers_uicore* uicore, double& val, AddressType& addr);
int [=getdesign_name=]_pute_DMb___fdouble(Checkers_uicore* uicore, double val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___fdouble(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___fdouble(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getealt_DMb___fdouble(Checkers_uicore* uicore, double& val, AddressType& addr);
int [=getdesign_name=]_putealt_DMb___fdouble(Checkers_uicore* uicore, double val, AddressType& addr);
int [=getdesign_name=]_get_DMb___flongdouble(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb___flongdouble(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_gete_DMb___flongdouble(Checkers_uicore* uicore, double& val, AddressType& addr);
int [=getdesign_name=]_pute_DMb___flongdouble(Checkers_uicore* uicore, double val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___flongdouble(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___flongdouble(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getealt_DMb___flongdouble(Checkers_uicore* uicore, double& val, AddressType& addr);
int [=getdesign_name=]_putealt_DMb___flongdouble(Checkers_uicore* uicore, double val, AddressType& addr);
int [=getdesign_name=]_get_DMb___Pvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___Pvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___Pvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___Pvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___PPMvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___PPMvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___PPMvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___PPMvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___PDMbvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___PDMbvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___PDMbvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___PDMbvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___PDMhvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___PDMhvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___PDMhvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___PDMhvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___PDMwvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___PDMwvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___PDMwvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___PDMwvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___PDMb_statvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___PDMb_statvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___PDMb_statvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___PDMb_statvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___PDMh_statvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___PDMh_statvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___PDMh_statvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___PDMh_statvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb___PDMw_statvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_put_DMb___PDMw_statvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_getalt_DMb___PDMw_statvoid(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_putalt_DMb___PDMw_statvoid(Checkers_uicore* uicore, unsigned long long uval, AddressType& addr);
int [=getdesign_name=]_get_DMb_w08(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb_w08(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb_w08(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb_w08(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_get_DMb_w16(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb_w16(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb_w16(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb_w16(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_get_DMb_w32(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb_w32(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb_w32(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb_w32(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_get_DMb_int16p(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_put_DMb_int16p(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getalt_DMb_int16p(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_putalt_DMb_int16p(Checkers_uicore* uicore, long long val, AddressType& addr);
int [=getdesign_name=]_getstring_DMb(Checkers_uicore* uicore, std::string& val, AddressType& addr);
int [=getdesign_name=]_putstring_DMb(Checkers_uicore* uicore, std::string val, AddressType& addr, int term_zero);
int [=getdesign_name=]_getstringalt_DMb(Checkers_uicore* uicore, std::string& val, AddressType& addr);
int [=getdesign_name=]_putstringalt_DMb(Checkers_uicore* uicore, std::string val, AddressType& addr, int term_zero);
int [=getdesign_name=]_getp_DMb___sshort(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_getpalt_DMb___sshort(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_getp_DMb___ushort(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_getpalt_DMb___ushort(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_getp_DMb___schar(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_getpalt_DMb___schar(Checkers_uicore* uicore, long long& val, AddressType& addr);
int [=getdesign_name=]_getp_DMb___uchar(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_getpalt_DMb___uchar(Checkers_uicore* uicore, unsigned long long& uval, AddressType& addr);
int [=getdesign_name=]_write_main_argc_argv(Checkers_uicore* uicore, long long argc, AddressType argv);
int [=getdesign_name=]_argv_write_string(Checkers_uicore* uicore, std::string val, AddressType& addr);
int [=getdesign_name=]_argv_write_ptr(Checkers_uicore* uicore, unsigned long long val, AddressType& addr);
int [=getdesign_name=]_argv_align_ptr(Checkers_uicore* uicore, AddressType& addr);
