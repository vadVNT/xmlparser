#include<iostream>
#include<string>
#include<list>
#include<cstdint>

#include "vnt_base_parse.h"

using namespace std;


template<
	template<class T, class Allocator> class container,
	typename it_t
>
class xml_reader
{
public:
	
	bool read_xml(it_t* pit)
	{
		if(!read_DTD(pit)) return false;
		if(!read_elem_tag_last(pit)) return false;
		return true;
	}
	
	bool read_DTD(it_t* pit)
	{
		int32_t n = 6;
		char pattern[] = "<!xml>";
		it_t it_pattern = pattern;
		it_t* pit_pattern = &it_pattern;
		/*
		Хочу, чтобы было вот так:

		vnt_stream stream_pattern("<!xml>");
		it_t* pit_pattern = &stream_pattern.begin();
		int32_t n = stream_pattern.size();
		*/

		if(!tryread<it_t>::fix_str(pit, pit_pattern, n)) return false;
		return true;
	}
	
	bool read_elem_tag_last(it_t* pit)
	{
		return true;
	}
	
};

int main(int argc, char** argv)
{
	char xml_doc[] = "<!xml>";
	char* it = xml_doc;
	char** pit = &it;

	xml_reader<list, char*> xreader;
	if(xreader.read_xml(pit) ) cout << "xml_doc parsed" << endl;;


	return 0;
}
