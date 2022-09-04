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
** File:  utility.hpp
**
** Purpose: test support function/types.
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_UTILITY_HPP
#define MATHX_FRAMEWORK_UTILITY_HPP

namespace mathx
{
namespace test
{

struct random
{

// generate random value in input value
template<typename t>
inline static void get(t& value, cs_t from, cs_t count)
{
	// std::rand returns int
	int* arr = (int*)&value.comp[from];

	const cs_t len = (sizeof(typename t::ut) * count) / sizeof(int);

	for (cs_t i=0; i<len; ++i)
	{
		std::clock_t c = std::clock();
		while( c == std::clock() );
		std::srand( ((unsigned int)std::time(NULL) + (unsigned int)std::clock()) );

		arr[i] = std::rand();
		arr[i] *= arr[i] * ((i+1) << 1);
	}
}

// generate random value in input value
template<typename t>
inline static void get(t& value)
{
	return get(value, 0, t::meta::array_count);
}


};


}
}


#endif // MATHX_FRAMEWORK_UTILITY_HPP
