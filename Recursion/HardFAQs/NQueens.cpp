#include <string>
#include <vector>
using namespace std;

/**
 * @brief Recursively places queens column by column using backtracking.
 *
 * The function attempts to place one queen in every column. Three helper
 * arrays are used to determine whether a queen can be safely placed in
 * constant time:
 *
 * - leftRow[row]      → Indicates whether a row already contains a queen.
 * - lowerDiagonal     → Represents the diagonal identified by (row + col).
 * - upperDiagonal     → Represents the diagonal identified by
 *                       (n - 1 - row + col).
 *
 * If a valid position is found, the queen is placed and the function
 * recursively processes the next column. After returning, the queen is
 * removed to explore other configurations (backtracking).
 *
 * @param col Current column being processed.
 * @param n Size of the chessboard.
 * @param board Current board configuration.
 * @param solutions Stores all valid board configurations.
 * @param leftRow Tracks occupied rows.
 * @param upperDiagonal Tracks occupied upper diagonals.
 * @param lowerDiagonal Tracks occupied lower diagonals.
 *
 * Time Complexity: O(N!)
 * Space Complexity: O(N)
 */
void solve(int col,
           int n,
           vector<string>& board,
           vector<vector<string>>& solutions,
           vector<int>& leftRow,
           vector<int>& upperDiagonal,
           vector<int>& lowerDiagonal) {

    // All queens have been placed.
    if (col == n) {
        solutions.push_back(board);
        return;
    }

    // Try placing a queen in every row of the current column.
    for (int row = 0; row < n; row++) {

        if (leftRow[row] == 0 &&
            lowerDiagonal[row + col] == 0 &&
            upperDiagonal[n - 1 - row + col] == 0) {

            // Place the queen.
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 - row + col] = 1;

            solve(col + 1, n, board, solutions,
                  leftRow, upperDiagonal, lowerDiagonal);

            // Backtrack.
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 - row + col] = 0;
        }
    }
}

/**
 * @brief Finds all possible ways to place N queens on an N × N chessboard.
 *
 * The goal is to place N queens such that no two queens attack each other.
 * Therefore:
 * - No two queens may share the same row.
 * - No two queens may share the same column.
 * - No two queens may share the same diagonal.
 *
 * Example:
 * n = 4
 *
 * One valid solution:
 *
 * . Q . .
 * . . . Q
 * Q . . .
 * . . Q .
 *
 * Another valid solution:
 *
 * . . Q .
 * Q . . .
 * . . . Q
 * . Q . .
 *
 * Algorithm:
 * 1. Start from the first column.
 * 2. Try placing a queen in every row.
 * 3. Use three helper arrays to check row and diagonal conflicts in O(1).
 * 4. If the placement is valid, recursively solve the next column.
 * 5. Remove the queen after returning (backtracking).
 * 6. Store every valid configuration.
 *
 * Note:
 * - Every solution contains exactly one queen in each column.
 * - Diagonal indices:
 *      Lower diagonal = row + col
 *      Upper diagonal = n - 1 - row + col
 *
 * @param n Size of the chessboard.
 * @return vector<vector<string>> All valid N-Queens configurations.
 *
 * Time Complexity: O(N!)
 * Space Complexity: O(N) excluding the output.
 */
vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> solutions;

    vector<string> board(n, string(n, '.'));

    vector<int> leftRow(n, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);

    solve(0, n, board, solutions,
          leftRow, upperDiagonal, lowerDiagonal);

    return solutions;
}