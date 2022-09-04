// ==++==
//
//    Copyright (C) Muhammad Aladdin
//
//    The use and distribution terms for this software are contained in the file 
//    named LICENSE, which can be found in the root of this distribution.
//
// ==--==
/*============================================================
**
** File:  startup_post.hpp
**
** Purpose: native types used to initiate mathx types
**
===========================================================*/

#ifndef MATHX_COMMON_HELPER_STARTUP_POST_HPP
#define MATHX_COMMON_HELPER_STARTUP_POST_HPP

namespace mathx
{

// default natives to initiate mathx major types.
// you are free to change the following types to affect all mathx types at once,
// or you can initiate any mathx type with certain native types to affect it only.
//
// here we use native types as big as to fit into processor register for maximum performance.
// for 32bit system: (should be)
//     unsigned_half_int = unsigned short int
//       signed_half_int =   signed short int
//     unsigned_full_int = unsigned int
//       signed_full_int =   signed int
//
// for 64bit system:
//     unsigned_half_int = unsigned int
//       signed_half_int =   signed int
//     unsigned_full_int = unsigned long long int
//       signed_full_int =   signed long long int
//

//////////////////////////////////////////////////////////
//                    !! WARNING !!                     //
// CHANGE NEXT TYPES ONLY IF YOU KNOW WHAT YOU'RE DOING //
//         INVALID TYPES WILL BREAK THE LIBRARY         //
//////////////////////////////////////////////////////////

// LONG STORY SHORT:
// 1) mathx_ut, mathx_st, mathx_udt and mathx_sdt must be native integer types with size in power of 2.
// 2) mathx_ut, mathx_udt are unsigned with mathx_ut size as mathx_udt half size.
// 3) mathx_st, mathx_sdt are   signed with mathx_st size as mathx_sdt half size.

// this is half-size unsigned-integer type, default is [meta::sys_info::unsigned_half_int].
typedef meta::sys_info::unsigned_half_int  mathx_ut;
// this is the signed version of unsigned_half_int, default is [meta::sys_info::signed_half_int].
typedef meta::sys_info::signed_half_int    mathx_st;
// this is full-size unsigned-integer type, default is [meta::sys_info::unsigned_full_int].
typedef meta::sys_info::unsigned_full_int  mathx_udt;
// this is the signed version of unsigned_full_int, default is [meta::sys_info::signed_full_int].
typedef meta::sys_info::signed_full_int    mathx_sdt;

}

#endif // MATHX_COMMON_HELPER_STARTUP_POST_HPP
