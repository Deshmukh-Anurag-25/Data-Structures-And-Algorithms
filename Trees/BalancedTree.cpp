#include "Node.h"
#include <algorithm>
using namespace std;

int height(Node *root) {
  if (!root)
    return 0;
  int lh = height(root->left);
  if (lh == -1)
    return -1;
  int rh = height(root->right);
  if (rh == -1)
    return -1;

  if (abs(lh - rh) > 1)
    return -1;

  return 1 + max(lh, rh);
}

bool isBalanced(Node *root) {
  int ans = height(root);
  return (ans == -1) ? false : true;
}
