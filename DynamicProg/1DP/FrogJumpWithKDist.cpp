#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
using namespace std;

/**
 * @brief Computes the minimum energy required for a frog to reach the
 * last stone when it can jump up to k stones at a time.
 *
 * The frog starts at the first stone and may jump to any of the next
 * k stones. The energy required for a jump is the absolute difference
 * between the heights of the starting and destination stones.
 *
 * Example:
 * heights = {10, 30, 40, 20}
 * k = 2
 *
 * Possible paths:
 * 10 → 30 → 40 → 20
 * Energy = 20 + 10 + 20 = 50
 *
 * 10 → 30 → 20
 * Energy = 20 + 10 = 30
 *
 * 10 → 40 → 20
 * Energy = 30 + 20 = 50
 *
 * Returns:
 * 30
 *
 * Algorithm:
 * 1. Let dp[i] represent the minimum energy required to reach the ith
 *    stone.
 * 2. Initialize:
 *      dp[0] = 0
 * 3. For every stone i:
 *      - Try every possible jump length from 1 to k.
 *      - If the previous stone exists, compute:
 *            dp[i-j] + |height[i] - height[i-j]|
 *      - Store the minimum among all possible jumps.
 * 4. Return dp[n - 1].
 *
 * Note:
 * - Unlike the classic Frog Jump problem, the frog is allowed to jump
 *   more than two stones.
 * - Every state considers at most k previous states.
 *
 * @param heights Height of each stone.
 * @param k Maximum jump length.
 * @return int Minimum energy required to reach the last stone.
 *
 * Time Complexity: O(n × k)
 * Space Complexity: O(n)
 * where:
 * - n = number of stones.
 * - k = maximum jump length.
 */
int frogJump(vector<int>& heights, int k) {

    int n = heights.size();

    // dp[i] = minimum energy required to reach stone i.
    vector<int> dp(n, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {

        int minimumEnergy = INT_MAX;

        // Try every possible jump length.
        for (int j = 1; j <= k; j++) {

            if (i - j >= 0) {

                int jumpEnergy =
                    dp[i - j] +
                    abs(heights[i] - heights[i - j]);

                minimumEnergy = min(minimumEnergy, jumpEnergy);
            }
        }

        dp[i] = minimumEnergy;
    }

    return dp[n - 1];
}