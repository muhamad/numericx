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
** File:  stream.hpp
**
** Purpose: output data to stream
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_STREAM_HPP
#define MATHX_FRAMEWORK_STREAM_HPP

namespace mathx
{
namespace test
{

// framework internals
namespace ti
{
// color information
struct color_info
{
	const color  c;
	const bright b;
	const place  p;
	inline color_info(color cc, bright bb, place pp) : c(cc), b(bb), p(pp) {}
};

// holds a value to write to stream
template<typename t>
struct out_t
{
	const t value;
	inline out_t(const t input) : value(input) {}
};

template<typename t>
struct out_t<t&>
{
	const t& value;
	inline out_t(const t& input) : value(input) {}
};
}

// write duration to stream
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& operator << (std::basic_ostream<char_t, traits_t>& stm, const duration& d)
{
	bool print = false;
	bool at_least_one = false;

	if(d.get_days() > 0)
	{
		print = true;
		at_least_one = true;
		stm << "days: " << d.get_days();
	}
	
	if(print || (!test_info::show_all_duration_parts && d.get_hours() > 0))
	{
		if (print) stm << ", ";
		at_least_one = true;

		print = true;
		stm << "hours: " << d.get_hours();
	}

	if(print || (!test_info::show_all_duration_parts && d.get_minutes() > 0))
	{
		if (print) stm << ", ";
		at_least_one = true;

		print = true;
		stm << "minutes: " << d.get_minutes();
	}
	
	if(print || (!test_info::show_all_duration_parts && d.get_seconds() > 0))
	{
		if (print) stm << ", ";
		at_least_one = true;

		print = true;
		stm << "seconds: " << d.get_seconds();
	}

	if (!at_least_one || (!test_info::show_all_duration_parts && d.get_milliseconds() > 0))
	{
		if (print) stm << ", ";
		stm << "milliseconds: " << d.get_milliseconds();
	}

	return stm;
}

// set standard output text colors
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& operator << (std::basic_ostream<char_t, traits_t>& stm, const ti::color_info& ci)
{
	ccolor::set_color(ci.c, ci.b, ci.p);
	return stm;
}

// reset standard output colors
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& resetc(std::basic_ostream<char_t, traits_t>& stm)
{
	ccolor::reset();
	return stm;
}

// write date/time to stream
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& operator << (std::basic_ostream<char_t, traits_t>& stm, const date_time& dt)
{
	static const char* mon[] = { "January", "February", "March", "April", "May", "June", 
								 "July", "August", "September", "October", "November", "December" };
	static const char* day[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	static const char* tmz[] = { "AM", "PM" };

	stm << day[dt.week_day] << ", " << mon[dt.month - 1] << " " << dt.day << ", " << dt.year << " ";

	char c[3] = {'0', '0', 0};
	int tmz_idx = 0;

	if (dt.hour == 0) stm << "12";
	else
	{
		dt_t hour = dt.hour;

		if (hour == 12)
			tmz_idx = 1;
		if (hour > 12)
		{
			tmz_idx = 1;
			hour -= 12;
		}

		c[0] = (hour > 9)? '1': '0';
		c[1] = char('0' + hour % 10);
		stm << c;
	}
	stm << ':';

	c[0] = char('0' + dt.minute / 10);
	c[1] = char('0' + dt.minute % 10);
	stm << c << ':';
	
	c[0] = char('0' + dt.second / 10);
	c[1] = char('0' + dt.second % 10);
	stm << c << ' ' << tmz[tmz_idx];

	return stm;
}

// write boolean to stream
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& operator << (std::basic_ostream<char_t, traits_t>& stm, const ti::out_t<bool>& o)
{
	stm << std::boolalpha << o.value << std::noboolalpha;
	return stm;
}

// write line breaks into stream
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& operator << (std::basic_ostream<char_t, traits_t>& stm, const ti::out_t<int>& o)
{
	for (int i=0; i<o.value; ++i) stm << '\n';
	return stm;
}

// write name
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& operator << (std::basic_ostream<char_t, traits_t>& stm, const ti::out_t<std::string&>& s)
{
	stm << '\'' << s.value << '\'';
	return stm;
}

// manipulator to set foreground color
inline ti::color_info forec(const color& c, const bright& b)
{
	return ti::color_info(c, b, front);
}

// manipulator to set background color
inline ti::color_info backc(const color& c, const bright& b)
{
	return ti::color_info(c, b, back);
}

// manipulator to write boolean string
inline ti::out_t<bool> write(const bool value)
{
	return ti::out_t<bool>(value);
}

// write line breaks
inline ti::out_t<int> lnbks(const int count)
{
	return ti::out_t<int>(count);
}

// manipulator to write string
inline ti::out_t<std::string&> write(const std::string& name)
{
	return ti::out_t<std::string&>(name);
}

// get current local date/time
inline date_time get_dt()
{
	time_t t = time(NULL);
	std::tm& tt = *std::localtime(&t);

	return date_time(dt_t(tt.tm_year + 1900), dt_t(tt.tm_mon + 1),
					 dt_t(tt.tm_mday), dt_t(tt.tm_hour), dt_t(tt.tm_min), dt_t(tt.tm_sec > 59? 59: tt.tm_sec),
					 dt_t(tt.tm_wday));
}



// set information color to standard output
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& info(std::basic_ostream<char_t, traits_t>& stm)
{
	cout << forec(green, yes);
	return stm;
}

// set hint color to standard output
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& hint(std::basic_ostream<char_t, traits_t>& stm)
{
	cout << forec(magenta, yes);
	return stm;
}

// set warning color to standard output
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& warning(std::basic_ostream<char_t, traits_t>& stm)
{
	cout << forec(yellow, yes);
	return stm;
}

// set error color to standard output
template<typename char_t, typename traits_t> inline
std::basic_ostream<char_t, traits_t>& error(std::basic_ostream<char_t, traits_t>& stm)
{
	cout << forec(red, yes);
	return stm;
}


}
}

#endif // MATHX_FRAMEWORK_STREAM_HPP
