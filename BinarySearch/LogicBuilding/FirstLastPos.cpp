#include <vector>
using namespace std;

/**
 * @brief Finds the first or last occurrence of a target element in a sorted vector.
 *
 * Performs a modified binary search to locate either the first or the last
 * occurrence of the specified target. When the target is found, the search
 * continues in the appropriate half of the vector to locate the boundary
 * occurrence.
 *
 * Example:
 * nums = {5, 7, 7, 8, 8, 10}
 * target = 8
 *
 * search(nums, target, true)  returns 3
 * search(nums, target, false) returns 4
 *
 * Example:
 * nums = {1, 2, 3, 4}
 * target = 5
 *
 * Returns:
 * -1
 *
 * Algorithm:
 * 1. Perform a standard binary search.
 * 2. If the target is found:
 *    - Record its index.
 *    - If searching for the first occurrence, continue searching the left half.
 *    - Otherwise, continue searching the right half.
 * 3. Return the recorded index, or -1 if the target is absent.
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 * - Returns -1 if the target is not present.
 *
 * @param nums The sorted vector of integers.
 * @param target The value to search for.
 * @param isFirst If true, finds the first occurrence; otherwise, finds the last occurrence.
 * @return int The index of the requested occurrence, or -1 if not found.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int search(vector<int> &nums, int target, bool isFirst) {
    int left = 0, right = nums.size() - 1;
    int idx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            idx = mid;

            if (isFirst)
                right = mid - 1;
            else
                left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return idx;
}

/**
 * @brief Finds the first and last occurrences of a target element in a sorted vector.
 *
 * Uses the search() helper function twice:
 * - First to locate the first occurrence of the target.
 * - Then to locate the last occurrence.
 *
 * The returned vector contains the starting and ending indices of the
 * target's range. If the target is not present, both indices are -1.
 *
 * Example:
 * nums = {5, 7, 7, 8, 8, 10}
 * target = 8
 *
 * Returns:
 * {3, 4}
 *
 * Example:
 * nums = {5, 7, 7, 8, 8, 10}
 * target = 6
 *
 * Returns:
 * {-1, -1}
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 * - If the target occurs only once, both returned indices are the same.
 *
 * @param nums The sorted vector of integers.
 * @param target The value whose range is to be found.
 * @return vector<int> A vector containing the first and last occurrence
 *         indices of the target.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
vector<int> searchRange(vector<int> &nums, int target) {
    return {search(nums, target, true), search(nums, target, false)};
}