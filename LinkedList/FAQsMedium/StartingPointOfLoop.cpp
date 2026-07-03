#include "ListNode.h"
using namespace std;

/**
 * @brief Finds the starting node of a cycle in a singly linked list.
 *
 * Uses Floyd's Cycle Detection Algorithm (Tortoise and Hare) to first
 * determine whether a cycle exists. If a cycle is detected, one pointer
 * is reset to the head of the list while the other remains at the meeting
 * point inside the cycle. Both pointers then advance one node at a time.
 * The node at which they meet is the starting node of the cycle.
 *
 * Example:
 * head = 3 -> 2 -> 0 -> -4
 *              ^         |
 *              |_________|
 *
 * Returns:
 * Node containing value 2.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> nullptr
 *
 * Returns:
 * nullptr
 *
 * Algorithm:
 * 1. Initialize slow and fast pointers at the head.
 * 2. Move:
 *    - slow one node at a time.
 *    - fast two nodes at a time.
 * 3. If the pointers never meet, the list contains no cycle.
 * 4. If they meet:
 *    - Reset slow to the head.
 *    - Move both pointers one step at a time.
 * 5. The node where they meet again is the starting node of the cycle.
 *
 * Note:
 * - The linked list is not modified.
 * - If no cycle exists, the function returns nullptr.
 * - The algorithm relies on Floyd's mathematical property of cycle
 *   detection to locate the cycle's entry point.
 *
 * @param head Pointer to the head of the linked list.
 * @return Node* Pointer to the first node of the cycle, or nullptr if no
 *         cycle exists.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* findStartingPoint(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;

            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return nullptr;
}