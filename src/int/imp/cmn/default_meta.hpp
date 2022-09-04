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
** File:  default_meta.hpp
**
** Purpose: int_t/uint_t implementation for int_meta
**
===========================================================*/

#ifndef MATHX_INT_IMP_CMN_DEFAULT_META_HPP
#define MATHX_INT_IMP_CMN_DEFAULT_META_HPP

namespace mathx
{
namespace mxi
{

// metadata constants
template <typename t>
struct default_meta
{
	typedef t type;

	typedef ispec_t<type> spec;

	static const bool is_signed = spec::is_signed;

	static const cs_t radix = spec::radix;

	static const cs_t sign_bits = spec::is_signed? 1: 0;

	static const cs_t element_bits = spec::comp_b;

	static const cs_t data_bits = spec::used_s;

	static const cs_t all_bits = spec::full_s;

	static const cs_t array_count = spec::comp_c;

	static const cs_t radix_digits_count = meta::int_info<type>::bin_digits;

	static const cs_t bin_digits_count = meta::int_info<type>::bin_digits;

	static const cs_t oct_digits_count = meta::int_info<type>::oct_digits;

	static const cs_t dec_digits_count = meta::int_info<type>::dec_digits;

	static const cs_t hex_digits_count = meta::int_info<type>::hex_digits;
};

}
}

#endif // MATHX_INT_IMP_CMN_DEFAULT_META_HPP
