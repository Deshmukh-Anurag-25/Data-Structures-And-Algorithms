#include <vector>
using namespace std;

/**
 * @brief Recursively computes the number of unique paths to reach a cell
 * in a grid containing obstacles using memoization.
 *
 * The robot starts from the top-left corner and can move only:
 * - Down
 * - Right
 *
 * Cells containing 1 are obstacles and cannot be visited.
 *
 * The number of ways to reach a cell is the sum of:
 * - Paths from the cell above.
 * - Paths from the cell to the left.
 *
 * Previously computed states are stored in the DP table to avoid
 * recomputation.
 *
 * @param row Current row.
 * @param col Current column.
 * @param grid Grid containing obstacles.
 * @param dp Memoization table.
 * @return int Number of unique paths to reach (row, col).
 *
 * Time Complexity: O(m × n)
 * Space Complexity: O(m × n) + O(m + n)
 * where:
 * - m = number of rows.
 * - n = number of columns.
 */
int solve(int row,
          int col,
          vector<vector<int>>& grid,
          vector<vector<int>>& dp) {

    // Current cell is blocked.
    if (row >= 0 && col >= 0 && grid[row][col] == 1)
        return 0;

    // Reached the starting cell.
    if (row == 0 && col == 0)
        return 1;

    // Outside the grid.
    if (row < 0 || col < 0)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = solve(row - 1, col, grid, dp);
    int left = solve(row, col - 1, grid, dp);

    return dp[row][col] = up + left;
}

/**
 * @brief Computes the number of unique paths from the top-left corner
 * to the bottom-right corner of a grid containing obstacles using
 * space-optimized dynamic programming.
 *
 * The robot may move only:
 * - Right
 * - Down
 *
 * Cells containing 1 are blocked and cannot be visited.
 *
 * Example:
 * Grid:
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 * Valid paths:
 * Right → Right → Down → Down
 * Down → Down → Right → Right
 *
 * Returns:
 * 2
 *
 * Algorithm:
 * 1. If the starting cell is blocked, return 0.
 * 2. Let dp[col] represent the number of paths to reach the current row
 *    at column col.
 * 3. Process the grid row by row.
 * 4. For every cell:
 *      - If it is an obstacle, store 0.
 *      - Otherwise:
 *            paths = pathsFromAbove + pathsFromLeft
 * 5. Store the current row and continue.
 * 6. Return the value of the bottom-right cell.
 *
 * Note:
 * - Obstacle cells always contribute zero paths.
 * - Only the previous row is required, reducing the DP table from
 *   O(m × n) to O(n).
 *
 * @param obstacleGrid Grid where:
 *        - 0 represents an empty cell.
 *        - 1 represents an obstacle.
 * @return int Number of unique paths.
 *
 * Time Complexity: O(m × n)
 * Space Complexity: O(n)
 * where:
 * - m = number of rows.
 * - n = number of columns.
 */
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // If the starting cell is blocked, no path exists.
    if (obstacleGrid[0][0] == 1)
        return 0;

    // Previous row.
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int row = 0; row < m; row++) {

        // Current row.
        vector<int> current(n, 0);

        for (int col = 0; col < n; col++) {

            if (row == 0 && col == 0) {
                current[col] = 1;
                continue;
            }

            // Obstacle cell.
            if (obstacleGrid[row][col] == 1) {
                current[col] = 0;
                continue;
            }

            int up = 0;
            int left = 0;

            if (row > 0)
                up = dp[col];

            if (col > 0)
                left = current[col - 1];

            current[col] = up + left;
        }

        dp = current;
    }

    return dp[n - 1];
}