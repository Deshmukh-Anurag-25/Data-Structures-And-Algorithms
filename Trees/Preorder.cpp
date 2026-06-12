#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

void dfs(Node *root, vector<int> &ans) {
  if (!root)
    return;

  ans.push_back(root->val);
  dfs(root->left, ans);
  dfs(root->right, ans);
}

vector<int> preorder(Node *root) {
  vector<int> ans;
  dfs(root, ans);
  return ans;
}
