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
** File:  predefined.hpp
**
** Purpose: predefined conversion-helper types
**
===========================================================*/

#ifndef MATHX_CAST_PREDEFINED_HPP
#define MATHX_CAST_PREDEFINED_HPP

namespace mathx
{
namespace imp
{

// base class for standard letter_t specialization
template<typename charT>
struct predefined_letter_t
{
	typedef charT char_t;
	
	static const char_t zero  = char_t('0');
	static const char_t one   = char_t('1');
	static const char_t two   = char_t('2');
	static const char_t three = char_t('3');
	static const char_t four  = char_t('4');
	static const char_t five  = char_t('5');
	static const char_t six   = char_t('6');
	static const char_t seven = char_t('7');
	static const char_t eight = char_t('8');
	static const char_t nine  = char_t('9');

	static const char_t hex_a = char_t('a');
	static const char_t hex_b = char_t('b');
	static const char_t hex_c = char_t('c');
	static const char_t hex_d = char_t('d');
	static const char_t hex_e = char_t('e');
	static const char_t hex_f = char_t('f');

	static const char_t hex_A = char_t('A');
	static const char_t hex_B = char_t('B');
	static const char_t hex_C = char_t('C');
	static const char_t hex_D = char_t('D');
	static const char_t hex_E = char_t('E');
	static const char_t hex_F = char_t('F');

	static const char_t float_e = char_t('e');
	static const char_t float_E = char_t('E');

	static const char_t comma = char_t(',');
	static const char_t dot   = char_t('.');
	static const char_t plus  = char_t('+');
	static const char_t minus = char_t('-');

	// order based on common use character
	inline static bool is_whitespace(char_t c)
	{ return (c == char_t(' ') || c == char_t('\t') || c == char_t('\v') || c == char_t('\r') || c == char_t('\f')); }
};

// base class for standard base_t specialization
template<cs_t bv, typename charT, template<typename> class letterT>
struct predefined_base_t
{
	typedef charT char_t;
	typedef letterT<charT> letter;
	typedef custom_t<false, false> custom;

	static const cs_t base = bv;
	static const bool is_specialized = !(bv == 2 || bv == 8 || bv == 10 || bv == 16);

	inline static bool is_hex(char_t c)
	{
		return c |= char_t(0x20), c >= letter::hex_a && c <= letter::hex_f;
	}

	inline static bool check(char_t c)
	{
		if (base == 2)
			return (c == letter::zero || c == letter::one);
		else
		if (base == 8)
			return (c >= letter::zero && c <= letter::seven);
		else
		if (base == 10)
			return (c >= letter::zero && c <= letter::nine);
		else
		if (base == 16)
			return (c >= letter::zero && c <= letter::nine) || is_hex(c);

		return false;
	}

	inline static cs_t char_to_digit(char_t c)
	{
		if (base == 2)
		{
			if (c == letter::zero || c == letter::one) return c - letter::zero;
		}
		else
		if (base == 8)
		{
			if (c >= letter::zero && c <= letter::seven) return c - letter::zero;
		}
		else
		if (base == 10)
		{
			if (c >= letter::zero && c <= letter::nine) return c - letter::zero;
		}
		else
		if (base == 16)
		{
			if (c >= letter::zero && c <= letter::nine) return c - letter::zero;
			if (c >= letter::hex_A && c <= letter::hex_F) return c - letter::hex_A + 10;
			if (c >= letter::hex_a && c <= letter::hex_f) return c - letter::hex_a + 10;
		}

		return -1;
	}

	inline static char_t digit_to_char(cs_t d, bool u)
	{
		if (d >= 0  && d <=  9) return char_t(letter::zero + d);
		if (d >= 10 && d <= 15) return char_t((u? letter::hex_A: letter::hex_a) + d - 10);

		return char_t(0);
	}
};

}

// letter_t for char type
template<> struct letter_t<char> : public imp::predefined_letter_t<char> {};

// letter_t for wchar type
template<> struct letter_t<wchar_t> : public imp::predefined_letter_t<wchar_t> {};

// base2 partial specialization
template <typename charT> struct base_t<2, charT> : public imp::predefined_base_t<2, charT, letter_t> {};

// base8 partial specialization
template <typename charT> struct base_t<8, charT> : public imp::predefined_base_t<8, charT, letter_t> {};

// base10 partial specialization
template <typename charT> struct base_t<10, charT> : public imp::predefined_base_t<10, charT, letter_t> {};

// base16 partial specialization
template <typename charT> struct base_t<16, charT> : public imp::predefined_base_t<16, charT, letter_t> {};

}

#endif // MATHX_CAST_PREDEFINED_HPP
