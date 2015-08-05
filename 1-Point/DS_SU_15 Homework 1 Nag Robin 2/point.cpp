#include "point.h"
#include <cmath> // for pow and sqrt

point::point()
{
    x = 0;
    y = 0;
}

void point::set_point(double a , double b)
{
    x = a;
    y = b;
}

double point::get_distance(point p)
{
    double distance;
    double x_dist = get_x() - p.get_x();
    double y_dist = get_y() - p.get_y();
    distance = sqrt(pow(x_dist,2) + pow(y_dist,2));
    return distance;
}

point::~point()
{
}

