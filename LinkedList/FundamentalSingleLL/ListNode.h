#pragma once

/**
 * @brief Represents a node in a singly linked list.
 *
 * Each node stores an integer value and a pointer to the next node in the
 * list. This structure serves as the fundamental building block for
 * singly linked list implementations.
 *
 * Data Members:
 * - val  : The integer value stored in the node.
 * - next : Pointer to the next node in the list. A value of nullptr
 *          indicates that this is the last node.
 *
 * Constructors:
 * - Node()
 *      Creates a node with value 0 and next set to nullptr.
 *
 * - Node(int val)
 *      Creates a node with the specified value and next set to nullptr.
 *
 * - Node(int val, Node* next)
 *      Creates a node with the specified value and initializes the next
 *      pointer to the provided node.
 *
 * Example:
 * Node* head = new Node(10);
 * Node* second = new Node(20);
 * head->next = second;
 *
 * Result:
 * 10 -> 20 -> nullptr
 */
struct Node {
    int val;      ///< The value stored in the node.
    Node *next;   ///< Pointer to the next node.

    /// @brief Constructs a node with value 0 and next = nullptr.
    Node() : val(0), next(nullptr) {}

    /// @brief Constructs a node with the specified value.
    /// @param val The value to store in the node.
    Node(int val) : val(val), next(nullptr) {}

    /**
     * @brief Constructs a node with the specified value and next pointer.
     * @param val The value to store in the node.
     * @param next Pointer to the next node in the linked list.
     */
    Node(int val, Node *next) : val(val), next(next) {}
};