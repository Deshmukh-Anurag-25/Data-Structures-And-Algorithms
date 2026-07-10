#include "ListNode.h"
using namespace std;

/**
 * @brief Deletes the tail node of a singly linked list.
 *
 * The function removes the last node of the linked list, deallocates its
 * memory, and returns the head of the updated list.
 *
 * Example:
 * Linked List:
 * 1 -> 2 -> 3 -> 4 -> nullptr
 *
 * Returns:
 * 1 -> 2 -> 3 -> nullptr
 *
 * Example:
 * Linked List:
 * 5 -> nullptr
 *
 * Returns:
 * nullptr
 *
 * Algorithm:
 * 1. If the linked list is empty or contains only one node, return nullptr.
 * 2. Traverse the list while maintaining pointers to the current node and
 *    its previous node.
 * 3. Stop when the current node reaches the tail.
 * 4. Disconnect the tail by setting the previous node's next pointer to
 *    nullptr.
 * 5. Delete the tail node.
 * 6. Return the original head.
 *
 * Note:
 * - The memory occupied by the tail node is released.
 * - If the list has only one node, the resulting list is empty.
 *
 * @param head Pointer to the head of the singly linked list.
 * @return Node* Pointer to the head of the updated linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of nodes in the linked list.
 */
Node* deleteTail(Node* head) {
    if (!head)
        return nullptr;

    if (!head->next) {
        delete head;
        return nullptr;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = nullptr;
    delete curr;

    return head;
}