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
** File:  math.hpp
**
** Purpose: mathematical library
**
===========================================================*/

#ifndef MATHX_MATH_MATH_HPP
#define MATHX_MATH_MATH_HPP

namespace mathx
{
namespace math
{
	//
	// Absolute function
	// get absolute value of input object.
	// support int_t, uint_t
	//
	// value: get its absolute value.
	// result: save absolute value in it.
	// return result.
	//
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& abs(const MATHX_DEF_INT_T_TYPE& value, MATHX_DEF_INT_T_TYPE& result);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE abs(const MATHX_DEF_UINT_T_TYPE& value, MATHX_DEF_UINT_T_TYPE& result);
	//
	// value: save absolute value in it.
	// return value.
	//
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& abs(MATHX_DEF_INT_T_TYPE& value);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& abs(MATHX_DEF_UINT_T_TYPE& value);



	//
	// Sign function
	// get sign of input object
	// support int_t, uint_t
	//
	// return 0 for zero, -1 for negative value, 1 for positive value
	MATHX_DCL_INT_T_TEMPLATE inline
	cs_t sign(const MATHX_DEF_INT_T_TYPE& value);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	cs_t sign(const MATHX_DEF_UINT_T_TYPE& value);



	//
	// Minimum value function
	// get minimum of two inputs
	// support int_t, uint_t
	//
	// return const reference to object
	MATHX_DCL_INT_T_TEMPLATE inline
	const MATHX_DEF_INT_T_TYPE& min(const MATHX_DEF_INT_T_TYPE& v1, const MATHX_DEF_INT_T_TYPE& v2);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	const MATHX_DEF_UINT_T_TYPE& min(const MATHX_DEF_UINT_T_TYPE& v1, const MATHX_DEF_UINT_T_TYPE& v2);
	//
	// return reference to object
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& min(MATHX_DEF_INT_T_TYPE& v1, MATHX_DEF_INT_T_TYPE& v2);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& min(MATHX_DEF_UINT_T_TYPE& v1, MATHX_DEF_UINT_T_TYPE& v2);



	//
	// Maximum value function
	// get maximum of two inputs
	// support int_t, uint_t
	//
	// return const reference to object
	MATHX_DCL_INT_T_TEMPLATE inline
	const MATHX_DEF_INT_T_TYPE& max(const MATHX_DEF_INT_T_TYPE& v1, const MATHX_DEF_INT_T_TYPE& v2);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	const MATHX_DEF_UINT_T_TYPE& max(const MATHX_DEF_UINT_T_TYPE& v1, const MATHX_DEF_UINT_T_TYPE& v2);
	//
	// return reference to object with minimum value
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& max(MATHX_DEF_INT_T_TYPE& v1, MATHX_DEF_INT_T_TYPE& v2);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& max(MATHX_DEF_UINT_T_TYPE& v1, MATHX_DEF_UINT_T_TYPE& v2);



	//
	// Factorial Check function
	// determine if factorial of input value can be saved correctly in input type
	// support int_t, uint_t
	//
	template<typename type> inline
	bool can_save_fact_digits(cu_t value);



	//
	// Factorial function
	// support int_t, uint_t
	//
	// return false if result can not be saved in input object
	//
	MATHX_DCL_INT_T_TEMPLATE inline
	bool factorial(cu_t value, MATHX_DEF_INT_T_TYPE& obj);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	bool factorial(cu_t value, MATHX_DEF_UINT_T_TYPE& obj);



	//
	// Power function
	// compute base raised to exponent
	// support int_t, uint_t
	//
	// for int_t, uint_t if exponent is less than one zero returned.
	//
	// base: base value
	// exp: exponent value
	// result: object to store result in.
	//
	// note: if address of value equal to address of result a temporary object is created.
	// return result
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& pow(const MATHX_DEF_INT_T_TYPE& base, cs_t exp, MATHX_DEF_INT_T_TYPE& result);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& pow(const MATHX_DEF_UINT_T_TYPE& base, cs_t exp, MATHX_DEF_UINT_T_TYPE& result);
	//
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& pow(const MATHX_DEF_INT_T_TYPE& base, const MATHX_DEF_INT_T_TYPE& exp, MATHX_DEF_INT_T_TYPE& result);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& pow(const MATHX_DEF_UINT_T_TYPE& base, const MATHX_DEF_UINT_T_TYPE& exp, MATHX_DEF_UINT_T_TYPE& result);
	//
	//
	// base: base value, result saved in here
	// exp: exponent value
	//
	// note: temporary object is created.
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& pow(MATHX_DEF_INT_T_TYPE& base, cs_t exp);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& pow(MATHX_DEF_UINT_T_TYPE& base, cs_t exp);
	//
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& pow(MATHX_DEF_INT_T_TYPE& base, const MATHX_DEF_INT_T_TYPE& exp);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& pow(MATHX_DEF_UINT_T_TYPE& base, const MATHX_DEF_UINT_T_TYPE& exp);



