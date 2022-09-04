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
** File:  meta.hpp
**
** Purpose: int_t/uint_t implementation for info_t and int_info
**
===========================================================*/

#ifndef MATHX_INT_IMP_META_HPP
#define MATHX_INT_IMP_META_HPP

namespace mathx
{
namespace meta
{

// partial specialization for int_t
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct info_t< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
{
	// input type
	typedef int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> type;

	// is native type
	static const bool is_native = false;
	// is integer type
	static const bool is_integer = true;
	// is signed type
	static const bool is_signed = true;
	// is float-point type
	static const bool is_float   = false;
	// number of bytes in type
	static const ts_t num_of_bytes = bits_count / MATHX_BIT;
	// number of bits in type
	static const ts_t num_of_bits = bits_count;
	// type id
	static const type_id id = ti_int_t;
};

// partial specialization for uint_t
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct info_t< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
{
	// input type
	typedef uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> type;

	// is native type
	static const bool is_native = false;
	// is integer type
	static const bool is_integer = true;
	// is signed type
	static const bool is_signed = false;
	// is float-point type
	static const bool is_float   = false;
	// number of bytes in type
	static const ts_t num_of_bytes = bits_count / MATHX_BIT;
	// number of bits in type
	static const ts_t num_of_bits = bits_count;
	// type id
	static const type_id id = ti_uint_t;
};

// partial specialization for int_t
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_info< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
{
	// input type
	typedef int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> type;
	typedef info_t<type> info;

	// is native type
	static const bool is_native = info::is_native;
	// is signed type
	static const bool is_signed = info::is_signed;
	// number of bits in type
	static const ts_t all_bits = info::num_of_bits;
	// number of bits used for data
	static const ts_t used_bits = info::num_of_bits - 1;
	// number of bits in one component
	static const ts_t comp_bits = mxi::isizeof<ut_t>::value;
	// number of binary digits in type
	static const ts_t bin_digits = mxi::num_of_bin_digits_in_type<type>::value;
	// number of octal digits in type
	static const ts_t oct_digits = mxi::num_of_oct_digits_in_type<type>::value;
	// number of decimal digits in type
	static const ts_t dec_digits = mxi::num_of_dec_digits_in_type<type>::value;
	// number of hexadecimal digits in type
	static const ts_t hex_digits = mxi::num_of_hex_digits_in_type<type>::value;
};

// partial specialization for int_t
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_info< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
{
	// input type
	typedef uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> type;
	typedef info_t<type> info;

	// is native type
	static const bool is_native = info::is_native;
	// is signed type
	static const bool is_signed = info::is_signed;
	// number of bits in type
	static const ts_t all_bits = info::num_of_bits;
	// number of bits used for data
	static const ts_t used_bits = info::num_of_bits;
	// number of bits in one component
	static const ts_t comp_bits = mxi::isizeof<ut_t>::value;
	// number of binary digits in type
	static const ts_t bin_digits = mxi::num_of_bin_digits_in_type<type>::value;
	// number of octal digits in type
	static const ts_t oct_digits = mxi::num_of_oct_digits_in_type<type>::value;
	// number of decimal digits in type
	static const ts_t dec_digits = mxi::num_of_dec_digits_in_type<type>::value;
	// number of hexadecimal digits in type
	static const ts_t hex_digits = mxi::num_of_hex_digits_in_type<type>::value;
};

}
}

#endif // MATHX_INT_IMP_META_HPP
