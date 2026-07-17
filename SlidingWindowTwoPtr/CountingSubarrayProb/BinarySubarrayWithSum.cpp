#include <vector>
using namespace std;

/**
 * @brief Counts the number of subarrays whose sum is less than or equal to
 * the given goal.
 *
 * The function uses the sliding window technique.
 *
 * Since the array contains only binary values (0 and 1), increasing the
 * right pointer can only increase the window sum, allowing the left pointer
 * to shrink the window whenever the sum exceeds the goal.
 *
 * For every valid window ending at index `right`, all subarrays starting
 * between `left` and `right` are also valid.
 *
 * Example:
 * nums = {1, 0, 1}
 * goal = 2
 *
 * Valid subarrays ending at each position are counted using:
 * (right - left + 1)
 *
 * @param nums Binary input array.
 * @param goal Maximum allowed subarray sum.
 * @return int Number of subarrays whose sum is less than or equal to goal.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of elements in the array.
 */
int countSubarray(vector<int>& nums, int goal) {

    // No subarray can have a negative sum.
    if (goal < 0)
        return 0;

    int left = 0;
    int right = 0;
    int sum = 0;
    int count = 0;

    while (right < nums.size()) {

        // Expand the window.
        sum += nums[right];

        // Shrink the window until it becomes valid.
        while (sum > goal) {
            sum -= nums[left];
            left++;
        }

        // Count all valid subarrays ending at 'right'.
        count += (right - left + 1);

        right++;
    }

    return count;
}

/**
 * @brief Counts the number of subarrays whose sum is exactly equal to the
 * given goal.
 *
 * Instead of directly counting subarrays with sum = goal, the solution uses
 * the following identity:
 *
 * Exactly(goal) =
 *     AtMost(goal) − AtMost(goal − 1)
 *
 * where:
 * - AtMost(goal) counts all subarrays having sum ≤ goal.
 * - AtMost(goal − 1) removes those whose sum is smaller than the target.
 *
 * Example:
 * nums = {1, 0, 1, 0, 1}
 * goal = 2
 *
 * Valid subarrays:
 * {1,0,1}
 * {1,0,1,0}
 * {0,1,0,1}
 * {1,0,1}
 *
 * Returns:
 * 4
 *
 * Algorithm:
 * 1. Count subarrays with sum ≤ goal.
 * 2. Count subarrays with sum ≤ goal − 1.
 * 3. Their difference equals the number of subarrays whose sum is exactly
 *    equal to goal.
 *
 * Note:
 * - This approach works because the array contains only binary values.
 * - The sliding window technique is not valid for arbitrary integers
 *   containing negative numbers.
 *
 * @param nums Binary input array.
 * @param goal Required subarray sum.
 * @return int Number of subarrays whose sum equals the goal.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of elements in the array.
 */
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return countSubarray(nums, goal) -
           countSubarray(nums, goal - 1);
}