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
** File:  cth.hpp
**
** Purpose: compile-time helper types
**
===========================================================*/

#ifndef MATHX_COMMON_HELPER_CTH_HPP
#define MATHX_COMMON_HELPER_CTH_HPP

namespace mathx
{
namespace mxi
{

// get size of type in bits corresponding to MATHX_BIT.
// t: type name.
template<typename t>
struct isizeof
{
	static const ts_t value = sizeof(t) * MATHX_BIT;
};

// detect if input number is a power of 2.
// val: integer literal.
template<tu_t val>
struct is_power_of_2
{
	static const bool value = !(val & (val - 1));
};

// detect if input number is an even number.
// val: integer literal.
template<tu_t val>
struct is_even
{
	static const bool value = (val % 2) == 0;
};

// divide input value by two
// val: input value
template<ts_t val>
struct div_by_two
{
	static const ts_t value = (val >> 1);
};

// multiply input value by two
// val: input value
template<ts_t val>
struct mul_by_two
{
	static const ts_t value = (val << 1);
};

// get base2 logarithm for unsigned integer literal.
// val: integer literal to get its log2.
template<tu_t val>
struct log2_for_literal
{
	static const ts_t value = 1 + log2_for_literal< (val >> 1) >::value;
};
template<> struct log2_for_literal<1> { static const ts_t value = 0; };

// get base2 logarithm for type.
// t: type name.
template<typename t>
struct log2_for_type
{
	static const ts_t value = isizeof<t>::value - 1;
};

// get base10 logarithm for type.
// t: type name.
template<typename t>
struct log10_for_type
{
	static const ts_t value = ts_t( ((meta::info_t<t>::num_of_bits - (meta::info_t<t>::is_signed? 1: 0)) * 1233) >> 12);
};

// get 10 to power.
// t: type to hold the result.
// p: the power.
template<typename t, tu_t p>
struct power10_for_type_helper
{
	static const t value = 10 * power10_for_type_helper<t, p - 1>::value;
};
template<typename t> struct power10_for_type_helper<t, 0> { static const t value = 1; };

// get maximum 10 to power that can be saved in unsigned type [t].
// t: type to hold the result, must be native unsigned integral type.
template<typename t>
struct power10_for_type
{
	static const t value = power10_for_type_helper<t, log10_for_type<t>::value>::value;
};

// get 10 to power in range from 0 maximum power uintL can hold.
// p: power to raise 10 to.
template<tu_t p>
struct power10_for_value
{
	static const tu_t value = power10_for_type_helper<tu_t, p>::value;
};

// get base10 logarithm for unsigned integer literal.
// val: integer literal to get its log10.
template<tu_t val>
struct log10_for_literal
{
private:
	// partial value
	static const ts_t pvalue = ts_t( ((log2_for_literal<val>::value + 1) * 1233) >> 12);
public:
	static const ts_t value = pvalue - ts_t(val < power10_for_value<pvalue>::value);
};

// get number of binary digits in integer literal.
// val: integer literal.
template<tu_t val>
struct num_of_bin_digits_in_value
{
	static const ts_t value = log2_for_literal<val>::value + 1;
};

// get number of binary digits can stored inside input type.
// t: type name.
template<typename t>
struct num_of_bin_digits_in_type
{
	static const ts_t value = meta::info_t<t>::num_of_bits;
};

// get number of hexadecimal digits in integer literal.
// val: integer literal.
template<tu_t val>
struct num_of_hex_digits_in_value
{
private:
	static const ts_t pvalue = log2_for_literal<val>::value + 1;
public:
	static const ts_t value = (pvalue >> 2) + ts_t(!!(pvalue % 4));
};

// get number of hexadecimal digits can stored inside input type.
// t: type name.
template<typename t>
struct num_of_hex_digits_in_type
{
	static const ts_t value = num_of_bin_digits_in_type<t>::value / 4;
};

// get number of octal digits in integer literal.
// val: integer literal.
template<tu_t val>
struct num_of_oct_digits_in_value
{
private:
	static const ts_t pvalue = log2_for_literal<val>::value + 1;
public:
	static const ts_t value = (pvalue / 3) + ts_t(!!(pvalue % 3));
};

// get number of octal digits can stored inside input type.
// t: type name.
template<typename t>
struct num_of_oct_digits_in_type
{
	static const ts_t value = (num_of_bin_digits_in_type<t>::value / 3) + 1;
};

// get number of decimal digits in integer literal.
// val: integer literal.
template<tu_t val>
struct num_of_dec_digits_in_value
{
	static const ts_t value = log10_for_literal<val>::value + 1;
};

// get number of decimal digits can stored inside input type.
// t: type name.
template<typename t>
struct num_of_dec_digits_in_type
{
	static const ts_t value = log10_for_type<t>::value + 1;
};

// get number of base digits that can be stored in type with input size.
// type_size: number of bits in type to store base digits, must be a power of 2.
// base: base value, must be between 2 and maximum value can be stored in type with type_size.
// NOTE: the smaller the base the less accurate the computed value.
//       less accurate as in more digits. for power of 2 bases computed result is accurate.
template<tu_t type_size, tu_t base>
struct num_of_base_digits_in_type
{
	static const ts_t value = ts_t(type_size / log2_for_literal<base>::value) + 1;
};

// partial specialization to provide accurate result for base3
template<tu_t size>
struct num_of_base_digits_in_type<size, 3>
{
private:
	static const ts_t pvalue = num_of_base_digits_in_type<size, 2>::value;
public:
	static const ts_t value =  pvalue - ts_t(pvalue / 2.7);
};

// get value of left-most digit in octal base for input size.
// val: size of type in bits, size must be a multiple of 2 to for valid result.
template<tu_t val>
struct left_most_octal_digit_for_value
{
	static const ts_t value = (is_power_of_2<val>::value)? (((val % 3) & 1)? 1: 3): 0;
	//static const ts_t value = (is_power_of_2<val>::value)? (is_even< log2_for_literal<val>::value >::value? 1: 3) : 0;
};

// get value of left-most digit in octal base for type.
// t: type name, its size must be multiple of 2 to get valid result.
template<typename t>
struct left_most_octal_digit_for_type
{
	static const ts_t value = left_most_octal_digit_for_value< isizeof<t>::value >::value;
};

// get number of bits remained in type that can't form octal digit
template<typename t>
struct octal_remain_digit_bits_in_type
{
	static const ts_t value = num_of_bin_digits_in_value< left_most_octal_digit_for_type<t>::value >::value;
};

// set least significant bits for half type size to ones.
// t: unsigned type
template<typename t>
struct fill_type_least_half_bits
{
	static const t value = t(~0) >> (isizeof<t>::value >> 1);
};

// set most significant bits for half type size to ones.
// t: unsigned type
template<typename t>
struct fill_type_most_half_bits
{
	static const t value = ~ (fill_type_least_half_bits<t>::value);
};

// get number of bits occupied for sign in IEEE compatible float-point type.
// size: type size in bits.
template<tu_t size>
struct float_sign_size
{
	static const ts_t value = 1;
};

// get number of bits occupied for exponent in IEEE compatible float-point type.
// size: type size in bits.
template<tu_t size>
struct float_exponent_size
{
	static const ts_t value = (4 * log2_for_literal<size>::value) - 13;
};
template<> struct float_exponent_size<16> { static const ts_t value = 5; };
template<> struct float_exponent_size<32> { static const ts_t value = 8; };


// get number of bits occupied for mantissa in IEEE compatible float-point type.
// size: type size in bits.
template<tu_t size>
struct float_mantissa_size
{
public:
	static const ts_t value = size - float_sign_size<size>::value - float_exponent_size<size>::value;
};

// get number of bits represent precision in IEEE compatible float-point type.
// size: type size in bits.
template<tu_t size>
struct float_precision_size
{
	static const ts_t value = float_mantissa_size<size>::value + float_sign_size<size>::value;
};

// get maximum exponent in IEEE compatible float-point type.
// size: type size in bits.
template<tu_t size>
struct float_emax_value
{
	static const tu_t value = (tu_t(1) << (float_exponent_size<size>::value - 1)) - 1;
};

// get signed-integer type from input size
template <tu_t value> struct int_from_size;
template<> struct int_from_size< isizeof< int8_t>::value > { typedef int8_t  t; };
template<> struct int_from_size< isizeof<int16_t>::value > { typedef int16_t t; };
template<> struct int_from_size< isizeof<int32_t>::value > { typedef int32_t t; };
template<> struct int_from_size< isizeof<int64_t>::value > { typedef int64_t t; };

// get unsigned-integer type from input size
template <tu_t value> struct uint_from_size;
template<> struct uint_from_size< isizeof< uint8_t>::value > { typedef  uint8_t t; };
template<> struct uint_from_size< isizeof<uint16_t>::value > { typedef uint16_t t; };
template<> struct uint_from_size< isizeof<uint32_t>::value > { typedef uint32_t t; };
template<> struct uint_from_size< isizeof<uint64_t>::value > { typedef uint64_t t; };

}
}

#endif // MATHX_COMMON_HELPER_CTH_HPP
