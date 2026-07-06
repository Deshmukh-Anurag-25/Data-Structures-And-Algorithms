#include "Node.h"
#include <stack>
#include <vector>
using namespace std;

/**
 * @brief Performs preorder, inorder, and postorder traversals of a binary
 * tree using a single iterative traversal.
 *
 * Each node is associated with a state:
 * - State 1: Process for preorder, then visit the left subtree.
 * - State 2: Process for inorder, then visit the right subtree.
 * - State 3: Process for postorder.
 *
 * By revisiting each node with different states, all three traversals are
 * obtained in a single pass through the tree.
 *
 * Example:
 *        1
 *       / \
 *      2   3
 *     / \
 *    4   5
 *
 * Preorder:
 * {1, 2, 4, 5, 3}
 *
 * Inorder:
 * {4, 2, 5, 1, 3}
 *
 * Postorder:
 * {4, 5, 2, 3, 1}
 *
 * Returns:
 * {
 *   {4, 2, 5, 1, 3},
 *   {1, 2, 4, 5, 3},
 *   {4, 5, 2, 3, 1}
 * }
 *
 * Algorithm:
 * 1. Push the root onto a stack with state 1.
 * 2. While the stack is not empty:
 *    - State 1:
 *        - Record the node for preorder.
 *        - Push the node back with state 2.
 *        - Push its left child.
 *    - State 2:
 *        - Record the node for inorder.
 *        - Push the node back with state 3.
 *        - Push its right child.
 *    - State 3:
 *        - Record the node for postorder.
 * 3. Return the three traversals.
 *
 * Note:
 * - Only one stack is used.
 * - Each node is pushed onto the stack at most three times.
 * - If the tree is empty, an empty vector is returned.
 *
 * @param root Pointer to the root of the binary tree.
 * @return vector<vector<int>> A vector containing:
 *         - ans[0] = inorder traversal
 *         - ans[1] = preorder traversal
 *         - ans[2] = postorder traversal
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<vector<int>> treeTraversal(Node *root) {
    if (!root)
        return {};

    stack<pair<Node *, int>> st;
    st.push({root, 1});

    vector<int> pre, in, post;
    vector<vector<int>> ans;

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->val);

            it.second++;
            st.push(it);

            if (it.first->left)
                st.push({it.first->left, 1});
        }

        else if (it.second == 2) {
            in.push_back(it.first->val);

            it.second++;
            st.push(it);

            if (it.first->right)
                st.push({it.first->right, 1});
        }

        else {
            post.push_back(it.first->val);
        }
    }

    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}