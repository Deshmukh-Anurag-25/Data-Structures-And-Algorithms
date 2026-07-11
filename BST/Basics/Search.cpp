#include "Node.h"
using namespace std;

/**
 * @brief Searches for a value in a Binary Search Tree (BST).
 *
 * A Binary Search Tree satisfies the following property:
 * - All values in the left subtree are smaller than the current node.
 * - All values in the right subtree are greater than the current node.
 *
 * The function iteratively traverses the tree by comparing the target value
 * with the current node's value. Depending on the comparison, it moves to
 * either the left or right subtree until the value is found or the search
 * reaches a nullptr.
 *
 * Example:
 *          8
 *        /   \
 *       3     10
 *      / \      \
 *     1   6      14
 *        / \     /
 *       4   7   13
 *
 * Search value = 6
 *
 * Returns:
 * Pointer to the node containing 6.
 *
 * Example:
 * Search value = 5
 *
 * Returns:
 * nullptr
 *
 * Algorithm:
 * 1. Start from the root node.
 * 2. While the current node is not nullptr:
 *    - If the current node's value equals the target, return the node.
 *    - If the target is greater than the current value, move to the right
 *      subtree.
 *    - Otherwise, move to the left subtree.
 * 3. If the traversal reaches nullptr, the value does not exist in the tree.
 *
 * Note:
 * - The BST property allows one subtree to be discarded at every step,
 *   making the search efficient.
 * - The function returns a pointer to the matching node, not just a boolean.
 *
 * @param root Pointer to the root of the Binary Search Tree.
 * @param val The value to search for.
 * @return Node* Pointer to the node containing the value if found;
 *         otherwise nullptr.
 *
 * Time Complexity: O(h)
 * Space Complexity: O(1)
 * where:
 * - h = height of the Binary Search Tree.
 */
Node* searchInBST(Node* root, int val) {
    while (root) {
        if (root->val == val)
            return root;
        else if (root->val < val)
            root = root->right;
        else
            root = root->left;
    }

    return nullptr;
}