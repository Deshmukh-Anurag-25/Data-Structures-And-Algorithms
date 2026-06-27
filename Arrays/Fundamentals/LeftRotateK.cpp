#include <algorithm>
#include <vector>
using namespace std;

void leftRotateBy(vector<int> &nums, int k) {
  int n = nums.size();
  k %= n;
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
  reverse(nums.begin(), nums.end());
}
