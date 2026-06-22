#include "Node.h"
#include <algorithm>
using namespace std;

int height(Node *root, int &diameter) {
  if (!root)
    return 0;
  int lh = height(root->left, diameter);
  int rh = height(root->right, diameter);

  diameter = max(diameter, lh + rh);

  return 1 + max(lh, rh);
}

int diameterOfBinaryTree(Node *root) {
  int diameter = 0;
  height(root, diameter);
  return diameter;
}
