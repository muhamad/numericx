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
** File:  prototype.hpp
**
** Purpose: cast helper functions
**
===========================================================*/

#ifndef MATHX_INT_CC_PROTOTYPE_HPP
#define MATHX_INT_CC_PROTOTYPE_HPP

namespace mathx
{
namespace mxi
{

// add single value to input type
// value: value to be added to num
template<typename t>
inline void int_fast_add(t& num, typename t::ut value);

// multiply input number by input value
// Note input number must be positive
template<typename t>
inline void int_fast_mul(t& num, cs_t count, typename t::ut value);

// divide input number by input value
// index: location of first most significant element with value
// return reminder
// Note input number must be positive
template<typename t>
inline typename t::ut int_fast_div(t& num, cs_t index, typename t::ut value);

// get number of bits in input value
template<typename ut>
inline cs_t int_fast_bit_count(ut value);

// get exponent for input-base which satisfy the equation: b^e = ut(~0)
template<typename ut, typename base_type>
inline cs_t log_in_base_for_type_size();

// get value of base raised to power
template<typename ut>
inline ut ipower(ut bas, cs_t pwr);

// get number of digits in [num_t] for [base_t]
template<typename num_t, typename base_t>
inline cs_t digits_in_type_for_base();

}
}

#endif // MATHX_INT_CC_PROTOTYPE_HPP
