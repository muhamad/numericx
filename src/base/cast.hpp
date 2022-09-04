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
** File:  cast.hpp
**
** Purpose: conversion types to convert from/to mathx types
**
===========================================================*/

#ifndef MATHX_BASE_CAST_HPP
#define MATHX_BASE_CAST_HPP

///////////////////////
//    NUMERIC_CAST   //
///////////////////////
//
// numeric_cast is a template class with conversion operators to other types.
//
// every public numeric type in mathx will have an implementation to:
//  1) convert its type from/to c++ numeric native types. e.g. char, int, float.
//  2) convert its type from/to same type with different precision e.g: int128 from/to int512.
//  3) convert its type to other mathx numeric types e.g: int128 to uint256.
//
// numeric_cast for int_t/uint_t will never fail i.e. for sign will extended or most
// significant bits will be truncated.
//
// TODO: future float-point and fixed-point types explanation will be here.
//
// possible implementation for numeric_cast that convert from [int] to [float], [bool] and [unsigned int]
// should look like:
//
// template<>
// struct numeric_cast<int>
// {
//	  const int& value;
//
//	  numeric_cast<int>(const int& input) : value(input) {}
//
//	  operator float() const { return float(value); }
//
//	  operator unsigned int() const { return (unsigned int)value; }
//
//	  operator bool() const { return value != 0; }
// };
//
// int main()
// {
//     float        a = numeric_cast<int>(-1024); // -1024.0f
//     unsigned int b = numeric_cast<int>(-1024); // 0xFFFFFC00
//     bool         c = numeric_cast<int>(-1024); // true
// }
//

namespace mathx
{
// it: input type
template<typename it> struct numeric_cast;
}

/////////////////////////////
//    STRING CONVERSION    //
/////////////////////////////
//
// string_cast is used to convert any numeric type from/to any string type, however before describing it
// we need to discuss its pre-requests:
//
//  1. character information.
//    are characters used by common bases, such as hex-characters, float-point exponent-E and so on.
//	  these characters are encapsulated in letter_t class and used by predefined base2, base8, base10 and base16.
//
//	  if you did define a custom base then you only need to define some characters from letter_t:
//    float_e, float_E, comma, dot, plus, minus.
//
//    when implementing custom letter_t for predefined bases, there is 2 rules you must follow:
//    1) digits from 0 to 9 must be in sequence i.e. '0' + 3 = '3'.
//    2) hex digits from 'A' to 'F', and from 'a' to 'f' must be in sequence i.e. 'A' + 4 = 'D'.
//
//    if you ignore these rules predefined conversion using your custom letter_t will have unknown behaviour.
//
//  2. base information.
//     is used to define numeric base boundaries. by checking characters and converting them from/to their numeric value.
//     this information are encapsulated in base_t class.
//
//     mathx defined base2, base8, base10 and base16 for existed and new character types. however if you needed another base
//     we defined alpha-numeric base for you that represent digits from 0 to 9 and letters from a-z upper and lower, and to use
//     it all you need is to provide customization information which do 2 thing:
//     1) is your base can have a sign? e.g. base16 and base2 have no sign but base10 have.
//     2) is your base can display negative sign?
//
//     you answer these question throw custom_t class.
//     all above bases are simple bases which don't support complex letter grouping such existed in Latin numeral and for that
//     you need to create a class for you base that act a signature for it then write your own string_cast implementation.
//
//  string_cast takes string type and base type then provide you with 3 functions:
//				1- length: return number of character that represent numeric value.
//				2- from: convert string to integer.
//				3- to: convert integer to string. and there is two versions of it:
//					   one that ask you the character case you want the result string,
//					   the other version assume character case is lower characters.
//
//  if base didn't supplied for string_cast base10 will be used by default.
//

namespace mathx
{
// charT: character data-type
template<typename charT>
struct letter_t
{
	// character type
	typedef charT char_t;
	
	// character for number '0'
	static const char_t zero;
	// character for number '1' must be '0' + 1
	static const char_t one;
	// character for number '2' must be '0' + 2
	static const char_t two;
	// character for number '3' must be '0' + 3
	static const char_t three;
	// character for number '4' must be '0' + 4
	static const char_t four;
	// character for number '5' must be '0' + 5
	static const char_t five;
	// character for number '6' must be '0' + 6
	static const char_t six;
	// character for number '7' must be '0' + 7
	static const char_t seven;
	// character for number '8' must be '0' + 8
	static const char_t eight;
	// character for number '9' must be '0' + 9
	static const char_t nine;

