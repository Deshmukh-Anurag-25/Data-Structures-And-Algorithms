#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

int height(Node *root) {
  if (!root)
    return 0;

  int leftHeight = height(root->left);
  if (leftHeight == -1)
    return -1;
  int rightHeight = height(root->right);
  if (rightHeight == -1)
    return -1;

  if (abs(leftHeight - rightHeight) > 1)
    return -1;
  return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(Node *root) { return height(root) != -1; }
