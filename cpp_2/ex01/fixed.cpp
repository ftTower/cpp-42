
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
        setRawBits(other.getRawBits());
    return (*this);
}

Fixed::~Fixed () {
    std::cout << "destructor called" << std::endl;
}



Fixed::Fixed(const int n) {
    std::cout << "const int constructor called with " << n << std::endl;
    setRawBits(n << this->rawBit);
}


Fixed::Fixed(const float f) {
    std::cout << "const float constructor called with " << f << std::endl;
    this->setRawBits((int)roundf(f * (1 << this->rawBit)));
}


int Fixed::toInt() const {
    return(this->getRawBits() >> this->rawBit);
}

float Fixed::toFloat() const {
    float f;

    f = (float)this->getRawBits() / (1 << this->rawBit);
    return(f);
}

int Fixed::getRawBits() const {
    // std::cout << "getRawBits called" << std::endl;
    return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits called" << std::endl;
    this->fixedPointValue = raw;
}


