#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/**
 * @brief Computes the maximum profit that can be earned by buying and
 * selling a stock exactly once.
 *
 * You are given the stock price for each day. You may:
 * - Buy one stock on a single day.
 * - Sell it on a later day.
 *
 * The goal is to maximize the profit. If no profit is possible,
 * the function returns 0.
 *
 * Example:
 * Prices:
 * 7 1 5 3 6 4
 *
 * Buy at:
 * 1
 *
 * Sell at:
 * 6
 *
 * Profit:
 * 6 − 1 = 5
 *
 * Returns:
 * 5
 *
 * Algorithm:
 * 1. Maintain the minimum stock price seen so far.
 * 2. For every day's price:
 *      - Update the minimum buying price.
 *      - Compute the profit obtained by selling today.
 *      - Update the maximum profit if the current profit is larger.
 * 3. Return the maximum profit obtained.
 *
 * Note:
 * - Buying must always occur before selling.
 * - If prices are strictly decreasing, no profitable transaction exists,
 *   so the answer is 0.
 *
 * @param arr Array containing the stock price for each day.
 * @param n Number of days.
 * @return int Maximum profit obtainable from one transaction.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of days.
 */
int stockBuySell(vector<int> arr, int n) {

    // Lowest stock price encountered so far.
    int minimumPrice = INT_MAX;

    // Maximum profit obtained.
    int maximumProfit = 0;

    for (int i = 0; i < n; i++) {

        // Update the minimum buying price.
        minimumPrice = min(minimumPrice, arr[i]);

        // Compute profit if the stock is sold today.
        maximumProfit = max(maximumProfit,
                            arr[i] - minimumPrice);
    }

    return maximumProfit;
}