#pragma once

/**
 * @brief Represents a node in a doubly linked list.
 *
 * Each node stores an integer value along with pointers to both the next
 * and previous nodes in the list. This structure serves as the fundamental
 * building block for doubly linked list implementations.
 *
 * Data Members:
 * - val  : The integer value stored in the node.
 * - next : Pointer to the next node in the list. A value of nullptr
 *          indicates that this is the last node.
 * - prev : Pointer to the previous node in the list. A value of nullptr
 *          indicates that this is the first node.
 *
 * Constructors:
 * - Node()
 *      Creates a node with value 0 and both next and prev set to nullptr.
 *
 * - Node(int val)
 *      Creates a node with the specified value and both next and prev set
 *      to nullptr.
 *
 * - Node(int val, Node* next, Node* prev)
 *      Creates a node with the specified value and initializes both the
 *      next and previous pointers.
 *
 * Example:
 * Node* first = new Node(10);
 * Node* second = new Node(20);
 *
 * first->next = second;
 * second->prev = first;
 *
 * Result:
 * nullptr <- 10 <-> 20 -> nullptr
 */
struct Node {
    int val;       ///< The value stored in the node.
    Node* next;    ///< Pointer to the next node.
    Node* prev;    ///< Pointer to the previous node.

    /// @brief Constructs a node with value 0 and both pointers set to nullptr.
    Node() : val(0), next(nullptr), prev(nullptr) {}

    /**
     * @brief Constructs a node with the specified value.
     * @param val The value to store in the node.
     */
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}

    /**
     * @brief Constructs a node with the specified value and neighboring pointers.
     * @param val The value to store in the node.
     * @param next Pointer to the next node.
     * @param prev Pointer to the previous node.
     */
    Node(int val, Node* next, Node* prev)
        : val(val), next(next), prev(prev) {}
};