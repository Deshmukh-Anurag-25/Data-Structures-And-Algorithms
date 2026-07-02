#include "ListNode.h"
using namespace std;

/**
 * @brief Adds two non-negative integers represented as linked lists.
 *
 * Each linked list stores a non-negative integer in reverse order, where
 * each node contains a single digit. The function returns a new linked
 * list representing the sum of the two integers, also in reverse order.
 *
 * A dummy node is used to simplify the construction of the resulting
 * linked list, while a carry variable handles overflow during addition.
 *
 * Example:
 * linkedList1 = 2 -> 4 -> 3
 * linkedList2 = 5 -> 6 -> 4
 *
 * Represents:
 * 342 + 465 = 807
 *
 * Returns:
 * 7 -> 0 -> 8
 *
 * Example:
 * linkedList1 = 9 -> 9
 * linkedList2 = 1
 *
 * Represents:
 * 99 + 1 = 100
 *
 * Returns:
 * 0 -> 0 -> 1
 *
 * Algorithm:
 * 1. Create a dummy node to simplify result construction.
 * 2. Traverse both linked lists simultaneously.
 * 3. At each step:
 *    - Read the current digits (or 0 if a list has ended).
 *    - Compute the sum along with the carry.
 *    - Create a node containing the resulting digit.
 *    - Update the carry.
 * 4. Continue until both lists are exhausted and no carry remains.
 * 5. Return the node following the dummy node.
 *
 * Note:
 * - The input linked lists are not modified.
 * - Digits are stored in reverse order.
 * - The linked lists may have different lengths.
 * - A new linked list is allocated to store the result.
 *
 * @param linkedList1 Reference to the head of the first linked list.
 * @param linkedList2 Reference to the head of the second linked list.
 * @return Node* The head of the linked list representing the sum.
 *
 * Time Complexity: O(max(n, m))
 * Space Complexity: O(max(n, m))
 */
Node* addTwoNumbers(Node* &linkedList1, Node* &linkedList2) {
    Node* dummy = new Node(-1);
    Node* mover = dummy;
    int carry = 0;

    Node* temp1 = linkedList1;
    Node* temp2 = linkedList2;

    while (temp1 || temp2 || carry) {
        int data1 = (temp1) ? temp1->val : 0;
        int data2 = (temp2) ? temp2->val : 0;

        int sum = data1 + data2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        mover->next = new Node(digit);
        mover = mover->next;

        if (temp1)
            temp1 = temp1->next;

        if (temp2)
            temp2 = temp2->next;
    }

    return dummy->next;
}