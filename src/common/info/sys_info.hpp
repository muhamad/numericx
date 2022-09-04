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
** File:  sys_info.hpp
**
** Purpose: compiling platform information
**
===========================================================*/

#ifndef MATHX_COMMON_INFO_SYS_INFO_HPP
#define MATHX_COMMON_INFO_SYS_INFO_HPP

namespace mathx
{
namespace meta
{

// basic information about compiling platform
struct sys_info
{
	// processor register-half-size signed-int
	typedef  mxi::int_from_size< mxi::div_by_two< mxi::isizeof< mxi::ptr >::value >::value >::t   signed_half_int;
	// processor register-half-size unsigned-int
	typedef mxi::uint_from_size< mxi::div_by_two< mxi::isizeof< mxi::ptr >::value >::value >::t unsigned_half_int;

	// processor register-size signed-int
	typedef  mxi::int_from_size< mxi::isizeof< mxi::ptr >::value >::t   signed_full_int;
	// processor register-size unsigned-int
	typedef mxi::uint_from_size< mxi::isizeof< mxi::ptr >::value >::t unsigned_full_int;

	// number of bits per one byte
	static const ts_t bits_per_byte = MATHX_BIT;
	// float-point base representation
	static const ts_t float_base = FLT_RADIX;

	// is big-endian platform
	static const bool is_big_endian = (MATHX_BIG_ENDIAN == MATHX_TRUE)? true: false;
	// is platform uses twos complement to represent signed integer
	static const bool is_twos_complement = true;
	// what bus size of compiling platform
	// mathx didn't test with 16 bit.
	static const ts_t platform_type = mxi::isizeof<mxi::ptr>::value; // should be 32, 64... etc.
};

}
}

#endif // MATHX_COMMON_INFO_SYS_INFO_HPP
