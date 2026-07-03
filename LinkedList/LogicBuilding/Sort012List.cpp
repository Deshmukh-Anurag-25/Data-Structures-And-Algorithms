#include"ListNode.h"
using namespace std;

/**
 * @brief Sorts a linked list containing only 0s, 1s, and 2s.
 *
 * Rearranges the nodes of a singly linked list so that all 0s appear first,
 * followed by all 1s, and then all 2s. The sorting is performed by creating
 * three separate sublists—one for each value—and then concatenating them.
 *
 * No new data nodes are created; the existing nodes are relinked.
 *
 * Example:
 * head = 1 -> 0 -> 2 -> 1 -> 0
 *
 * Returns:
 * 0 -> 0 -> 1 -> 1 -> 2
 *
 * Example:
 * head = 2 -> 2 -> 1 -> 0
 *
 * Returns:
 * 0 -> 1 -> 2 -> 2
 *
 * Algorithm:
 * 1. Create three dummy nodes representing the lists of 0s, 1s, and 2s.
 * 2. Traverse the original linked list.
 * 3. Append each node to its corresponding sublist.
 * 4. Terminate all three sublists.
 * 5. Connect:
 *    - 0-list to the 1-list if it exists; otherwise to the 2-list.
 *    - 1-list to the 2-list.
 * 6. Return the head of the merged list.
 *
 * Note:
 * - The input list is modified in-place.
 * - The relative order of nodes with the same value is preserved.
 * - The function assumes every node contains only 0, 1, or 2.
 *
 * @param head Reference to the head of the linked list.
 * @return Node* Pointer to the head of the sorted linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* sortList(Node* &head) {
    Node head0(-1), head1(-1), head2(-1);
    Node *temp0 = &head0;
    Node *temp1 = &head1;
    Node *temp2 = &head2;

    Node* temp = head;

    while (temp) {
        if (temp->val == 0) {
            temp0->next = temp;
            temp0 = temp0->next;
        } else if (temp->val == 1) {
            temp1->next = temp;
            temp1 = temp1->next;
        } else {
            temp2->next = temp;
            temp2 = temp2->next;
        }

        temp = temp->next;
    }

    temp0->next = nullptr;
    temp1->next = nullptr;
    temp2->next = nullptr;

    temp0->next = (head1.next) ? head1.next : head2.next;
    temp1->next = head2.next;

    return head0.next;
}