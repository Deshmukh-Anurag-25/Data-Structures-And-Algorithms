#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Computes the maximum amount of money that can be robbed without
 * robbing two adjacent houses.
 *
 * Each house contains a certain amount of money. If two adjacent houses
 * are robbed, the security system is triggered. Therefore, after robbing
 * a house, the next house cannot be robbed.
 *
 * Example:
 * nums = {2, 7, 9, 3, 1}
 *
 * Possible selections:
 * 2 + 9 + 1 = 12
 * 7 + 3 = 10
 * 2 + 9 = 11
 *
 * Returns:
 * 12
 *
 * Algorithm:
 * 1. Maintain two variables:
 *      prev  = maximum money that can be robbed up to the previous house.
 *      prev2 = maximum money that can be robbed up to the house before the
 *              previous house.
 * 2. For every house:
 *      - Rob the current house:
 *            current money + prev2
 *      - Skip the current house:
 *            prev
 *      - Store the maximum of the two choices.
 * 3. Update the previous states.
 * 4. Return the maximum money after processing all houses.
 *
 * Note:
 * - Since each state depends only on the previous two states,
 *   the DP array can be replaced by two variables.
 *
 * @param nums Money available in each house.
 * @return int Maximum amount of money that can be robbed.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of houses.
 */
int rob(vector<int>& nums) {

    int n = nums.size();

    // Maximum money that can be robbed up to the first house.
    int prev = nums[0];

    // Maximum money that can be robbed before the first house.
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