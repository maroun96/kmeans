#pragma once

#include <vector>

using std::vector;

class Kmeans
{
public:
    Kmeans(int k, int max_iterations, double tolerance);

    void fit(const vector<vector<double>>& points);
    vector<vector<double>> getCentroids() const;

private:
    int k;
    int max_iterations;
    double tolerance;
    vector<vector<double>> centroids;

    void initializeCentroids(const vector<vector<double>>& points);
    int findNearestCluster(const vector<double>& point);
    void updateCentroids(const vector<vector<vector<double>>>& clusters);
    bool converged(const vector<vector<double>>& previous_centroids);
};

