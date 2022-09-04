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
** File:  string_helper.hpp
**
** Purpose: string helper functions
**
===========================================================*/

#ifndef MATHX_COMMON_HELPER_STRING_HELPER_HPP
#define MATHX_COMMON_HELPER_STRING_HELPER_HPP

namespace mathx
{
namespace mxi
{

// swap characters in range
template<typename char_t>
inline void string_swap(char_t* str, cs_t from, cs_t length)
{
	// last index
	cs_t to = from + length - 1;
	// fast division by 2
	length >>= 1;

	// do swap
	while(length--)
	{
		char_t c = str[from];
		str[from++] = str[to];
		str[to--] = c;
	}
}

}
}

#endif // MATHX_COMMON_HELPER_STRING_HELPER_HPP
