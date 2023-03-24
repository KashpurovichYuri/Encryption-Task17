#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <sstream>
#include <fstream>

#include <Windows.h>


void fill_money(const std::string& input, const std::string& locale_name, long double& value)
{
	std::istringstream sin(input);
	sin.imbue(std::locale(locale_name));
	sin >> std::get_money(value, true);
}


void print_money(const std::string& locale_name, const double value)
{
	std::ostringstream sout;
	sout.imbue(std::locale(locale_name));
	sout << std::showbase << std::put_money(value, false) << std::endl;
	std::cout << sout.str() << std::endl;
}

auto EUR_to_RUB(const double value, const double course)
{
	return value * course;
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::string input_money;
	std::cin >> input_money;

	long double val_EUR;
	fill_money(input_money, "de_DE.utf8", val_EUR);
	print_money("de_DE.utf8", val_EUR);

	const double course = 80.73;
	auto val_RUB = EUR_to_RUB(val_EUR, course);
	print_money("ru_RU.utf8", val_RUB);

	system("pause");

	return EXIT_SUCCESS;
}