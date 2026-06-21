#include <algorithm>
#include <vector>
using namespace std;

void nextPremutation(vector<int> &nums) {
  int n = nums.size();
  int pivot = -1;

  for (int i = n - 2; i >= 0; i--) {
    if (nums[i] < nums[i + 1]) {
      pivot = i;
      break;
    }
  }

  if (pivot == -1) {
    reverse(nums.begin(), nums.end());
    return;
  }

  int j = n - 1;

  while (j > pivot) {
    if (nums[j] > nums[pivot]) {
      swap(nums[j], nums[pivot]);
      break;
    }
    j--;
  }

  reverse(nums.begin() + pivot + 1, nums.end());
}
