#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int low, int high) {
  int pivot = nums[low];
  int i = low, j = high;

  while (i < j) {
    while (nums[i] <= pivot && i <= high - 1)
      i++;
    while (nums[j] > pivot && j >= low + 1)
      j--;

    if (i < j)
      swap(nums[i], nums[j]);
  }

  swap(nums[low], nums[j]);
  return j;
}

void quickSort(vector<int> &nums, int low, int high) {
  if (low >= high)
    return;
  int pivotIdx = partition(nums, low, high);

  quickSort(nums, low, pivotIdx - 1);
  quickSort(nums, pivotIdx + 1, high);
}
