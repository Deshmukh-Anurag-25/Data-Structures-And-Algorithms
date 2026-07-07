#include "Node.h"
#include <algorithm>
using namespace std;

/**
 * @brief Computes the maximum depth (height) of a binary tree.
 *
 * The maximum depth of a binary tree is the number of nodes along the
 * longest path from the root node down to the farthest leaf node.
 *
 * The function recursively computes the depths of the left and right
 * subtrees and returns one plus the greater of the two.
 *
 * Example:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 *
 * Maximum depth = 3
 *
 * Longest paths:
 * 1 → 2 → 4
 * 1 → 2 → 5
 *
 * Example:
 *
 *      1
 *       \
 *        2
 *         \
 *          3
 *
 * Maximum depth = 3
 *
 * Algorithm:
 * 1. If the current node is nullptr, return 0.
 * 2. Recursively compute the depth of the left subtree.
 * 3. Recursively compute the depth of the right subtree.
 * 4. Return:
 *      1 + max(leftDepth, rightDepth)
 *
 * Note:
 * - The depth of an empty tree is 0.
 * - A tree containing only the root node has depth 1.
 * - Height and maximum depth are commonly used interchangeably.
 *
 * @param root Pointer to the root of the binary tree.
 * @return int The maximum depth (height) of the tree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes
 * - h = height of the tree (recursive call stack)
 */
int maxDepth(Node *root) {
    if (!root)
        return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return 1 + max(leftHeight, rightHeight);
}