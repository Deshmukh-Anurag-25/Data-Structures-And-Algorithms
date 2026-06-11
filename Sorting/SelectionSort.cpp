#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &nums) {

  int n = nums.size();
  for (int i = 0; i < n; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (nums[j] < nums[mini])
        mini = j;
    }

    if (mini != i)
      swap(nums[mini], nums[i]);
  }
}
