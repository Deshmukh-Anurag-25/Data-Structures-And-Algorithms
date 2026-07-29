#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Solves the Best Time to Buy and Sell Stock IV problem using
 * recursion with memoization.
 *
 * The state of the recursion is defined by:
 * - idx  : Current day.
 * - buy  : Whether buying is allowed.
 *           - 1 → Can buy.
 *           - 0 → Must sell or skip.
 * - k    : Number of remaining transactions.
 *
 * A transaction consists of one buy followed by one sell.
 *
 * At every state:
 * - If buying is allowed:
 *      1. Buy the stock.
 *      2. Skip the current day.
 *
 * - If holding a stock:
 *      1. Sell the stock (consumes one transaction).
 *      2. Skip the current day.
 *
 * Memoization ensures each state is computed only once.
 *
 * @param idx Current day.
 * @param buy Buying state.
 * @param k Remaining transactions.
 * @param prices Daily stock prices.
 * @param dp Memoization table.
 * @return int Maximum profit from the current state.
 *
 * Time Complexity: O(n × 2 × k)
 * Space Complexity: O(n × 2 × k) + O(n)
 */
int solve(int idx,
          int buy,
          int k,
          vector<int>& prices,
          vector<vector<vector<int>>>& dp) {

    int n = prices.size();

    // No days or no transactions left.
    if (idx == n || k == 0)
        return 0;

    if (dp[idx][buy][k] != -1)
        return dp[idx][buy][k];

    int profit = 0;

    if (buy) {

        profit = max(
            -prices[idx] + solve(idx + 1, 0, k, prices, dp),
            solve(idx + 1, 1, k, prices, dp));

    } else {

        profit = max(
            prices[idx] + solve(idx + 1, 1, k - 1, prices, dp),
            solve(idx + 1, 0, k, prices, dp));
    }

    return dp[idx][buy][k] = profit;
}

/**
 * @brief Computes the maximum profit obtainable with at most k
 * buy-sell transactions using space-optimized dynamic programming.
 *
 * A transaction consists of:
 * - Buy one stock.
 * - Sell the same stock.
 *
 * Multiple transactions are allowed, but only one stock may be held
 * at any given time.
 *
 * Example:
 * Prices:
 * 3 2 6 5 0 3
 *
 * k = 2
 *
 * Optimal transactions:
 * Buy at 2 → Sell at 6  (Profit = 4)
 * Buy at 0 → Sell at 3  (Profit = 3)
 *
 * Maximum Profit:
 * 7
 *
 * Algorithm:
 * 1. Process the days from right to left.
 * 2. Maintain two DP tables:
 *      - ahead → DP values for the next day.
 *      - curr  → DP values for the current day.
 * 3. For every day:
 *      - Compute both buying and selling states.
 *      - Update all possible remaining transaction counts.
 * 4. Copy the current day's results into the next-day table.
 * 5. The answer is the profit on day 0 when buying is allowed with
 *    k transactions remaining.
 *
 * State:
 * dp[buy][transactions]
 *
 * where:
 * - buy = 1 → Can buy.
 * - buy = 0 → Holding a stock (must sell or skip).
 *
 * Note:
 * - Only the next day's DP states are required, allowing the DP table
 *   to be reduced from O(n × 2 × k) to O(2 × k).
 *
 * @param k Maximum number of transactions allowed.
 * @param prices Daily stock prices.
 * @return int Maximum achievable profit.
 *
 * Time Complexity: O(n × k)
 * Space Complexity: O(k)
 * where:
 * - n = number of days.
 * - k = maximum allowed transactions.
 */
int maxProfit(int k, vector<int>& prices) {

    int n = prices.size();

    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));

    // Process days from last to first.
    for (int i = n - 1; i >= 0; i--) {

        for (int buy = 0; buy <= 1; buy++) {

            for (int transactions = 1; transactions <= k; transactions++) {

                int profit = 0;

                if (buy) {

                    profit = max(
                        -prices[i] + ahead[0][transactions],
                        ahead[1][transactions]);

                } else {

                    profit = max(
                        prices[i] + ahead[1][transactions - 1],
                        ahead[0][transactions]);
                }

                curr[buy][transactions] = profit;
            }
        }

        ahead = curr;
    }

    return ahead[1][k];

    // Memoization solution:
    // vector<vector<vector<int>>> dp(
    //     n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    // return solve(0, 1, k, prices, dp);
}