	//
	// Square root function
	// support int_t, uint_t
	//
	// for int_t, uint_t it compute integer square root
	//
	// note: if address of value equal to address of result a temporary object is created.
	// return result
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& sqrt(const MATHX_DEF_INT_T_TYPE& value, MATHX_DEF_INT_T_TYPE& result);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& sqrt(const MATHX_DEF_UINT_T_TYPE& value, MATHX_DEF_UINT_T_TYPE& result);
	//
	// note: temporary object is created.
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& sqrt(MATHX_DEF_INT_T_TYPE& value);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& sqrt(MATHX_DEF_UINT_T_TYPE& value);



	//
	// Cube root function
	// support int_t, uint_t
	//
	// for int_t, uint_t it compute integer square root
	//
	// note: if address of value equal to address of result a temporary object is created.
	// return result
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& cbrt(const MATHX_DEF_INT_T_TYPE& value, MATHX_DEF_INT_T_TYPE& result);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& cbrt(const MATHX_DEF_UINT_T_TYPE& value, MATHX_DEF_UINT_T_TYPE& result);
	//
	// note: temporary object is created.
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& cbrt(MATHX_DEF_INT_T_TYPE& value);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& cbrt(MATHX_DEF_UINT_T_TYPE& value);



	//
	// Rotate left function
	// support uint_t
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& rol(const MATHX_DEF_UINT_T_TYPE& value, cu_t shift, MATHX_DEF_UINT_T_TYPE& result);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& rol(MATHX_DEF_UINT_T_TYPE& value, cu_t shift);



	//
	// Rotate right function
	// support uint_t
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& ror(const MATHX_DEF_UINT_T_TYPE& value, cu_t shift, MATHX_DEF_UINT_T_TYPE& result);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& ror(MATHX_DEF_UINT_T_TYPE& value, cu_t shift);



	//
	// Greatest common divisor function
	// support int_t, uint_t
	//
	// for int_t if negative value provided a temporary will created
	// if address of result equal to address of v1 or v2 a temporary will created
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& gcd(const MATHX_DEF_INT_T_TYPE& v1, const MATHX_DEF_INT_T_TYPE& v2, MATHX_DEF_INT_T_TYPE& result);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& gcd(const MATHX_DEF_UINT_T_TYPE& v1, const MATHX_DEF_UINT_T_TYPE& v2, MATHX_DEF_UINT_T_TYPE& result);
	//
	// note: temporary object is created.
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& gcd(MATHX_DEF_INT_T_TYPE& v1, MATHX_DEF_INT_T_TYPE& v2);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& gcd(MATHX_DEF_UINT_T_TYPE& v1, MATHX_DEF_UINT_T_TYPE& v2);



	//
	// Least common multiple function
	// support int_t, uint_t
	//
	// for int_t if negative value provided a temporary will created
	// if address of result equal to address of v1 or v2 a temporary will created
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& lcm(const MATHX_DEF_INT_T_TYPE& v1, const MATHX_DEF_INT_T_TYPE& v2, MATHX_DEF_INT_T_TYPE& result);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& lcm(const MATHX_DEF_UINT_T_TYPE& v1, const MATHX_DEF_UINT_T_TYPE& v2, MATHX_DEF_UINT_T_TYPE& result);
	//
	// note: temporary object is created.
	MATHX_DCL_INT_T_TEMPLATE inline
	MATHX_DEF_INT_T_TYPE& lcm(MATHX_DEF_INT_T_TYPE& v1, MATHX_DEF_INT_T_TYPE& v2);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	MATHX_DEF_UINT_T_TYPE& lcm(MATHX_DEF_UINT_T_TYPE& v1, MATHX_DEF_UINT_T_TYPE& v2);



	//
	// Ineger base2 logarithm function
	// support int_t, uint_t
	//
	// for int_t if input is negative -1 returned.
	MATHX_DCL_INT_T_TEMPLATE inline
	cs_t ilog2(const MATHX_DEF_INT_T_TYPE& value);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	cs_t ilog2(const MATHX_DEF_UINT_T_TYPE& value);



	//
	// Ineger base10 logarithm function
	// support int_t, uint_t
	//
	// for int_t if input is negative -1 returned.
	MATHX_DCL_INT_T_TEMPLATE inline
	cs_t ilog10(const MATHX_DEF_INT_T_TYPE& value);
	//
	MATHX_DCL_UINT_T_TEMPLATE inline
	cs_t ilog10(const MATHX_DEF_UINT_T_TYPE& value);
}
}

#endif // MATHX_MATH_MATH_HPP
