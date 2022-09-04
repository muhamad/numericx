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
** File:  default_bitwise.hpp
**
** Purpose: int_t/uint_t implementation for int_bitwise
**
===========================================================*/

#ifndef MATHX_INT_IMP_CMN_DEFAULT_BITWISE_HPP
#define MATHX_INT_IMP_CMN_DEFAULT_BITWISE_HPP

namespace mathx
{
namespace mxi
{

// bitwise functions
template <typename t>
struct default_bitwise
{
	typedef t type;

	typedef ispec_t<type> spec;

	inline static type& and_op(type& obj, const type& rhs)
	{
		for (cs_t i = 0; i < spec::comp_c; ++i) obj.comp[i] &= rhs.comp[i];
		return obj;
	}

	inline static type& or_op(type& obj, const type& rhs)
	{
		for (cs_t i = 0; i < spec::comp_c; ++i) obj.comp[i] |= rhs.comp[i];
		return obj;
	}

	inline static type& xor_op(type& obj, const type& rhs)
	{
		for (cs_t i = 0; i < spec::comp_c; ++i) obj.comp[i] ^= rhs.comp[i];
		return obj;
	}

	inline static t neg_op(const type& lhs)
	{
		type tmp;
		for (cs_t i = 0; i < spec::comp_c; ++i) tmp.comp[i] = ~lhs.comp[i];
		return tmp;
	}

	inline static type& neg_op(type& obj)
	{
		for (cs_t i = 0; i < spec::comp_c; ++i) obj.comp[i] = ~obj.comp[i];
		return obj;
	}
};

}
}

#endif // MATHX_INT_IMP_CMN_DEFAULT_BITWISE_HPP
