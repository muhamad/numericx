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
** Purpose: string_cast common implementation
**
===========================================================*/

#ifndef MATHX_INT_SC_IMP_CMN_HPP
#define MATHX_INT_SC_IMP_CMN_HPP

namespace mathx
{
namespace mxi
{

template<typename num_type, typename str_type, typename base_type>
struct native_string_cast
{
	inline static cs_t length(const num_type& n)
	{
		if (!base_type::is_specialized)
		{
			if (base_type::base == 10)
				return int_len_dec<num_type>(n);
			else
				return int_len_bas<num_type, base_type>(n);
		}
		else
			return int_len_any<num_type, base_type>(n);
	}

	inline static bool from(const str_type s, num_type& n)
	{
		if (!base_type::is_specialized)
		{
			if (base_type::base == 10)
				return int_fstr_dec<num_type, base_type>(s, n);
			else
				return int_fstr_bas<num_type, base_type>(s, n);
		}
		else
			return int_fstr_any<num_type, base_type>(s, n);
	}

	inline static bool to(str_type s, const num_type& n)
	{
		return to(s, n, false);
	}

	inline static bool to(str_type s, const num_type& n, bool upper)
	{
		if (!base_type::is_specialized)
		{
			if (base_type::base == 10)
				return int_tstr_dec<num_type, base_type>(n, s);
			else
				return int_tstr_bas<num_type, base_type>(n, s, upper);
		}
		else
			return int_tstr_any<num_type, base_type>(n, s, upper);
	}
};

template<typename num_type, typename str_type, typename base_type>
struct basic_string_cast
{
	inline static cs_t length(const num_type& n)
	{
		if (!base_type::is_specialized)
		{
			if (base_type::base == 10)
				return int_len_dec<num_type>(n);
			else
				return int_len_bas<num_type, base_type>(n);
		}
		else
			return int_len_any<num_type, base_type>(n);
	}

	inline static bool from(const str_type& s, num_type& n)
	{
		if (!base_type::is_specialized)
		{
			if (base_type::base == 10)
				return int_fstr_dec<num_type, base_type>(s.c_str(), n);
			else
				return int_fstr_bas<num_type, base_type>(s.c_str(), n);
		}
		else
			return int_fstr_any<num_type, base_type>(s.c_str(), n);
	}

	inline static bool to(str_type& s, const num_type& n)
	{
		return to(s, n, false);
	}

	inline static bool to(str_type& s, const num_type& n, bool upper)
	{
		typedef typename str_type::value_type char_t;

		cu_t digits = 0;

		if (base_type::is_specialized)
			digits = num_of_base_digits_in_type<num_type::meta::all_bits, base_type::base>::value;
		else
		{
			switch(base_type::base)
			{
			case 2:
				digits = num_type::meta::bin_digits_count;
				break;

			case 8:
				digits = num_type::meta::oct_digits_count;
				break;

			case 10:
				digits = num_type::meta::dec_digits_count;
				break;
			
			default:
				digits = num_type::meta::hex_digits_count;
			}
		}

		if (num_type::meta::is_signed) ++digits;
		
		if (s.size() < digits)
		{
			// don't call resize it will copy if current buffer can't extended
			s.~basic_string();
			new (&s) str_type(digits, 0);
		}
		else
			s.assign(s.size(), 0);

		bool ret = true;

		if (base_type::is_specialized)
			ret = int_tstr_any<num_type, base_type>(n, (char_t*)s.c_str(), upper);
		else
		{
			if (base_type::base == 10)
				ret = int_tstr_dec<num_type, base_type>(n, (char_t*)s.c_str());
			else
				ret = int_tstr_bas<num_type, base_type>(n, (char_t*)s.c_str(), upper);
		}
		
		if (ret == false) return false;

		int start = 0, end = digits - 1, trace = start;

		if (s[end] != 0) return ret;

		if (s[end] == 0 && s[end-1] != 0)
			start = end;
		else
		{
			while(end > start)
			{
				if (s[start] != 0)
				{
					trace = start;
					start += (end - start) >> 1;
					continue;
				}

				if (s[start-1] != 0) break;

				if (s[start] == 0)
				{
					end = start;
					start = trace;
					continue;
				}
			}
		}
		s.erase(start);

		return ret;
	}
};

}
}

#endif // MATHX_INT_SC_IMP_CMN_HPP
