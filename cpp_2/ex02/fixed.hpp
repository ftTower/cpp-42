
#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
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

	bool operator<(const Fixed &f1) const;
	bool operator<=(const Fixed &f1) const;
	bool operator>(const Fixed &f1) const;
	bool operator>=(const Fixed &f1) const;
	bool operator==(const Fixed &f1) const;
	bool operator!=(const Fixed &f1) const;

	//----------------arithmetic//

	Fixed &operator=(const Fixed &other);

	//----------------incrementation//

	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int value);
	Fixed operator--(int value);

	//------------------functions------------------------//

	int  getRawBits() const;
	void setRawBits(int const raw);

	float toFloat() const;
	int   toInt() const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &n);

Fixed operator/(const Fixed &f1, const Fixed &f2);
Fixed operator*(const Fixed &f1, const Fixed &f2);
Fixed operator-(const Fixed &f1, const Fixed &f2);
Fixed operator+(const Fixed &f1, const Fixed &f2);

#endif