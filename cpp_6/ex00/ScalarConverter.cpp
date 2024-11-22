
#include "ScalarConverter.hpp"

typedef enum e_type {
	CHAR,
	INT,
	FLOAT,
	FLOAT_PSEUDO,
	DOUBLE,
	DOUBLE_PSEUDO,
} t_type;

t_type	parseLiteral(const std::string &literal) {
	std::cout << "[" << "\033[32m" << literal << " \033[0m\033[31m";
	if (literal.length() == 1 && !isdigit(literal[0]))
		return (std::cout << "CHAR]\033[0m", CHAR);
	else if (literal.find(".") != std::string::npos) {
		if (literal[literal.size() - 1] == 'f')
			return (std::cout << "FLOAT]\033[0m" ,FLOAT);
		else
			return (std::cout << "DOUBLE]\033[0m",DOUBLE);
	}
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (std::cout << "FLOAT PSEUDO]\033[0m", FLOAT_PSEUDO);
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (std::cout << "DOUBLE PSEUDO]\033[0m", DOUBLE_PSEUDO);
	return (std::cout << "INT]\033[0m",INT);
}

void	printChar(t_type type, const std::string &literal) {
	std::cout << "|char  :\t";
	
	int value = 0;
	char buf;
	
	if (type == CHAR) {
		value = literal[0];
		buf = literal[0];
	}
	else if (type == INT) {
		value = atoi(literal.c_str());
		buf = (char)atoi(literal.c_str());
	}
	else if (type == FLOAT) {
		value = (int)strtof(literal.c_str(), NULL);
		buf = (char)strtof(literal.c_str(), NULL);
	}
	else if (type == DOUBLE) {
		value = (int)strtod(literal.c_str(), NULL);
		buf = (char)strtod(literal.c_str(), NULL);
	}

	if (value >= 0 && value < 32)
		std::cout << "not printable char" << std::endl;
	else if (value < 0 || value > 126)	
		std::cout << "not in ascii table" << std::endl;
	else
		std::cout << "'" << buf << "'" << std::endl;
}

void	printInt(t_type type, const std::string &literal) {
	int value = 0;
	std::cout << "|int   :\t";
	if (type == INT) {
		if ((strtol(literal.c_str(), NULL, 10) > std::numeric_limits<int>::max()) || (strtol(literal.c_str(), NULL, 10) < std::numeric_limits<int>::min()))
			return (std::cout << "too large for a int" << std::endl, (void)NULL);	
		value = atoi(literal.c_str());
	}
	else if (type == CHAR)
		value = (int)literal[0];
	else if (type == DOUBLE)
		value = (int)strtod(literal.c_str(), NULL);
	else if (type == FLOAT)
		value = (int)strtof(literal.c_str(), NULL);
	else
		return (std::cout << "impossible" << std::endl, (void)NULL);
	std::cout << value << std::endl;
}

void	printFloat(t_type type, const std::string &literal) {
	std::cout << "|float :\t";
	if (type == FLOAT || type == INT || type == DOUBLE)
		std::cout << strtof(literal.c_str(), NULL) << "f";
	else if (type == CHAR)
		std::cout << (float)literal[0] << "f";
	else if (type == FLOAT_PSEUDO && (literal == "inff" || literal == "+inff"))
		std::cout << "+inff";
	else if (type == FLOAT_PSEUDO && literal == "-inff")
		std::cout << "-inff";
	else if (type == FLOAT_PSEUDO && literal == "nanf")
		std::cout << "nanf";
	std::cout  << std::endl;
}

void	printDouble(t_type type, const std::string &literal) {
	std::cout << "|double :\t";
	if (type == FLOAT || type == INT || type == DOUBLE)
		std::cout << strtod(literal.c_str(), NULL);
	else if (type == CHAR)
		std::cout << (float)literal[0];
	else if (type == DOUBLE_PSEUDO && (literal == "inf" || literal == "+inf"))
		std::cout << "+inf";
	else if (type == DOUBLE_PSEUDO && literal == "-inf")
		std::cout << "-inf";
	else if (type == DOUBLE_PSEUDO && literal == "nan")
		std::cout << "nan";
	std::cout << std::endl;
}

void	ScalarConverter::convert(const std::string &literal) {
	std::cout << "===========";
	t_type type = parseLiteral(literal);
	std::cout << "===========" << std::endl;
	
	printChar(type, literal);
	printInt(type, literal);
	printDouble(type, literal);
	printFloat(type, literal);
	
	std::cout << std::endl;
	
}

