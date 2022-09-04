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
** File:  imp_cmn.hpp
**
** Purpose: common implementation
**
===========================================================*/

#ifndef MATHX_INT_CC_IMP_CMN_HPP
#define MATHX_INT_CC_IMP_CMN_HPP

namespace mathx
{
namespace mxi
{

template<typename ut>
inline cs_t int_fast_bit_count(ut value)
{
	// set least significant bits for ut - i.e. half its size - to ones
	const ut bit_pattren = fill_type_least_half_bits<ut>::value;

	cs_t bits_count = 0;

	if ((value & bit_pattren) != value)
	{
		bits_count = div_by_two< isizeof<ut>::value >::value;
		value >>= div_by_two< isizeof<ut>::value >::value;
	}

	while(value)
	{
		++bits_count;
		value >>= 1;
	}

	return bits_count;
}

template<typename ut, typename base_type>
inline cs_t log_in_base_for_type_size()
{
	return cs_t( fp_t(log10_for_type<ut>::value) / std::log10((fp_t)base_type::base) );
}

template<typename ut>
inline ut ipower(ut bas, cs_t pwr)
{
	const ut b = bas;
	for (cs_t i = 1; i < pwr; ++i) bas *= b;
	return bas;
}

template<typename num_t, typename base_type>
inline cs_t digits_in_type_for_base()
{
	return cs_t( fp_t(meta::int_info<num_t>::dec_digits) / std::log10((fp_t)base_type::base) ) + 1;
}

}
}

#endif // MATHX_INT_CC_IMP_CMN_HPP
