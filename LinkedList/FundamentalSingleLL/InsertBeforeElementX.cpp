#include "ListNode.h"
using namespace std;

/**
 * @brief Inserts a new node before the first occurrence of a given value.
 *
 * The function inserts a new node containing the specified value before
 * the first node whose value equals the target.
 *
 * Example:
 * Linked List:
 * 1 -> 2 -> 4 -> 5 -> nullptr
 *
 * insertValue = 3
 * target = 4
 *
 * Returns:
 * 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
 *
 * Algorithm:
 * 1. If the list is empty, return nullptr.
 * 2. If the head contains the target value, insert at the head.
 * 3. Traverse the list while examining the next node.
 * 4. When the next node contains the target value:
 *    - Insert the new node before it.
 * 5. Return the updated head.
 *
 * Note:
 * - Only the first occurrence of the target value is considered.
 * - If the target does not exist, the list remains unchanged.
 *
 * @param head Pointer to the head of the linked list.
 * @param insertValue Value to insert.
 * @param target Value before which insertion is performed.
 * @return Node* Pointer to the updated head.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* insertBeforeValue(Node* head, int insertValue, int target) {
    if (!head)
        return nullptr;

    if (head->val == target) {
        Node* newNode = new Node(insertValue);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;

    while (temp->next) {
        if (temp->next->val == target) {
            Node* newNode = new Node(insertValue);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }

    return head;
}