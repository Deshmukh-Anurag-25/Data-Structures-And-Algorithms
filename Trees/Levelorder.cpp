#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> levelOrder(Node *root) {
  if (!root)
    return {};
  queue<Node *> q;
  vector<vector<int>> ans;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    vector<int> level;

    for (int i = 0; i < n; i++) {
      Node *front = q.front();
      q.pop();

      level.push_back(front->val);
      if (front->left)
        q.push(front->left);
      if (front->right)
        q.push(front->right);
    }

    ans.push_back(level);
  }

  return ans;
}
