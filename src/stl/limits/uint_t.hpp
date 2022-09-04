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
** File:  uint_t.hpp
**
** Purpose: numeric_limits for uint_t
**
===========================================================*/

#ifndef MATHX_STL_LIMITS_UINT_T_HPP
#define MATHX_STL_LIMITS_UINT_T_HPP

namespace std
{

template<mathx::cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
class numeric_limits < mathx::uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
{
	typedef mathx::uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> t;

public:
	static const bool is_specialized = true;
	static t min() throw() { t tmp; return t::range::set_min(tmp); }
	static t max() throw() { t tmp; return t::range::set_max(tmp); }
	static const int digits = t::meta::radix_digits_count;
	static const int digits10 = t::meta::dec_digits_count;
	static const bool is_signed = true;
	static const bool is_integer = true;
	static const bool is_exact = true;
	static const int radix = t::meta::radix;

	static t epsilon() throw()	 { t tmp; return t::range::set_zero(tmp); }
	static t round_error() throw() { t tmp; return t::range::set_zero(tmp); }
	static const int min_exponent = 0;
	static const int min_exponent10 = 0;
	static const int max_exponent = 0;
	static const int max_exponent10 = 0;
	static const bool has_infinity = false;
	static const bool has_quiet_NaN = false;
	static const bool has_signaling_NaN = false;
	static const float_denorm_style has_denorm = denorm_absent;
	static const bool has_denorm_loss = false;
	static t infinity() throw()	  { t tmp; return t::range::set_zero(tmp); }
	static t quiet_NaN() throw()	 { t tmp; return t::range::set_zero(tmp); }
	static t signaling_NaN() throw() { t tmp; return t::range::set_zero(tmp); }
	static t denorm_min() throw()	{ t tmp; return t::range::set_zero(tmp); }
	static const bool is_iec559 = false;
	static const bool is_bounded = true;
	static const bool is_modulo = true;
	static const bool traps = true;
	static const bool tinyness_before = false;
	static const float_round_style round_style = round_toward_zero;
};

}

#endif // MATHX_STL_LIMITS_UINT_T_HPP