	// hexadecimal lower character for number '10'
	static const char_t hex_a;
	// hexadecimal lower character for number '11' must be 'a' + 1
	static const char_t hex_b;
	// hexadecimal lower character for number '12' must be 'a' + 2
	static const char_t hex_c;
	// hexadecimal lower character for number '13' must be 'a' + 3
	static const char_t hex_d;
	// hexadecimal lower character for number '14' must be 'a' + 4
	static const char_t hex_e;
	// hexadecimal lower character for number '15' must be 'a' + 5
	static const char_t hex_f;

	// hexadecimal upper character for number '10'
	static const char_t hex_A;
	// hexadecimal upper character for number '11' must be 'A' + 1
	static const char_t hex_B;
	// hexadecimal upper character for number '12' must be 'A' + 2
	static const char_t hex_C;
	// hexadecimal upper character for number '13' must be 'A' + 3
	static const char_t hex_D;
	// hexadecimal upper character for number '14' must be 'A' + 4
	static const char_t hex_E;
	// hexadecimal upper character for number '15' must be 'A' + 5
	static const char_t hex_F;

	// scientific exponent lower letter 'e'
	static const char_t float_e;
	// scientific exponent upper letter 'E'
	static const char_t float_E;

	// character for comma ','
	static const char_t comma;
	// character for dot '.'
	static const char_t dot;
	// character for plus '+'
	static const char_t plus;
	// character for letter '-'
	static const char_t minus;

	// is character whitespace character
	inline static bool is_whitespace(char_t);
};

// base customization information
template<bool hs, bool ss>
struct custom_t
{
	// can plus/minus represented in this base?
	static const bool have_sign = hs;

	// show negative sign.
	// if [have_sign] is true then sign will be printed.
	static const bool show_sign = ss;
};

// bv: number of digits in base
// charT: character data-type, default is [char].
// letterT: letter information, input character type will be charT, default is [letter_t].
// customT: custom information about base, default is [custom_t].
template<cs_t bv, typename charT = char, template<typename> class letterT = letter_t, typename customT = custom_t<false, false> >
struct base_t
{
	// character type
	typedef charT char_t;
	// predefined letter information
	typedef letterT<charT> letter;
	// base customization information (not used for predefined bases)
	typedef customT custom;

	// base value
	static const cs_t base;
	// false for predefined types, true otherwise.
	static const bool is_specialized;

	// is input character belong to this base
	// return true if input character is in range, false otherwise.
	inline static bool check(const char_t);

	// get digit value from its character.
	// return value from 0 to base-1, -1 on failure.
	inline static cs_t char_to_digit(const char_t);

	// get character for input number.
	// d: digit to get equivalent character.
	// u: true for upper letter, false for lower letter.
	// return valid character or null character on failure.
	// note: this function ONLY called when input base is specialized.
	inline static char_t digit_to_char(const cs_t d, const bool u);
};

// num_type : MathX numeric type
// str_type : any string type
// base_type: base information, default is base10
template<typename num_type, typename str_type, typename base_type = base_t<10, typename meta::string_info<str_type>::char_t> >
struct string_cast
{
	// get number of character needed to store character-version of input number
	// return non-zero value
	// note: never include null-character in result length
	inline static cs_t length(const num_type& n);

	// convert input string to its numeric value
	// s: string to convert.
	// n: object to store result value in.
	// return true if conversion succeeded, false otherwise.
	// note: (1) if conversion fails n is intact.
	//		 (2) conversion should check for overflow.
	inline static bool from(const str_type& s, num_type& n);

	// convert numeric value to string
	// s: conversion result.
	// n: value to be converted.
	// return true if conversion succeeded, false otherwise.
	// note: (1) characters are lower by default.
	//		 (2) null character never appended.
	//		 (3) length of input string acquired from [length] function.
	//			 and this function DON'T check for buffer length, so
	//			 if length is shorter than needed a buffer overrun will occur.
	inline static bool to(str_type& s, const num_type& n);

	// convert numeric value to string
	// s: conversion result.
	// n: value to be converted.
	// upper: true to get upper letters, false for lower letters.
	// return true if conversion succeeded, false otherwise.
	// note: (1) null character never appended.
	//		 (2) length of input string acquired from [length] function.
	//			 and this function DON'T check for buffer length, so
	//			 if length is shorter than needed a buffer overrun will occur.
	inline static bool to(str_type& s, const num_type& n, bool upper);
};

}

#endif // MATHX_BASE_CAST_HPP
