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
** Purpose: numeric_cast common implementation
**
===========================================================*/

#ifndef MATHX_INT_NC_IMP_CMN_HPP
#define MATHX_INT_NC_IMP_CMN_HPP

namespace mathx
{
namespace mxi
{

// from boolean to int_t/uint_t
struct bool_to_inum
{
	const imp::value_t<bool>& vt;

	inline bool_to_inum(imp::value_t<bool>& input) : vt(input) {}

	template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
			 template <typename> class range_t, template <typename> class bitwise_t,
			 template <typename> class logic_t, template <typename> class arithmetic_t,
			 template <typename> class meta_t>
	inline operator int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>()
	{
		typedef int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> out_t;
		out_t result;

		if (vt.value) return out_t::range::set_one(result);
		return out_t::range::set_zero(result);
	}

	template<cu_t bits_count, typename ut_t, typename udt_t,
			 template <typename> class range_t, template <typename> class bitwise_t,
			 template <typename> class logic_t, template <typename> class arithmetic_t,
			 template <typename> class meta_t>
	inline operator uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>()
	{
		typedef uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> out_t;
		out_t result;

		if (vt.value) return out_t::range::set_one(result);
		return out_t::range::set_zero(result);
	}
};

// from native integer to int_t/uint_t
// ni_t: native integer type
template<typename ni_t>
struct int_to_inum
{
	const imp::value_t<ni_t>& vt;

	inline int_to_inum<ni_t>(const imp::value_t<ni_t>& input) : vt(input) {}

	template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
			 template <typename> class range_t, template <typename> class bitwise_t,
			 template <typename> class logic_t, template <typename> class arithmetic_t,
			 template <typename> class meta_t>
	inline operator int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>()
	{
		typedef int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> out_t;
		out_t result;

		return int_from_ni_to_t<out_t, ni_t>(vt.value, result);
	}

	template<cu_t bits_count, typename ut_t, typename udt_t,
			 template <typename> class range_t, template <typename> class bitwise_t,
			 template <typename> class logic_t, template <typename> class arithmetic_t,
			 template <typename> class meta_t>
	inline operator uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>()
	{
		typedef uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> out_t;
		out_t result;

		if (meta::info_t<ni_t>::is_signed)
			return  int_from_ni_to_t<out_t, ni_t>(vt.value, result);
		else
			return int_from_pni_to_t<out_t, ni_t>(vt.value, result);
	}
};

// from native float-point to int_t/uint_t
// flt_t: native float-point type
template<typename flt_t>
struct float_to_inum
{
	const imp::value_t<flt_t>& vt;

	inline float_to_inum<flt_t>(const imp::value_t<flt_t>& input) : vt(input) {}

	template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
			 template <typename> class range_t, template <typename> class bitwise_t,
			 template <typename> class logic_t, template <typename> class arithmetic_t,
			 template <typename> class meta_t>
	inline operator int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>()
	{
		typedef int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> out_t;
		out_t result;

		return int_from_nf_to_t<out_t, flt_t>(vt.value, result);
	}

	template<cu_t bits_count, typename ut_t, typename udt_t,
			 template <typename> class range_t, template <typename> class bitwise_t,
			 template <typename> class logic_t, template <typename> class arithmetic_t,
			 template <typename> class meta_t>
	inline operator uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>()
	{
		typedef uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> out_t;
		out_t result;

		return  int_from_nf_to_t<out_t, flt_t>(vt.value, result);
	}
};

// from int_t/uint_t to native type
// parent_t: type with value
// num_t: int_t/uint_t
template<typename num_t>
struct inum_to_native
{
	const imp::value_t<num_t>& vt;

	inline inum_to_native<num_t>(const imp::value_t<num_t>& input) : vt(input) {}

	inline operator char()	  { return execute<char>(); }

	inline operator int8_t()	{ return execute<int8_t>(); }

	inline operator int16_t()   { return execute<int16_t>(); }

	inline operator int32_t()   { return execute<int32_t>(); }

	inline operator long_t()	{ return execute<long_t>(); }

	inline operator int64_t()   { return execute<int64_t>(); }

	inline operator uint8_t()   { return execute<uint8_t>(); }

	inline operator uint16_t()  { return execute<uint16_t>(); }

	inline operator uint32_t()  { return execute<uint32_t>(); }

	inline operator ulong_t()   { return execute<ulong_t>(); }

	inline operator uint64_t()  { return execute<uint64_t>(); }

#if MATHX_ALLOW_NATIVE_FP_CONVERTION == MATHX_TRUE

	inline operator float32_t() { return execute<float32_t>(); }

	inline operator float64_t() { return execute<float64_t>(); }

