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
** File:  color.hpp
**
** Purpose: terminal color
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_COLOR_HPP
#define MATHX_FRAMEWORK_COLOR_HPP

namespace mathx
{
namespace test
{

// terminal colors
enum color
{
	// black color
	black = 0,
	// blue color
	blue = 1,
	// green color
	green = 2,
	// cyan color
	cyan = 3,
	// red color
	red = 4,
	// magenta color
	magenta = 5,
	// yellow color
	yellow = 6,
	// white color
	white = 7
};

// terminal color bright
enum bright
{
	// use color standard bright
	no = 0,
	// use a bright color
	yes = 1
};

// location to apply color into
enum place
{
	// apply to foreground
	front = 0,
	// apply to background
	back = 1
};

// terminal color class
template<typename type>
struct ccolor_t
{
	// get color-type name
	inline static const char* name() { return type::name(); }

	// set foreground/background colors to default state
	inline static void reset() { type::reset(); }

	// set color attributes
	inline static void set_color(color c, bright b = no, place p = front) { type::set_color(c, b, p); }
};

}
}

#endif // MATHX_FRAMEWORK_COLOR_HPP
