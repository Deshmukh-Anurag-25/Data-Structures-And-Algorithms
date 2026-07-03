#include "ListNode.h"
using namespace std;

/**
 * @brief Rearranges a linked list by grouping odd-indexed nodes followed by
 *        even-indexed nodes.
 *
 * Rearranges the nodes of a singly linked list such that all nodes at odd
 * positions appear before all nodes at even positions while preserving the
 * relative order within each group.
 *
 * The node positions are based on **1-based indexing**, not on the values
 * stored in the nodes.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4 -> 5
 *
 * Returns:
 * 1 -> 3 -> 5 -> 2 -> 4
 *
 * Example:
 * head = 2 -> 1 -> 3 -> 5 -> 6 -> 4 -> 7
 *
 * Returns:
 * 2 -> 3 -> 6 -> 7 -> 1 -> 5 -> 4
 *
 * Algorithm:
 * 1. Handle the empty list and single-node list as edge cases.
 * 2. Initialize pointers to the first odd and first even nodes.
 * 3. Traverse the list while both even nodes and their successors exist.
 * 4. Relink:
 *    - The current odd node to the next odd node.
 *    - The current even node to the next even node.
 * 5. Append the even list after the odd list.
 * 6. Return the head of the rearranged list.
 *
 * Note:
 * - The rearrangement is performed in-place.
 * - The relative order of odd-positioned nodes is preserved.
 * - The relative order of even-positioned nodes is preserved.
 * - Node positions (not node values) determine whether a node is odd or even.
 *
 * @param head Reference to the head of the linked list.
 * @return Node* Pointer to the head of the rearranged linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* oddEvenList(Node* &head) {
    if (!head || !head->next)
        return head;

    Node* oHead = head;
    Node* eHead = head->next;

    Node* tempO = oHead;
    Node* tempE = eHead;

    while (tempE && tempE->next) {
        tempO->next = tempE->next;
        tempO = tempO->next;

        tempE->next = tempO->next;
        tempE = tempE->next;
    }

    tempO->next = eHead;

    return oHead;
}