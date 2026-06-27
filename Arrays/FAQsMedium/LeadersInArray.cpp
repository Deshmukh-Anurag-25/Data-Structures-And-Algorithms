#include <vector>
using namespace std;

vector<int> leaders(vector<int> &nums) {
  int n = nums.size();
  vector<int> ans;
  int maxi = nums[n - 1];

  for (int i = n - 1; i >= 0; i--) {
    if (ans.empty() || nums[i] > maxi) {
      ans.push_back(nums[i]);
      maxi = nums[i];
    }
  }

  return ans;
}
