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
** File:  common.hpp
**
** Purpose: various types used by test framework
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_COMMON_HPP
#define MATHX_FRAMEWORK_COMMON_HPP

namespace mathx
{
namespace test
{

// date/time data-type size must be unsigned 16-bits
typedef mxi::uint_from_size<16>::t dt_t;

// date/time information
struct date_time
{
	dt_t year:12;  // 1 - 4095
	dt_t month:4;  // 1 - 12
	dt_t day:5;    // 1 - 31
	dt_t hour:5;   // 0 - 23
	dt_t minute:6; // 0 - 59
	dt_t second:6; // 0 - 59

	dt_t week_day:3; // 0-6 where 0=Sunday ...

	inline date_time() : year(1), month(1), day(1), hour(0), minute(0), second(0), week_day(0) {}
	inline date_time(dt_t y, dt_t m, dt_t d, dt_t h, dt_t mi, dt_t s, dt_t wd)
		: year(y), month(m), day(d), hour(h), minute(mi), second(s), week_day(wd) {}
};

// link name to object
struct name_t
{
	// initialization
	inline name_t(const std::string& n) : name(n) {}

	// get name
	inline const std::string& get_name() const { return name; }

protected:
	const std::string name;
};

}
}


#endif // MATHX_FRAMEWORK_COMMON_HPP
