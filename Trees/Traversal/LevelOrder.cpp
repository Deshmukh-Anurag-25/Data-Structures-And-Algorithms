#include "Node.h"
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief Performs a level order traversal (Breadth-First Search) of a binary tree.
 *
 * Visits the nodes level by level, starting from the root. All nodes at the
 * same depth are grouped together in a separate vector.
 *
 * The traversal uses a queue to process nodes in First-In-First-Out (FIFO)
 * order, ensuring that each level is completely processed before moving to
 * the next.
 *
 * Example:
 *         1
 *        / \
 *       2   3
 *      / \   \
 *     4   5   6
 *
 * Returns:
 * {
 *   {1},
 *   {2, 3},
 *   {4, 5, 6}
 * }
 *
 * Algorithm:
 * 1. If the tree is empty, return an empty vector.
 * 2. Push the root node into a queue.
 * 3. While the queue is not empty:
 *    - Determine the number of nodes in the current level.
 *    - Remove each node from the queue.
 *    - Store its value in the current level.
 *    - Push its left and right children (if they exist).
 * 4. Append the completed level to the result.
 * 5. Repeat until all levels have been processed.
 *
 * Note:
 * - Also known as Breadth-First Search (BFS).
 * - Nodes belonging to the same depth appear together in the returned
 *   vector.
 * - If the tree is empty, an empty vector is returned.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<vector<int>> A vector where each inner vector contains the
 *         node values of one level of the tree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<vector<int>> levelorder(Node *root) {
    if (!root)
        return {};

    vector<vector<int>> ans;
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        vector<int> level;

        for (int i = 0; i < n; i++) {
            Node *front = q.front();
            q.pop();

            level.push_back(front->val);

            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);
        }

        ans.push_back(level);
    }

    return ans;
}