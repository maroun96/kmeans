#include <kmeans.hpp>
#include <utils.hpp>
#include <cmath>
#include <iostream>
#include <limits>
#include <set>

using std::vector;

Kmeans::Kmeans(int n_clusters, int max_iterations, double tolerance)
    : n_clusters(n_clusters), 
      max_iterations(max_iterations), 
      tolerance(tolerance), 
      rng(std::random_device{}()) {}

void Kmeans::initializeCentroids(const vector<vector<double>>& points){
    std::uniform_int_distribution<int> dist(0, points.size()-1);
    std::set<int> random_indices_set;

    while (random_indices_set.size() < static_cast<size_t>(n_clusters)){
        random_indices_set.insert(dist(rng));
    }

    for (auto index : random_indices_set){
        centroids.push_back(points[index]);
    }
}

int Kmeans::findNearestCluster(const vector<double>& point){
    int cluster_index;
    double distance;
    double current_minimum_distance = std::numeric_limits<double>::max();

    for (int i = 0; i < n_clusters; i++){
        distance = utils::calculateDistance(centroids[i], point);
        if (distance < current_minimum_distance){
            cluster_index = i;
            current_minimum_distance = distance;
        }
    }

    return cluster_index;
}

void Kmeans::updateClusterIndices(const vector<vector<double>>& points){
    cluster_indices.clear();
    for (auto point : points){
        cluster_indices.push_back(findNearestCluster(point));
    }
}

void Kmeans::updateCentroids(const vector<vector<double>>& points){
    int cluster_index;
    vector<int> count(n_clusters);
    vector<vector<double>> sum(n_clusters, vector<double>(features_dim));

    for (int i = 0; i < points_dim; i++){
        cluster_index = cluster_indices[i];
        count[cluster_index]++;
        for (int j = 0; j < features_dim; j++){
            sum[cluster_index][j] += points[i][j];
        }
    }

    for (int i = 0; i < n_clusters; i++){
        for (int j = 0; j < features_dim; j++){
            centroids[i][j] = sum[i][j]/count[i];
        }
    }
}

bool Kmeans::converged(const vector<vector<double>>& previous_centroids){
    for (int i = 0; i < n_clusters; i++){
        if (utils::calculateDistance(centroids[i], previous_centroids[i]) > tolerance){
            return false;
        }
    }
    return true;
}

void Kmeans::fit(const vector<vector<double>>& points){
    points_dim = points.size();
    features_dim = points[0].size();
    cluster_indices.resize(points.size());

    // Step 1: Initialize centroids randomly
    initializeCentroids(points);

    for (int iter = 0; iter < max_iterations; iter++) {
        vector<vector<double>> previous_centroids = centroids;

        // Step 2: Assign points to the nearest cluster
        updateClusterIndices(points);

        // Step 3: Update centroids based on cluster assignments
        updateCentroids(points);

        // Step 4: Check for convergence
        if (converged(previous_centroids)) {
            break;
        }
    }
}

vector<vector<double>> Kmeans::getCentroids() const{
    return centroids;
}

vector<int> Kmeans::getClusterIndices() const{
    return cluster_indices;
}