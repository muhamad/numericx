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
** File:  mathx_config.hpp
**
** Purpose: configuration header
**
===========================================================*/

#ifndef MATHX_CONFIG_HPP
#define MATHX_CONFIG_HPP

#define MATHX_FALSE   (0) // false value.
#define MATHX_TRUE    (1) // true value.
#define MATHX_AUTO    (2) // auto-detect default value.

// set number of bits in one byte, must be a power of 2.
// default is [CHAR_BIT].
#define MATHX_BIT CHAR_BIT

// set to [MATHX_TRUE] if big endian platform.
// default is [MATHX_FALSE]. use [MATHX_AUTO] to auto-detect.
#define MATHX_BIG_ENDIAN MATHX_FALSE

// set to [MATHX_FALSE] to disable STL features.
// default is [MATHX_TRUE].
#define MATHX_ALLOW_STL MATHX_TRUE

// set to [MATHX_TRUE] if you want to allow conversion from/to library types to/from built-in float-point.
// default is [MATHX_FALSE]. use [MATHX_AUTO] to auto-detect.
#define MATHX_ALLOW_NATIVE_FP_CONVERTION MATHX_AUTO

// set to [MATHX_FALSE] if float-point value shouldn't truncated to be saved into int_t/uint_t.
// default is [MATHX_TRUE].
// when set to [MATHX_FALSE] instead of truncation, the result will be zero.
#define MATHX_ALLOW_NATIVE_FP_TO_INT_TRUNCATION MATHX_TRUE

// set to [MATHX_FALSE] if int_t/uint_t value shouldn't truncated to be saved into float-point.
// default is [MATHX_TRUE].
// when set to [MATHX_FALSE] instead of truncation, the result will be zero.
#define MATHX_ALLOW_INT_TO_NATIVE_FP_TRUNCATION MATHX_TRUE


#endif // MATHX_CONFIG_HPP
