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
** File:  info_t.hpp
**
** Purpose: type classification
**
===========================================================*/

#ifndef MATHX_COMMON_INFO_INFO_T_HPP
#define MATHX_COMMON_INFO_INFO_T_HPP

namespace mathx
{
namespace meta
{

// type identification code
enum type_id
{
	ti_basic_int,	// used with built-in integer types
	ti_basic_float,	// used with built-in float-point types
	ti_basic_bool,  // used with built-in bool type
	ti_int_t,		// used with int_t
	ti_uint_t,		// used with uint_t
	ti_float_t,		// used with float_t
	ti_fixed_t,		// used with fixed_t (fixed-point type)
	ti_others		// used with internal types and useless types
};

// type basic information
template <typename t>
struct info_t
{
	typedef t type;

	// is native type
	static const bool is_native  = true;
	// is boolean type
	static const bool is_bool    = false;
	// is integer type
	static const bool is_integer = (type(5)/type(2)) == type(2);
	// is signed type
	static const bool is_signed  = type(-1) < type(0);
	// is float-point type
	static const bool is_float   = ! is_integer;
	// number of bytes in type
	static const ts_t num_of_bytes = sizeof(type);
	// number of bits in type
	static const ts_t num_of_bits  = sizeof(type) * MATHX_BIT;
	// type id
	static const type_id id = is_integer? ti_basic_int: ti_basic_float;
};

// [bool] type information
template <>
struct info_t<bool>
{
	typedef bool type;

	// is native type
	static const bool is_native  = true;
	// is boolean type
	static const bool is_bool    = true;
	// is integer type
	static const bool is_integer = false;
	// is signed type
	static const bool is_signed  = false;
	// is float-point type
	static const bool is_float   = false;
	// number of bytes in type
	static const ts_t num_of_bytes = sizeof(bool);
	// number of bits in type
	static const ts_t num_of_bits  = sizeof(bool) * MATHX_BIT;
	// type id
	static const type_id id = ti_basic_bool;
};

}
}

#endif // MATHX_COMMON_INFO_INFO_T_HPP
