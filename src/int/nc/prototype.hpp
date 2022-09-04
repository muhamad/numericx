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
** Purpose: numeric_cast helper functions
**
===========================================================*/

#ifndef MATHX_INT_NC_PROTOTYPE_HPP
#define MATHX_INT_NC_PROTOTYPE_HPP

namespace mathx
{
namespace mxi
{

// from positive native integer to int_t/uint_t
// num_t: int_t/uint_t
// ni_t: native integer
template<typename num_t, typename ni_t>
inline num_t& int_from_pni_to_t(const ni_t& value, num_t& result);

// from native integer to int_t/uint_t
// num_tt: int_t/uint_t
// ni_t: native integer
template<typename num_t, typename ni_t>
inline num_t& int_from_ni_to_t(const ni_t& value, num_t& result);

// from float-point to uint_t/int_t
// num_t: int_t/uint_t
// ft_t: float-point type
template<typename num_t, typename flt_t>
inline num_t& int_from_nf_to_t(flt_t value, num_t& result);

// from int_t/uint_t to native integer
// num_t: int_t/uint_t
// ni_t: native integer
template<typename num_t, typename ni_t>
inline ni_t& int_from_t_to_ni(const num_t& value, ni_t& result);

// from int_t/uint_t to float-point
// num_t: int_t/uint_t
// ft_t: float-point type
template<typename num_t, typename flt_t>
inline flt_t& int_from_t_to_nf(const num_t& value, flt_t& result);

// from int_t/uint_t to uint_t/int_t
// NOTE: basic types that form both types must be the same
template<typename num_it, typename num_ot>
inline num_ot& int_from_sut_to_sut(const num_it& value, num_ot& result);

}
}

#endif // MATHX_INT_NC_PROTOTYPE_HPP
