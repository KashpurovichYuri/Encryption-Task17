#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

auto searcher(const std::string & text, const std::regex & regex)
{
	auto begin = std::sregex_iterator(std::cbegin(text), std::cend(text), regex);
	auto end = std::sregex_iterator();
	std::for_each(
		begin,
		end,
		[](const std::smatch & match)
		{
			std::cout << match[0] << std::endl ;
		});
}

int main()
{
	std::string text{
		R"(493893 @@#3224 lkfgj23 234oorj 43ojf9vi 2002.01.29 fdlpodf 09:54:42 dfo9u8--3=32+ \n 
		erk 8:43:55 12:45:78 okfdgll 7657.11.28 1223.14.14 kfdlfkgj 1223.10.40 lfkgl 11:200:23
		10:45:55 2000.02.29 43243ferd ss21:09:18 ss21.09.18 12324 2343 plrp-! 1@!!23!34.23.32)"
	};

	std::regex dates_regex(
		"(\\d{1,4}\\.((([0][13578]|[1][02])\\.([0-2][0-9]|[3][01]))|(([0][2]|11)\\.([01][0-9]|[2][0-8]))|([0][469]\\.([01][0-9]|30))))"
		"|((\\d\\d([02468][048]|[13579][260]))\\.02\\.29)"
	);
	auto dates_begin = std::sregex_iterator(std::cbegin(text), std::cend(text), dates_regex);
	auto dates_end = std::sregex_iterator();

	std::cout << "Found dates:" << std::endl;
	searcher(text, dates_regex);
	std::cout << std::endl;

	std::regex times_regex(
		"([0-9]|[0-1][0-9]|[2][0-4]):([0-5][0-9]|60){2}"
	);
	std::cout << "Found times:" << std::endl;	
	searcher(text, times_regex);
	std::cout << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}

/*
Output:

Found dates:
2002.01.29
7657.11.28
2000.02.29
21.09.18

Found times:
09:54:42
8:43:55
10:45:55
21:09:18

Press any key to continue . . .
*/