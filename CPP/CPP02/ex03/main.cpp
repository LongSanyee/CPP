#include "Point.hpp"

#include <iostream>
#include "Point.hpp"

int main(void)
{
    Point a(0.0, 0.0);
    Point b(5.0, 0.0);
    Point c(2.0, 4.0);

    Point p(2, 1);

    if (bsp(a, b, c, p))
        std::cout << "point is inside" << std::endl;
    else
        std::cout << "point is outside or on edge or on vertex" << std::endl;
}