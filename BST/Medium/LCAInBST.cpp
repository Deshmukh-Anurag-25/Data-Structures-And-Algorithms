#include "Node.h"
using namespace std;

/**
 * @brief Finds the Lowest Common Ancestor (LCA) of two nodes in a
 * Binary Search Tree (BST).
 *
 * In a BST:
 * - All values in the left subtree are smaller than the current node.
 * - All values in the right subtree are greater than the current node.
 *
 * Using this property, the function determines whether both target nodes
 * lie in the left subtree, the right subtree, or on opposite sides of the
 * current node.
 *
 * Example:
 *              6
 *            /   \
 *           2     8
 *          / \   / \
 *         0   4 7   9
 *            / \
 *           3   5
 *
 * p = 2, q = 8
 * LCA = 6
 *
 * Example:
 * p = 2, q = 4
 * LCA = 2
 *
 * Algorithm:
 * 1. Start from the root.
 * 2. If both target values are smaller than the current node,
 *    search the left subtree.
 * 3. If both target values are greater than the current node,
 *    search the right subtree.
 * 4. Otherwise, the current node is the Lowest Common Ancestor.
 *
 * Note:
 * - The function assumes both nodes exist in the BST.
 * - A node can be the ancestor of itself.
 *
 * @param root Pointer to the root of the Binary Search Tree.
 * @param p Pointer to the first node.
 * @param q Pointer to the second node.
 * @return Node* Pointer to the Lowest Common Ancestor.
 *
 * Time Complexity: O(h)
 * Space Complexity: O(h)
 * where:
 * - h = height of the Binary Search Tree.
 */
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (!root)
        return nullptr;

    int curr = root->val;

    if (curr > p->val && curr > q->val)
        return lowestCommonAncestor(root->left, p, q);

    if (curr < p->val && curr < q->val)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}