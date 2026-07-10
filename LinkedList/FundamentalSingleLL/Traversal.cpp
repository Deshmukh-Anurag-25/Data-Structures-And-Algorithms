#include "ListNode.h"
#include <vector>
using namespace std;

/**
 * @brief Traverses a singly linked list and returns its elements.
 *
 * Starting from the head node, the function visits each node exactly once
 * and stores its value in a vector. The traversal continues until the end
 * of the linked list is reached.
 *
 * Example:
 * Linked List:
 * 1 -> 2 -> 3 -> 4 -> nullptr
 *
 * Returns:
 * {1, 2, 3, 4}
 *
 * Example:
 * Linked List:
 * nullptr
 *
 * Returns:
 * {}
 *
 * Algorithm:
 * 1. If the linked list is empty, return an empty vector.
 * 2. Initialize a temporary pointer at the head.
 * 3. Traverse the linked list until the pointer becomes nullptr.
 * 4. Append each node's value to the result vector.
 * 5. Return the populated vector.
 *
 * Note:
 * - The linked list is not modified.
 * - The values are returned in the same order as they appear in the list.
 *
 * @param head Pointer to the head of the singly linked list.
 * @return vector<int> A vector containing all node values in traversal order.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of nodes in the linked list.
 */
vector<int> traversal(Node* head) {
    if (!head)
        return {};

    vector<int> ans;
    Node* temp = head;

    while (temp) {
        ans.push_back(temp->val);
        temp = temp->next;
    }

    return ans;
}