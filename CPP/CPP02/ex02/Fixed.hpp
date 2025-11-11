#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();
    ~Fixed();
    Fixed& operator=(const Fixed& other);
    Fixed(const Fixed& other);
    float toFloat( void ) const;
    int toInt( void ) const;
    Fixed(const int convert);
    Fixed(const float point);
    Fixed operator++();
    Fixed operator--();
    Fixed operator--(int);
    Fixed operator++(int);
    Fixed operator*(const Fixed& a);
    Fixed operator-(const Fixed& a);
    Fixed operator+(const Fixed& a);
    Fixed operator/(const Fixed& a);
    bool operator>(const Fixed& a);
    bool operator>=(const Fixed& a);
    bool operator==(const Fixed& a);
    bool operator<=(const Fixed& a);
    bool operator<(const Fixed& a);
    bool operator!=(const Fixed& a);
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
private:
    int fixed;
    static const int fract;
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);

#endif
