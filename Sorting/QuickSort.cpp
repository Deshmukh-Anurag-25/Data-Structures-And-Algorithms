#include <vector>
using namespace std;

/**
 * @brief Partitions a subarray around a pivot for Quick Sort.
 *
 * Uses the first element of the subarray as the pivot. Two pointers move
 * toward each other from opposite ends of the subarray:
 * - The left pointer advances until it finds an element greater than the pivot.
 * - The right pointer retreats until it finds an element less than or equal
 *   to the pivot.
 *
 * When the pointers have not crossed, the out-of-place elements are swapped.
 * Once the pointers cross, the pivot is placed into its final sorted
 * position, and its index is returned.
 *
 * Example:
 * nums = {4, 6, 2, 5, 7, 9, 1, 3}
 *
 * After partitioning:
 * nums = {3, 1, 2, 4, 7, 9, 5, 6}
 *                ^
 *              Pivot
 *
 * The exact arrangement of elements on either side of the pivot may vary,
 * but:
 * - Every element to the left of the pivot is <= pivot.
 * - Every element to the right of the pivot is > pivot.
 *
 * Algorithm:
 * 1. Choose the first element as the pivot.
 * 2. Initialize two pointers:
 *    - l at the beginning of the subarray.
 *    - r at the end of the subarray.
 * 3. Move l forward while elements are <= pivot.
 * 4. Move r backward while elements are > pivot.
 * 5. Swap the out-of-place elements if l < r.
 * 6. When the pointers cross, swap the pivot with nums[r].
 * 7. Return r as the pivot's final position.
 *
 * Note:
 * - This implementation follows Hoare-style partitioning.
 * - The pivot is chosen as the first element.
 * - The partition operation is performed in-place.
 *
 * @param nums The input vector.
 * @param low Starting index of the subarray.
 * @param high Ending index of the subarray.
 * @return int The final index of the pivot.
 *
 * Time Complexity:
 * - Best/Average Case: O(n)
 * - Worst Case: O(n)
 *
 * Space Complexity: O(1)
 */
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

/**
 * @brief Sorts an array in ascending order using the Quick Sort algorithm.
 *
 * Quick Sort is a divide-and-conquer algorithm that recursively partitions
 * the array around a pivot. After partitioning, the pivot is in its final
 * sorted position, and the left and right subarrays are sorted
 * independently.
 *
 * Example:
 * nums = {10, 7, 8, 9, 1, 5}
 *
 * After execution:
 * nums = {1, 5, 7, 8, 9, 10}
 *
 * Algorithm:
 * 1. Partition the current subarray around a pivot.
 * 2. Recursively sort the left subarray.
 * 3. Recursively sort the right subarray.
 * 4. Repeat until each subarray contains at most one element.
 *
 * Note:
 * - Quick Sort is not a stable sorting algorithm.
 * - This implementation selects the first element as the pivot.
 * - Poor pivot selection can degrade performance to O(n²).
 *
 * @param nums The input vector of integers to be sorted.
 * @param low Starting index of the current subarray.
 * @param high Ending index of the current subarray.
 *
 * Time Complexity:
 * - Best Case: O(n log n)
 * - Average Case: O(n log n)
 * - Worst Case: O(n²)
 *
 * Space Complexity:
 * - Average Case: O(log n) (recursive call stack)
 * - Worst Case: O(n)
 */
void quickSort(vector<int> &nums, int low, int high) {
    if (low >= high)
        return;

    int pivot = partition(nums, low, high);

    quickSort(nums, low, pivot - 1);
    quickSort(nums, pivot + 1, high);
}