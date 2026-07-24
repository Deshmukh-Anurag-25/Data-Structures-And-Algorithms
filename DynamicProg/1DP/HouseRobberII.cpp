#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Computes the maximum amount of money that can be robbed from a
 * linear arrangement of houses.
 *
 * Two adjacent houses cannot be robbed because doing so would trigger the
 * security system.
 *
 * The function uses space-optimized dynamic programming where:
 * - prev  = maximum money that can be robbed up to the previous house.
 * - prev2 = maximum money that can be robbed up to the house before the
 *           previous house.
 *
 * @param nums Money available in each house arranged in a straight line.
 * @return int Maximum amount of money that can be robbed.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int hr1(vector<int>& nums) {

    int n = nums.size();

    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++) {

        // Rob the current house.
        int take = nums[i];

        if (i > 1)
            take += prev2;

        // Skip the current house.
        int notTake = prev;

        int current = max(take, notTake);

        prev2 = prev;
        prev = current;
    }

    return prev;
}

/**
 * @brief Computes the maximum amount of money that can be robbed from
 * houses arranged in a circle.
 *
 * Unlike the original House Robber problem, the first and last houses are
 * adjacent. Therefore, both cannot be robbed together.
 *
 * The problem is divided into two independent linear House Robber
 * problems:
 *
 * 1. Ignore the first house.
 * 2. Ignore the last house.
 *
 * The larger of the two answers is the optimal solution.
 *
 * Example:
 * nums = {2, 3, 2}
 *
 * Case 1:
 * {3, 2}
 * Maximum = 3
 *
 * Case 2:
 * {2, 3}
 * Maximum = 3
 *
 * Returns:
 * 3
 *
 * Example:
 * nums = {1, 2, 3, 1}
 *
 * Case 1:
 * {2, 3, 1} → 3
 *
 * Case 2:
 * {1, 2, 3} → 4
 *
 * Returns:
 * 4
 *
 * Algorithm:
 * 1. If there is only one house, return its value.
 * 2. Create two arrays:
 *      - One excluding the first house.
 *      - One excluding the last house.
 * 3. Solve the linear House Robber problem for both arrays.
 * 4. Return the larger answer.
 *
 * Note:
 * - Since the first and last houses are adjacent, every valid solution
 *   must exclude one of them.
 *
 * @param nums Money available in each house.
 * @return int Maximum amount of money that can be robbed.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of houses.
 */
int rob(vector<int>& nums) {

    int n = nums.size();

    // Only one house exists.
    if (n == 1)
        return nums[0];

    vector<int> excludeFirst;
    vector<int> excludeLast;

    for (int i = 0; i < n; i++) {

        if (i != 0)
            excludeFirst.push_back(nums[i]);

        if (i != n - 1)
            excludeLast.push_back(nums[i]);
    }

    return max(hr1(excludeFirst), hr1(excludeLast));
}