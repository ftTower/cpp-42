
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    private:
        int fixedPointValue;
        static const int rawBit = 8;
    public:

        //------------------constructor------------------------//

        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &other);


        ~Fixed();

        //------------------operator------------------------//
        

        //-----------------comparison//

        friend bool operator<(const Fixed &f1, const Fixed &f2) {
            if (f1.fixedPointValue < f2.fixedPointValue)
                return (true);
            return (false);
        }
        
        friend bool operator<=(const Fixed &f1, const Fixed &f2) {
            if (f1.fixedPointValue <= f2.fixedPointValue)
                return (true);
            return (false);
        }
        
        friend bool operator>(const Fixed &f1, const Fixed &f2) {
            if (f1.fixedPointValue > f2.fixedPointValue)
                return (true);
            return (false);
        }
        
        friend bool operator>=(const Fixed &f1, const Fixed &f2) {
            if (f1.fixedPointValue >= f2.fixedPointValue)
                return (true);
            return (false);
        }
        
        friend bool operator==(const Fixed &f1, const Fixed &f2) {
            if (f1.fixedPointValue == f2.fixedPointValue)
                return (true);
            return (false);
        }
        
        friend bool operator!=(const Fixed &f1, const Fixed &f2) {
            if (f1.fixedPointValue != f2.fixedPointValue)
                return (true);
            return (false);
        }

        //----------------arithmetic//

        Fixed &operator=(const Fixed &other) {
            if (this != &other)
                setRawBits(other.getRawBits());
            return (*this);
        }

        friend Fixed operator+(const Fixed& f1, const Fixed& f2) {
            Fixed f3;
            f3.setRawBits(f1.getRawBits() + f2.getRawBits());
            return (f3);
        }

        friend Fixed operator-(const Fixed& f1, const Fixed& f2) {
            Fixed f3;
            f3.setRawBits(f1.getRawBits() - f2.getRawBits());
            return (f3);
        }

        friend Fixed operator*(const Fixed& f1, const Fixed& f2) {
            Fixed f3;
            f3.setRawBits(f1.getRawBits() * f2.getRawBits() >> rawBit);
            return (f3);
        }

        friend Fixed operator/(const Fixed& f1, const Fixed& f2) {
            Fixed f3;
            f3.setRawBits((f1.getRawBits() << rawBit) / f2.getRawBits() );
            return (f3);
        }

        //----------------incrementation//

        Fixed& operator++() {
            this->fixedPointValue+=1;
            return *this;
        }

        Fixed& operator--() {
            this->fixedPointValue-=1;
            return *this;
        }

        Fixed operator++(int) {
            Fixed temp = *this;
            this->fixedPointValue+=1;
            return temp;
        }

        Fixed operator--(int) {
            Fixed temp = *this;
            this->fixedPointValue-=1;
            return temp;
        }

        //----------------output//

        friend std::ostream& operator<<(std::ostream& out, const Fixed& n) {return out << n.toFloat();}

        //------------------functions------------------------//

        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;

        static Fixed &min(Fixed &a, Fixed &b) {
            return (a < b) ? a : b;
        }
        
        static const Fixed &min(const Fixed &a,const  Fixed &b) {
            return (a < b) ? a : b;
        }
        
        static Fixed &max(Fixed &a, Fixed &b) {
            return (a > b) ? a : b;
        }
        
        static const Fixed &max(const Fixed &a,const  Fixed &b) {
            return (a > b) ? a : b;
        }
};



#endif