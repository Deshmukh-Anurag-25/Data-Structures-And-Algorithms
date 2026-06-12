#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

void dfs(Node *root, vector<int> &ans) {
  if (!root)
    return;

  dfs(root->left, ans);
  ans.push_back(root->val);
  dfs(root->right, ans);
}

vector<int> inorder(Node *root) {
  vector<int> ans;
  dfs(root, ans);

  return ans;
}
