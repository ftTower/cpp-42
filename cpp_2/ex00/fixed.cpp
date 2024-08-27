
#include "fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "affectation constructor called" << std::endl;
    if (this != &other)
        this->fixedPointValue = other.getRawBits();
    return (*this);
}

Fixed::~Fixed () {
    std::cout << "destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits called" << std::endl;
    return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits called" << std::endl;
    this->fixedPointValue = raw;
}

