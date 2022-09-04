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
** Purpose: int_contract specialization for int_t/uint_t
**
===========================================================*/

#ifndef MATHX_INT_IMP_PREDEFINED_HPP
#define MATHX_INT_IMP_PREDEFINED_HPP

namespace mathx
{

//////////////////////////
// INT_T SPECILAIZATION //
//////////////////////////

// range functions
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_range< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	: public mxi::default_range< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> > {};

// bitwise functions
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_bitwise< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	: public mxi::default_bitwise< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> > {};

// logic functions
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_logic< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	: public mxi::default_logic< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> > {};

// arithmetic functions
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_arithmetic< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	: public mxi::default_arithmetic< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> > {};

// metadata constants
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_meta< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	: public mxi::default_meta< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> > {};


///////////////////////////
// UINT_T SPECILAIZATION //
///////////////////////////

// range functions
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_range< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	: public mxi::default_range< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> > {};

// bitwise functions
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_bitwise< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	: public mxi::default_bitwise< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> > {};

// logic functions
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_logic< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	: public mxi::default_logic< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> > {};

// arithmetic functions
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_arithmetic< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	: public mxi::default_arithmetic< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> > {};

// metadata constants
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_meta< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	: public mxi::default_meta< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> > {};

}

#endif // MATHX_INT_IMP_PREDEFINED_HPP
