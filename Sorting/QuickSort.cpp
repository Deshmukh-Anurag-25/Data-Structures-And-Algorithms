#include <vector>
using namespace std;

int partition(vector<int> &nums, int low, int high) {
  int pivot = nums[low];
  int l = low, r = high;
  while (l <= r) {
    while (l <= high - 1 && nums[l] <= pivot)
      l++;
    while (r >= low + 1 && nums[r] > pivot)
      r--;

    if (l < r)
      swap(nums[l], nums[r]);
  }

  swap(nums[low], nums[r]);
  return r;
}

void quickSort(vector<int> &nums, int low, int high) {
  if (low >= high)
    return;

  int pivot = partition(nums, low, high);
  quickSort(nums, low, pivot - 1);
  quickSort(nums, pivot + 1, high);
}
