#include "Node.h"
#include "algorithm"
#include <climits>
using namespace std;

int maxi = INT_MIN;

int maxPathSum(Node *root) {
  if (!root)
    return 0;

  int ls = max(0, maxPathSum(root->left));
  int rs = max(0, maxPathSum(root->right));

  maxi = max(maxi, ls + rs + root->val);
  return max(ls, rs) + root->val;
}
