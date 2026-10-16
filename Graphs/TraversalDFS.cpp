#include <vector>
using namespace std;

/**
 * @brief Performs Depth First Search (DFS) traversal of a graph.
 *
 * Marks the current node as visited, adds it to the traversal,
 * and recursively explores all its unvisited neighbours.
 *
 * @param node The current node being visited.
 * @param adj The adjacency list representing the graph.
 * @param vis Visited array to avoid revisiting nodes.
 * @param ans Stores nodes in DFS traversal order.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) for the recursion stack.
 */
void dfs(int node, vector<vector<int>>& adj,
         vector<int>& vis, vector<int>& ans) {

    vis[node] = 1;
    ans.push_back(node);

    for (int neighbour : adj[node]) {
        if (!vis[neighbour]) {
            dfs(neighbour, adj, vis, ans);
        }
    }
}

/**
 * @brief Performs DFS traversal of the entire graph.
 *
 * Starts DFS from every unvisited vertex to ensure that
 * disconnected components are also visited.
 *
 * @param adj The adjacency list representing the graph.
 * @return A vector containing the DFS traversal order.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) auxiliary space.
 */
vector<int> dfsTraversal(vector<vector<int>>& adj) {
    int n = adj.size();

    vector<int> vis(n, 0);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, ans);
        }
    }

    return ans;
}
