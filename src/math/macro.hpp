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
** File:  macros.hpp
**
** Purpose: macros used by mathematical library
**
===========================================================*/

#ifndef MATHX_MATH_MACROS_HPP
#define MATHX_MATH_MACROS_HPP

#define MATHX_DCL_INT_T_TEMPLATE \
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t, \
		 template <typename> class range_t, template <typename> class bitwise_t, \
		 template <typename> class logic_t, template <typename> class arithmetic_t, \
		 template <typename> class meta_t>


#define MATHX_DEF_INT_T_TYPE \
	int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>


#define MATHX_DCL_UINT_T_TEMPLATE \
template<cu_t bits_count, typename ut_t, typename udt_t, \
	template <typename> class range_t, template <typename> class bitwise_t, \
	template <typename> class logic_t, template <typename> class arithmetic_t, \
	template <typename> class meta_t>


#define MATHX_DEF_UINT_T_TYPE \
	uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>


#endif // MATHX_MATH_MACROS_HPP
