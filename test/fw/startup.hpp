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
** File:  startup.hpp
**
** Purpose: validate compile-time types
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_STARTUP_HPP
#define MATHX_FRAMEWORK_STARTUP_HPP

namespace mathx
{
namespace test
{

namespace ti
{

template<typename t> struct int_id { static const ts_t value = 0; };
template<> struct int_id<char> { static const ts_t value = 1; };
template<> struct int_id<signed char> { static const ts_t value = 1; };
template<> struct int_id<unsigned char> { static const ts_t value = 1; };
template<> struct int_id<short> { static const ts_t value = 2; };
template<> struct int_id<unsigned short> { static const ts_t value = 2; };
template<> struct int_id<int> { static const ts_t value = 3; };
template<> struct int_id<unsigned int> { static const ts_t value = 3; };
template<> struct int_id<long> { static const ts_t value = 4; };
template<> struct int_id<unsigned long> { static const ts_t value = 4; };
template<> struct int_id<long long> { static const ts_t value = 5; };
template<> struct int_id<unsigned long long> { static const ts_t value = 5; };

template<typename t> struct float_id { static const ts_t value = 0; };
template<> struct float_id<float> { static const ts_t value = 6; };
template<> struct float_id<double> { static const ts_t value = 7; };
template<> struct float_id<long double> { static const ts_t value = 8; };

template<typename t> struct get_type_id
{ static const ts_t value = meta::info_t<t>::is_integer? int_id<t>::value: float_id<t>::value; };

}

struct startup
{

inline static bool check()
{
	using namespace ti;
	using std::cout;

	static const char* names[] =
	{
		"**unkown type**",
		"char",
		"short int",
		"int",
		"long int",
		"long long int",
		"float",
		"double",
		"long double"
	};

	const cs_t ts_idx  = get_type_id<mathx_st>::value;
	const cs_t tu_idx  = get_type_id<mathx_ut>::value;
	const cs_t tsd_idx = get_type_id<mathx_sdt>::value;
	const cs_t tud_idx = get_type_id<mathx_udt>::value;
	
	const cs_t cs_idx = get_type_id<cs_t>::value;
	const cs_t cu_idx = get_type_id<cu_t>::value;
	const cs_t fp_idx = get_type_id<fp_t>::value;

	const bool ts_signed = meta::info_t<mathx_st>::is_signed;
	const bool tu_signed = meta::info_t<mathx_ut>::is_signed;
	const bool tsd_signed = meta::info_t<mathx_sdt>::is_signed;
	const bool tud_signed = meta::info_t<mathx_udt>::is_signed;

	if (!meta::info_t<cs_t>::is_signed)
	{
		cout << forec(red, yes);
		cout << "cs_t a.k.a. [unsigned " << names[cs_idx] << "] is unsigned type.\n" << resetc;
		return false;
	}

	if (meta::info_t<cu_t>::is_signed)
	{
		cout << forec(red, yes);
		cout << "cu_t a.k.a. [signed " << names[cu_idx] << "] is signed type.\n" << resetc;
		return false;
	}

	if (sizeof(cs_t) != sizeof(cu_t))
	{
		cout << forec(red, yes);
		cout << "cs_t a.k.a. [signed " << names[cs_idx] << "] cu_t a.k.a. [unsigned " << names[cu_idx] << "]  don't have same size.\n";
		cout << resetc;
		return false;
	}
	
	if (!meta::info_t<fp_t>::is_float)
	{
		cout << forec(red, yes);
		cout << "fp_t a.k.a. [" << names[fp_idx] << "] is not float-point type.\n";
		cout << resetc;
		return false;
	}

	if (!ts_signed || !tsd_signed)
	{
		cout << forec(red, yes);

		bool signed_type = false;

		if (!ts_signed)
		{
			signed_type = true;
			cout << "mathx_st a.k.a. [unsigned " << names[ts_idx] << "]";
		}

		if (!tsd_signed)
		{
			if (signed_type) cout << " and ";
			cout << "mathx_sdt a.k.a. [unsigned " << names[tsd_idx] << "]";
		}
		else
			signed_type = false;

		cout << (signed_type? " are ": " is ");
		cout << "not signed type(s).\n" << resetc;
		return false;
	}

	if (tu_signed || tud_signed)
	{
		cout << forec(red, yes);

		bool unsigned_type = false;

		if (tu_signed)
		{
			unsigned_type = true;
			cout << "mathx_ut a.k.a. [signed " << names[tu_idx] << "]";
		}

		if (tud_signed)
		{
			if (unsigned_type) cout << " and ";
			cout << "mathx_udt a.k.a. [signed " << names[tud_idx] << "]";
		}
		else
			unsigned_type = false;

		cout << (unsigned_type? " are ": " is ");
		cout << "not unsigned type(s).\n" << resetc;
		return false;
	}

	if (sizeof(mathx_st) != sizeof(mathx_ut))
	{
		cout << forec(red, yes);
		cout << "mathx_st a.k.a. [signed " << names[ts_idx] << "] and mathx_ut a.k.a. [unsigned " << names[tu_idx] << "] don't have same size.\n";
		cout << resetc;
		return false;
	}

	if (sizeof(mathx_sdt) != sizeof(mathx_udt))
	{
		cout << forec(red, yes);
		cout << "mathx_sdt a.k.a. [signed " << names[tsd_idx] << "] and mathx_udt a.k.a. [unsigned " << names[tud_idx] << "] don't have same size.\n";
		cout << resetc;
		return false;
	}
	
	if (sizeof(mathx_sdt) != (sizeof(mathx_st) * 2))
	{
		cout << forec(red, yes);
		cout << "mathx_sdt a.k.a. [signed " << names[tsd_idx] << "] is not as twice in size as mathx_st a.k.a. [signed " << names[ts_idx] << "].\n";
		cout << resetc;
		return false;
	}

	if (sizeof(mathx_udt) != (sizeof(mathx_ut) * 2))
	{
		cout << forec(red, yes);
		cout << "mathx_udt a.k.a. [unsigned " << names[tud_idx] << "] is not as twice in size as mathx_ut a.k.a. [unsigned " << names[tu_idx] << "].\n";
		cout << resetc;
		return false;
	}

	if (!counter::is_valid())
	{
		cout << forec(red, yes);
		cout << "active counter name is " << counter::name() << " won't represent milliseconds correctly, "
				"to correct this error either implement a counter for your platform or send us you platform information.\n";
		cout << resetc;
		return false;
	}

	if (!test_info::summary) return true;

	cout << forec(cyan, yes);
	cout << "MathX configuration:\n";
	cout << "\tcurrent version: " << version::name() << ".\n";
	cout << "\toperating system is " << meta::sys_info::platform_type << "bit.\n";
	cout << "\tbits per byte: " << meta::sys_info::bits_per_byte << ".\n";
	cout << "\tis twos complement: " << write(meta::sys_info::is_twos_complement) << ".\n";
	cout << "\tfloat-point base: " << meta::sys_info::float_base << ".\n";
	cout << "\tis big endian: " << write(meta::sys_info::is_big_endian) << ".\n";
	cout << "\tallow STL: " << write(MATHX_ALLOW_STL? true: false) << ".\n";
	cout << "\tallow native float-point conversion: " << write(MATHX_ALLOW_NATIVE_FP_CONVERTION? true: false) << ".\n";
	cout << "\tallow native float-point to int_t/uint_t truncation: " << write(MATHX_ALLOW_NATIVE_FP_TO_INT_TRUNCATION? true: false) << ".\n";
	cout << "\tallow int_t/uint_t to native float-point truncation: " << write(MATHX_ALLOW_INT_TO_NATIVE_FP_TRUNCATION? true: false) << ".\n\n";

	cout << "MathX types:\n";
	cout << "\tcs_t a.k.a. [signed " << names[cs_idx] << "] is " << mxi::isizeof<cs_t>::value << "bits.\n";
	cout << "\tcu_t a.k.a. [unsigned " << names[cu_idx] << "] is " << mxi::isizeof<cu_t>::value << "bits.\n";
	cout << "\tfp_t a.k.a. [" << names[fp_idx] << "] is " << mxi::isizeof<fp_t>::value << "bits.\n";
	cout << "\tmathx_st a.k.a. [signed " << names[ts_idx] << "] is " << mxi::isizeof<mathx_st>::value << "bits.\n";
	cout << "\tmathx_ut a.k.a. [unsigned " << names[tu_idx] << "] is " << mxi::isizeof<mathx_ut>::value << "bits.\n";
	cout << "\tmathx_sdt a.k.a. [signed " << names[tsd_idx] << "] is " << mxi::isizeof<mathx_sdt>::value << "bits.\n";
	cout << "\tmathx_udt a.k.a. [unsigned " << names[tud_idx] << "] is " << mxi::isizeof<mathx_udt>::value << "bits.\n\n";
	
	cout << "Test configuration:\n";
	cout << "\tverbose mode: " << write(test_info::verbose) << ".\n";
	cout << "\tcounter API: " << counter::name() << ".\n";
	cout << "\tcolor API: " << ccolor::name() << ".\n";
	cout << "\tshow time stamp: " << write(test_info::show_time_stamp) << ".\n";
	cout << "\tshow all duration parts: " << write(test_info::show_all_duration_parts) << ".\n";
	cout << "\tallow console colors: " << write(test_info::allow_colors) << ".\n";
	cout << "\tint_t/uint_t test size is " << test_info::int_uint_bits << "bits using default implementation.\n";
	cout << "\tint_t/uint_t elements count: " << test_info::si_t::meta::array_count << ".\n";
	cout << "\tstop current unit test at first test case error: " << write(test_info::stop_at_first_case_error) << ".\n";
	cout << "\tstop all unit tests at first test case error: " << write(test_info::stop_all_at_first_case_error) << ".\n";
	cout << "\tbenchmark only if all unit test passed: " << write(test_info::benchmark_if_all_units_ok) << ".\n";
	cout << "\tnumber of registered unit tests: " << manager::get_count<unit_test>() << ".\n";
	cout << "\tnumber of registered benchmark tests: " << manager::get_count<speed_test>() << ".\n\n";
	cout << resetc;

	return true;
}

};

}
}

#endif // MATHX_FRAMEWORK_STARTUP_HPP
