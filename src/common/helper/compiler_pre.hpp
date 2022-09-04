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
** File:  compiler_pre.hpp
**
** Purpose: compiler configuration to be used before library
**
===========================================================*/

// NEVER PUT HEADER GUARD IN THIS FILE BECAUSE IT WILL BE USED SEVERAL TIMES.

#if defined(__INTEL_COMPILER)
#   pragma warning( push )
#   pragma warning( disable : 337 ) // invalid union member has disallowed member function
#   pragma warning( disable : 111 ) // invalid union member has disallowed member function
#
#elif defined(_MSC_VER)
#   pragma warning( push )
#   pragma warning( disable : 4127 ) // conditional expression is constant
#   pragma warning( disable : 4355 ) // 'this' used in base member initializer list
#   pragma warning( disable : 4512 ) // assignment operator could not be generated
#   pragma warning( disable : 4706 ) // assignment within conditional expression
#   pragma warning( disable : 6326 ) // potential comparison of a constant with another constant
#
#elif defined(__GNUG__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wmultichar"
#
#elif defined(__clang__)
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wmultichar"
#endif
