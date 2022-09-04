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
** File:  int_info.hpp
**
** Purpose: integer general information
**
===========================================================*/

#ifndef MATHX_COMMON_INFO_INT_INFO_HPP
#define MATHX_COMMON_INFO_INT_INFO_HPP

namespace mathx
{
namespace meta
{

// integer information
template<typename t>
struct int_info
{
	// input type
	typedef t type;
	typedef info_t<type> info;

	// is native type
	static const bool is_native = true;
	// is signed type
	static const bool is_signed = info::is_signed;
	// number of bits in type
	static const ts_t all_bits = info::num_of_bits;
	// number of bits used for data
	static const ts_t used_bits = info::num_of_bits - (is_signed? 1: 0);
	// number of bits in one component
	static const ts_t comp_bits = info::num_of_bits;
	// number of binary digits in type
	static const ts_t bin_digits = mxi::num_of_bin_digits_in_type<type>::value;
	// number of octal digits in type
	static const ts_t oct_digits = mxi::num_of_oct_digits_in_type<type>::value;
	// number of decimal digits in type
	static const ts_t dec_digits = mxi::num_of_dec_digits_in_type<type>::value;
	// number of hexadecimal digits in type
	static const ts_t hex_digits = mxi::num_of_hex_digits_in_type<type>::value;
};

}
}

#endif // MATHX_COMMON_INFO_INT_INFO_HPP
