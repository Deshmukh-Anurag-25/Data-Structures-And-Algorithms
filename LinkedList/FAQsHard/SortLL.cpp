#include "ListNode.h"
using namespace std;

/**
 * @brief Merges two sorted singly linked lists into a single sorted list.
 *
 * Iteratively merges two linked lists sorted in non-decreasing order by
 * repeatedly selecting the smaller of the current nodes from each list.
 * Existing nodes are relinked; no new data nodes are created.
 *
 * Example:
 * list1 = 1 -> 3 -> 5
 * list2 = 2 -> 4 -> 6
 *
 * Returns:
 * 1 -> 2 -> 3 -> 4 -> 5 -> 6
 *
 * Algorithm:
 * 1. Create a dummy node to simplify list construction.
 * 2. Compare the current nodes of both lists.
 * 3. Append the smaller node to the merged list.
 * 4. Advance the corresponding pointer.
 * 5. When one list is exhausted, append the remaining nodes of the other list.
 * 6. Return the node following the dummy node.
 *
 * Note:
 * - The input lists must already be sorted.
 * - Existing nodes are reused.
 * - The merge is stable; equal-valued nodes preserve their relative order.
 *
 * @param list1 Pointer to the head of the first sorted linked list.
 * @param list2 Pointer to the head of the second sorted linked list.
 * @return Node* Pointer to the head of the merged sorted linked list.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(1)
 */
Node* merge(Node* list1, Node* list2) {
    Node* dummy = new Node(0);
    Node* temp = dummy;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if (list1)
        temp->next = list1;
    else
        temp->next = list2;

    return dummy->next;
}

/**
 * @brief Finds the middle node of a singly linked list.
 *
 * Uses the slow and fast pointer technique to locate the node immediately
 * preceding the midpoint of the list. This is particularly useful for
 * splitting a linked list into two nearly equal halves during merge sort.
 *
 * For an even-length list, the first middle node is returned.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4
 *
 * Returns:
 * Node containing value 2.
 *
 * Example:
 * head = 1 -> 2 -> 3 -> 4 -> 5
 *
 * Returns:
 * Node containing value 3.
 *
 * @param head Pointer to the head of the linked list.
 * @return Node* Pointer to the middle node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* findMiddle(Node* head) {
    if (!head || !head->next)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/**
 * @brief Sorts a singly linked list using Merge Sort.
 *
 * Recursively divides the linked list into two halves, sorts each half,
 * and merges the sorted halves to produce a fully sorted linked list.
 *
 * Merge Sort is particularly well-suited for linked lists because merging
 * can be performed efficiently without requiring random access.
 *
 * Example:
 * head = 4 -> 2 -> 1 -> 3
 *
 * Returns:
 * 1 -> 2 -> 3 -> 4
 *
 * Example:
 * head = -1 -> 5 -> 3 -> 4 -> 0
 *
 * Returns:
 * -1 -> 0 -> 3 -> 4 -> 5
 *
 * Algorithm:
 * 1. Handle the base case of an empty or single-node list.
 * 2. Find the middle node of the list.
 * 3. Split the list into two halves.
 * 4. Recursively sort both halves.
 * 5. Merge the two sorted halves.
 * 6. Return the head of the merged list.
 *
 * Note:
 * - The linked list is sorted in-place by relinking existing nodes.
 * - No additional data nodes are allocated during sorting.
 * - The algorithm is stable.
 *
 * @param head Pointer to the head of the linked list.
 * @return Node* Pointer to the head of the sorted linked list.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(log n) (recursive call stack)
 */
Node* sortList(Node* head) {
    if (!head || !head->next)
        return head;

    Node* middle = findMiddle(head);

    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    left = sortList(left);
    right = sortList(right);

    return merge(left, right);
}