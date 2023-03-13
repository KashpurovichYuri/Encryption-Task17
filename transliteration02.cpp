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
	std::string input;
	std::cin >> input;
	
	std::string u8string = convert_locale_to_utf(input);
	std::u32string u32string = boost::locale::conv::utf_to_utf < char32_t, char >(u8string);
	std::u32string u32transliteration;

	std::map<int, int> hash_table;
	for (auto i = 0x0410; i <= 0x042f; ++i)
		hash_table.emplace(i, i - 0x3cf);
	for (auto i = 0x0430; i <= 0x044f; ++i)
		hash_table.emplace(i, i - 0x3cf);

	for (const auto& symbol : input)
		u32transliteration.push_back(char(hash_table[symbol]));

	std::string u8transliteration = boost::locale::conv::utf_to_utf < char, char32_t > (u32transliteration);
	std::string cp1251transliteration = convert_utf_to_locale(u8transliteration);

	std::cout << cp1251transliteration << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}