namespace mathx
{

//////////////////////////
//  INT_T CONSTRUCTORS  //
//////////////////////////

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const char value)
{ *this = numeric_cast<signed int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const signed char value)
{ *this = numeric_cast<signed int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const unsigned char value)
{ *this = numeric_cast<unsigned int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const wchar_t value)
{ *this = numeric_cast<unsigned int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const bool value)
{ *this = numeric_cast<bool>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const signed short int value)
{ *this = numeric_cast<signed int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const signed int value)
{ *this = numeric_cast<signed int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const signed long int value)
{ *this = numeric_cast<signed long long int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const signed long long int value)
{ *this = numeric_cast<signed long long int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const unsigned short int value)
{ *this = numeric_cast<unsigned int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const unsigned int value)
{ *this = numeric_cast<unsigned int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const unsigned long int value)
{ *this = numeric_cast<unsigned long long int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const unsigned long long int value)
{ *this = numeric_cast<unsigned long long int>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const float value)
{ *this = numeric_cast<float>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const double value)
{ *this = numeric_cast<double>(value); }

template<cu_t bits_count, typename ut_t, typename st_t, typename udt_t, typename sdt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
int_t<bits_count, ut_t, st_t, udt_t, sdt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::int_t(const long double value)
{ *this = numeric_cast<long double>(value); }

///////////////////////////
//  UINT_T CONSTRUCTORS  //
///////////////////////////

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const char value)
{ *this = numeric_cast<signed int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const signed char value)
{ *this = numeric_cast<signed int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const unsigned char value)
{ *this = numeric_cast<unsigned int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const wchar_t value)
{ *this = numeric_cast<signed int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const bool value)
{ *this = numeric_cast<bool>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const signed short int value)
{ *this = numeric_cast<signed int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const signed int value)
{ *this = numeric_cast<signed int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const signed long int value)
{ *this = numeric_cast<signed long long int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const signed long long int value)
{ *this = numeric_cast<signed long long int>(value); }


template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const unsigned short int value)
{ *this = numeric_cast<unsigned int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const unsigned int value)
{ *this = numeric_cast<unsigned int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const unsigned long int value)
{ *this = numeric_cast<unsigned long long int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const unsigned long long int value)
{ *this = numeric_cast<unsigned long long int>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const float value)
{ *this = numeric_cast<float>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const double value)
{ *this = numeric_cast<double>(value); }

template<cu_t bits_count, typename ut_t, typename udt_t,
		 template <typename> class range_t, template <typename> class bitwise_t,
		 template <typename> class logic_t, template <typename> class arithmetic_t,
		 template <typename> class meta_t> inline
uint_t<bits_count, ut_t, udt_t, range_t, bitwise_t, logic_t, arithmetic_t, meta_t>::uint_t(const long double value)
{ *this = numeric_cast<long double>(value); }

}
