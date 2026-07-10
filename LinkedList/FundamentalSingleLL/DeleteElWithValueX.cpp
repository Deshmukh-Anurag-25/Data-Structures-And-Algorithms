#include "ListNode.h"
using namespace std;

/**
 * @brief Deletes the first node containing a specified value from a
 * singly linked list.
 *
 * The function searches the linked list for the first occurrence of the
 * given value. If found, the node is removed from the list, its memory is
 * released, and the updated head is returned.
 *
 * Example:
 * Linked List:
 * 1 -> 2 -> 3 -> 2 -> 4 -> nullptr
 * x = 2
 *
 * Returns:
 * 1 -> 3 -> 2 -> 4 -> nullptr
 *
 * Example:
 * Linked List:
 * 5 -> 10 -> nullptr
 * x = 5
 *
 * Returns:
 * 10 -> nullptr
 *
 * Algorithm:
 * 1. If the linked list is empty, return nullptr.
 * 2. If the head node contains the target value:
 *    - Remove the head.
 *    - Return the new head.
 * 3. Traverse the linked list while maintaining pointers to the current
 *    node and its previous node.
 * 4. When the first node containing the target value is found:
 *    - Link the previous node to the next node.
 *    - Delete the current node.
 *    - Stop the traversal.
 * 5. Return the head of the updated linked list.
 *
 * Note:
 * - Only the first occurrence of the value is deleted.
 * - If the value does not exist, the original list is returned unchanged.
 *
 * @param head Pointer to the head of the singly linked list.
 * @param x The value to delete.
 * @return Node* Pointer to the head of the updated linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of nodes in the linked list.
 */
Node* deleteElement(Node* head, int x) {
    if (!head)
        return nullptr;

    if (head->val == x) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp) {
        if (temp->val == x) {
            prev->next = temp->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}