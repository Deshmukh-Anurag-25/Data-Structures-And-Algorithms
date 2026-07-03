#include "ListNode.h"
using namespace std;

/**
 * @brief Detects whether a singly linked list contains a cycle.
 *
 * Uses Floyd's Cycle Detection Algorithm (also known as the Tortoise and
 * Hare algorithm) to determine whether a linked list contains a loop.
 *
 * Two pointers traverse the list:
 * - slow moves one node at a time.
 * - fast moves two nodes at a time.
 *
 * If the linked list contains a cycle, the two pointers will eventually
 * meet. Otherwise, the fast pointer will reach the end of the list.
 *
 * Example:
 * head = 3 -> 2 -> 0 -> -4
 *              ^         |
 *              |_________|
 *
 * Returns:
 * true
 *
 * Example:
 * head = 1 -> 2 -> 3 -> nullptr
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. Initialize both slow and fast pointers at the head.
 * 2. Move:
 *    - slow one node at a time.
 *    - fast two nodes at a time.
 * 3. If the pointers ever meet, a cycle exists.
 * 4. If the fast pointer reaches nullptr (or its next is nullptr), no
 *    cycle exists.
 *
 * Note:
 * - The linked list is not modified.
 * - The algorithm works regardless of where the cycle begins.
 *
 * @param head Pointer to the head of the linked list.
 * @return bool True if the linked list contains a cycle; otherwise, false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}