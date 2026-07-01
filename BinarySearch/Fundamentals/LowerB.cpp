#include <vector>
using namespace std;

/**
 * @brief Finds the lower bound of a target value in a sorted vector.
 *
 * Performs an iterative binary search to locate the first element that is
 * greater than or equal to the specified target. If such an element exists,
 * its index is returned; otherwise, the function returns -1.
 *
 * Example:
 * nums = {1, 2, 4, 4, 5, 7}
 * x = 4
 *
 * Returns:
 * 2
 *
 * Explanation:
 * nums[2] is the first element that is greater than or equal to 4.
 *
 * Example:
 * nums = {1, 2, 4, 4, 5, 7}
 * x = 6
 *
 * Returns:
 * 5
 *
 * Explanation:
 * nums[5] = 7 is the first element greater than or equal to 6.
 *
 * Example:
 * nums = {1, 2, 3}
 * x = 5
 *
 * Returns:
 * -1
 *
 * Algorithm:
 * 1. Initialize low, high, and idx.
 * 2. Compute the middle index.
 * 3. If nums[mid] >= x:
 *    - Store mid as a potential answer.
 *    - Continue searching the left half for an earlier occurrence.
 * 4. Otherwise, search the right half.
 * 5. Return the recorded index if found; otherwise, return -1.
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 * - Unlike std::lower_bound, this implementation returns -1 if no element
 *   is greater than or equal to x. The STL version would return nums.size().
 *
 * @param nums The sorted vector of integers.
 * @param x The target value.
 * @return int The index of the first element greater than or equal to x,
 *         or -1 if no such element exists.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int lowerBound(vector<int>& nums, int x) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int idx = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= x) {
            idx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return idx;
}