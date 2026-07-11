#include "Node.h"
#include <vector>
using namespace std;

/**
 * @brief Finds the floor and ceil of a given key in a Binary Search Tree (BST).
 *
 * The floor of a key is the greatest value in the BST that is less than or
 * equal to the key. The ceil of a key is the smallest value in the BST that
 * is greater than or equal to the key.
 *
 * The function leverages the BST property to determine both values in a
 * single traversal. At each node:
 * - If the current value equals the key, both floor and ceil are the key.
 * - If the current value is smaller than the key, it is a candidate for
 *   the floor, and the search continues in the right subtree.
 * - If the current value is greater than the key, it is a candidate for
 *   the ceil, and the search continues in the left subtree.
 *
 * Example:
 *            8
 *          /   \
 *         4     12
 *        / \    / \
 *       2   6  10 14
 *
 * Key = 5
 *
 * Floor = 4
 * Ceil  = 6
 *
 * Example:
 * Key = 12
 *
 * Floor = 12
 * Ceil  = 12
 *
 * Example:
 * Key = 15
 *
 * Floor = 14
 * Ceil  = -1
 *
 * Algorithm:
 * 1. Initialize floor and ceil to -1.
 * 2. Traverse the BST from the root.
 * 3. If the current node's value equals the key:
 *    - Set both floor and ceil to the current value.
 *    - Stop the traversal.
 * 4. If the current value is smaller than the key:
 *    - Update the floor.
 *    - Move to the right subtree.
 * 5. Otherwise:
 *    - Update the ceil.
 *    - Move to the left subtree.
 * 6. Return the floor and ceil.
 *
 * Note:
 * - If no floor exists, -1 is returned.
 * - If no ceil exists, -1 is returned.
 * - The BST property allows the search to discard one subtree at each step.
 *
 * @param root Pointer to the root of the Binary Search Tree.
 * @param key The value whose floor and ceil are to be found.
 * @return vector<int> A vector containing {floor, ceil}.
 *
 * Time Complexity: O(h)
 * Space Complexity: O(1)
 * where:
 * - h = height of the Binary Search Tree.
 */
vector<int> floorCeilOfBST(Node* root, int key) {
    int floor = -1;
    int ceil = -1;

    while (root) {
        if (root->val == key) {
            floor = ceil = root->val;
            break;
        }

        if (root->val < key) {
            floor = root->val;
            root = root->right;
        } else {
            ceil = root->val;
            root = root->left;
        }
    }

    return {floor, ceil};
}