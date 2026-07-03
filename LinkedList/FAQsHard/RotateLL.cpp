#include "ListNode.h"
using namespace std;

/**
 * @brief Rotates a singly linked list to the right by k positions.
 *
 * Moves the last k nodes of the linked list to the front while preserving
 * their relative order. If k is greater than the length of the list, the
 * effective number of rotations is computed using k modulo the list length.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4 -> 5
 * k = 2
 *
 * Returns:
 * 4 -> 5 -> 1 -> 2 -> 3
 *
 * Example:
 * head = 0 -> 1 -> 2
 * k = 4
 *
 * Since 4 % 3 = 1,
 *
 * Returns:
 * 2 -> 0 -> 1
 *
 * Algorithm:
 * 1. Handle empty and single-node lists.
 * 2. Traverse the list once to determine its length and locate the last node.
 * 3. Compute the effective rotation:
 *      k = k % length
 * 4. If k is 0, return the original list.
 * 5. Move the fast pointer k nodes ahead of the slow pointer.
 * 6. Advance both pointers until the fast pointer reaches the end.
 * 7. The slow pointer now points to the new head, while the previous node
 *    becomes the new tail.
 * 8. Connect the original tail to the original head to form a circular list.
 * 9. Break the circle after the new tail.
 * 10. Return the new head.
 *
 * Note:
 * - The linked list is modified in-place.
 * - No new nodes are allocated.
 * - If k is a multiple of the list length, the original list is returned.
 *
 * @param head Pointer to the head of the linked list.
 * @param k The number of positions to rotate the list to the right.
 * @return Node* Pointer to the head of the rotated linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* rotateRight(Node* head, int k) {
    if (!head || !head->next)
        return head;

    int len = 1;
    Node* temp = head;

    while (temp->next) {
        len++;
        temp = temp->next;
    }

    k %= len;

    if (k == 0)
        return head;

    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }

    Node* prev = nullptr;

    while (fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    Node* newHead = slow;

    temp->next = head;
    prev->next = nullptr;

    return newHead;
}