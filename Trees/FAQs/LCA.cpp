#include "Node.h"
using namespace std;

/**
 * @brief Finds the Lowest Common Ancestor (LCA) of two nodes in a binary tree.
 *
 * The Lowest Common Ancestor of two nodes p and q is the lowest node in the
 * tree that has both p and q as descendants (where a node can be a descendant
 * of itself).
 *
 * Unlike a Binary Search Tree, this algorithm works for a general binary tree
 * by recursively searching both the left and right subtrees.
 *
 * Example:
 *               3
 *             /   \
 *            5     1
 *           / \   / \
 *          6   2 0   8
 *             / \
 *            7   4
 *
 * p = 5, q = 1
 * LCA = 3
 *
 * Example:
 * p = 5, q = 4
 * LCA = 5
 *
 * Algorithm:
 * 1. If the current node is nullptr, return nullptr.
 * 2. If the current node is either p or q, return the current node.
 * 3. Recursively search the left and right subtrees.
 * 4. If both recursive calls return non-null pointers, the current node is
 *    the Lowest Common Ancestor.
 * 5. Otherwise, return the non-null result from either subtree.
 *
 * Note:
 * - The function assumes both nodes exist in the tree.
 * - A node can be the ancestor of itself.
 *
 * @param root Pointer to the root of the binary tree.
 * @param p Pointer to the first node.
 * @param q Pointer to the second node.
 * @return Node* Pointer to the Lowest Common Ancestor of p and q.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes in the tree.
 * - h = height of the tree (recursion stack).
 */
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (!root || root == p || root == q)
        return root;

    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    if (!left)
        return right;

    if (!right)
        return left;

    return root;
}