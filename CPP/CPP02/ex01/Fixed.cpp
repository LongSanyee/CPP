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

int Fixed::toInt( void ) const
{
    return (this->fixed / pow(2, fract));
}

float Fixed::toFloat( void ) const
{
    float tmp = (float)this->fixed;

    return (tmp / pow(2, fract));
}

std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
    out << other.toFloat();

    return (out);
}