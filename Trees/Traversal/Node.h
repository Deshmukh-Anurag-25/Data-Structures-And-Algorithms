#pragma once

/**
 * @brief Represents a node in a binary tree.
 *
 * Each node stores an integer value along with pointers to its left and
 * right child nodes. This structure serves as the fundamental building
 * block for binary trees, including Binary Search Trees (BSTs),
 * Binary Trees (BTs), AVL Trees, and other tree-based data structures.
 *
 * Data Members:
 * - val   : The integer value stored in the node.
 * - left  : Pointer to the left child. A value of nullptr indicates that
 *           the node has no left child.
 * - right : Pointer to the right child. A value of nullptr indicates that
 *           the node has no right child.
 *
 * Constructors:
 * - Node()
 *      Creates a node with value 0 and both child pointers set to nullptr.
 *
 * - Node(int val)
 *      Creates a node with the specified value and initializes both child
 *      pointers to nullptr.
 *
 * - Node(int val, Node* left, Node* right)
 *      Creates a node with the specified value and initializes the left
 *      and right child pointers.
 *
 * Example:
 *          10
 *         /  \
 *        5    15
 *
 * Node* root = new Node(10);
 * root->left = new Node(5);
 * root->right = new Node(15);
 *
 * Result:
 *        10
 *       /  \
 *      5    15
 */
struct Node {
public:
    int val;      ///< The value stored in the node.
    Node *left;   ///< Pointer to the left child.
    Node *right;  ///< Pointer to the right child.

    /**
     * @brief Constructs a node with value 0 and no children.
     */
    Node() : val(0), left(nullptr), right(nullptr) {}

    /**
     * @brief Constructs a node with the specified value.
     * @param val The value to store in the node.
     */
    Node(int val) : val(val), left(nullptr), right(nullptr) {}

    /**
     * @brief Constructs a node with the specified value and child pointers.
     *
     * @param val The value to store in the node.
     * @param left Pointer to the left child.
     * @param right Pointer to the right child.
     */
    Node(int val, Node *left, Node *right)
        : val(val), left(left), right(right) {}
};