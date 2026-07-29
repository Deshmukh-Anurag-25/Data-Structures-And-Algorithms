#include <vector>
using namespace std;

/**
 * @brief Computes the maximum profit from buying and selling stocks with
 * a transaction fee.
 *
 * You may perform as many transactions as you like, but:
 * - You can hold at most one stock at a time.
 * - After selling a stock, a fixed transaction fee is deducted.
 *
 * Dynamic Programming States:
 * - buy = 1 → You are allowed to buy a stock.
 * - buy = 0 → You currently own a stock and may sell it.
 *
 * Transition:
 * - Buy state:
 *      max(-price + nextSellState,
 *          skipCurrentDay)
 *
 * - Sell state:
 *      max(price - fee + nextBuyState,
 *          skipCurrentDay)
 *
 * Example:
 * prices = [1,3,2,8,4,9]
 * fee = 2
 *
 * Buy at 1, Sell at 8  → Profit = 5
 * Buy at 4, Sell at 9  → Profit = 3
 *
 * Total Profit = 8
 *
 * Algorithm:
 * 1. Traverse the prices array from the last day to the first.
 * 2. Maintain two DP states:
 *      - dp[i][1] = Maximum profit when buying is allowed.
 *      - dp[i][0] = Maximum profit when holding a stock.
 * 3. At each day, decide whether to buy, sell, or skip.
 * 4. Return the profit starting from day 0 with buying allowed.
 *
 * @param prices Stock prices for each day.
 * @param fee Transaction fee charged on every sale.
 * @return int Maximum achievable profit.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of days.
 */
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {

            if (buy) {
                dp[i][buy] = max(-prices[i] + dp[i + 1][0],
                                 dp[i + 1][1]);
            } else {
                dp[i][buy] = max(prices[i] - fee + dp[i + 1][1],
                                 dp[i + 1][0]);
            }
        }
    }

    return dp[0][1];
}