#include <queue>
#include <vector>
using namespace std;

/**
 * @brief Detects a cycle in a directed graph using BFS.
 *
 * Uses Kahn's Algorithm (Topological Sort) to detect cycles.
 * Initially, all vertices with indegree 0 are added to the queue.
 * Each processed vertex reduces the indegree of its neighbours.
 *
 * If all vertices are processed, the graph contains no cycle.
 * If some vertices remain unprocessed, a cycle exists.
 *
 * @param n Number of vertices in the graph.
 * @param edges List of directed edges, where each edge [u, v]
 *              represents a directed edge from u to v.
 *
 * @return True if the graph contains a cycle, otherwise false.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E), including the adjacency list.
 */
bool isCycle(int n, vector<vector<int>>& edges) {

    // Build the adjacency list and calculate indegrees.
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (auto& it : edges) {
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }

    // Initialize the queue with vertices having indegree 0.
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Count the number of processed vertices.
    int cnt = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cnt++;

        // Remove the outgoing edges of the current vertex.
        for (int neighbour : adj[node]) {
            indegree[neighbour]--;

            // Process the neighbour when its indegree becomes 0.
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // If some vertices remain unprocessed, a cycle exists.
    return cnt != n;
}