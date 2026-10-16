#include <vector>
#include <queue>
using namespace std;

/**
 * @brief Performs Breadth First Search (BFS) traversal of a graph.
 *
 * Visits nodes level by level using a queue. Marks each node
 * as visited when it is added to the queue to prevent duplicates.
 *
 * @param src The starting vertex for BFS.
 * @param adj The adjacency list representing the graph.
 * @param vis Visited array to avoid revisiting nodes.
 * @param ans Stores nodes in BFS traversal order.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) for the queue.
 */
void bfs(int src, vector<vector<int>>& adj,
         vector<int>& vis, vector<int>& ans) {

    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                vis[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
}

/**
 * @brief Performs BFS traversal of the entire graph.
 *
 * Starts BFS from every unvisited vertex to ensure that
 * disconnected components are also visited.
 *
 * @param adj The adjacency list representing the graph.
 * @return A vector containing the BFS traversal order.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) auxiliary space.
 */
vector<int> bfsTraversal(vector<vector<int>>& adj) {
    int n = adj.size();

    vector<int> vis(n, 0);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            bfs(i, adj, vis, ans);
        }
    }

    return ans;
}
