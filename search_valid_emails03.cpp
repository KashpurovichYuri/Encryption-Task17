#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string text{
		R"(123.0023 user@gmail.com-- --less@@ werl;k?? 323 yandex@yandex.ru AAA@AAA.comMM http://a@mail.mipt.ru \n 
		stusew@er 42][]\54\yty\m\s\\)))s2424 quio perdf;l  i.s.m.mipt@smth		studen@phystech.edu23 \n
		eae @@ 224--12()][]]] ya@yo2@lkfkj.end!-- and 43*23@fsdsk.werejkfkfjkfnd txt.re@dfsf.932adfs rer@@243.423
		uyetr!@fksdf.24ffd 5837adasd@fsdfd.e johndoe@domainsample.com 456rgf-- 76...--!!a@adsds.edu123
		jo!hn.doe@domainsample.net john.doe43@domainsample.co.uk fgfe 7 a@edu.edw a@dffd.org rr@ee.ru )"
	};

	std::regex emails_regex(
		R"((\w+\.)*(\w+)(@)(\w{2,6}+\.)*(\w{2}))"
		); // a@mail.mipt.ru is correct
	auto emails_begin = std::sregex_iterator(std::cbegin(text), std::cend(text), emails_regex);
	auto emails_end = std::sregex_iterator();

	std::cout << "Found domains:" << std::endl;
	std::for_each(
		emails_begin,
		emails_end,
		[](const std::smatch & match)
		{
			std::cout << match[0] << std::endl ;
		});

	std::cout << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}

/*
Output:

Found domains:
gmail.com
yandex.ru
AAA.comMM
phystech.edu
lkfkj.end
fsdsk.werejkfkfjkfnd
domainsample.com
adsds.edu
domainsample.net
domainsample.co.uk
edu.edw
dffd.org
ee.ru

Press any key to continue . . .
*/