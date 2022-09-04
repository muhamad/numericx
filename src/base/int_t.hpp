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
** File:  int_t.hpp
**
** Purpose: fixed-length signed-integer data type
**
===========================================================*/

#ifndef MATHX_BASE_INT_T_HPP
#define MATHX_BASE_INT_T_HPP

namespace mathx
{
// bits_count: number of bits
// ut_t, st_t, udt_t, sdt_t: see "common/helper/post_startup.hpp"
// range_t: range functions.
// bitwise_t: bitwise functions.
// logic_t: logic functions.
// arithmetic_t: arithmetic functions
// meta_t: metadata constants
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_t
{
	typedef int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> type;

	typedef ut_t     ut; // unsigned half type
	typedef st_t     st; //   signed half type
	typedef udt_t   udt; // unsigned full type
	typedef sdt_t   sdt; //   signed full type

	typedef range_t<type>           range; // range functions
	typedef bitwise_t<type>       bitwise; // bitwise functions
	typedef logic_t<type>           logic; // logic functions
	typedef arithmetic_t<type> arithmetic; // arithmetic functions
	typedef meta_t<type>             meta; // metadata constants

	ut comp[meta::array_count];

	inline int_t() {}

	inline int_t(const char           value);
	inline int_t(const signed char    value);
	inline int_t(const unsigned char  value);
	inline int_t(const wchar_t        value);

	inline int_t(const bool value);

	inline int_t(const signed short int     value);
	inline int_t(const signed int           value);
	inline int_t(const signed long int      value);
	inline int_t(const signed long long int value);

	inline int_t(const unsigned short int     value);
	inline int_t(const unsigned int           value);
	inline int_t(const unsigned long int      value);
	inline int_t(const unsigned long long int value);

	inline int_t(const float       value);
	inline int_t(const double      value);
	inline int_t(const long double value);

	inline type& operator +=(const type& rhs) { return arithmetic::add(*this, rhs); }
	inline type& operator -=(const type& rhs) { return arithmetic::sub(*this, rhs); }
	inline type& operator *=(const type& rhs) { return arithmetic::multiply(*this, rhs); }
	inline type& operator /=(const type& rhs) { return arithmetic::divide(*this, rhs); }
	inline type& operator %=(const type& rhs) { return arithmetic::modulus(*this, rhs); }

	inline type& operator <<=(cs_t rhs)  { return arithmetic::left_shift(*this, rhs); }
	inline type& operator >>=(cs_t rhs)  { return arithmetic::right_shift(*this, rhs); }

	inline type& operator &=(const type& rhs) { return bitwise::and_op(*this, rhs); }
	inline type& operator |=(const type& rhs) { return bitwise::or_op(*this, rhs); }
	inline type& operator ^=(const type& rhs) { return bitwise::xor_op(*this, rhs); }

	inline type operator ~() const { return bitwise::neg_op(*this); }

	inline bool operator !() const { return logic::not_op(*this); }

	inline type operator +() const { return *this; }
	inline type operator -() const { type tmp(*this); return arithmetic::multiply_none(tmp); }

	// prefix
	inline type& operator ++() { return arithmetic::inc(*this); }
	inline type& operator --() { return arithmetic::dec(*this); }

	// postfix
	inline type operator ++(int) { type tmp(*this); arithmetic::inc(*this); return tmp; }
	inline type operator --(int) { type tmp(*this); arithmetic::dec(*this); return tmp; }

	inline ut& operator[](cs_t index) { return comp[index]; }
	inline ut operator[](cs_t index) const { return comp[index]; }

	inline friend type operator +(const type& lhs, const type& rhs) { return type(lhs) += rhs; }
	inline friend type operator -(const type& lhs, const type& rhs) { return type(lhs) -= rhs; }
	inline friend type operator *(const type& lhs, const type& rhs) { return type(lhs) *= rhs; }
	inline friend type operator /(const type& lhs, const type& rhs) { return type(lhs) /= rhs; }
	inline friend type operator %(const type& lhs, const type& rhs) { return type(lhs) %= rhs; }

	inline friend type operator <<(const type& lhs, cu_t rhs) { return type(lhs) <<= rhs; }
	inline friend type operator >>(const type& lhs, cu_t rhs) { return type(lhs) >>= rhs; }

	inline friend type operator &(const type& lhs, const type& rhs) { return type(lhs) &= rhs; }
	inline friend type operator |(const type& lhs, const type& rhs) { return type(lhs) |= rhs; }
	inline friend type operator ^(const type& lhs, const type& rhs) { return type(lhs) ^= rhs; }

	inline friend bool operator &&(const type& lhs, const type& rhs) { return logic::and_op(lhs, rhs); }
	inline friend bool operator ||(const type& lhs, const type& rhs) { return logic::or_op(lhs, rhs); }

	inline friend bool operator ==(const type& lhs, const type& rhs) { return logic::equal(lhs, rhs); }
	inline friend bool operator !=(const type& lhs, const type& rhs) { return logic::not_equal(lhs, rhs); }

	inline friend bool operator > (const type& lhs, const type& rhs) { return logic::greater_than(lhs, rhs); }
	inline friend bool operator >=(const type& lhs, const type& rhs) { return logic::greater_than_equal(lhs, rhs); }
	inline friend bool operator < (const type& lhs, const type& rhs) { return logic::less_than(lhs, rhs); }
	inline friend bool operator <=(const type& lhs, const type& rhs) { return logic::less_than_equal(lhs, rhs); }
};

}

#endif // MATHX_BASE_INT_T_HPP
