#include <vector>
using namespace std;

/**
 * @brief Stores the total number of reverse pairs found during Merge Sort.
 *
 * A reverse pair is a pair of indices (i, j) such that:
 * - i < j
 * - nums[i] > 2 * nums[j]
 *
 * The variable is updated during the merge sort process after counting
 * valid pairs across the two sorted halves.
 */
int cnt = 0;

/**
 * @brief Merges two sorted subarrays into a single sorted subarray.
 *
 * The function merges the following sorted ranges:
 * - nums[low ... mid]
 * - nums[mid + 1 ... high]
 *
 * The merged result is written back into the original array.
 *
 * Example:
 * Left  = {1, 4, 6}
 * Right = {2, 3, 5}
 *
 * After merging:
 * {1, 2, 3, 4, 5, 6}
 *
 * Note:
 * - Both subarrays must already be sorted.
 * - The merge operation is stable.
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
 * @brief Counts reverse pairs between two sorted subarrays.
 *
 * Counts pairs (i, j) such that:
 * - low ≤ i ≤ mid
 * - mid + 1 ≤ j ≤ high
 * - nums[i] > 2 * nums[j]
 *
 * Since both halves are already sorted, a two-pointer approach efficiently
 * counts all valid reverse pairs without restarting the right pointer for
 * each element in the left half.
 *
 * Example:
 * Left  = {4, 5}
 * Right = {1, 2}
 *
 * Reverse pairs:
 * (4,1), (5,1), (5,2)
 *
 * Count = 3
 *
 * Algorithm:
 * 1. Initialize the right pointer to the beginning of the right subarray.
 * 2. For each element in the left subarray:
 *    - Move the right pointer while the reverse pair condition holds.
 *    - Add the number of valid right-side elements to the answer.
 *
 * Note:
 * - Both subarrays must already be sorted.
 * - Uses 2LL to avoid integer overflow during multiplication.
 *
 * @param nums The input array.
 * @param low Starting index of the left subarray.
 * @param mid Ending index of the left subarray.
 * @param high Ending index of the right subarray.
 *
 * Time Complexity: O(high - low + 1)
 * Space Complexity: O(1)
 */
void countPairs(vector<int> &nums, int low, int mid, int high) {
    int right = mid + 1;

    for (int i = low; i <= mid; i++) {
        while (right <= high && nums[i] > 2LL * nums[right]) {
            right++;
        }

        cnt += right - (mid + 1);
    }
}

/**
 * @brief Sorts an array using Merge Sort while counting reverse pairs.
 *
 * Recursively divides the array into two halves, counts reverse pairs
 * between the sorted halves, and merges them into a single sorted array.
 *
 * A reverse pair satisfies:
 * nums[i] > 2 * nums[j], where i < j.
 *
 * Example:
 * nums = {1, 3, 2, 3, 1}
 *
 * After execution:
 * nums = {1, 1, 2, 3, 3}
 *
 * cnt = 2
 *
 * Algorithm:
 * 1. Recursively sort the left half.
 * 2. Recursively sort the right half.
 * 3. Count reverse pairs between the two sorted halves.
 * 4. Merge the two halves.
 *
 * Note:
 * - The array is sorted in-place.
 * - The total number of reverse pairs is accumulated in the global
 *   variable `cnt`.
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

    countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);
}