#include <vector>
using namespace std;

/**
 * @brief Finds the single non-duplicate element in a sorted vector.
 *
 * Given a sorted vector where every element appears exactly twice except
 * for one element that appears only once, this function returns the unique
 * element using binary search.
 *
 * The algorithm leverages the fact that:
 * - Before the unique element, pairs begin at even indices.
 * - After the unique element, pairs begin at odd indices.
 *
 * By examining the parity of the middle index and its neighboring elements,
 * the search space is halved in each iteration.
 *
 * Example:
 * nums = {1, 1, 2, 3, 3, 4, 4, 8, 8}
 *
 * Returns:
 * 2
 *
 * Example:
 * nums = {3, 3, 7, 7, 10, 11, 11}
 *
 * Returns:
 * 10
 *
 * Algorithm:
 * 1. Handle edge cases where the unique element is at the beginning,
 *    end, or the vector contains only one element.
 * 2. Perform binary search on indices [1, n - 2].
 * 3. If nums[mid] differs from both neighbors, it is the answer.
 * 4. Otherwise, use the parity of mid and pair alignment to determine
 *    which half contains the unique element.
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 * - Exactly one element appears once, while every other element appears
 *   exactly twice.
 *
 * @param nums The sorted vector of integers.
 * @return int The single non-duplicate element, or -1 if no such element exists.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int singleNonDuplicate(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

    int left = 1, right = n - 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
            return nums[mid];

        if ((mid % 2 != 0 && nums[mid - 1] == nums[mid]) ||
            (mid % 2 == 0 && nums[mid] != nums[mid - 1])) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}