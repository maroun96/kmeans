#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <random>
#include <kmeans.hpp>

using std::vector;

// Function to generate a cluster of points
void generate_cluster(double mean_x, double mean_y, double stddev_x, double stddev_y, int num_points, 
                      vector<vector<double>>& cluster_points) {
    // Create random number generators for x and y
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist_x(mean_x, stddev_x);
    std::normal_distribution<> dist_y(mean_y, stddev_y);

    // Generate points and store in x_coords and y_coords vectors
    for (int i = 0; i < num_points; ++i) {
        cluster_points.push_back({dist_x(gen), dist_y(gen)});
    }
}

int main() {
    // Define cluster parameters (mean_x, mean_y, stddev_x, stddev_y)
    int num_points_per_cluster = 100;

    // Vectors to store x and y coordinates
    vector<vector<double>> points;

    // Cluster 1: Mean (0,0), standard deviation (1,1)
    generate_cluster(0.0, 0.0, 1.0, 1.0, num_points_per_cluster, points);

    // Cluster 2: Mean (5,5), standard deviation (1,1)
    generate_cluster(5.0, 5.0, 1.0, 1.0, num_points_per_cluster, points);

    // Cluster 3: Mean (-5,5), standard deviation (1,1)
    generate_cluster(-5.0, 5.0, 1.0, 1.0, num_points_per_cluster, points);
    

    // Instantiate and fit the KMeans model
    Kmeans kmeans(3);
    kmeans.fit(points);

    auto centroids = kmeans.getCentroids();

    // Print centroids
    std::cout << "Computed centroids:\n";
    for (const auto& centroid : centroids) {
        for (double item : centroid) {
            std::cout << item << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}

