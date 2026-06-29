#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Finds the maximum sum of a contiguous subarray.
 *
 * Uses Kadane's Algorithm to determine the maximum possible sum of any
 * contiguous subarray in a single traversal. At each step, the algorithm
 * decides whether to extend the current subarray or start a new one from
 * the current element.
 *
 * Example:
 * nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}
 *
 * Returns:
 * 6
 * Explanation:
 * The subarray {4, -1, 2, 1} has the maximum sum of 6.
 *
 * Example:
 * nums = {1}
 *
 * Returns:
 * 1
 *
 * Example:
 * nums = {-3, -2, -5}
 *
 * Returns:
 * -2
 *
 * Algorithm:
 * 1. Initialize the current sum and maximum sum with the first element.
 * 2. For each subsequent element:
 *    - Either extend the current subarray or start a new one.
 *    - Update the maximum sum found so far.
 *
 * Note:
 * - The input vector must contain at least one element.
 * - The function correctly handles arrays containing all negative values.
 *
 * @param nums The input vector of integers.
 * @return int The maximum sum of any contiguous subarray.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxSubarray(vector<int> &nums) {
    int n = nums.size();
    int sum = nums[0], maxSum = nums[0];

    for (int i = 1; i < n; i++) {
        sum = max(nums[i], sum + nums[i]);
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}