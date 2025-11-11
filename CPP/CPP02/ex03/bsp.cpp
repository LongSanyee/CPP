#include "Point.hpp"

float calculat_area(Point const a, Point const b, Point const c)
{
    float area;

    area = 0.5f * (a.getx()*(b.gety() - c.gety()) + b.getx()*(c.gety() - a.gety()) + c.getx()*(a.gety() - b.gety()));
    return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float abc = calculat_area(a, b, c);

    float pab = calculat_area(point, a, b);
    float pbc = calculat_area(point, b, c);
    float pca = calculat_area(point, c, a);

    return fabs(fabs(abc) - (fabs(pab) + fabs(pbc) + fabs(pca))) < 0.0001f
    && pab > 0 && pbc > 0 && pca > 0;
}
