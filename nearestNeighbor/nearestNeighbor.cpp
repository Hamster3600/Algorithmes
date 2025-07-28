#include <iostream>
#include <vector>
#include <limits> 

const int INF = std::numeric_limits<int>::max();

void solveTSPNearestNeighbor(const std::vector<std::vector<int>>& graph) {
    int numCities = graph.size();
    std::vector<bool> visited(numCities, false);
    std::vector<int> path;
    int currentCity = 0; 
    int totalCost = 0;

    path.push_back(currentCity);
    visited[currentCity] = true;

    for (int i = 0; i < numCities - 1; i++) {
        int nearestCity = -1;
        int minCost = INF;

        for (int nextCity = 0; nextCity < numCities; nextCity++) {
            if (!visited[nextCity] && graph[currentCity][nextCity] < minCost) {
                minCost = graph[currentCity][nextCity];
                nearestCity = nextCity;
            }
        }
        totalCost += minCost;
        currentCity = nearestCity;
        path.push_back(currentCity);
        visited[currentCity] = true;
    }

    totalCost += graph[path.back()][path[0]];

    std::cout << "Path: ";
    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << " -> " << path[0] << std::endl;
    std::cout << "Total Cost: " << totalCost << std::endl;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    solveTSPNearestNeighbor(graph);
    return 0;
}