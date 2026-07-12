#include "Node.h"
using namespace std;

/**
 * @brief Finds the rightmost node in a subtree.
 *
 * The rightmost node is the node with the maximum value in a Binary Search
 * Tree (BST) subtree. It is used while deleting a node that has two children,
 * so that the right subtree can be attached to the inorder predecessor.
 *
 * @param root Pointer to the root of the subtree.
 * @return Node* Pointer to the rightmost node.
 *
 * Time Complexity: O(h)
 * Space Complexity: O(h)
 * where:
 * - h = height of the subtree.
 */
Node* findLastRight(Node* root) {
    if (!root->right)
        return root;

    return findLastRight(root->right);
}

/**
 * @brief Rearranges the BST after deleting a node.
 *
 * This helper function handles the three possible deletion cases:
 * - Node has no left child.
 * - Node has no right child.
 * - Node has two children.
 *
 * For the third case, the right subtree is attached to the rightmost node
 * of the left subtree, and the left child becomes the new subtree root.
 *
 * @param root Pointer to the node being deleted.
 * @return Node* Pointer to the root of the updated subtree.
 *
 * Time Complexity: O(h)
 * Space Complexity: O(h)
 */
Node* helper(Node* root) {
    if (!root->left)
        return root->right;

    if (!root->right)
        return root->left;

    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);

    lastRight->right = rightChild;

    return root->left;
}

/**
 * @brief Deletes a node with the specified key from a Binary Search Tree.
 *
 * The function searches for the node containing the given key and removes it
 * while preserving the Binary Search Tree property.
 *
 * Cases handled:
 * - Leaf node.
 * - Node with one child.
 * - Node with two children.
 *
 * Example:
 *            5
 *          /   \
 *         3     6
 *        / \     \
 *       2   4     7
 *
 * Delete key = 3
 *
 * Result:
 *            5
 *          /   \
 *         2     6
 *          \     \
 *           4     7
 *
 * Algorithm:
 * 1. If the root itself contains the key, delete it using the helper.
 * 2. Otherwise, iteratively search for the parent of the target node.
 * 3. Replace the appropriate child with the updated subtree returned by
 *    the helper function.
 * 4. Return the original root.
 *
 * Note:
 * - If the key does not exist, the original tree is returned unchanged.
 * - The BST property is preserved after deletion.
 *
 * @param root Pointer to the root of the BST.
 * @param key Value to be deleted.
 * @return Node* Pointer to the root of the updated BST.
 *
 * Time Complexity: O(h)
 * Space Complexity: O(h)
 * where:
 * - h = height of the Binary Search Tree.
 */
Node* deleteNode(Node* root, int key) {
    if (!root)
        return nullptr;

    if (root->val == key)
        return helper(root);

    Node* originalRoot = root;

    while (root) {
        if (root->val > key) {
            if (root->left && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }

    return originalRoot;
}