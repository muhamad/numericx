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
** File:  imp_int.hpp
**
** Purpose: mathematical library int_t/uint_t implementation
**
===========================================================*/

#ifndef MATHX_MATH_IMP_INT_HPP
#define MATHX_MATH_IMP_INT_HPP

namespace mathx
{
namespace math
{
namespace math_imp
{


template<typename type> inline
type& int_abs(const type& value, type& result)
{
	if (type::meta::is_signed)
	{
		if (type::range::is_neg(value))
		{
			if (&result == &value)
				return type::arithmetic::multiply_none(result);
			else
				return type::arithmetic::multiply_none(result, value);
		}
	}

	if (&result == &value) return result;
	return result = value;
}


template<typename type> inline
cs_t int_get_sign(const type& value)
{
	if (type::meta::is_signed && type::range::is_neg(value)) return -1;

	return type::range::is_zero(value)? 0: 1;
}


template<typename type, bool is_min> inline
type& int_min_max(const type& v1, const type& v2)
{
	if (is_min)
		return const_cast<type&>(type::logic::less_than(v1, v2)? v1: v2);
	else
		return const_cast<type&>(type::logic::greater_than(v1, v2)? v1: v2);
}


template<typename type> inline
bool int_fact_digits_in_range(const cu_t& value)
{
	// use 0.5 * log(2 * pi) + (n + 0.5) * log(n) - n * log(e)
	// where
	//    0.5 * log(2 * pi) = 0.3990899341790575247825035915077
	//               log(e) = 0.4342944819034043684988814432564

	return type::meta::dec_digits_count >=
		   cs_t
		   (
			fp_t(1.3990899341790575247825035915077) +
	        (value + fp_t(0.5)) * std::log10(fp_t(value)) -
	        fp_t(value * fp_t(0.4342944819034043684988814432564))
	       );
}

template<typename type> inline
bool compute_fact(const cu_t& value, type& result)
{
	typedef typename type::ut   ut;
	typedef typename type::udt udt;

	if (!int_fact_digits_in_range<type>(value))
		return false;

	if (value == 1)
	{
		result = value;
		return true;
	}

	type::range::set_one(result);

	if (value == 0) return true;

	if (sizeof(ut) >= sizeof(cu_t))
	{
		// TODO: test big-endian implementation

		ut carry = 0;
		cs_t count = 1;

		for (cu_t i=2; i<=value; ++i)
		{
	#if MATHX_BIG_ENDIAN == MATHX_TRUE
			for(cs_t j=type::meta::array_count - 1; j>=0; --j)
	#else
			for(cs_t j=0; j<type::meta::array_count; ++j)
	#endif
			{
				udt sum = i * udt(result.comp[j]) + carry;
				result.comp[j] = (*(mxi::split_t<ut>*)&sum).comp[MATHX_LO];
				carry = (*(mxi::split_t<ut>*)&sum).comp[MATHX_HI];

	#if MATHX_BIG_ENDIAN == MATHX_TRUE
				if ((type::meta::array_count - j) > count && carry == 0 && sum == 0)
	#else
				if (j > count && carry == 0 && sum == 0)
	#endif
				{
					count = j + 1;
					break;
				}
			}
		}
	}
	else
	{
		// TODO: implement factorial of multi-element input

		const cs_t e_count = sizeof(cu_t) / sizeof(ut);

		union data { ut comp[e_count]; } const &e = *(data*)&value;


	}

	return true;
}

}
}
}

#endif // MATHX_MATH_IMP_INT_HPP
