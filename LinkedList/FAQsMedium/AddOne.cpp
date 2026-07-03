#include "ListNode.h"
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
 * head = 1 -> 2 -> 3 -> 4
 *
 * Returns:
 * 4 -> 3 -> 2 -> 1
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
Node* reverseLL(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* front = head;

    while (curr) {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

/**
 * @brief Adds one to a non-negative integer represented as a linked list.
 *
 * Each node of the linked list stores a single digit of the integer, with
 * the most significant digit at the head of the list.
 *
 * The algorithm reverses the list to simplify addition from the least
 * significant digit, performs the addition while propagating any carry,
 * appends a new node if a final carry remains, and finally restores the
 * original digit order.
 *
 * Example:
 * head = 1 -> 2 -> 3
 *
 * Represents:
 * 123
 *
 * Returns:
 * 1 -> 2 -> 4
 *
 * Example:
 * head = 9 -> 9 -> 9
 *
 * Represents:
 * 999
 *
 * Returns:
 * 1 -> 0 -> 0 -> 0
 *
 * Algorithm:
 * 1. Reverse the linked list.
 * 2. Initialize the carry as 1.
 * 3. Traverse the reversed list:
 *    - Add the carry to the current digit.
 *    - Update the digit.
 *    - Propagate the carry.
 * 4. If a carry remains after the traversal, append a new node.
 * 5. Reverse the list again to restore the original order.
 * 6. Return the new head.
 *
 * Note:
 * - The linked list is modified in-place.
 * - A new node is allocated only if the most significant digit overflows.
 *
 * @param head Pointer to the head of the linked list.
 * @return Node* Pointer to the head of the updated linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* addOne(Node* head) {
    Node* reverseHead = reverseLL(head);
    Node* temp = reverseHead;
    Node* prev = nullptr;
    int carry = 1;

    while (temp) {
        int sum = temp->val + carry;
        carry = sum / 10;
        temp->val = sum % 10;

        prev = temp;
        temp = temp->next;
    }

    if (carry) {
        prev->next = new Node(1);
    }

    return reverseLL(reverseHead);
}