#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/**
 * @brief Recursively computes the minimum path sum from the top-left
 * corner to the current cell using memoization.
 *
 * The grid contains non-negative integers representing the cost of
 * entering each cell.
 *
 * The robot starts at the top-left corner and may move only:
 * - Down
 * - Right
 *
 * The minimum cost to reach a cell is the smaller of:
 * - Minimum cost from the cell above.
 * - Minimum cost from the cell to the left.
 *
 * Previously computed states are stored in the DP table to avoid
 * recomputation.
 *
 * @param row Current row.
 * @param col Current column.
 * @param grid Cost matrix.
 * @param dp Memoization table.
 * @return int Minimum path sum to reach (row, col).
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

    // Reached the starting cell.
    if (row == 0 && col == 0)
        return grid[0][0];

    // Outside the grid.
    if (row < 0 || col < 0)
        return INT_MAX;

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = solve(row - 1, col, grid, dp);
    int left = solve(row, col - 1, grid, dp);

    if (up != INT_MAX)
        up += grid[row][col];

    if (left != INT_MAX)
        left += grid[row][col];

    return dp[row][col] = min(up, left);
}

/**
 * @brief Computes the minimum path sum from the top-left corner to the
 * bottom-right corner using space-optimized dynamic programming.
 *
 * Each cell contains a non-negative cost. The objective is to reach the
 * destination while minimizing the total sum of the visited cells.
 *
 * The robot may move only:
 * - Right
 * - Down
 *
 * Example:
 * Grid:
 * 1 3 1
 * 1 5 1
 * 4 2 1
 *
 * Minimum-cost path:
 * 1 → 3 → 1 → 1 → 1
 *
 * Total cost:
 * 7
 *
 * Algorithm:
 * 1. Let dp[col] represent the minimum path sum to reach the current row
 *    at column col.
 * 2. Process the grid row by row.
 * 3. For every cell:
 *      - Cost from above = current cell value + dp[col]
 *      - Cost from left  = current cell value + currentRow[col - 1]
 *      - Store the smaller value.
 * 4. Replace the previous row with the current row.
 * 5. Return the minimum cost of the bottom-right cell.
 *
 * Note:
 * - Only the previous row is required at any time.
 * - This reduces the space complexity from O(m × n) to O(n).
 *
 * @param grid Matrix containing the cost of each cell.
 * @return int Minimum path sum from the top-left to the bottom-right
 *         corner.
 *
 * Time Complexity: O(m × n)
 * Space Complexity: O(n)
 * where:
 * - m = number of rows.
 * - n = number of columns.
 */
int minPathSum(vector<vector<int>>& grid) {

    int rows = grid.size();
    int cols = grid[0].size();

    // Previous row.
    vector<int> dp(cols, 0);
    dp[0] = grid[0][0];

    for (int row = 0; row < rows; row++) {

        // Current row.
        vector<int> current(cols, 0);

        for (int col = 0; col < cols; col++) {

            if (row == 0 && col == 0) {
                current[0] = grid[0][0];
                continue;
            }

            int up = INT_MAX;
            int left = INT_MAX;

            if (row > 0)
                up = grid[row][col] + dp[col];

            if (col > 0)
                left = grid[row][col] + current[col - 1];

            current[col] = min(up, left);
        }

        dp = current;
    }

    return dp[cols - 1];
}