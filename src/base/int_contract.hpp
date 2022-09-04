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
** File:  int_contract.hpp
**
** Purpose: int_t/uint_t core functions
**
===========================================================*/

#ifndef MATHX_BASE_INT_CONTRACT_HPP
#define MATHX_BASE_INT_CONTRACT_HPP

namespace mathx
{

// range functions
// type: int_t/uint_t specialization
template <typename t>
struct int_range
{
	typedef t type;

	// set input object to its type minimum representable value.
	// [obj]: input object
	// returns reference to [obj]
	inline static type& set_min(type& obj);

	// set input object to its type maximum representable value.
	// [obj]: input object
	// returns reference to [obj]
	inline static type& set_max(type& obj);

	// set input object to negative one.
	// [obj]: input object
	// returns reference to [obj]
	inline static type& set_none(type& obj);

	// set input object to zero
	// [obj]: input object
	// returns reference to [obj]
	inline static type& set_zero(type& obj);

	// set input object to one
	// [obj]: input object
	// returns reference to [obj]
	inline static type& set_one(type& obj);

	// check if input object contains the minimum value can be held by its type
	// [obj]: input object
	// return true if it is, false otherwise
	inline static bool is_min(const type& obj);

	// check if input object contains the maximum value can be held by its type
	// [obj]: input object
	// return true if it is, false otherwise
	inline static bool is_max(const type& obj);

	// check if input object is less than zero.
	// [obj]: input object
	// returns true if negative, false otherwise.
	// NOTE: Use with signed-type
	inline static bool is_neg(const type& obj);

	// check if input object contains the value negative one
	// [obj]: input object
	// return true if it is, false otherwise
	inline static bool is_none(const type& obj);

	// check if input object contains the value zero
	// [obj]: input object
	// return true if it is, false otherwise
	inline static bool is_zero(const type& obj);

	// check if input object contains the value one
	// [obj]: input object
	// return true if it is, false otherwise
	inline static bool is_one(const type& obj);

	// check if input object contains either values zero or one
	// [obj]: input object
	// return true if it is, false otherwise
	inline static bool is_zero_or_one(const type& obj);
};

// bitwise functions
// type: int_t/uint_t specialization
template <typename t>
struct int_bitwise
{
	typedef t type;

	// signed/unsigned bitwise and.
	// [obj] : left-hand object
	// [rhs]: right-hand object
	// returns reference to [obj]
	// NOTE: has same effect as built-in bitwise-and operator
	inline static type& and_op(type& obj, const type& rhs);

	// signed/unsigned bitwise or.
	// [obj] : left-hand object
	// [rhs]: right-hand object
	// returns reference to [obj]
	// NOTE: has same effect as built-in bitwise-or operator
	inline static type& or_op(type& obj, const type& rhs);

	// signed/unsigned bitwise exclusive xor.
	// [obj] : left-hand object
	// [rhs]: right-hand object
	// returns reference to [obj]
	// NOTE: has same effect as built-in bitwise-xor operator
	inline static type& xor_op(type& obj, const type& rhs);

	// signed/unsigned bitwise negation.
	// [lhs]: input object
	// returns negated copy of [lhs]
	// NOTE: has same effect as built-in bitwise-negation operator
	inline static t neg_op(const type& lhs);

	// signed/unsigned bitwise self negation
	// [obj] : input object
	// returns reference to [obj]
	// NOTE: has same effect as built-in bitwise-negation operator
	inline static type& neg_op(type& obj);
};

// logic functions
// type: int_t/uint_t specialization
template <typename t>
struct int_logic
{
	typedef t type;

	// signed/unsigned logic and.
	// [lhs]: left-hand object
	// [rhs]: right-hand object
	// return true if both input are true, false otherwise
	// NOTE: has same effect as built-in logic-and operator
	inline static bool and_op(const type& lhs, const type& rhs);

	// signed/unsigned logic or.
	// [lhs]: left-hand object
	// [rhs]: right-hand object
	// return true if both either are true, false otherwise
	// NOTE: has same effect as built-in logic-or operator
	inline static bool or_op(const type& lhs, const type& rhs);

	// determine if input object have non-zero value.
	// [obj] : input object
	// returns false if input object is zero, true otherwise.
	// NOTE: applied formula is [obj] != [0]
	inline static bool self_or(const type& obj);

	// signed/unsigned logic not.
	// [lhs]: input object
	// return true if input object value is true, false otherwise
	// NOTE: has same effect as built-in logic-not operator
	inline static bool not_op(const type& lhs);

	// signed/unsigned logic less than.
	// [lhs]: left-hand object
	// [rhs]: right-hand object
	// return true if [lhs] is less than [rhs], false otherwise
	// NOTE: has same effect as built-in logic-less-than operator
	inline static bool less_than(const type& lhs, const type& rhs);

	// signed/unsigned logic greater than.
	// [lhs]: left-hand object
	// [rhs]: right-hand object
	// return true if [lhs] is greater than [rhs], false otherwise
	// NOTE: has same effect as built-in logic-greater-than operator
	inline static bool greater_than(const type& lhs, const type& rhs);

	// signed/unsigned logic less than or equal.
	// [lhs]: left-hand object
	// [rhs]: right-hand object
	// return true if [lhs] is less than or equal to [rhs], false otherwise
	// NOTE: has same effect as built-in logic-less-than-or-equal-to operator
	inline static bool less_than_equal(const type& lhs, const type& rhs);

