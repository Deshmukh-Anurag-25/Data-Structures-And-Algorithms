#include <vector>
using namespace std;

/**
 * @brief Sorts an array in ascending order using the Insertion Sort algorithm.
 *
 * Insertion Sort builds the sorted portion of the array one element at a
 * time. For each element, it shifts all larger elements in the sorted
 * portion one position to the right and inserts the current element into
 * its correct position.
 *
 * This algorithm is efficient for small datasets and nearly sorted arrays.
 *
 * Example:
 * nums = {5, 2, 4, 6, 1, 3}
 *
 * After execution:
 * nums = {1, 2, 3, 4, 5, 6}
 *
 * Example:
 * nums = {1, 2, 3, 4}
 *
 * After execution:
 * nums = {1, 2, 3, 4}
 *
 * Algorithm:
 * 1. Treat the first element as a sorted subarray.
 * 2. Iterate through the remaining elements.
 * 3. Store the current element (pivot).
 * 4. Shift all larger elements in the sorted portion one position to the
 *    right.
 * 5. Insert the pivot into its correct position.
 * 6. Repeat until all elements have been processed.
 *
 * Note:
 * - Insertion Sort is a stable sorting algorithm.
 * - It is adaptive, performing well on nearly sorted arrays.
 * - It sorts the array in-place without requiring additional memory.
 *
 * @param nums The input vector of integers to be sorted.
 *
 * Time Complexity:
 * - Best Case: O(n)
 * - Average Case: O(n²)
 * - Worst Case: O(n²)
 *
 * Space Complexity: O(1)
 */
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