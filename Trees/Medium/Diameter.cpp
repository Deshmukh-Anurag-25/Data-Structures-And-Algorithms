#include "Node.h"
#include <algorithm>
using namespace std;

/**
 * @brief Computes the height of a binary tree while updating its diameter.
 *
 * The diameter of a binary tree is the length (in edges) of the longest path
 * between any two nodes in the tree. This path may or may not pass through
 * the root.
 *
 * During the recursive computation of subtree heights, the diameter is
 * updated using:
 *
 *      leftHeight + rightHeight
 *
 * since the longest path passing through the current node consists of the
 * deepest node in the left subtree to the deepest node in the right subtree.
 *
 * Example:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 *
 * Heights:
 * - Left subtree = 2
 * - Right subtree = 1
 *
 * Diameter = 3 edges
 * (4 → 2 → 1 → 3)
 *
 * Algorithm:
 * 1. Recursively compute the left subtree height.
 * 2. Recursively compute the right subtree height.
 * 3. Update the maximum diameter using:
 *      leftHeight + rightHeight
 * 4. Return:
 *      1 + max(leftHeight, rightHeight)
 *
 * Note:
 * - Height is measured in nodes.
 * - Diameter is measured in edges.
 * - Both height computation and diameter calculation are completed in a
 *   single DFS traversal.
 *
 * @param root Pointer to the current node.
 * @param diameter Reference to the maximum diameter found so far.
 * @return int Height of the current subtree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes
 * - h = height of the tree
 */
int height(Node *root, int &diameter) {
    if (!root)
        return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

/**
 * @brief Computes the diameter of a binary tree.
 *
 * The diameter is defined as the number of edges on the longest path between
 * any two nodes in the tree. The longest path does not necessarily pass
 * through the root.
 *
 * This implementation computes the diameter in a single traversal by
 * simultaneously calculating subtree heights.
 *
 * Example:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 *
 * Longest path:
 * 4 → 2 → 1 → 3
 *
 * Returns:
 * 3
 *
 * Algorithm:
 * 1. Initialize the diameter to 0.
 * 2. Perform a DFS that computes subtree heights.
 * 3. Update the diameter at every node.
 * 4. Return the maximum diameter found.
 *
 * Note:
 * - Diameter is measured in edges.
 * - For an empty tree or a tree with a single node, the diameter is 0.
 *
 * @param root Pointer to the root of the binary tree.
 * @return int The diameter of the binary tree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
int diameterOfBinaryTree(Node *root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}