#include "Node.h"
#include <vector>
using namespace std;

/**
 * @brief Performs a DFS to compute the right view of a binary tree.
 *
 * The traversal visits the right subtree before the left subtree.
 * The first node encountered at every depth is visible from the right side
 * and is added to the result.
 *
 * Example:
 *         1
 *        / \
 *       2   3
 *        \   \
 *         5   4
 *
 * Right View:
 * {1, 3, 4}
 *
 * Algorithm:
 * 1. If the current node is nullptr, return.
 * 2. If this is the first node visited at the current depth,
 *    add it to the result.
 * 3. Recursively visit the right subtree.
 * 4. Recursively visit the left subtree.
 *
 * @param root Pointer to the current node.
 * @param level Current depth in the tree.
 * @param ans Vector storing the right view.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
void dfsRight(Node *root, int level, vector<int> &ans) {
    if (!root)
        return;

    if (ans.size() == level)
        ans.push_back(root->val);

    dfsRight(root->right, level + 1, ans);
    dfsRight(root->left, level + 1, ans);
}

/**
 * @brief Returns the right side view of a binary tree.
 *
 * The right side view consists of the nodes visible when the tree is viewed
 * from its right side.
 *
 * Example:
 *         1
 *        / \
 *       2   3
 *        \   \
 *         5   4
 *
 * Returns:
 * {1, 3, 4}
 *
 * Algorithm:
 * 1. Perform a DFS that prioritizes the right subtree.
 * 2. Record the first node encountered at each depth.
 * 3. Return the collected nodes.
 *
 * Note:
 * - If the tree is empty, an empty vector is returned.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<int> The right side view from top to bottom.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
vector<int> rightSideView(Node *root) {
    vector<int> ans;
    dfsRight(root, 0, ans);
    return ans;
}

/**
 * @brief Performs a DFS to compute the left view of a binary tree.
 *
 * The traversal visits the left subtree before the right subtree.
 * The first node encountered at every depth is visible from the left side
 * and is added to the result.
 *
 * Example:
 *         1
 *        / \
 *       2   3
 *      /     \
 *     4       5
 *
 * Left View:
 * {1, 2, 4}
 *
 * Algorithm:
 * 1. If the current node is nullptr, return.
 * 2. If this is the first node visited at the current depth,
 *    add it to the result.
 * 3. Recursively visit the left subtree.
 * 4. Recursively visit the right subtree.
 *
 * Note:
 * - This helper function computes the left view but does not return it.
 * - A wrapper function similar to rightSideView() can be written if a
 *   complete left view API is required.
 *
 * @param root Pointer to the current node.
 * @param level Current depth in the tree.
 * @param ans Vector storing the left view.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
void dfsLeft(Node *root, int level, vector<int> &ans) {
    if (!root)
        return;

    if (ans.size() == level)
        ans.push_back(root->val);

    dfsLeft(root->left, level + 1, ans);
    dfsLeft(root->right, level + 1, ans);
}