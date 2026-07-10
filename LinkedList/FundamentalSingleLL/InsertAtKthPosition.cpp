#include "ListNode.h"
using namespace std;

/**
 * @brief Inserts a new node at the k-th position of a singly linked list.
 *
 * Positions are numbered starting from 1.
 *
 * Example:
 * Linked List:
 * 1 -> 2 -> 4 -> 5 -> nullptr
 * k = 3, x = 3
 *
 * Returns:
 * 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
 *
 * Algorithm:
 * 1. If k = 1, insert at the head.
 * 2. Traverse until reaching the (k-1)-th node.
 * 3. Insert the new node after it.
 * 4. Return the head.
 *
 * Note:
 * - If k is greater than length + 1, the list remains unchanged.
 *
 * @param head Pointer to the head of the linked list.
 * @param k 1-based insertion position.
 * @param x Value to insert.
 * @return Node* Pointer to the updated head.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* insertKthPosition(Node* head, int k, int x) {
    if (k == 1) {
        Node* newNode = new Node(x);
        newNode->next = head;
        return newNode;
    }

    int cnt = 1;
    Node* temp = head;

    while (temp && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }

    if (!temp)
        return head;

    Node* newNode = new Node(x);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}