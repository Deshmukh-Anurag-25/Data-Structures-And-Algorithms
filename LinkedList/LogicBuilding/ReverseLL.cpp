#include"ListNode.h"
using namespace std;

/**
 * @brief Reverses a singly linked list.
 *
 * Iteratively reverses the links of a singly linked list and returns the
 * new head of the reversed list.
 *
 * Three pointers are used during the reversal:
 * - prev  : Points to the previous node.
 * - curr  : Points to the current node being processed.
 * - front : Temporarily stores the next node before the link is reversed.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4 -> 5
 *
 * Returns:
 * 5 -> 4 -> 3 -> 2 -> 1
 *
 * Example:
 * head = 1
 *
 * Returns:
 * 1
 *
 * Example:
 * head = nullptr
 *
 * Returns:
 * nullptr
 *
 * Algorithm:
 * 1. Initialize three pointers:
 *    - prev as nullptr.
 *    - curr as the head.
 *    - front to store the next node.
 * 2. Traverse the list while curr is not nullptr.
 * 3. Save the next node in front.
 * 4. Reverse the current node's next pointer.
 * 5. Move prev and curr one step forward.
 * 6. After the traversal, prev becomes the new head.
 *
 * Note:
 * - The reversal is performed in-place.
 * - No new nodes are allocated.
 *
 * @param head Pointer to the head of the linked list.
 * @return Node* Pointer to the head of the reversed linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* reverseList(Node* head) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* front = nullptr;

    while (curr) {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}