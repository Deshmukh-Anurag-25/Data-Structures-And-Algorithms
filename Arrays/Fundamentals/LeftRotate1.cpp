#include <vector>
using namespace std;

void leftRotate(vector<int> &nums) {
  int temp = nums[0];
  int n = nums.size();
  for (int i = 0; i < n - 1; i++) {
    nums[i] = nums[i + 1];
  }

  nums[n - 1] = temp;
}
