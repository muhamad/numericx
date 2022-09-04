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
** File:  default_logic.hpp
**
** Purpose: int_t/uint_t big-endian implementation for int_logic
**
===========================================================*/

#ifndef MATHX_INT_IMP_BE_DEFAULT_LOGIC_HPP
#define MATHX_INT_IMP_BE_DEFAULT_LOGIC_HPP

namespace mathx
{
namespace mxi
{

// logic functions
template <typename t>
struct default_logic
{
	typedef t type;

	typedef ispec_t<type> spec;
	typedef typename type::ut ut;
	typedef typename type::st st;
	typedef typename type::range range;

	// zero value
	static const ut zero_v = ut(0);
	// one value
	static const ut one_v  = ut(1);
	// maximum unsigned value
	static const ut maxu_v  = ut(~0);
	// maximum signed value
	static const ut maxs_v  = fast_div_by_two< maxu_v >::value;
	// minimum signed value
	static const ut mins_v  = one_v << (spec::comp_b - 1);

	inline static bool and_op(const type& lhs, const type& rhs)
	{
		return !range::is_zero(lhs) && !range::is_zero(rhs);
	}

	inline static bool or_op(const type& lhs, const type& rhs)
	{
		return !range::is_zero(lhs) || !range::is_zero(rhs);
	}

	inline static bool self_or(const type& obj)
	{
		for (cs_t i = spec::comp_c - 1; i >= 0; --i) if(obj.comp[i] != zero_v) return true;
		return false;
	}

	inline static bool not_op(const type& lhs)
	{
		return range::is_zero(lhs);
	}

	inline static bool less_than(const type& lhs, const type& rhs)
	{
		if (spec::is_signed)
		{
			const bool neg = range::is_neg(lhs) || range::is_neg(rhs);

			if ((st)lhs.comp[0] < (st)rhs.comp[0]) return true;

			if (neg)
			{
				for (cs_t i = 1; i < spec::comp_c; ++i)
					if(lhs.comp[i] != rhs.comp[i]) return (st)lhs.comp[i] < (st)rhs.comp[i];
			}
			else
			{
				for (cs_t i = 1; i < spec::comp_c; ++i)
					if(lhs.comp[i] != rhs.comp[i]) return lhs.comp[i] < rhs.comp[i];
			}
		}
		else
		{
			for (cs_t i = 1; i < spec::comp_c ; ++i)
				if(lhs.comp[i] != rhs.comp[i]) return lhs.comp[i] < rhs.comp[i];
		}
		return false;
	}

	inline static bool greater_than(const type& lhs, const type& rhs)
	{
		return less_than(rhs, lhs);
	}

	inline static bool less_than_equal(const type& lhs, const type& rhs)
	{
		return !less_than(rhs, lhs);
	}

	inline static bool greater_than_equal(const type& lhs, const type& rhs)
	{
		return !less_than(lhs, rhs);
	}

	inline static bool equal(const type& lhs, const type& rhs)
	{
		for (cs_t i = spec::comp_c - 1; i >= 0; --i)
			if( lhs.comp[i] != rhs.comp[i] ) return false;
		return true;
	}

	inline static bool not_equal(const type& lhs, const type& rhs)
	{
		return !equal(lhs, rhs);
	}
};

}
}

#endif // MATHX_INT_IMP_BE_DEFAULT_LOGIC_HPP
