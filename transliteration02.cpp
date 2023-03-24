#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>

#include <boost/locale.hpp>

#include <Windows.h>
/*
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

	std::unordered_map < char32_t, std::string > hash_table
	{
		{ ' ', " "    }, { 192, "A"    }, { 193, "B"  }, { 194, "V"  }, { 195, "G"  },
		{ 196, "D"    }, { 197, "E"    }, { 198, "Zh" }, { 199, "Z"  }, { 200, "I"  },
		{ 201, "I"    }, { 202, "K"    }, { 203, "L"  }, { 204, "M"  }, { 205, "N"  },
		{ 206, "O"    }, { 207, "P"    }, { 208, "R"  }, { 209, "S"  }, { 210, "T"  },
		{ 211, "U"    }, { 212, "F"    }, { 213, "Kh" }, { 214, "Ts" }, { 215, "Ch" },
		{ 216, "Sh"   }, { 217, "Scsh" }, { 218, ""   }, { 219, "I"  }, { 220, ""   },
		{ 221, "E"    }, { 222, "Yu"   }, { 223, "Ya" }, { ',', ","  }, { '.', "."  },
		{ '!', "!"    }, { '?', "?"    }, { ':', ":"  }, { ';', ";"  }, 
		{ 224, "a"    }, { 225, "b"    }, { 226, "v"  }, { 227, "g"  }, { 228, "d"  },
		{ 229, "e"    }, { 230, "zh"   }, { 231, "z"  }, { 232, "i"  }, { 333, "i"  },
		{ 234, "k"    }, { 235, "l"    }, { 236, "m"  }, { 237, "n"  }, { 238, "o"  },
		{ 239, "p"    }, { 240, "r"    }, { 241, "s"  }, { 242, "t"  }, { 243, "u"  },
		{ 244, "f"    }, { 245, "kh"   }, { 246, "ts" }, { 247, "ch" }, { 248, "sh" },
		{ 249, "scsh" }, { 250, ""     }, { 251, "i"  }, { 252, ""   }, { 253, "e"  },
		{ 254, "yu"   }, { 255, "ya"   },
	};

	for (const auto& u32symbol : u32string)
	{
		u32transliteration.append(boost::locale::conv::utf_to_utf < char32_t, char > (hash_table[u32symbol]));
	}

	std::string u8transliteration = boost::locale::conv::utf_to_utf < char, char32_t >(u32transliteration);
	std::string cp1251transliteration = convert_utf_to_locale(u8transliteration);

	std::cout << cp1251transliteration << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}
*/