#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/**
 * @brief Constructs a Minimum Spanning Tree (MST) using Prim's Algorithm.
 *
 * Builds an adjacency list from the given edge list and uses a min-priority
 * queue to greedily select the minimum-weight edge connecting an unvisited
 * vertex to the growing MST.
 *
 * Stores each selected edge as {parent, node, weight} to construct the MST.
 *
 * @param n Number of vertices in the graph.
 * @param edges List of edges, where each edge contains {u, v, weight}.
 * @return List of MST edges, where each edge contains {parent, node, weight}.
 *
 * Time Complexity: O(E log E)
 * Space Complexity: O(V + E)
 */
vector<vector<int>> mstPrims(int n, vector<vector<int>>& edges) {

    // Adjacency list: {weight, neighbour}
    vector<vector<pair<int, int>>> adj(n);

    for (auto& it : edges) {
        adj[it[0]].push_back({it[2], it[1]});
        adj[it[1]].push_back({it[2], it[0]});
    }

    vector<int> vis(n, 0);

    // Min-priority queue: {weight, node, parent}
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > pq;

    pq.push({0, 0, -1});

    vector<vector<int>> mst;

    while (!pq.empty()) {
        auto [weight, node, parent] = pq.top();
        pq.pop();

        if (vis[node]) continue;

        vis[node] = 1;

        // Store the edge selected for the MST
        if (parent != -1) {
            mst.push_back({parent, node, weight});
        }

        // Explore unvisited neighbours
        for (auto& it : adj[node]) {
            int adjWt = it.first;
            int adjNode = it.second;

            if (!vis[adjNode]) {
                pq.push({adjWt, adjNode, node});
            }
        }
    }

    return mst;
}