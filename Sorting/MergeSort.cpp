#include <vector>
using namespace std;

/**
 * @brief Merges two sorted subarrays into a single sorted subarray.
 *
 * The function merges the following sorted ranges:
 * - nums[low ... mid]
 * - nums[mid + 1 ... high]
 *
 * A temporary vector is used to store the merged elements before copying
 * them back into the original array.
 *
 * Example:
 * Before merging:
 * nums = {2, 5, 8, 1, 3, 7}
 *          ^     ^  ^     ^
 *         low   mid mid+1 high
 *
 * Left  = {2, 5, 8}
 * Right = {1, 3, 7}
 *
 * After merging:
 * nums = {1, 2, 3, 5, 7, 8}
 *
 * Algorithm:
 * 1. Maintain two pointers for the left and right sorted subarrays.
 * 2. Compare the current elements.
 * 3. Append the smaller element to the temporary array.
 * 4. Continue until one subarray is exhausted.
 * 5. Append the remaining elements of the other subarray.
 * 6. Copy the merged result back into the original array.
 *
 * Note:
 * - Both subarrays must already be sorted.
 * - Merge Sort is a stable sorting algorithm.
 *
 * @param nums The input vector.
 * @param low Starting index of the left subarray.
 * @param mid Ending index of the left subarray.
 * @param high Ending index of the right subarray.
 *
 * Time Complexity: O(high - low + 1)
 * Space Complexity: O(high - low + 1)
 */
void merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp;
    int l = low;
    int r = mid + 1;

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

/**
 * @brief Sorts an array in ascending order using the Merge Sort algorithm.
 *
 * Merge Sort is a divide-and-conquer algorithm that recursively divides
 * the array into two halves, sorts each half independently, and then
 * merges the sorted halves into a single sorted array.
 *
 * Example:
 * nums = {38, 27, 43, 3, 9, 82, 10}
 *
 * After execution:
 * nums = {3, 9, 10, 27, 38, 43, 82}
 *
 * Algorithm:
 * 1. Divide the array into two halves.
 * 2. Recursively sort the left half.
 * 3. Recursively sort the right half.
 * 4. Merge the two sorted halves.
 * 5. Repeat until the entire array is sorted.
 *
 * Note:
 * - Merge Sort is a stable sorting algorithm.
 * - It guarantees O(n log n) time complexity in all cases.
 * - Additional memory is required for merging.
 *
 * @param nums The input vector of integers to be sorted.
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