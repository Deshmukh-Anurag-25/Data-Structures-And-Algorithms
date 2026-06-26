#include "Node.h"

Node *insertNode(Node *root, int x) {
  Node *newNode = new Node(x);
  if (!root)
    return newNode;
  Node *curr = root;
  Node *prev = nullptr;

  while (curr) {
    prev = curr;

    if (curr->val < x) {
      curr = curr->right;
    } else {
      curr = curr->left;
    }
  }

  if (prev->val < x) {
    prev->right = newNode;
  } else {
    prev->left = newNode;
  }

  return root;
}
