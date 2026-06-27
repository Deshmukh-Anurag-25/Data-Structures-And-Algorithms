#include "Node.h"
#include <vector>
using namespace std;

void dfs(Node *root, vector<int> &ans) {
  if (!root)
    return;
  dfs(root->left, ans);
  dfs(root->right, ans);
  ans.push_back(root->val);
}

vector<int> postorder(Node *root) {
  vector<int> ans;
  dfs(root, ans);
  return ans;
}
