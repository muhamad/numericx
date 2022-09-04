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
** File:  default_arithmetic.hpp
**
** Purpose: int_t/uint_t little-endian implementation for int_arithmetic
**
===========================================================*/

#ifndef MATHX_INT_IMP_LE_DEFAULT_ARITHMETIC_HPP
#define MATHX_INT_IMP_LE_DEFAULT_ARITHMETIC_HPP

namespace mathx
{
namespace mxi
{

// arithmetic functions
// type: int_t/uint_t specialization
template <typename t>
struct default_arithmetic
{
	typedef t type;

	typedef ispec_t<type> spec;
	typedef typename t::st  st;
	typedef typename t::ut  ut;
	typedef typename t::udt udt;

	typedef typename t::logic logic;
	typedef typename t::range range;

	// zero value
	static const ut zero_v = ut(0);
	// one value
	static const ut one_v  = ut(1);
	// maximum unsigned value
	static const ut maxu_v  = ut(~0);

	inline static type& add(type& obj, const type& rhs)
	{
		// value of current element
		udt value = udt(0);
		// carry value from last addition
		ut  carry = zero_v;
		// index of right-most non-zero element in object with larger length
		cs_t idx = -1; // -1 means object is zero

		// detect the index
		for (cs_t i = spec::comp_c - 1; i >= 0; --i)
		{
			// if both are zeros then keep going
			if ( (obj.comp[i] == zero_v) && (rhs.comp[i] == zero_v) ) continue;
			// save the index
			idx = i;
			break;
		}

		// if index is -1 then nothing to add
		if (idx == -1) return obj;

		for(cs_t i = 0; i <= idx; ++i)
		{
			value = udt(obj.comp[i]) + rhs.comp[i] + carry;
			obj.comp[i]= (*(split_t<ut>*)&value).comp[MATHX_LO];
			carry = (*(split_t<ut>*)&value).comp[MATHX_HI];
		}

		if ( (carry != zero_v) && (++idx < spec::comp_c) )
			obj.comp[idx] = carry;

		return obj;
	}

	inline static type& inc(type& obj)
	{
		// increment is a special version of addition algorithm where the rhs is equal to 1

		// increment least significant element
		++obj.comp[0];

		for(cs_t i = 0; i < spec::comp_c - 1; ++i)
			// if current element is zero increment next element otherwise we're done
			if (obj.comp[i] == zero_v) ++obj.comp[i+1]; else break;

		return obj;
	}

	inline static type& sub(type& obj, const type& rhs)
	{
		// value of current element
		udt value = udt(0);
		// carry value from last addition
		ut  borrow= zero_v;
		// index of right-most non-zero element in object with larger length
		cs_t idx = -1; // default value means object is zero

		// detect the index
		for (cs_t i = spec::comp_c - 1; i >= 0; --i)
		{
			// if both are zeros then keep going
			if ( (obj.comp[i] == zero_v) && (rhs.comp[i] == zero_v) ) continue;
			// save the index
			idx = i;
			break;
		}

		// if index is -1 then nothing to subtract
		if (idx == -1) return obj;

		for(cs_t i = 0; i <= idx; ++i)
		{
			value = udt(obj.comp[i]) - rhs.comp[i] - borrow;
			obj.comp[i]= (*(split_t<ut>*)&value).comp[MATHX_LO];
			borrow = (*(split_t<ut>*)&value).comp[MATHX_HI] != ut(0)? 1: 0;
		}

		//normalize most significant elements if needed
		if (borrow) for (++idx; idx < spec::comp_c; ++idx) obj.comp[idx] = maxu_v;

		return obj;
	}

	inline static type& dec(type& obj)
	{
		// decrement is a special version of subtraction algorithm where the rhs is equal to 1

		for(cs_t i=0; i < spec::comp_c; ++i)
			// decrement current element then test it against -1 if less than -1 we're done otherwise continue.
			if ( --obj.comp[i] < maxu_v ) break;

		return obj;
	}

	inline static type& left_shift(type& obj, cs_t rhs)
	{
		// check invalid inputs and undefined behaviour
		if (range::is_zero(obj) || (rhs == 0) || cu_t(rhs) >= spec::full_s) return obj;

		// get number of elements to discard
		const cu_t count = rhs >> (num_of_bin_digits_in_value< spec::comp_b >::value - 1);
		// get number of bits to shift left
		rhs -= count << (num_of_bin_digits_in_value< spec::comp_b >::value - 1);

		// if shift will occur
		if (rhs != 0)
		{
			// shift all elements but head
			for(cs_t src_idx = spec::comp_c - count - 1, dst_idx = spec::comp_c - 1; src_idx > 0; --src_idx)
				obj.comp[dst_idx--] = (obj.comp[src_idx] << rhs) | (obj.comp[src_idx - 1] >> (spec::comp_b - rhs));

			// update head element
			obj.comp[count] = obj.comp[0] << rhs;
		}
		else
		{
			// just copy
			for(cs_t src_idx = spec::comp_c - count - 1, dst_idx = spec::comp_c - 1; src_idx >= 0; --src_idx)
				obj.comp[dst_idx--] = obj.comp[src_idx];
		}

		// put zeros in remained component
		for(cs_t i = 0; i < count; ++i) obj.comp[i] = zero_v;

		return obj;
	}

