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
** File:  test_info.hpp
**
** Purpose: test information
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_TEST_INFO_HPP
#define MATHX_FRAMEWORK_TEST_INFO_HPP

namespace mathx
{
namespace test
{

struct test_info
{
private:
	static const bool is_valid_int_bits = (MATHX_TEST_INT_UINT_BITS >= MATHX_16bT) &&
										  (MATHX_TEST_INT_UINT_BITS <= MATHX_512bT) &&
										  mxi::is_power_of_2<MATHX_TEST_INT_UINT_BITS>::value;
public:
	// see MATHX_TEST_SUMMARY
	static const bool summary = (MATHX_TEST_SUMMARY == MATHX_TRUE)? true: false;

	// see MATHX_TEST_VERBOSE
	static const bool verbose = (MATHX_TEST_VERBOSE == MATHX_TRUE)? true: false;

	// see MATHX_TEST_SHOW_TIME_STAMP
	static const bool show_time_stamp = (MATHX_TEST_SHOW_TIME_STAMP == MATHX_TRUE)? true: false;

	// see MATHX_TEST_SHOW_ALL_DURATION_PARTS
	static const bool show_all_duration_parts = (MATHX_TEST_SHOW_ALL_DURATION_PARTS == MATHX_TRUE)? true: false;

	// see MATHX_TEST_ALLOW_COLORS
	static const bool allow_colors = (MATHX_TEST_ALLOW_COLORS == MATHX_TRUE)? true: false;

	// see MATHX_TEST_INT_UINT_BITS
	static const ts_t int_uint_bits = is_valid_int_bits? MATHX_TEST_INT_UINT_BITS: 0;

	// see MATHX_TEST_STOP_AT_FIRST_CASE_ERROR
	static const bool stop_at_first_case_error = (MATHX_TEST_STOP_AT_FIRST_CASE_ERROR == MATHX_TRUE)? true: false;

	// see MATHX_TEST_STOP_ALL_AT_FIRST_CASE_ERROR
	static const bool stop_all_at_first_case_error = (MATHX_TEST_STOP_ALL_AT_FIRST_CASE_ERROR == MATHX_TRUE)? true: false;

	// see MATHX_TEST_BENCHMARK_IF_ALL_UNITS_OK
	static const bool benchmark_if_all_units_ok = (MATHX_TEST_BENCHMARK_IF_ALL_UNITS_OK == MATHX_TRUE)? true: false;

	typedef imp:: int_factory<int_uint_bits>::type si_t;
	typedef imp::uint_factory<int_uint_bits>::type ui_t;
};


}
}

#endif // MATHX_FRAMEWORK_TEST_INFO_HPP