	inline operator floatld_t() { return execute<floatld_t>(); }

#endif

	inline operator bool()
	{
		if(num_t::range::is_zero(vt.value)) return false;
		return true;
	}

private:
	// execute conversion from type to native
	template<typename built_t>
	inline built_t execute()
	{
		built_t result;

		if(meta::info_t<built_t>::is_integer)
			return int_from_t_to_ni<num_t, built_t>(vt.value, result);
		else
			return int_from_t_to_nf<num_t, built_t>(vt.value, result);
	}
};

// from int_t to any
template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct int_t_to_any
	   : public inum_to_native< int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
{
	typedef int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> num_t;
	typedef inum_to_native<num_t> base;
	const imp::value_t<num_t>& vt;
	
	int_t_to_any(const imp::value_t<num_t>& input) : vt(input), base(input) {}

	// call copy constructor instead of conversion function
	inline operator num_t()
	{
		return vt.value;
	}

	// source and result type are different in signedness
	inline operator uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>()
	{
		typedef uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> out_t;

		return *(out_t*)&(vt.value);
	}

	// source and result type have different algorithms or bits count
	template<cu_t bits_count2,
			 template <typename> class range_t2, template <typename> class bitwise_t2,
			 template <typename> class logic_t2, template <typename> class arithmetic_t2,
			 template <typename> class meta_t2>
	inline operator int_t<bits_count2, ut_t, st_t, udt_t, sdt_t, range_t2, bitwise_t2, logic_t2, arithmetic_t2, meta_t2>()
	{
		typedef int_t<bits_count2, ut_t, st_t, udt_t, sdt_t, range_t2, bitwise_t2, logic_t2, arithmetic_t2, meta_t2> out_t;
		out_t result;

		return mxi::int_from_sut_to_sut<num_t, out_t>(vt.value, result);
	}

	// source and result type have different algorithms or bits count
	template<cu_t bits_count2,
			 template <typename> class range_t2, template <typename> class bitwise_t2,
			 template <typename> class logic_t2, template <typename> class arithmetic_t2,
			 template <typename> class meta_t2>
	inline operator uint_t<bits_count2, ut_t, udt_t, range_t2, bitwise_t2, logic_t2, arithmetic_t2, meta_t2>()
	{
		typedef uint_t<bits_count2, ut_t, udt_t, range_t2, bitwise_t2, logic_t2, arithmetic_t2, meta_t2> out_t;
		out_t result;

		return mxi::int_from_sut_to_sut<num_t, out_t>(vt.value, result);
	}
};

// from int_t to any
template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t>
struct uint_t_to_any
	   : public inum_to_native< uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> >
{
	typedef uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> num_t;
	typedef inum_to_native<num_t> base;
	const imp::value_t<num_t>& vt;
	
	uint_t_to_any(const imp::value_t<num_t>& input) : vt(input), base(input) {}

	// call copy constructor instead of conversion function
	inline operator num_t()
	{
		return vt.value;
	}

	// source and result type are different in signedness
	template<typename st_t, typename sdt_t>
	inline operator int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>()
	{
		typedef int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t> out_t;

		return *(out_t*)&(vt.value);
	}

	// source and result type have different algorithms or bits count
	template<cu_t bits_count2,
			 template <typename> class range_t2, template <typename> class bitwise_t2,
			 template <typename> class logic_t2, template <typename> class arithmetic_t2,
			 template <typename> class meta_t2>
	inline operator uint_t<bits_count2, ut_t, udt_t, range_t2, bitwise_t2, logic_t2, arithmetic_t2, meta_t2>()
	{
		typedef uint_t<bits_count2, ut_t, udt_t, range_t2, bitwise_t2, logic_t2, arithmetic_t2, meta_t2> out_t;
		out_t result;

		return mxi::int_from_sut_to_sut<num_t, out_t>(vt.value, result);
	}

	// source and result type have different algorithms or bits count
	template<cu_t bits_count2, typename st_t, typename sdt_t,
			 template <typename> class range_t2, template <typename> class bitwise_t2,
			 template <typename> class logic_t2, template <typename> class arithmetic_t2,
			 template <typename> class meta_t2>
	inline operator int_t<bits_count2, ut_t, st_t, udt_t, sdt_t, range_t2, bitwise_t2, logic_t2, arithmetic_t2, meta_t2>()
	{
		typedef int_t<bits_count2, ut_t, st_t, udt_t, sdt_t, range_t2, bitwise_t2, logic_t2, arithmetic_t2, meta_t2> out_t;
		out_t result;

		return mxi::int_from_sut_to_sut<num_t, out_t>(vt.value, result);
	}
};

}
}

#endif // MATHX_INT_NC_IMP_CMN_HPP
