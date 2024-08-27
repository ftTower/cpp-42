
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    private:
        int fixedPointValue;
        static const int rawBit = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &other);

        Fixed &operator=(const Fixed &other);

        friend Fixed& operator<(Fixed &f1,Fixed &f2) {
            if (f1.fixedPointValue < f2.fixedPointValue)
                return (f1);
            return (f2);
        }

        friend Fixed operator+(const Fixed& f1, const Fixed& f2) {
            Fixed f3;
            f3.setRawBits(f1.getRawBits() + f2.getRawBits());
            return (f3);
        }

        friend std::ostream& operator<<(std::ostream& out, const Fixed& n) {
            return out << n.toFloat();
        }


        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;
};



#endif