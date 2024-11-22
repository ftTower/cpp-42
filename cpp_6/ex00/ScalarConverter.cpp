
#include "ScalarConverter.hpp"

typedef enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
} t_type;

t_type	parseLiteral(const std::string &literal) {
	if (literal.length() == 1 && !isdigit(literal[0]))
		return (CHAR);
	else if (literal.find(".") != std::string::npos) {
		if (literal.back() == 'f')
			return (FLOAT);
		else
			return (DOUBLE);
	}
	return (INT);
}

void	ScalarConverter::convert(const std::string &literal) {
	std::cout << literal << std::endl;
	parseLiteral(literal);
	
}

