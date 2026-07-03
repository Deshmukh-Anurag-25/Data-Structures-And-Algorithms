#include "ListNode.h"
using namespace std;

/**
 * @brief Finds the intersection node of two singly linked lists.
 *
 * Determines the first common node shared by two singly linked lists using
 * the two-pointer technique. The pointers traverse both lists and switch
 * to the head of the opposite list after reaching the end. This equalizes
 * the total distance traveled by both pointers, ensuring they either meet
 * at the intersection node or simultaneously reach nullptr.
 *
 * Example:
 * List A: 4 -> 1
 *              \
 *               8 -> 4 -> 5
 *              /
 * List B:    5 -> 6 -> 1
 *
 * Returns:
 * Node containing value 8.
 *
 * Example:
 * List A: 1 -> 2 -> 3
 * List B: 4 -> 5 -> 6
 *
 * Returns:
 * nullptr
 *
 * Algorithm:
 * 1. Initialize two pointers at the heads of the two lists.
 * 2. Traverse both lists simultaneously.
 * 3. When a pointer reaches the end of its list, redirect it to the head
 *    of the other list.
 * 4. Continue until both pointers point to the same node.
 * 5. Return the meeting node (or nullptr if no intersection exists).
 *
 * Note:
 * - Intersection is determined by node address, not by node value.
 * - The linked lists are not modified.
 * - If no intersection exists, the function returns nullptr.
 *
 * @param headA Pointer to the head of the first linked list.
 * @param headB Pointer to the head of the second linked list.
 * @return Node* Pointer to the intersection node, or nullptr if the lists
 *         do not intersect.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(1)
 */
Node* getIntersectionNode(Node* headA, Node* headB) {
    Node* tempA = headA;
    Node* tempB = headB;

    while (tempA != tempB) {
        tempA = (tempA) ? tempA->next : headB;
        tempB = (tempB) ? tempB->next : headA;
    }

    return tempA;
}