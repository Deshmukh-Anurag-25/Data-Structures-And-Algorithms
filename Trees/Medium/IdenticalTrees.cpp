#include "Node.h"

bool isIdentical(Node *p, Node *q) {
  if (!p && !q)
    return true;
  if (!p || !q)
    return false;
  if (p->val != q->val)
    return false;

  return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
}
