#include <vector>
using namespace std;

int cnt = 0;

void merge(vector<int> &nums, int low, int mid, int high) {
  vector<int> temp;
  int l = low, r = mid + 1;

  while (l <= mid && r <= high) {
    if (nums[l] > nums[r]) {
      temp.push_back(nums[r++]);
    } else {
      temp.push_back(nums[l++]);
    }
  }

  while (l <= mid)
    temp.push_back(nums[l++]);
  while (r <= high)
    temp.push_back(nums[r++]);

  for (int i = low; i <= high; i++) {
    nums[i] = temp[i - low];
  }
}

void countPairs(vector<int> &nums, int low, int mid, int high) {
  int right = mid + 1;
  for (int i = low; i <= mid; i++) {
    while (right <= high && nums[i] > 2LL * nums[right]) {
      right++;
    }

    cnt += right - (mid + 1);
  }
}

void mergeSort(vector<int> &nums, int low, int high) {
  if (low >= high)
    return;
  int mid = low + (high - low) / 2;

  mergeSort(nums, low, mid);
  mergeSort(nums, mid + 1, high);
  countPairs(nums, low, mid, high);
  merge(nums, low, mid, high);
}
