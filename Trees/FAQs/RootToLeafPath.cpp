#include "Node.h"
#include <vector>
using namespace std;

/**
 * @brief Stores all root-to-leaf paths of a binary tree.
 */
vector<vector<int>> ans;

/**
 * @brief Performs a depth-first traversal to collect all root-to-leaf paths.
 *
 * The function maintains the current path from the root to the current node.
 * Whenever a leaf node is reached, the current path is added to the result.
 *
 * @param root Pointer to the current node.
 * @param path Stores the current root-to-node path.
 */
void dfs(Node* root, vector<int>& path) {
    if (!root)
        return;

    path.push_back(root->val);

    if (!root->left && !root->right) {
        ans.push_back(path);
    } else {
        dfs(root->left, path);
        dfs(root->right, path);
    }

    path.pop_back();
}

/**
 * @brief Returns all root-to-leaf paths in a binary tree.
 *
 * A root-to-leaf path is a sequence of node values starting at the root
 * and ending at a leaf node.
 *
 * Example:
 *            1
 *          /   \
 *         2     3
 *          \
 *           5
 *
 * Returns:
 * {
 *   {1, 2, 5},
 *   {1, 3}
 * }
 *
 * Algorithm:
 * 1. Start a DFS traversal from the root.
 * 2. Add each visited node to the current path.
 * 3. If a leaf node is reached, store the current path.
 * 4. Backtrack by removing the current node before returning.
 *
 * Note:
 * - Every root-to-leaf path is included exactly once.
 * - The order of paths follows a depth-first traversal.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<vector<int>> A list containing all root-to-leaf paths.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes in the tree.
 * - h = height of the tree (excluding the output).
 */
vector<vector<int>> allRootToLeaf(Node* root) {
    ans.clear();

    vector<int> path;
    dfs(root, path);

    return ans;
}