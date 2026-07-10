#include "ListNode.h"
using namespace std;

/**
 * @brief Inserts a new node at the beginning of a singly linked list.
 *
 * The function creates a new node with the specified value and makes it
 * the new head of the linked list.
 *
 * Example:
 * Linked List:
 * 2 -> 3 -> 4 -> nullptr
 * x = 1
 *
 * Returns:
 * 1 -> 2 -> 3 -> 4 -> nullptr
 *
 * Algorithm:
 * 1. Create a new node with the given value.
 * 2. Point the new node to the current head.
 * 3. Return the new node as the updated head.
 *
 * @param head Pointer to the head of the linked list.
 * @param x Value to insert.
 * @return Node* Pointer to the new head.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
Node* insertHead(Node* head, int x) {
    Node* newNode = new Node(x);
    newNode->next = head;
    return newNode;
}