#include "Fixed.hpp"

const int Fixed::fract = 8;

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::Fixed()
{
    fixed = 0;
}

Fixed::~Fixed()
{
    
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->fixed = other.fixed;
    return (*this);
}

bool Fixed::operator>(const Fixed& a)
{
    if (this->fixed > a.fixed)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& a)
{
    if (this->fixed < a.fixed)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& a)
{
    if (this->fixed >= a.fixed)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& a)
{
    if (this->fixed <= a.fixed)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed& a)
{
    if (this->fixed == a.fixed)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& a)
{
    if (this->fixed != a.fixed)
        return (true);
    return false;
}

Fixed Fixed::operator*(const Fixed& a)
{
    Fixed temp;

    temp.fixed = (this->fixed * a.fixed) >> 8;
    return temp;
}

Fixed Fixed::operator-(const Fixed& a)
{
    Fixed temp;

    temp.fixed = this->fixed - a.fixed;
    return temp;
}

Fixed Fixed::operator+(const Fixed& a)
{
    Fixed temp;

    temp.fixed = this->fixed + a.fixed;
    return temp;
}

Fixed Fixed::operator/(const Fixed& a)
{
    Fixed temp;

    temp.fixed = (this->fixed << 8) / a.fixed;;
    return temp;
}

Fixed Fixed::operator++()
{
    fixed++;

    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    fixed++;
    return temp;
}

Fixed Fixed::operator--()
{
    fixed--;

    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    fixed--;
    return (tmp);
}

std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
    out << other.toFloat();

    return (out);
}

int Fixed::toInt( void ) const
{
    return (this->fixed / pow(2, fract));
}

float Fixed::toFloat( void ) const
{
    float tmp = (float)this->fixed;

    return (tmp / pow(2, fract));
}

Fixed::Fixed(const int convert)
{
    fixed = convert * pow(2, fract);
}

Fixed::Fixed(const float point)
{
    fixed = roundf(point * pow(2, fract));
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a > b)
        return b;
    return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.fixed > b.fixed)
        return b;
    return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.fixed > b.fixed)
        return a;
    return b;
}