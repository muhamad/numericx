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
** Purpose: string_cast helper functions
**
===========================================================*/

#ifndef MATHX_INT_SC_PROTOTYPE_HPP
#define MATHX_INT_SC_PROTOTYPE_HPP

namespace mathx
{
namespace mxi
{

// get number of decimal digits in input value
// return value greater than or equals to one.
template<typename num_type>
inline cs_t int_len_dec(const num_type& value);

// get number of digits in input value for base2/8/16
// return value greater than or equals to one.
template<typename num_type, typename base_type>
inline cs_t int_len_bas(const num_type& value);

// get number of digits in input value for any base_type
// return value greater than or equals to one.
template<typename num_type, typename base_type>
inline cs_t int_len_any(const num_type& value);

// convert decimal string to int_t/uint_t
// return true if conversion succeeded, false otherwise
template<typename num_type, typename base_type>
inline bool int_fstr_dec(const typename base_type::char_t* str, num_type& value);

// convert string in base2/8/16 to int_t/uint_t
// return true if conversion succeeded, false otherwise
template<typename num_type, typename base_type>
inline bool int_fstr_bas(const typename base_type::char_t* str, num_type& value);

// convert string in input base_type to int_t/uint_t
// return true if conversion succeeded, false otherwise
template<typename num_type, typename base_type>
inline bool int_fstr_any(const typename base_type::char_t* str, num_type& value);

// convert int_t/uint_t to decimal string
// return true if conversion succeeded, false otherwise
template<typename num_type, typename base_type>
inline bool int_tstr_dec(const num_type& value, typename base_type::char_t* str);

// convert int_t/uint_t to string in base2/8/16
// return true if conversion succeeded, false otherwise
template<typename num_type, typename base_type>
inline bool int_tstr_bas(const num_type& value, typename base_type::char_t* str, bool upper);

// convert int_t/uint_t to string in input base_type
// return true if conversion succeeded, false otherwise
template<typename num_type, typename base_type>
inline bool int_tstr_any(const num_type& value, typename base_type::char_t* str, bool upper);

}
}

#endif // MATHX_INT_SC_PROTOTYPE_HPP
