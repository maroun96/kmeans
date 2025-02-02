#include <kmeans.h>
#include <utils.h>
#include <cmath>
#include <iostream>
#include <limits>
#include <cstdlib>

using std::vector;

Kmeans::Kmeans(int k, int max_iterations, double tolerance)
    : k(k), max_iterations(max_iterations), tolerance(tolerance) {}

void Kmeans::fit(const vector<vector<double>>& points) {
    initializeCentroids(points);

    for (int iter = 0; iter < max_iterations; ++iter) {
        vector<vector<vector<double>>> clusters(k);

        for (const auto& point : points) {
            int cluster_idx = findNearestCluster(point);
            clusters[cluster_idx].push_back(point);
        }
        
        auto previous_centroids = centroids;
        updateCentroids(clusters);
        if (converged(previous_centroids)) break;
    }
}

void Kmeans::initializeCentroids(const vector<vector<double>>& points) {
    centroids.clear();
    for (int i = 0; i < k; ++i) {
        int random_idx = rand() % points.size();
        centroids.push_back(points[random_idx]);
    }
}

int Kmeans::findNearestCluster(const vector<double>& point) {
    int nearest_cluster = 0;
    double min_distance = std::numeric_limits<double>::max();
    
    for (int i = 0; i < k; ++i) {
        double distance = utils::calculateDistance(point, centroids[i]);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_cluster = i;
        }
    }
    return nearest_cluster;
}

void Kmeans::updateCentroids(const vector<vector<vector<double>>>& clusters) {
    for (int i = 0; i < k; ++i) {
        if (clusters[i].empty()) continue;
        
        // Initialize new centroid coordinates with zeros
        vector<double> new_coords(clusters[i][0].size(), 0.0);
        
        // Sum up all coordinates
        for (const auto& point : clusters[i]) {
            for (size_t j = 0; j < point.size(); ++j) {
                new_coords[j] += point[j];
            }
        }
        
        // Calculate average
        for (double& coord : new_coords) {
            coord /= clusters[i].size();
        }
        
        centroids[i] = new_coords;
    }
}

bool Kmeans::converged(const vector<vector<double>>& previous_centroids) {
    for (size_t i = 0; i < centroids.size(); ++i) {
        if (utils::calculateDistance(centroids[i], previous_centroids[i]) > tolerance) {
            return false;
        }
    }
    return true;
}

vector<vector<double>> Kmeans::getCentroids() const {
    return centroids;
}