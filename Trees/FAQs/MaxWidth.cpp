#include "Node.h"
#include <algorithm>
#include <queue>
using namespace std;

/**
 * @brief Computes the maximum width of a binary tree.
 *
 * The width of a level is defined as the number of positions between the
 * leftmost and rightmost non-null nodes at that level in the complete binary
 * tree representation, including any null positions in between.
 *
 * Each node is assigned an index as if the tree were stored in an array:
 * - Root: index 0
 * - Left child: 2 * index + 1
 * - Right child: 2 * index + 2
 *
 * To prevent integer overflow for deep trees, the indices at each level are
 * normalized by subtracting the index of the first node in that level.
 *
 * Example:
 *              1
 *            /   \
 *           3     2
 *          / \     \
 *         5   3     9
 *
 * Maximum Width = 4
 *
 * Algorithm:
 * 1. Perform a level-order traversal using a queue.
 * 2. Store each node along with its virtual index.
 * 3. Normalize indices at each level by subtracting the minimum index.
 * 4. Record the first and last indices of the current level.
 * 5. Compute the width as (last - first + 1).
 * 6. Return the maximum width among all levels.
 *
 * Note:
 * - Normalizing indices avoids overflow without affecting the width.
 * - The algorithm works even for sparse binary trees.
 *
 * @param root Pointer to the root of the binary tree.
 * @return long long Maximum width of the binary tree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of nodes in the tree.
 */
long long widthOfBinaryTree(Node* root) {
    if (!root)
        return 0;

    queue<pair<Node*, long long>> q;
    q.push({root, 0});

    long long ans = 0;

    while (!q.empty()) {
        int n = q.size();

        long long minIndex = q.front().second;
        long long first = 0, last = 0;

        for (int i = 0; i < n; i++) {
            long long curr = q.front().second - minIndex;
            Node* node = q.front().first;
            q.pop();

            if (i == 0)
                first = curr;

            if (i == n - 1)
                last = curr;

            if (node->left)
                q.push({node->left, 2 * curr + 1});

            if (node->right)
                q.push({node->right, 2 * curr + 2});
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
}