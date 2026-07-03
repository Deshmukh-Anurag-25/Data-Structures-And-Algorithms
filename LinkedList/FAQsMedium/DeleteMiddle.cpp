#include "ListNode.h"
using namespace std;

/**
 * @brief Deletes the middle node of a singly linked list.
 *
 * Uses the two-pointer (Tortoise and Hare) technique to locate the middle
 * node in a single traversal. A third pointer tracks the node immediately
 * preceding the middle node, allowing the middle node to be removed by
 * updating a single link.
 *
 * If the linked list contains an even number of nodes, the second of the
 * two middle nodes is removed.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4 -> 5
 *
 * Returns:
 * 1 -> 2 -> 4 -> 5
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4
 *
 * Returns:
 * 1 -> 2 -> 4
 *
 * Example:
 * head = 1
 *
 * Returns:
 * nullptr
 *
 * Algorithm:
 * 1. Handle the empty list and single-node list as special cases.
 * 2. Initialize slow, fast, and prev pointers.
 * 3. Move:
 *    - slow one node at a time.
 *    - fast two nodes at a time.
 *    - prev follows immediately behind slow.
 * 4. When fast reaches the end, slow points to the middle node.
 * 5. Remove the middle node by linking prev directly to slow->next.
 * 6. Return the head of the modified list.
 *
 * Note:
 * - The linked list is modified in-place.
 * - If the list has an even number of nodes, the second middle node is
 *   deleted.
 * - This implementation does not deallocate the removed node. If dynamic
 *   memory management is required, delete the removed node before
 *   returning.
 *
 * @param head Pointer to the head of the linked list.
 * @return Node* Pointer to the head of the modified linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* deleteMiddle(Node* head) {
    if (!head || !head->next)
        return nullptr;

    Node* slow = head;
    Node* prev = nullptr;
    Node* fast = head;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;

    return head;
}