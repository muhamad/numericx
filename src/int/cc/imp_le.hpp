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
** File:  imp_le.hpp
**
** Purpose: little-endian implementation
**
===========================================================*/

#ifndef MATHX_INT_CC_IMP_LE_HPP
#define MATHX_INT_CC_IMP_LE_HPP

namespace mathx
{
namespace mxi
{

template<typename t>
inline void int_fast_add(t& num, typename t::ut value)
{
	typedef typename t::ut  ut;
	typedef typename t::udt udt;

	for (cs_t idx = 0; value && idx < ispec_t<t>::comp_c; ++idx)
	{
		udt cur = udt(num.comp[idx]) + value;
		num.comp[idx] = (*(split_t<ut>*)&cur).comp[MATHX_LO];
		value = (*(split_t<ut>*)&cur).comp[MATHX_HI];
	}
}

template<typename t>
inline void int_fast_mul(t& num, cs_t count, typename t::ut value)
{
	typedef typename t::ut  ut;
	typedef typename t::udt udt;

	ut carry = 0;

	for(cs_t i = 0; i < ispec_t<t>::comp_c; ++i)
	{
		udt sum = value * udt(num.comp[i]) + carry;
		num.comp[i] = (*(split_t<ut>*)&sum).comp[MATHX_LO];
		carry = (*(split_t<ut>*)&sum).comp[MATHX_HI];

		// to avoid repeat over zero elements
		// this order is very important, changing that will slow the performance
		if (i > count && carry == 0 && sum == 0) break;
	}
}

template<typename t>
inline typename t::ut int_fast_div(t& num, cs_t index, typename t::ut value)
{
	typedef typename t::ut ut;
	typedef typename t::udt udt;
	
	const cs_t size = isizeof<ut>::value;

	udt a = 0;

	for (cs_t i = index; i >= 0; --i)
	{
		udt b = (udt)num.comp[i] + (a << size);
		num.comp[i] = ut(b / value);

		a = b - udt(value) * num.comp[i];
	}

	return ut(a);
}

}
}

#endif // MATHX_INT_CC_IMP_LE_HPP
