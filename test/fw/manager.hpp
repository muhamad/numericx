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
** File:  manager.hpp
**
** Purpose: test manager
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_MANAGER_HPP
#define MATHX_FRAMEWORK_MANAGER_HPP

namespace mathx
{
namespace test
{

struct manager
{
	// add benchmark/unit test to collection
	template<typename type> inline static void add(type* value);

	// get number of registered benchmark/unit tests
	template<typename type> inline static cs_t get_count();

	// get benchmark/unit test at input index
	template<typename type> inline static type* at(cs_t index);

	// execute registered unit tests
	// return true if all cases executed successfully, false otherwise.
	inline static bool run_units();

	// execute registered benchmark tests
	// return overall execution duration.
	inline static duration run_speeds();

private:
	typedef std::vector<unit_test*> ut;
	typedef std::vector<speed_test*> st;

	inline static ut& get_ut() { static ut t; return t; }
	inline static st& get_st() { static st t; return t; }
};

#include "manager.inl"


}
}


#endif // MATHX_FRAMEWORK_MANAGER_HPP
