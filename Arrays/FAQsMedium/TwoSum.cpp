#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  int n = nums.size();
  unordered_map<int, int> seen;
  int complement = 0;

  for (int i = 0; i < n; i++) {
    complement = target - nums[i];
    if (seen.find(complement) != seen.end()) {
      return {i, seen[complement]};
    }

    seen[nums[i]] = i;
  }

  return {-1, -1};
}
