#include <vector>
using namespace std;

/**
 * @brief Recursively determines whether a subsequence with the target sum exists.
 *
 * The function explores every possible subsequence using recursion. At each
 * index, it has two choices:
 * - Include the current element in the subsequence.
 * - Exclude the current element.
 *
 * If the running sum becomes equal to the target, the function immediately
 * returns true. If all elements have been processed or the running sum
 * exceeds the target, the current path is abandoned.
 *
 * @param index Current index being processed.
 * @param n Total number of elements.
 * @param target Required subsequence sum.
 * @param nums Input array.
 * @param sum Current sum of the chosen subsequence.
 * @return bool True if a valid subsequence exists; otherwise false.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 * where:
 * - n = number of elements in the array.
 */
bool helper(int index, int n, int target, vector<int> nums, int sum) {
    if (sum == target)
        return true;

    if (index >= n || sum > target)
        return false;

    if (helper(index + 1, n, target, nums, sum + nums[index]))
        return true;

    return helper(index + 1, n, target, nums, sum);
}

/**
 * @brief Checks whether there exists a subsequence whose sum equals the
 * given target.
 *
 * A subsequence is formed by selecting zero or more elements from the array
 * without changing their relative order.
 *
 * Example:
 * nums = {1, 2, 3, 4}
 * target = 6
 *
 * Valid subsequence:
 * {2, 4}
 *
 * Returns:
 * true
 *
 * Example:
 * nums = {5, 2, 7}
 * target = 6
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. Start from the first element with a running sum of 0.
 * 2. At every index:
 *    - Include the current element.
 *    - Exclude the current element.
 * 3. If the running sum equals the target, return true.
 * 4. If all possibilities are exhausted, return false.
 *
 * Note:
 * - This implementation assumes all array elements are non-negative because
 *   of the pruning condition (sum > target).
 * - If negative numbers are allowed, the pruning condition should be removed.
 *
 * @param nums Input array.
 * @param target Required subsequence sum.
 * @return bool True if such a subsequence exists; otherwise false.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 * where:
 * - n = number of elements in the array.
 */
bool checkSubsequenceSum(vector<int>& nums, int target) {
    int n = nums.size();
    return helper(0, n, target, nums, 0);
}