#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

int dfs(Node *root, int &maxi) {
  if (!root)
    return 0;

  int ls = max(0, dfs(root->left, maxi));
  int rs = max(0, dfs(root->right, maxi));

  maxi = max(maxi, ls + rs + root->val);

  return root->val + max(ls, rs);
}

int maxSum(Node *root) {
  int maxi = INT_MIN;
  dfs(root, maxi);

  return maxi;
}
