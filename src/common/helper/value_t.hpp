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
** File:  value_t.hpp
**
** Purpose: common value between types
**
===========================================================*/

#ifndef MATHX_COMMON_HELPER_VALUE_T_HPP
#define MATHX_COMMON_HELPER_VALUE_T_HPP

namespace mathx
{
namespace imp
{

// value_t used to share value between types
template<typename type>
struct value_t
{
	const type& value;

	inline value_t<type>(const type& input) : value(input) {}
};

}
}

#endif // MATHX_COMMON_HELPER_VALUE_T_HPP
