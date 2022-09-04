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
** File:  default_range.hpp
**
** Purpose: int_t/uint_t little-endian implementation for int_range
**
===========================================================*/

#ifndef MATHX_INT_IMP_LE_DEFAULT_RANGE_HPP
#define MATHX_INT_IMP_LE_DEFAULT_RANGE_HPP

namespace mathx
{
namespace mxi
{

// range functions
template <typename t>
struct default_range
{
	typedef t type;

	typedef ispec_t<type> spec;
	typedef typename type::ut ut;

	// zero value
	static const ut zero_v = ut(0);
	// one value
	static const ut one_v  = ut(1);
	// maximum unsigned value
	static const ut maxu_v  = ut(~0);
	// maximum signed value
	static const ut maxs_v  = div_by_two< maxu_v >::value;
	// minimum signed value
	static const ut mins_v  = one_v << (spec::comp_b - 1);

	inline static type& set_min(type& obj)
	{
		// if type is not signed
		if (!spec::is_signed)
		{
			// minimum value is zero
			return set_zero(obj);
		}
		else
		{
			// minimum value is 0x8 at most significant nibble, the rest is zero
			obj.comp[spec::comp_c - 1] = mins_v;
			for (cs_t i = 0; i < spec::comp_c - 1; ++i) obj.comp[i] = zero_v;
			return obj;
		}
	}

	inline static type& set_max(type& obj)
	{
		// if type is not signed
		if (!spec::is_signed)
		{
			// maximum value is 0xff
			return set_none(obj);
		}
		else
		{
			// maximum value is 0x7 at most significant nibble, the rest is 0xf
			obj.comp[spec::comp_c - 1] = maxs_v;
			for (cs_t i = 0; i < spec::comp_c - 1; ++i) obj.comp[i] = maxu_v;
			return obj;
		}
	}

	inline static type& set_none(type& obj)
	{
		for (cs_t i = 0; i < spec::comp_c; ++i) obj.comp[i] = maxu_v;
		return obj;
	}

	inline static type& set_zero(type& obj)
	{
		for (cs_t i = 0; i < spec::comp_c; ++i) obj.comp[i] = zero_v;
		return obj;
	}

	inline static type& set_one(type& obj)
	{
		obj.comp[0] = one_v;
		for (cs_t i = 1; i < spec::comp_c; ++i) obj.comp[i] = zero_v;
		return obj;
	}

	inline static bool is_min(const type& obj)
	{
		// if type is not signed
		if (!spec::is_signed)
		{
			// check if any element is not zero
			return is_zero(obj);
		}
		else
		{
			// minimum value is 0x8 in most significant nibble and zero in the rest
			if (obj.comp[spec::comp_c - 1] != mins_v) return false;
			for (cs_t i = 0; i < spec::comp_c - 1; ++i) if(obj.comp[i] != zero_v) return false;
			return true;
		}
	}

	inline static bool is_max(const type& obj)
	{
		// if type is not signed
		if (!spec::is_signed)
		{
			// check if any element is not ~0
			return is_none(obj);
		}
		else
		{
			// maximum value is 0x7 in most significant nibble and 0xf at the rest.
			if (obj.comp[spec::comp_c - 1] != maxs_v) return false;
			for (cs_t i = 0; i < spec::comp_c - 1; ++i) if(obj.comp[i] != maxu_v) return false;
			return true;
		}
	}

	inline static bool is_neg(const type& obj)
	{
		// if not signed
		if (!spec::is_signed)
			return false;
		else
			// evaluate to true if most significant bit is one, otherwise false.
			return (obj.comp[spec::comp_c -1] & mins_v) != zero_v;
	}

	inline static bool is_zero(const type& obj)
	{
		for (cs_t i = 0; i < spec::comp_c; ++i) if (obj.comp[i] != zero_v) return false;
		return true;
	}

	inline static bool is_one(const type& obj)
	{
		if (obj.comp[0] != one_v) return false;
		for (cs_t i = 1; i < spec::comp_c; ++i) if (obj.comp[i] != zero_v) return false;
		return true;
	}

	inline static bool is_none(const type& obj)
	{
		for (cs_t i = 0; i < spec::comp_c; ++i) if (obj.comp[i] != maxu_v) return false;
		return true;
	}

	inline static bool is_zero_or_one(const type& obj)
	{
		if (obj.comp[0] != zero_v && obj.comp[0] != one_v) return false;
		for (cs_t i = 1; i < spec::comp_c; ++i) if (obj.comp[i] != zero_v) return false;
		return true;
	}
};

}
}

#endif // MATHX_INT_IMP_LE_DEFAULT_RANGE_HPP
