
#include "fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	// std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	// std::cout << "destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	// std::cout << "const int constructor called with " << n << std::endl;
	setRawBits(n << this->rawBit);
}

Fixed::Fixed(const float f)
{
	// std::cout << "const float constructor called with " << f << std::endl;
	this->setRawBits((int)roundf(f * (1 << this->rawBit)));
}

const Fixed	&Fixed::min(Fixed const &c1, Fixed const &c2)
{
	if (c1 < c2)
		return (c1);
	return (c2);
}

const Fixed	&Fixed::max(Fixed const &c1, Fixed const &c2)
{
	if (c1 > c2)
		return (c1);
	return (c2);
}

int Fixed::toInt() const
{
	return (this->getRawBits() >> this->rawBit);
}

float Fixed::toFloat() const
{
	float f;

	f = (float)this->getRawBits() / (1 << this->rawBit);
	return (f);
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits called" << std::endl;
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits called" << std::endl;
	this->fixedPointValue = raw;
}
