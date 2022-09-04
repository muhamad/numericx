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
** File:  int_nc.hpp
**
** Purpose: numeric_cast implementation
**
===========================================================*/

#ifndef MATHX_CAST_INT_NC_HPP
#define MATHX_CAST_INT_NC_HPP

namespace mathx
{

// TODO: modify following macros to include more base classes after implementing float_t, fixed_t.

#define MATHX_DEFINE_NC(tn, base_type) \
template<> \
struct numeric_cast<tn> \
		: public imp::value_t<tn>, \
		  public mxi::base_type<tn> \
{ \
	typedef imp::value_t<tn> vt; \
	typedef mxi::base_type<tn> base; \
\
	inline numeric_cast<tn>(const tn& input) : vt(input), base( dynamic_cast<vt&>(*this) ) {} \
};

#define MATHX_DEFINE_NC2(tn, base_type) \
template<> \
struct numeric_cast<tn> \
		: public imp::value_t<tn>, public mxi::base_type \
{ \
	typedef imp::value_t<tn> vt; \
	typedef mxi::base_type base; \
\
	inline numeric_cast<tn>(const tn& input) : vt(input), base( dynamic_cast<vt&>(*this) ) {} \
};


////////////////////////////////
// FROM BOOLEAN TO MATHX TYPE //
////////////////////////////////

MATHX_DEFINE_NC2(bool, bool_to_inum)

/////////////////////////////////////////
// FROM NATIVE CHAR TYPE TO MATHX TYPE //
/////////////////////////////////////////

// from char to int_t/uint_t
MATHX_DEFINE_NC(char, int_to_inum)

// from signed char to int_t/uint_t
MATHX_DEFINE_NC(signed char, int_to_inum)

// from unsigned char to int_t/uint_t
MATHX_DEFINE_NC(unsigned char, int_to_inum)

// from wchar_t to int_t/uint_t
MATHX_DEFINE_NC(wchar_t, int_to_inum)

//////////////////////////////////////////////
// FROM NATIVE SIGNED INTEGER TO MATHX TYPE //
//////////////////////////////////////////////

// from signed short int to int_t/uint_t
MATHX_DEFINE_NC(signed short int, int_to_inum)

// from signed int to int_t/uint_t
MATHX_DEFINE_NC(signed int, int_to_inum)

// from signed long int to int_t/uint_t
MATHX_DEFINE_NC(signed long int, int_to_inum)

// from signed long long int to int_t/uint_t
MATHX_DEFINE_NC(signed long long int, int_to_inum)

////////////////////////////////////////////////
// FROM NATIVE UNSIGNED INTEGER TO MATHX TYPE //
////////////////////////////////////////////////

// from unsigned short int to int_t/uint_t
MATHX_DEFINE_NC(unsigned short int, int_to_inum)

// from unsigned int to int_t/uint_t
MATHX_DEFINE_NC(unsigned int, int_to_inum)

// from unsigned long int to int_t/uint_t
MATHX_DEFINE_NC(unsigned long int, int_to_inum)

// from unsigned long long int to int_t/uint_t
MATHX_DEFINE_NC(unsigned long long int, int_to_inum)


///////////////////////////////////////////
// FROM NATIVE FLOAT-POINT TO MATHX TYPE //
///////////////////////////////////////////

#if MATHX_ALLOW_NATIVE_FP_CONVERTION == MATHX_TRUE

// from float to int_t/uint_t
MATHX_DEFINE_NC(float, float_to_inum)

// from double to int_t/uint_t
MATHX_DEFINE_NC(double, float_to_inum)

// from long double to int_t/uint_t
MATHX_DEFINE_NC(long double, float_to_inum)

#endif

#undef MATHX_DEFINE_NC
#undef MATHX_DEFINE_NC2

///////////////////////
// FROM INT_T TO ANY //
///////////////////////

// from int_t to:
//   int_t: with all different cases.
//  uint_t: with all different cases.
//	  ni: all native integer types.
//	  nf: all native float-point types.
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct numeric_cast< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	   : public imp::value_t< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >,
		 public mxi::int_t_to_any<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>
{
	typedef int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> num_t;
	typedef imp::value_t<num_t> vt;
	typedef mxi::int_t_to_any<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> base;
	
	numeric_cast<num_t>(const num_t& input) : vt(input), base( dynamic_cast<vt&>(*this) ) {}
};

////////////////////////
// FROM UINT_T TO ANY //
////////////////////////

// from uint_t to:
//   int_t: with all different cases.
//  uint_t: with all different cases.
//	  ni: all native integer types.
//	  nf: all native float-point types.
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct numeric_cast< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
	   : public imp::value_t< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >,
		 public mxi::uint_t_to_any<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>
{
	typedef uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> num_t;
	typedef imp::value_t<num_t> vt;
	typedef mxi::uint_t_to_any<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> base;
	
	numeric_cast<num_t>(const num_t& input) : vt(input), base( dynamic_cast<vt&>(*this) ) {}
};

}

#endif // MATHX_CAST_INT_NC_HPP
