#include <cmath>
#include <vector>
using namespace std;

/**
 * @brief Finds the repeating and missing numbers in an array.
 *
 * Given an array containing integers from 1 to n, exactly one number
 * appears twice (the repeating number) and exactly one number is missing.
 *
 * The algorithm uses the sign-marking technique by treating the array as a
 * hash table. Each visited value marks its corresponding index as negative.
 * If an index is encountered that is already negative, the corresponding
 * value is the repeating number. A second traversal identifies the index
 * that was never marked, which corresponds to the missing number.
 *
 * Example:
 * nums = {3, 1, 2, 5, 3}
 *
 * Returns:
 * {3, 4}
 *
 * Explanation:
 * - 3 appears twice.
 * - 4 is missing.
 *
 * Example:
 * nums = {1, 2, 2, 4}
 *
 * Returns:
 * {2, 3}
 *
 * Algorithm:
 * 1. Traverse the array.
 * 2. For each value x:
 *    - Compute index = |x| - 1.
 *    - If nums[index] is already negative, x is the repeating number.
 *    - Otherwise, negate nums[index] to mark x as visited.
 * 3. Traverse the array again.
 * 4. The first positive element indicates the missing number.
 * 5. Return {repeating, missing}.
 *
 * Note:
 * - The input array is modified during execution.
 * - If the original array must be preserved, create a copy before calling
 *   this function.
 * - The returned vector contains:
 *      ans[0] = repeating number
 *      ans[1] = missing number
 *
 * @param nums The input vector containing numbers from 1 to n.
 * @return vector<int> A vector containing the repeating and missing
 *         numbers in the order {repeating, missing}.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
vector<int> findMissingRepeatingNumber(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans;

    // Find the repeating number.
    for (int i = 0; i < n; i++) {
        int idx = abs(nums[i]) - 1;

        if (nums[idx] < 0) {
            ans.push_back(idx + 1);
        } else {
            nums[idx] *= -1;
        }
    }

    // Find the missing number.
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            ans.push_back(i + 1);
        }
    }

    return ans;
}