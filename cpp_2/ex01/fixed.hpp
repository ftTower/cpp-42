
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

    private:
        int fixedPointValue;
        static const int rawBit = 8;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);

        ~Fixed();


        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;
};



#endif