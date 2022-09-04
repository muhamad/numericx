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
** File:  imp_cmn.hpp
**
** Purpose: mathematical library common implementation
**
===========================================================*/

#ifndef MATHX_MATH_IMP_CMN_HPP
#define MATHX_MATH_IMP_CMN_HPP

namespace mathx
{
namespace math
{

MATHX_DCL_INT_T_TEMPLATE inline
MATHX_DEF_INT_T_TYPE& abs(const MATHX_DEF_INT_T_TYPE& value, MATHX_DEF_INT_T_TYPE& result)
{
	typedef MATHX_DEF_INT_T_TYPE type;
	return math_imp::int_abs<type>(value, result);
}

MATHX_DCL_UINT_T_TEMPLATE inline
MATHX_DEF_UINT_T_TYPE abs(const MATHX_DEF_UINT_T_TYPE& value, MATHX_DEF_UINT_T_TYPE& result)
{
	//typedef MATHX_DEF_UINT_T_TYPE type;
	//return math_imp::int_abs<type>(value, result);
	if (&result == &value) return result;
	return result = value;
}

MATHX_DCL_INT_T_TEMPLATE inline
MATHX_DEF_INT_T_TYPE& abs(MATHX_DEF_INT_T_TYPE& value)
{
	typedef MATHX_DEF_INT_T_TYPE type;
	return math_imp::int_abs<type>(value, value);
}

MATHX_DCL_UINT_T_TEMPLATE inline
MATHX_DEF_UINT_T_TYPE& abs(MATHX_DEF_UINT_T_TYPE& value)
{
	//typedef MATHX_DEF_UINT_T_TYPE type;
	//return math_imp::int_abs<type>(value, value);
	return value;
}

MATHX_DCL_INT_T_TEMPLATE inline
cs_t sign(const MATHX_DEF_INT_T_TYPE& value)
{
	typedef MATHX_DEF_INT_T_TYPE type;
	return math_imp::int_get_sign<type>(value);
}

MATHX_DCL_UINT_T_TEMPLATE inline
cs_t sign(const MATHX_DEF_UINT_T_TYPE& value)
{
	typedef MATHX_DEF_UINT_T_TYPE type;
	return math_imp::int_get_sign<type>(value);
}

MATHX_DCL_INT_T_TEMPLATE inline
const MATHX_DEF_INT_T_TYPE& min(const MATHX_DEF_INT_T_TYPE& v1, const MATHX_DEF_INT_T_TYPE& v2)
{
	typedef MATHX_DEF_INT_T_TYPE type;
	return math_imp::int_min_max<type, true>(v1, v2);
}

MATHX_DCL_UINT_T_TEMPLATE inline
const MATHX_DEF_UINT_T_TYPE& min(const MATHX_DEF_UINT_T_TYPE& v1, const MATHX_DEF_UINT_T_TYPE& v2)
{
	typedef MATHX_DEF_UINT_T_TYPE type;
	return math_imp::int_min_max<type, true>(v1, v2);
}

MATHX_DCL_INT_T_TEMPLATE inline
MATHX_DEF_INT_T_TYPE& min(MATHX_DEF_INT_T_TYPE& v1, MATHX_DEF_INT_T_TYPE& v2)
{
	typedef MATHX_DEF_INT_T_TYPE type;
	return math_imp::int_min_max<type, true>(v1, v2);
}

MATHX_DCL_UINT_T_TEMPLATE inline
MATHX_DEF_UINT_T_TYPE& min(MATHX_DEF_UINT_T_TYPE& v1, MATHX_DEF_UINT_T_TYPE& v2)
{
	typedef MATHX_DEF_UINT_T_TYPE type;
	return math_imp::int_min_max<type, true>(v1, v2);
}

MATHX_DCL_INT_T_TEMPLATE inline
const MATHX_DEF_INT_T_TYPE& max(const MATHX_DEF_INT_T_TYPE& v1, const MATHX_DEF_INT_T_TYPE& v2)
{
	typedef MATHX_DEF_INT_T_TYPE type;
	return math_imp::int_min_max<type, false>(v1, v2);
}

MATHX_DCL_UINT_T_TEMPLATE inline
const MATHX_DEF_UINT_T_TYPE& max(const MATHX_DEF_UINT_T_TYPE& v1, const MATHX_DEF_UINT_T_TYPE& v2)
{
	typedef MATHX_DEF_UINT_T_TYPE type;
	return math_imp::int_min_max<type, false>(v1, v2);
}

MATHX_DCL_INT_T_TEMPLATE inline
MATHX_DEF_INT_T_TYPE& max(MATHX_DEF_INT_T_TYPE& v1, MATHX_DEF_INT_T_TYPE& v2)
{
	typedef MATHX_DEF_INT_T_TYPE type;
	return math_imp::int_min_max<type, false>(v1, v2);
}


MATHX_DCL_UINT_T_TEMPLATE inline
MATHX_DEF_UINT_T_TYPE& max(MATHX_DEF_UINT_T_TYPE& v1, MATHX_DEF_UINT_T_TYPE& v2)
{
	typedef MATHX_DEF_UINT_T_TYPE type;
	return math_imp::int_min_max<type, false>(v1, v2);
}

template<typename type> inline
bool can_save_fact_digits(cu_t value)
{
	return math_imp::int_fact_digits_in_range<type>(value);
}

MATHX_DCL_INT_T_TEMPLATE inline
bool factorial(cu_t value, MATHX_DEF_INT_T_TYPE& obj)
{
	typedef MATHX_DEF_INT_T_TYPE type;
	return math_imp::compute_fact<type>(value, obj);
}

MATHX_DCL_UINT_T_TEMPLATE inline
bool factorial(cu_t value, MATHX_DEF_UINT_T_TYPE& obj)
{
	typedef MATHX_DEF_UINT_T_TYPE type;
	return math_imp::compute_fact<type>(value, obj);
}

}
}

#endif // MATHX_MATH_IMP_CMN_HPP
