#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Recursively computes the maximum profit obtainable from stock
 * trading with unlimited transactions using memoization.
 *
 * At every day, there are two possible states:
 * - buy = 1 → A stock can be bought.
 * - buy = 0 → A stock is currently held and can be sold.
 *
 * At each state, the algorithm decides whether to perform the current
 * transaction or skip the day.
 *
 * The computed results are stored in the DP table so that every state
 * (day, buy) is solved only once.
 *
 * @param idx Current trading day.
 * @param buy Indicates whether buying is currently allowed.
 * @param prices Stock prices.
 * @param n Number of trading days.
 * @param dp Memoization table.
 * @return int Maximum profit obtainable from the current state.
 *
 * Time Complexity: O(n × 2)
 * Space Complexity: O(n × 2) + O(n)
 * where:
 * - n = number of trading days.
 */
int solve(int idx,
          int buy,
          vector<int>& prices,
          int& n,
          vector<vector<int>>& dp) {

    // No days remaining.
    if (idx == n)
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    int profit = 0;

    if (buy) {

        // Buy today or skip.
        profit = max(
            -prices[idx] + solve(idx + 1, 0, prices, n, dp),
            solve(idx + 1, 1, prices, n, dp));
    }
    else {

        // Sell today or skip.
        profit = max(
            prices[idx] + solve(idx + 1, 1, prices, n, dp),
            solve(idx + 1, 0, prices, n, dp));
    }

    return dp[idx][buy] = profit;
}

/**
 * @brief Computes the maximum profit obtainable with unlimited stock
 * transactions using constant-space dynamic programming.
 *
 * You may complete as many buy-sell transactions as desired, provided
 * that you sell the current stock before buying another one.
 *
 * Example:
 * Prices:
 * 7 1 5 3 6 4
 *
 * Transactions:
 * Buy at 1 → Sell at 5 = 4
 * Buy at 3 → Sell at 6 = 3
 *
 * Total Profit:
 * 7
 *
 * Algorithm:
 * 1. Process the prices from the last day to the first.
 * 2. Maintain two DP states:
 *      - dpBuy     → Maximum profit when buying is allowed.
 *      - dpNotBuy  → Maximum profit when a stock is currently held.
 * 3. For every day:
 *      - Compute the profit for the "sell/hold" state.
 *      - Compute the profit for the "buy/skip" state.
 * 4. Update the DP states for the next iteration.
 * 5. Return the profit when buying is initially allowed.
 *
 * Note:
 * - Only the next day's DP states are required.
 * - The solution therefore uses four integer variables instead of
 *   arrays, reducing the auxiliary space to O(1).
 *
 * @param prices Array containing the stock price for each day.
 * @param n Number of trading days.
 * @return int Maximum profit obtainable.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of trading days.
 */
int stockBuySell(vector<int> prices, int n) {

    // DP values for the next day.
    int dpBuy = 0;
    int dpNotBuy = 0;

    // DP values for the current day.
    int currentBuy = 0;
    int currentNotBuy = 0;

    for (int day = n - 1; day >= 0; day--) {

        // State when a stock is currently held.
        currentNotBuy = max(
            prices[day] + dpBuy,
            dpNotBuy);

        // State when buying is allowed.
        currentBuy = max(
            -prices[day] + dpNotBuy,
            dpBuy);

        dpBuy = currentBuy;
        dpNotBuy = currentNotBuy;
    }

    return dpBuy;
}

#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Recursively computes the maximum profit obtainable from stock
 * trading with unlimited transactions using memoization.
 *
 * At every day, there are two possible states:
 * - buy = 1 → A stock can be bought.
 * - buy = 0 → A stock is currently held and can be sold.
 *
 * At each state, the algorithm decides whether to perform the current
 * transaction or skip the day.
 *
 * The computed results are stored in the DP table so that every state
 * (day, buy) is solved only once.
 *
 * @param idx Current trading day.
 * @param buy Indicates whether buying is currently allowed.
 * @param prices Stock prices.
 * @param n Number of trading days.
 * @param dp Memoization table.
 * @return int Maximum profit obtainable from the current state.
 *
 * Time Complexity: O(n × 2)
 * Space Complexity: O(n × 2) + O(n)
 * where:
 * - n = number of trading days.
 */
int solve(int idx,
          int buy,
          vector<int>& prices,
          int& n,
          vector<vector<int>>& dp) {

    // No days remaining.
    if (idx == n)
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    int profit = 0;

    if (buy) {

        // Buy today or skip.
        profit = max(
            -prices[idx] + solve(idx + 1, 0, prices, n, dp),
            solve(idx + 1, 1, prices, n, dp));
    }
    else {

        // Sell today or skip.
        profit = max(
            prices[idx] + solve(idx + 1, 1, prices, n, dp),
            solve(idx + 1, 0, prices, n, dp));
    }

    return dp[idx][buy] = profit;
}

/**
 * @brief Computes the maximum profit obtainable with unlimited stock
 * transactions using constant-space dynamic programming.
 *
 * You may complete as many buy-sell transactions as desired, provided
 * that you sell the current stock before buying another one.
 *
 * Example:
 * Prices:
 * 7 1 5 3 6 4
 *
 * Transactions:
 * Buy at 1 → Sell at 5 = 4
 * Buy at 3 → Sell at 6 = 3
 *
 * Total Profit:
 * 7
 *
 * Algorithm:
 * 1. Process the prices from the last day to the first.
 * 2. Maintain two DP states:
 *      - dpBuy     → Maximum profit when buying is allowed.
 *      - dpNotBuy  → Maximum profit when a stock is currently held.
 * 3. For every day:
 *      - Compute the profit for the "sell/hold" state.
 *      - Compute the profit for the "buy/skip" state.
 * 4. Update the DP states for the next iteration.
 * 5. Return the profit when buying is initially allowed.
 *
 * Note:
 * - Only the next day's DP states are required.
 * - The solution therefore uses four integer variables instead of
 *   arrays, reducing the auxiliary space to O(1).
 *
 * @param prices Array containing the stock price for each day.
 * @param n Number of trading days.
 * @return int Maximum profit obtainable.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of trading days.
 */
int stockBuySell(vector<int> prices, int n) {

    // DP values for the next day.
    int dpBuy = 0;
    int dpNotBuy = 0;

    // DP values for the current day.
    int currentBuy = 0;
    int currentNotBuy = 0;

    for (int day = n - 1; day >= 0; day--) {

        // State when a stock is currently held.
        currentNotBuy = max(
            prices[day] + dpBuy,
            dpNotBuy);

        // State when buying is allowed.
        currentBuy = max(
            -prices[day] + dpNotBuy,
            dpBuy);

        dpBuy = currentBuy;
        dpNotBuy = currentNotBuy;
    }

    return dpBuy;
}