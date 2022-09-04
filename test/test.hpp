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
** File:  test.hpp
**
** Purpose: test framework main header
**
===========================================================*/

#ifndef MATHX_TEST_TEST_HPP
#define MATHX_TEST_TEST_HPP

#include <iostream> // for cout, endl, boolalpha, noboolalpha, operator<<
#include <string>   // for string and operator<<
#include <vector>   // for vector
#include <memory>   // for placement new
#include <ctime>    // for localtime

#include "../../src/common/helper/compiler_pre.hpp"

#include "../../mathx.hpp"
#include "config.hpp"
#include "fw/test_info.hpp"
#include "fw/counter.hpp"
#include "fw/color.hpp"
#include "fw/common.hpp"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
#   define MATHX_USES_WINDOWS_COUNTER
#   define MATHX_HAVE_COUNTER
#
#elif defined(unix) || defined(__unix__) || defined(__unix)
#   include <unistd.h>
#   ifdef _POSIX_VERSION
#      define MATHX_USES_POSIX_COUNTER
#      define MATHX_HAVE_COUNTER
#      include <time.h>
#   endif
#
#endif

#ifndef MATHX_HAVE_COUNTER
#   define MATHX_USES_CLOCK_COUNTER
#   include <ctime>
	using std::clock_t;
#endif

#include "fw/known_counters.hpp"

#if MATHX_TEST_ALLOW_COLORS == MATHX_FALSE
#   define MATHX_NO_COLORS
#
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
#   define MATHX_USES_WINDOWS_COLORS
#
#else
#   define MATHX_USES_ANSI_COLORS
#endif

#include "fw/known_colors.hpp"

#include "fw/stream.hpp"
#include "fw/types.hpp"
#include "fw/manager.hpp"
#include "fw/startup.hpp"

#include "fw/int_ef.hpp"
#include "utility.hpp"
#include "macros.hpp"

#include "../../src/common/helper/compiler_post.hpp"

#endif // MATHX_TEST_TEST_HPP