	inline static type& right_shift(type& obj, cs_t rhs)
	{
		// check invalid inputs and undefined behaviour
		if (range::is_zero(obj) || (rhs == 0) || cu_t(rhs) >= spec::full_s) return obj;

		// pattern to be placed in higher components after shift
		const ut bit_pattern = spec::is_signed && range::is_neg(obj)? maxu_v: zero_v;

		// number of bits used to calculate number of element to discard
		const cu_t shift_bits = num_of_bin_digits_in_value< spec::comp_b >::value - 1;
		// number of elements to discard while shifting
		const cu_t discard_count = rhs >> shift_bits;
		// actual number of bits to shift right inside single element
		rhs -= discard_count << shift_bits;
		// number of bits to complement previous element while shifting
		const cu_t compl_bits = spec::comp_b - rhs;

		// if shift will occur
		if (rhs != 0)
		{
			// index of last component
			const cs_t last_idx = cs_t(spec::comp_c - discard_count) - 1;

			for(cs_t src_idx = (cs_t)discard_count, dst_idx = 0; src_idx < last_idx; ++src_idx)
				obj.comp[dst_idx++] = (obj.comp[src_idx] >> rhs) | (obj.comp[src_idx + 1] << compl_bits);

			// if signed type be aware of the sign
			if (spec::is_signed)
				obj.comp[last_idx] = (st)obj.comp[last_idx] >> rhs;
			else
				obj.comp[last_idx] >>= rhs;
		}
		else
		{
			// just copy
			for(cs_t src_idx = (cs_t)discard_count, dst_idx = 0; src_idx < (cs_t)spec::comp_c; ++src_idx)
				obj.comp[dst_idx++] = obj.comp[src_idx];

		}

		// put sign pattern in remain elements
		for (cs_t i = spec::comp_c - 1, c = discard_count; c > 0; --i, --c) obj.comp[i] = bit_pattern;

		return obj;
	}

	inline static type& multiply(type& obj, const type& rhs)
	{
		// handle special cases

		// if obj is zero or rhs is 0 then the result is zero
		if (range::is_zero(obj) || range::is_zero(rhs)) return range::set_zero(obj);
		// if rhs is 1 then nothing change
		if (range::is_one(rhs)) return obj;
		// if [t] is signed type and rhs is -1 then the result is negated
		if (spec::is_signed && range::is_none(rhs)) return multiply_none(obj);
		// if obj is 1 then the result is the rhs
		if (range::is_one(obj)) return obj = rhs;
		// if [t] is signed type and obj is -1 then the result is negated
		if (spec::is_signed && range::is_none(obj)) return multiply_none(obj, rhs);

		// value of inputs
		t v1 = obj, v2 = rhs;
		range::set_zero(obj);

		// is sign exist
		bool sign = false;

		// if [t] is signed type
		if (spec::is_signed)
		{
			bool sign_v1 = range::is_neg(v1);
			bool sign_v2 = range::is_neg(v2);

			// save result sign
			sign = sign_v1 ^ sign_v2;

			// if v1 contains sign remove it
			if(sign_v1) multiply_none(v1);
			// if v2 contains sign remove it
			if(sign_v2) multiply_none(v2);
		}

		// smaller and bigger numbers
		// using reference instead of pointer for better optimizations
		t &small = v2, &big = v1;

		// Next loop used to optimize multiplication to
		// small number of loops if number of elements occupied
		// by both numbers are different

		// number of occupied elements in input numbers
		cs_t small_count = 0, big_count = 0;

		// get number of elements occupied in big/small
		for(cs_t i = spec::comp_c-1; i >= 0; --i) if (small.comp[i] != zero_v) { small_count = i+1; break; }
		for(cs_t i = spec::comp_c-1; i >= 0; --i) if (big.comp[i] != zero_v) { big_count = i+1; break; }

		for(cs_t j = 0; j < small_count; ++j)
		{
			if (!small.comp[j]) continue;

			ut carry = 0;
			for(cs_t i = 0, k = j; k < spec::comp_c; ++i, ++k)
			{
				udt sum = udt(small.comp[j]) * udt(big.comp[i]) + udt(obj.comp[k]) + carry;
				obj.comp[k] = (*(split_t<ut>*)&sum).comp[MATHX_LO];
				carry = (*(split_t<ut>*)&sum).comp[MATHX_HI];

				// to avoid repeat over zero elements
				// this order is very important, changing that will slow the performance
				if (k > big_count && carry == 0 && sum == 0) break;
			}
		}

		// correct the sign
		if (spec::is_signed && sign) return multiply_none(obj);

		return obj;
	}

