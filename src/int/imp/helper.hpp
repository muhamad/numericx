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
** File:  helper.hpp
**
** Purpose: int_t/uint_t helper types
**
===========================================================*/

#ifndef MATHX_INT_IMP_HELPER_HPP
#define MATHX_INT_IMP_HELPER_HPP

namespace mathx
{
namespace mxi
{

// provide fast access to low/high elements of a udt_t
template <typename ut> struct split_t { ut comp[2]; };

// provide internal information about int_t/uint_t
template<typename t>
struct ispec_t
{
	typedef meta::int_info<t> bi;
	typedef meta::info_t<t> info;

	// radix used to implement int_t/uint_t
	static const ts_t radix = 2;
	// total number of bits in t, should be a power of 2
	static const ts_t full_s = (bi::all_bits >= MATHX_16bT && is_power_of_2< bi::all_bits >::value)? bi::all_bits: 0;
	// total number of bits but sign bit
	static const ts_t used_s = bi::used_bits;
	// true if number is signed, false otherwise
	static const bool is_signed = bi::is_signed;
	// half number of bits in t
	static const ts_t half_s = div_by_two<full_s>::value;
	// number of bits in one component
	static const ts_t comp_b = (bi::all_bits >= MATHX_16bT && is_power_of_2< bi::comp_bits >::value)? bi::comp_bits: 0;
	// number of bits in one double component
	static const ts_t comp_d = mul_by_two<comp_b>::value;
	// number of array elements in t
	static const ts_t comp_c = full_s / comp_b;
};

}
}

#endif // MATHX_INT_IMP_HELPER_HPP
