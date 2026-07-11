#include "Node.h"
#include <vector>
using namespace std;

/**
 * @brief Computes the boundary traversal of a binary tree in anti-clockwise order.
 *
 * The boundary traversal consists of:
 * 1. The root node.
 * 2. The left boundary (excluding leaf nodes).
 * 3. All leaf nodes from left to right.
 * 4. The right boundary (excluding leaf nodes) in reverse order.
 *
 * The traversal ensures that no node appears more than once in the result.
 *
 * Example:
 *              1
 *            /   \
 *           2     3
 *          / \   / \
 *         4   5 6   7
 *            / \
 *           8   9
 *
 * Boundary Traversal:
 * 1 -> 2 -> 4 -> 8 -> 9 -> 6 -> 7 -> 3
 *
 * Algorithm:
 * 1. Add the root node.
 * 2. Traverse the left boundary while excluding leaf nodes.
 * 3. Traverse the entire tree to collect all leaf nodes.
 * 4. Traverse the right boundary while excluding leaf nodes and add
 *    the nodes in reverse order.
 * 5. Concatenate all parts to obtain the final boundary traversal.
 *
 * Note:
 * - The root is included only once.
 * - Leaf nodes are not included in the left or right boundary traversal.
 * - If the tree consists of only the root node, the result contains only
 *   the root.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<int> The boundary traversal of the binary tree in
 *         anti-clockwise order.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes in the tree.
 * - h = height of the tree (recursion stack).
 */

/// @brief Collects the left boundary excluding leaf nodes.
void calcLeft(Node* root, vector<int>& left) {
    if (!root)
        return;

    if (!root->left && !root->right)
        return;

    left.push_back(root->val);

    if (root->left)
        calcLeft(root->left, left);
    else
        calcLeft(root->right, left);
}

/// @brief Collects all leaf nodes from left to right.
void calcLeaf(Node* root, vector<int>& leaf) {
    if (!root)
        return;

    calcLeaf(root->left, leaf);
    calcLeaf(root->right, leaf);

    if (!root->left && !root->right)
        leaf.push_back(root->val);
}

/// @brief Collects the right boundary excluding leaf nodes in reverse order.
void calcRight(Node* root, vector<int>& right) {
    if (!root)
        return;

    if (!root->left && !root->right)
        return;

    if (root->right)
        calcRight(root->right, right);
    else
        calcRight(root->left, right);

    right.push_back(root->val);
}

vector<int> boundary(Node* root) {
    if (!root)
        return {};

    vector<int> left, leaf, right;

    calcLeft(root->left, left);
    calcLeaf(root, leaf);
    calcRight(root->right, right);

    vector<int> ans;
    ans.push_back(root->val);

    ans.insert(ans.end(), left.begin(), left.end());

    if (root->left || root->right)
        ans.insert(ans.end(), leaf.begin(), leaf.end());

    ans.insert(ans.end(), right.begin(), right.end());

    return ans;
}