#include "Node.h"
using namespace std;

/**
 * @brief Stores the value of the kth smallest element.
 */
int value = 0;

/**
 * @brief Performs an inorder traversal to find the kth smallest element.
 *
 * Since an inorder traversal of a Binary Search Tree (BST) visits nodes in
 * ascending order, the kth visited node corresponds to the kth smallest
 * element.
 *
 * @param root Pointer to the current node.
 * @param count Reference to the number of nodes visited so far.
 * @param k The position of the desired smallest element.
 *
 * Time Complexity: O(h + k) on average, O(n) in the worst case.
 * Space Complexity: O(h)
 * where:
 * - h = height of the Binary Search Tree.
 */
void dfs(Node* root, int& count, int k) {
    if (!root)
        return;

    dfs(root->left, count, k);

    if (count == k)
        return;

    value = root->val;
    count++;

    dfs(root->right, count, k);
}

/**
 * @brief Finds the kth smallest element in a Binary Search Tree (BST).
 *
 * A Binary Search Tree stores its elements such that an inorder traversal
 * visits the nodes in ascending order. By counting the visited nodes during
 * the traversal, the kth smallest element can be identified.
 *
 * Example:
 *            5
 *          /   \
 *         3     6
 *        / \
 *       2   4
 *      /
 *     1
 *
 * k = 3
 *
 * Inorder Traversal:
 * 1 -> 2 -> 3 -> 4 -> 5 -> 6
 *
 * Returns:
 * 3
 *
 * Algorithm:
 * 1. Perform an inorder traversal.
 * 2. Maintain a counter for the number of visited nodes.
 * 3. Update the answer while traversing.
 * 4. Stop once the kth node has been visited.
 *
 * Note:
 * - The BST property guarantees that inorder traversal visits nodes in
 *   sorted order.
 * - It is assumed that 1 ≤ k ≤ number of nodes in the BST.
 *
 * @param root Pointer to the root of the Binary Search Tree.
 * @param k The position (1-based) of the desired smallest element.
 * @return int The kth smallest value in the BST.
 *
 * Time Complexity: O(h + k) on average, O(n) in the worst case.
 * Space Complexity: O(h)
 * where:
 * - h = height of the Binary Search Tree.
 */
int kthSmallest(Node* root, int k) {
    value = 0;
    int count = 0;

    dfs(root, count, k);

    return value;
}