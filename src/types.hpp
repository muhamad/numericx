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
** File:  types.hpp
**
** Purpose: predefined numeric types
**
===========================================================*/

#ifndef MATHX_TYPES_HPP
#define MATHX_TYPES_HPP

namespace mathx
{
namespace imp
{

template<cu_t a,
		 typename b = mathx_ut, typename c = mathx_st, typename d = mathx_udt, typename e = mathx_sdt,
		 template <typename> class f = mxi::default_range, template <typename> class g = mxi::default_bitwise,
		 template <typename> class h = mxi::default_logic, template <typename> class i = mxi::default_arithmetic,
		 template <typename> class j = mxi::default_meta>
struct int_factory
{
	typedef int_t<a, b, c, d, e, f, g, h, i, j> type;
};

template<cu_t a,
		 typename b = mathx_ut, typename c = mathx_udt,
		 template <typename> class d = mxi::default_range, template <typename> class e = mxi::default_bitwise,
		 template <typename> class f = mxi::default_logic, template <typename> class g = mxi::default_arithmetic,
		 template <typename> class h = mxi::default_meta>
struct uint_factory
{
	typedef uint_t<a, b, c, d, e, f, g, h> type;
};

}

typedef imp::int_factory< MATHX_16bT>::type  int128_t;
typedef imp::int_factory< MATHX_32bT>::type  int256_t;
typedef imp::int_factory< MATHX_64bT>::type  int512_t;
typedef imp::int_factory<MATHX_128bT>::type int1024_t;
typedef imp::int_factory<MATHX_256bT>::type int2048_t;
typedef imp::int_factory<MATHX_512bT>::type int4096_t;

typedef imp::uint_factory< MATHX_16bT>::type  uint128_t;
typedef imp::uint_factory< MATHX_32bT>::type  uint256_t;
typedef imp::uint_factory< MATHX_64bT>::type  uint512_t;
typedef imp::uint_factory<MATHX_128bT>::type uint1024_t;
typedef imp::uint_factory<MATHX_256bT>::type uint2048_t;
typedef imp::uint_factory<MATHX_512bT>::type uint4096_t;

}

#endif // MATHX_TYPES_HPP
