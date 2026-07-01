#include <vector>
using namespace std;

/**
 * @brief Finds the upper bound of a target value in a sorted vector.
 *
 * Performs an iterative binary search to locate the first element that is
 * strictly greater than the specified target. If such an element exists,
 * its index is returned; otherwise, the function returns -1.
 *
 * Example:
 * nums = {1, 2, 4, 4, 5, 7}
 * x = 4
 *
 * Returns:
 * 4
 *
 * Explanation:
 * nums[4] = 5 is the first element greater than 4.
 *
 * Example:
 * nums = {1, 2, 4, 4, 5, 7}
 * x = 6
 *
 * Returns:
 * 5
 *
 * Explanation:
 * nums[5] = 7 is the first element greater than 6.
 *
 * Example:
 * nums = {1, 2, 3}
 * x = 5
 *
 * Returns:
 * -1
 *
 * Algorithm:
 * 1. Initialize low, high, and answer index.
 * 2. Repeatedly divide the search space in half.
 * 3. If the middle element is greater than the target:
 *    - Record its index as a potential answer.
 *    - Continue searching the left half.
 * 4. Otherwise, search the right half.
 * 5. Return the recorded index if found; otherwise, return -1.
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 * - This implementation differs from std::upper_bound:
 *   - std::upper_bound returns nums.size() if no valid element exists.
 *   - This function returns -1 instead.
 *
 * @param nums The sorted vector of integers.
 * @param x The target value.
 * @return int The index of the first element strictly greater than x,
 *         or -1 if no such element exists.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int upperBound(vector<int> &nums, int x) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int idx = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > x) {
            idx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return idx;
}