	inline static type& divide(type& obj, const type& rhs)
	{
		t rem;
		return full_division(obj, rhs, rem);
	}

	inline static type& modulus(type& obj, const type& rhs)
	{
		t value = obj;
		full_division(value, rhs, obj);
		return obj;
	}

	inline static type& multiply_none(type& obj)
	{
		// you can think of this function as a shortcut instead
		// of calling the heavy multiplication function.

		// assume whoever call this function that [obj]
		// contains value.

		// negate then increment first element
		obj.comp[0] = ~obj.comp[0] + one_v;

		// counter for loop
		cs_t i = 1;

		// do negation and increment in one step
		for(; i < spec::comp_c; ++i)
			if (obj.comp[i-1] == zero_v) obj.comp[i] = ~obj.comp[i] + one_v; else break;

		// for remain elements just negate
		for (; i < spec::comp_c; ++i) obj.comp[i] = ~obj.comp[i];

		return obj;
	}

	inline static type& multiply_none(type& obj, const type& rhs)
	{
		// this function same as above with one exception
		// that it is copy rhs to obj during that operation

		// assume whoever call this function that [obj]
		// and [rhs] contains value.

		// negate then increment first element
		obj.comp[0] = ~rhs.comp[0] + one_v;

		// counter for loop
		cs_t i = 1;

		// do copy, negation and increment in one step
		for(; i < spec::comp_c; ++i)
			if (obj.comp[i-1] == zero_v) obj.comp[i] = ~rhs.comp[i] + one_v; else break;

		// for remain elements just copy & negate
		for (; i < spec::comp_c; ++i) obj.comp[i] = ~rhs.comp[i];

		return obj;
	}

