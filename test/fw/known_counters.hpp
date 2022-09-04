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
** File:  known_counters.hpp
**
** Purpose: predefined counters
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_KNOWN_COUNTERS_HPP
#define MATHX_FRAMEWORK_KNOWN_COUNTERS_HPP

namespace mathx
{
namespace test
{

#if defined(MATHX_USES_WINDOWS_COUNTER)

// your compiler should link to windows library by default
// GetTickCount used instead of GetTickCount64 for platform portability
extern "C" unsigned __stdcall GetTickCount(void);

struct windows_counter
{
	inline static const char* name() { return "Windows API"; }

	inline static bool is_valid() { return true; }

	inline windows_counter() : d(0), r(false) {}

	inline void start()
	{
		r = true;
		d = GetTickCount();
	}

	inline void stop()
	{
		milli_t e = GetTickCount();

		// check for time wrap
		if (e < d)
		{
			d -= e;
			e = milli_t(~0);
		}

		d = e - d;
		r = false;
	}

	inline void reset()
	{
		d = 0;
		r = false;
	}

	inline bool is_running() const { return r; }

	inline duration get() const { return duration(d); }

	inline milli_t get_milliseconds() const { return d; }

private:
	milli_t d;
	bool r;
};

typedef counter_t<windows_counter> counter;

#elif defined(MATHX_USES_POSIX_COUNTER)

struct posix_counter
{
	static const clock_t ratio = CLOCKS_PER_SEC / 1000;

	inline static const char* name() { return "POSIX API"; }

	inline static bool is_valid() { return ratio > 0 && clock() != clock_t(-1); }

	inline posix_counter() : d(0), r(false) {}

	inline void start()
	{
		r = true;
		d = clock();
	}

	inline void stop()
	{
		clock_t e = clock();

		// check for time wrap
		if (e < d)
		{
			d -= e;
			e = clock_t(~0);
		}

		d = (e - d) / ratio;
		r = false;
	}

	inline bool is_running() const { return r; }

	inline duration get() const { return duration(d); }

	inline milli_t get_milliseconds() const { return d; }

	inline void reset()
	{
		d = 0;
		r = false;
	}

private:
	clock_t d;
	bool r;
};

typedef counter_t<posix_counter> counter;

#elif defined(MATHX_USES_CLOCK_COUNTER)

struct clock_counter
{
	static const clock_t ratio = CLOCKS_PER_SEC / 1000;

	inline static const char* name() { return "C/C++ API"; }

	inline static bool is_valid() { return ratio > 0 && clock() != clock_t(-1); }

	inline clock_counter() : d(0), r(false) {}

	inline void start()
	{
		r = true;
		d = clock();
	}

	inline void stop()
	{
		const clock_t tmp = clock();
		d = (tmp - d) / ratio;
		r = false;
	}

	inline bool is_running() const { return r; }

	inline duration get() const { return duration(d); }

	inline milli_t get_milliseconds() const { return d; }

	inline void reset()
	{
		d = 0;
		r = false;
	}

private:
	clock_t d;
	bool r;
};

typedef counter_t<clock_counter> counter;

#endif

}
}


#endif // MATHX_FRAMEWORK_KNOWN_COUNTERS_HPP
