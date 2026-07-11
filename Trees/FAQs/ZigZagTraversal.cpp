#include "Node.h"
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief Performs the zigzag (spiral) level order traversal of a binary tree.
 *
 * In a zigzag traversal, the direction of traversal alternates at each level:
 * - The first level is traversed from left to right.
 * - The second level is traversed from right to left.
 * - The third level is traversed from left to right.
 * - And so on.
 *
 * Example:
 *              1
 *            /   \
 *           2     3
 *          / \   / \
 *         4   5 6   7
 *
 * Zigzag Traversal:
 * {
 *   {1},
 *   {3, 2},
 *   {4, 5, 6, 7}
 * }
 *
 * Algorithm:
 * 1. Perform a level-order traversal using a queue.
 * 2. For each level:
 *    - Create a vector of size equal to the number of nodes at that level.
 *    - If traversing left-to-right, place each node at index i.
 *    - Otherwise, place each node at index (n - 1 - i).
 * 3. Toggle the traversal direction after every level.
 * 4. Store each level in the result.
 *
 * Note:
 * - A queue is used to process nodes level by level.
 * - The insertion index is adjusted to avoid reversing the level vector.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<vector<int>> The zigzag level order traversal of the tree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of nodes in the tree.
 */
vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> ans;

    if (!root)
        return ans;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);

        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();

            int idx = leftToRight ? i : n - 1 - i;
            level[idx] = node->val;

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        ans.push_back(level);
        leftToRight = !leftToRight;
    }

    return ans;
}