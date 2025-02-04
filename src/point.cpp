#include <point.hpp>
#include <cmath>

Point::Point(vector<double> coord) :
    coordinates(coord) {}

double Point::distance(Point p){
    double sum = 0;
    for (int i = 0; i < coordinates.size(); i++){
        sum += pow((coordinates[i] - p.coordinates[i]), 2);
    }
    return sqrt(sum);
}

