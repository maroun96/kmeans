#include <iostream>
#include <vector>
#include <kmeans.h>
#include <ctime>

using std::vector;

int main() {
    // Seed random number generator
    srand(time(nullptr));
    
    // Create some example 2D points
    vector<vector<double>> points = {
        {1.0, 2.0}, {1.5, 1.8}, {2.0, 2.1},  // Cluster 1
        {8.0, 8.0}, {8.2, 8.1}, {8.4, 8.2},  // Cluster 2
        {15.0, 1.0}, {15.2, 1.1}, {15.5, 1.2}  // Cluster 3
    };

    // Initialize K-means with k=3 clusters, max 100 iterations, and tolerance of 0.0001
    Kmeans kmeans(3, 100, 0.0001);
    
    // Fit the model
    kmeans.fit(points);
    
    // Get and print the centroids
    auto centroids = kmeans.getCentroids();
    std::cout << "Final centroids:" << std::endl;
    for (size_t i = 0; i < centroids.size(); ++i) {
        std::cout << "Centroid " << i + 1 << ": (" 
                 << centroids[i][0] << ", " 
                 << centroids[i][1] << ")" << std::endl;
    }

    return 0;
}