#include "Fixed.hpp"

const int Fixed::fract = 8;

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed()
{
    setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
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

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;

    return (fixed);
}

void Fixed::setRawBits( int const raw )
{
    fixed = raw;
}