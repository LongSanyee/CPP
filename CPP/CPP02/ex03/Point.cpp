#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    
}

Point::~Point()
{

}

Point::Point(const Point& copy): x(copy.x), y(copy.y)
{
    
}

Point Point::operator=(const Point& other)
{
    (void)other;
    return (*this);
}

Point::Point(const float dx, const float dy) : x(dx), y(dy)
{

}

float Point::getx() const
{
    return (x.toFloat());
}

float Point::gety() const
{
    return (y.toFloat());
}
