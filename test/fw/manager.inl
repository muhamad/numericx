// add speed/unit test to collection
template<> inline void manager::add<unit_test>(unit_test* value) { get_ut().push_back(value); }
template<> inline void manager::add<speed_test>(speed_test* value) { get_st().push_back(value); }

// get number of registered speed/unit tests
template<> inline cs_t manager::get_count<unit_test>() { return get_ut().size(); }
template<> inline cs_t manager::get_count<speed_test>() { return get_st().size(); }

// get speed/unit test at input index
template<> inline unit_test* manager::at<unit_test>(cs_t index) { return get_ut()[index]; }
template<> inline speed_test* manager::at<speed_test>(cs_t index) { return get_st()[index]; }

inline bool manager::run_units()
{
	using std::cout;

	// number of registered unit tests
	const cs_t count = get_count<unit_test>();

	if (count == 0)
	{
		cout << info
			 << "unit tests not found.\n"
			 << resetc;
		return true;
	}

	// number of case executed with errors
	cs_t total_cases_errs = 0;
	// number of cases passed
	cs_t total_cases_pass = 0;
	// number of units executed with errors
	cs_t total_unit_errs  = 0;


	// execute unit test
	for (cs_t unit_idx = 0; unit_idx < count; ++unit_idx)
	{
		// get unit at index
		unit_test* tunit = at<unit_test>(unit_idx);
		// get number of cases in unit test
		const cs_t cases_count = tunit->get_cases_count();

		if (cases_count == 0)
		{
			if (test_info::verbose)
			{
				cout << warning
					 << "\nunit test " << write(tunit->get_name()) << " don't have any cases."
					 << resetc
			}

			continue;
		}

		cout << hint
			 << "\nexecuting unit test " << write(tunit->get_name())
			 << resetc;

		// number of cases with error
		cs_t err_count = 0;

		// execute test case
		for (cs_t case_idx = 0; case_idx < cases_count; ++case_idx)
		{
			unit_case* tcase = tunit->get_case(case_idx);

			if (test_info::verbose)
			{
				cout << info
					 << "\nexecuting case " << write(tcase->get_name())
					 << resetc;
			}

			bool result = tcase->execute();

			// if execution failed
			if (!result)
			{
				if (test_info::stop_at_first_case_error)
				{
					cout << error
						 << "\nunit test " << write(tunit->get_name()) <<  " execution stopped after first error."
						 << resetc;
				}
				++err_count;
			}

			if (test_info::verbose)
			{
				cout << (result? info: error)
					 << "\ncase " << write(tcase->get_name())
					 << (result? " passed.": " failed.")
					 << resetc;
			}

			if (test_info::stop_at_first_case_error && result) break;
		}

		const cs_t paased_cases = cases_count - err_count;
		total_cases_pass += paased_cases;
		total_cases_errs += err_count;

		if (err_count > 0)
		{
			++total_unit_errs;

			cout << warning
				 << "\nexecution finished with (" << err_count << ") error(s), (" << paased_cases << ") passed."
				 << resetc;

			if (test_info::stop_all_at_first_case_error && count > 0)
			{
				cout << hint
					 << "\nstop executing rest of unit tests after first error."
					 << resetc;

				break;
			}
		}
		else
		{
			cout << info
				 << "\ntest case(s) in " << write(tunit->get_name()) << " passed."
				 << resetc;
		}

		if (unit_idx < (count - 1)) cout << "\n";
	}

	if (count > 1)
	{
		cout << info
			 << "\n\nexecution finished with overall:\n"
			 << "\t(" << count - total_unit_errs << ") unit(s) passed.\n"
			 << "\t(" << total_unit_errs << ") unit(s) with errors.\n"
			 << "\t(" << total_cases_pass << ") case(s) passed.\n"
			 << "\t(" << total_cases_errs << ") case(s) failed.\n\n"
			 << resetc;
	}
	else
		cout << "\n\n";

	return total_cases_errs == 0;
}

inline duration manager::run_speeds()
{
	return duration();
}
