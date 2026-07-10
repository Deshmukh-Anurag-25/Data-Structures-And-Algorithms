#include "ListNode.h"
using namespace std;

/**
 * @brief Deletes the head node of a singly linked list.
 *
 * The function removes the first node of the linked list, deallocates its
 * memory, and returns the new head of the list.
 *
 * Example:
 * Linked List:
 * 1 -> 2 -> 3 -> nullptr
 *
 * Returns:
 * 2 -> 3 -> nullptr
 *
 * Example:
 * Linked List:
 * 5 -> nullptr
 *
 * Returns:
 * nullptr
 *
 * Algorithm:
 * 1. If the linked list is empty, return nullptr.
 * 2. Store the second node as the new head.
 * 3. Delete the original head node.
 * 4. Return the new head.
 *
 * Note:
 * - The memory occupied by the original head node is released.
 * - If the list contains only one node, the resulting list is empty.
 *
 * @param head Pointer to the head of the singly linked list.
 * @return Node* Pointer to the new head after deletion.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
Node* deleteHead(Node* head) {
    if (!head)
        return nullptr;

    Node* newHead = head->next;
    delete head;

    return newHead;
}