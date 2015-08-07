#include<iostream>
#include<string>
#include<list>
#include<cstdint>

//#include "vnt_base_parse.h"
//#include "feel_base_parse.h"
#define r_ifnot(expr)      if(expr)

using namespace std;



// класс базовых ф-ий парсинга
template<typename it_t, typename str_t, typename ch_t>
struct basic_read
{
	it_t container_end;

	basic_read(it_t cont_end)
		: container_end(cont_end) {}

	bool atend(it_t it)
	{
		return (it == container_end) ? true : false;
	}

	// формат ф-ии, реализованный Филиппом:
    int fix_str(it_t * pit, const ch_t * s)
	{
        while(!this->atend(*pit))
            if(!*s)
                return 0;
            else if(**pit!=*s)
                return 1;
            else
                (*pit)++, s++;
        return -1;
    }

	// Формат ф-ии, реализованный Вадимом 
	// (проверка на конец файла отсутствует, но её нужно добавить):
	static bool fix_str(it_t* pit, str_t* str)
	{
		it_t it_str = (*str).begin();

		while(it_str != (*str).end())
			if(**pit != *it_str)
				return 1;
			else
				(*pit)++, it_str++;
		return 0;
	}
};


template<
	template<class T, class Alloc = allocator<T>> class container,
	typename str_t
>
class parser
{
	typedef typename str_t::iterator it_t;
	typedef typename str_t::value_type ch_t;
	//typedef basic_read<it_t, str_t, ch_t> read;
	basic_read<it_t, str_t, ch_t> read;

public:

	// Конструктор нужен, если планируется использовать atend(it) в basic_read
	parser(str_t* pstr) : read(basic_read<it_t, str_t, ch_t>((*pstr).end())) {}

	bool read_xml(str_t* pstr)
	{
		it_t it = (*pstr).begin();
		it_t* pit = &it;
		

		if(!read_DTD(pit)) return false;
		//if(!read_elem_tag_last(pit, pcont)) return false;
		return true;
	}

	bool read_DTD(it_t* pit)
	{
		string str = "<!xml>";
		//char str[] = "<!xml>";
		//const char* pstr = str;
		//r_ifnot(read_fix_str(pit, &str)) return false;
		r_ifnot(read.fix_str(pit, &str)) return false;
		//r_ifnot(read.fix_str(pit, pstr)) return false;
		return true;
	}

	bool read_fix_str(it_t* pit, string* str)
	{
		it_t it_str = (*str).begin();

		while(it_str != (*str).end())
			if(**pit != *it_str)
				return 1;
			else
				(*pit)++, it_str++;
		return 0;
	}

};


int main(int argc, char** argv)
{
	/*
	char xml_doc[] = "<!xml>";
	char* it = xml_doc;
	char** pit = &it;

	xml_reader<list, char*> xreader;
	if(xreader.read_xml(pit) ) cout << "xml_doc parsed" << endl;;

	string str = "123456";

	char* ps = &str;
	ps++;

	cout << *ps << endl;
	*/
	string xml_doc = "<!xml>";

	parser<list,string> xreader(&xml_doc);
//	parser<list,string>::result_type* pres;
	if(xreader.read_xml(&xml_doc)) cout << "распарсил" << endl;
	else cout << "ошибка" << endl;




	return 0;
}
