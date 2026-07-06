#include "Node.h"
#include <vector>
using namespace std;

/**
 * @brief Performs a recursive preorder traversal of a binary tree.
 *
 * Visits the nodes in the following order:
 * 1. Root node
 * 2. Left subtree
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
 * 1 → 2 → 4 → 5 → 3
 *
 * Result:
 * {1, 2, 4, 5, 3}
 *
 * Algorithm:
 * 1. If the current node is nullptr, return.
 * 2. Visit the current node.
 * 3. Recursively traverse the left subtree.
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

    ans.push_back(root->val);
    dfs(root->left, ans);
    dfs(root->right, ans);
}

/**
 * @brief Returns the preorder traversal of a binary tree.
 *
 * Performs a recursive preorder traversal (Root → Left → Right)
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
 * {1, 2, 4, 5, 3}
 *
 * Algorithm:
 * 1. Create an empty result vector.
 * 2. Perform a recursive preorder traversal.
 * 3. Return the populated vector.
 *
 * Note:
 * - If the tree is empty, an empty vector is returned.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<int> The preorder traversal of the tree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes
 * - h = height of the tree
 */
vector<int> preorder(Node *root) {
    vector<int> ans;
    dfs(root, ans);
    return ans;
}