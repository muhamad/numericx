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
** File:  string_id.hpp
**
** Purpose: string data-type identification
**
===========================================================*/

#ifndef MATHX_COMMON_HELPER_STRING_ID_HPP
#define MATHX_COMMON_HELPER_STRING_ID_HPP

namespace mathx
{
namespace meta
{

// size information
template <typename t>
struct size_info
{
	// number of bytes in t
	static const ts_t char_byte_size = sizeof(t);
	// number of bits in t
	static const ts_t char_bits_size = mxi::isizeof<t>::value;
};

// character information
template<typename charT>
struct char_info;

// string information
template<typename stringT>
struct string_info;

}
}

namespace mathx
{
namespace imp
{

// character info base class
template<typename charT, ts_t _id, bool _known>
struct base_ci
{
	typedef charT char_t;
	typedef meta::size_info<char_t> size;

	static const ts_t id = _id;
	static const bool is_known_char = _known;
};

// string info base class
template<typename stringT, typename charT, ts_t _id, bool _native, bool _stl>
struct base_si
{
	typedef charT				   char_t;
	typedef charT*					str_t;
	typedef meta::char_info<charT>  cinfo;

	typedef stringT  stl_t;

	static const ts_t id = _id;
	static const bool is_native = _native;
	static const bool is_stl = _stl;
};

}
}

namespace mathx
{
namespace meta
{

// [char] type information
template <> struct char_info<char> : public imp::base_ci<char, 1, true> {};

// [wchar_t] type information
template <> struct char_info<wchar_t> : public imp::base_ci<wchar_t, 2, true> {};

// [char*] type information
template<> struct string_info<char*> : public imp::base_si<char*, char, 1, true, false> {};

// [wchar_t*] type information
template<> struct string_info<wchar_t*> : public imp::base_si<wchar_t*, wchar_t, 2, true, false> {};

// [std::string] type information
template<>
struct string_info<std::string> : public imp::base_si<std::string, char, 3, false, true> {};

// [std::wstring] type information
template<>
struct string_info<std::wstring> : public imp::base_si<std::wstring, wchar_t, 4, false, true> {};

// [std::basic_string<char, traits, allocator>] type information
template<typename traits, typename allocator>
struct string_info< std::basic_string<char, traits, allocator> >
	: public imp::base_si< std::basic_string<char, traits, allocator>, char, 5, false, true> {};

// [std::basic_string<wchar_t, traits, allocator>] type information
template<typename traits, typename allocator>
struct string_info< std::basic_string<wchar_t, traits, allocator> >
	: public imp::base_si< std::basic_string<wchar_t, traits, allocator>, wchar_t, 6, false, true> {};

}
}

#endif // MATHX_COMMON_HELPER_STRING_ID_HPP
