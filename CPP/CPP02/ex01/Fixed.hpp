#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    Fixed(const int convert);
    Fixed(const float point);
    float toFloat( void ) const;
    int toInt( void ) const;
private:
    int fixed;
    static const int fract;
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);

#endif