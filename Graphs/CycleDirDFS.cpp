
#include <vector>
using namespace std;

/**
 * @brief Detects a cycle in a directed graph using DFS.
 *
 * Marks the current node as visited and adds it to the current
 * DFS recursion path.
 *
 * If a neighbour is already in the current recursion path,
 * a directed cycle exists.
 *
 * @param node The current vertex being visited.
 * @param adj The adjacency list representing the directed graph.
 * @param vis Visited array to avoid revisiting vertices.
 * @param pathVis Tracks vertices in the current DFS recursion path.
 * @return True if a cycle is detected, otherwise false.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) for the visited arrays and recursion stack.
 */
bool dfs(int node, vector<vector<int>>& adj,
         vector<int>& vis, vector<int>& pathVis) {

    vis[node] = 1;
    pathVis[node] = 1;

    for (int neighbour : adj[node]) {
        if (!vis[neighbour]) {
            if (dfs(neighbour, adj, vis, pathVis)) {
                return true;
            }
        }
        else if (pathVis[neighbour]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

/**
 * @brief Determines whether a directed graph contains a cycle.
 *
 * Builds an adjacency list from the directed edge list and
 * starts DFS from every unvisited vertex to handle disconnected
 * components.
 *
 * @param n Number of vertices in the graph.
 * @param edges List of directed edges, where each edge [u, v]
 *              represents an edge from u to v.
 * @return True if the graph contains a cycle, otherwise false.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E) including the adjacency list.
 */
bool isCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);

    for (auto& it : edges) {
        adj[it[0]].push_back(it[1]);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathVis)) {
                return true;
            }
        }
    }

    return false;
}
