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
** File:  int_ef.hpp
**
** Purpose: signed/unsigned integer with endian-free access.
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_INT_EF_hpp
#define MATHX_FRAMEWORK_INT_EF_hpp

namespace mathx
{
namespace test
{

struct int_ef
{
	typedef test_info::si_t     si;
	typedef test_info::ui_t     ui;
	typedef test_info::si_t::st st;
	typedef test_info::si_t::ut ut;

	static const cs_t count  = ui::meta::array_count;
	static const cs_t e_bit  = ui::meta::element_bits;

	ut arr[count];

	// convert to int_t
	inline operator si&() const { return *(si*)arr; }

	// convert to uint_t
	inline operator ui&() const { return *(ui*)arr; }

	// access element in endian-free manner
	inline ut operator[](cs_t index) const
	{
		if (meta::sys_info::is_big_endian)
			return arr[count - index - 1];
		else
			return arr[index];
	}
};

}
}

#endif // MATHX_FRAMEWORK_INT_EF_hpp
