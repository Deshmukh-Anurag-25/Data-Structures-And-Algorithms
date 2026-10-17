
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief Detects a cycle in an undirected graph using BFS.
 *
 * Traverses the graph level by level using a queue.
 * Each queue entry stores the current node and its parent.
 *
 * If an already visited neighbour is found that is not the
 * parent of the current node, a cycle exists.
 *
 * @param src The starting vertex for BFS.
 * @param adj The adjacency list representing the graph.
 * @param vis Visited array to avoid revisiting vertices.
 * @return True if a cycle is detected, otherwise false.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) for the visited array and queue.
 */
bool bfs(int src, vector<vector<int>>& adj, vector<int>& vis) {
    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = 1;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                vis[neighbour] = 1;
                q.push({neighbour, node});
            }
            else if (neighbour != parent) {
                return true;
            }
        }
    }

    return false;
}

/**
 * @brief Determines whether an undirected graph contains a cycle.
 *
 * Constructs an adjacency list from the given edge list and
 * starts BFS from every unvisited vertex to handle disconnected
 * components.
 *
 * @param V Number of vertices in the graph.
 * @param edges List of edges, where each edge contains two vertices.
 * @return True if the graph contains a cycle, otherwise false.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E) including the adjacency list.
 */
bool hasCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);

    for (auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (bfs(i, adj, vis)) {
                return true;
            }
        }
    }

    return false;
}
