
#include "fixed.hpp"

// int main( void ) {
// 	Fixed a(5);
// 	Fixed b(2);

// 	std::cout << "a " << a << std::endl;
// 	std::cout << "b " << b << std::endl;

// 	std::cout << "===========comparison==========" << std::endl;

// 	if (a > b)
// 		std::cout << "a > b" << std::endl;
// 	else
// 		std::cout << "a < b" << std::endl;
// 	if (a >= b)
// 		std::cout << "a >= b" << std::endl;
// 	else
// 		std::cout << "a < b" << std::endl;
// 	if (a <= b)
// 		std::cout << "a <= b" << std::endl;
// 	else
// 		std::cout << "a > b" << std::endl;
// 	if (a == b)
// 		std::cout << "a == b" << std::endl;
// 	else
// 		std::cout << "a != b" << std::endl;
// 	if (a != b)
// 		std::cout << "a != b" << std::endl;
// 	else
// 		std::cout << "a == b" << std::endl;

// 	std::cout << "===========arithmetic==========" << std::endl;

// 	Fixed c = a + b;
// 	std::cout << "a + b = " << c << std::endl;
// 	c = a - b;
// 	std::cout << "a - b = " << c << std::endl;
// 	c = a * b;
// 	std::cout << "a * b = " << c << std::endl;
// 	c = a / b;
// 	std::cout << "a / b = " << c << std::endl;

// 	std::cout << "===========incrementation==========" << std::endl;

// 	for(int i = 0; i < 20 ; i++)
// 	{
// 		a++;
// 		std::cout << a << std::endl;
// 	}

// 	return (0);
// }

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	return (0);
}