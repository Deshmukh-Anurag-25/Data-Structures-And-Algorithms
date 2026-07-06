#include "Node.h"
#include <vector>
using namespace std;

/**
 * @brief Performs a recursive inorder traversal of a binary tree.
 *
 * Visits the nodes in the following order:
 * 1. Left subtree
 * 2. Root node
 * 3. Right subtree
 *
 * The visited node values are appended to the provided result vector.
 *
 * Example:
 *        1
 *       / \
 *      2   3
 *     / \
 *    4   5
 *
 * Traversal:
 * 4 → 2 → 5 → 1 → 3
 *
 * Result:
 * {4, 2, 5, 1, 3}
 *
 * Algorithm:
 * 1. If the current node is nullptr, return.
 * 2. Recursively traverse the left subtree.
 * 3. Visit the current node.
 * 4. Recursively traverse the right subtree.
 *
 * Note:
 * - This is a recursive depth-first traversal.
 * - The result vector is updated in-place.
 *
 * @param root Pointer to the current node.
 * @param ans Vector used to store the traversal.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes
 * - h = height of the tree (recursive call stack)
 */
void dfs(Node *root, vector<int> &ans) {
    if (!root)
        return;

    dfs(root->left, ans);
    ans.push_back(root->val);
    dfs(root->right, ans);
}

/**
 * @brief Returns the inorder traversal of a binary tree.
 *
 * Performs a recursive inorder traversal (Left → Root → Right)
 * and returns the visited node values as a vector.
 *
 * Example:
 *        1
 *       / \
 *      2   3
 *     / \
 *    4   5
 *
 * Returns:
 * {4, 2, 5, 1, 3}
 *
 * Algorithm:
 * 1. Create an empty result vector.
 * 2. Perform a recursive inorder traversal.
 * 3. Return the populated vector.
 *
 * Note:
 * - If the tree is empty, an empty vector is returned.
 * - In a Binary Search Tree (BST), an inorder traversal visits the nodes
 *   in non-decreasing (sorted) order.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<int> The inorder traversal of the tree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes
 * - h = height of the tree
 */
vector<int> inorder(Node *root) {
    vector<int> ans;
    dfs(root, ans);
    return ans;
}