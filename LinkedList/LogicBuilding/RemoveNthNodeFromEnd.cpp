#include"ListNode.h"
using namespace std;

/**
 * @brief Removes the nth node from the end of a singly linked list.
 *
 * Uses the two-pointer technique along with a dummy node to remove the
 * nth node from the end of the list in a single traversal.
 *
 * The fast pointer is advanced (n + 1) steps ahead of the slow pointer,
 * creating a gap of n nodes between them. Both pointers are then moved
 * together until the fast pointer reaches the end of the list. At this
 * point, the slow pointer is positioned immediately before the node to
 * be removed.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4 -> 5
 * n = 2
 *
 * Returns:
 * 1 -> 2 -> 3 -> 5
 *
 * Example:
 * head = 1
 * n = 1
 *
 * Returns:
 * nullptr
 *
 * Algorithm:
 * 1. Create a dummy node pointing to the head.
 * 2. Initialize both fast and slow pointers at the dummy node.
 * 3. Move the fast pointer (n + 1) steps ahead.
 * 4. Move both pointers forward until fast reaches nullptr.
 * 5. The slow pointer now points to the node preceding the one to remove.
 * 6. Skip the target node by updating the next pointer.
 * 7. Return the node following the dummy node.
 *
 * Note:
 * - A dummy node simplifies handling the case where the head node is removed.
 * - The linked list is modified in-place.
 * - It is assumed that n is a valid position (1 ≤ n ≤ length of the list).
 *
 * @param head Pointer to the head of the linked list.
 * @param n The position (1-based) from the end of the list of the node to remove.
 * @return Node* Pointer to the head of the modified linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* removeNthFromEnd(Node* head, int n) {
    Node dummy(0, head);
    Node* fast = &dummy;
    Node* slow = &dummy;

    for (int i = 0; i <= n; i++)
        fast = fast->next;

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy.next;
}