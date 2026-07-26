#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Recursively computes the maximum number of cherries that two
 * robots can collect using memoization.
 *
 * Two robots start at:
 * - Robot 1 → (0, 0)
 * - Robot 2 → (0, m - 1)
 *
 * Both robots move simultaneously from one row to the next.
 *
 * From each cell, a robot may move:
 * - Down-left
 * - Down
 * - Down-right
 *
 * If both robots land on the same cell, the cherries in that cell are
 * counted only once.
 *
 * The DP state is:
 * dp[row][col1][col2]
 *
 * where:
 * - row  = current row.
 * - col1 = Robot 1's column.
 * - col2 = Robot 2's column.
 *
 * @param row Current row.
 * @param col1 Current column of Robot 1.
 * @param col2 Current column of Robot 2.
 * @param grid Cherry grid.
 * @param dp Three-dimensional memoization table.
 * @return int Maximum cherries collectible from the current state.
 *
 * Time Complexity: O(rows × cols² × 9)
 * Space Complexity: O(rows × cols²) + O(rows)
 * where:
 * - rows = number of rows.
 * - cols = number of columns.
 */
int solve(int row,
          int col1,
          int col2,
          vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {

    int cols = grid[0].size();

    // Robot moved outside the grid.
    if (col1 < 0 || col1 >= cols ||
        col2 < 0 || col2 >= cols)
        return -1000000000;

    // Reached the last row.
    if (row == grid.size() - 1) {

        if (col1 == col2)
            return grid[row][col1];

        return grid[row][col1] + grid[row][col2];
    }

    if (dp[row][col1][col2] != -1)
        return dp[row][col1][col2];

    int maximumCherries = -1000000000;

    // Try every movement for both robots.
    for (int move1 = -1; move1 <= 1; move1++) {

        for (int move2 = -1; move2 <= 1; move2++) {

            int cherries;

            if (col1 == col2) {

                cherries =
                    grid[row][col1] +
                    solve(row + 1,
                          col1 + move1,
                          col2 + move2,
                          grid,
                          dp);
            }
            else {

                cherries =
                    grid[row][col1] +
                    grid[row][col2] +
                    solve(row + 1,
                          col1 + move1,
                          col2 + move2,
                          grid,
                          dp);
            }

            maximumCherries = max(maximumCherries, cherries);
        }
    }

    return dp[row][col1][col2] = maximumCherries;
}

/**
 * @brief Computes the maximum number of cherries that two robots can
 * collect while moving from the top row to the bottom row.
 *
 * Robot 1 starts at the top-left corner.
 * Robot 2 starts at the top-right corner.
 *
 * Every row, both robots move simultaneously to the next row.
 * Each robot may move:
 * - Down-left
 * - Down
 * - Down-right
 *
 * If both robots visit the same cell, its cherries are counted only
 * once.
 *
 * Example:
 *
 * Grid:
 * 3 1 1
 * 2 5 1
 * 1 5 5
 * 2 1 1
 *
 * One optimal traversal:
 *
 * Robot 1:
 * (0,0) → (1,0) → (2,1) → (3,0)
 *
 * Robot 2:
 * (0,2) → (1,1) → (2,2) → (3,2)
 *
 * Total cherries:
 * 24
 *
 * Algorithm:
 * 1. Start with Robot 1 at column 0 and Robot 2 at column cols − 1.
 * 2. At every row:
 *      - Try all 9 possible combinations of robot movements.
 *      - Collect cherries from both positions.
 *      - If both robots occupy the same cell, count its cherries once.
 * 3. Store every state (row, col1, col2) using memoization.
 * 4. Return the maximum cherries collected.
 *
 * Note:
 * - There are three choices for each robot at every row, producing
 *   3 × 3 = 9 transitions per state.
 * - Memoization ensures each state is solved only once.
 *
 * @param matrix Grid containing cherries.
 * @return int Maximum cherries collectible.
 *
 * Time Complexity: O(rows × cols² × 9)
 * Space Complexity: O(rows × cols²)
 * where:
 * - rows = number of rows.
 * - cols = number of columns.
 */
int cherryPickup(vector<vector<int>>& matrix) {

    int rows = matrix.size();
    int cols = matrix[0].size();

    // Memoization table.
    vector<vector<vector<int>>> dp(
        rows,
        vector<vector<int>>(
            cols,
            vector<int>(cols, -1)));

    return solve(0, 0, cols - 1, matrix, dp);
}