#include "Node.h"
#include <map>
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief Computes the bottom view of a binary tree.
 *
 * The bottom view consists of the nodes visible when the tree is viewed
 * from below. For every horizontal distance from the root, the bottommost
 * node is included in the result.
 *
 * A level order traversal (BFS) is performed while tracking the horizontal
 * distance (HD) of each node:
 * - Root has HD = 0.
 * - Left child has HD - 1.
 * - Right child has HD + 1.
 *
 * Since BFS processes nodes level by level, overwriting the value for a
 * horizontal distance ensures that the deepest node encountered at that
 * distance is retained.
 *
 * Example:
 *            20
 *           /  \
 *          8    22
 *         / \     \
 *        5   3     25
 *           / \
 *          10 14
 *
 * Bottom View:
 * {5, 10, 3, 14, 25}
 *
 * Algorithm:
 * 1. If the tree is empty, return an empty vector.
 * 2. Perform a BFS while storing each node's horizontal distance.
 * 3. For every visited node:
 *    - Update the value corresponding to its horizontal distance.
 *    - Enqueue its left and right children with updated distances.
 * 4. Traverse the ordered map from leftmost to rightmost horizontal
 *    distance and collect the stored values.
 *
 * Note:
 * - When multiple nodes share the same horizontal distance, the node
 *   appearing at the greatest depth is included.
 * - If two nodes are at the same depth and horizontal distance, the node
 *   processed later during BFS (typically the right one) is retained.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<int> The bottom view of the binary tree from left to right.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * where:
 * - n = number of nodes
 */
vector<int> bottomView(Node *root) {
    if (!root)
        return {};

    queue<pair<Node *, int>> q;
    map<int, int> mpp;
    vector<int> ans;

    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        Node *node = it.first;
        int line = it.second;

        mpp[line] = node->val;

        if (node->left)
            q.push({node->left, line - 1});

        if (node->right)
            q.push({node->right, line + 1});
    }

    for (auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans;
}