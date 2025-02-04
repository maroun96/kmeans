#pragma once

#include <vector>

using std::vector;

struct Point
{
    vector<double> coordinates;

    //Constructor declaration 
    Point(vector<double> coords);

    double distance(Point p);
};
