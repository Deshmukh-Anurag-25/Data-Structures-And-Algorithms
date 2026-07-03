#include "ListNode.h"
using namespace std;

/**
 * @brief Finds the length of the cycle in a singly linked list.
 *
 * Uses Floyd's Cycle Detection Algorithm (Tortoise and Hare) to determine
 * whether a cycle exists. If a cycle is detected, the function traverses
 * the cycle once to count the number of nodes it contains.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4 -> 5
 *              ^              |
 *              |______________|
 *
 * Returns:
 * 4
 *
 * Example:
 * head = 1 -> 2 -> 3 -> nullptr
 *
 * Returns:
 * 0
 *
 * Algorithm:
 * 1. Initialize slow and fast pointers at the head.
 * 2. Move:
 *    - slow one node at a time.
 *    - fast two nodes at a time.
 * 3. If the pointers never meet, no cycle exists.
 * 4. If they meet:
 *    - Keep one pointer fixed.
 *    - Move the other pointer around the cycle until it reaches the fixed
 *      pointer again, counting the number of nodes visited.
 * 5. Return the cycle length.
 *
 * Note:
 * - The linked list is not modified.
 * - Returns 0 if the linked list does not contain a cycle.
 *
 * @param head Pointer to the head of the linked list.
 * @return int The number of nodes in the cycle, or 0 if no cycle exists.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int findLengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int len = 1;
            slow = fast->next;

            while (fast != slow) {
                slow = slow->next;
                len++;
            }

            return len;
        }
    }

    return 0;
}