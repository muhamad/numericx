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
** File:  alphnum_base.hpp
**
** Purpose: alphanumeric custom base
**
===========================================================*/

#ifndef MATHX_BASE_ALPHNUM_BASE_HPP
#define MATHX_BASE_ALPHNUM_BASE_HPP

namespace mathx
{
namespace imp
{

// A base with Arabic digits and English letters
template<cs_t bv,
		 typename charT = char,
		 template<typename> class letterT = letter_t,
		 typename customT = custom_t<true, true>,
		 bool is_in_range = (bv > 1 && bv < 37)
		>
struct alphanum_base;

// specialization for valid base number
template<cs_t bv, typename charT, template<typename> class letterT, typename customT>
struct alphanum_base<bv, charT, letterT, customT, true>
{
	typedef charT char_t;
	typedef letterT<charT> letter;
	typedef customT custom;

	static const cs_t base = bv;
	static const bool is_specialized = true;

	inline static bool check(char_t c)
	{
		if (bv < 10) return c >= char_t('0') && c <= char_t('0' + bv);

		return (c >= char_t('0') && c <= char_t('9')) ||
			   (c >= char_t('A') && c <= char_t('A' + bv - 10)) ||
			   (c >= char_t('a') && c <= char_t('a' + bv - 10));
	}

	inline static cs_t char_to_digit(char_t c)
	{
		if (c >= char_t('0') && c <= char_t('9')) return c - char_t('0');
		if (c >= char_t('A') && c <= char_t('Z')) return c - char_t('A') + 10;
		if (c >= char_t('a') && c <= char_t('z')) return c - char_t('a') + 10;

		return -1;
	}

	inline static char_t digit_to_char(cs_t n, bool upper)
	{
		if (n < 0 || n >= bv) return char_t(0);

		if (upper) return char_t("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n]);

		return char_t("0123456789abcdefghijklmnopqrstuvwxyz"[n]);
	}
};

}
}

#endif // MATHX_BASE_ALPHNUM_BASE_HPP
