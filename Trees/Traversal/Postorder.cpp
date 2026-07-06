#include "Node.h"
#include <vector>
using namespace std;

/**
 * @brief Performs a recursive postorder traversal of a binary tree.
 *
 * Visits the nodes in the following order:
 * 1. Left subtree
 * 2. Right subtree
 * 3. Root node
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
 * 4 → 5 → 2 → 3 → 1
 *
 * Result:
 * {4, 5, 2, 3, 1}
 *
 * Algorithm:
 * 1. If the current node is nullptr, return.
 * 2. Recursively traverse the left subtree.
 * 3. Recursively traverse the right subtree.
 * 4. Visit the current node.
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
    dfs(root->right, ans);
    ans.push_back(root->val);
}

/**
 * @brief Returns the postorder traversal of a binary tree.
 *
 * Performs a recursive postorder traversal (Left → Right → Root)
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
 * {4, 5, 2, 3, 1}
 *
 * Algorithm:
 * 1. Create an empty result vector.
 * 2. Perform a recursive postorder traversal.
 * 3. Return the populated vector.
 *
 * Note:
 * - If the tree is empty, an empty vector is returned.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<int> The postorder traversal of the tree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes
 * - h = height of the tree
 */
vector<int> postorder(Node *root) {
    vector<int> ans;
    dfs(root, ans);
    return ans;
}