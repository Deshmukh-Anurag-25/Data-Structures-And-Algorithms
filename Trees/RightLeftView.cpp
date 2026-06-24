#include "Node.h"
#include <vector>
using namespace std;

void dfsRight(Node *root, int level, vector<int> &ans) {
  if (!root)
    return;
  if (ans.size() == level)
    ans.push_back(root->val);

  dfsRight(root->right, level + 1, ans);
  dfsRight(root->left, level + 1, ans);
}

vector<int> rightSideView(Node *root) {
  vector<int> ans;
  dfsRight(root, 0, ans);
  return ans;
}

void dfsLeft(Node *root, int level, vector<int> &ans) {
  if (!root)
    return;
  if (ans.size() == level)
    ans.push_back(root->val);
  dfsLeft(root->left, level + 1, ans);
  dfsLeft(root->right, level + 1, ans);
}
