#include <utils.hpp>
#include <cmath>

using std::vector;

double utils::calculateDistance(const vector<double>& p1, const vector<double>& p2) {
    double sum = 0;
    for (size_t i = 0; i < p1.size(); ++i) {
        sum += pow(p1[i] - p2[i], 2);
    }
    return sqrt(sum);
}