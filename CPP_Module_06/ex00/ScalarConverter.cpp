
#include "ScalarConverter.hpp"
#include <string.h>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	FLOAT_PSEUDO,
	DOUBLE,
	DOUBLE_PSEUDO,
}		t_type;

t_type	parseLiteral(const std::string &literal)
{
	std::cout << "["
				<< "\033[32m" << literal << " \033[0m\033[31m";
	if (literal.length() == 1 && !isdigit(literal[0]))
		return (std::cout << "CHAR]\033[0m", CHAR);
	else if (literal.find(".") != std::string::npos)
	{
		if (literal[literal.size() - 1] == 'f')
			return (std::cout << "FLOAT]\033[0m", FLOAT);
		else
			return (std::cout << "DOUBLE]\033[0m", DOUBLE);
	}
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf"
		|| literal == "-nanf")
		return (std::cout << "FLOAT PSEUDO]\033[0m", FLOAT_PSEUDO);
	else if (literal == "-inf" || literal == "+inf" || literal == "nan"
		|| literal == "-nan")
		return (std::cout << "DOUBLE PSEUDO]\033[0m", DOUBLE_PSEUDO);
	return (std::cout << "INT]\033[0m", INT);
}

void	printChar(t_type type, const std::string &literal)
{
	int		value;
	char	buf;

	std::cout << "|char  :\t";
	value = 0;
	if (type == CHAR)
	{
		value = static_cast<int>(literal[0]);
		buf = static_cast<char>(literal[0]);
	}
	else if (type == INT)
	{
		value = atoi(literal.c_str());
		buf = static_cast<char>(value);
	}
	else if (type == FLOAT)
	{
		value = static_cast<int>(strtof(literal.c_str(), NULL));
		buf = static_cast<char>(value);
	}
	else if (type == DOUBLE)
	{
		value = static_cast<int>(strtod(literal.c_str(), NULL));
		buf = static_cast<char>(value);
	}
	if (value >= 0 && value < 32)
		std::cout << "not printable char" << std::endl;
	else if (value < 0 || value > 126)
		std::cout << "not in ascii table" << std::endl;
	else
		std::cout << "'" << buf << "'" << std::endl;
}

void	printInt(t_type type, const std::string &literal)
{
	int	value;

	value = 0;
	std::cout << "|int   :\t";
	if (type == INT)
	{
		if ((strtol(literal.c_str(), NULL,
					10) > std::numeric_limits<int>::max())
			|| (strtol(literal.c_str(), NULL,
					10) < std::numeric_limits<int>::min()))
			return (std::cout << "too large for a int" << std::endl,
				(void)NULL);
		value = atoi(literal.c_str());
	}
	else if (type == CHAR)
		value = static_cast<int>(literal[0]);
	else if (type == DOUBLE)
		value = static_cast<int>(strtod(literal.c_str(), NULL));
	else if (type == FLOAT)
		value = static_cast<int>(strtof(literal.c_str(), NULL));
	else
		return (std::cout << "impossible" << std::endl, (void)NULL);
	std::cout << value << std::endl;
}

void	printInf(const std::string &literal, bool isFloat)
{
	if (isFloat && (!strncmp("inf", literal.c_str(), literal.size())
			|| !strncmp("+inf", literal.c_str(), literal.size())
			|| !strncmp("-inf", literal.c_str(), literal.size())
			|| !strncmp("nan", literal.c_str(), literal.size())
			|| !strncmp("-nan", literal.c_str(), literal.size())))
		std::cout << literal << "f";
	else if (!isFloat && (!strncmp("inf", literal.c_str(), literal.size())
			|| !strncmp("+inf", literal.c_str(), literal.size())
			|| !strncmp("-inf", literal.c_str(), literal.size())
			|| !strncmp("nan", literal.c_str(), literal.size())
			|| !strncmp("-nan", literal.c_str(), literal.size())))
		std::cout << literal;
	else if (!isFloat && (!strncmp("inff", literal.c_str(), literal.size())
			|| !strncmp("+inff", literal.c_str(), literal.size())
			|| !strncmp("-inff", literal.c_str(), literal.size())
			|| !strncmp("nanf", literal.c_str(), literal.size())
			|| !strncmp("-nanf", literal.c_str(), literal.size())))
		std::cout << literal.substr(0, literal.size() - 1);
	else if (isFloat && (!strncmp("inff", literal.c_str(), literal.size())
			|| !strncmp("+inff", literal.c_str(), literal.size())
			|| !strncmp("-inff", literal.c_str(), literal.size())
			|| !strncmp("nanf", literal.c_str(), literal.size())
			|| !strncmp("-nanf", literal.c_str(), literal.size())))
		std::cout << literal;
}

void	printFloat(t_type type, const std::string &literal)
{
	std::cout << "|float :\t";
	if (type == FLOAT || type == INT || type == DOUBLE)
		std::cout << strtof(literal.c_str(), NULL) << "f";
	else if (type == CHAR)
		std::cout << static_cast<float>(literal[0]) << "f";
	else if (type == DOUBLE_PSEUDO || type == FLOAT_PSEUDO)
		printInf(literal, true);
	std::cout << std::endl;
}

void	printDouble(t_type type, const std::string &literal)
{
	std::cout << "|double :\t";
	if (type == FLOAT || type == INT || type == DOUBLE)
		std::cout << strtod(literal.c_str(), NULL);
	else if (type == CHAR)
		std::cout << static_cast<float>(literal[0]);
	else if (type == DOUBLE_PSEUDO || type == FLOAT_PSEUDO)
		printInf(literal, false);
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	t_type	type;

	std::cout << "===========";
	type = parseLiteral(literal);
	std::cout << "===========" << std::endl;
	printChar(type, literal);
	printInt(type, literal);
	printDouble(type, literal);
	printFloat(type, literal);
	std::cout << std::endl;
}
