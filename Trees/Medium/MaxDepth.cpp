#include "Node.h"
#include <algorithm>
using namespace std;

int maxDepth(Node *root) {
  if (!root)
    return 0;
  int leftHeight = maxDepth(root->left);
  int rightHeight = maxDepth(root->right);

  return 1 + max(leftHeight, rightHeight);
}
