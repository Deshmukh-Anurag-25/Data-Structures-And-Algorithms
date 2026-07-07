#include "Node.h"
#include <algorithm>
#include <climits>
using namespace std;

/**
 * @brief Stores the maximum path sum found during the DFS traversal.
 *
 * This global variable is updated whenever a path with a greater sum is
 * encountered. It should be initialized to INT_MIN before computing the
 * maximum path sum of a tree.
 */
int maxi = INT_MIN;

/**
 * @brief Computes the maximum path sum in a binary tree.
 *
 * A path is any sequence of connected nodes where each pair of adjacent
 * nodes is connected by an edge. The path:
 * - May start and end at any node.
 * - Must contain at least one node.
 * - Cannot revisit a node.
 *
 * During the DFS traversal:
 * - The function returns the maximum gain that can be extended upward to
 *   the parent.
 * - At each node, the maximum path passing through that node is computed
 *   using:
 *
 *      leftGain + rightGain + node->val
 *
 * where negative gains are ignored.
 *
 * Example:
 *         1
 *        / \
 *       2   3
 *
 * Maximum path:
 * 2 → 1 → 3
 *
 * Maximum path sum = 6
 *
 * Example:
 *        -10
 *        /  \
 *       9    20
 *           /  \
 *          15   7
 *
 * Maximum path:
 * 15 → 20 → 7
 *
 * Maximum path sum = 42
 *
 * Algorithm:
 * 1. Recursively compute the maximum gain from the left subtree.
 * 2. Recursively compute the maximum gain from the right subtree.
 * 3. Ignore negative gains by replacing them with 0.
 * 4. Update the global maximum using:
 *      leftGain + rightGain + currentNodeValue
 * 5. Return the maximum gain that can be extended to the parent:
 *      currentNodeValue + max(leftGain, rightGain)
 *
 * Note:
 * - This function returns the maximum extendable gain, not the overall
 *   maximum path sum.
 * - The final answer is stored in the global variable `maxi`.
 * - Before calling this function for a new tree, reset:
 *      maxi = INT_MIN;
 *
 * Example usage:
 * maxi = INT_MIN;
 * maxPathSum(root);
 * cout << maxi;
 *
 * @param root Pointer to the current node.
 * @return int Maximum gain that can be extended to the parent.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * where:
 * - n = number of nodes
 * - h = height of the tree
 */
int maxPathSum(Node *root) {
    if (!root)
        return 0;

    int ls = max(0, maxPathSum(root->left));
    int rs = max(0, maxPathSum(root->right));

    maxi = max(maxi, ls + rs + root->val);

    return root->val + max(ls, rs);
}