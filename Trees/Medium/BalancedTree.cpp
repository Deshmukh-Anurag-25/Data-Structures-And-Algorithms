#include "Node.h"
#include <algorithm>
using namespace std;

/**
 * @brief Computes the height of a binary tree while checking if it is height-balanced.
 *
 * A binary tree is considered height-balanced if, for every node, the
 * difference between the heights of its left and right subtrees is at most 1.
 *
 * This function returns:
 * - The height of the subtree rooted at the current node if it is balanced.
 * - -1 immediately if an unbalanced subtree is detected.
 *
 * This allows balance checking and height computation to be performed in a
 * single traversal.
 *
 * Example:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 *
 * Returns:
 * Height = 3
 *
 * Example:
 *     1
 *    /
 *   2
 *  /
 * 3
 *
 * Returns:
 * -1 (tree is not balanced)
 *
 * Algorithm:
 * 1. If the node is nullptr, return 0.
 * 2. Recursively compute the left subtree height.
 * 3. If the left subtree is unbalanced, return -1.
 * 4. Recursively compute the right subtree height.
 * 5. If the right subtree is unbalanced, return -1.
 * 6. If the height difference exceeds 1, return -1.
 * 7. Otherwise, return the subtree height.
 *
 * @param root Pointer to the root of the current subtree.
 * @return int Height of the subtree if balanced, otherwise -1.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes
 * - h = height of the tree
 */
int height(Node *root) {
    if (!root)
        return 0;

    int lh = height(root->left);
    if (lh == -1)
        return -1;

    int rh = height(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

/**
 * @brief Determines whether a binary tree is height-balanced.
 *
 * A binary tree is height-balanced if, for every node, the heights of the
 * left and right subtrees differ by at most one.
 *
 * This function uses the optimized height() helper, which simultaneously
 * computes subtree heights and detects imbalance, avoiding repeated height
 * calculations.
 *
 * Example:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 *
 * Returns:
 * true
 *
 * Example:
 *     1
 *    /
 *   2
 *  /
 * 3
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. Compute the tree height using the helper function.
 * 2. If the helper returns -1, the tree is unbalanced.
 * 3. Otherwise, the tree is balanced.
 *
 * @param root Pointer to the root of the binary tree.
 * @return bool True if the tree is height-balanced, otherwise false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
bool isBalanced(Node *root) {
    return height(root) != -1;
}