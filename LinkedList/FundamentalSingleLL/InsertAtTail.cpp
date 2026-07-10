#include "ListNode.h"
using namespace std;

/**
 * @brief Inserts a new node at the end of a singly linked list.
 *
 * The function creates a new node containing the specified value and
 * appends it to the end of the linked list.
 *
 * Example:
 * Linked List:
 * 1 -> 2 -> 3 -> nullptr
 * x = 4
 *
 * Returns:
 * 1 -> 2 -> 3 -> 4 -> nullptr
 *
 * Algorithm:
 * 1. Create a new node.
 * 2. If the list is empty, return the new node.
 * 3. Traverse to the last node.
 * 4. Link the last node to the new node.
 * 5. Return the original head.
 *
 * @param head Pointer to the head of the linked list.
 * @param x Value to insert.
 * @return Node* Pointer to the head of the updated list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* insertTail(Node* head, int x) {
    Node* newNode = new Node(x);

    if (!head)
        return newNode;

    Node* temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = newNode;

    return head;
}   