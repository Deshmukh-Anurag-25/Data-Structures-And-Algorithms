
#include <vector>
using namespace std;

/**
 * @brief Disjoint Set Union (DSU) using path compression
 *        and union by size.
 *
 * Maintains disjoint sets and efficiently merges sets
 * or determines whether two nodes belong to the same set.
 */
class DSU {
    vector<int> size, parent;

public:
    /**
     * @brief Initializes each node as a separate set.
     *
     * @param n Maximum node index. Initializes nodes from 0 to n.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    /**
     * @brief Finds the ultimate parent using path compression.
     *
     * @param x The node whose ultimate parent is required.
     * @return The ultimate parent (representative) of x.
     *
     * Time Complexity: O(alpha(n)) amortized.
     */
    int findUlPar(int x) {
        if (x == parent[x]) return x;

        // Path compression
        return parent[x] = findUlPar(parent[x]);
    }

    /**
     * @brief Merges the sets containing u and v using union by size.
     *
     * Attaches the smaller set under the larger set and updates
     * the size of the resulting set.
     *
     * @param u First node.
     * @param v Second node.
     *
     * Time Complexity: O(alpha(n)) amortized.
     */
    void unite(int u, int v) {
        int ulp_u = findUlPar(u);
        int ulp_v = findUlPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

/**
 * @brief Detects whether an undirected graph contains a cycle.
 *
 * Uses DSU to check whether the endpoints of an edge are already
 * connected. If they are, the edge creates a cycle.
 *
 * Processes each undirected edge once using u < v.
 *
 * @param V Number of vertices, numbered from 0 to V-1.
 * @param adj Adjacency list representing the undirected graph.
 * @return true if a cycle exists, false otherwise.
 *
 * Time Complexity: O(V + E * alpha(V)).
 * Space Complexity: O(V) auxiliary space for DSU.
 */
class Solution {
public:
    bool detectCycle(int V, vector<int> adj[]) {
        // Initialize DSU for all vertices
        DSU dsu(V);

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {

                // Process each undirected edge only once
                if (u < v) {

                    // If both vertices have the same parent,
                    // they are already connected, so a cycle exists.
                    if (dsu.findUlPar(u) == dsu.findUlPar(v)) {
                        return true;
                    }

                    // Merge their connected components
                    dsu.unite(u, v);
                }
            }
        }

        // No cycle was found
        return false;
    }
};
