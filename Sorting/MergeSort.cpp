#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high) {
  vector<int> temp;
  int l = low, r = mid + 1;

  while (l <= mid && r <= high) {
    if (nums[l] <= nums[r])
      temp.push_back(nums[l++]);
    else
      temp.push_back(nums[r++]);
  }

  while (l <= mid)
    temp.push_back(nums[l++]);
  while (r <= high)
    temp.push_back(nums[r++]);

  for (int i = low; i <= high; i++) {
    nums[i] = temp[i - low];
  }
}

void mergeSort(vector<int> &nums, int low, int high) {
  if (low >= high)
    return;

  int mid = low + (high - low) / 2;
  mergeSort(nums, low, mid);
  mergeSort(nums, mid + 1, high);

  merge(nums, low, mid, high);
}
