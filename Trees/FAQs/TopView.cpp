#include "Node.h"
#include <map>
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief Computes the top view of a binary tree.
 *
 * The top view consists of the nodes visible when the tree is viewed from
 * above. For every horizontal distance from the root, the first node
 * encountered is included in the result.
 *
 * A level order traversal (BFS) is performed while tracking the horizontal
 * distance (HD) of each node:
 * - Root has HD = 0.
 * - Left child has HD - 1.
 * - Right child has HD + 1.
 *
 * Since BFS processes nodes level by level, the first node encountered at
 * each horizontal distance is the one visible from the top.
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
 * Top View:
 * {5, 8, 20, 22, 25}
 *
 * Algorithm:
 * 1. If the tree is empty, return an empty vector.
 * 2. Perform a BFS while storing each node's horizontal distance.
 * 3. For every visited node:
 *    - If its horizontal distance has not been seen before,
 *      store its value.
 *    - Enqueue its left and right children with updated
 *      horizontal distances.
 * 4. Traverse the ordered map from leftmost to rightmost horizontal
 *    distance and collect the stored values.
 *
 * Note:
 * - Only the first node encountered at each horizontal distance is stored.
 * - BFS guarantees that higher-level nodes are processed before lower-level
 *   nodes.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<int> The top view of the binary tree from left to right.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * where:
 * - n = number of nodes
 */
vector<int> topView(Node *root) {
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

        if (mpp.find(line) == mpp.end())
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