#include "ListNode.h"
using namespace std;

/**
 * @brief Finds the middle node of a singly linked list.
 *
 * Uses the two-pointer (Tortoise and Hare) technique to locate the middle
 * node in a single traversal. The slow pointer advances one node at a time,
 * while the fast pointer advances two nodes at a time.
 *
 * When the fast pointer reaches the end of the list, the slow pointer will
 * be positioned at the middle node.
 *
 * If the list contains an even number of nodes, the function returns the
 * second of the two middle nodes.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4 -> 5
 *
 * Returns:
 * 3
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4 -> 5 -> 6
 *
 * Returns:
 * 4
 *
 * Algorithm:
 * 1. Initialize two pointers, slow and fast, at the head.
 * 2. Move:
 *    - slow one node at a time.
 *    - fast two nodes at a time.
 * 3. Continue until fast reaches the end of the list.
 * 4. Return the node pointed to by slow.
 *
 * Note:
 * - If the list has an odd number of nodes, the exact middle is returned.
 * - If the list has an even number of nodes, the second middle node is
 *   returned.
 * - The linked list is not modified.
 *
 * @param head Pointer to the head of the linked list.
 * @return Node* Pointer to the middle node of the linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* middleOfLinkedList(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}