	// signed/unsigned logic greater than or equal.
	// [lhs]: left-hand object
	// [rhs]: right-hand object
	// return true if [lhs] is greater than or equal to [rhs], false otherwise
	// NOTE: has same effect as built-in logic-greater-than-or-equal-to operator
	inline static bool greater_than_equal(const type& lhs, const type& rhs);

	// signed/unsigned logic equal to.
	// [lhs]: left-hand object
	// [rhs]: right-hand object
	// return true if [lhs] is equal to [rhs], false otherwise
	// NOTE: has same effect as built-in logic-equals-to operator
	inline static bool equal(const type& lhs, const type& rhs);

	// signed/unsigned logic not equal to.
	// [lhs]: left-hand object
	// [rhs]: right-hand object
	// return true if [lhs] is not equal to [rhs], false otherwise
	// NOTE: has same effect as built-in logic-not-equals-to operator
	inline static bool not_equal(const type& lhs, const type& rhs);
};

// arithmetic functions
// type: int_t/uint_t specialization
template <typename t>
struct int_arithmetic
{
	typedef t type;

	// signed/unsigned addition
	// [obj] : left-hand object
	// [rhs]: value to add to [obj]
	// returns reference to [obj]
	// NOTE: applied formula is [obj] += [rhs]
	inline static type& add(type& obj, const type& rhs);

	// signed/unsigned increment by one
	// [obj] : input object
	// returns reference to [obj]
	// NOTE: applied formula is [obj] = ++[obj]
	inline static type& inc(type& obj);

	// signed/unsigned subtraction
	// [obj] : left-hand object
	// [rhs]: value to subtract from [obj]
	// returns reference to [obj]
	// NOTE: applied formula is [obj] -= [rhs]
	inline static type& sub(type& obj, const type& rhs);

	// signed/unsigned decrement by one
	// [obj] : input object
	// returns reference to [obj]
	// NOTE: applied formula is [obj] = --[obj]
	inline static type& dec(type& obj);

	// signed/unsigned shift left
	// [obj] : left-hand object
	// [rhs]: number of bits to shift left
	// returns reference to [obj]
	// NOTE: applied formula is [obj] <<= [rhs]
	inline static type& left_shift(type& obj, cs_t rhs);

	// signed/unsigned shift right
	// [obj] : left-hand object
	// [rhs]: number of bits to shift right
	// returns reference to [obj]
	// NOTE: applied formula is [obj] >>= [rhs]
	inline static type& right_shift(type& obj, cs_t rhs);

	// signed/unsigned multiplication
	// [obj] : left-hand object
	// [rhs]: the multiplier
	// returns reference to [obj]
	// NOTE: applied formula is [obj] *= [rhs]
	inline static type& multiply(type& obj, const type& rhs);

	// signed/unsigned division without reminder
	// [obj] : left-hand object
	// [rhs]: the divisor
	// returns reference to [obj] with quotient
	// NOTE: applied formula is [obj] = [obj] / [rhs]
	inline static type& divide(type& obj, const type& rhs);

	// signed/unsigned reminder
	// [obj] : left-hand object
	// [rhs]: the divisor
	// returns reference to [obj] with reminder
	// NOTE: applied formula is [obj] = [obj] % [rhs]
	inline static type& modulus(type& obj, const type& rhs);

	// fast multiply by negative one
	// [obj]: object to multiply by [-1]
	// returns reference to [obj]
	// NOTE: applied formula [obj] *= [-1]
	// [obj] must contains non-zero value.
	inline static type& multiply_none(type& obj);

	// fast copy and multiply by negative one
	// [rhs]: object to be copied
	// [obj] : destination object to copy and multiply into
	// returns reference to [obj]
	// NOTE: applied formula [obj] = [rhs] * [-1]
	// [obj] and [rhs] must contains non-zero value.
	inline static type& multiply_none(type& obj, const type& rhs);

	// signed/unsigned division with reminder, address of [rem] always not equal to address of [me]
	// [obj] : left-hand object
	// [rhs]: the divisor
	// [rem]: the reminder
	// returns reference to [me] with quotient
	// NOTE: applied formula is [obj] = [obj] / [rhs] and [rem] = [obj] % [rhs]
	inline static type& full_division(type& obj, const type& rhs, type& rem);
};

// metadata constants
// type: int_t/uint_t specialization
template <typename t>
struct int_meta
{
	typedef t type;

	// is type is signed
	static const bool is_signed;

	// base used to implement input type
	static const cs_t radix;

	// get number of bits used to store sign
	static const cs_t sign_bits;

	// get number of bits in one array element
	static const cs_t element_bits;

	// get number of bits used to store numeric data
	static const cs_t data_bits;

	// get type size in bits
	static const cs_t all_bits;

	// get number of elements used to represent type objects
	static const cs_t array_count;

	// number of radix digits in input type
	static const cs_t radix_digits_count;

	// number of decimal digits in input type
	static const cs_t bin_digits_count;

	// number of octal digits in input type
	static const cs_t oct_digits_count;

	// number of decimal digits in input type
	static const cs_t dec_digits_count;

	// number of hexadecimal digits in input type
	static const cs_t hex_digits_count;
};

}

#endif // MATHX_BASE_INT_CONTRACT_HPP
