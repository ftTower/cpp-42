
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
	std::cout << "\x1b[7m";
	if (literal.length() == 1 && !isdigit(literal[0]))
		return (std::cout << "[CHAR]\033[0m", CHAR);
	else if (literal.find(".") != std::string::npos) {
		if (literal[literal.size() - 1] == 'f')
			return (std::cout << "[FLOAT]\033[0m" ,FLOAT);
		else
			return (std::cout << "[DOUBLE]\033[0m",DOUBLE);
	}
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (std::cout << "[FLOAT PSEUDO]\033[0m", FLOAT_PSEUDO);
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (std::cout << "[DOUBLE PSEUDO]\033[0m", DOUBLE_PSEUDO);
	return (std::cout << "[INT]\033[0m",INT);
}

void	printChar(t_type type, const std::string &literal) {
	std::cout << "char  : ";
	
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
	
}

void	printFloat(t_type type, const std::string &literal) {
	std::cout << "float : ";
	if (type == FLOAT || type == INT || type == DOUBLE)
		std::cout << strtof(literal.c_str(), NULL);
	else if (type == CHAR)
		std::cout << (float)literal[0];
	else if (type == FLOAT_PSEUDO && (literal == "inff" || literal == "+inff"))
		std::cout << std::numeric_limits<float>::infinity();
	else if (type == FLOAT_PSEUDO && literal == "-inff")
		std::cout << -std::numeric_limits<float>::infinity();
	else if (type == FLOAT_PSEUDO && literal == "nanf")
		std::cout << nanf("");
	std::cout << "f" << std::endl;
}

void	ScalarConverter::convert(const std::string &literal) {
	std::cout << "===========";
	t_type type = parseLiteral(literal);
	std::cout << "===========" << std::endl;
	
	printChar(type, literal);
	printFloat(type, literal);

	
	//for(size_t i = 0; literal[i]; i++)
	//	if ((!i && literal[i] != '-' && !isdigit(literal[i])))
	//		return (std::cout << "Failed to convert string" << std::endl, (void)NULL);

	//std::cout << "int  : " << value << std::endl;
	
	
	//if (!isdigit(atoi(literal.c_str())))
	//	std::cout << atoi(literal.c_str()) << std::endl;
	//else
	//	std::cout << "Non printable" << std::endl;
	//std::cout << "int   : " << atoi(literal.c_str()) << std::endl;
	//std::cout << "float : " << strtof(literal.c_str(), NULL) << std::endl;
	//std::cout << "double: " << strtod(literal.c_str(), NULL) << std::endl;
}

