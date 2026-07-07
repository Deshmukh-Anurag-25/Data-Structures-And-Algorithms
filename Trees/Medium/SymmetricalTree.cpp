#include "Node.h"

/**
 * @brief Determines whether two subtrees are mirror images of each other.
 *
 * Two trees are mirrors if:
 * - Their root nodes contain the same value.
 * - The left subtree of one tree is a mirror of the right subtree of the
 *   other tree.
 * - The right subtree of one tree is a mirror of the left subtree of the
 *   other tree.
 *
 * The function recursively compares corresponding mirrored nodes.
 *
 * Example:
 *
 * Tree 1:          Tree 2:
 *      2                2
 *     / \              / \
 *    3   4            4   3
 *
 * Returns:
 * true
 *
 * Example:
 *
 * Tree 1:          Tree 2:
 *      2                2
 *     /                  \
 *    3                    3
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. If both nodes are nullptr, they are mirrors.
 * 2. If only one node is nullptr, they are not mirrors.
 * 3. If the node values differ, they are not mirrors.
 * 4. Recursively compare:
 *    - Left subtree of the first tree with the right subtree of the second.
 *    - Right subtree of the first tree with the left subtree of the second.
 * 5. Return true only if both recursive comparisons succeed.
 *
 * @param p Pointer to the root of the first subtree.
 * @param q Pointer to the root of the second subtree.
 * @return bool True if the subtrees are mirror images, otherwise false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes
 * - h = height of the tree
 */
bool isMirror(Node *p, Node *q) {
    if (!p && !q)
        return true;

    if (!p || !q)
        return false;

    if (p->val != q->val)
        return false;

    return isMirror(p->left, q->right) &&
           isMirror(p->right, q->left);
}

/**
 * @brief Determines whether a binary tree is symmetric.
 *
 * A binary tree is symmetric if its left and right subtrees are mirror
 * images of each other.
 *
 * Example:
 *         1
 *        / \
 *       2   2
 *      / \ / \
 *     3  4 4  3
 *
 * Returns:
 * true
 *
 * Example:
 *         1
 *        / \
 *       2   2
 *        \   \
 *         3   3
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. Compare the left and right subtrees of the root.
 * 2. Recursively verify that they are mirror images.
 *
 * Note:
 * - An empty tree is considered symmetric.
 *
 * @param root Pointer to the root of the binary tree.
 * @return bool True if the tree is symmetric, otherwise false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
bool isSymmetrical(Node *root) {
    if (!root)
        return true;

    return isMirror(root->left, root->right);
}