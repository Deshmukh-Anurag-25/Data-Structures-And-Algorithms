#include <vector>
using namespace std;

/**
 * @brief Stores the number of subsequences whose sum equals the target.
 */
int count = 0;

/**
 * @brief Recursively counts all subsequences whose sum equals the target.
 *
 * At every index, the function explores two possibilities:
 * - Include the current element in the subsequence.
 * - Exclude the current element.
 *
 * Whenever the running sum becomes equal to the target, the count is
 * incremented.
 *
 * @param index Current index being processed.
 * @param n Number of elements in the array.
 * @param nums Input array.
 * @param target Required subsequence sum.
 * @param sum Current sum of the chosen subsequence.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 * where:
 * - n = number of elements in the array.
 */
void helper(int index, int n, const vector<int>& nums, int target, int sum) {
    if (sum == target) {
        count++;
        return;
    }

    if (index >= n)
        return;

    helper(index + 1, n, nums, target, sum + nums[index]);
    helper(index + 1, n, nums, target, sum);
}

/**
 * @brief Counts the number of subsequences whose sum equals the given target.
 *
 * A subsequence is formed by selecting zero or more elements from the array
 * without changing their relative order.
 *
 * Example:
 * nums = {1, 2, 1}
 * target = 2
 *
 * Valid subsequences:
 * {2}
 * {1, 1}
 *
 * Returns:
 * 2
 *
 * Algorithm:
 * 1. Start with an empty subsequence and a running sum of 0.
 * 2. At each element:
 *    - Include the element.
 *    - Exclude the element.
 * 3. Count every subsequence whose sum equals the target.
 * 4. Return the total count.
 *
 * Note:
 * - This implementation explores all possible subsequences.
 * - It assumes non-negative numbers because it stops exploring once the
 *   target sum is reached.
 *
 * @param nums Input array.
 * @param target Required subsequence sum.
 * @return int Number of subsequences whose sum equals the target.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 * where:
 * - n = number of elements in the array.
 */
int countSubsequenceWithTargetSum(vector<int>& nums, int target) {
    count = 0;

    helper(0, nums.size(), nums, target, 0);

    return count;
}