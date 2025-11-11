#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
    Point();
    ~Point();
    Point(const Point& copy);
    Point operator=(const Point& other);
    Point(const float dx, const float dy);
    float getx() const;
    float gety() const;
private:
    Fixed const x;
    Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif