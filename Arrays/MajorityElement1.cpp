#include <vector>
using namespace std;

int majorityElement(vector<int> &nums) {
  int n = nums.size();
  int el = 0, cnt = 0;

  for (int num : nums) {
    if (cnt == 0) {
      cnt = 1;
      el = num;
    } else if (el == num) {
      cnt++;
    } else
      cnt--;
  }

  cnt = 0;
  for (int num : nums) {
    if (num == el)
      cnt++;
  }

  return (cnt > n / 2) ? el : -1;
}
