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
** File:  startup_pre.hpp
**
** Purpose: native types used inside mathx code
**
===========================================================*/

#ifndef MATHX_COMMON_HELPER_STARTUP_PRE_HPP
#define MATHX_COMMON_HELPER_STARTUP_PRE_HPP

namespace mathx
{

// native types to compile mathx.
// the following types are defined in pairs, in which each group must
// have same size with signedness.

// this types used to store array index, array size and counter (i.e. for loops)
// note: an array may be numeric or character based.
typedef  mxi::int32_t cs_t; //   signed type  (code signed type)
typedef mxi::uint32_t cu_t; // unsigned type  (code unsigned type)

// next types are used with compile-time templates to compute certain values.
// native types used here are the largest native integer types the compiler can work with.
// if your compiler don't support the following integer types then change them
// to your compiler largest native integer and be careful for signedness.

typedef  mxi::int64_t ts_t; //   signed type  (template signed type)
typedef mxi::uint64_t tu_t; // unsigned type  (template unsigned type)

// float-point type used with certain operations.
// with integer types: used during float-point conversion and to convert cs_t/cu_t to float-point
//                     in order to pass them to mathematical functions in standard library.
typedef mxi::float64_t fp_t; // float-point type

}

#endif // MATHX_COMMON_HELPER_STARTUP_PRE_HPP
