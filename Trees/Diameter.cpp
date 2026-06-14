#include "Node.h"
#include "bits/stdc++.h"
using namespace std;

int height(Node *root, int &diameter) {
  if (!root)
    return 0;

  int leftHeight = height(root->left, diameter);
  int rightHeight = height(root->right, diameter);

  diameter = max(diameter, leftHeight + rightHeight);

  return 1 + max(leftHeight, rightHeight);
}

int diameterOfBT(Node *root) {
  int diameter = 0;
  height(root, diameter);
  return diameter;
}
