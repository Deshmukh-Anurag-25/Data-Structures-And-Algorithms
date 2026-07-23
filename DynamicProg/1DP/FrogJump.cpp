#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
using namespace std;

/**
 * @brief Computes the minimum energy required for a frog to reach the
 * last stone using space-optimized dynamic programming.
 *
 * The frog starts at the first stone and may jump:
 * - To the next stone (1 step).
 * - To the stone after next (2 steps).
 *
 * The energy required for a jump is the absolute difference between the
 * heights of the starting and destination stones.
 *
 * Example:
 * heights = {10, 20, 30, 10}
 *
 * Possible paths:
 * 10 → 20 → 30 → 10
 * Energy = 10 + 10 + 20 = 40
 *
 * 10 → 30 → 10
 * Energy = 20 + 20 = 40
 *
 * 10 → 20 → 10
 * Energy = 10 + 10 = 20
 *
 * Returns:
 * 20
 *
 * Algorithm:
 * 1. Let:
 *      prev  = minimum energy to reach the previous stone.
 *      prev2 = minimum energy to reach the stone before the previous one.
 * 2. For every stone:
 *      - Compute the cost of jumping from the previous stone.
 *      - Compute the cost of jumping from two stones behind.
 *      - Choose the minimum of the two.
 * 3. Update the previous states.
 * 4. Return the minimum energy required to reach the last stone.
 *
 * Note:
 * - Since each state depends only on the previous two states,
 *   the DP array can be replaced with two variables.
 *
 * @param heights Height of each stone.
 * @return int Minimum energy required to reach the last stone.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of stones.
 */
int frogJump(vector<int>& heights) {

    int n = heights.size();

    // Minimum energy to reach the previous stone.
    int prev = 0;

    // Minimum energy to reach the stone before the previous one.
    int prev2 = 0;

    for (int i = 1; i < n; i++) {

        // Jump from the previous stone.
        int firstStep =
            prev + abs(heights[i] - heights[i - 1]);

        // Jump from two stones behind.
        int secondStep = INT_MAX;

        if (i > 1) {
            secondStep =
                prev2 + abs(heights[i] - heights[i - 2]);
        }

        int current = min(firstStep, secondStep);

        prev2 = prev;
        prev = current;
    }

    return prev;
}