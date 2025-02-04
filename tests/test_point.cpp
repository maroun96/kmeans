#include <iostream>
#include <cassert>
#include <cmath>
#include <point.hpp>

int main() {
    Point p1({1.0, 2.0, 3.0});
    Point p2({4.0, 5.0, 6.0});

    double expected_distance = sqrt(27.0);
    double computed_distance = p1.distance(p2);

    assert(std::abs(computed_distance - expected_distance) < 1e-6);

    std::cout << "Test Passed: distance_to() works correctly!" << std::endl;
    return 0;  // Return 0 for a successful test
}
