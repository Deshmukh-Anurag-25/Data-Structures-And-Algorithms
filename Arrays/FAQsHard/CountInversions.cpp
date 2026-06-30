#include <vector>
using namespace std;

/**
 * @brief Stores the total number of inversions found during Merge Sort.
 *
 * An inversion is a pair of indices (i, j) such that:
 * - i < j
 * - nums[i] > nums[j]
 *
 * The variable is updated during the merge step whenever an element from
 * the right subarray is placed before remaining elements in the left
 * subarray.
 */
int cnt = 0;

/**
 * @brief Merges two sorted subarrays while counting inversions.
 *
 * The function merges the following sorted ranges:
 * - nums[low ... mid]
 * - nums[mid + 1 ... high]
 *
 * During merging, if an element in the right subarray is smaller than the
 * current element in the left subarray, then all remaining elements in the
 * left subarray form inversions with that element.
 *
 * Example:
 * nums = {2, 4, 5, 1, 3}
 *
 * Left  = {2, 4, 5}
 * Right = {1, 3}
 *
 * Inversions found:
 * (2,1), (4,1), (5,1), (4,3), (5,3)
 *
 * Count added = 5
 *
 * Algorithm:
 * 1. Maintain two pointers for the left and right sorted subarrays.
 * 2. Compare the current elements.
 * 3. If the left element is greater:
 *    - Every remaining element in the left subarray forms an inversion.
 *    - Increase the inversion count.
 *    - Insert the right element into the temporary array.
 * 4. Otherwise, insert the left element.
 * 5. Copy any remaining elements.
 * 6. Copy the merged result back into the original array.
 *
 * Note:
 * - Both subarrays must already be sorted.
 * - The merge is stable.
 * - The global variable `cnt` accumulates the inversion count.
 *
 * @param nums The input array.
 * @param low Starting index of the first subarray.
 * @param mid Ending index of the first subarray.
 * @param high Ending index of the second subarray.
 *
 * Time Complexity: O(high - low + 1)
 * Space Complexity: O(high - low + 1)
 */
void merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp;
    int l = low, r = mid + 1;

    while (l <= mid && r <= high) {
        if (nums[l] > nums[r]) {
            cnt += mid - l + 1;
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

/**
 * @brief Sorts an array using Merge Sort while counting inversions.
 *
 * Recursively divides the array into two halves until each subarray
 * contains a single element. During the merge phase, the subarrays are
 * merged back together in sorted order while counting inversions.
 *
 * Example:
 * nums = {5, 3, 2, 4, 1}
 *
 * After execution:
 * nums = {1, 2, 3, 4, 5}
 *
 * cnt = 8
 *
 * Algorithm:
 * 1. Recursively split the array into two halves.
 * 2. Sort the left half.
 * 3. Sort the right half.
 * 4. Merge the two sorted halves while counting inversions.
 *
 * Note:
 * - The array is sorted in-place.
 * - The inversion count is stored in the global variable `cnt`.
 *
 * @param nums The input array.
 * @param low Starting index of the current subarray.
 * @param high Ending index of the current subarray.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
void mergeSort(vector<int> &nums, int low, int high) {
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}