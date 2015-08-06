#ifndef VNT_BASE_PARSE
#define VNT_BASE_PARS

template<class it_t>
struct tryread {

	static bool fix_str(it_t *pit_str, it_t *pit_pattern, int32_t n)
	{
		for(int32_t i=0; i<n; i++) {
			if(**pit_str != **pit_pattern) return false;	
			(*pit_str)++; (*pit_pattern)++;
		}
		return true;
	}

	static bool fix_symb(it_t *pit_str, it_t *pit_symb)
	{
		if(**pit_str != **pit_symb) return false;
		(*pit_str)++;
		return true;
	}

	/*
	bool until_symb(it_t *pit_str, it_t *pit_symb, it_t *pit_res, int32_t* pn);
	*/


}; // namespace read

#endif
