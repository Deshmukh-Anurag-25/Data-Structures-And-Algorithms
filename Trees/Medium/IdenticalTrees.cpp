#include "Node.h"

/**
 * @brief Determines whether two binary trees are identical.
 *
 * Two binary trees are considered identical if they satisfy all of the
 * following conditions:
 * - They have the same structure.
 * - Corresponding nodes contain the same value.
 * - Their left subtrees are identical.
 * - Their right subtrees are identical.
 *
 * The function recursively compares corresponding nodes in both trees.
 *
 * Example:
 *
 * Tree 1:          Tree 2:
 *      1                1
 *     / \              / \
 *    2   3            2   3
 *
 * Returns:
 * true
 *
 * Example:
 *
 * Tree 1:          Tree 2:
 *      1                1
 *     /                  \
 *    2                    2
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. If both nodes are nullptr, the current subtrees are identical.
 * 2. If only one node is nullptr, the trees differ.
 * 3. If the node values differ, the trees are not identical.
 * 4. Recursively compare:
 *    - Left subtrees
 *    - Right subtrees
 * 5. Return true only if both recursive comparisons return true.
 *
 * Note:
 * - Both structure and node values must match exactly.
 * - The comparison is performed using a depth-first traversal.
 *
 * @param p Pointer to the root of the first binary tree.
 * @param q Pointer to the root of the second binary tree.
 * @return bool True if the two trees are identical, otherwise false.
 *
 * Time Complexity: O(min(n, m))
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes in the first tree
 * - m = number of nodes in the second tree
 * - h = maximum height of the recursion stack
 */
bool isIdentical(Node *p, Node *q) {
    if (!p && !q)
        return true;

    if (!p || !q)
        return false;

    if (p->val != q->val)
        return false;

    return isIdentical(p->left, q->left) &&
           isIdentical(p->right, q->right);
}