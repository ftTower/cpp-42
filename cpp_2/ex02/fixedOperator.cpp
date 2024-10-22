#include "fixed.hpp"

//----------------arithmetic//

std::ostream &operator<<(std::ostream &out, const Fixed &n)
{
	out << n.toFloat();
	return (out);
}

Fixed operator+(const Fixed &f1, const Fixed &f2)
{
	Fixed	f3;

	f3.setRawBits(f1.getRawBits() + f2.getRawBits());
	return (f3);
}

Fixed operator-(const Fixed &f1, const Fixed &f2)
{
	Fixed	f3;

	f3.setRawBits(f1.getRawBits() - f2.getRawBits());
	return (f3);
}

Fixed operator*(const Fixed &f1, const Fixed &f2)
{
	return (Fixed(f1.toFloat() * f2.toFloat()));
}

Fixed operator/(const Fixed &f1, const Fixed &f2)
{
	return (Fixed(f1.toFloat() / f2.toFloat()));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		setRawBits(other.getRawBits());
	return (*this);
}

//----------------incrementation//

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}

//-----------------comparison//

bool Fixed::operator<(const Fixed &f1) const
{
	if (this->toFloat() < f1.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &f1) const
{
	if (this->toFloat() <= f1.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed &f1) const
{
	if (this->toFloat() > f1.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &f1) const
{
	if (this->toFloat() >= f1.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &f1) const
{
	if (this->toFloat() == f1.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &f1) const
{
	if (this->toFloat() != f1.toFloat())
		return (true);
	return (false);
}
