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
** File:  types.hpp
**
** Purpose: test base classes
**
===========================================================*/

#ifndef MATHX_FRAMEWORK_TYPES_HPP
#define MATHX_FRAMEWORK_TYPES_HPP

namespace mathx
{
namespace test
{

// represents a test case
struct case_t : public name_t
{
protected:
	inline case_t(const std::string& name) : name_t(name) {}
};

// group tests in single test
struct group_t : public name_t
{
protected:
	inline group_t(const std::string& name) : name_t(name) {}

public:
	// get number of test cases in this test group
	virtual cs_t get_cases_count() const = 0;

	// get test case at input index
	virtual case_t* get_case(cs_t index) const = 0;
};

// base class for code verification
struct unit_case : public case_t
{
protected:
	inline unit_case(const std::string& name) : case_t(name) {}

public:
	// execute case logic
	// return true on success, false otherwise
	virtual bool execute() = 0;
};

// used to group multiple test cases
struct unit_test : public group_t
{
protected:
	inline unit_test(const std::string& name) : group_t(name) {}

public:
	virtual unit_case* get_case(cs_t index) const = 0;
};

// base class for testing code speed
struct speed_case : public case_t
{
protected:
	inline speed_case(const std::string& name) : case_t(name) {}

public:
	// execute case logic
	// return duration with execution elapsed time
	virtual duration execute() = 0;
};

// used to group multiple speed cases
struct speed_test : public group_t
{
protected:
	inline speed_test(const std::string& name) : group_t(name) {}

public:
	virtual speed_case* get_case(cs_t index) const = 0;
};

}
}

#endif // MATHX_FRAMEWORK_TYPES_HPP
