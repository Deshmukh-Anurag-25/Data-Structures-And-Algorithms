#include <vector>
using namespace std;

vector<int> pascalTriangleII(int r) {
  vector<int> ans;
  ans.push_back(1);
  int res = 1;

  for (int i = 1; i < r; i++) {
    res = res * (r - i);
    res = res / i;

    ans.push_back(res);
  }

  return ans;
}

vector<vector<int>> pascalTriangleIII(int r) {
  vector<vector<int>> ans;
  for (int i = 1; i <= r; i++) {
    ans.push_back(pascalTriangleII(i));
  }

  return ans;
}
