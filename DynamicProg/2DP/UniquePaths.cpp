#include <vector>
using namespace std;

/**
 * @brief Recursively computes the number of unique paths from the
 * top-left corner to the current cell using memoization.
 *
 * The robot can move only:
 * - Down
 * - Right
 *
 * The function computes the number of ways to reach cell (i, j) by
 * considering the two possible previous cells:
 * - (i - 1, j)
 * - (i, j - 1)
 *
 * Previously computed states are stored in the DP table to avoid
 * repeated calculations.
 *
 * @param i Current row.
 * @param j Current column.
 * @param dp Memoization table.
 * @return int Number of unique paths to reach cell (i, j).
 *
 * Time Complexity: O(m × n)
 * Space Complexity: O(m × n) + O(m + n)
 */
int solve(int i, int j, vector<vector<int>>& dp) {

    // Reached the starting cell.
    if (i == 0 && j == 0)
        return 1;

    // Outside the grid.
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i - 1, j, dp);
    int left = solve(i, j - 1, dp);

    return dp[i][j] = up + left;
}

/**
 * @brief Computes the number of unique paths from the top-left corner
 * to the bottom-right corner of an m × n grid using
 * space-optimized dynamic programming.
 *
 * A robot starts at the top-left corner of the grid and wants to reach
 * the bottom-right corner.
 *
 * At every step, it may move only:
 * - Right
 * - Down
 *
 * Example:
 * m = 3, n = 2
 *
 * Grid:
 * S . .
 * . . E
 *
 * Possible paths:
 * Right → Right → Down
 * Right → Down → Right
 * Down → Right → Right
 *
 * Returns:
 * 3
 *
 * Algorithm:
 * 1. Let dp[j] represent the number of paths to reach the current row
 *    at column j.
 * 2. Process the grid row by row.
 * 3. For every cell:
 *      - Paths from above = dp[j]
 *      - Paths from left  = currentRow[j - 1]
 *      - Total = above + left
 * 4. Store the current row and use it as the previous row for the next
 *    iteration.
 * 5. Return the value of the bottom-right cell.
 *
 * Note:
 * - Only the previous row is required at any time.
 * - Therefore, the 2D DP table is reduced to two 1D arrays.
 *
 * @param m Number of rows.
 * @param n Number of columns.
 * @return int Number of unique paths.
 *
 * Time Complexity: O(m × n)
 * Space Complexity: O(m)
 * where:
 * - m = number of rows.
 * - n = number of columns.
 */
int uniquePaths(int m, int n) {

    // Previous row.
    vector<int> dp(m, 0);
    dp[0] = 1;

    for (int row = 0; row < n; row++) {

        // Current row.
        vector<int> current(m, 0);

        for (int col = 0; col < m; col++) {

            if (row == 0 && col == 0) {
                current[col] = 1;
                continue;
            }

            int up = dp[col];

            int left = 0;
            if (col > 0)
                left = current[col - 1];

            current[col] = up + left;
        }

        dp = current;
    }

    return dp[m - 1];
}