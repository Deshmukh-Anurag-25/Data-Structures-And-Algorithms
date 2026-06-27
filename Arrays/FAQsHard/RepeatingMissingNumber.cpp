#include <math.h>
#include <vector>
using namespace std;

vector<int> findMissingRepeatingNumber(vector<int> &nums) {
  int n = nums.size();
  vector<int> ans;

  for (int i = 0; i < n; i++) {
    int idx = abs(nums[i]) - 1;
    if (nums[idx] < 0) {
      ans.push_back(idx + 1);
    } else {
      nums[idx] *= -1;
    }
  }

  for (int i = 0; i < n; i++) {
    if (nums[i] > 0)
      ans.push_back(i + 1);
  }

  return ans;
}
