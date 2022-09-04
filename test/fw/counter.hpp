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
** File:  counter.hpp
**
** Purpose: time measurement
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_COUNTER_HPP
#define MATHX_FRAMEWORK_COUNTER_HPP

namespace mathx
{
namespace test
{

// type to hold milliseconds, must be unsigned 32-bits
// can represent interval with maximum length:
// 49 days, 17 hours, 2 minutes, 47 seconds and 295 milliseconds.
typedef mxi::uint_from_size<32>::t milli_t;

// time interval for duration
struct interval
{
	// number of millisecond per day
	static const milli_t milli_per_day    = 24 * 60 * 60 * 1000;
	// number of millisecond per hour
	static const milli_t milli_per_hour   = 60 * 60 * 1000;
	// number of millisecond per minute
	static const milli_t milli_per_minute = 60 * 1000;
	// number of millisecond per second
	static const milli_t milli_per_second = 1000;
};

// timer duration information
struct duration
{
	// initialize duration with zero
	inline duration() : total(0), all(0) {}

	// initialize duration with specified values
	inline duration(milli_t d, milli_t h, milli_t m, milli_t s, milli_t mi)
	{
		e.days    = d;
		e.hours   = h;
		e.minutes = m;
		e.seconds = s;
		e.milliseconds = mi;

		total = mi + (s * interval::milli_per_second) + (m * interval::milli_per_minute)
				   + (h * interval::milli_per_hour) + (d * interval::milli_per_day);
	}

	// initialize duration with total milliseconds
	inline duration(milli_t all) : total(all)
	{
		e.days = all / interval::milli_per_day;
		all %= interval::milli_per_day;

		e.hours = all / interval::milli_per_hour;
		all %= interval::milli_per_hour;

		e.minutes = all / interval::milli_per_minute;
		all %= interval::milli_per_minute;

		e.seconds = all / interval::milli_per_second;
		all %= interval::milli_per_second;

		e.milliseconds = all;
	}

	// get total number of milliseconds in duration
	inline milli_t get_total_milliseconds() const { return total; }

	// get number of days in duration
	inline milli_t get_days() const { return e.days; }

	// get number of hours in duration
	inline milli_t get_hours() const { return e.hours; }

	// get number of minutes in duration
	inline milli_t get_minutes() const { return e.minutes; }

	// get number of seconds in duration
	inline milli_t get_seconds() const { return e.seconds; }

	// get number of milliseconds in duration
	inline milli_t get_milliseconds() const { return e.milliseconds; }

	// add duration to this
	inline duration& add(const duration& d) { return * new (this) duration(total + d.total); }

	// subtract duration from this
	inline duration& sub(const duration& d) { return * new (this) duration(total - d.total); }

	// add/subtract with operators
	inline duration& operator+=(const duration& d) { return add(d); }
	inline duration& operator-=(const duration& d) { return sub(d); }

	inline friend duration operator+(const duration& lh, const duration& rh) { duration d(lh); return d.add(rh); }
	inline friend duration operator-(const duration& lh, const duration& rh) { duration d(lh); return d.sub(rh); }

	// compare duration
	inline friend bool operator ==(const duration& lh, const duration& rh) { return lh.total == rh.total; }
	inline friend bool operator !=(const duration& lh, const duration& rh) { return lh.total != rh.total; }
	inline friend bool operator  >(const duration& lh, const duration& rh) { return lh.total  > rh.total; }
	inline friend bool operator >=(const duration& lh, const duration& rh) { return lh.total >= rh.total; }
	inline friend bool operator  <(const duration& lh, const duration& rh) { return lh.total  < rh.total; }
	inline friend bool operator <=(const duration& lh, const duration& rh) { return lh.total <= rh.total; }

private:
	// total milliseconds
	milli_t total;

	// milliseconds as units
	union
	{
	milli_t all;
	struct
	{
		milli_t days:5;
		milli_t hours:5;
		milli_t minutes:6;
		milli_t seconds:6;
		milli_t milliseconds:10;
	} e;
	};
};

// counter class
template<typename type>
struct counter_t : public type
{
	// is type can calculate milliseconds?
	inline static bool is_valid() { return type::is_valid(); }

	// get counter name
	inline static const char* name() { return type::name(); }

	// call base constructor
	inline counter_t<type>() : type() {}

	// start count
	inline void start() { type::start(); }

	// stop count
	inline void stop() { type::stop(); }

	// reset counter
	inline void reset() { return type::reset(); }

	// check counter status
	inline bool is_running() const { return type::is_running(); }

	// get duration
	inline duration get() const { return type::get(); }

	// get total milliseconds.
	inline milli_t get_milliseconds() const { return type::get_milliseconds(); }
};

//
// Next types should be used in the future where an algorithm have time estimation
// then we should save it using these types.
//

// convert time to milliseconds using days to milliseconds
template<milli_t d, milli_t h, milli_t m, milli_t s, milli_t mi>
struct time_to_milli
{
	static const milli_t value = mi + (s * interval::milli_per_second)
								 + (m * interval::milli_per_minute)
								 + (h * interval::milli_per_hour)
								 + (d * interval::milli_per_day);
};

// convert time to milliseconds using hours to milliseconds
template<milli_t h, milli_t m, milli_t s, milli_t mi>
struct time_to_milli<0, h, m, s, mi>
{
	static const milli_t value = mi + (s * interval::milli_per_second)
								 + (m * interval::milli_per_minute)
								 + (h * interval::milli_per_hour);
};

// convert time to milliseconds using minutes to milliseconds
template<milli_t m, milli_t s, milli_t mi>
struct time_to_milli<0, 0, m, s, mi>
{
	static const milli_t value = mi + (s * interval::milli_per_second) + (m * interval::milli_per_minute);
};

// convert time to milliseconds using seconds and milliseconds
template<milli_t s, milli_t mi>
struct time_to_milli<0, 0, 0, s, mi>
{
	static const milli_t value = mi + (s * interval::milli_per_second);
};

}
}


#endif // MATHX_FRAMEWORK_COUNTER_HPP
