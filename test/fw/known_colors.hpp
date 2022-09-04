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
** File:  known_colors.hpp
**
** Purpose: predefined terminal colors
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_KNOWN_COLORS_HPP
#define MATHX_FRAMEWORK_KNOWN_COLORS_HPP

namespace mathx
{
namespace test
{

#ifdef MATHX_NO_COLORS

struct no_colors
{
	inline static const char* name() { return "no colors"; }
	inline static void reset() {}
	inline static void set_color(color, bright, place) {}
};

typedef ccolor_t<no_colors> ccolor;

#elif defined(MATHX_USES_WINDOWS_COLORS)

extern "C"
{
	struct CSBI
	{
		unsigned long long whatever;
		unsigned short attributes;
		unsigned long long  window;
		unsigned max_window_size;
	};

	void* __stdcall GetStdHandle(int hStd);
	bool  __stdcall GetConsoleScreenBufferInfo(void* hConsoleOutput, CSBI* lpCSBI);
	bool  __stdcall SetConsoleTextAttribute(void* hConsoleOutput, unsigned short wAttributes);
}

struct windows_cc
{
	inline static const char* name() { return "Windows API"; }

	inline static void reset()
	{
		pdata& p = pdata::get();
		SetConsoleTextAttribute(p.handle, p.attrib);
	}

	inline static void set_color(color c, bright b, place p)
	{
		unsigned short attrib = (unsigned short)c;

		if (b == yes) attrib |= 0x8;
		if (p == back) attrib <<= 4;

		SetConsoleTextAttribute(pdata::get().handle, attrib);
	}

	struct pdata
	{
		void* handle;
		unsigned short attrib;

		inline pdata()
		{
			handle = GetStdHandle(-11);

			CSBI tmp;
			GetConsoleScreenBufferInfo(handle, &tmp);
			attrib = tmp.attributes;
		}

		inline static pdata& get()
		{
			static pdata data;
			return data;
		}
	};
};

typedef ccolor_t<windows_cc> ccolor;

#elif defined(MATHX_USES_ANSI_COLORS)

#define MATHX_ANSI_CC(C) "\x1b[" #C "m"

struct ansi_cc
{
	inline static const char* name() { return "ANSI colors"; }

	inline static void reset() { std::cout << "\x1B[0m"; }

	inline static void set_color(color c, bright b, place p)
	{
		static const char* arr[] = {"\x1B[0m", "\x1B[1m"};

		static const char* colors[][8] =
		{
			{
				MATHX_ANSI_CC(30), MATHX_ANSI_CC(34), MATHX_ANSI_CC(32), MATHX_ANSI_CC(36),
				MATHX_ANSI_CC(31), MATHX_ANSI_CC(35), MATHX_ANSI_CC(33), MATHX_ANSI_CC(37)
			},
			{
				MATHX_ANSI_CC(40), MATHX_ANSI_CC(44), MATHX_ANSI_CC(42), MATHX_ANSI_CC(46),
				MATHX_ANSI_CC(41), MATHX_ANSI_CC(45), MATHX_ANSI_CC(43), MATHX_ANSI_CC(47)
			}
		};
		
		std::cout << arr[b] << colors[p][c];
	}
};

#undef MATHX_ANSI_CC

typedef ccolor_t<ansi_cc> ccolor;

#endif

}
}


#endif // MATHX_FRAMEWORK_KNOWN_COLORS_HPP
