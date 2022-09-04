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
** File:  default_arithmetic.hpp
**
** Purpose: int_t/uint_t big-endian implementation for int_arithmetic
**
===========================================================*/

#ifndef MATHX_INT_IMP_BE_DEFAULT_ARITHMETIC_HPP
#define MATHX_INT_IMP_BE_DEFAULT_ARITHMETIC_HPP

namespace mathx
{
namespace mxi
{

// arithmetic functions
// type: int_t/uint_t specialization
template <typename t>
struct default_arithmetic
{
	typedef t type;

	typedef ispec_t<type> spec;
	typedef typename t::st  st;
	typedef typename t::ut  ut;
	typedef typename t::udt udt;

	typedef typename t::logic logic;
	typedef typename t::range range;

	// zero value
	static const ut zero_v = ut(0);
	// one value
	static const ut one_v  = ut(1);
	// maximum unsigned value
	static const ut maxu_v  = ut(~0);
};

}
}

#endif // MATHX_INT_IMP_BE_DEFAULT_ARITHMETIC_HPP
