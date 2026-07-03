#include "ListNode.h"
using namespace std;

/**
 * @brief Merges two sorted singly linked lists into a single sorted list.
 *
 * Iteratively merges two linked lists sorted in non-decreasing order into
 * one sorted linked list by repeatedly selecting the smaller current node.
 * The existing nodes are relinked; no new data nodes are created.
 *
 * Example:
 * list1 = 1 -> 2 -> 4
 * list2 = 1 -> 3 -> 4
 *
 * Returns:
 * 1 -> 1 -> 2 -> 3 -> 4 -> 4
 *
 * Example:
 * list1 = nullptr
 * list2 = 0
 *
 * Returns:
 * 0
 *
 * Algorithm:
 * 1. Create a dummy node to simplify result construction.
 * 2. Compare the current nodes of both lists.
 * 3. Append the smaller node to the merged list.
 * 4. Advance the pointer of the selected list.
 * 5. Repeat until one list is exhausted.
 * 6. Append the remaining nodes of the non-empty list.
 * 7. Return the node following the dummy node.
 *
 * Note:
 * - Both input linked lists must already be sorted.
 * - Existing nodes are reused; no new data nodes are allocated.
 * - The relative order of equal elements from the same list is preserved.
 *
 * @param list1 Pointer to the head of the first sorted linked list.
 * @param list2 Pointer to the head of the second sorted linked list.
 * @return Node* Pointer to the head of the merged sorted linked list.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(1)
 */
Node* mergeTwoLists(Node* list1, Node* list2) {
    Node* dummy = new Node(0);
    Node* mover = dummy;

    Node* temp1 = list1;
    Node* temp2 = list2;

    while (temp1 && temp2) {
        if (temp1->val < temp2->val) {
            mover->next = temp1;
            temp1 = temp1->next;
        } else {
            mover->next = temp2;
            temp2 = temp2->next;
        }

        mover = mover->next;
    }

    if (temp1)
        mover->next = temp1;

    if (temp2)
        mover->next = temp2;

    return dummy->next;
}