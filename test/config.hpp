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
** File:  config.hpp
**
** Purpose: test configuration
**
===========================================================*/

#ifndef MATHX_TEST_CONFIG_HPP
#define MATHX_TEST_CONFIG_HPP

// show mathx configuration summary
// default is [MATHX_TRUE], use [MATHX_FALSE] to turn off.
#define MATHX_TEST_SUMMARY  MATHX_TRUE


// allow test to show detailed information
// default is [MATHX_TRUE], use [MATHX_FALSE] to turn off.
#define MATHX_TEST_VERBOSE  MATHX_TRUE


// show time before/after unit execution
// default is [MATHX_TRUE], use [MATHX_FALSE] to turn off.
#define MATHX_TEST_SHOW_TIME_STAMP  MATHX_TRUE


// when writing duration to stream show all parts even those with zero value.
// default is [MATHX_FALSE], use [MATHX_TRUE] to turn on.
#define MATHX_TEST_SHOW_ALL_DURATION_PARTS  MATHX_FALSE


// show colors in console
// default is [MATHX_TRUE], use [MATHX_FALSE] to turn off.
#define MATHX_TEST_ALLOW_COLORS  MATHX_TRUE


// number of bits in int_t/uint_t used during test
// default is [MATHX_128bT]
// there is 6 sizes used to initialize mathx types, middle size selected.
// SIZE MUST BE ONE OF [MATHX_*bT] DEFINED IN "src/common/helper/check.hpp" OTHERWISE COMPILE WILL FAIL.
#define MATHX_TEST_INT_UINT_BITS  MATHX_128bT


// stop unit test execution at first case error
// default is [MATHX_FALSE], use [MATHX_TRUE] to turn on.
#define MATHX_TEST_STOP_AT_FIRST_CASE_ERROR  MATHX_FALSE


// stop all unit tests executions at first case error
// default is [MATHX_FALSE], use [MATHX_TRUE] to turn on.
// used only when running all unit tests.
#define MATHX_TEST_STOP_ALL_AT_FIRST_CASE_ERROR  MATHX_FALSE


// execute all benchmark tests only if all unit tests executed without problem
// default is [MATHX_TRUE], use [MATHX_FALSE] to turn off.
// used only when running all unit and benchmark tests.
#define MATHX_TEST_BENCHMARK_IF_ALL_UNITS_OK  MATHX_TRUE


#endif // MATHX_TEST_CONFIG_HPP
