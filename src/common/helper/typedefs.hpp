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
** File:  typedefs.hpp
**
** Purpose: native types synonyms
**
===========================================================*/

#ifndef MATHX_COMMON_HELPER_TYPEDEFS_HPP
#define MATHX_COMMON_HELPER_TYPEDEFS_HPP

namespace mathx
{
namespace mxi
{

// all size mentioned in type names and comments are hypothetical,
// in real world they don't have to, it's just something we used to.

typedef signed char    int8_t; //   signed 8-bit integer
typedef unsigned char uint8_t; // unsigned 8-bit integer

typedef signed short int    int16_t; //   signed 16-bit integer
typedef unsigned short int uint16_t; // unsigned 16-bit integer

typedef signed int    int32_t; //   signed 32-bit integer
typedef unsigned int uint32_t; // unsigned 32-bit integer

typedef signed long int    long_t; //   signed long integer
typedef unsigned long int ulong_t; // unsigned long integer

typedef signed long long int    int64_t; //   signed 64-bit integer
typedef unsigned long long int uint64_t; // unsigned 64-bit integer

typedef float       float32_t; // float-point type
typedef double      float64_t; // float-point type 
typedef long double floatld_t; // float-point type

typedef char     ascii_t; // ASCII/ANSI character
typedef wchar_t   wide_t; // wide character

typedef ascii_t* astr_t; // ordinary-character string
typedef  wide_t* wstr_t; // wide-character string

typedef void* ptr; // pointer type

}
}

#endif // MATHX_COMMON_HELPER_TYPEDEFS_HPP
