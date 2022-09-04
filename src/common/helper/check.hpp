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
** File:  check.hpp
**
** Purpose: configuration header validation
**
===========================================================*/

#ifndef MATHX_COMMON_HELPER_CHECK_HPP
#define MATHX_COMMON_HELPER_CHECK_HPP

// IMPORTANT MACROS DON'T CHANGE
/***********************************************/
#define   MATHX_16BYTES (  16) //   16 bytes
#define   MATHX_32BYTES (  32) //   32 bytes
#define   MATHX_64BYTES (  64) //   64 bytes
#define  MATHX_128BYTES ( 128) //  128 bytes
#define  MATHX_256BYTES ( 256) //  256 bytes
#define  MATHX_512BYTES ( 512) //  256 bytes

// SIZE RELATIVE TO MATHX_BIT
#define   MATHX_16bT (MATHX_BIT *   MATHX_16BYTES)
#define   MATHX_32bT (MATHX_BIT *   MATHX_32BYTES)
#define   MATHX_64bT (MATHX_BIT *   MATHX_64BYTES)
#define  MATHX_128bT (MATHX_BIT *  MATHX_128BYTES)
#define  MATHX_256bT (MATHX_BIT *  MATHX_256BYTES)
#define  MATHX_512bT (MATHX_BIT *  MATHX_512BYTES)
/***********************************************/

////////////////////////////////
//      BASE MACRO CHECK      //
////////////////////////////////

#if MATHX_FALSE != 0
#   error MATHX_FALSE has chnaged, please set it to (0)
#endif

#if MATHX_TRUE != 1
#   error MATHX_TRUE has chnaged, please set it to (1)
#endif

#if MATHX_AUTO != 2
#   error MATHX_AUTO has chnaged, please set it to (2)
#endif

////////////////////////////////
//        HELPER MACRO        //
////////////////////////////////

// evaluate to 1 if input value is a power of 2.
#define MATHX_IS_PWR2(x) ( !( (x) & ( (x) - (1) ) ) )

// evaluate to 1 if float-point uses base2 as radix
#define MATHX_FP_IS_BASE2 ( MATHX_IS_PWR2(FLT_RADIX) )

// evaluate to 1 if system use 2s complement to represent signed numbers
#define MATHX_IS_TWOS_COMPL ( ~0 == -1 )

// evaluate to 1 if platform is a big endian (used by configuration auto-detection).
// tested and passed using: VISUAL C++, INTEL C++, GCC, CLANG, SUN COMPILER, IBM COMPILER
#define MATHX_IS_BE ( ('12') != (0x3132) )

// check macro value
#define MATHX_CHECK(mn)  ( (mn != MATHX_TRUE) && (mn != MATHX_FALSE) )

// check macro value in addition MATHX_AUTO
#define MATHX_CHECK_AUTO(mn)  ( MATHX_CHECK(mn) && (mn != MATHX_AUTO) )

/////////////////////////////////
//       MATHX_BIT CHECK       //
/////////////////////////////////

#if MATHX_BIT == 0
#  error MATHX_BIT must be non-zero value.
#endif

#if !MATHX_IS_PWR2(MATHX_BIT)
#  error MATHX_BIT must be a power of two.
#endif

///////////////////////////////
//   CHECK PREDEFINED SIZE   //
///////////////////////////////

#if MATHX_16BYTES != 16
#  error MATHX_16BYTES changed, its value should be 16.
#endif

#if MATHX_32BYTES != 32
#  error MATHX_32BYTES changed, its value should be 32.
#endif

#if MATHX_64BYTES != 64
#  error MATHX_64BYTES changed, its value should be 64.
#endif

#if MATHX_128BYTES != 128
#  error MATHX_128BYTES changed, its value should be 128.
#endif

#if MATHX_256BYTES != 256
#  error MATHX_256BYTES changed, its value should be 256.
#endif

#if MATHX_512BYTES != 512
#  error MATHX_512BYTES changed, its value should be 512.
#endif

#if (MATHX_BIT * MATHX_16BYTES) != MATHX_16bT
#  error MATHX_16bT changed, please set it to (MATHX_BIT * MATHX_16BYTES).
#endif

#if (MATHX_BIT * MATHX_32BYTES) != MATHX_32bT
#  error MATHX_32bT changed, please set it to (MATHX_BIT * MATHX_32BYTES).
#endif

#if (MATHX_BIT * MATHX_64BYTES) != MATHX_64bT
#  error MATHX_64bT changed, please set it to (MATHX_BIT * MATHX_64BYTES).
#endif

#if (MATHX_BIT * MATHX_128BYTES) != MATHX_128bT
#  error MATHX_128bT changed, please set it to (MATHX_BIT * MATHX_128BYTES).
#endif

