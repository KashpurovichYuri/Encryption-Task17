#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>

#include <boost/locale.hpp>

#include <Windows.h>

std::string convert_locale_to_utf(const std::string& string)
{
	boost::locale::generator generator;
	generator.locale_cache_enabled(true);

	std::locale locale =
		generator(boost::locale::util::get_system_locale());

	return boost::locale::conv::to_utf < char >(string, locale);
}

std::string convert_utf_to_locale(const std::string& string)
{
	boost::locale::generator generator;
	generator.locale_cache_enabled(true);

	std::locale locale =
		generator(boost::locale::util::get_system_locale());

	return boost::locale::conv::from_utf < char >(string, locale);
}

int main()
{
	system("chcp 1251");

	std::string input;
	getline(std::cin, input);

	std::string u8string = convert_locale_to_utf(input);
	std::u32string u32string = boost::locale::conv::utf_to_utf < char32_t, char >(u8string);
	std::u32string u32transliteration;

	std::map < char32_t, char32_t > hash_table
	{
		{  32, 32 },
		{ 192, 65 }, { 193, 66 }, { 194, 86 }, { 195, 71 }, { 192, 65 }, { 196, 68 },
		{ 197, 69 }, { 198, 90 }, { 199, 90 }, { 200, 73 }, { 201, 73 }, { 202, 75 },
		{ 203, 76 }, { 204, 77 }, { 205, 78 }, { 206, 79 }, { 207, 80 }, { 208, 82 },
		{ 209, 83 }, { 210, 84 }, { 211, 85 }, { 212, 70 }, { 213, 75 }, { 214, 84 },
		{ 215, 67 }, { 216, 83 }, { 217, 83 }, { 218,  0 }, { 219, 73 }, { 220,  0 },
		{ 221, 69 }, { 222, 73 }, { 223, 89 }, 
	}; // but we need to process especially: 198,90; 213,75; 214,84; 215,67; 216,83; 217,83; 222,73; 223,89;

	for (const auto& u32symbol : u32string)
		u32transliteration.push_back(hash_table[u32symbol]);

	std::string u8transliteration = boost::locale::conv::utf_to_utf < char, char32_t >(u32transliteration);
	std::string cp1251transliteration = convert_utf_to_locale(u8transliteration);

	std::cout << cp1251transliteration << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}
