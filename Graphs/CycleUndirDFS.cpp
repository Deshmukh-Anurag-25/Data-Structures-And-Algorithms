
#include <vector>
using namespace std;

/**
 * @brief Detects a cycle in an undirected graph using DFS.
 *
 * Marks the current node as visited and recursively explores
 * its unvisited neighbours.
 *
 * If a visited neighbour is found that is not the parent of
 * the current node, a cycle exists.
 *
 * @param node The current vertex being visited.
 * @param parent The parent vertex from which the current node was reached.
 * @param adj The adjacency list representing the graph.
 * @param vis Visited array to avoid revisiting vertices.
 * @return True if a cycle is detected, otherwise false.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) for the visited array and recursion stack.
 */
bool dfs(int node, int parent, vector<vector<int>>& adj,
         vector<int>& vis) {

    vis[node] = 1;

    for (int neighbour : adj[node]) {

        if (!vis[neighbour]) {
            if (dfs(neighbour, node, adj, vis)) {
                return true;
            }
        }
        else if (neighbour != parent) {
            return true;
        }
    }

    return false;
}

/**
 * @brief Determines whether an undirected graph contains a cycle.
 *
 * Builds an adjacency list from the given edge list and starts
 * DFS from every unvisited vertex to handle disconnected graphs.
 *
 * @param V Number of vertices in the graph.
 * @param edges List of edges, where each edge contains two vertices.
 * @return True if the graph contains a cycle, otherwise false.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E) including the adjacency list.
 */
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);

    for (auto& it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis)) {
                return true;
            }
        }
    }

    return false;
}
