#include <vector>
using namespace std;

/**
 * @brief Sorts an array in ascending order using the Bubble Sort algorithm.
 *
 * Bubble Sort repeatedly traverses the array, compares adjacent elements,
 * and swaps them if they are in the wrong order. After each pass, the
 * largest unsorted element "bubbles" to its correct position at the end
 * of the array.
 *
 * This implementation includes an optimization that terminates early if
 * no swaps are performed during a pass, indicating that the array is
 * already sorted.
 *
 * Example:
 * nums = {5, 1, 4, 2, 8}
 *
 * After execution:
 * nums = {1, 2, 4, 5, 8}
 *
 * Example:
 * nums = {1, 2, 3, 4}
 *
 * After execution:
 * nums = {1, 2, 3, 4}
 *
 * The algorithm exits after the first pass because the array is already
 * sorted.
 *
 * Algorithm:
 * 1. Traverse the array multiple times.
 * 2. Compare every pair of adjacent elements.
 * 3. Swap them if they are in the wrong order.
 * 4. After each pass, the largest remaining element reaches its final
 *    position.
 * 5. If no swaps occur during a pass, terminate early.
 *
 * Note:
 * - Bubble Sort is a stable sorting algorithm.
 * - It performs well on nearly sorted arrays because of the early
 *   termination optimization.
 * - It is inefficient for large datasets compared to O(n log n)
 *   sorting algorithms such as Merge Sort or Quick Sort.
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
void bubbleSort(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        bool isSorted = true;

        for (int j = 1; j < n - i; j++) {
            if (nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                isSorted = false;
            }
        }

        if (isSorted)
            break;
    }
}