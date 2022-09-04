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
** File:  int_sc.hpp
**
** Purpose: string_cast implementation
**
===========================================================*/

#ifndef MATHX_CAST_INT_SC_HPP
#define MATHX_CAST_INT_SC_HPP

namespace mathx
{
// int_t, native string e.g. char*, wchar_t* etc...
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t, typename charT, typename baseT>
struct string_cast
	   < int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>, charT*, baseT>
	   : public mxi::native_string_cast< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>, charT*, baseT> {};

// uint_t, native string e.g. char*, wchar_t* etc...
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t, typename charT, typename baseT>
struct string_cast
	   < uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>, charT*, baseT >
	   : public mxi::native_string_cast< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>, charT*, baseT> {};

// int_t, basic_string class e.g. string, wstring and any basic_string<charT, traits, allocator>
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t,
		 typename charT, typename traits, typename allocator, typename baseT>
struct string_cast
	   < int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>, std::basic_string<charT, traits, allocator>, baseT>
	   : public mxi::basic_string_cast< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>, std::basic_string<charT, traits, allocator>, baseT> {};

// uint_t, basic_string class e.g. string, wstring and any basic_string<charT, traits, allocator>
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t,
		 typename charT, typename traits, typename allocator, typename baseT>
struct string_cast
	   < uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>, std::basic_string<charT, traits, allocator>, baseT>
	   : public mxi::basic_string_cast< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>, std::basic_string<charT, traits, allocator>, baseT> {};

}

#endif // MATHX_CAST_INT_SC_HPP
