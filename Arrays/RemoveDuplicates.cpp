#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
  int n = nums.size();
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] != nums[j]) {
      nums[++j] = nums[i];
    }
  }

  return j + 1;
}
