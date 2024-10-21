
#include "fixed.hpp"

int main( void ) {
	Fixed a(5);
	Fixed b(2);

	std::cout << "a " << a << std::endl;
	std::cout << "b " << b << std::endl;

	std::cout << "===========comparison==========" << std::endl;
	//! comparison
	if (a > b)
		std::cout << "a > b" << std::endl;
	else
		std::cout << "a < b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	else
		std::cout << "a < b" << std::endl;	
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	else
		std::cout << "a > b" << std::endl;
	if (a == b)
		std::cout << "a == b" << std::endl;
	else
		std::cout << "a != b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	else
		std::cout << "a == b" << std::endl;

	std::cout << "===========arithmetic==========" << std::endl;
	//! arithmetic
	Fixed c = a + b;
	std::cout << "a + b = " << c << std::endl;
	c = a - b;
	std::cout << "a - b = " << c << std::endl;
	c = a * b;
	std::cout << "a * b = " << c << std::endl;
	c = a / b;
	std::cout << "a / b = " << c << std::endl;

	std::cout << "===========incrementation==========" << std::endl;
	//! incrementation
	for(int i = 0; i < 5; i++)
		std::cout << "a++ = " << a++ << std::endl;
	std::cout << "--a = " << ++a << " -> " << a << std::endl;


	return 0;
}
