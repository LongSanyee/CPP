#include "Fixed.hpp"

const int Fixed::fract = 8;

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixed = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called " << std::endl;
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

    temp.fixed = (this->fixed * a.fixed) >> fract;
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

    temp.fixed = (this->fixed << fract) / a.fixed;;
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
    this->fixed++;
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
    this->fixed--;
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
    std::cout << "Int constructor called" << std::endl;
    fixed = convert * pow(2, fract);
}

Fixed::Fixed(const float point)
{
    std::cout << "Float constructor called" << std::endl;
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