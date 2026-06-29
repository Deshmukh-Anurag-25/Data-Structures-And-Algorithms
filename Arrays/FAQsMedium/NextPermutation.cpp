#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Transforms a vector into its next lexicographically greater permutation.
 *
 * Rearranges the elements of the vector to produce the next permutation in
 * lexicographical order. If the current arrangement is already the largest
 * possible permutation, the vector is rearranged into the smallest
 * permutation (ascending order).
 *
 * The algorithm works as follows:
 * 1. Find the rightmost element that is smaller than its next element
 *    (the pivot).
 * 2. If no such element exists, reverse the entire vector.
 * 3. Otherwise, find the smallest element to the right of the pivot that
 *    is greater than the pivot.
 * 4. Swap the pivot with that element.
 * 5. Reverse the suffix following the pivot.
 *
 * Example:
 * nums = {1, 2, 3}
 *
 * After modification:
 * {1, 3, 2}
 *
 * Example:
 * nums = {3, 2, 1}
 *
 * After modification:
 * {1, 2, 3}
 *
 * Example:
 * nums = {1, 1, 5}
 *
 * After modification:
 * {1, 5, 1}
 *
 * Note:
 * - The permutation is modified in-place.
 * - Duplicate elements are handled correctly.
 *
 * @param nums The vector of integers representing the current permutation.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void nextPremutation(vector<int> &nums) {
    int n = nums.size();
    int pivot = -1;

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }

    if (pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int j = n - 1;

    while (j > pivot) {
        if (nums[j] > nums[pivot]) {
            swap(nums[j], nums[pivot]);
            break;
        }
        j--;
    }

    reverse(nums.begin() + pivot + 1, nums.end());
}