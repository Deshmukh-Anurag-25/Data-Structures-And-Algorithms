#include <vector>
using namespace std;

/**
 * @brief Computes the number of distinct ways to climb n stairs using
 * plain recursion.
 *
 * At each step, you have two choices:
 * - Climb 1 stair.
 * - Climb 2 stairs.
 *
 * The total number of ways to reach the nth stair is therefore the sum
 * of the ways to reach the previous two stairs.
 *
 * Example:
 * n = 3
 *
 * Possible ways:
 * 1 + 1 + 1
 * 1 + 2
 * 2 + 1
 *
 * Returns:
 * 3
 *
 * Algorithm:
 * 1. If n is 0 or 1, return 1.
 * 2. Recursively compute:
 *      ways(n) = ways(n - 1) + ways(n - 2)
 * 3. Return the total.
 *
 * Note:
 * - This solution recomputes many overlapping subproblems.
 * - It is mainly useful for understanding the recurrence relation.
 *
 * @param n Number of stairs.
 * @return int Number of distinct ways to reach the top.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 * where:
 * - n = number of stairs.
 */
int climbStairsRecursive(int n) {
    if (n <= 1)
        return 1;

    return climbStairsRecursive(n - 1) +
           climbStairsRecursive(n - 2);
}

/**
 * @brief Helper function for the memoization approach.
 *
 * The function stores previously computed results so that each state is
 * solved only once.
 *
 * @param n Current stair.
 * @param dp Memoization table.
 * @return int Number of ways to reach stair n.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int solveMemo(int n, vector<int>& dp) {
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = solveMemo(n - 1, dp) +
                   solveMemo(n - 2, dp);
}

/**
 * @brief Computes the number of distinct ways to climb n stairs using
 * recursion with memoization.
 *
 * Memoization avoids solving the same subproblem multiple times by
 * storing previously computed answers.
 *
 * Example:
 * n = 5
 *
 * Instead of recomputing ways(3), ways(2), etc., every value is computed
 * only once and reused whenever needed.
 *
 * Algorithm:
 * 1. Create a memoization array initialized with -1.
 * 2. Recursively compute the answer.
 * 3. Before solving a state, check whether it has already been computed.
 * 4. Store every computed answer for future use.
 *
 * Note:
 * - This converts the exponential recursive solution into a linear-time
 *   dynamic programming solution.
 *
 * @param n Number of stairs.
 * @return int Number of distinct ways to reach the top.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of stairs.
 */
int climbStairsMemoization(int n) {
    vector<int> dp(n + 1, -1);
    return solveMemo(n, dp);
}

/**
 * @brief Computes the number of distinct ways to climb n stairs using
 * bottom-up dynamic programming (tabulation).
 *
 * The DP array stores:
 * dp[i] = number of ways to reach the ith stair.
 *
 * Example:
 * n = 5
 *
 * dp:
 * 1 1 2 3 5 8
 *
 * Returns:
 * 8
 *
 * Algorithm:
 * 1. Initialize:
 *      dp[0] = 1
 *      dp[1] = 1
 * 2. Compute every remaining state using:
 *      dp[i] = dp[i - 1] + dp[i - 2]
 * 3. Return dp[n].
 *
 * Note:
 * - Every state depends only on the previous two states.
 *
 * @param n Number of stairs.
 * @return int Number of distinct ways to reach the top.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of stairs.
 */
int climbStairs(int n) {
    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/**
 * @brief Computes the number of distinct ways to climb n stairs using
 * space-optimized dynamic programming.
 *
 * Since every state depends only on the previous two states, the entire
 * DP array is unnecessary.
 *
 * Example:
 * n = 5
 *
 * prev2 = dp[0]
 * prev1 = dp[1]
 *
 * Iteration:
 * 2 → 2
 * 3 → 3
 * 4 → 5
 * 5 → 8
 *
 * Returns:
 * 8
 *
 * Algorithm:
 * 1. Store only the previous two DP states.
 * 2. Compute the current answer.
 * 3. Shift the previous values forward.
 * 4. Continue until reaching the nth stair.
 *
 * Note:
 * - This is the most space-efficient implementation.
 * - It produces the same result as tabulation while using constant space.
 *
 * @param n Number of stairs.
 * @return int Number of distinct ways to reach the top.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of stairs.
 */
int climbStairsOptimized(int n) {
    if (n <= 1)
        return 1;

    int prev2 = 1;
    int prev1 = 1;

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}