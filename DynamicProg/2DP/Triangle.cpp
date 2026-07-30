#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/**
 * @brief Recursively computes the minimum path sum from the top of a
 * triangle to the current position using memoization.
 *
 * Starting from the top element, you may move only to:
 * - The element directly below.
 * - The element diagonally below to the right.
 *
 * The minimum cost to reach the bottom is obtained by choosing the
 * smaller of the two possible paths.
 *
 * Previously computed states are stored in the DP table to avoid
 * repeated calculations.
 *
 * @param row Current row in the triangle.
 * @param col Current column in the current row.
 * @param triangle Triangle containing the values.
 * @param dp Memoization table.
 * @return int Minimum path sum from (row, col) to the bottom.
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(n²) + O(n)
 * where:
 * - n = number of rows in the triangle.
 */
int solve(int row,
          int col,
          vector<vector<int>>& triangle,
          vector<vector<int>>& dp) {

    // Reached the last row.
    if (row == triangle.size() - 1)
        return triangle[row][col];

    if (dp[row][col] != INT_MIN)
        return dp[row][col];

    // Move directly downward.
    int down =
        triangle[row][col] +
        solve(row + 1, col, triangle, dp);

    // Move diagonally downward.
    int diagonal =
        triangle[row][col] +
        solve(row + 1, col + 1, triangle, dp);

    return dp[row][col] = min(down, diagonal);
}

/**
 * @brief Computes the minimum path sum from the top to the bottom of a
 * triangle using recursion with memoization.
 *
 * Beginning at the top element, each step allows movement to one of the
 * two adjacent elements in the next row:
 * - Directly below.
 * - Diagonally below to the right.
 *
 * Example:
 * Triangle:
 *
 *        2
 *       3 4
 *      6 5 7
 *     4 1 8 3
 *
 * Minimum path:
 * 2 → 3 → 5 → 1
 *
 * Total:
 * 11
 *
 * Algorithm:
 * 1. Start from the top of the triangle.
 * 2. At every element, recursively compute:
 *      - Minimum path through the element below.
 *      - Minimum path through the diagonal element.
 * 3. Store computed results in the DP table.
 * 4. Return the minimum path sum from the top.
 *
 * Note:
 * - Every state (row, col) is solved only once because of memoization.
 *
 * @param triangle Triangle containing the path costs.
 * @return int Minimum path sum from the top to the bottom.
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(n²) + O(n)
 * where:
 * - n = number of rows in the triangle.
 */
int minimumTotal(vector<vector<int>>& triangle) {

    int rows = triangle.size();
    int cols = triangle[rows - 1].size();

    // Memoization table.
    vector<vector<int>> dp(
        rows,
        vector<int>(cols, INT_MIN));

    return solve(0, 0, triangle, dp);
}