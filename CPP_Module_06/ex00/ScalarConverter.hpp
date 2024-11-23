
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>
class ScalarConverter {

	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
	
	public :
		static void convert(const std::string &literal);
};

