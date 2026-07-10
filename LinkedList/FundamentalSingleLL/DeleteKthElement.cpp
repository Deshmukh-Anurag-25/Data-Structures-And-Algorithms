#include "ListNode.h"
using namespace std;

/**
 * @brief Deletes the k-th node from a singly linked list.
 *
 * The nodes are numbered starting from 1. If the specified position is
 * valid, the corresponding node is removed from the list and its memory is
 * released.
 *
 * Example:
 * Linked List:
 * 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
 * k = 3
 *
 * Returns:
 * 1 -> 2 -> 4 -> 5 -> nullptr
 *
 * Example:
 * Linked List:
 * 10 -> 20 -> nullptr
 * k = 1
 *
 * Returns:
 * 20 -> nullptr
 *
 * Algorithm:
 * 1. If the linked list is empty, return nullptr.
 * 2. If k = 1:
 *    - Remove the head node.
 *    - Return the new head.
 * 3. Traverse the linked list while maintaining the current node, its
 *    previous node, and the current position.
 * 4. When the k-th node is reached:
 *    - Link the previous node to the next node.
 *    - Delete the current node.
 * 5. Return the head of the updated linked list.
 *
 * Note:
 * - If k is greater than the length of the linked list, the list remains
 *   unchanged.
 * - Node positions are 1-based.
 *
 * @param head Pointer to the head of the singly linked list.
 * @param k Position of the node to delete (1-based indexing).
 * @return Node* Pointer to the head of the updated linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of nodes in the linked list.
 */
Node* deleteKthElement(Node* head, int k) {
    if (!head)
        return nullptr;

    if (k == 1) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    int cnt = 1;
    Node* prev = nullptr;
    Node* temp = head;

    while (temp) {
        if (cnt == k) {
            prev->next = temp->next;
            delete temp;
            break;
        }

        cnt++;
        prev = temp;
        temp = temp->next;
    }

    return head;
}