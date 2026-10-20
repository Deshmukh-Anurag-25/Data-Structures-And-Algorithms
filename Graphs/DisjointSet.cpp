#include <vector>
using namespace std;

/**
 * @brief Implements Disjoint Set Union (DSU) using path compression,
 *        union by rank, and union by size.
 *
 * Maintains disjoint sets and supports finding the ultimate parent
 * and merging two sets efficiently.
 */
class DisjointSet {
    vector<int> rank, parent, size;

public:
    /**
     * @brief Initializes every node as a separate set.
     *
     * @param n Maximum node index. Initializes nodes from 0 to n.
     */
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    /**
     * @brief Finds the ultimate parent using path compression.
     *
     * @param node The node whose ultimate parent is required.
     * @return The ultimate parent of the node.
     *
     * Time Complexity: O(alpha(n)) amortized.
     */
    int findUlPar(int node) {
        if (node == parent[node]) return node;

        return parent[node] = findUlPar(parent[node]);
    }

    /**
     * @brief Merges two sets using union by rank.
     *
     * Attaches the lower-rank tree under the higher-rank tree.
     * If both ranks are equal, one root becomes the parent and
     * its rank increases by one.
     *
     * @param u First node.
     * @param v Second node.
     *
     * Time Complexity: O(alpha(n)) amortized.
     */
    void unionByRank(int u, int v) {
        int ulp_u = findUlPar(u);
        int ulp_v = findUlPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    /**
     * @brief Merges two sets using union by size.
     *
     * Attaches the smaller set under the larger set and updates
     * the size of the new root. If both sets have equal size,
     * ulp_u becomes the parent of ulp_v.
     *
     * @param u First node.
     * @param v Second node.
     *
     * Time Complexity: O(alpha(n)) amortized.
     */
    void unionBySize(int u, int v) {
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