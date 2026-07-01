#include <vector>
using namespace std;

/**
 * @brief Finds the index of a target element or its insertion position in a
 *        sorted vector.
 *
 * Performs an iterative binary search to locate the target element. If the
 * target exists, its index is returned. Otherwise, the function returns the
 * index where the target should be inserted to maintain the sorted order of
 * the vector.
 *
 * Example:
 * nums = {1, 3, 5, 6}
 * target = 5
 *
 * Returns:
 * 2
 *
 * Example:
 * nums = {1, 3, 5, 6}
 * target = 2
 *
 * Returns:
 * 1
 *
 * Example:
 * nums = {1, 3, 5, 6}
 * target = 7
 *
 * Returns:
 * 4
 *
 * Example:
 * nums = {1, 3, 5, 6}
 * target = 0
 *
 * Returns:
 * 0
 *
 * Algorithm:
 * 1. Initialize two pointers, left and right.
 * 2. Perform binary search while left <= right.
 * 3. If the target is found, return its index.
 * 4. Otherwise, narrow the search space.
 * 5. When the search ends, left points to the correct insertion position.
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 * - If the target is not present, the returned index indicates where it
 *   should be inserted while preserving the sorted order.
 *
 * @param nums The sorted vector of integers.
 * @param target The value to search for or insert.
 * @return int The index of the target if found; otherwise, the insertion index.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}