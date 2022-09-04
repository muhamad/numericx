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
** File:  compiler_post.hpp
**
** Purpose: compiler configuration to be used after library
**
===========================================================*/

// NEVER PUT HEADER GUARD IN THIS FILE BECAUSE IT WILL BE USED SEVERAL TIMES.

#if defined(__INTEL_COMPILER) || defined(_MSC_VER)
#   pragma warning( pop )
#elif defined(__GNUG__)
#   pragma GCC diagnostic pop
#elif defined(__clang__)
#   pragma clang diagnostic pop
#endif
