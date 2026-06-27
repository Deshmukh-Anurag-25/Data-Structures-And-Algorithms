#include "Node.h"
#include <map>
#include <queue>
#include <vector>
using namespace std;

vector<int> topView(Node *root) {
  if (!root)
    return {};

  queue<pair<Node *, int>> q;
  map<int, int> mpp;
  vector<int> ans;

  q.push({root, 0});

  while (!q.empty()) {
    auto it = q.front();
    q.pop();

    Node *node = it.first;
    int line = it.second;

    if (mpp.find(line) == mpp.end())
      mpp[line] = node->val;

    if (node->left)
      q.push({node->left, line - 1});
    if (node->right)
      q.push({node->right, line + 1});
  }

  for (auto it : mpp) {
    ans.push_back(it.second);
  }

  return ans;
}
