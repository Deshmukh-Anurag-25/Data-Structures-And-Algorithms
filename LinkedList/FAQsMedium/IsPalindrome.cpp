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

/**
 * @brief Finds the middle node of a singly linked list.
 *
 * Uses the two-pointer (Tortoise and Hare) technique to locate the middle
 * node in a single traversal. The slow pointer advances one node at a time,
 * while the fast pointer advances two nodes at a time.
 *
 * If the list contains an even number of nodes, the second middle node is
 * returned.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4 -> 5
 *
 * Returns:
 * 3
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4
 *
 * Returns:
 * 3
 *
 * @param head Pointer to the head of the linked list.
 * @return Node* Pointer to the middle node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/**
 * @brief Determines whether a singly linked list is a palindrome.
 *
 * A linked list is considered a palindrome if its sequence of values reads
 * the same forwards and backwards.
 *
 * The algorithm finds the middle of the list, reverses the second half,
 * and compares the first half with the reversed second half node by node.
 *
 * Example:
 * head = 1 -> 2 -> 2 -> 1
 *
 * Returns:
 * true
 *
 * Example:
 * head = 1 -> 2
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. Find the middle node of the linked list.
 * 2. Reverse the second half of the list.
 * 3. Compare corresponding nodes from the beginning and the reversed half.
 * 4. If all compared values match, the list is a palindrome.
 *
 * Note:
 * - The second half of the list is reversed in-place.
 * - This implementation does not restore the list to its original order.
 * - To preserve the original list, reverse the second half again before
 *   returning.
 *
 * @param head Pointer to the head of the linked list.
 * @return bool True if the linked list is a palindrome; otherwise, false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool isPalindrome(Node* head) {
    Node* temp2 = reverseLL(findMiddle(head));
    Node* temp1 = head;

    while (temp2) {
        if (temp1->val != temp2->val)
            return false;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
}