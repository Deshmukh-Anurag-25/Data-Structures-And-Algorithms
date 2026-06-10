#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; i++) {

    bool isSorted = true;
    for (int j = 1; j < n - i; j++) {
      if (nums[j] < nums[j - 1]) {
        swap(nums[j], nums[j - 1]);
        isSorted = false;
      }
    }

    if (isSorted)
      break;
  }
}
