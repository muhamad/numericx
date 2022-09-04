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
** Purpose: numeric_cast little-endian implementation
**
===========================================================*/

#ifndef MATHX_INT_NC_IMP_LE_HPP
#define MATHX_INT_NC_IMP_LE_HPP

namespace mathx
{
namespace mxi
{

template<typename num_t, typename ni_t>
inline num_t& int_from_pni_to_t(const ni_t& value, num_t& result)
{
	typedef typename num_t::ut ut;
	typedef ispec_t<num_t> spec;

	num_t::range::set_zero(result);

	if (value == ni_t(0)) return result;

	if (sizeof(num_t) < sizeof(ni_t))
	{
		const num_t& v = *(const num_t*)&value;
		for (cs_t i = 0; i < spec::comp_c ; ++i) result.comp[i] = v.comp[i];
	}
	else if (sizeof(ut) >= sizeof(ni_t))
		result.comp[0] = ut(value);
	else
		*(ni_t*)result.comp = value;

	return result;
}

template<typename num_t, typename ni_t>
inline num_t& int_from_ni_to_t(const ni_t& value, num_t& result)
{
	if (value >= ni_t(0)) return int_from_pni_to_t<num_t, ni_t>(value, result);

	num_t::range::set_none(result);

	if (sizeof(num_t) < sizeof(ni_t))
	{
		const num_t& v = *(const num_t*)&value;
		for (cs_t i = 0; i < ispec_t<num_t>::comp_c; ++i) result.comp[i] = v.comp[i];
	}
	else if (sizeof(typename num_t::st) >= sizeof(ni_t))
		result.comp[0] = typename num_t::st(value);
	else
		*(ni_t*)result.comp = value;

	return result;
}

template<typename num_t, typename flt_t>
inline num_t& int_from_nf_to_t(flt_t value, num_t& result)
{
#if MATHX_ALLOW_NATIVE_FP_CONVERTION == MATHX_FALSE
	// if float-point native operations isn't allowed and yet this function called
	// then throw exception and let the hardware deal with it.
	volatile cs_t c = 0;
	volatile cs_t q = 3 / c;
	return result;
#else
	typedef typename num_t::ut ut;
	typedef ispec_t<num_t> spec;

	const flt_t zero = flt_t(0);

	bool sign = value < zero;
	if (sign) value *= -1;

	num_t::range::set_zero(result);

	// if zero do nothing
	if (value == zero) return result;

	// get number of binary digits in f
	cs_t actual_digits = 0;
	std::frexp(value, (cs_t*)&actual_digits);

	// number of binary digits in r
	const cs_t digit_cnt = spec::comp_b;

	// get start index in array for little-endian format
	cs_t start_index = cs_t(actual_digits / digit_cnt) + cs_t((actual_digits / digit_cnt) * digit_cnt < actual_digits) - 1;

	// if float-point value is more than it can be stored in input type
	if (start_index >= spec::comp_c)
	{
#if MATHX_ALLOW_NATIVE_FP_TO_INT_TRUNCATION == MATHX_TRUE
		// if required elements  - i.e. (start_index+1) - is twice more or greater than
		// number of elements in result then the conversion will yield zero.
		if (((start_index+1) / spec::comp_c) > 1) return result;

		// truncate component that will not be stored

		// discard left-most digits
		for(cs_t i = start_index; i >= spec::comp_c; --i)
		{
			flt_t fpow = std::pow(flt_t(meta::sys_info::float_base), flt_t(digit_cnt) * i);
			value -= fpow * flt_t(ut(value / fpow));
		}
		start_index = spec::comp_c - 1;
		// sign is not important because number already truncated
		sign = false;
#else
		return result;
#endif
	}

	// get all parts but the last
	while(start_index > 0)
	{
		flt_t fpow = std::pow(flt_t(meta::sys_info::float_base), flt_t(digit_cnt) * start_index);
		result.comp[start_index] = ut(value / fpow);
		value -= fpow * flt_t(result.comp[start_index]);
		--start_index;
	}
	result.comp[0] = ut(value);

	if (sign) num_t::arithmetic::multiply_none(result);

	return result;
#endif
}

template<typename num_t, typename ni_t>
inline ni_t& int_from_t_to_ni(const num_t& value, ni_t& result)
{
	result = ni_t(0);

	if (sizeof(ni_t) <= sizeof(typename num_t::ut)) return result = ni_t(value.comp[0]);

	return result = *(ni_t*)value.comp;
}

template<typename num_t, typename flt_t>
inline flt_t& int_from_t_to_nf(const num_t& value, flt_t& result)
{
#if MATHX_ALLOW_NATIVE_FP_CONVERTION == MATHX_FALSE
	// if float-point native operations isn't allowed and yet the user used this function
	// then throw exception and let the hardware deal with it.
	volatile cs_t c = 0;
	volatile cs_t q = 3 / c;
	return result;
#else
	typedef ispec_t<num_t> spec;

	result = flt_t(0);

	bool sign = false;
	num_t tmp;

	if (spec::is_signed && num_t::range::is_neg(value))
	{
		num_t::arithmetic::multiply_none(tmp, value);
		sign = true;
	}
	else
		tmp = value;

	// index of last element occupied
	cs_t comp_idx = -1;

	for (cs_t i = spec::comp_c - 1; i >= 0; --i)
	{
		if (value.comp[i])
		{
			comp_idx = i;
			break;
		}
	}

	if (comp_idx == -1) return result;

	// number of bits occupied by input value
	cs_t bits_count = comp_idx * spec::comp_b;
	{
		typename num_t::ut rest = value.comp[comp_idx];
		// get number of bits in item at comp_idx
		while(++bits_count, rest >>= 1);
	}

#if MATHX_ALLOW_INT_TO_NATIVE_FP_TRUNCATION == MATHX_FALSE
	if (bits_count > float_info<flt_t>::bin_digits_count) return result;
#endif

	for (cs_t i = comp_idx; i >= 0; --i)
		result += flt_t (std::pow(fp_t(meta::sys_info::float_base), fp_t(spec::comp_b * i)) * value.comp[i]);

	if (spec::is_signed && sign) result *= flt_t(-1);
	return result;
#endif
}

template<typename num_it, typename num_ot>
inline num_ot& int_from_sut_to_sut(const num_it& value, num_ot& result)
{
	typedef ispec_t<num_it> spec_it;
	typedef ispec_t<num_ot> spec_ot;

	// if result type size is less than or equals to source type size
	if (spec_ot::full_s <= spec_it::full_s)
		for (cs_t i = 0; i < spec_ot::comp_c; ++i) result.comp[i] = value.comp[i];

	// result type with size greater than source type size
	else
	{
		cs_t i = 0;
		for(; i < spec_it::comp_c; ++i) result.comp[i] = value.comp[i];

		// if input and output are unsigned types
		if (spec_ot::info::id == meta::ti_uint_t && spec_it::info::id == spec_ot::info::id)
			for(; i < spec_ot::comp_c; ++i) result.comp[i] = 0;
		else
		{
			// if sign bit is set in source value
			// remember i can't use int_range::is_neg because it's only work with
			// signed-types and to simplify the code i choose the following approach
			if (spec_it::info::id == meta::ti_int_t && (value.comp[spec_it::comp_c - 1] >> (spec_it::comp_b - 1)))
				for(; i < spec_ot::comp_c; ++i) result.comp[i] = typename num_ot::ut(~0);
			else
				for(; i < spec_ot::comp_c; ++i) result.comp[i] = 0;
		}
	}
	return result;
}

}
}

#endif // MATHX_INT_NC_IMP_LE_HPP
