#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Recursively computes the maximum profit obtainable from stock
 * trading with at most two transactions using memoization.
 *
 * A transaction consists of:
 * - Buying one stock.
 * - Selling that stock later.
 *
 * At every day, three pieces of information define the DP state:
 * - idx  → Current trading day.
 * - buy  → Whether buying is currently allowed.
 * - cap  → Number of transactions remaining.
 *
 * The function explores every valid choice and stores previously
 * computed states to avoid repeated calculations.
 *
 * @param idx Current trading day.
 * @param buy Indicates whether buying is allowed.
 * @param cap Remaining number of transactions.
 * @param prices Stock prices.
 * @param dp Three-dimensional memoization table.
 * @return int Maximum profit obtainable from the current state.
 *
 * Time Complexity: O(n × 2 × 3)
 * Space Complexity: O(n × 2 × 3) + O(n)
 * where:
 * - n = number of trading days.
 */
int solve(int idx,
          int buy,
          int cap,
          vector<int>& prices,
          vector<vector<vector<int>>>& dp) {

    int n = prices.size();

    // No days or transactions remaining.
    if (idx == n || cap == 0)
        return 0;

    if (dp[idx][buy][cap] != -1)
        return dp[idx][buy][cap];

    int profit = 0;

    if (buy) {

        // Buy today or skip.
        profit = max(
            -prices[idx] + solve(idx + 1, 0, cap, prices, dp),
            solve(idx + 1, 1, cap, prices, dp));
    }
    else {

        // Sell today or skip.
        profit = max(
            prices[idx] + solve(idx + 1, 1, cap - 1, prices, dp),
            solve(idx + 1, 0, cap, prices, dp));
    }

    return dp[idx][buy][cap] = profit;
}

/**
 * @brief Computes the maximum profit obtainable with at most two stock
 * transactions using space-optimized dynamic programming.
 *
 * A transaction consists of one buy followed by one sell.
 * At most two complete transactions are allowed.
 *
 * Example:
 * Prices:
 * 3 3 5 0 0 3 1 4
 *
 * One optimal strategy:
 * Buy at 0 → Sell at 3 = 3
 * Buy at 1 → Sell at 4 = 3
 *
 * Total Profit:
 * 6
 *
 * Algorithm:
 * 1. Process the prices from the last day to the first.
 * 2. Maintain three DP dimensions:
 *      - day
 *      - buy (0 or 1)
 *      - remaining transactions (1 or 2)
 * 3. For every state:
 *      If buying is allowed:
 *          max(-price + nextSellState,
 *              skip)
 *      Otherwise:
 *          max(price + nextBuyStateAfterUsingOneTransaction,
 *              skip)
 * 4. Since every state depends only on the next day, keep only two
 *    2 × 3 DP tables.
 * 5. Return the state representing:
 *      Day 0,
 *      Buying allowed,
 *      Two transactions remaining.
 *
 * Note:
 * - A transaction is counted only after selling.
 * - Buying does not decrease the remaining transaction count.
 *
 * @param prices Array containing the stock price for each day.
 * @return int Maximum profit obtainable.
 *
 * Time Complexity: O(n × 2 × 2) ≈ O(n)
 * Space Complexity: O(2 × 3) ≈ O(1)
 * where:
 * - n = number of trading days.
 */
int maxProfit(vector<int>& prices) {

    int n = prices.size();

    // DP table for the next day.
    vector<vector<int>> next(2, vector<int>(3, 0));

    // DP table for the current day.
    vector<vector<int>> current(2, vector<int>(3, 0));

    for (int day = n - 1; day >= 0; day--) {

        for (int buy = 0; buy <= 1; buy++) {

            for (int transactions = 1; transactions <= 2; transactions++) {

                if (buy) {

                    current[buy][transactions] = max(
                        -prices[day] + next[0][transactions],
                        next[1][transactions]);
                }
                else {

                    current[buy][transactions] = max(
                        prices[day] + next[1][transactions - 1],
                        next[0][transactions]);
                }
            }
        }

        next = current;
    }

    return next[1][2];
}