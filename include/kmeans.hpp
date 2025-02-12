#pragma once

#include <vector>
#include <random>

using std::vector;

class Kmeans
{
public:
    Kmeans(int k, int max_iterations = 1000, double tolerance = 1e-7);

    void fit(const vector<vector<double>>& points);
    vector<vector<double>> getCentroids() const;
    vector<int> getClusterIndices() const;

private:
    int n_clusters;
    int max_iterations;
    int features_dim;
    int points_dim;
    double tolerance;
    std::mt19937 rng;
    vector<vector<double>> centroids;
    vector<int> cluster_indices;

    void initializeCentroids(const vector<vector<double>>& points);
    void updateClusterIndices(const vector<vector<double>>& points);
    int findNearestCluster(const vector<double> &point);
    void updateCentroids(const vector<vector<double>>& points);
    bool converged(const vector<vector<double>>& previous_centroids);
};

