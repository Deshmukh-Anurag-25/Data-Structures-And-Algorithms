#include <vector>
using namespace std;

void insertionSort(vector<int> &nums) {
  int n = nums.size();

  for (int i = 1; i < n; i++) {
    int pivot = nums[i];
    int j = i - 1;

    while (j >= 0 && nums[j] > pivot) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = pivot;
  }
}