#if (MATHX_BIT * MATHX_256BYTES) != MATHX_256bT
#  error MATHX_256bT changed, please set it to (MATHX_BIT * MATHX_256BYTES).
#endif

#if (MATHX_BIT * MATHX_512BYTES) != MATHX_512bT
#  error MATHX_512bT changed, please set it to (MATHX_BIT * MATHX_512BYTES).
#endif

/////////////////////////////////
//     2s COMPLEMENT CHECK     //
/////////////////////////////////

#if !MATHX_IS_TWOS_COMPL
#   error this system do not use twos complement to represent signed numbers.
#endif

/////////////////////////////////
//       BIG ENDIAN CHECK      //
/////////////////////////////////

#if MATHX_CHECK_AUTO(MATHX_BIG_ENDIAN)
#  error MATHX_BIG_ENDIAN valid values are MATHX_FALSE, MATHX_TRUE and MATHX_AUTO.
#endif

#if MATHX_BIG_ENDIAN == MATHX_AUTO
#  undef MATHX_BIG_ENDIAN
#  if MATHX_IS_BE
#    define MATHX_BIG_ENDIAN MATHX_TRUE
#  else
#    define MATHX_BIG_ENDIAN MATHX_FALSE
#  endif
#endif

/////////////////////////////////
//          STL CHECK          //
/////////////////////////////////

#if MATHX_CHECK(MATHX_ALLOW_STL)
#   error MATHX_ALLOW_STL valid values are MATHX_FALSE and MATHX_TRUE.
#endif

/////////////////////////////////
//      FLOAT POINT CHECK      //
/////////////////////////////////

#if MATHX_CHECK_AUTO(MATHX_ALLOW_NATIVE_FP_CONVERTION)
#   error MATHX_ALLOW_NATIVE_FP_CONVERTION valid values are MATHX_FALSE, MATHX_TRUE and MATHX_AUTO.
#endif

#if MATHX_ALLOW_NATIVE_FP_CONVERTION == MATHX_AUTO
#   undef MATHX_ALLOW_NATIVE_FP_CONVERTION
#
#   if MATHX_FP_IS_BASE2
#      define MATHX_ALLOW_NATIVE_FP_CONVERTION MATHX_TRUE
#   else
#      define MATHX_ALLOW_NATIVE_FP_CONVERTION MATHX_FALSE
#   endif
#endif

#if MATHX_ALLOW_NATIVE_FP_CONVERTION == MATHX_TRUE && MATHX_FP_IS_BASE2 != 1
#   error MATHX_ALLOW_NATIVE_FP_CONVERTION is ON and base2 is not a float-point radix, this will cause float-point conversion to fail, set MATHX_ALLOW_NATIVE_FP_CONVERTION to MATHX_FALSE to continue.
#endif

#if MATHX_FP_IS_BASE2 == 0
#  undef MATHX_ALLOW_NATIVE_FP_TO_INT_TRUNCATION
#  undef MATHX_ALLOW_INT_TO_NATIVE_FP_TRUNCATION
#
#  define MATHX_ALLOW_NATIVE_FP_TO_INT_TRUNCATION MATHX_FALSE
#  define MATHX_ALLOW_INT_TO_NATIVE_FP_TRUNCATION MATHX_FALSE
#else
#  if MATHX_CHECK(MATHX_ALLOW_NATIVE_FP_TO_INT_TRUNCATION)
#     error MATHX_ALLOW_NATIVE_FP_TO_INT_TRUNCATION valid values are MATHX_FALSE and MATHX_TRUE.
#  endif
#
#  if MATHX_CHECK(MATHX_ALLOW_INT_TO_NATIVE_FP_TRUNCATION)
#     error MATHX_ALLOW_INT_TO_NATIVE_FP_TRUNCATION valid values are MATHX_FALSE and MATHX_TRUE.
#  endif
#endif

////////////////////////////////
//          CLEAN UP          //
////////////////////////////////

#undef MATHX_IS_PWR2
#undef MATHX_FP_IS_BASE2
#undef MATHX_IS_TWOS_COMPL
#undef MATHX_IS_BE
#undef MATHX_CHECK
#undef MATHX_CHECK_AUTO

///////////////////////////////
//      INTERNAL USE         //
///////////////////////////////

// MATHX_LO & MATHX_HI provide access to split_t::comp in endian-free manner
#if MATHX_BIG_ENDIAN == MATHX_TRUE
#    define MATHX_LO 1
#    define MATHX_HI 0
#else
#    define MATHX_LO 0
#    define MATHX_HI 1
#endif

#endif // MATHX_COMMON_HELPER_CHECK_HPP
