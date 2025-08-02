/* 
Explanation of the algorithm:
1. The program implements Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a graph.
2. The function `sortEdges`:
   - Sorts the edges of the graph based on their weights using a simple sorting algorithm.
3. The `DSU` (Disjoint Set Union) structure:
   - Provides methods for union-find operations to detect cycles in the graph.
   - Includes `find` to locate the root of a set and `unite` to merge two sets.
4. The function `kruskalMST`:
   - Sorts the edges by weight.
   - Iterates through the edges, adding them to the MST if they do not form a cycle.
   - Uses the DSU structure to manage connected components.
   - Outputs the edges in the MST and the total weight.
5. The main function:
   - Defines a graph with vertices and edges.
   - Calls `kruskalMST` to compute and display
*/

#include <iostream>
#include <vector>

struct Edge {
    int u, v, weight;
};

void sortEdges(std::vector<Edge>& edges) {
    int n = edges.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

struct DSU { 
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }
};

void kruskalMST(int numVertices, std::vector<Edge>& edges) {
    sortEdges(edges);
    DSU dsu(numVertices);
    std::vector<Edge> mst;
    int mstWeight = 0;

    for (const Edge& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst.push_back(edge);
            mstWeight += edge.weight;
        }
    }

    std::cout << "MST Edges:" << std::endl;
    for (int i = 0; i < mst.size(); i++) {
        std::cout << mst[i].u << " - " << mst[i].v << " (Weight: " << mst[i].weight << ")" << std::endl;
    }
    std::cout << "Total MST Weight: " << mstWeight << std::endl;
}

int main() {
    int numVertices = 4;
    std::vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    kruskalMST(numVertices, edges);
    return 0;
}