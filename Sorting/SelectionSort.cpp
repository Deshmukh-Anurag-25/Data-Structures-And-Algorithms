#include <vector>
using namespace std;

/**
 * @brief Sorts an array in ascending order using the Selection Sort algorithm.
 *
 * Selection Sort repeatedly selects the smallest element from the unsorted
 * portion of the array and places it at the beginning of the unsorted
 * region. After each pass, the sorted portion of the array grows by one
 * element.
 *
 * Unlike Bubble Sort, Selection Sort performs at most one swap per pass,
 * making it useful when the cost of swapping is high.
 *
 * Example:
 * nums = {64, 25, 12, 22, 11}
 *
 * After execution:
 * nums = {11, 12, 22, 25, 64}
 *
 * Example:
 * nums = {5, 4, 3, 2, 1}
 *
 * After execution:
 * nums = {1, 2, 3, 4, 5}
 *
 * Algorithm:
 * 1. Divide the array into a sorted and an unsorted region.
 * 2. Find the smallest element in the unsorted region.
 * 3. Swap it with the first element of the unsorted region.
 * 4. Expand the sorted region by one element.
 * 5. Repeat until the entire array is sorted.
 *
 * Note:
 * - Selection Sort is not a stable sorting algorithm.
 * - It always performs O(n²) comparisons, regardless of the initial order
 *   of the input.
 * - It performs at most (n - 1) swaps, which is fewer than Bubble Sort.
 *
 * @param nums The input vector of integers to be sorted.
 *
 * Time Complexity:
 * - Best Case: O(n²)
 * - Average Case: O(n²)
 * - Worst Case: O(n²)
 *
 * Space Complexity: O(1)
 */
void selectionSort(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int mini = i;

        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[mini]) {
                mini = j;
            }
        }

        if (i != mini)
            swap(nums[i], nums[mini]);
    }
}