	inline static type& full_division(type& obj, const type& rhs, type& rem)
	{
		// set remainder to zero
		range::set_zero(rem);

		// handle special cases

		// if divisor is zero let hardware handle it.
		if (range::is_zero(rhs)) obj.comp[0] /= rhs.comp[0];
		// if dividend is zero return zero, no remainder
		if (range::is_zero(obj)) return range::set_zero(obj);
		// if divisor is one return dividend, no remainder
		if (range::is_one(rhs)) return obj;
		// if both equals return one, no remainder
		if (logic::equal(obj, rhs)) return range::set_one(obj);

		// save absolute value of inputs
		// de = dividend, di = divisor
		type de, di;
		// result sign for signed types
		bool all_sign = false, de_sign = false;

		// if [t] is signed
		if(spec::is_signed)
		{
			bool di_sign = false;

			// save the sign
			de_sign  = range::is_neg(obj);
			di_sign  = range::is_neg(rhs);
			all_sign = de_sign ^ di_sign;

			// if obj contains sign remove it
			if(de_sign)
				multiply_none(de, obj);
			else
				de = obj;

			// if rhs contains sign remove it
			if(di_sign)
				multiply_none(di, rhs);
			else
				di = rhs;

			// if both equal then the sign is different, set obj to -1, no remainder.
			// test for sign first to avoid equality check if no sign because we already done that.
			if (!all_sign && logic::equal(de, di)) return range::set_none(obj);
		}
		else
		{
			de = obj;
			di = rhs;
		}

		// if divisor greater than dividend
		if (logic::greater_than(di, de))
		{
			rem = obj;
			return range::set_zero(obj);
		}

		// first non-zero component index
		cs_t de_index = spec::comp_c, di_index = spec::comp_c;

		while(--de_index >= 0) if (de.comp[de_index] != 0) break;
		while(--di_index >= 0) if (di.comp[di_index] != 0) break;

		// if one element occupied in divisor, use short algorithm
		if (di_index == 0)
		{
			udt a = 0, b = 0;

			for (cs_t i = de_index; i >= 0; --i)
			{
				a = (udt)de.comp[i] + (b << spec::comp_b);
				obj.comp[i] = ut(a / di.comp[0]);

				b = a - udt(di.comp[0]) * obj.comp[i];
			}

			rem.comp[0] = ut(b);

			while(++de_index < spec::comp_c) obj.comp[de_index] = zero_v;
		}
		else
		{
			// final number of bits occupied by ms divisor component value
			cs_t bits_count = isizeof<ut>::value;
			// number of bits to be shifted
			cs_t shift_len = div_by_two< isizeof<ut>::value >::value;
			// copy of ms divisor component value
			ut tmp1 = di.comp[di_index];

			do
			{
				// value after shift
				ut tmp2 = tmp1 >> shift_len;

				// if value exist
				if(tmp2)
				{
					// update number of occupied bits
					bits_count -= shift_len;
					// update temporary value
					tmp1 = tmp2;
				}
				// update number of bits to shift
				shift_len >>= 1;
			}
			// loop as long as there is bits to shift
			while(shift_len != 0);

			// update bits count
			bits_count -= tmp1;

			// number of unused bits in divisor
			const cs_t spare_bits  = bits_count;
			// number of used bits in divisor
			const cs_t remain_bits = isizeof<ut>::value - spare_bits;
			// number of occupied components in divisor
			const cs_t di_size	 = di_index + 1;

			// temporary array to hold result
			ut de_arr[spec::comp_c + 1], di_arr[spec::comp_c];

			// if normalization required
			if (spare_bits)
			{
				// normalize divisor
				for (cs_t i = di_index; i > 0; --i)
					di_arr[i] = (di.comp[i] << spare_bits) | (di.comp[i-1] >> remain_bits);
				di_arr[0] = di.comp[0] << spare_bits;

				// normalize dividend
				de_arr[de_index + 1] = de.comp[de_index] >> remain_bits;
				for (cs_t i = de_index; i > 0; --i)
					de_arr[i] = (de.comp[i] << spare_bits) | (de.comp[i - 1] >> remain_bits);
				de_arr[0] = de.comp[0] << spare_bits;

				for (cs_t i = di_index + 1; i < spec::comp_c; ++i) di_arr[i] = 0;
				for (cs_t i = de_index + 2; i < spec::comp_c; ++i) de_arr[i] = 0;
			}
			else // just copy
			{
				for (cs_t i = 0; i < spec::comp_c; ++i) di_arr[i] = di.comp[i];
				for (cs_t i = 0; i < spec::comp_c; ++i) de_arr[i] = de.comp[i];
			}
			de_arr[spec::comp_c] = 0;

			// partial quotient and remainder
			udt qhat, rhat;

			const udt mask = udt(1) << spec::comp_b;

			// quotient/remainder loop
			for (cs_t i = de_index - di_index; i >= 0; --i)
			{
				qhat = ((udt(de_arr[i + di_size]) << spec::comp_b) + de_arr[i + di_size - 1]) / di_arr[di_size - 1];
				rhat = ((udt(de_arr[i + di_size]) << spec::comp_b) + de_arr[i + di_size - 1]) - qhat * di_arr[di_size - 1];

				while( (qhat >= mask) || (qhat * di_arr[di_size - 2] > ((rhat << spec::comp_b) + de_arr[i + di_size - 2])) )
				{
					--qhat;
					rhat += di_arr[di_size - 1];
					if (!(rhat < mask)) break;
				}

				udt k = 0;
				sdt_t tmp = 0;
				for (cs_t j = 0; j < di_size; ++j)
				{
					udt p = qhat * di_arr[j];
					tmp = de_arr[j + i] - k - (p & ut(~0));
					de_arr[j + i] = ut(tmp);
					k = (p >> spec::comp_b) - (tmp >> spec::comp_b);
				}

				tmp = de_arr[i + di_size] - k;
				de_arr[i + di_size] = ut(tmp);

				obj.comp[i] = ut(qhat);
				if (tmp < 0)
				{
					--obj.comp[i];
					k = 0;

					for (cs_t j = 0; j < di_size; ++j)
					{
						tmp = de_arr[j + i] + di_arr[j] + k;
						de_arr[j + i] = ut(tmp);
						k = tmp >> spec::comp_c;
					}
					de_arr[i + di_size] += ut(k);
				}
			}

			// set the rest to zero
			for (cs_t i = de_index - di_index + 1; i < spec::comp_c; ++i) obj.comp[i] = zero_v;

			// normalize remainder
			for (cs_t i = 0; i < di_size - 1; ++i)
				rem.comp[i] = ut((de_arr[i] >> spare_bits) | (udt(de_arr[i+1]) << remain_bits));

		}

		// if signed type
		if (spec::is_signed)
		{
			// correct sign if any
			if (all_sign) multiply_none(obj);
			if (de_sign && !range::is_zero(rem)) multiply_none(rem);
		}

		return obj;
	}

};

}
}

#endif // MATHX_INT_IMP_LE_DEFAULT_ARITHMETIC_HPP
