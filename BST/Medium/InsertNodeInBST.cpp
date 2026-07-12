#include "Node.h"
using namespace std;

/**
 * @brief Inserts a new node into a Binary Search Tree (BST).
 *
 * A Binary Search Tree satisfies the following property:
 * - All values in the left subtree are smaller than the current node.
 * - All values in the right subtree are greater than or equal to the
 *   current node.
 *
 * The function iteratively traverses the tree to locate the appropriate
 * insertion position and then attaches the new node as a leaf.
 *
 * Example:
 * Before Insertion:
 *
 *          5
 *        /   \
 *       3     7
 *      / \     \
 *     2   4     8
 *
 * Insert = 6
 *
 * After Insertion:
 *
 *          5
 *        /   \
 *       3     7
 *      / \   / \
 *     2   4 6   8
 *
 * Algorithm:
 * 1. Create a new node containing the given value.
 * 2. If the tree is empty, return the new node as the root.
 * 3. Traverse the tree while keeping track of the parent node.
 * 4. Move left if the value is smaller; otherwise move right.
 * 5. Attach the new node as the appropriate child of the parent.
 * 6. Return the original root.
 *
 * Note:
 * - The tree remains a valid Binary Search Tree after insertion.
 * - Duplicate values are inserted into the left subtree in this implementation.
 *
 * @param root Pointer to the root of the Binary Search Tree.
 * @param x Value to be inserted.
 * @return Node* Pointer to the root of the updated Binary Search Tree.
 *
 * Time Complexity: O(h)
 * Space Complexity: O(1)
 * where:
 * - h = height of the Binary Search Tree.
 */
Node* insertNode(Node* root, int x) {
    Node* newNode = new Node(x);

    if (!root)
        return newNode;

    Node* curr = root;
    Node* prev = nullptr;

    while (curr) {
        prev = curr;

        if (curr->val < x)
            curr = curr->right;
        else
            curr = curr->left;
    }

    if (prev->val < x)
        prev->right = newNode;
    else
        prev->left = newNode;

    return root;
}