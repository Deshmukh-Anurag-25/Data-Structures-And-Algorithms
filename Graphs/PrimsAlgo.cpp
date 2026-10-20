#include <vector>
#include <queue>
using namespace std;

/**
 * @brief Calculates the Minimum Spanning Tree (MST) weight using Prim's Algorithm.
 *
 * Builds an adjacency list from the given edge list and uses a min-priority
 * queue to greedily select the minimum-weight edge connecting a visited
 * vertex to an unvisited vertex.
 *
 * Each vertex is added to the MST only once, preventing cycles.
 *
 * @param n Number of vertices in the graph.
 * @param edges List of edges, where each edge contains {u, v, weight}.
 * @return Total weight of the Minimum Spanning Tree.
 *
 * Time Complexity: O(E log E)
 * Space Complexity: O(V + E)
 */
int primsWeight(int n, vector<vector<int>>& edges) {

    // Adjacency list: {weight, neighbour}
    vector<vector<pair<int, int>>> adj(n);

    for (auto& it : edges) {
        adj[it[0]].push_back({it[2], it[1]});
        adj[it[1]].push_back({it[2], it[0]});
    }

    vector<int> vis(n, 0);

    // Min-priority queue: {weight, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int weight = it.first;

        // Skip vertices already included in the MST
        if (vis[node]) continue;

        vis[node] = 1;
        sum += weight;

        // Explore unvisited neighbours
        for (auto& it : adj[node]) {
            int adjNode = it.second;
            int adjWt = it.first;

            if (!vis[adjNode]) {
                pq.push({adjWt, adjNode});
            }
        }
    }

    return sum;
}