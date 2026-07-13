#include "Node.h"
#include <unordered_set>
using namespace std;

/**
 * @brief Performs a depth-first traversal to determine whether a pair of
 * nodes sums to the given target.
 *
 * During traversal, each visited node value is stored in a hash set.
 * For every node, the function checks whether its complement
 * (target - current value) has already been encountered.
 *
 * @param root Pointer to the current node.
 * @param target The required sum.
 * @param seen Hash set containing values of previously visited nodes.
 * @return bool True if a valid pair exists; otherwise false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
bool dfs(Node* root, int target, unordered_set<int>& seen) {
    if (!root)
        return false;

    if (seen.find(target - root->val) != seen.end())
        return true;

    seen.insert(root->val);

    return dfs(root->left, target, seen) ||
           dfs(root->right, target, seen);
}

/**
 * @brief Determines whether a Binary Search Tree contains two nodes whose
 * values add up to a given target.
 *
 * The function traverses the tree while maintaining a hash set of values
 * that have already been visited. For each node, it checks whether the
 * complement required to form the target sum has been seen before.
 *
 * Example:
 *             5
 *           /   \
 *          3     6
 *         / \     \
 *        2   4     7
 *
 * Target = 9
 *
 * Pair:
 * 2 + 7 = 9
 *
 * Returns:
 * true
 *
 * Example:
 * Target = 28
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. Initialize an empty hash set.
 * 2. Perform a depth-first traversal of the tree.
 * 3. For each node:
 *    - Check whether (target - current value) exists in the set.
 *    - If it exists, return true.
 *    - Otherwise, insert the current value into the set.
 * 4. Continue recursively through the left and right subtrees.
 * 5. If no valid pair is found, return false.
 *
 * Note:
 * - Although the input is a BST, this solution does not explicitly use
 *   the BST property.
 * - The hash set allows constant-time average lookup for complements.
 *
 * @param root Pointer to the root of the Binary Search Tree.
 * @param target The required sum.
 * @return bool True if two nodes sum to the target; otherwise false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of nodes in the tree.
 */
bool twoSumBST(Node* root, int target) {
    unordered_set<int> seen;
    return dfs(root, target, seen);
}