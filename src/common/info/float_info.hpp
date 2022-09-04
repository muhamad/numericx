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
** File:  float_info.hpp
**
** Purpose: float-point general information
**
===========================================================*/

#ifndef MATHX_COMMON_INFO_FLOAT_INFO_HPP
#define MATHX_COMMON_INFO_FLOAT_INFO_HPP

namespace mathx
{
namespace meta
{
	// float-point information
	template <typename t> struct float_info;

// [float] information
template <>
struct float_info<float>
{
	// input type
	typedef float type;
	typedef info_t<type> info;

	// is native type
	static const bool is_native = true;
	// is compatible with IEEE-475 standard
	static const bool is_ieee754 = std::numeric_limits<type>::is_iec559;
	// number of bits used by sign
	static const ts_t sign_size = is_ieee754? mxi::float_sign_size< info::num_of_bits >::value: 0;
	// number of bits used by exponent
	static const ts_t exp_size = is_ieee754? mxi::float_exponent_size< info::num_of_bits >::value: 0;
	// number of bits used by mantissa
	static const ts_t man_size = is_ieee754? mxi::float_mantissa_size< info::num_of_bits >::value: 0;
	// number of decimal digits in mantissa
	static const ts_t dec_digits_count = FLT_DIG;
	// number of binary digits in mantissa
	static const ts_t bin_digits_count = FLT_MANT_DIG;
	// maximum binary exponent
	static const ts_t max_bin_exponent = FLT_MAX_EXP;
	// minimum binary exponent
	static const ts_t min_bin_exponent = FLT_MIN_EXP;
	// maximum decimal exponent
	static const ts_t max_dec_exponent = FLT_MAX_10_EXP;
	// minimum decimal exponent
	static const ts_t min_dec_exponent = FLT_MIN_10_EXP;
};

// [double] information
template <>
struct float_info<double>
{
	// input type
	typedef double type;
	typedef info_t<type> info;

	// is native type
	static const bool is_native = true;
	// is compatible with IEEE-475 standard
	static const bool is_ieee754 = std::numeric_limits<type>::is_iec559;
	// number of bits used by sign
	static const ts_t sign_size = is_ieee754? mxi::float_sign_size< info::num_of_bits >::value: 0;
	// number of bits used by exponent
	static const ts_t exp_size = is_ieee754? mxi::float_exponent_size< info::num_of_bits >::value: 0;
	// number of bits used by mantissa
	static const ts_t man_size = is_ieee754? mxi::float_mantissa_size< info::num_of_bits >::value: 0;
	// number of decimal digits in mantissa
	static const ts_t dec_digits_count = DBL_DIG;
	// number of binary digits in mantissa
	static const ts_t bin_digits_count = DBL_MANT_DIG;
	// maximum binary exponent
	static const ts_t max_bin_exponent = DBL_MAX_EXP;
	// minimum binary exponent
	static const ts_t min_bin_exponent = DBL_MIN_EXP;
	// maximum decimal exponent
	static const ts_t max_dec_exponent = DBL_MAX_10_EXP;
	// minimum decimal exponent
	static const ts_t min_dec_exponent = DBL_MIN_10_EXP;
};

// [long double] information
template <>
struct float_info<long double>
{
	// input type
	typedef long double  type;
	typedef info_t<type> info;

	// is native type
	static const bool is_native = true;
	// is compatible with IEEE-475 standard
	static const bool is_ieee754 = std::numeric_limits<type>::is_iec559;
	// number of bits used by sign
	static const ts_t sign_size = is_ieee754? mxi::float_sign_size< info::num_of_bits >::value: 0;
	// number of bits used by exponent
	static const ts_t exp_size = is_ieee754? mxi::float_exponent_size< info::num_of_bits >::value: 0;
	// number of bits used by mantissa
	static const ts_t man_size = is_ieee754? mxi::float_mantissa_size< info::num_of_bits >::value: 0;
	// number of decimal digits in mantissa
	static const ts_t dec_digits_count = LDBL_DIG;
	// number of binary digits in mantissa
	static const ts_t bin_digits_count = LDBL_MANT_DIG;
	// maximum binary exponent
	static const ts_t max_bin_exponent = LDBL_MAX_EXP;
	// minimum binary exponent
	static const ts_t min_bin_exponent = LDBL_MIN_EXP;
	// maximum decimal exponent
	static const ts_t max_dec_exponent = LDBL_MAX_10_EXP;
	// minimum decimal exponent
	static const ts_t min_dec_exponent = LDBL_MIN_10_EXP;
};

}
}

#endif // MATHX_COMMON_INFO_FLOAT_INFO_HPP
