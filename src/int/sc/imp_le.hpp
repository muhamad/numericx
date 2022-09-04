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
** File:  imp_le.hpp
**
** Purpose: string_cast little-endian implementation
**
===========================================================*/

#ifndef MATHX_INT_SC_IMP_LE_HPP
#define MATHX_INT_SC_IMP_LE_HPP

namespace mathx
{
namespace mxi
{

template<typename num_type>
inline cs_t int_len_dec(const num_type& value)
{
	typedef typename num_type::ut ut;
	typedef ispec_t<num_type> spec;

	// the value zero
	const ut zero = ut(0);
	// is input type has sign
	bool has_sign = false;

	// temporary value
	num_type r;

	// if signed value
	if (spec::is_signed && num_type::range::is_neg(value))
	{
		// un-sign it
		has_sign = true;
		num_type::arithmetic::multiply_none(r, value);
	}
	else
		r = value;

	// index of first most-significant component with value
	cs_t idx = spec::comp_c;

	while(--idx >= 0) if (value.comp[idx] != zero) break;

	cs_t digits_count = 0;

	ut rem = 0;

	while(idx > -1)
	{
		rem = int_fast_div<num_type>(r, idx, power10_for_type<ut>::value);

		if (idx > -1 && r.comp[idx] == zero) --idx;

		if(idx != -1)
			digits_count += log10_for_type<ut>::value;
	}

	if (rem != zero)
	{
		cs_t bits_count = int_fast_bit_count<ut>(rem);

		digits_count += (bits_count * 1233) >> 12;
	}

	return digits_count + 1 + (has_sign? 1: 0);
}

template<typename num_type, typename base_type>
inline cs_t int_len_bas(const num_type& value)
{
	typedef typename num_type::ut ut;
	typedef ispec_t<num_type> spec;

	// sign pattern
	const ut sign_pattern = (spec::is_signed && num_type::range::is_neg(value))? ut(~0): ut(0);
	// location of first non-occupied element
	cs_t idx = spec::comp_c;

	// get non-occupied location
	while(--idx > -1 && value.comp[idx] == sign_pattern);

	if (idx == -1)
	{
		// if no sign
		if (sign_pattern == 0) return 1;

		if (base_type::base == 2)
			return spec::full_s;
		else
		if (base_type::base == 8)
			return (spec::full_s / 3) + 1;
		else // base16
			return spec::full_s / 4;
	}

	// count components bits + remaining bits
	cs_t bits_count = (idx * isizeof<ut>::value) + int_fast_bit_count<ut>(value.comp[idx]);

	if (base_type::base == 2)
		return bits_count;
	else
	if (base_type::base == 8)
		return (bits_count / 3) + ((bits_count % 3) != 0? 1: 0);
	else // base16
		return (bits_count / 4) + ((bits_count % 4) != 0? 1: 0);
}

template<typename num_type, typename base_type>
inline cs_t int_len_any(const num_type& value)
{
	typedef typename num_type::ut ut;
	typedef typename base_type::custom custom;
	typedef ispec_t<num_type> spec;

	if (base_type::base < 2) return 0;

	// maximum number of base digits can be stored in input type -1
	const cs_t base_digits = log_in_base_for_type_size<ut, base_type>();
	// the value zero
	const ut zero = ut(0);
	// is input type has sign
	bool has_sign = false;

	// temporary value
	num_type r;

	if (custom::have_sign == false)
		r = value;
	else
	{
		// if signed value
		if (spec::is_signed && num_type::range::is_neg(value))
		{
			// remove sign
			if (custom::show_sign) has_sign = true;
			num_type::arithmetic::multiply_none(r, value);
		}
		else
			r = value;
	}

	// used to count input value digits count
	const ut power = ipower<ut>(base_type::base, base_digits);

	// index of first most-significant component with value
	cs_t idx = spec::comp_c;

	while(--idx >= 0) if (r.comp[idx] != zero ) break;

	// total number of digits
	cs_t digits_count = 0;

	ut rem = 0;

	if (idx == -1) return 1;

	while(idx > -1)
	{
		rem = int_fast_div<num_type>(r, idx, power);

		if (idx > -1 && r.comp[idx] == zero) --idx;

		if(idx != -1)
			digits_count += base_digits;
	}

	if (rem != zero)
	{
		while(rem >= base_type::base)
		{
			++digits_count;
			rem /= base_type::base;
		}

		if ((rem % base_type::base) != 0) ++digits_count;
	}

	return digits_count + (has_sign? 1: 0);
}

template<typename num_type, typename base_type>
inline bool int_fstr_dec(const typename base_type::char_t* str, num_type& value)
{
	typedef typename num_type::ut ut;
	typedef typename base_type::char_t char_t;
	typedef typename base_type::letter letter;

	// result sign
	bool has_sign = false;

	// check for sign, if it is exist it will affect input result no matter type of [t]
	if ((*str == letter::minus && (has_sign = true)) || *str == letter::plus) ++str;

	// skip leading zeros
	while(*str == letter::zero) ++str;

	// if it all zero then mission accomplished
	if (*str == 0)
	{
		num_type::range::set_zero(value);
		return true;
	}

	// a pointer to check invalid digits
	const char_t* str2 = str;

	// check base digits
	while(*str2 != 0) if(!base_type::check(*str2++)) return false;

	// size of part to convert
	cs_t str_len = str2 - str;

	// if number of digits more than a type can handle then
	// an overflow will occur.
	if (str_len > num_of_dec_digits_in_type<num_type>::value) return false;

	// number of digits to store inside ut without overflow
	const cs_t ut_digits_count = num_of_dec_digits_in_type<ut>::value - 1;
	// number of digits that requires 10th power calculation
	const cs_t remain_count = str_len % ut_digits_count;

	num_type::range::set_zero(value);

	// do convert
	while(str_len != 0)
	{
		// value of single component
		ut result = 0;

		// get component value
		for(cs_t i=0; *str && (i < ut_digits_count); ++i, --str_len)
			result = ut(result * 10) + ut(base_type::char_to_digit(*str++));

		if (str_len != 0 || remain_count == 0)
			// second parameter is zero to terminate multiplication as soon as possible
			int_fast_mul<num_type>(value, 0, power10_for_value<ut_digits_count>::value);
		else
		{
			ut pwr = 10;
			// calculate 10th power
			for (cs_t i = 1; i < remain_count; ++i) pwr *= 10;

			int_fast_mul<num_type>(value, 0, pwr);
		}

		int_fast_add<num_type>(value, result);
	}

	if (has_sign) num_type::arithmetic::multiply_none(value);

	return true;
}

template<typename num_type, typename base_type>
inline bool int_fstr_bas(const typename base_type::char_t* str, num_type& value)
{
	typedef typename num_type::ut ut;
	typedef typename base_type::char_t char_t;
	typedef typename base_type::letter letter;

	// skip leading zeros
	while(*str == letter::zero) ++str;

	// if it all zero then mission accomplished
	if (*str == 0)
	{
		num_type::range::set_zero(value);
		return true;
	}

	// a pointer to check invalid digits
	const char_t* str2 = str;

	// check base digits
	while(*str2 != 0) if(!base_type::check(*str2++)) return false;

	// string size to convert
	cs_t str_len = str2 - str;

	// set result to zero
	num_type::range::set_zero(value);
	
	if (base_type::base == 2) {
		if (str_len > num_type::meta::bin_digits_count) return false;
	}
	else if (base_type::base == 8) {
		if (str_len > num_type::meta::hex_digits_count) return false;
	}
	else { // base16
		if (str_len > num_type::meta::hex_digits_count) return false;
	}

	// convert
	if (base_type::base == 2 || base_type::base == 16)
	{
		// number of base digits in ut
		const cs_t ut_digits_count = (base_type::base == 2)? num_of_bin_digits_in_type<ut>::value: num_of_hex_digits_in_type<ut>::value;
		// number of remaining digits in most significant element
		const cs_t remain_digits = str_len % ut_digits_count;
		// number of elements to represent input string
		const cs_t ecount = str_len / ut_digits_count;
		// total number of elements needed
		const cs_t etotal = ecount + (remain_digits != 0? 1: 0);
		// number of bits per digit
		const cs_t ut_digit_bits = isizeof<ut>::value / ut_digits_count;

		// get element location
		cs_t idx = etotal - 1;

		// if there less-than-element digits
		if (remain_digits != 0)
		{
			// element to store remain digits on
			ut& itm = value.comp[idx];

			// convert
			for (cs_t i = 0; i < remain_digits; ++i)
			{
				itm <<= ut_digit_bits;
				itm |= base_type::char_to_digit(*str++);
			}
		}

		// convert remaining digits
		while(idx != 0)
		{
			ut& itm = value.comp[--idx];

			// convert
			for (cs_t i = 0; i < ut_digits_count; ++i)
			{
				itm <<= ut_digit_bits;
				itm |= base_type::char_to_digit(*str++);
			}
		}
	}
	else // base8
	{
		// element to store data into
		cs_t idx = 0;
		// value to store into the LSB of element at index stored in [idx]
		ut next_value = 0;
		// number of bits to shift by element at [idx] to preserve its value
		ut remain_bits = 0;

		// loop 
		while(str_len != 0)
		{
			// element to store remain digits on
			ut& itm = value.comp[idx];
			itm = next_value;

			while(remain_bits < isizeof<ut>::value)
			{
				--str2;
				itm |= ut(*str2 - letter::zero) << remain_bits;
				remain_bits += 3;

				if (--str_len == 0) break;
			}

			const int tmp = isizeof<ut>::value - remain_bits + 3;

			if (tmp == 3)
				next_value = remain_bits = 0;
			else
			{
				remain_bits = (tmp == 1)? 2: 1;
				next_value  = ut(*str2 - letter::zero) >> tmp;
			}

			++idx;

			if (str_len == 0 && next_value != 0) value.comp[idx] = next_value;
		}
	}

	return true;
}

template<typename num_type, typename base_type>
inline bool int_fstr_any(const typename base_type::char_t* str, num_type& value)
{
	typedef typename num_type::ut ut;
	typedef typename base_type::char_t char_t;
	typedef typename base_type::letter letter;
	typedef typename base_type::custom custom;

	if (base_type::base < 2) return false;

	// result sign
	bool has_sign = false;

	// check for sign, if it is exist it will affect input result no matter is type of [num_type]
	if (custom::have_sign)
		if ((*str == letter::minus && (has_sign = true)) || *str == letter::plus) ++str;

	// skip leading zeros
	while(base_type::char_to_digit(*str) == 0) ++str;

	// if it all zero then mission accomplished
	if (*str == 0) return true;

	// a pointer to check invalid digits
	const char_t* str2 = str;

	// check base digits
	while(*str2) if(!base_type::check(*str2++)) return false;

	// size of part to convert
	cs_t str_len = str2 - str;

	// if number of digits more than a type can handle then
	// an overflow will occur.
	if ( str_len > digits_in_type_for_base<num_type, base_type>() ) return false;

	// maximum number of base digits can be stored in input type
	const cs_t base_digits = log_in_base_for_type_size<ut, base_type>();
	// used to count input value digits count
	const ut power = ipower<ut>(base_type::base, base_digits);

	// number of digits that requires 10th power calculation
	const cs_t remain_count = str_len % base_digits;

	num_type::range::set_zero(value);

	// do convert
	while(str_len)
	{
		// value of single component
		ut result = 0;

		// get component value
		for(cs_t i=0; *str && (i < base_digits); ++i, --str_len)
			result = ut(result * base_type::base) + ut(base_type::char_to_digit(*str++));

		if (str_len || remain_count == 0)
			// parameter count == 0 so multiplication terminates as soon as possible
			int_fast_mul<num_type>(value, 0, power);
		else
		{
			// calculate base power
			ut pwr = ipower<ut>(base_type::base, remain_count);

			int_fast_mul<num_type>(value, 0, pwr);
		}

		int_fast_add<num_type>(value, result);
	}

	if (has_sign) num_type::arithmetic::multiply_none(value);

	return true;
}

template<typename num_type, typename base_type>
inline bool int_tstr_dec(const num_type& value, typename base_type::char_t* str)
{
	typedef typename num_type::ut ut;
	typedef typename base_type::char_t char_t;
	typedef typename base_type::letter letter;
	typedef ispec_t<num_type> spec;

	bool has_sign = false;

	// value to convert
	num_type n;

	char_t* str2 = str;

	if (spec::is_signed && num_type::range::is_neg(value))
	{
		has_sign = true;
		*str2++ = letter::minus;
		num_type::arithmetic::multiply_none(n, value);
	}
	else
		n = value;

	// maximum 10th power can be saved in [ut] type
	const ut pwr10 = power10_for_type<ut>::value;

	// location of last occupied element
	cs_t idx = spec::comp_c;

	// get location
	while(--idx > -1 && n.comp[idx] == ut(0));

	if (idx == -1)
	{
		*str = letter::zero;
		return true;
	}


	// decimal digits
	const char_t digits[] = { letter::zero,  letter::one, letter::two, letter::three,
							  letter::four, letter::five, letter::six, letter::seven,
							  letter::eight, letter::nine };

	while(idx > -1)
	{
		// get digits
		ut rem = int_fast_div<num_type>(n, idx, pwr10);

		if (idx > -1 && n.comp[idx] == ut(0)) --idx;

		// save digits
		if (idx == -1)
		{
			// discard leading zeros
			while(rem != 0)
			{
				*str2++ = digits[ rem % base_type::base ];
				rem /= base_type::base;
			}
		}
		else
		{
			// embed leading zeros
			for (cs_t i = 0; i < num_of_dec_digits_in_value<pwr10>::value - 1; ++i)
			{
				*str2++ = digits[ rem % base_type::base ];
				rem /= base_type::base;
			}
		}
	}

	if (num_type::meta::is_signed && has_sign)
		string_swap<char_t>(str + 1, 0, str2 - str - 1);
	else
		string_swap<char_t>(str, 0, str2 - str);

	return true;
}

template<typename num_type, typename base_type>
inline bool int_tstr_bas(const num_type& value, typename base_type::char_t* str, bool upper)
{
	typedef typename num_type::ut ut;
	typedef typename base_type::char_t char_t;
	typedef typename base_type::letter letter;
	typedef ispec_t<num_type> spec;

	// location of last occupied element
	cs_t idx = spec::comp_c;

	// get location
	while(--idx > -1 && value.comp[idx] == ut(0));

	// no value
	if (idx == -1)
	{
		*str = letter::zero;
		return true;
	}

	// for base2 and base16
	if (base_type::base == 2 || base_type::base == 16)
	{
		// max digit in base
		const ut digit = (base_type::base == 2)? ut(1): ut(0xf);
		// bits per digit
		const cs_t bpd = (base_type::base == 2)? ut(1): ut(4);
		// array to be used
		const cs_t use = upper? 1: 0;

		// digits array
		const char_t digits[][16] =
		{
			{
			  letter::zero,  letter::one,   letter::two,   letter::three, letter::four,
			  letter::five,  letter::six,   letter::seven, letter::eight, letter::nine,
			  letter::hex_a, letter::hex_b, letter::hex_c, letter::hex_d, letter::hex_e,
			  letter::hex_f
			},
			{
			  letter::zero,  letter::one,   letter::two,   letter::three, letter::four ,
			  letter::five,  letter::six,   letter::seven, letter::eight, letter::nine,
			  letter::hex_A, letter::hex_B, letter::hex_C, letter::hex_D, letter::hex_E,
			  letter::hex_F
			}
		};

		// if value of most significant array element not full with value
		if ((value.comp[idx] & (digit << (isizeof<ut>::value - bpd))) == 0)
		{
			// bits counter
			cs_t bits_count = int_fast_bit_count<ut>(value.comp[idx]);

			// if base16
			if (base_type::base == 16)
				// normalize bits-size
				bits_count = ((bits_count >> 2) + ((bits_count % 4) > 0? 1: 0)) * bpd;

			// get element value
			ut itm = value.comp[idx];

			// get digits in MS element
			while(bits_count != 0)
			{
				bits_count -= bpd;
				*str++ = digits[use][ ((digit << bits_count) & itm) >> bits_count ];
			}

			// decrement index
			--idx;
		}

		// get rest of digits
		while(idx > -1)
		{
			// current element
			ut itm = value.comp[idx];

			for (cs_t i = isizeof<ut>::value - bpd; i > -1; i -= bpd)
			{
				// save digits
				*str++ = digits[use][ ((digit << i) & itm) >> i ];
			}

			// update index
			--idx;
		}

		return true;
	}

	// When converting arbitrary arithmetic type to octal string there is 3 cases:
	//
	// 1- the digit have less than 3 bits (only in most-significant bits either a 1 or 2 bits).
	// 2- the digit have exact 3 bits (normal state).
	// 3- the digit bits exist in 2 consecutive elements (happened in [1] and [2]).
	//
	// In [1]:
	// if the power of 2 used to construct the type is an even number then bits count is 2,
	// and if it's odd number then the bits count is 1.
	// We use [octal_remain_digit_bits_in_type] to get that number of bits, and we use
	// [left_most_octal_digit_for_type] to get the value that those bits represent when they
	// all set.
	//
	// In [2]: we shift and extract the digit for exact bits.
	//
	// In [3]:
	// for each case there is sub-case and they're:
	//
	// In [1]
	// In this case we can have a digit with only 1 or 2 bits so for this problem they are 2 bits
	// and they located at least-significant-bit in element E and at most-significant-bit in element E-1.
	//
	// In [2]
	// a digit will have 1-bit at least-significant-bit in element E and 2-bits at most-significant-bits
	// in element E-1 and vice versa.

	// digits array
	const char_t digits[] =
	{
		letter::zero, letter::one,  letter::two, letter::three,
		letter::four, letter::five, letter::six, letter::seven
	};

	// number of bits per digit
	const cs_t bits_per_digit = 3;
	// number of bits in most-significant digit in input type
	const cs_t bits_per_special_digit = octal_remain_digit_bits_in_type<num_type>::value;
	// number of bits in [ut]
	const cs_t ut_bits = isizeof<ut>::value;

	// value to get character from.
	ut shift_value = 0;
	// number of bits to shift [shift_value] by to get valid character
	cs_t shift_bits = 0;

	// handle bits less than 3
	bool handle_less_bits = false;
	// distributed-bits
	bool is_splitted = false;

	// detect less-than-3-bits digit
	if ((value.comp[spec::comp_c - 1] & (left_most_octal_digit_for_type<num_type>::value << (ut_bits - bits_per_special_digit))) > 0)
	{
		handle_less_bits = true;
		shift_bits = isizeof<ut>::value;
	}
	else
	{
		// number of used bits in MS element
		const cs_t used_bits = int_fast_bit_count<ut>(value.comp[idx]);
		// total used bits in input type
		const cs_t bit_size = idx * isizeof<ut>::value + used_bits;
		// number of bits in inaccurate digit
		const cs_t bcnt = bit_size % 3;

		// set number of bits in element at idx
		shift_bits = used_bits;

		if (bcnt != 0) handle_less_bits = true;
		if (used_bits < bcnt) is_splitted = true;
	}

	// if case exist handle it
	if (handle_less_bits)
	{
		if (is_splitted)
		{
			*str++ = digits[ (value.comp[idx] << 1) | (value.comp[idx - 1] >> (ut_bits - 1)) ];
			shift_bits = ut_bits - 1;
			shift_value = value.comp[--idx] & (ut(~0) >> 1);
		}
		else
		{
			shift_bits -= bits_per_special_digit;
			*str++ = digits[ value.comp[idx] >> shift_bits ];
			shift_value = value.comp[idx] & (ut(~0) >> (ut_bits - shift_bits));

			if (shift_bits == 0)
			{
				shift_bits = ut_bits;
				if (--idx > -1) shift_value = value.comp[idx];
			}
		}
	}

	// get all 3-bits digits
	while(idx > -1)
	{
		while(shift_bits >= bits_per_digit)
		{
			shift_bits -= bits_per_digit;
			*str++ = digits[ shift_value >> shift_bits ];
			shift_value &= ~(ut(~0) << shift_bits);
		}

		if (--idx == -1) break;

		if (shift_bits == 0)
		{
			shift_bits = ut_bits;
			shift_value = value.comp[idx];
			continue;
		}

		const cs_t tmp_bits = ut_bits - (shift_bits == 1? 2: 1);
		*str++ = digits [ (shift_value << (bits_per_digit - shift_bits)) | (value.comp[idx] >> tmp_bits) ];
		shift_value = value.comp[idx] & (ut(~0) >> (ut_bits - tmp_bits));
		shift_bits = tmp_bits;
	}

	return true;
}

template<typename num_type, typename base_type>
inline bool int_tstr_any(const num_type& value, typename base_type::char_t* str, bool upper)
{
	typedef typename num_type::ut ut;
	typedef typename base_type::letter letter;
	typedef typename base_type::custom custom;
	typedef typename base_type::char_t char_t;
	typedef ispec_t<num_type> spec;

	if (base_type::base < 2) return false;

	// maximum number of base digits can be stored in input type -1
	const cs_t base_digits = log_in_base_for_type_size<ut, base_type>();
	// the value zero
	const ut zero = ut(0);
	// is input type has sign
	bool has_sign = false;

	// temporary value
	num_type r;

	char_t* str2 = str;

	if (!custom::have_sign)
		r = value;
	else
	{
		// if signed value
		if (spec::is_signed && num_type::range::is_neg(value))
		{
			// remove sign
			if (custom::show_sign)
			{
				has_sign = true;
				*str2++ = letter::minus;
			}
			num_type::arithmetic::multiply_none(r, value);
		}
		else
			r = value;
	}

	// used to count input value digits count
	const ut power = ipower<ut>(base_type::base, base_digits);

	// index of first most-significant component with value
	cs_t idx = spec::comp_c;

	while(--idx >= 0) if (r.comp[idx] != zero ) break;

	if (idx == -1)
	{
		*str = base_type::digit_to_char(0, upper);
		return true;
	}

	while(idx > -1)
	{
		// get digits
		ut rem = int_fast_div<num_type>(r, idx, power);

		if (idx > -1 && r.comp[idx] == zero) --idx;

		// save digits
		if (idx == -1)
		{
			// discard leading zeros
			while(rem != 0)
			{
				*str2++ = base_type::digit_to_char(rem % base_type::base, upper);
				rem /= base_type::base;
			}
		}
		else
		{
			// embed leading zeros
			for (cs_t i = 0; i < base_digits; ++i)
			{
				*str2++ = base_type::digit_to_char(rem % base_type::base, upper);
				rem /= base_type::base;
			}
		}
	}

	if (num_type::meta::is_signed && has_sign)
		string_swap<char_t>(str + 1, 0, str2 - str - 1);
	else
		string_swap<char_t>(str, 0, str2 - str);

	return true;
}

}
}

#endif // MATHX_INT_SC_IMP_LE_HPP
