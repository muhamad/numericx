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
** File:  macros.hpp
**
** Purpose: helper macros.
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_MACROS_HPP
#define MATHX_FRAMEWORK_MACROS_HPP

// define normal test case body
#define DEFINE_UNIT_CASE(name, msg)					\
struct name : public test::unit_case				\
{													\
	static name& inst;								\
	inline bool execute();							\
													\
private:											\
	inline name() : unit_case(msg) {}				\
	static name& get() { static name c; return c; }	\
};													\
													\
name& name::inst = name::get();//////////////////////



// create execute function declaration
#define DECL_UNIT_CASE_EXEC(name) inline bool name::execute()



// test/speed case template boolean argument
#define UNIT_ARG test_unsigned



// define test case body with template boolean argument
#define DEFINE_UNIT_CASE_ARG(name, signed_msg, unsigned_msg)	\
template<bool UNIT_ARG>											\
struct name : public test::unit_case							\
{																\
	static name& inst;											\
	inline bool execute();										\
																\
private:														\
	name() : unit_case(UNIT_ARG? unsigned_msg: signed_msg) {}	\
	inline static name& get() { static name c; return c; }		\
};																\
																\
template<bool UNIT_ARG>											\
name<UNIT_ARG>& name<UNIT_ARG>::inst = name<UNIT_ARG>::get();////



// create execute function declaration
#define DECL_UNIT_CASE_EXEC_ARG(name)	\
template<bool UNIT_ARG>					\
inline bool name<UNIT_ARG>::execute()////



// define unit test group
#define DEFINE_UNIT_TEST(name, msg, case_count)						\
struct name : public test::unit_test								\
{																	\
	static name& inst;												\
																	\
	static const cs_t arr_count = case_count;						\
																	\
	inline cs_t get_cases_count() const { return case_count; }		\
																	\
	inline unit_case* get_case(cs_t index) const;					\
																	\
private:															\
	inline name() : unit_test(msg)									\
	{ manager::add<unit_test>( dynamic_cast<unit_test*>(this) ); }	\
																	\
	inline static name& get() { static name c; return c; }			\
};																	\
																	\
name& name::inst = name::get();//////////////////////////////////////



// create get case function for test group
#define DECL_UNIT_TEST_GET_CASE(name)				\
inline unit_case* name::get_case(cs_t index) const///



// define array of cases
#define DEFINE_CASE_ARR static unit_case* arr[arr_count] =



// define case return statement
#define DEFINE_CASE_RETURN return arr[index];



// define non-template case element
#define SET_UNIT_CASE_SLOT(name) dynamic_cast<unit_case*>(& name::inst)



// define case element with boolean argument
#define SET_UNIT_CASE_SLOT_ARG(name, bv) dynamic_cast<unit_case*>(& name<bv>::inst)



#endif // MATHX_FRAMEWORK_MACROS_HPP
